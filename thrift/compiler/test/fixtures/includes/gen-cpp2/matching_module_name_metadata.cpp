/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include <thrift/lib/cpp2/gen/module_metadata_cpp.h>
#include "thrift/compiler/test/fixtures/includes/gen-cpp2/matching_module_name_metadata.h"

namespace apache {
namespace thrift {
namespace detail {
namespace md {
using ThriftMetadata = ::apache::thrift::metadata::ThriftMetadata;
using ThriftPrimitiveType = ::apache::thrift::metadata::ThriftPrimitiveType;
using ThriftType = ::apache::thrift::metadata::ThriftType;


void StructMetadata<::matching_module_name::MyStruct>::gen(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("matching_module_name.MyStruct", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& matching_module_name_MyStruct = res.first->second;
  matching_module_name_MyStruct.name = "matching_module_name.MyStruct";
  matching_module_name_MyStruct.is_union = false;
  static const std::tuple<int32_t, const char*, bool, std::unique_ptr<MetadataTypeInterface>>
  matching_module_name_MyStruct_fields[] = {
    {1, "OtherStructField", false, std::make_unique<Struct< ::matching_module_name::OtherStruct>>("matching_module_name.OtherStruct", metadata)},
  };
  for (const auto& f : matching_module_name_MyStruct_fields) {
    ::apache::thrift::metadata::ThriftField field;
    field.id = std::get<0>(f);
    field.name = std::get<1>(f);
    field.is_optional = std::get<2>(f);
    std::get<3>(f)->initialize(field.type);
    matching_module_name_MyStruct.fields.push_back(std::move(field));
  }
}

} // namespace md
} // namespace detail
} // namespace thrift
} // namespace apache