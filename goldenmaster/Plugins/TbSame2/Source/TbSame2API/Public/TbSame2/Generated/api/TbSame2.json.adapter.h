#pragma once

#include "apigear.json.adapter.h"
#include "TbSame2/Generated/api/TbSame2_data.h"
#include "TbSame2/Generated/api/TbSame2SameStruct1InterfaceInterface.h"
#include "TbSame2/Generated/api/TbSame2SameStruct2InterfaceInterface.h"
#include "TbSame2/Generated/api/TbSame2SameEnum1InterfaceInterface.h"
#include "TbSame2/Generated/api/TbSame2SameEnum2InterfaceInterface.h"

static void from_json(const nlohmann::json& j, FTbSame2Struct1& p)
{
	p.field1 = j.at("field1").get<int32>();
	p.field2 = j.at("field2").get<int32>();
	p.field3 = j.at("field3").get<int32>();
}

static void to_json(nlohmann::json& j, const FTbSame2Struct1& p)
{
	j = nlohmann::json{{"field1", p.field1}, {"field2", p.field2}, {"field3", p.field3}};
}

static void from_json(const nlohmann::json& j, FTbSame2Struct2& p)
{
	p.field1 = j.at("field1").get<int32>();
	p.field2 = j.at("field2").get<int32>();
	p.field3 = j.at("field3").get<int32>();
}

static void to_json(nlohmann::json& j, const FTbSame2Struct2& p)
{
	j = nlohmann::json{{"field1", p.field1}, {"field2", p.field2}, {"field3", p.field3}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSame2SameStruct1InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITbSame2SameStruct1InterfaceInterface>(p.GetObject())->SetProp1(j.at("prop1").get<FTbSame2Struct1>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSame2SameStruct1InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"prop1", Cast<ITbSame2SameStruct1InterfaceInterface>(p.GetObject())->GetProp1()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSame2SameStruct2InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITbSame2SameStruct2InterfaceInterface>(p.GetObject())->SetProp1(j.at("prop1").get<FTbSame2Struct2>());
	Cast<ITbSame2SameStruct2InterfaceInterface>(p.GetObject())->SetProp2(j.at("prop2").get<FTbSame2Struct2>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSame2SameStruct2InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"prop1", Cast<ITbSame2SameStruct2InterfaceInterface>(p.GetObject())->GetProp1()}, {"prop2", Cast<ITbSame2SameStruct2InterfaceInterface>(p.GetObject())->GetProp2()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSame2SameEnum1InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITbSame2SameEnum1InterfaceInterface>(p.GetObject())->SetProp1(j.at("prop1").get<ETbSame2Enum1>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSame2SameEnum1InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"prop1", Cast<ITbSame2SameEnum1InterfaceInterface>(p.GetObject())->GetProp1()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSame2SameEnum2InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITbSame2SameEnum2InterfaceInterface>(p.GetObject())->SetProp1(j.at("prop1").get<ETbSame2Enum1>());
	Cast<ITbSame2SameEnum2InterfaceInterface>(p.GetObject())->SetProp2(j.at("prop2").get<ETbSame2Enum2>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSame2SameEnum2InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"prop1", Cast<ITbSame2SameEnum2InterfaceInterface>(p.GetObject())->GetProp1()}, {"prop2", Cast<ITbSame2SameEnum2InterfaceInterface>(p.GetObject())->GetProp2()}};
}
