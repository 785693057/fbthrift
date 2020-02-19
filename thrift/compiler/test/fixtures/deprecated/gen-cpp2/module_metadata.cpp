/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include <thrift/lib/cpp2/gen/module_metadata_cpp.h>
#include "thrift/compiler/test/fixtures/deprecated/gen-cpp2/module_metadata.h"

namespace apache {
namespace thrift {
namespace detail {
namespace md {
using ThriftMetadata = ::apache::thrift::metadata::ThriftMetadata;
using ThriftPrimitiveType = ::apache::thrift::metadata::ThriftPrimitiveType;
using ThriftType = ::apache::thrift::metadata::ThriftType;


void StructMetadata<::cpp2::House>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.House", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_House = res.first->second;
  module_House.name = "module.House";
  module_House.is_union = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_House_fields[] = {
    {1, "id", false, std::make_unique<Typedef>("module.ColorID", std::make_unique<Primitive>(ThriftPrimitiveType::I64))},
    {2, "houseName", false, std::make_unique<Primitive>(ThriftPrimitiveType::STRING)},
    {3, "houseColors", true, std::make_unique<Set>(std::make_unique<Typedef>("module.ColorID", std::make_unique<Primitive>(ThriftPrimitiveType::I64)))},
  };
  for (const auto& f : module_House_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id = std::get<0>(f);
    field.name = std::get<1>(f);
    field.is_optional = std::get<2>(f);
    std::get<3>(f)->initialize(field.type);
    module_House.fields.push_back(std::move(field));
  }
}
void StructMetadata<::cpp2::Field>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.Field", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_Field = res.first->second;
  module_Field.name = "module.Field";
  module_Field.is_union = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  module_Field_fields[] = {
    {1, "id", false, std::make_unique<Typedef>("module.ColorID", std::make_unique<Primitive>(ThriftPrimitiveType::I64))},
    {2, "fieldType", false, std::make_unique<Primitive>(ThriftPrimitiveType::I32)},
  };
  for (const auto& f : module_Field_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id = std::get<0>(f);
    field.name = std::get<1>(f);
    field.is_optional = std::get<2>(f);
    std::get<3>(f)->initialize(field.type);
    module_Field.fields.push_back(std::move(field));
  }
}

} // namespace md
} // namespace detail
} // namespace thrift
} // namespace apache