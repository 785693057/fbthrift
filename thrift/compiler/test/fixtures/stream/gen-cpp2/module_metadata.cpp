/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include <thrift/lib/cpp2/gen/module_metadata_cpp.h>
#include "thrift/compiler/test/fixtures/stream/gen-cpp2/module_metadata.h"

namespace apache::thrift::detail::metadata {

using ThriftMetadata = ::apache::thrift::metadata::ThriftMetadata;
using ThriftPrimitiveType = ::apache::thrift::metadata::ThriftPrimitiveType;
using ThriftType = ::apache::thrift::metadata::ThriftType;


void GeneratedStructMetadata<::cpp2::FooEx>::genMetadata(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.FooEx", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_FooEx = res.first->second;
  module_FooEx.name = "module.FooEx";
  module_FooEx.is_union = false;
}

void GeneratedExceptionMetadata<::cpp2::FooEx>::genMetadata(ThriftMetadata& metadata) {
  auto res = metadata.exceptions.emplace("module.FooEx", ::apache::thrift::metadata::ThriftException{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftException& module_FooEx = res.first->second;
  module_FooEx.name = "module.FooEx";
}
} // apache::thrift::detail::metadata