#pragma once

#include "apigear.json.adapter.h"
#include "TbNames/Generated/api/TbNames_data.h"
#include "TbNames/Generated/api/TbNamesNamEsInterface.h"

static void from_json(const nlohmann::json& j, TScriptInterface<ITbNamesNamEsInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITbNamesNamEsInterface>(p.GetObject())->SetSwitch(j.at("Switch").get<bool>());
	Cast<ITbNamesNamEsInterface>(p.GetObject())->SetSomeProperty(j.at("SOME_PROPERTY").get<int32>());
	Cast<ITbNamesNamEsInterface>(p.GetObject())->SetSomePoperty2(j.at("Some_Poperty2").get<int32>());
	Cast<ITbNamesNamEsInterface>(p.GetObject())->SetEnumProperty(j.at("enum_property").get<ETbNamesEnum_With_Under_scores>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbNamesNamEsInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"Switch", Cast<ITbNamesNamEsInterface>(p.GetObject())->GetSwitch()}, {"SOME_PROPERTY", Cast<ITbNamesNamEsInterface>(p.GetObject())->GetSomeProperty()}, {"Some_Poperty2", Cast<ITbNamesNamEsInterface>(p.GetObject())->GetSomePoperty2()}, {"enum_property", Cast<ITbNamesNamEsInterface>(p.GetObject())->GetEnumProperty()}};
}
