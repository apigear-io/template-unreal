#pragma once

#include "apigear.json.adapter.h"
#include "Testbed1/Generated/api/Testbed1_data.h"
#include "Testbed1/Generated/api/Testbed1StructInterfaceInterface.h"
#include "Testbed1/Generated/api/Testbed1StructArrayInterfaceInterface.h"
#include "Testbed1/Generated/api/Testbed1StructArray2InterfaceInterface.h"

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

static void from_json(const nlohmann::json& j, TScriptInterface<ITestbed1StructInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITestbed1StructInterfaceInterface>(p.GetObject())->SetPropBool(j.at("propBool").get<FTestbed1StructBool>());
	Cast<ITestbed1StructInterfaceInterface>(p.GetObject())->SetPropInt(j.at("propInt").get<FTestbed1StructInt>());
	Cast<ITestbed1StructInterfaceInterface>(p.GetObject())->SetPropFloat(j.at("propFloat").get<FTestbed1StructFloat>());
	Cast<ITestbed1StructInterfaceInterface>(p.GetObject())->SetPropString(j.at("propString").get<FTestbed1StructString>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITestbed1StructInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"propBool", Cast<ITestbed1StructInterfaceInterface>(p.GetObject())->GetPropBool()}, {"propInt", Cast<ITestbed1StructInterfaceInterface>(p.GetObject())->GetPropInt()}, {"propFloat", Cast<ITestbed1StructInterfaceInterface>(p.GetObject())->GetPropFloat()}, {"propString", Cast<ITestbed1StructInterfaceInterface>(p.GetObject())->GetPropString()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITestbed1StructArrayInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->SetPropBool(j.at("propBool").get<TArray<FTestbed1StructBool>>());
	Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->SetPropInt(j.at("propInt").get<TArray<FTestbed1StructInt>>());
	Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->SetPropFloat(j.at("propFloat").get<TArray<FTestbed1StructFloat>>());
	Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->SetPropString(j.at("propString").get<TArray<FTestbed1StructString>>());
	Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->SetPropEnum(j.at("propEnum").get<TArray<ETestbed1Enum0>>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITestbed1StructArrayInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"propBool", Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->GetPropBool()}, {"propInt", Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->GetPropInt()}, {"propFloat", Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->GetPropFloat()}, {"propString", Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->GetPropString()}, {"propEnum", Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->GetPropEnum()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITestbed1StructArray2InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->SetPropBool(j.at("propBool").get<FTestbed1StructBoolWithArray>());
	Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->SetPropInt(j.at("propInt").get<FTestbed1StructIntWithArray>());
	Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->SetPropFloat(j.at("propFloat").get<FTestbed1StructFloatWithArray>());
	Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->SetPropString(j.at("propString").get<FTestbed1StructStringWithArray>());
	Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->SetPropEnum(j.at("propEnum").get<FTestbed1StructEnumWithArray>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITestbed1StructArray2InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"propBool", Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->GetPropBool()}, {"propInt", Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->GetPropInt()}, {"propFloat", Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->GetPropFloat()}, {"propString", Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->GetPropString()}, {"propEnum", Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->GetPropEnum()}};
}
