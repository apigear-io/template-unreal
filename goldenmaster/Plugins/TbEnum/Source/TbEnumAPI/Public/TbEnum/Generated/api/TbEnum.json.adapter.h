#pragma once

#include "apigear.json.adapter.h"
#include "TbEnum/Generated/api/TbEnum_data.h"
#include "TbEnum/Generated/api/TbEnumEnumInterfaceInterface.h"

static void from_json(const nlohmann::json& j, TScriptInterface<ITbEnumEnumInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITbEnumEnumInterfaceInterface>(p.GetObject())->SetProp0(j.at("prop0").get<ETbEnumEnum0>());
	Cast<ITbEnumEnumInterfaceInterface>(p.GetObject())->SetProp1(j.at("prop1").get<ETbEnumEnum1>());
	Cast<ITbEnumEnumInterfaceInterface>(p.GetObject())->SetProp2(j.at("prop2").get<ETbEnumEnum2>());
	Cast<ITbEnumEnumInterfaceInterface>(p.GetObject())->SetProp3(j.at("prop3").get<ETbEnumEnum3>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbEnumEnumInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"prop0", Cast<ITbEnumEnumInterfaceInterface>(p.GetObject())->GetProp0()}, {"prop1", Cast<ITbEnumEnumInterfaceInterface>(p.GetObject())->GetProp1()}, {"prop2", Cast<ITbEnumEnumInterfaceInterface>(p.GetObject())->GetProp2()}, {"prop3", Cast<ITbEnumEnumInterfaceInterface>(p.GetObject())->GetProp3()}};
}
