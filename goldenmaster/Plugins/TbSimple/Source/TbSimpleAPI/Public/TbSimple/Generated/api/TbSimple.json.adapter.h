#pragma once

#include "apigear.json.adapter.h"
#include "TbSimple/Generated/TbSimpleLogCategories.h"
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

	const auto propBoolIter = j.find("propBool");
	if (propBoolIter != j.end() && !propBoolIter->is_null() && propBoolIter->is_boolean())
	{
		Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->SetPropBool(propBoolIter->get<bool>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propBool' missing or type mismatch in ITbSimpleSimpleInterfaceInterface -> ignore"));
	}

	const auto propIntIter = j.find("propInt");
	if (propIntIter != j.end() && !propIntIter->is_null() && propIntIter->is_number_integer())
	{
		Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->SetPropInt(propIntIter->get<int32>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propInt' missing or type mismatch in ITbSimpleSimpleInterfaceInterface -> ignore"));
	}

	const auto propInt32Iter = j.find("propInt32");
	if (propInt32Iter != j.end() && !propInt32Iter->is_null() && propInt32Iter->is_number_integer())
	{
		Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->SetPropInt32(propInt32Iter->get<int32>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propInt32' missing or type mismatch in ITbSimpleSimpleInterfaceInterface -> ignore"));
	}

	const auto propInt64Iter = j.find("propInt64");
	if (propInt64Iter != j.end() && !propInt64Iter->is_null() && propInt64Iter->is_number_integer())
	{
		Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->SetPropInt64(propInt64Iter->get<int64>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propInt64' missing or type mismatch in ITbSimpleSimpleInterfaceInterface -> ignore"));
	}

	const auto propFloatIter = j.find("propFloat");
	if (propFloatIter != j.end() && !propFloatIter->is_null() && propFloatIter->is_number())
	{
		Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->SetPropFloat(propFloatIter->get<float>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propFloat' missing or type mismatch in ITbSimpleSimpleInterfaceInterface -> ignore"));
	}

	const auto propFloat32Iter = j.find("propFloat32");
	if (propFloat32Iter != j.end() && !propFloat32Iter->is_null() && propFloat32Iter->is_number())
	{
		Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->SetPropFloat32(propFloat32Iter->get<float>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propFloat32' missing or type mismatch in ITbSimpleSimpleInterfaceInterface -> ignore"));
	}

	const auto propFloat64Iter = j.find("propFloat64");
	if (propFloat64Iter != j.end() && !propFloat64Iter->is_null() && propFloat64Iter->is_number())
	{
		Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->SetPropFloat64(propFloat64Iter->get<double>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propFloat64' missing or type mismatch in ITbSimpleSimpleInterfaceInterface -> ignore"));
	}

	const auto propStringIter = j.find("propString");
	if (propStringIter != j.end() && !propStringIter->is_null() && propStringIter->is_string())
	{
		Cast<ITbSimpleSimpleInterfaceInterface>(p.GetObject())->SetPropString(propStringIter->get<FString>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propString' missing or type mismatch in ITbSimpleSimpleInterfaceInterface -> ignore"));
	}
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

	const auto propBoolIter = j.find("propBool");
	if (propBoolIter != j.end() && !propBoolIter->is_null() && propBoolIter->is_array())
	{
		Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->SetPropBool(propBoolIter->get<TArray<bool>>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propBool' missing or type mismatch in ITbSimpleSimpleArrayInterfaceInterface -> ignore"));
	}

	const auto propIntIter = j.find("propInt");
	if (propIntIter != j.end() && !propIntIter->is_null() && propIntIter->is_array())
	{
		Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->SetPropInt(propIntIter->get<TArray<int32>>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propInt' missing or type mismatch in ITbSimpleSimpleArrayInterfaceInterface -> ignore"));
	}

	const auto propInt32Iter = j.find("propInt32");
	if (propInt32Iter != j.end() && !propInt32Iter->is_null() && propInt32Iter->is_array())
	{
		Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->SetPropInt32(propInt32Iter->get<TArray<int32>>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propInt32' missing or type mismatch in ITbSimpleSimpleArrayInterfaceInterface -> ignore"));
	}

	const auto propInt64Iter = j.find("propInt64");
	if (propInt64Iter != j.end() && !propInt64Iter->is_null() && propInt64Iter->is_array())
	{
		Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->SetPropInt64(propInt64Iter->get<TArray<int64>>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propInt64' missing or type mismatch in ITbSimpleSimpleArrayInterfaceInterface -> ignore"));
	}

	const auto propFloatIter = j.find("propFloat");
	if (propFloatIter != j.end() && !propFloatIter->is_null() && propFloatIter->is_array())
	{
		Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->SetPropFloat(propFloatIter->get<TArray<float>>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propFloat' missing or type mismatch in ITbSimpleSimpleArrayInterfaceInterface -> ignore"));
	}

	const auto propFloat32Iter = j.find("propFloat32");
	if (propFloat32Iter != j.end() && !propFloat32Iter->is_null() && propFloat32Iter->is_array())
	{
		Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->SetPropFloat32(propFloat32Iter->get<TArray<float>>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propFloat32' missing or type mismatch in ITbSimpleSimpleArrayInterfaceInterface -> ignore"));
	}

	const auto propFloat64Iter = j.find("propFloat64");
	if (propFloat64Iter != j.end() && !propFloat64Iter->is_null() && propFloat64Iter->is_array())
	{
		Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->SetPropFloat64(propFloat64Iter->get<TArray<double>>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propFloat64' missing or type mismatch in ITbSimpleSimpleArrayInterfaceInterface -> ignore"));
	}

	const auto propStringIter = j.find("propString");
	if (propStringIter != j.end() && !propStringIter->is_null() && propStringIter->is_array())
	{
		Cast<ITbSimpleSimpleArrayInterfaceInterface>(p.GetObject())->SetPropString(propStringIter->get<TArray<FString>>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propString' missing or type mismatch in ITbSimpleSimpleArrayInterfaceInterface -> ignore"));
	}
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

	const auto propBoolIter = j.find("propBool");
	if (propBoolIter != j.end() && !propBoolIter->is_null() && propBoolIter->is_boolean())
	{
		Cast<ITbSimpleNoOperationsInterfaceInterface>(p.GetObject())->SetPropBool(propBoolIter->get<bool>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propBool' missing or type mismatch in ITbSimpleNoOperationsInterfaceInterface -> ignore"));
	}

	const auto propIntIter = j.find("propInt");
	if (propIntIter != j.end() && !propIntIter->is_null() && propIntIter->is_number_integer())
	{
		Cast<ITbSimpleNoOperationsInterfaceInterface>(p.GetObject())->SetPropInt(propIntIter->get<int32>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propInt' missing or type mismatch in ITbSimpleNoOperationsInterfaceInterface -> ignore"));
	}
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

	const auto propBoolIter = j.find("propBool");
	if (propBoolIter != j.end() && !propBoolIter->is_null() && propBoolIter->is_boolean())
	{
		Cast<ITbSimpleNoSignalsInterfaceInterface>(p.GetObject())->SetPropBool(propBoolIter->get<bool>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propBool' missing or type mismatch in ITbSimpleNoSignalsInterfaceInterface -> ignore"));
	}

	const auto propIntIter = j.find("propInt");
	if (propIntIter != j.end() && !propIntIter->is_null() && propIntIter->is_number_integer())
	{
		Cast<ITbSimpleNoSignalsInterfaceInterface>(p.GetObject())->SetPropInt(propIntIter->get<int32>());
	}
	else
	{
		UE_LOG(LogTbSimple, Verbose, TEXT("from_json: interface property 'propInt' missing or type mismatch in ITbSimpleNoSignalsInterfaceInterface -> ignore"));
	}
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
