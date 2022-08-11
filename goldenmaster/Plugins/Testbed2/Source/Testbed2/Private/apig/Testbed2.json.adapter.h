#pragma once

#include "apigear.json.adapter.h"

static void from_json(const nlohmann::json& j, FTestbed2Struct1& p) {
    p.field1 = j.at("field1").get<int32>();
}

static void to_json(nlohmann::json& j, const FTestbed2Struct1& p) {
    j = nlohmann::json{
        {"field1", p.field1}
        };
}

static void from_json(const nlohmann::json& j, FTestbed2Struct2& p) {
    p.field1 = j.at("field1").get<int32>();
    p.field2 = j.at("field2").get<int32>();
}

static void to_json(nlohmann::json& j, const FTestbed2Struct2& p) {
    j = nlohmann::json{
        {"field1", p.field1},
        {"field2", p.field2}
        };
}

static void from_json(const nlohmann::json& j, FTestbed2Struct3& p) {
    p.field1 = j.at("field1").get<int32>();
    p.field2 = j.at("field2").get<int32>();
    p.field3 = j.at("field3").get<int32>();
}

static void to_json(nlohmann::json& j, const FTestbed2Struct3& p) {
    j = nlohmann::json{
        {"field1", p.field1},
        {"field2", p.field2},
        {"field3", p.field3}
        };
}

static void from_json(const nlohmann::json& j, FTestbed2Struct4& p) {
    p.field1 = j.at("field1").get<int32>();
    p.field2 = j.at("field2").get<int32>();
    p.field3 = j.at("field3").get<int32>();
    p.field4 = j.at("field4").get<int32>();
}

static void to_json(nlohmann::json& j, const FTestbed2Struct4& p) {
    j = nlohmann::json{
        {"field1", p.field1},
        {"field2", p.field2},
        {"field3", p.field3},
        {"field4", p.field4}
        };
}

static void from_json(const nlohmann::json& j, FTestbed2NestedStruct1& p) {
    p.field1 = j.at("field1").get<FTestbed2Struct1>();
}

static void to_json(nlohmann::json& j, const FTestbed2NestedStruct1& p) {
    j = nlohmann::json{
        {"field1", p.field1}
        };
}

static void from_json(const nlohmann::json& j, FTestbed2NestedStruct2& p) {
    p.field1 = j.at("field1").get<FTestbed2Struct1>();
    p.field2 = j.at("field2").get<FTestbed2Struct2>();
}

static void to_json(nlohmann::json& j, const FTestbed2NestedStruct2& p) {
    j = nlohmann::json{
        {"field1", p.field1},
        {"field2", p.field2}
        };
}

static void from_json(const nlohmann::json& j, FTestbed2NestedStruct3& p) {
    p.field1 = j.at("field1").get<FTestbed2Struct1>();
    p.field2 = j.at("field2").get<FTestbed2Struct2>();
    p.field3 = j.at("field3").get<FTestbed2Struct3>();
}

static void to_json(nlohmann::json& j, const FTestbed2NestedStruct3& p) {
    j = nlohmann::json{
        {"field1", p.field1},
        {"field2", p.field2},
        {"field3", p.field3}
        };
}
