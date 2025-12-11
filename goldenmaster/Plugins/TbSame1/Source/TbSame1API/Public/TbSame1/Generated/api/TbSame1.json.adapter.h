#pragma once

#include "apigear.json.adapter.h"
#include "TbSame1/Generated/TbSame1LogCategories.h"
#include "TbSame1/Generated/api/TbSame1_data.h"
#include "TbSame1/Generated/api/TbSame1SameStruct1InterfaceInterface.h"
#include "TbSame1/Generated/api/TbSame1SameStruct2InterfaceInterface.h"
#include "TbSame1/Generated/api/TbSame1SameEnum1InterfaceInterface.h"
#include "TbSame1/Generated/api/TbSame1SameEnum2InterfaceInterface.h"

static void from_json(const nlohmann::json& j, FTbSame1Struct1& p)
{
	const auto field1Iter = j.find("field1");
	if (field1Iter != j.end() && !field1Iter->is_null() && field1Iter->is_number_integer())
	{
		p.field1 = field1Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTbSame1, Error, TEXT("from_json: struct field 'field1' missing or type mismatch in FTbSame1Struct1 -> using default value"));
	}

	const auto field2Iter = j.find("field2");
	if (field2Iter != j.end() && !field2Iter->is_null() && field2Iter->is_number_integer())
	{
		p.field2 = field2Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTbSame1, Error, TEXT("from_json: struct field 'field2' missing or type mismatch in FTbSame1Struct1 -> using default value"));
	}

	const auto field3Iter = j.find("field3");
	if (field3Iter != j.end() && !field3Iter->is_null() && field3Iter->is_number_integer())
	{
		p.field3 = field3Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTbSame1, Error, TEXT("from_json: struct field 'field3' missing or type mismatch in FTbSame1Struct1 -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTbSame1Struct1& p)
{
	j = nlohmann::json{{"field1", p.field1}, {"field2", p.field2}, {"field3", p.field3}};
}

static void from_json(const nlohmann::json& j, FTbSame1Struct2& p)
{
	const auto field1Iter = j.find("field1");
	if (field1Iter != j.end() && !field1Iter->is_null() && field1Iter->is_number_integer())
	{
		p.field1 = field1Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTbSame1, Error, TEXT("from_json: struct field 'field1' missing or type mismatch in FTbSame1Struct2 -> using default value"));
	}

	const auto field2Iter = j.find("field2");
	if (field2Iter != j.end() && !field2Iter->is_null() && field2Iter->is_number_integer())
	{
		p.field2 = field2Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTbSame1, Error, TEXT("from_json: struct field 'field2' missing or type mismatch in FTbSame1Struct2 -> using default value"));
	}

	const auto field3Iter = j.find("field3");
	if (field3Iter != j.end() && !field3Iter->is_null() && field3Iter->is_number_integer())
	{
		p.field3 = field3Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTbSame1, Error, TEXT("from_json: struct field 'field3' missing or type mismatch in FTbSame1Struct2 -> using default value"));
	}
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

	const auto prop1Iter = j.find("prop1");
	if (prop1Iter != j.end() && !prop1Iter->is_null() && prop1Iter->is_object())
	{
		Cast<ITbSame1SameStruct1InterfaceInterface>(p.GetObject())->SetProp1(prop1Iter->get<FTbSame1Struct1>());
	}
	else
	{
		UE_LOG(LogTbSame1, Error, TEXT("from_json: interface property 'prop1' missing or type mismatch in ITbSame1SameStruct1InterfaceInterface -> ignore"));
	}
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

	const auto prop1Iter = j.find("prop1");
	if (prop1Iter != j.end() && !prop1Iter->is_null() && prop1Iter->is_object())
	{
		Cast<ITbSame1SameStruct2InterfaceInterface>(p.GetObject())->SetProp1(prop1Iter->get<FTbSame1Struct2>());
	}
	else
	{
		UE_LOG(LogTbSame1, Error, TEXT("from_json: interface property 'prop1' missing or type mismatch in ITbSame1SameStruct2InterfaceInterface -> ignore"));
	}

	const auto prop2Iter = j.find("prop2");
	if (prop2Iter != j.end() && !prop2Iter->is_null() && prop2Iter->is_object())
	{
		Cast<ITbSame1SameStruct2InterfaceInterface>(p.GetObject())->SetProp2(prop2Iter->get<FTbSame1Struct2>());
	}
	else
	{
		UE_LOG(LogTbSame1, Error, TEXT("from_json: interface property 'prop2' missing or type mismatch in ITbSame1SameStruct2InterfaceInterface -> ignore"));
	}
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

	const auto prop1Iter = j.find("prop1");
	if (prop1Iter != j.end() && !prop1Iter->is_null() && prop1Iter->is_number_integer())
	{
		Cast<ITbSame1SameEnum1InterfaceInterface>(p.GetObject())->SetProp1(prop1Iter->get<ETbSame1Enum1>());
	}
	else
	{
		UE_LOG(LogTbSame1, Error, TEXT("from_json: interface property 'prop1' missing or type mismatch in ITbSame1SameEnum1InterfaceInterface -> ignore"));
	}
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

	const auto prop1Iter = j.find("prop1");
	if (prop1Iter != j.end() && !prop1Iter->is_null() && prop1Iter->is_number_integer())
	{
		Cast<ITbSame1SameEnum2InterfaceInterface>(p.GetObject())->SetProp1(prop1Iter->get<ETbSame1Enum1>());
	}
	else
	{
		UE_LOG(LogTbSame1, Error, TEXT("from_json: interface property 'prop1' missing or type mismatch in ITbSame1SameEnum2InterfaceInterface -> ignore"));
	}

	const auto prop2Iter = j.find("prop2");
	if (prop2Iter != j.end() && !prop2Iter->is_null() && prop2Iter->is_number_integer())
	{
		Cast<ITbSame1SameEnum2InterfaceInterface>(p.GetObject())->SetProp2(prop2Iter->get<ETbSame1Enum2>());
	}
	else
	{
		UE_LOG(LogTbSame1, Error, TEXT("from_json: interface property 'prop2' missing or type mismatch in ITbSame1SameEnum2InterfaceInterface -> ignore"));
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSame1SameEnum2InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"prop1", Cast<ITbSame1SameEnum2InterfaceInterface>(p.GetObject())->GetProp1()}, {"prop2", Cast<ITbSame1SameEnum2InterfaceInterface>(p.GetObject())->GetProp2()}};
}
