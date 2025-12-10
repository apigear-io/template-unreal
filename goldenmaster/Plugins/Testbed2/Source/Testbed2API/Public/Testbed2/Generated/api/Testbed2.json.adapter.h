#pragma once

#include "apigear.json.adapter.h"
#include "Testbed2/Generated/Testbed2LogCategories.h"
#include "Testbed2/Generated/api/Testbed2_data.h"
#include "Testbed2/Generated/api/Testbed2ManyParamInterfaceInterface.h"
#include "Testbed2/Generated/api/Testbed2NestedStruct1InterfaceInterface.h"
#include "Testbed2/Generated/api/Testbed2NestedStruct2InterfaceInterface.h"
#include "Testbed2/Generated/api/Testbed2NestedStruct3InterfaceInterface.h"

static void from_json(const nlohmann::json& j, FTestbed2Struct1& p)
{
	const auto field1Iter = j.find("field1");
	if (field1Iter != j.end() && !field1Iter->is_null() && field1Iter->is_number_integer())
	{
		p.field1 = field1Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: struct field 'field1' missing or type mismatch in FTestbed2Struct1 -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed2Struct1& p)
{
	j = nlohmann::json{{"field1", p.field1}};
}

static void from_json(const nlohmann::json& j, FTestbed2Struct2& p)
{
	const auto field1Iter = j.find("field1");
	if (field1Iter != j.end() && !field1Iter->is_null() && field1Iter->is_number_integer())
	{
		p.field1 = field1Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: struct field 'field1' missing or type mismatch in FTestbed2Struct2 -> using default value"));
	}

	const auto field2Iter = j.find("field2");
	if (field2Iter != j.end() && !field2Iter->is_null() && field2Iter->is_number_integer())
	{
		p.field2 = field2Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: struct field 'field2' missing or type mismatch in FTestbed2Struct2 -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed2Struct2& p)
{
	j = nlohmann::json{{"field1", p.field1}, {"field2", p.field2}};
}

static void from_json(const nlohmann::json& j, FTestbed2Struct3& p)
{
	const auto field1Iter = j.find("field1");
	if (field1Iter != j.end() && !field1Iter->is_null() && field1Iter->is_number_integer())
	{
		p.field1 = field1Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: struct field 'field1' missing or type mismatch in FTestbed2Struct3 -> using default value"));
	}

	const auto field2Iter = j.find("field2");
	if (field2Iter != j.end() && !field2Iter->is_null() && field2Iter->is_number_integer())
	{
		p.field2 = field2Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: struct field 'field2' missing or type mismatch in FTestbed2Struct3 -> using default value"));
	}

	const auto field3Iter = j.find("field3");
	if (field3Iter != j.end() && !field3Iter->is_null() && field3Iter->is_number_integer())
	{
		p.field3 = field3Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: struct field 'field3' missing or type mismatch in FTestbed2Struct3 -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed2Struct3& p)
{
	j = nlohmann::json{{"field1", p.field1}, {"field2", p.field2}, {"field3", p.field3}};
}

static void from_json(const nlohmann::json& j, FTestbed2Struct4& p)
{
	const auto field1Iter = j.find("field1");
	if (field1Iter != j.end() && !field1Iter->is_null() && field1Iter->is_number_integer())
	{
		p.field1 = field1Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: struct field 'field1' missing or type mismatch in FTestbed2Struct4 -> using default value"));
	}

	const auto field2Iter = j.find("field2");
	if (field2Iter != j.end() && !field2Iter->is_null() && field2Iter->is_number_integer())
	{
		p.field2 = field2Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: struct field 'field2' missing or type mismatch in FTestbed2Struct4 -> using default value"));
	}

	const auto field3Iter = j.find("field3");
	if (field3Iter != j.end() && !field3Iter->is_null() && field3Iter->is_number_integer())
	{
		p.field3 = field3Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: struct field 'field3' missing or type mismatch in FTestbed2Struct4 -> using default value"));
	}

	const auto field4Iter = j.find("field4");
	if (field4Iter != j.end() && !field4Iter->is_null() && field4Iter->is_number_integer())
	{
		p.field4 = field4Iter->get<int32>();
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: struct field 'field4' missing or type mismatch in FTestbed2Struct4 -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed2Struct4& p)
{
	j = nlohmann::json{{"field1", p.field1}, {"field2", p.field2}, {"field3", p.field3}, {"field4", p.field4}};
}

static void from_json(const nlohmann::json& j, FTestbed2NestedStruct1& p)
{
	const auto field1Iter = j.find("field1");
	if (field1Iter != j.end() && !field1Iter->is_null() && field1Iter->is_object())
	{
		p.field1 = field1Iter->get<FTestbed2Struct1>();
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: struct field 'field1' missing or type mismatch in FTestbed2NestedStruct1 -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed2NestedStruct1& p)
{
	j = nlohmann::json{{"field1", p.field1}};
}

static void from_json(const nlohmann::json& j, FTestbed2NestedStruct2& p)
{
	const auto field1Iter = j.find("field1");
	if (field1Iter != j.end() && !field1Iter->is_null() && field1Iter->is_object())
	{
		p.field1 = field1Iter->get<FTestbed2Struct1>();
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: struct field 'field1' missing or type mismatch in FTestbed2NestedStruct2 -> using default value"));
	}

	const auto field2Iter = j.find("field2");
	if (field2Iter != j.end() && !field2Iter->is_null() && field2Iter->is_object())
	{
		p.field2 = field2Iter->get<FTestbed2Struct2>();
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: struct field 'field2' missing or type mismatch in FTestbed2NestedStruct2 -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed2NestedStruct2& p)
{
	j = nlohmann::json{{"field1", p.field1}, {"field2", p.field2}};
}

static void from_json(const nlohmann::json& j, FTestbed2NestedStruct3& p)
{
	const auto field1Iter = j.find("field1");
	if (field1Iter != j.end() && !field1Iter->is_null() && field1Iter->is_object())
	{
		p.field1 = field1Iter->get<FTestbed2Struct1>();
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: struct field 'field1' missing or type mismatch in FTestbed2NestedStruct3 -> using default value"));
	}

	const auto field2Iter = j.find("field2");
	if (field2Iter != j.end() && !field2Iter->is_null() && field2Iter->is_object())
	{
		p.field2 = field2Iter->get<FTestbed2Struct2>();
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: struct field 'field2' missing or type mismatch in FTestbed2NestedStruct3 -> using default value"));
	}

	const auto field3Iter = j.find("field3");
	if (field3Iter != j.end() && !field3Iter->is_null() && field3Iter->is_object())
	{
		p.field3 = field3Iter->get<FTestbed2Struct3>();
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: struct field 'field3' missing or type mismatch in FTestbed2NestedStruct3 -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed2NestedStruct3& p)
{
	j = nlohmann::json{{"field1", p.field1}, {"field2", p.field2}, {"field3", p.field3}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITestbed2ManyParamInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	const auto prop1Iter = j.find("prop1");
	if (prop1Iter != j.end() && !prop1Iter->is_null() && prop1Iter->is_number_integer())
	{
		Cast<ITestbed2ManyParamInterfaceInterface>(p.GetObject())->SetProp1(prop1Iter->get<int32>());
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: interface property 'prop1' missing or type mismatch in ITestbed2ManyParamInterfaceInterface -> ignore"));
	}

	const auto prop2Iter = j.find("prop2");
	if (prop2Iter != j.end() && !prop2Iter->is_null() && prop2Iter->is_number_integer())
	{
		Cast<ITestbed2ManyParamInterfaceInterface>(p.GetObject())->SetProp2(prop2Iter->get<int32>());
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: interface property 'prop2' missing or type mismatch in ITestbed2ManyParamInterfaceInterface -> ignore"));
	}

	const auto prop3Iter = j.find("prop3");
	if (prop3Iter != j.end() && !prop3Iter->is_null() && prop3Iter->is_number_integer())
	{
		Cast<ITestbed2ManyParamInterfaceInterface>(p.GetObject())->SetProp3(prop3Iter->get<int32>());
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: interface property 'prop3' missing or type mismatch in ITestbed2ManyParamInterfaceInterface -> ignore"));
	}

	const auto prop4Iter = j.find("prop4");
	if (prop4Iter != j.end() && !prop4Iter->is_null() && prop4Iter->is_number_integer())
	{
		Cast<ITestbed2ManyParamInterfaceInterface>(p.GetObject())->SetProp4(prop4Iter->get<int32>());
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: interface property 'prop4' missing or type mismatch in ITestbed2ManyParamInterfaceInterface -> ignore"));
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITestbed2ManyParamInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"prop1", Cast<ITestbed2ManyParamInterfaceInterface>(p.GetObject())->GetProp1()}, {"prop2", Cast<ITestbed2ManyParamInterfaceInterface>(p.GetObject())->GetProp2()}, {"prop3", Cast<ITestbed2ManyParamInterfaceInterface>(p.GetObject())->GetProp3()}, {"prop4", Cast<ITestbed2ManyParamInterfaceInterface>(p.GetObject())->GetProp4()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITestbed2NestedStruct1InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	const auto prop1Iter = j.find("prop1");
	if (prop1Iter != j.end() && !prop1Iter->is_null() && prop1Iter->is_object())
	{
		Cast<ITestbed2NestedStruct1InterfaceInterface>(p.GetObject())->SetProp1(prop1Iter->get<FTestbed2NestedStruct1>());
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: interface property 'prop1' missing or type mismatch in ITestbed2NestedStruct1InterfaceInterface -> ignore"));
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITestbed2NestedStruct1InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"prop1", Cast<ITestbed2NestedStruct1InterfaceInterface>(p.GetObject())->GetProp1()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITestbed2NestedStruct2InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	const auto prop1Iter = j.find("prop1");
	if (prop1Iter != j.end() && !prop1Iter->is_null() && prop1Iter->is_object())
	{
		Cast<ITestbed2NestedStruct2InterfaceInterface>(p.GetObject())->SetProp1(prop1Iter->get<FTestbed2NestedStruct1>());
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: interface property 'prop1' missing or type mismatch in ITestbed2NestedStruct2InterfaceInterface -> ignore"));
	}

	const auto prop2Iter = j.find("prop2");
	if (prop2Iter != j.end() && !prop2Iter->is_null() && prop2Iter->is_object())
	{
		Cast<ITestbed2NestedStruct2InterfaceInterface>(p.GetObject())->SetProp2(prop2Iter->get<FTestbed2NestedStruct2>());
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: interface property 'prop2' missing or type mismatch in ITestbed2NestedStruct2InterfaceInterface -> ignore"));
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITestbed2NestedStruct2InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"prop1", Cast<ITestbed2NestedStruct2InterfaceInterface>(p.GetObject())->GetProp1()}, {"prop2", Cast<ITestbed2NestedStruct2InterfaceInterface>(p.GetObject())->GetProp2()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITestbed2NestedStruct3InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	const auto prop1Iter = j.find("prop1");
	if (prop1Iter != j.end() && !prop1Iter->is_null() && prop1Iter->is_object())
	{
		Cast<ITestbed2NestedStruct3InterfaceInterface>(p.GetObject())->SetProp1(prop1Iter->get<FTestbed2NestedStruct1>());
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: interface property 'prop1' missing or type mismatch in ITestbed2NestedStruct3InterfaceInterface -> ignore"));
	}

	const auto prop2Iter = j.find("prop2");
	if (prop2Iter != j.end() && !prop2Iter->is_null() && prop2Iter->is_object())
	{
		Cast<ITestbed2NestedStruct3InterfaceInterface>(p.GetObject())->SetProp2(prop2Iter->get<FTestbed2NestedStruct2>());
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: interface property 'prop2' missing or type mismatch in ITestbed2NestedStruct3InterfaceInterface -> ignore"));
	}

	const auto prop3Iter = j.find("prop3");
	if (prop3Iter != j.end() && !prop3Iter->is_null() && prop3Iter->is_object())
	{
		Cast<ITestbed2NestedStruct3InterfaceInterface>(p.GetObject())->SetProp3(prop3Iter->get<FTestbed2NestedStruct3>());
	}
	else
	{
		UE_LOG(LogTestbed2, Error, TEXT("from_json: interface property 'prop3' missing or type mismatch in ITestbed2NestedStruct3InterfaceInterface -> ignore"));
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITestbed2NestedStruct3InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"prop1", Cast<ITestbed2NestedStruct3InterfaceInterface>(p.GetObject())->GetProp1()}, {"prop2", Cast<ITestbed2NestedStruct3InterfaceInterface>(p.GetObject())->GetProp2()}, {"prop3", Cast<ITestbed2NestedStruct3InterfaceInterface>(p.GetObject())->GetProp3()}};
}
