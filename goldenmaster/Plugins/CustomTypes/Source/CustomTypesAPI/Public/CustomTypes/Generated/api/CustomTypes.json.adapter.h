#pragma once

#include "apigear.json.adapter.h"
#include "CustomTypes/Generated/api/CustomTypes_data.h"

static void from_json(const nlohmann::json& j, FCustomTypesVector3D& p)
{
	p.x = j.at("x").get<float>();
	p.y = j.at("y").get<float>();
	p.z = j.at("z").get<float>();
}

static void to_json(nlohmann::json& j, const FCustomTypesVector3D& p)
{
	j = nlohmann::json{{"x", p.x}, {"y", p.y}, {"z", p.z}};
}
