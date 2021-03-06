/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <thrift/lib/cpp2/async/AsyncProcessor.h>

namespace apache {
namespace thrift {

constexpr std::chrono::seconds ServerInterface::BlockingThreadManager::kTimeout;
thread_local RequestParams ServerInterface::requestParams_;

EventTask::~EventTask() {
  expired();
}

void EventTask::run() {
  if (!oneway_) {
    if (req_ && !req_->isActive()) {
      // del on eventbase thread
      base_->runInEventBaseThread([req = std::move(req_)]() mutable {});
      return;
    }
  }
  taskFunc_(std::move(req_));
}

void EventTask::expired() {
  // only expire req_ once
  if (!req_) {
    return;
  }
  failWith(
      TApplicationException{"Task expired without processing"},
      kTaskExpiredErrorCode);
}

void EventTask::failWith(folly::exception_wrapper ex, std::string exCode) {
  auto cleanUp = [oneway = oneway_,
                  req = std::move(req_),
                  ex = std::move(ex),
                  exCode = std::move(exCode)]() mutable {
    // if oneway, skip sending back anything
    if (oneway) {
      return;
    }
    req->sendErrorWrapped(std::move(ex), std::move(exCode));
  };

  if (base_->isInEventBaseThread()) {
    cleanUp();
  } else {
    base_->runInEventBaseThread(std::move(cleanUp));
  }
}

void AsyncProcessor::terminateInteraction(
    int64_t,
    Cpp2ConnContext&,
    folly::EventBase&) noexcept {
  LOG(DFATAL) << "This processor doesn't support interactions";
}

void AsyncProcessor::destroyAllInteractions(
    Cpp2ConnContext&,
    concurrency::ThreadManager&,
    folly::EventBase&) noexcept {}

bool GeneratedAsyncProcessor::createInteraction(
    ResponseChannelRequest::UniquePtr& req,
    int64_t id,
    const std::string& name,
    Cpp2RequestContext& ctx,
    concurrency::ThreadManager* tm,
    folly::EventBase& eb,
    ServerInterface* si) {
  eb.dcheckIsInEventBaseThread();

  auto nullthrows = [](std::unique_ptr<Tile> tile) {
    if (!tile) {
      DLOG(FATAL) << "Nullptr returned from interaction constructor";
      throw std::runtime_error("Nullptr returned from interaction constructor");
    }
    return tile;
  };
  auto& conn = *ctx.getConnectionContext();

  // In the eb model we create the interaction inline.
  if (!tm) {
    si->setEventBase(&eb);
    si->setConnectionContext(&ctx);
    auto tile = folly::makeTryWith(
        [&] { return nullthrows(createInteractionImpl(name)); });
    if (tile.hasException()) {
      req->sendErrorWrapped(
          folly::make_exception_wrapper<TApplicationException>(
              "Interaction constructor failed with " +
              tile.exception().what().toStdString()),
          kInteractionConstructorErrorErrorCode);
      return true; // Not a duplicate; caller will see missing tile.
    }
    (*tile)->destructionExecutor_ = &eb;
    return conn.addTile(id, std::move(*tile));
  }

  // In the tm model we use a promise.
  auto promise = std::make_unique<TilePromise>();
  auto promisePtr = promise.get();
  if (!conn.addTile(id, std::move(promise))) {
    return false;
  }

  folly::via(
      tm,
      [=, eb = &eb, ctx = &ctx] {
        si->setEventBase(eb);
        si->setThreadManager(tm);
        si->setConnectionContext(ctx);
        return nullthrows(createInteractionImpl(name));
      })
      .via(&eb)
      .thenTry([&conn, id, tm, &eb, promisePtr](auto&& t) {
        auto promise = std::unique_ptr<TilePromise>(promisePtr);
        std::unique_ptr<Tile> tile;
        if (t.hasValue()) {
          tile = std::move(*t);
          tile->destructionExecutor_ = tm;
        }

        if (promise->destructionRequested_) {
          // promise not in tile map, not running continuations
          if (tile) {
            auto ex = std::move(tile->destructionExecutor_);
            std::move(ex).add([tile = std::move(tile)](auto) {});
          }
        } else if (promise->terminationRequested_) {
          // promise not in tile map, continuations will free tile
          if (tile) {
            tile->terminationRequested_ = true;
            promise->fulfill<InteractionEventTask>(*tile.release(), *tm, eb);
          } else {
            promise->failWith<EventTask>(
                folly::make_exception_wrapper<TApplicationException>(
                    "Interaction constructor failed with " +
                    t.exception().what().toStdString()),
                kInteractionConstructorErrorErrorCode);
          }
        } else {
          if (tile) {
            // promise and tile managed by pointer in tile map
            promise->fulfill<InteractionEventTask>(*tile, *tm, eb);
            conn.resetTile(id, std::move(tile)).release(); // aliases promise
          } else {
            promise->failWith<EventTask>(
                folly::make_exception_wrapper<TApplicationException>(
                    "Interaction constructor failed with " +
                    t.exception().what().toStdString()),
                kInteractionConstructorErrorErrorCode);
            conn.removeTile(id).release(); // aliases promise
          }
        }
      });
  return true;
}

std::unique_ptr<Tile> GeneratedAsyncProcessor::createInteractionImpl(
    const std::string&) {
  return nullptr;
}

void GeneratedAsyncProcessor::terminateInteraction(
    int64_t id,
    Cpp2ConnContext& conn,
    folly::EventBase& eb) noexcept {
  eb.dcheckIsInEventBaseThread();

  auto tile = conn.removeTile(id);
  if (!tile) {
    return;
  } else if (tile->refCount_ || tile->__fbthrift_isPromise()) {
    tile->terminationRequested_ = true;
    tile.release(); // freed by last decref
  } else {
    auto ex = std::move(tile->destructionExecutor_);
    std::move(ex).add([tile = std::move(tile)](auto) {});
  }
}

void GeneratedAsyncProcessor::destroyAllInteractions(
    Cpp2ConnContext& conn,
    concurrency::ThreadManager& tm,
    folly::EventBase& eb) noexcept {
  eb.dcheckIsInEventBaseThread();

  if (conn.tiles_.empty()) {
    return;
  }

  auto tiles = std::move(conn.tiles_);
  for (auto& [id, tile] : tiles) {
    if (tile->refCount_) {
      if (tile->__fbthrift_isPromise()) {
        static_cast<TilePromise&>(*tile).destructionRequested_ = true;
      } else {
        tile->terminationRequested_ = true;
      }
      tile.release();
    }
  }

  tm.add([tiles = std::move(tiles)] {});
}

bool GeneratedAsyncProcessor::validateRpcKind(
    ResponseChannelRequest::UniquePtr& req,
    RpcKind kind) {
  switch (kind) {
    case RpcKind::SINGLE_REQUEST_NO_RESPONSE:
      switch (req->rpcKind()) {
        case RpcKind::SINGLE_REQUEST_NO_RESPONSE:
          return true;
        case RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE:
          req->sendReply(std::unique_ptr<folly::IOBuf>());
          return true;
        default:
          break;
      }
      break;
    case RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE:
      switch (req->rpcKind()) {
        case RpcKind::SINGLE_REQUEST_NO_RESPONSE:
        case RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE:
          return true;
        default:
          break;
      }
      break;
    default:
      if (kind == req->rpcKind()) {
        return true;
      }
  }
  if (req->rpcKind() != RpcKind::SINGLE_REQUEST_NO_RESPONSE) {
    req->sendErrorWrapped(
        folly::make_exception_wrapper<TApplicationException>(
            TApplicationException::TApplicationExceptionType::UNKNOWN_METHOD,
            "Function kind mismatch"),
        kRequestTypeDoesntMatchServiceFunctionType);
  }
  return false;
}

bool GeneratedAsyncProcessor::setUpRequestProcessing(
    ResponseChannelRequest::UniquePtr& req,
    Cpp2RequestContext* ctx,
    folly::EventBase* eb,
    concurrency::ThreadManager* tm,
    RpcKind kind,
    ServerInterface* si,
    const char* interaction) {
  if (!validateRpcKind(req, kind)) {
    return false;
  }

  bool interactionMetadataValid;
  if (auto interactionId = ctx->getInteractionId()) {
    if (auto interactionCreate = ctx->getInteractionCreate()) {
      if (!interaction ||
          *interactionCreate->interactionName_ref() != interaction) {
        interactionMetadataValid = false;
      } else if (!createInteraction(
                     req,
                     interactionId,
                     *interactionCreate->interactionName_ref(),
                     *ctx,
                     tm,
                     *eb,
                     si)) {
        // Duplicate id is a contract violation so close the connection.
        // Terminate this interaction first so queued requests can't use it
        // (which could result in UB).
        terminateInteraction(interactionId, *ctx->getConnectionContext(), *eb);
        req->sendErrorWrapped(
            TApplicationException(
                "Attempting to create interaction with duplicate id. Failing all requests in that interaction."),
            kConnectionClosingErrorCode);
        return false;
      } else {
        interactionMetadataValid = true;
      }
    } else {
      interactionMetadataValid = !!interaction;
    }

    if (interactionMetadataValid && !tm) {
      try {
        // This is otherwise done by InteractionEventTask when dequeued.
        auto& tile = ctx->getConnectionContext()->getTile(interactionId);
        ctx->setTile(tile);
        tile.__fbthrift_acquireRef(*eb);
      } catch (const std::out_of_range&) {
        req->sendErrorWrapped(
            TApplicationException(
                "Invalid interaction id " + std::to_string(interactionId)),
            kInteractionIdUnknownErrorCode);
        return false;
      }
    }
  } else {
    interactionMetadataValid = !interaction;
  }
  if (!interactionMetadataValid) {
    req->sendErrorWrapped(
        folly::make_exception_wrapper<TApplicationException>(
            TApplicationException::TApplicationExceptionType::UNKNOWN_METHOD,
            "Interaction and method do not match"),
        kMethodUnknownErrorCode);
    return false;
  }

  return true;
}

concurrency::PRIORITY ServerInterface::getRequestPriority(
    Cpp2RequestContext* ctx,
    concurrency::PRIORITY prio) {
  concurrency::PRIORITY callPriority = ctx->getCallPriority();
  return callPriority == concurrency::N_PRIORITIES ? prio : callPriority;
}

void ServerInterface::setEventBase(folly::EventBase* eb) {
  folly::RequestEventBase::set(eb);
  requestParams_.eventBase_ = eb;
}

void ServerInterface::BlockingThreadManager::add(folly::Func f) {
  std::shared_ptr<concurrency::Runnable> task =
      concurrency::FunctionRunner::create(std::move(f));
  try {
    executor_->add(
        std::move(task), std::chrono::milliseconds(kTimeout).count(), 0, false);
    return;
  } catch (...) {
    LOG(FATAL) << "Failed to schedule a task within timeout: "
               << folly::exceptionStr(std::current_exception());
  }
}

bool ServerInterface::BlockingThreadManager::keepAliveAcquire() noexcept {
  auto keepAliveCount = keepAliveCount_.fetch_add(1, std::memory_order_relaxed);
  // We should never increment from 0
  DCHECK(keepAliveCount > 0);
  return true;
}

void ServerInterface::BlockingThreadManager::keepAliveRelease() noexcept {
  auto keepAliveCount = keepAliveCount_.fetch_sub(1, std::memory_order_acq_rel);
  DCHECK(keepAliveCount >= 1);
  if (keepAliveCount == 1) {
    delete this;
  }
}

HandlerCallbackBase::~HandlerCallbackBase() {
  // req must be deleted in the eb
  if (req_) {
    if (req_->isActive() && ewp_) {
      exception(TApplicationException(
          TApplicationException::INTERNAL_ERROR,
          "apache::thrift::HandlerCallback not completed"));
      return;
    }
    assert(eb_ != nullptr);
    if (eb_->inRunningEventBaseThread()) {
      releaseInteractionInstance();
      req_.reset();
    } else {
      eb_->runInEventBaseThread(
          [req = std::move(req_),
           interaction = std::exchange(interaction_, nullptr),
           eb = getEventBase()] { releaseInteraction(interaction, eb); });
    }
  }
}

folly::EventBase* HandlerCallbackBase::getEventBase() {
  assert(eb_ != nullptr);
  return eb_;
}

concurrency::ThreadManager* HandlerCallbackBase::getThreadManager() {
  assert(tm_ != nullptr);
  return tm_;
}

void HandlerCallbackBase::forward(const HandlerCallbackBase& other) {
  eb_ = other.eb_;
  tm_ = other.tm_;
  ewp_ = other.ewp_;
}

folly::Optional<uint32_t> HandlerCallbackBase::checksumIfNeeded(
    folly::IOBufQueue& queue) {
  folly::Optional<uint32_t> crc32c;
  if (req_->isReplyChecksumNeeded() && !queue.empty()) {
    std::unique_ptr<folly::IOBuf> iobuf(queue.move());
    if (iobuf) {
      crc32c = checksum::crc32c(*iobuf);
      queue.append(std::move(iobuf));
    }
  }
  return crc32c;
}

void HandlerCallbackBase::transform(folly::IOBufQueue& queue) {
  // Do any compression or other transforms in this thread, the same thread
  // that serialization happens on.
  queue.append(transport::THeader::transform(
      queue.move(), reqCtx_->getHeader()->getWriteTransforms()));
}

void HandlerCallbackBase::doExceptionWrapped(folly::exception_wrapper ew) {
  if (req_ == nullptr) {
    LOG(ERROR) << ew.what();
  } else {
    callExceptionInEventBaseThread(ewp_, ew);
  }
}

void HandlerCallbackBase::doAppOverloadedException(const std::string& message) {
  if (eb_->inRunningEventBaseThread()) {
    releaseInteractionInstance();
    std::exchange(req_, {})->sendErrorWrapped(
        folly::make_exception_wrapper<TApplicationException>(
            TApplicationException::LOADSHEDDING, message),
        kAppOverloadedErrorCode);
  } else {
    eb_->runInEventBaseThread(
        [message,
         interaction = std::exchange(interaction_, nullptr),
         req = std::move(req_),
         eb = getEventBase()]() mutable {
          releaseInteraction(interaction, eb);
          req->sendErrorWrapped(
              folly::make_exception_wrapper<TApplicationException>(
                  TApplicationException::LOADSHEDDING, std::move(message)),
              kAppOverloadedErrorCode);
        });
  }
}

void HandlerCallbackBase::sendReply(folly::IOBufQueue queue) {
  folly::Optional<uint32_t> crc32c = checksumIfNeeded(queue);
  transform(queue);
  if (getEventBase()->isInEventBaseThread()) {
    releaseInteractionInstance();
    std::exchange(req_, {})->sendReply(queue.move(), nullptr, crc32c);
  } else {
    getEventBase()->runInEventBaseThread(
        [req = std::move(req_),
         queue = std::move(queue),
         crc32c,
         interaction = std::exchange(interaction_, nullptr),
         eb = getEventBase()]() mutable {
          releaseInteraction(interaction, eb);
          req->sendReply(queue.move(), nullptr, crc32c);
        });
  }
}

void HandlerCallbackBase::sendReply(
    ResponseAndServerStreamFactory&& responseAndStream) {
  auto& queue = responseAndStream.response;
  auto& stream = responseAndStream.stream;
  folly::Optional<uint32_t> crc32c = checksumIfNeeded(queue);
  transform(queue);
  stream.setInteraction(std::exchange(interaction_, nullptr));
  if (getEventBase()->isInEventBaseThread()) {
    std::exchange(req_, {})->sendStreamReply(
        queue.move(), std::move(stream), crc32c);
  } else {
    getEventBase()->runInEventBaseThread([req = std::move(req_),
                                          queue = std::move(queue),
                                          stream = std::move(stream),
                                          crc32c]() mutable {
      req->sendStreamReply(queue.move(), std::move(stream), crc32c);
    });
  }
}

void HandlerCallbackBase::sendReply(
    FOLLY_MAYBE_UNUSED
        std::pair<folly::IOBufQueue, apache::thrift::detail::SinkConsumerImpl>&&
            responseAndSinkConsumer) {
#if FOLLY_HAS_COROUTINES
  auto& queue = responseAndSinkConsumer.first;
  auto& sinkConsumer = responseAndSinkConsumer.second;
  folly::Optional<uint32_t> crc32c = checksumIfNeeded(queue);
  transform(queue);
  sinkConsumer.interaction = std::exchange(interaction_, nullptr);

  if (getEventBase()->isInEventBaseThread()) {
    std::exchange(req_, {})->sendSinkReply(
        queue.move(), std::move(sinkConsumer), crc32c);
  } else {
    getEventBase()->runInEventBaseThread(
        [req = std::move(req_),
         queue = std::move(queue),
         sinkConsumer = std::move(sinkConsumer),
         crc32c]() mutable {
          req->sendSinkReply(queue.move(), std::move(sinkConsumer), crc32c);
        });
  }
#else
  std::terminate();
#endif
}

void HandlerCallbackBase::releaseInteraction(
    Tile* interaction,
    folly::EventBase* eb) {
  if (interaction) {
    interaction->__fbthrift_releaseRef(*eb);
  }
}
void HandlerCallbackBase::releaseInteractionInstance() {
  releaseInteraction(std::exchange(interaction_, nullptr), getEventBase());
}

HandlerCallback<void>::HandlerCallback(
    ResponseChannelRequest::UniquePtr req,
    std::unique_ptr<ContextStack> ctx,
    cob_ptr cp,
    exnw_ptr ewp,
    int32_t protoSeqId,
    folly::EventBase* eb,
    concurrency::ThreadManager* tm,
    Cpp2RequestContext* reqCtx,
    Tile* interaction)
    : HandlerCallbackBase(
          std::move(req),
          std::move(ctx),
          ewp,
          eb,
          tm,
          reqCtx,
          interaction),
      cp_(cp) {
  this->protoSeqId_ = protoSeqId;
}

void HandlerCallback<void>::complete(folly::Try<folly::Unit>&& r) {
  if (r.hasException()) {
    exception(std::move(r.exception()));
  } else {
    done();
  }
}

void HandlerCallback<void>::doDone() {
  assert(cp_ != nullptr);
  auto queue = cp_(this->protoSeqId_, this->ctx_.get());
  this->ctx_.reset();
  sendReply(std::move(queue));
}

} // namespace thrift
} // namespace apache
