/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include <thrift/lib/cpp2/gen/module_metadata_cpp.h>
#include "thrift/compiler/test/fixtures/templated-deserialize/gen-cpp2/module_metadata.h"

namespace apache::thrift::detail::metadata {

using ThriftMetadata = ::apache::thrift::metadata::ThriftMetadata;
using ThriftPrimitiveType = ::apache::thrift::metadata::ThriftPrimitiveType;
using ThriftType = ::apache::thrift::metadata::ThriftType;

void GeneratedEnumMetadata<::cpp2::MyEnumA>::genMetadata(ThriftMetadata& metadata) {
  auto res = metadata.enums.emplace("module.MyEnumA", ::apache::thrift::metadata::ThriftEnum{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftEnum& module_MyEnumA = res.first->second;
  module_MyEnumA.name = "module.MyEnumA";
  module_MyEnumA.elements[1] = "fieldA";
  module_MyEnumA.elements[2] = "fieldB";
  module_MyEnumA.elements[4] = "fieldC";
}

void GeneratedStructMetadata<::cpp2::SmallStruct>::genMetadata(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.SmallStruct", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_SmallStruct = res.first->second;
  module_SmallStruct.name = "module.SmallStruct";
  module_SmallStruct.is_union = false;
  ::apache::thrift::metadata::ThriftField module_SmallStruct_small_A_1;
  module_SmallStruct_small_A_1.id = 1;
  module_SmallStruct_small_A_1.name = "small_A";
  module_SmallStruct_small_A_1.is_optional = false;
  auto module_SmallStruct_small_A_1_type = std::make_unique<Primitive>(ThriftPrimitiveType::BOOL);
  module_SmallStruct_small_A_1_type->initialize(module_SmallStruct_small_A_1.type);
  module_SmallStruct.fields.push_back(std::move(module_SmallStruct_small_A_1));
  ::apache::thrift::metadata::ThriftField module_SmallStruct_small_B_2;
  module_SmallStruct_small_B_2.id = 2;
  module_SmallStruct_small_B_2.name = "small_B";
  module_SmallStruct_small_B_2.is_optional = false;
  auto module_SmallStruct_small_B_2_type = std::make_unique<Primitive>(ThriftPrimitiveType::I32);
  module_SmallStruct_small_B_2_type->initialize(module_SmallStruct_small_B_2.type);
  module_SmallStruct.fields.push_back(std::move(module_SmallStruct_small_B_2));
}
void GeneratedStructMetadata<::cpp2::containerStruct>::genMetadata(ThriftMetadata& metadata) {
  auto res = metadata.structs.emplace("module.containerStruct", ::apache::thrift::metadata::ThriftStruct{});
  if (!res.second) {
    return;
  }
  ::apache::thrift::metadata::ThriftStruct& module_containerStruct = res.first->second;
  module_containerStruct.name = "module.containerStruct";
  module_containerStruct.is_union = false;
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldA_1;
  module_containerStruct_fieldA_1.id = 1;
  module_containerStruct_fieldA_1.name = "fieldA";
  module_containerStruct_fieldA_1.is_optional = false;
  auto module_containerStruct_fieldA_1_type = std::make_unique<Primitive>(ThriftPrimitiveType::BOOL);
  module_containerStruct_fieldA_1_type->initialize(module_containerStruct_fieldA_1.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldA_1));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldB_2;
  module_containerStruct_fieldB_2.id = 2;
  module_containerStruct_fieldB_2.name = "fieldB";
  module_containerStruct_fieldB_2.is_optional = false;
  auto module_containerStruct_fieldB_2_type = std::make_unique<Map>(std::make_unique<Primitive>(ThriftPrimitiveType::STRING), std::make_unique<Primitive>(ThriftPrimitiveType::BOOL));
  module_containerStruct_fieldB_2_type->initialize(module_containerStruct_fieldB_2.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldB_2));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldC_3;
  module_containerStruct_fieldC_3.id = 3;
  module_containerStruct_fieldC_3.name = "fieldC";
  module_containerStruct_fieldC_3.is_optional = false;
  auto module_containerStruct_fieldC_3_type = std::make_unique<Set>(std::make_unique<Primitive>(ThriftPrimitiveType::I32));
  module_containerStruct_fieldC_3_type->initialize(module_containerStruct_fieldC_3.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldC_3));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldD_4;
  module_containerStruct_fieldD_4.id = 4;
  module_containerStruct_fieldD_4.name = "fieldD";
  module_containerStruct_fieldD_4.is_optional = false;
  auto module_containerStruct_fieldD_4_type = std::make_unique<Primitive>(ThriftPrimitiveType::STRING);
  module_containerStruct_fieldD_4_type->initialize(module_containerStruct_fieldD_4.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldD_4));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldE_5;
  module_containerStruct_fieldE_5.id = 5;
  module_containerStruct_fieldE_5.name = "fieldE";
  module_containerStruct_fieldE_5.is_optional = false;
  auto module_containerStruct_fieldE_5_type = std::make_unique<Primitive>(ThriftPrimitiveType::STRING);
  module_containerStruct_fieldE_5_type->initialize(module_containerStruct_fieldE_5.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldE_5));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldF_6;
  module_containerStruct_fieldF_6.id = 6;
  module_containerStruct_fieldF_6.name = "fieldF";
  module_containerStruct_fieldF_6.is_optional = false;
  auto module_containerStruct_fieldF_6_type = std::make_unique<List>(std::make_unique<List>(std::make_unique<List>(std::make_unique<Primitive>(ThriftPrimitiveType::I32))));
  module_containerStruct_fieldF_6_type->initialize(module_containerStruct_fieldF_6.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldF_6));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldG_7;
  module_containerStruct_fieldG_7.id = 7;
  module_containerStruct_fieldG_7.name = "fieldG";
  module_containerStruct_fieldG_7.is_optional = false;
  auto module_containerStruct_fieldG_7_type = std::make_unique<Map>(std::make_unique<Primitive>(ThriftPrimitiveType::STRING), std::make_unique<Map>(std::make_unique<Primitive>(ThriftPrimitiveType::STRING), std::make_unique<Map>(std::make_unique<Primitive>(ThriftPrimitiveType::STRING), std::make_unique<Primitive>(ThriftPrimitiveType::I32))));
  module_containerStruct_fieldG_7_type->initialize(module_containerStruct_fieldG_7.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldG_7));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldH_8;
  module_containerStruct_fieldH_8.id = 8;
  module_containerStruct_fieldH_8.name = "fieldH";
  module_containerStruct_fieldH_8.is_optional = false;
  auto module_containerStruct_fieldH_8_type = std::make_unique<List>(std::make_unique<Set>(std::make_unique<Primitive>(ThriftPrimitiveType::I32)));
  module_containerStruct_fieldH_8_type->initialize(module_containerStruct_fieldH_8.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldH_8));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldI_9;
  module_containerStruct_fieldI_9.id = 9;
  module_containerStruct_fieldI_9.name = "fieldI";
  module_containerStruct_fieldI_9.is_optional = false;
  auto module_containerStruct_fieldI_9_type = std::make_unique<Primitive>(ThriftPrimitiveType::BOOL);
  module_containerStruct_fieldI_9_type->initialize(module_containerStruct_fieldI_9.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldI_9));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldJ_10;
  module_containerStruct_fieldJ_10.id = 10;
  module_containerStruct_fieldJ_10.name = "fieldJ";
  module_containerStruct_fieldJ_10.is_optional = false;
  auto module_containerStruct_fieldJ_10_type = std::make_unique<Map>(std::make_unique<Primitive>(ThriftPrimitiveType::STRING), std::make_unique<List>(std::make_unique<Primitive>(ThriftPrimitiveType::I32)));
  module_containerStruct_fieldJ_10_type->initialize(module_containerStruct_fieldJ_10.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldJ_10));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldK_11;
  module_containerStruct_fieldK_11.id = 11;
  module_containerStruct_fieldK_11.name = "fieldK";
  module_containerStruct_fieldK_11.is_optional = false;
  auto module_containerStruct_fieldK_11_type = std::make_unique<List>(std::make_unique<List>(std::make_unique<List>(std::make_unique<List>(std::make_unique<Primitive>(ThriftPrimitiveType::I32)))));
  module_containerStruct_fieldK_11_type->initialize(module_containerStruct_fieldK_11.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldK_11));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldL_12;
  module_containerStruct_fieldL_12.id = 12;
  module_containerStruct_fieldL_12.name = "fieldL";
  module_containerStruct_fieldL_12.is_optional = false;
  auto module_containerStruct_fieldL_12_type = std::make_unique<Set>(std::make_unique<Set>(std::make_unique<Set>(std::make_unique<Primitive>(ThriftPrimitiveType::BOOL))));
  module_containerStruct_fieldL_12_type->initialize(module_containerStruct_fieldL_12.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldL_12));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldM_13;
  module_containerStruct_fieldM_13.id = 13;
  module_containerStruct_fieldM_13.name = "fieldM";
  module_containerStruct_fieldM_13.is_optional = false;
  auto module_containerStruct_fieldM_13_type = std::make_unique<Map>(std::make_unique<Set>(std::make_unique<List>(std::make_unique<Primitive>(ThriftPrimitiveType::I32))), std::make_unique<Map>(std::make_unique<List>(std::make_unique<Set>(std::make_unique<Primitive>(ThriftPrimitiveType::STRING))), std::make_unique<Primitive>(ThriftPrimitiveType::STRING)));
  module_containerStruct_fieldM_13_type->initialize(module_containerStruct_fieldM_13.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldM_13));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldN_14;
  module_containerStruct_fieldN_14.id = 14;
  module_containerStruct_fieldN_14.name = "fieldN";
  module_containerStruct_fieldN_14.is_optional = false;
  auto module_containerStruct_fieldN_14_type = std::make_unique<List>(std::make_unique<Typedef>("module.IndirectionA", std::make_unique<Primitive>(ThriftPrimitiveType::I64)));
  module_containerStruct_fieldN_14_type->initialize(module_containerStruct_fieldN_14.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldN_14));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldO_15;
  module_containerStruct_fieldO_15.id = 15;
  module_containerStruct_fieldO_15.name = "fieldO";
  module_containerStruct_fieldO_15.is_optional = false;
  auto module_containerStruct_fieldO_15_type = std::make_unique<List>(std::make_unique<Typedef>("module.IndirectionB", std::make_unique<Primitive>(ThriftPrimitiveType::DOUBLE)));
  module_containerStruct_fieldO_15_type->initialize(module_containerStruct_fieldO_15.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldO_15));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldP_16;
  module_containerStruct_fieldP_16.id = 16;
  module_containerStruct_fieldP_16.name = "fieldP";
  module_containerStruct_fieldP_16.is_optional = false;
  auto module_containerStruct_fieldP_16_type = std::make_unique<List>(std::make_unique<Typedef>("module.IndirectionC", std::make_unique<Primitive>(ThriftPrimitiveType::I32)));
  module_containerStruct_fieldP_16_type->initialize(module_containerStruct_fieldP_16.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldP_16));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldQ_17;
  module_containerStruct_fieldQ_17.id = 17;
  module_containerStruct_fieldQ_17.name = "fieldQ";
  module_containerStruct_fieldQ_17.is_optional = false;
  auto module_containerStruct_fieldQ_17_type = std::make_unique<Enum< ::cpp2::MyEnumA>>("module.MyEnumA", metadata);
  module_containerStruct_fieldQ_17_type->initialize(module_containerStruct_fieldQ_17.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldQ_17));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldR_18;
  module_containerStruct_fieldR_18.id = 18;
  module_containerStruct_fieldR_18.name = "fieldR";
  module_containerStruct_fieldR_18.is_optional = false;
  auto module_containerStruct_fieldR_18_type = std::make_unique<Map>(std::make_unique<Primitive>(ThriftPrimitiveType::STRING), std::make_unique<Primitive>(ThriftPrimitiveType::BOOL));
  module_containerStruct_fieldR_18_type->initialize(module_containerStruct_fieldR_18.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldR_18));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldS_19;
  module_containerStruct_fieldS_19.id = 19;
  module_containerStruct_fieldS_19.name = "fieldS";
  module_containerStruct_fieldS_19.is_optional = false;
  auto module_containerStruct_fieldS_19_type = std::make_unique<Struct< ::cpp2::SmallStruct>>("module.SmallStruct", metadata);
  module_containerStruct_fieldS_19_type->initialize(module_containerStruct_fieldS_19.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldS_19));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldT_20;
  module_containerStruct_fieldT_20.id = 20;
  module_containerStruct_fieldT_20.name = "fieldT";
  module_containerStruct_fieldT_20.is_optional = false;
  auto module_containerStruct_fieldT_20_type = std::make_unique<Struct< ::cpp2::SmallStruct>>("module.SmallStruct", metadata);
  module_containerStruct_fieldT_20_type->initialize(module_containerStruct_fieldT_20.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldT_20));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldU_21;
  module_containerStruct_fieldU_21.id = 21;
  module_containerStruct_fieldU_21.name = "fieldU";
  module_containerStruct_fieldU_21.is_optional = false;
  auto module_containerStruct_fieldU_21_type = std::make_unique<Struct< ::cpp2::SmallStruct>>("module.SmallStruct", metadata);
  module_containerStruct_fieldU_21_type->initialize(module_containerStruct_fieldU_21.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldU_21));
  ::apache::thrift::metadata::ThriftField module_containerStruct_fieldX_23;
  module_containerStruct_fieldX_23.id = 23;
  module_containerStruct_fieldX_23.name = "fieldX";
  module_containerStruct_fieldX_23.is_optional = false;
  auto module_containerStruct_fieldX_23_type = std::make_unique<Struct< ::cpp2::SmallStruct>>("module.SmallStruct", metadata);
  module_containerStruct_fieldX_23_type->initialize(module_containerStruct_fieldX_23.type);
  module_containerStruct.fields.push_back(std::move(module_containerStruct_fieldX_23));
}

} // apache::thrift::detail::metadata