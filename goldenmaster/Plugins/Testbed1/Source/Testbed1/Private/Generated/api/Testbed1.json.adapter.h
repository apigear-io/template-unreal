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

static void from_json(const nlohmann::json& j, FTestbed1StructStruct& p)
{
	p.fieldString = j.at("fieldString").get<FTestbed1StructString>();
}

static void to_json(nlohmann::json& j, const FTestbed1StructStruct& p)
{
	j = nlohmann::json{{"fieldString", p.fieldString}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructEnum& p)
{
	p.fieldEnum = j.at("fieldEnum").get<ETestbed1Enum0>();
}

static void to_json(nlohmann::json& j, const FTestbed1StructEnum& p)
{
	j = nlohmann::json{{"fieldEnum", p.fieldEnum}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructBoolWithArray& p)
{
	p.fieldBool = j.at("fieldBool").get<TArray<bool>>();
}

static void to_json(nlohmann::json& j, const FTestbed1StructBoolWithArray& p)
{
	j = nlohmann::json{{"fieldBool", p.fieldBool}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructIntWithArray& p)
{
	p.fieldInt = j.at("fieldInt").get<TArray<int32>>();
}

static void to_json(nlohmann::json& j, const FTestbed1StructIntWithArray& p)
{
	j = nlohmann::json{{"fieldInt", p.fieldInt}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructFloatWithArray& p)
{
	p.fieldFloat = j.at("fieldFloat").get<TArray<float>>();
}

static void to_json(nlohmann::json& j, const FTestbed1StructFloatWithArray& p)
{
	j = nlohmann::json{{"fieldFloat", p.fieldFloat}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructStringWithArray& p)
{
	p.fieldString = j.at("fieldString").get<TArray<FString>>();
}

static void to_json(nlohmann::json& j, const FTestbed1StructStringWithArray& p)
{
	j = nlohmann::json{{"fieldString", p.fieldString}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructStructWithArray& p)
{
	p.fieldStruct = j.at("fieldStruct").get<TArray<FTestbed1StructStringWithArray>>();
}

static void to_json(nlohmann::json& j, const FTestbed1StructStructWithArray& p)
{
	j = nlohmann::json{{"fieldStruct", p.fieldStruct}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructEnumWithArray& p)
{
	p.fieldEnum = j.at("fieldEnum").get<TArray<ETestbed1Enum0>>();
}

static void to_json(nlohmann::json& j, const FTestbed1StructEnumWithArray& p)
{
	j = nlohmann::json{{"fieldEnum", p.fieldEnum}};
}
