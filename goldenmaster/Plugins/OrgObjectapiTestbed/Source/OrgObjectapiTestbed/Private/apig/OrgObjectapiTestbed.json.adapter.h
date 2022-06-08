#pragma once

#include "apigear.json.adapter.h"

static void from_json(const nlohmann::json& j, FOrgObjectapiTestbedStruct1& p) {
    p.field1 = j.at("field1").get<bool>();
    p.field2 = j.at("field2").get<int32>();
    p.field3 = j.at("field3").get<float>();
    p.field4 = j.at("field4").get<FString>();
}

static void to_json(nlohmann::json& j, const FOrgObjectapiTestbedStruct1& p) {
    j = nlohmann::json{
        {"field1", p.field1},
        {"field2", p.field2},
        {"field3", p.field3},
        {"field4", p.field4}
        };
}
