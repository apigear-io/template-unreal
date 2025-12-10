#pragma once

#include "apigear.json.adapter.h"
#include "Testbed1/Generated/Testbed1LogCategories.h"
#include "Testbed1/Generated/api/Testbed1_data.h"
#include "Testbed1/Generated/api/Testbed1StructInterfaceInterface.h"
#include "Testbed1/Generated/api/Testbed1StructArrayInterfaceInterface.h"
#include "Testbed1/Generated/api/Testbed1StructArray2InterfaceInterface.h"

static void from_json(const nlohmann::json& j, FTestbed1StructBool& p)
{
	const auto fieldBoolIter = j.find("fieldBool");
	if (fieldBoolIter != j.end() && !fieldBoolIter->is_null() && fieldBoolIter->is_boolean())
	{
		p.fieldBool = fieldBoolIter->get<bool>();
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: struct field 'fieldBool' missing or type mismatch in FTestbed1StructBool -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed1StructBool& p)
{
	j = nlohmann::json{{"fieldBool", p.fieldBool}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructInt& p)
{
	const auto fieldIntIter = j.find("fieldInt");
	if (fieldIntIter != j.end() && !fieldIntIter->is_null() && fieldIntIter->is_number_integer())
	{
		p.fieldInt = fieldIntIter->get<int32>();
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: struct field 'fieldInt' missing or type mismatch in FTestbed1StructInt -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed1StructInt& p)
{
	j = nlohmann::json{{"fieldInt", p.fieldInt}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructFloat& p)
{
	const auto fieldFloatIter = j.find("fieldFloat");
	if (fieldFloatIter != j.end() && !fieldFloatIter->is_null() && fieldFloatIter->is_number())
	{
		p.fieldFloat = fieldFloatIter->get<float>();
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: struct field 'fieldFloat' missing or type mismatch in FTestbed1StructFloat -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed1StructFloat& p)
{
	j = nlohmann::json{{"fieldFloat", p.fieldFloat}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructString& p)
{
	const auto fieldStringIter = j.find("fieldString");
	if (fieldStringIter != j.end() && !fieldStringIter->is_null() && fieldStringIter->is_string())
	{
		p.fieldString = fieldStringIter->get<FString>();
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: struct field 'fieldString' missing or type mismatch in FTestbed1StructString -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed1StructString& p)
{
	j = nlohmann::json{{"fieldString", p.fieldString}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructStruct& p)
{
	const auto fieldStringIter = j.find("fieldString");
	if (fieldStringIter != j.end() && !fieldStringIter->is_null() && fieldStringIter->is_object())
	{
		p.fieldString = fieldStringIter->get<FTestbed1StructString>();
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: struct field 'fieldString' missing or type mismatch in FTestbed1StructStruct -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed1StructStruct& p)
{
	j = nlohmann::json{{"fieldString", p.fieldString}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructEnum& p)
{
	const auto fieldEnumIter = j.find("fieldEnum");
	if (fieldEnumIter != j.end() && !fieldEnumIter->is_null() && fieldEnumIter->is_number_integer())
	{
		p.fieldEnum = fieldEnumIter->get<ETestbed1Enum0>();
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: struct field 'fieldEnum' missing or type mismatch in FTestbed1StructEnum -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed1StructEnum& p)
{
	j = nlohmann::json{{"fieldEnum", p.fieldEnum}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructBoolWithArray& p)
{
	const auto fieldBoolIter = j.find("fieldBool");
	if (fieldBoolIter != j.end() && !fieldBoolIter->is_null() && fieldBoolIter->is_array())
	{
		p.fieldBool = fieldBoolIter->get<TArray<bool>>();
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: struct field 'fieldBool' missing or type mismatch in FTestbed1StructBoolWithArray -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed1StructBoolWithArray& p)
{
	j = nlohmann::json{{"fieldBool", p.fieldBool}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructIntWithArray& p)
{
	const auto fieldIntIter = j.find("fieldInt");
	if (fieldIntIter != j.end() && !fieldIntIter->is_null() && fieldIntIter->is_array())
	{
		p.fieldInt = fieldIntIter->get<TArray<int32>>();
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: struct field 'fieldInt' missing or type mismatch in FTestbed1StructIntWithArray -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed1StructIntWithArray& p)
{
	j = nlohmann::json{{"fieldInt", p.fieldInt}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructFloatWithArray& p)
{
	const auto fieldFloatIter = j.find("fieldFloat");
	if (fieldFloatIter != j.end() && !fieldFloatIter->is_null() && fieldFloatIter->is_array())
	{
		p.fieldFloat = fieldFloatIter->get<TArray<float>>();
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: struct field 'fieldFloat' missing or type mismatch in FTestbed1StructFloatWithArray -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed1StructFloatWithArray& p)
{
	j = nlohmann::json{{"fieldFloat", p.fieldFloat}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructStringWithArray& p)
{
	const auto fieldStringIter = j.find("fieldString");
	if (fieldStringIter != j.end() && !fieldStringIter->is_null() && fieldStringIter->is_array())
	{
		p.fieldString = fieldStringIter->get<TArray<FString>>();
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: struct field 'fieldString' missing or type mismatch in FTestbed1StructStringWithArray -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed1StructStringWithArray& p)
{
	j = nlohmann::json{{"fieldString", p.fieldString}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructStructWithArray& p)
{
	const auto fieldStructIter = j.find("fieldStruct");
	if (fieldStructIter != j.end() && !fieldStructIter->is_null() && fieldStructIter->is_array())
	{
		p.fieldStruct = fieldStructIter->get<TArray<FTestbed1StructStringWithArray>>();
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: struct field 'fieldStruct' missing or type mismatch in FTestbed1StructStructWithArray -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed1StructStructWithArray& p)
{
	j = nlohmann::json{{"fieldStruct", p.fieldStruct}};
}

static void from_json(const nlohmann::json& j, FTestbed1StructEnumWithArray& p)
{
	const auto fieldEnumIter = j.find("fieldEnum");
	if (fieldEnumIter != j.end() && !fieldEnumIter->is_null() && fieldEnumIter->is_array())
	{
		p.fieldEnum = fieldEnumIter->get<TArray<ETestbed1Enum0>>();
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: struct field 'fieldEnum' missing or type mismatch in FTestbed1StructEnumWithArray -> using default value"));
	}
}

static void to_json(nlohmann::json& j, const FTestbed1StructEnumWithArray& p)
{
	j = nlohmann::json{{"fieldEnum", p.fieldEnum}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITestbed1StructInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	const auto propBoolIter = j.find("propBool");
	if (propBoolIter != j.end() && !propBoolIter->is_null() && propBoolIter->is_object())
	{
		Cast<ITestbed1StructInterfaceInterface>(p.GetObject())->SetPropBool(propBoolIter->get<FTestbed1StructBool>());
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: interface property 'propBool' missing or type mismatch in ITestbed1StructInterfaceInterface -> ignore"));
	}

	const auto propIntIter = j.find("propInt");
	if (propIntIter != j.end() && !propIntIter->is_null() && propIntIter->is_object())
	{
		Cast<ITestbed1StructInterfaceInterface>(p.GetObject())->SetPropInt(propIntIter->get<FTestbed1StructInt>());
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: interface property 'propInt' missing or type mismatch in ITestbed1StructInterfaceInterface -> ignore"));
	}

	const auto propFloatIter = j.find("propFloat");
	if (propFloatIter != j.end() && !propFloatIter->is_null() && propFloatIter->is_object())
	{
		Cast<ITestbed1StructInterfaceInterface>(p.GetObject())->SetPropFloat(propFloatIter->get<FTestbed1StructFloat>());
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: interface property 'propFloat' missing or type mismatch in ITestbed1StructInterfaceInterface -> ignore"));
	}

	const auto propStringIter = j.find("propString");
	if (propStringIter != j.end() && !propStringIter->is_null() && propStringIter->is_object())
	{
		Cast<ITestbed1StructInterfaceInterface>(p.GetObject())->SetPropString(propStringIter->get<FTestbed1StructString>());
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: interface property 'propString' missing or type mismatch in ITestbed1StructInterfaceInterface -> ignore"));
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITestbed1StructInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"propBool", Cast<ITestbed1StructInterfaceInterface>(p.GetObject())->GetPropBool()}, {"propInt", Cast<ITestbed1StructInterfaceInterface>(p.GetObject())->GetPropInt()}, {"propFloat", Cast<ITestbed1StructInterfaceInterface>(p.GetObject())->GetPropFloat()}, {"propString", Cast<ITestbed1StructInterfaceInterface>(p.GetObject())->GetPropString()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITestbed1StructArrayInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	const auto propBoolIter = j.find("propBool");
	if (propBoolIter != j.end() && !propBoolIter->is_null() && propBoolIter->is_array())
	{
		Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->SetPropBool(propBoolIter->get<TArray<FTestbed1StructBool>>());
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: interface property 'propBool' missing or type mismatch in ITestbed1StructArrayInterfaceInterface -> ignore"));
	}

	const auto propIntIter = j.find("propInt");
	if (propIntIter != j.end() && !propIntIter->is_null() && propIntIter->is_array())
	{
		Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->SetPropInt(propIntIter->get<TArray<FTestbed1StructInt>>());
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: interface property 'propInt' missing or type mismatch in ITestbed1StructArrayInterfaceInterface -> ignore"));
	}

	const auto propFloatIter = j.find("propFloat");
	if (propFloatIter != j.end() && !propFloatIter->is_null() && propFloatIter->is_array())
	{
		Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->SetPropFloat(propFloatIter->get<TArray<FTestbed1StructFloat>>());
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: interface property 'propFloat' missing or type mismatch in ITestbed1StructArrayInterfaceInterface -> ignore"));
	}

	const auto propStringIter = j.find("propString");
	if (propStringIter != j.end() && !propStringIter->is_null() && propStringIter->is_array())
	{
		Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->SetPropString(propStringIter->get<TArray<FTestbed1StructString>>());
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: interface property 'propString' missing or type mismatch in ITestbed1StructArrayInterfaceInterface -> ignore"));
	}

	const auto propEnumIter = j.find("propEnum");
	if (propEnumIter != j.end() && !propEnumIter->is_null() && propEnumIter->is_array())
	{
		Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->SetPropEnum(propEnumIter->get<TArray<ETestbed1Enum0>>());
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: interface property 'propEnum' missing or type mismatch in ITestbed1StructArrayInterfaceInterface -> ignore"));
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITestbed1StructArrayInterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"propBool", Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->GetPropBool()}, {"propInt", Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->GetPropInt()}, {"propFloat", Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->GetPropFloat()}, {"propString", Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->GetPropString()}, {"propEnum", Cast<ITestbed1StructArrayInterfaceInterface>(p.GetObject())->GetPropEnum()}};
}

static void from_json(const nlohmann::json& j, TScriptInterface<ITestbed1StructArray2InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	const auto propBoolIter = j.find("propBool");
	if (propBoolIter != j.end() && !propBoolIter->is_null() && propBoolIter->is_object())
	{
		Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->SetPropBool(propBoolIter->get<FTestbed1StructBoolWithArray>());
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: interface property 'propBool' missing or type mismatch in ITestbed1StructArray2InterfaceInterface -> ignore"));
	}

	const auto propIntIter = j.find("propInt");
	if (propIntIter != j.end() && !propIntIter->is_null() && propIntIter->is_object())
	{
		Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->SetPropInt(propIntIter->get<FTestbed1StructIntWithArray>());
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: interface property 'propInt' missing or type mismatch in ITestbed1StructArray2InterfaceInterface -> ignore"));
	}

	const auto propFloatIter = j.find("propFloat");
	if (propFloatIter != j.end() && !propFloatIter->is_null() && propFloatIter->is_object())
	{
		Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->SetPropFloat(propFloatIter->get<FTestbed1StructFloatWithArray>());
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: interface property 'propFloat' missing or type mismatch in ITestbed1StructArray2InterfaceInterface -> ignore"));
	}

	const auto propStringIter = j.find("propString");
	if (propStringIter != j.end() && !propStringIter->is_null() && propStringIter->is_object())
	{
		Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->SetPropString(propStringIter->get<FTestbed1StructStringWithArray>());
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: interface property 'propString' missing or type mismatch in ITestbed1StructArray2InterfaceInterface -> ignore"));
	}

	const auto propEnumIter = j.find("propEnum");
	if (propEnumIter != j.end() && !propEnumIter->is_null() && propEnumIter->is_object())
	{
		Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->SetPropEnum(propEnumIter->get<FTestbed1StructEnumWithArray>());
	}
	else
	{
		UE_LOG(LogTestbed1, Error, TEXT("from_json: interface property 'propEnum' missing or type mismatch in ITestbed1StructArray2InterfaceInterface -> ignore"));
	}
}

static void to_json(nlohmann::json& j, const TScriptInterface<ITestbed1StructArray2InterfaceInterface>& p)
{
	if (!p)
	{
		return;
	}

	j = nlohmann::json{{"propBool", Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->GetPropBool()}, {"propInt", Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->GetPropInt()}, {"propFloat", Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->GetPropFloat()}, {"propString", Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->GetPropString()}, {"propEnum", Cast<ITestbed1StructArray2InterfaceInterface>(p.GetObject())->GetPropEnum()}};
}
