#pragma once

#include "apigear.json.adapter.h"
#include "TbSimple/Generated/api/TbSimple_data.h"
#include "TbSimple/Generated/api/TbSimpleVoidInterfaceInterface.h"
#include "TbSimple/Generated/api/TbSimpleSimpleInterfaceInterface.h"
#include "TbSimple/Generated/api/TbSimpleSimpleArrayInterfaceInterface.h"
#include "TbSimple/Generated/api/TbSimpleNoPropertiesInterfaceInterface.h"
#include "TbSimple/Generated/api/TbSimpleNoOperationsInterfaceInterface.h"
#include "TbSimple/Generated/api/TbSimpleNoSignalsInterfaceInterface.h"
#include "TbSimple/Generated/api/TbSimpleEmptyInterfaceInterface.h"

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSimpleVoidInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSimpleVoidInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSimpleSimpleInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->SetPropBool(j.at("propBool").get<bool>());
	Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->SetPropInt(j.at("propInt").get<int32>());
	Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->SetPropInt32(j.at("propInt32").get<int32>());
	Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->SetPropInt64(j.at("propInt64").get<int64>());
	Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->SetPropFloat(j.at("propFloat").get<float>());
	Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->SetPropFloat32(j.at("propFloat32").get<float>());
	Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->SetPropFloat64(j.at("propFloat64").get<double>());
	Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->SetPropString(j.at("propString").get<FString>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSimpleSimpleInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"propBool", Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->GetPropBool()}, {"propInt", Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->GetPropInt()}, {"propInt32", Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->GetPropInt32()}, {"propInt64", Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->GetPropInt64()}, {"propFloat", Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->GetPropFloat()}, {"propFloat32", Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->GetPropFloat32()}, {"propFloat64", Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->GetPropFloat64()}, {"propString", Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->GetPropString()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->SetPropBool(j.at("propBool").get<TArray<bool>>());
	Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->SetPropInt(j.at("propInt").get<TArray<int32>>());
	Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->SetPropInt32(j.at("propInt32").get<TArray<int32>>());
	Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->SetPropInt64(j.at("propInt64").get<TArray<int64>>());
	Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->SetPropFloat(j.at("propFloat").get<TArray<float>>());
	Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->SetPropFloat32(j.at("propFloat32").get<TArray<float>>());
	Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->SetPropFloat64(j.at("propFloat64").get<TArray<double>>());
	Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->SetPropString(j.at("propString").get<TArray<FString>>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"propBool", Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->GetPropBool()}, {"propInt", Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->GetPropInt()}, {"propInt32", Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->GetPropInt32()}, {"propInt64", Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->GetPropInt64()}, {"propFloat", Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->GetPropFloat()}, {"propFloat32", Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->GetPropFloat32()}, {"propFloat64", Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->GetPropFloat64()}, {"propString", Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->GetPropString()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSimpleNoOperationsInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITbSimpleNoOperationsInterfaceInterface>(p.GetObject())->SetPropBool(j.at("propBool").get<bool>());
	Cast<ITbSimpleNoOperationsInterfaceInterface>(p.GetObject())->SetPropInt(j.at("propInt").get<int32>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSimpleNoOperationsInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"propBool", Cast<ITbSimpleNoOperationsInterfaceInterface>(p.GetObject())->GetPropBool()}, {"propInt", Cast<ITbSimpleNoOperationsInterfaceInterface>(p.GetObject())->GetPropInt()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSimpleNoSignalsInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITbSimpleNoSignalsInterfaceInterface>(p.GetObject())->SetPropBool(j.at("propBool").get<bool>());
	Cast<ITbSimpleNoSignalsInterfaceInterface>(p.GetObject())->SetPropInt(j.at("propInt").get<int32>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSimpleNoSignalsInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"propBool", Cast<ITbSimpleNoSignalsInterfaceInterface>(p.GetObject())->GetPropBool()}, {"propInt", Cast<ITbSimpleNoSignalsInterfaceInterface>(p.GetObject())->GetPropInt()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSimpleEmptyInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSimpleEmptyInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{};
}
