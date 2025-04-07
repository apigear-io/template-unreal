/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "Generated/api/Testbed1_data.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"

/**
 * Enumeration ETestbed1Enum0
 */
bool UTestbed1Library::toTestbed1Enum0(ETestbed1Enum0& ConvertedEnum, uint8 InValue)
{
	bool bSuccessful = false;
	switch (InValue)
	{
	case 0:
		ConvertedEnum = ETestbed1Enum0::T1E0_VALUE0;
		bSuccessful = true;
		break;
	case 1:
		ConvertedEnum = ETestbed1Enum0::T1E0_VALUE1;
		bSuccessful = true;
		break;
	case 2:
		ConvertedEnum = ETestbed1Enum0::T1E0_VALUE2;
		bSuccessful = true;
		break;
	default:
		ConvertedEnum = ETestbed1Enum0::T1E0_VALUE0;
	}
	return bSuccessful;
}

bool FTestbed1StructBool::operator==(const FTestbed1StructBool& rhs) const
{
	return (fieldBool == rhs.fieldBool);
}

bool FTestbed1StructBool::operator!=(const FTestbed1StructBool& rhs) const
{
	return !operator==(rhs);
}

FTestbed1StructBool::operator FString() const
{
	return ToString();
}

FString FTestbed1StructBool::ToString() const
{
	return ToJSON(true);
}

FString FTestbed1StructBool::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed1StructInt::operator==(const FTestbed1StructInt& rhs) const
{
	return (fieldInt == rhs.fieldInt);
}

bool FTestbed1StructInt::operator!=(const FTestbed1StructInt& rhs) const
{
	return !operator==(rhs);
}

FTestbed1StructInt::operator FString() const
{
	return ToString();
}

FString FTestbed1StructInt::ToString() const
{
	return ToJSON(true);
}

FString FTestbed1StructInt::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed1StructFloat::operator==(const FTestbed1StructFloat& rhs) const
{
	return (fieldFloat == rhs.fieldFloat);
}

bool FTestbed1StructFloat::operator!=(const FTestbed1StructFloat& rhs) const
{
	return !operator==(rhs);
}

FTestbed1StructFloat::operator FString() const
{
	return ToString();
}

FString FTestbed1StructFloat::ToString() const
{
	return ToJSON(true);
}

FString FTestbed1StructFloat::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed1StructString::operator==(const FTestbed1StructString& rhs) const
{
	return (fieldString == rhs.fieldString);
}

bool FTestbed1StructString::operator!=(const FTestbed1StructString& rhs) const
{
	return !operator==(rhs);
}

FTestbed1StructString::operator FString() const
{
	return ToString();
}

FString FTestbed1StructString::ToString() const
{
	return ToJSON(true);
}

FString FTestbed1StructString::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed1StructStruct::operator==(const FTestbed1StructStruct& rhs) const
{
	return (fieldString == rhs.fieldString);
}

bool FTestbed1StructStruct::operator!=(const FTestbed1StructStruct& rhs) const
{
	return !operator==(rhs);
}

FTestbed1StructStruct::operator FString() const
{
	return ToString();
}

FString FTestbed1StructStruct::ToString() const
{
	return ToJSON(true);
}

FString FTestbed1StructStruct::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed1StructEnum::operator==(const FTestbed1StructEnum& rhs) const
{
	return (fieldEnum == rhs.fieldEnum);
}

bool FTestbed1StructEnum::operator!=(const FTestbed1StructEnum& rhs) const
{
	return !operator==(rhs);
}

FTestbed1StructEnum::operator FString() const
{
	return ToString();
}

FString FTestbed1StructEnum::ToString() const
{
	return ToJSON(true);
}

FString FTestbed1StructEnum::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed1StructBoolWithArray::operator==(const FTestbed1StructBoolWithArray& rhs) const
{
	return (fieldBool == rhs.fieldBool);
}

bool FTestbed1StructBoolWithArray::operator!=(const FTestbed1StructBoolWithArray& rhs) const
{
	return !operator==(rhs);
}

FTestbed1StructBoolWithArray::operator FString() const
{
	return ToString();
}

FString FTestbed1StructBoolWithArray::ToString() const
{
	return ToJSON(true);
}

FString FTestbed1StructBoolWithArray::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed1StructIntWithArray::operator==(const FTestbed1StructIntWithArray& rhs) const
{
	return (fieldInt == rhs.fieldInt);
}

bool FTestbed1StructIntWithArray::operator!=(const FTestbed1StructIntWithArray& rhs) const
{
	return !operator==(rhs);
}

FTestbed1StructIntWithArray::operator FString() const
{
	return ToString();
}

FString FTestbed1StructIntWithArray::ToString() const
{
	return ToJSON(true);
}

FString FTestbed1StructIntWithArray::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed1StructFloatWithArray::operator==(const FTestbed1StructFloatWithArray& rhs) const
{
	return (fieldFloat == rhs.fieldFloat);
}

bool FTestbed1StructFloatWithArray::operator!=(const FTestbed1StructFloatWithArray& rhs) const
{
	return !operator==(rhs);
}

FTestbed1StructFloatWithArray::operator FString() const
{
	return ToString();
}

FString FTestbed1StructFloatWithArray::ToString() const
{
	return ToJSON(true);
}

FString FTestbed1StructFloatWithArray::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed1StructStringWithArray::operator==(const FTestbed1StructStringWithArray& rhs) const
{
	return (fieldString == rhs.fieldString);
}

bool FTestbed1StructStringWithArray::operator!=(const FTestbed1StructStringWithArray& rhs) const
{
	return !operator==(rhs);
}

FTestbed1StructStringWithArray::operator FString() const
{
	return ToString();
}

FString FTestbed1StructStringWithArray::ToString() const
{
	return ToJSON(true);
}

FString FTestbed1StructStringWithArray::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed1StructStructWithArray::operator==(const FTestbed1StructStructWithArray& rhs) const
{
	return (fieldStruct == rhs.fieldStruct);
}

bool FTestbed1StructStructWithArray::operator!=(const FTestbed1StructStructWithArray& rhs) const
{
	return !operator==(rhs);
}

FTestbed1StructStructWithArray::operator FString() const
{
	return ToString();
}

FString FTestbed1StructStructWithArray::ToString() const
{
	return ToJSON(true);
}

FString FTestbed1StructStructWithArray::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed1StructEnumWithArray::operator==(const FTestbed1StructEnumWithArray& rhs) const
{
	return (fieldEnum == rhs.fieldEnum);
}

bool FTestbed1StructEnumWithArray::operator!=(const FTestbed1StructEnumWithArray& rhs) const
{
	return !operator==(rhs);
}

FTestbed1StructEnumWithArray::operator FString() const
{
	return ToString();
}

FString FTestbed1StructEnumWithArray::ToString() const
{
	return ToJSON(true);
}

FString FTestbed1StructEnumWithArray::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

/* Returns true if Testbed1StructBool A is equal to Testbed1StructBool B (A == B) */
bool UTestbed1Library::EqualEqual_Testbed1StructBoolTestbed1StructBool(FTestbed1StructBool A, FTestbed1StructBool B)
{
	return A == B;
}

/* Returns true if Testbed1StructBool A is not equal to Testbed1StructBool B (A != B) */
bool UTestbed1Library::NotEqual_Testbed1StructBoolTestbed1StructBool(FTestbed1StructBool A, FTestbed1StructBool B)
{
	return A != B;
}

FString UTestbed1Library::Conv_Testbed1StructBoolToString(const FTestbed1StructBool& InTestbed1StructBool)
{
	return InTestbed1StructBool.ToString();
}

FString UTestbed1Library::Conv_Testbed1StructBoolToJSON(const FTestbed1StructBool& InTestbed1StructBool)
{
	return InTestbed1StructBool.ToJSON();
}

/* Returns true if Testbed1StructInt A is equal to Testbed1StructInt B (A == B) */
bool UTestbed1Library::EqualEqual_Testbed1StructIntTestbed1StructInt(FTestbed1StructInt A, FTestbed1StructInt B)
{
	return A == B;
}

/* Returns true if Testbed1StructInt A is not equal to Testbed1StructInt B (A != B) */
bool UTestbed1Library::NotEqual_Testbed1StructIntTestbed1StructInt(FTestbed1StructInt A, FTestbed1StructInt B)
{
	return A != B;
}

FString UTestbed1Library::Conv_Testbed1StructIntToString(const FTestbed1StructInt& InTestbed1StructInt)
{
	return InTestbed1StructInt.ToString();
}

FString UTestbed1Library::Conv_Testbed1StructIntToJSON(const FTestbed1StructInt& InTestbed1StructInt)
{
	return InTestbed1StructInt.ToJSON();
}

/* Returns true if Testbed1StructFloat A is equal to Testbed1StructFloat B (A == B) */
bool UTestbed1Library::EqualEqual_Testbed1StructFloatTestbed1StructFloat(FTestbed1StructFloat A, FTestbed1StructFloat B)
{
	return A == B;
}

/* Returns true if Testbed1StructFloat A is not equal to Testbed1StructFloat B (A != B) */
bool UTestbed1Library::NotEqual_Testbed1StructFloatTestbed1StructFloat(FTestbed1StructFloat A, FTestbed1StructFloat B)
{
	return A != B;
}

FString UTestbed1Library::Conv_Testbed1StructFloatToString(const FTestbed1StructFloat& InTestbed1StructFloat)
{
	return InTestbed1StructFloat.ToString();
}

FString UTestbed1Library::Conv_Testbed1StructFloatToJSON(const FTestbed1StructFloat& InTestbed1StructFloat)
{
	return InTestbed1StructFloat.ToJSON();
}

/* Returns true if Testbed1StructString A is equal to Testbed1StructString B (A == B) */
bool UTestbed1Library::EqualEqual_Testbed1StructStringTestbed1StructString(FTestbed1StructString A, FTestbed1StructString B)
{
	return A == B;
}

/* Returns true if Testbed1StructString A is not equal to Testbed1StructString B (A != B) */
bool UTestbed1Library::NotEqual_Testbed1StructStringTestbed1StructString(FTestbed1StructString A, FTestbed1StructString B)
{
	return A != B;
}

FString UTestbed1Library::Conv_Testbed1StructStringToString(const FTestbed1StructString& InTestbed1StructString)
{
	return InTestbed1StructString.ToString();
}

FString UTestbed1Library::Conv_Testbed1StructStringToJSON(const FTestbed1StructString& InTestbed1StructString)
{
	return InTestbed1StructString.ToJSON();
}

/* Returns true if Testbed1StructStruct A is equal to Testbed1StructStruct B (A == B) */
bool UTestbed1Library::EqualEqual_Testbed1StructStructTestbed1StructStruct(FTestbed1StructStruct A, FTestbed1StructStruct B)
{
	return A == B;
}

/* Returns true if Testbed1StructStruct A is not equal to Testbed1StructStruct B (A != B) */
bool UTestbed1Library::NotEqual_Testbed1StructStructTestbed1StructStruct(FTestbed1StructStruct A, FTestbed1StructStruct B)
{
	return A != B;
}

FString UTestbed1Library::Conv_Testbed1StructStructToString(const FTestbed1StructStruct& InTestbed1StructStruct)
{
	return InTestbed1StructStruct.ToString();
}

FString UTestbed1Library::Conv_Testbed1StructStructToJSON(const FTestbed1StructStruct& InTestbed1StructStruct)
{
	return InTestbed1StructStruct.ToJSON();
}

/* Returns true if Testbed1StructEnum A is equal to Testbed1StructEnum B (A == B) */
bool UTestbed1Library::EqualEqual_Testbed1StructEnumTestbed1StructEnum(FTestbed1StructEnum A, FTestbed1StructEnum B)
{
	return A == B;
}

/* Returns true if Testbed1StructEnum A is not equal to Testbed1StructEnum B (A != B) */
bool UTestbed1Library::NotEqual_Testbed1StructEnumTestbed1StructEnum(FTestbed1StructEnum A, FTestbed1StructEnum B)
{
	return A != B;
}

FString UTestbed1Library::Conv_Testbed1StructEnumToString(const FTestbed1StructEnum& InTestbed1StructEnum)
{
	return InTestbed1StructEnum.ToString();
}

FString UTestbed1Library::Conv_Testbed1StructEnumToJSON(const FTestbed1StructEnum& InTestbed1StructEnum)
{
	return InTestbed1StructEnum.ToJSON();
}

/* Returns true if Testbed1StructBoolWithArray A is equal to Testbed1StructBoolWithArray B (A == B) */
bool UTestbed1Library::EqualEqual_Testbed1StructBoolWithArrayTestbed1StructBoolWithArray(FTestbed1StructBoolWithArray A, FTestbed1StructBoolWithArray B)
{
	return A == B;
}

/* Returns true if Testbed1StructBoolWithArray A is not equal to Testbed1StructBoolWithArray B (A != B) */
bool UTestbed1Library::NotEqual_Testbed1StructBoolWithArrayTestbed1StructBoolWithArray(FTestbed1StructBoolWithArray A, FTestbed1StructBoolWithArray B)
{
	return A != B;
}

FString UTestbed1Library::Conv_Testbed1StructBoolWithArrayToString(const FTestbed1StructBoolWithArray& InTestbed1StructBoolWithArray)
{
	return InTestbed1StructBoolWithArray.ToString();
}

FString UTestbed1Library::Conv_Testbed1StructBoolWithArrayToJSON(const FTestbed1StructBoolWithArray& InTestbed1StructBoolWithArray)
{
	return InTestbed1StructBoolWithArray.ToJSON();
}

/* Returns true if Testbed1StructIntWithArray A is equal to Testbed1StructIntWithArray B (A == B) */
bool UTestbed1Library::EqualEqual_Testbed1StructIntWithArrayTestbed1StructIntWithArray(FTestbed1StructIntWithArray A, FTestbed1StructIntWithArray B)
{
	return A == B;
}

/* Returns true if Testbed1StructIntWithArray A is not equal to Testbed1StructIntWithArray B (A != B) */
bool UTestbed1Library::NotEqual_Testbed1StructIntWithArrayTestbed1StructIntWithArray(FTestbed1StructIntWithArray A, FTestbed1StructIntWithArray B)
{
	return A != B;
}

FString UTestbed1Library::Conv_Testbed1StructIntWithArrayToString(const FTestbed1StructIntWithArray& InTestbed1StructIntWithArray)
{
	return InTestbed1StructIntWithArray.ToString();
}

FString UTestbed1Library::Conv_Testbed1StructIntWithArrayToJSON(const FTestbed1StructIntWithArray& InTestbed1StructIntWithArray)
{
	return InTestbed1StructIntWithArray.ToJSON();
}

/* Returns true if Testbed1StructFloatWithArray A is equal to Testbed1StructFloatWithArray B (A == B) */
bool UTestbed1Library::EqualEqual_Testbed1StructFloatWithArrayTestbed1StructFloatWithArray(FTestbed1StructFloatWithArray A, FTestbed1StructFloatWithArray B)
{
	return A == B;
}

/* Returns true if Testbed1StructFloatWithArray A is not equal to Testbed1StructFloatWithArray B (A != B) */
bool UTestbed1Library::NotEqual_Testbed1StructFloatWithArrayTestbed1StructFloatWithArray(FTestbed1StructFloatWithArray A, FTestbed1StructFloatWithArray B)
{
	return A != B;
}

FString UTestbed1Library::Conv_Testbed1StructFloatWithArrayToString(const FTestbed1StructFloatWithArray& InTestbed1StructFloatWithArray)
{
	return InTestbed1StructFloatWithArray.ToString();
}

FString UTestbed1Library::Conv_Testbed1StructFloatWithArrayToJSON(const FTestbed1StructFloatWithArray& InTestbed1StructFloatWithArray)
{
	return InTestbed1StructFloatWithArray.ToJSON();
}

/* Returns true if Testbed1StructStringWithArray A is equal to Testbed1StructStringWithArray B (A == B) */
bool UTestbed1Library::EqualEqual_Testbed1StructStringWithArrayTestbed1StructStringWithArray(FTestbed1StructStringWithArray A, FTestbed1StructStringWithArray B)
{
	return A == B;
}

/* Returns true if Testbed1StructStringWithArray A is not equal to Testbed1StructStringWithArray B (A != B) */
bool UTestbed1Library::NotEqual_Testbed1StructStringWithArrayTestbed1StructStringWithArray(FTestbed1StructStringWithArray A, FTestbed1StructStringWithArray B)
{
	return A != B;
}

FString UTestbed1Library::Conv_Testbed1StructStringWithArrayToString(const FTestbed1StructStringWithArray& InTestbed1StructStringWithArray)
{
	return InTestbed1StructStringWithArray.ToString();
}

FString UTestbed1Library::Conv_Testbed1StructStringWithArrayToJSON(const FTestbed1StructStringWithArray& InTestbed1StructStringWithArray)
{
	return InTestbed1StructStringWithArray.ToJSON();
}

/* Returns true if Testbed1StructStructWithArray A is equal to Testbed1StructStructWithArray B (A == B) */
bool UTestbed1Library::EqualEqual_Testbed1StructStructWithArrayTestbed1StructStructWithArray(FTestbed1StructStructWithArray A, FTestbed1StructStructWithArray B)
{
	return A == B;
}

/* Returns true if Testbed1StructStructWithArray A is not equal to Testbed1StructStructWithArray B (A != B) */
bool UTestbed1Library::NotEqual_Testbed1StructStructWithArrayTestbed1StructStructWithArray(FTestbed1StructStructWithArray A, FTestbed1StructStructWithArray B)
{
	return A != B;
}

FString UTestbed1Library::Conv_Testbed1StructStructWithArrayToString(const FTestbed1StructStructWithArray& InTestbed1StructStructWithArray)
{
	return InTestbed1StructStructWithArray.ToString();
}

FString UTestbed1Library::Conv_Testbed1StructStructWithArrayToJSON(const FTestbed1StructStructWithArray& InTestbed1StructStructWithArray)
{
	return InTestbed1StructStructWithArray.ToJSON();
}

/* Returns true if Testbed1StructEnumWithArray A is equal to Testbed1StructEnumWithArray B (A == B) */
bool UTestbed1Library::EqualEqual_Testbed1StructEnumWithArrayTestbed1StructEnumWithArray(FTestbed1StructEnumWithArray A, FTestbed1StructEnumWithArray B)
{
	return A == B;
}

/* Returns true if Testbed1StructEnumWithArray A is not equal to Testbed1StructEnumWithArray B (A != B) */
bool UTestbed1Library::NotEqual_Testbed1StructEnumWithArrayTestbed1StructEnumWithArray(FTestbed1StructEnumWithArray A, FTestbed1StructEnumWithArray B)
{
	return A != B;
}

FString UTestbed1Library::Conv_Testbed1StructEnumWithArrayToString(const FTestbed1StructEnumWithArray& InTestbed1StructEnumWithArray)
{
	return InTestbed1StructEnumWithArray.ToString();
}

FString UTestbed1Library::Conv_Testbed1StructEnumWithArrayToJSON(const FTestbed1StructEnumWithArray& InTestbed1StructEnumWithArray)
{
	return InTestbed1StructEnumWithArray.ToJSON();
}
