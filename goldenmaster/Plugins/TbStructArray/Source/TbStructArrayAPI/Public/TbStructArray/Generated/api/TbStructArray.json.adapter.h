#pragma once

#include "apigear.json.adapter.h"
#include "TbStructArray/Generated/TbStructArrayLogCategories.h"
#include "TbStructArray/Generated/api/TbStructArray_data.h"
#include "TbStructArray/Generated/api/TbStructArrayStructArrayFieldInterfaceInterface.h"

static void from_json(const nlohmann::json& j, FTbStructArrayPoint& p)
{
	const auto xIter = j.find("x");
	if (xIter != j.end() && !xIter->is_null() && xIter->is_number())
	{
		p.x = xIter->get<float>();
	}
	else
	{
		UE_LOG(LogTbStructArray, Error, TEXT("from_json: struct field 'x' missing or type mismatch in FTbStructArrayPoint -> using default value"));
	}

	const auto yIter = j.find("y");
	if (yIter != j.end() && !yIter->is_null() && yIter->is_number())
	{
		p.y = yIter->get<float>();
	}
	else
	{
		UE_LOG(LogTbStructArray, Error, TEXT("from_json: struct field 'y' missing or type mismatch in FTbStructArrayPoint -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTbStructArrayPoint& p)
{
	j = nlohmann::json{{"x", p.x}, {"y", p.y}};
}

static void from_json(const nlohmann::json& j, FTbStructArrayStructWithArrayOfStructs& p)
{
	const auto pointsIter = j.find("points");
	if (pointsIter != j.end() && !pointsIter->is_null() && pointsIter->is_array())
	{
		p.points = pointsIter->get<TArray<FTbStructArrayPoint>>();
	}
	else
	{
		UE_LOG(LogTbStructArray, Error, TEXT("from_json: struct field 'points' missing or type mismatch in FTbStructArrayStructWithArrayOfStructs -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTbStructArrayStructWithArrayOfStructs& p)
{
	j = nlohmann::json{{"points", p.points}};
}

static void from_json(const nlohmann::json& j, FTbStructArrayStructWithArrayOfEnums& p)
{
	const auto tagsIter = j.find("tags");
	if (tagsIter != j.end() && !tagsIter->is_null() && tagsIter->is_array())
	{
		p.tags = tagsIter->get<TArray<ETbStructArrayTestEnum>>();
	}
	else
	{
		UE_LOG(LogTbStructArray, Error, TEXT("from_json: struct field 'tags' missing or type mismatch in FTbStructArrayStructWithArrayOfEnums -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTbStructArrayStructWithArrayOfEnums& p)
{
	j = nlohmann::json{{"tags", p.tags}};
}

static void from_json(const nlohmann::json& j, FTbStructArrayStructWithArrayOfInts& p)
{
	const auto valuesIter = j.find("values");
	if (valuesIter != j.end() && !valuesIter->is_null() && valuesIter->is_array())
	{
		p.values = valuesIter->get<TArray<int32>>();
	}
	else
	{
		UE_LOG(LogTbStructArray, Error, TEXT("from_json: struct field 'values' missing or type mismatch in FTbStructArrayStructWithArrayOfInts -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTbStructArrayStructWithArrayOfInts& p)
{
	j = nlohmann::json{{"values", p.values}};
}

static void from_json(const nlohmann::json& j, FTbStructArrayMixedStruct& p)
{
	const auto idIter = j.find("id");
	if (idIter != j.end() && !idIter->is_null() && idIter->is_number_integer())
	{
		p.id = idIter->get<int32>();
	}
	else
	{
		UE_LOG(LogTbStructArray, Error, TEXT("from_json: struct field 'id' missing or type mismatch in FTbStructArrayMixedStruct -> using default value"));
	}

	const auto nameIter = j.find("name");
	if (nameIter != j.end() && !nameIter->is_null() && nameIter->is_string())
	{
		p.name = nameIter->get<FString>();
	}
	else
	{
		UE_LOG(LogTbStructArray, Error, TEXT("from_json: struct field 'name' missing or type mismatch in FTbStructArrayMixedStruct -> using default value"));
	}

	const auto originIter = j.find("origin");
	if (originIter != j.end() && !originIter->is_null() && originIter->is_object())
	{
		p.origin = originIter->get<FTbStructArrayPoint>();
	}
	else
	{
		UE_LOG(LogTbStructArray, Error, TEXT("from_json: struct field 'origin' missing or type mismatch in FTbStructArrayMixedStruct -> using default value"));
	}

	const auto pointsIter = j.find("points");
	if (pointsIter != j.end() && !pointsIter->is_null() && pointsIter->is_array())
	{
		p.points = pointsIter->get<TArray<FTbStructArrayPoint>>();
	}
	else
	{
		UE_LOG(LogTbStructArray, Error, TEXT("from_json: struct field 'points' missing or type mismatch in FTbStructArrayMixedStruct -> using default value"));
	}

	const auto flagsIter = j.find("flags");
	if (flagsIter != j.end() && !flagsIter->is_null() && flagsIter->is_array())
	{
		p.flags = flagsIter->get<TArray<ETbStructArrayTestEnum>>();
	}
	else
	{
		UE_LOG(LogTbStructArray, Error, TEXT("from_json: struct field 'flags' missing or type mismatch in FTbStructArrayMixedStruct -> using default value"));
	}

	const auto scoresIter = j.find("scores");
	if (scoresIter != j.end() && !scoresIter->is_null() && scoresIter->is_array())
	{
		p.scores = scoresIter->get<TArray<int32>>();
	}
	else
	{
		UE_LOG(LogTbStructArray, Error, TEXT("from_json: struct field 'scores' missing or type mismatch in FTbStructArrayMixedStruct -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTbStructArrayMixedStruct& p)
{
	j = nlohmann::json{{"id", p.id}, {"name", p.name}, {"origin", p.origin}, {"points", p.points}, {"flags", p.flags}, {"scores", p.scores}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	const auto propStructArrayIter = j.find("propStructArray");
	if (propStructArrayIter != j.end() && !propStructArrayIter->is_null() && propStructArrayIter->is_object())
	{
		Cast<ITbStructArrayStructArrayFieldInterfaceInterface>(p.GetObject())->SetPropStructArray(propStructArrayIter->get<FTbStructArrayStructWithArrayOfStructs>());
	}
	else
	{
		UE_LOG(LogTbStructArray, Error, TEXT("from_json: interface property 'propStructArray' missing or type mismatch in ITbStructArrayStructArrayFieldInterfaceInterface -> ignore"));
	}

	const auto propEnumArrayIter = j.find("propEnumArray");
	if (propEnumArrayIter != j.end() && !propEnumArrayIter->is_null() && propEnumArrayIter->is_object())
	{
		Cast<ITbStructArrayStructArrayFieldInterfaceInterface>(p.GetObject())->SetPropEnumArray(propEnumArrayIter->get<FTbStructArrayStructWithArrayOfEnums>());
	}
	else
	{
		UE_LOG(LogTbStructArray, Error, TEXT("from_json: interface property 'propEnumArray' missing or type mismatch in ITbStructArrayStructArrayFieldInterfaceInterface -> ignore"));
	}

	const auto propIntArrayIter = j.find("propIntArray");
	if (propIntArrayIter != j.end() && !propIntArrayIter->is_null() && propIntArrayIter->is_object())
	{
		Cast<ITbStructArrayStructArrayFieldInterfaceInterface>(p.GetObject())->SetPropIntArray(propIntArrayIter->get<FTbStructArrayStructWithArrayOfInts>());
	}
	else
	{
		UE_LOG(LogTbStructArray, Error, TEXT("from_json: interface property 'propIntArray' missing or type mismatch in ITbStructArrayStructArrayFieldInterfaceInterface -> ignore"));
	}

	const auto propMixedIter = j.find("propMixed");
	if (propMixedIter != j.end() && !propMixedIter->is_null() && propMixedIter->is_object())
	{
		Cast<ITbStructArrayStructArrayFieldInterfaceInterface>(p.GetObject())->SetPropMixed(propMixedIter->get<FTbStructArrayMixedStruct>());
	}
	else
	{
		UE_LOG(LogTbStructArray, Error, TEXT("from_json: interface property 'propMixed' missing or type mismatch in ITbStructArrayStructArrayFieldInterfaceInterface -> ignore"));
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"propStructArray", Cast<ITbStructArrayStructArrayFieldInterfaceInterface>(p.GetObject())->GetPropStructArray()}, {"propEnumArray", Cast<ITbStructArrayStructArrayFieldInterfaceInterface>(p.GetObject())->GetPropEnumArray()}, {"propIntArray", Cast<ITbStructArrayStructArrayFieldInterfaceInterface>(p.GetObject())->GetPropIntArray()}, {"propMixed", Cast<ITbStructArrayStructArrayFieldInterfaceInterface>(p.GetObject())->GetPropMixed()}};
}
