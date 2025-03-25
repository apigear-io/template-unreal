#pragma once

#include "apigear.json.adapter.h"
#include "Testbed2/Generated/api/Testbed2_data.h"
#include "Testbed2/Generated/api/Testbed2ManyParamInterfaceInterface.h"
#include "Testbed2/Generated/api/Testbed2NestedStruct1InterfaceInterface.h"
#include "Testbed2/Generated/api/Testbed2NestedStruct2InterfaceInterface.h"
#include "Testbed2/Generated/api/Testbed2NestedStruct3InterfaceInterface.h"

static void from_json(const nlohmann::json& j, FTestbed2Struct1& p)
{
	p.field1 = j.at("field1").get<int32>();
}

static void to_json(nlohmann::json& j, const FTestbed2Struct1& p)
{
	j = nlohmann::json{{"field1", p.field1}};
}

static void from_json(const nlohmann::json& j, FTestbed2Struct2& p)
{
	p.field1 = j.at("field1").get<int32>();
	p.field2 = j.at("field2").get<int32>();
}

static void to_json(nlohmann::json& j, const FTestbed2Struct2& p)
{
	j = nlohmann::json{{"field1", p.field1}, {"field2", p.field2}};
}

static void from_json(const nlohmann::json& j, FTestbed2Struct3& p)
{
	p.field1 = j.at("field1").get<int32>();
	p.field2 = j.at("field2").get<int32>();
	p.field3 = j.at("field3").get<int32>();
}

static void to_json(nlohmann::json& j, const FTestbed2Struct3& p)
{
	j = nlohmann::json{{"field1", p.field1}, {"field2", p.field2}, {"field3", p.field3}};
}

static void from_json(const nlohmann::json& j, FTestbed2Struct4& p)
{
	p.field1 = j.at("field1").get<int32>();
	p.field2 = j.at("field2").get<int32>();
	p.field3 = j.at("field3").get<int32>();
	p.field4 = j.at("field4").get<int32>();
}

static void to_json(nlohmann::json& j, const FTestbed2Struct4& p)
{
	j = nlohmann::json{{"field1", p.field1}, {"field2", p.field2}, {"field3", p.field3}, {"field4", p.field4}};
}

static void from_json(const nlohmann::json& j, FTestbed2NestedStruct1& p)
{
	p.field1 = j.at("field1").get<FTestbed2Struct1>();
}

static void to_json(nlohmann::json& j, const FTestbed2NestedStruct1& p)
{
	j = nlohmann::json{{"field1", p.field1}};
}

static void from_json(const nlohmann::json& j, FTestbed2NestedStruct2& p)
{
	p.field1 = j.at("field1").get<FTestbed2Struct1>();
	p.field2 = j.at("field2").get<FTestbed2Struct2>();
}

static void to_json(nlohmann::json& j, const FTestbed2NestedStruct2& p)
{
	j = nlohmann::json{{"field1", p.field1}, {"field2", p.field2}};
}

static void from_json(const nlohmann::json& j, FTestbed2NestedStruct3& p)
{
	p.field1 = j.at("field1").get<FTestbed2Struct1>();
	p.field2 = j.at("field2").get<FTestbed2Struct2>();
	p.field3 = j.at("field3").get<FTestbed2Struct3>();
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

	Cast<ITestbed2ManyParamInterfaceInterface>(p.GetObject())->SetProp1(j.at("prop1").get<int32>());
	Cast<ITestbed2ManyParamInterfaceInterface>(p.GetObject())->SetProp2(j.at("prop2").get<int32>());
	Cast<ITestbed2ManyParamInterfaceInterface>(p.GetObject())->SetProp3(j.at("prop3").get<int32>());
	Cast<ITestbed2ManyParamInterfaceInterface>(p.GetObject())->SetProp4(j.at("prop4").get<int32>());
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

	Cast<ITestbed2NestedStruct1InterfaceInterface>(p.GetObject())->SetProp1(j.at("prop1").get<FTestbed2NestedStruct1>());
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

	Cast<ITestbed2NestedStruct2InterfaceInterface>(p.GetObject())->SetProp1(j.at("prop1").get<FTestbed2NestedStruct1>());
	Cast<ITestbed2NestedStruct2InterfaceInterface>(p.GetObject())->SetProp2(j.at("prop2").get<FTestbed2NestedStruct2>());
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

	Cast<ITestbed2NestedStruct3InterfaceInterface>(p.GetObject())->SetProp1(j.at("prop1").get<FTestbed2NestedStruct1>());
	Cast<ITestbed2NestedStruct3InterfaceInterface>(p.GetObject())->SetProp2(j.at("prop2").get<FTestbed2NestedStruct2>());
	Cast<ITestbed2NestedStruct3InterfaceInterface>(p.GetObject())->SetProp3(j.at("prop3").get<FTestbed2NestedStruct3>());
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITestbed2NestedStruct3InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"prop1", Cast<ITestbed2NestedStruct3InterfaceInterface>(p.GetObject())->GetProp1()}, {"prop2", Cast<ITestbed2NestedStruct3InterfaceInterface>(p.GetObject())->GetProp2()}, {"prop3", Cast<ITestbed2NestedStruct3InterfaceInterface>(p.GetObject())->GetProp3()}};
}
