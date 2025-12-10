#pragma once

#include "apigear.json.adapter.h"
#include "TbEnum/Generated/TbEnumLogCategories.h"
#include "TbEnum/Generated/api/TbEnum_data.h"
#include "TbEnum/Generated/api/TbEnumEnumInterfaceInterface.h"

static void from_json(const nlohmann::json& j, TScriptInterface<ITbEnumEnumInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	const auto prop0Iter = j.find("prop0");
	if (prop0Iter != j.end() && !prop0Iter->is_null() && prop0Iter->is_number_integer())
	{
		Cast<ITbEnumEnumInterfaceInterface>(p.GetObject())->SetProp0(prop0Iter->get<ETbEnumEnum0>());
	}
	else
	{
		UE_LOG(LogTbEnum, Error, TEXT("from_json: interface property 'prop0' missing or type mismatch in ITbEnumEnumInterfaceInterface -> ignore"));
	}

	const auto prop1Iter = j.find("prop1");
	if (prop1Iter != j.end() && !prop1Iter->is_null() && prop1Iter->is_number_integer())
	{
		Cast<ITbEnumEnumInterfaceInterface>(p.GetObject())->SetProp1(prop1Iter->get<ETbEnumEnum1>());
	}
	else
	{
		UE_LOG(LogTbEnum, Error, TEXT("from_json: interface property 'prop1' missing or type mismatch in ITbEnumEnumInterfaceInterface -> ignore"));
	}

	const auto prop2Iter = j.find("prop2");
	if (prop2Iter != j.end() && !prop2Iter->is_null() && prop2Iter->is_number_integer())
	{
		Cast<ITbEnumEnumInterfaceInterface>(p.GetObject())->SetProp2(prop2Iter->get<ETbEnumEnum2>());
	}
	else
	{
		UE_LOG(LogTbEnum, Error, TEXT("from_json: interface property 'prop2' missing or type mismatch in ITbEnumEnumInterfaceInterface -> ignore"));
	}

	const auto prop3Iter = j.find("prop3");
	if (prop3Iter != j.end() && !prop3Iter->is_null() && prop3Iter->is_number_integer())
	{
		Cast<ITbEnumEnumInterfaceInterface>(p.GetObject())->SetProp3(prop3Iter->get<ETbEnumEnum3>());
	}
	else
	{
		UE_LOG(LogTbEnum, Error, TEXT("from_json: interface property 'prop3' missing or type mismatch in ITbEnumEnumInterfaceInterface -> ignore"));
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbEnumEnumInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"prop0", Cast<ITbEnumEnumInterfaceInterface>(p.GetObject())->GetProp0()}, {"prop1", Cast<ITbEnumEnumInterfaceInterface>(p.GetObject())->GetProp1()}, {"prop2", Cast<ITbEnumEnumInterfaceInterface>(p.GetObject())->GetProp2()}, {"prop3", Cast<ITbEnumEnumInterfaceInterface>(p.GetObject())->GetProp3()}};
}
