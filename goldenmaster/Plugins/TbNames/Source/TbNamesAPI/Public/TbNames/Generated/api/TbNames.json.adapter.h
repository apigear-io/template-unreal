#pragma once

#include "apigear.json.adapter.h"
#include "TbNames/Generated/TbNamesLogCategories.h"
#include "TbNames/Generated/api/TbNames_data.h"
#include "TbNames/Generated/api/TbNamesNamEsInterface.h"

static void from_json(const nlohmann::json& j, TScriptInterface<ITbNamesNamEsInterface>& p)
{
	if (!p)
	{
		return;
	}

	const auto SwitchIter = j.find("Switch");
	if (SwitchIter != j.end() && !SwitchIter->is_null() && SwitchIter->is_boolean())
	{
		Cast<ITbNamesNamEsInterface>(p.GetObject())->SetSwitch(SwitchIter->get<bool>());
	}
	else
	{
		UE_LOG(LogTbNames, Error, TEXT("from_json: interface property 'Switch' missing or type mismatch in ITbNamesNamEsInterface -> ignore"));
	}

	const auto SOME_PROPERTYIter = j.find("SOME_PROPERTY");
	if (SOME_PROPERTYIter != j.end() && !SOME_PROPERTYIter->is_null() && SOME_PROPERTYIter->is_number_integer())
	{
		Cast<ITbNamesNamEsInterface>(p.GetObject())->SetSomeProperty(SOME_PROPERTYIter->get<int32>());
	}
	else
	{
		UE_LOG(LogTbNames, Error, TEXT("from_json: interface property 'SOME_PROPERTY' missing or type mismatch in ITbNamesNamEsInterface -> ignore"));
	}

	const auto Some_Poperty2Iter = j.find("Some_Poperty2");
	if (Some_Poperty2Iter != j.end() && !Some_Poperty2Iter->is_null() && Some_Poperty2Iter->is_number_integer())
	{
		Cast<ITbNamesNamEsInterface>(p.GetObject())->SetSomePoperty2(Some_Poperty2Iter->get<int32>());
	}
	else
	{
		UE_LOG(LogTbNames, Error, TEXT("from_json: interface property 'Some_Poperty2' missing or type mismatch in ITbNamesNamEsInterface -> ignore"));
	}

	const auto enum_propertyIter = j.find("enum_property");
	if (enum_propertyIter != j.end() && !enum_propertyIter->is_null() && enum_propertyIter->is_number_integer())
	{
		Cast<ITbNamesNamEsInterface>(p.GetObject())->SetEnumProperty(enum_propertyIter->get<ETbNamesEnum_With_Under_scores>());
	}
	else
	{
		UE_LOG(LogTbNames, Error, TEXT("from_json: interface property 'enum_property' missing or type mismatch in ITbNamesNamEsInterface -> ignore"));
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbNamesNamEsInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"Switch", Cast<ITbNamesNamEsInterface>(p.GetObject())->GetSwitch()}, {"SOME_PROPERTY", Cast<ITbNamesNamEsInterface>(p.GetObject())->GetSomeProperty()}, {"Some_Poperty2", Cast<ITbNamesNamEsInterface>(p.GetObject())->GetSomePoperty2()}, {"enum_property", Cast<ITbNamesNamEsInterface>(p.GetObject())->GetEnumProperty()}};
}
