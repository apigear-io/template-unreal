#pragma once

#include "apigear.json.adapter.h"
#include "TbSame1/Generated/api/TbSame1_data.h"
#include "TbSame1/Generated/api/TbSame1SameStruct1InterfaceInterface.h"
#include "TbSame1/Generated/api/TbSame1SameStruct2InterfaceInterface.h"
#include "TbSame1/Generated/api/TbSame1SameEnum1InterfaceInterface.h"
#include "TbSame1/Generated/api/TbSame1SameEnum2InterfaceInterface.h"

static void from_json(const nlohmann::json& j, FTbSame1Struct1& p)
{
	p.field1 = j.at("field1").get<int32>();
	p.field2 = j.at("field2").get<int32>();
	p.field3 = j.at("field3").get<int32>();
}

static void to_json(nlohmann::json& j, const FTbSame1Struct1& p)
{
	j = nlohmann::json{{"field1", p.field1}, {"field2", p.field2}, {"field3", p.field3}};
}

static void from_json(const nlohmann::json& j, FTbSame1Struct2& p)
{
	p.field1 = j.at("field1").get<int32>();
	p.field2 = j.at("field2").get<int32>();
	p.field3 = j.at("field3").get<int32>();
}

static void to_json(nlohmann::json& j, const FTbSame1Struct2& p)
{
	j = nlohmann::json{{"field1", p.field1}, {"field2", p.field2}, {"field3", p.field3}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSame1SameStruct1InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITbSame1SameStruct1InterfaceInterface>(p.GetObject())->SetProp1(j.at("prop1").get<FTbSame1Struct1>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSame1SameStruct1InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"prop1", Cast<ITbSame1SameStruct1InterfaceInterface>(p.GetObject())->GetProp1()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSame1SameStruct2InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITbSame1SameStruct2InterfaceInterface>(p.GetObject())->SetProp1(j.at("prop1").get<FTbSame1Struct2>());
	Cast<ITbSame1SameStruct2InterfaceInterface>(p.GetObject())->SetProp2(j.at("prop2").get<FTbSame1Struct2>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSame1SameStruct2InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"prop1", Cast<ITbSame1SameStruct2InterfaceInterface>(p.GetObject())->GetProp1()}, {"prop2", Cast<ITbSame1SameStruct2InterfaceInterface>(p.GetObject())->GetProp2()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSame1SameEnum1InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITbSame1SameEnum1InterfaceInterface>(p.GetObject())->SetProp1(j.at("prop1").get<ETbSame1Enum1>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSame1SameEnum1InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"prop1", Cast<ITbSame1SameEnum1InterfaceInterface>(p.GetObject())->GetProp1()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITbSame1SameEnum2InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	Cast<ITbSame1SameEnum2InterfaceInterface>(p.GetObject())->SetProp1(j.at("prop1").get<ETbSame1Enum1>());
	Cast<ITbSame1SameEnum2InterfaceInterface>(p.GetObject())->SetProp2(j.at("prop2").get<ETbSame1Enum2>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSame1SameEnum2InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"prop1", Cast<ITbSame1SameEnum2InterfaceInterface>(p.GetObject())->GetProp1()}, {"prop2", Cast<ITbSame1SameEnum2InterfaceInterface>(p.GetObject())->GetProp2()}};
}
