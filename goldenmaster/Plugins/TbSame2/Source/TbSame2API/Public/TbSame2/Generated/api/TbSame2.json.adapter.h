#pragma once

#include "apigear.json.adapter.h"
#include "TbSame2/Generated/TbSame2LogCategories.h"
#include "TbSame2/Generated/api/TbSame2_data.h"
#include "TbSame2/Generated/api/TbSame2SameStruct1InterfaceInterface.h"
#include "TbSame2/Generated/api/TbSame2SameStruct2InterfaceInterface.h"
#include "TbSame2/Generated/api/TbSame2SameEnum1InterfaceInterface.h"
#include "TbSame2/Generated/api/TbSame2SameEnum2InterfaceInterface.h"

static void from_json(const nlohmann::json& j, FTbSame2Struct1& p)
{
	const auto field1Iter = j.find("field1");
	if (field1Iter != j.end() && !field1Iter->is_null() && field1Iter->is_number_integer())
	{
		p.field1 = field1Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTbSame2, Error, TEXT("from_json: struct field 'field1' missing or type mismatch in FTbSame2Struct1 -> using default value"));
	}

	const auto field2Iter = j.find("field2");
	if (field2Iter != j.end() && !field2Iter->is_null() && field2Iter->is_number_integer())
	{
		p.field2 = field2Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTbSame2, Error, TEXT("from_json: struct field 'field2' missing or type mismatch in FTbSame2Struct1 -> using default value"));
	}

	const auto field3Iter = j.find("field3");
	if (field3Iter != j.end() && !field3Iter->is_null() && field3Iter->is_number_integer())
	{
		p.field3 = field3Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTbSame2, Error, TEXT("from_json: struct field 'field3' missing or type mismatch in FTbSame2Struct1 -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTbSame2Struct1& p)
{
	j = nlohmann::json{{"field1", p.field1}, {"field2", p.field2}, {"field3", p.field3}};
}

static void from_json(const nlohmann::json& j, FTbSame2Struct2& p)
{
	const auto field1Iter = j.find("field1");
	if (field1Iter != j.end() && !field1Iter->is_null() && field1Iter->is_number_integer())
	{
		p.field1 = field1Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTbSame2, Error, TEXT("from_json: struct field 'field1' missing or type mismatch in FTbSame2Struct2 -> using default value"));
	}

	const auto field2Iter = j.find("field2");
	if (field2Iter != j.end() && !field2Iter->is_null() && field2Iter->is_number_integer())
	{
		p.field2 = field2Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTbSame2, Error, TEXT("from_json: struct field 'field2' missing or type mismatch in FTbSame2Struct2 -> using default value"));
	}

	const auto field3Iter = j.find("field3");
	if (field3Iter != j.end() && !field3Iter->is_null() && field3Iter->is_number_integer())
	{
		p.field3 = field3Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTbSame2, Error, TEXT("from_json: struct field 'field3' missing or type mismatch in FTbSame2Struct2 -> using default value"));
	}
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

	const auto prop1Iter = j.find("prop1");
	if (prop1Iter != j.end() && !prop1Iter->is_null() && prop1Iter->is_object())
	{
		Cast<ITbSame2SameStruct1InterfaceInterface>(p.GetObject())->SetProp1(prop1Iter->get<FTbSame2Struct1>());
	}
	else
	{
		UE_LOG(LogTbSame2, Error, TEXT("from_json: interface property 'prop1' missing or type mismatch in ITbSame2SameStruct1InterfaceInterface -> ignore"));
	}
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

	const auto prop1Iter = j.find("prop1");
	if (prop1Iter != j.end() && !prop1Iter->is_null() && prop1Iter->is_object())
	{
		Cast<ITbSame2SameStruct2InterfaceInterface>(p.GetObject())->SetProp1(prop1Iter->get<FTbSame2Struct2>());
	}
	else
	{
		UE_LOG(LogTbSame2, Error, TEXT("from_json: interface property 'prop1' missing or type mismatch in ITbSame2SameStruct2InterfaceInterface -> ignore"));
	}

	const auto prop2Iter = j.find("prop2");
	if (prop2Iter != j.end() && !prop2Iter->is_null() && prop2Iter->is_object())
	{
		Cast<ITbSame2SameStruct2InterfaceInterface>(p.GetObject())->SetProp2(prop2Iter->get<FTbSame2Struct2>());
	}
	else
	{
		UE_LOG(LogTbSame2, Error, TEXT("from_json: interface property 'prop2' missing or type mismatch in ITbSame2SameStruct2InterfaceInterface -> ignore"));
	}
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

	const auto prop1Iter = j.find("prop1");
	if (prop1Iter != j.end() && !prop1Iter->is_null() && prop1Iter->is_number_integer())
	{
		Cast<ITbSame2SameEnum1InterfaceInterface>(p.GetObject())->SetProp1(prop1Iter->get<ETbSame2Enum1>());
	}
	else
	{
		UE_LOG(LogTbSame2, Error, TEXT("from_json: interface property 'prop1' missing or type mismatch in ITbSame2SameEnum1InterfaceInterface -> ignore"));
	}
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

	const auto prop1Iter = j.find("prop1");
	if (prop1Iter != j.end() && !prop1Iter->is_null() && prop1Iter->is_number_integer())
	{
		Cast<ITbSame2SameEnum2InterfaceInterface>(p.GetObject())->SetProp1(prop1Iter->get<ETbSame2Enum1>());
	}
	else
	{
		UE_LOG(LogTbSame2, Error, TEXT("from_json: interface property 'prop1' missing or type mismatch in ITbSame2SameEnum2InterfaceInterface -> ignore"));
	}

	const auto prop2Iter = j.find("prop2");
	if (prop2Iter != j.end() && !prop2Iter->is_null() && prop2Iter->is_number_integer())
	{
		Cast<ITbSame2SameEnum2InterfaceInterface>(p.GetObject())->SetProp2(prop2Iter->get<ETbSame2Enum2>());
	}
	else
	{
		UE_LOG(LogTbSame2, Error, TEXT("from_json: interface property 'prop2' missing or type mismatch in ITbSame2SameEnum2InterfaceInterface -> ignore"));
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITbSame2SameEnum2InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"prop1", Cast<ITbSame2SameEnum2InterfaceInterface>(p.GetObject())->GetProp1()}, {"prop2", Cast<ITbSame2SameEnum2InterfaceInterface>(p.GetObject())->GetProp2()}};
}
