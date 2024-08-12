#pragma once

#include "apigear.json.adapter.h"
#include "Generated/api/Testbed1_data.h"

static void from_json(const nlohmann::json& j, FTestbed1StructBool& p)
{
	p.fieldBool = j.at("fieldBool").get<bool>();
}

static void to_json(nlohmann::json& j, const FTestbed1StructBool& p)
{
	j = nlohmann::json{{"fieldBool", p.fieldBool}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructInt& p)
{
	p.fieldInt = j.at("fieldInt").get<int32>();
}

static void to_json(nlohmann::json& j, const FTestbed1StructInt& p)
{
	j = nlohmann::json{{"fieldInt", p.fieldInt}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructFloat& p)
{
	p.fieldFloat = j.at("fieldFloat").get<float>();
}

static void to_json(nlohmann::json& j, const FTestbed1StructFloat& p)
{
	j = nlohmann::json{{"fieldFloat", p.fieldFloat}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructString& p)
{
	p.fieldString = j.at("fieldString").get<FString>();
}

static void to_json(nlohmann::json& j, const FTestbed1StructString& p)
{
	j = nlohmann::json{{"fieldString", p.fieldString}};
}
