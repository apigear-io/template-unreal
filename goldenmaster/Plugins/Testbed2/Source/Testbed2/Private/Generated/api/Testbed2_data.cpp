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

#include "Generated/api/Testbed2_data.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"

/**
 * Enumeration ETestbed2Enum1
 */
bool UTestbed2Library::toTestbed2Enum1(ETestbed2Enum1& ConvertedEnum, uint8 InValue)
{
	bool bSuccessful = false;
	switch (InValue)
	{
	case 1:
		ConvertedEnum = ETestbed2Enum1::T2E1_Value1;
		bSuccessful = true;
		break;
	case 2:
		ConvertedEnum = ETestbed2Enum1::T2E1_Value2;
		bSuccessful = true;
		break;
	case 3:
		ConvertedEnum = ETestbed2Enum1::T2E1_Value3;
		bSuccessful = true;
		break;
	case 4:
		ConvertedEnum = ETestbed2Enum1::T2E1_Value4;
		bSuccessful = true;
		break;
	default:
		ConvertedEnum = ETestbed2Enum1::T2E1_Value1;
	}
	return bSuccessful;
}
/**
 * Enumeration ETestbed2Enum2
 */
bool UTestbed2Library::toTestbed2Enum2(ETestbed2Enum2& ConvertedEnum, uint8 InValue)
{
	bool bSuccessful = false;
	switch (InValue)
	{
	case 1:
		ConvertedEnum = ETestbed2Enum2::T2E2_Value1;
		bSuccessful = true;
		break;
	case 2:
		ConvertedEnum = ETestbed2Enum2::T2E2_Value2;
		bSuccessful = true;
		break;
	case 3:
		ConvertedEnum = ETestbed2Enum2::T2E2_Value3;
		bSuccessful = true;
		break;
	case 4:
		ConvertedEnum = ETestbed2Enum2::T2E2_Value4;
		bSuccessful = true;
		break;
	default:
		ConvertedEnum = ETestbed2Enum2::T2E2_Value1;
	}
	return bSuccessful;
}
/**
 * Enumeration ETestbed2Enum3
 */
bool UTestbed2Library::toTestbed2Enum3(ETestbed2Enum3& ConvertedEnum, uint8 InValue)
{
	bool bSuccessful = false;
	switch (InValue)
	{
	case 1:
		ConvertedEnum = ETestbed2Enum3::T2E3_Value1;
		bSuccessful = true;
		break;
	case 2:
		ConvertedEnum = ETestbed2Enum3::T2E3_Value2;
		bSuccessful = true;
		break;
	case 3:
		ConvertedEnum = ETestbed2Enum3::T2E3_Value3;
		bSuccessful = true;
		break;
	case 4:
		ConvertedEnum = ETestbed2Enum3::T2E3_Value4;
		bSuccessful = true;
		break;
	default:
		ConvertedEnum = ETestbed2Enum3::T2E3_Value1;
	}
	return bSuccessful;
}

bool FTestbed2Struct1::operator==(const FTestbed2Struct1& rhs) const
{
	return (field1 == rhs.field1);
}

bool FTestbed2Struct1::operator!=(const FTestbed2Struct1& rhs) const
{
	return !operator==(rhs);
}

FTestbed2Struct1::operator FString() const
{
	return ToString();
}

FString FTestbed2Struct1::ToString() const
{
	return ToJSON(true);
}

FString FTestbed2Struct1::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed2Struct2::operator==(const FTestbed2Struct2& rhs) const
{
	return (field1 == rhs.field1) && (field2 == rhs.field2);
}

bool FTestbed2Struct2::operator!=(const FTestbed2Struct2& rhs) const
{
	return !operator==(rhs);
}

FTestbed2Struct2::operator FString() const
{
	return ToString();
}

FString FTestbed2Struct2::ToString() const
{
	return ToJSON(true);
}

FString FTestbed2Struct2::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed2Struct3::operator==(const FTestbed2Struct3& rhs) const
{
	return (field1 == rhs.field1) && (field2 == rhs.field2) && (field3 == rhs.field3);
}

bool FTestbed2Struct3::operator!=(const FTestbed2Struct3& rhs) const
{
	return !operator==(rhs);
}

FTestbed2Struct3::operator FString() const
{
	return ToString();
}

FString FTestbed2Struct3::ToString() const
{
	return ToJSON(true);
}

FString FTestbed2Struct3::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed2Struct4::operator==(const FTestbed2Struct4& rhs) const
{
	return (field1 == rhs.field1) && (field2 == rhs.field2) && (field3 == rhs.field3) && (field4 == rhs.field4);
}

bool FTestbed2Struct4::operator!=(const FTestbed2Struct4& rhs) const
{
	return !operator==(rhs);
}

FTestbed2Struct4::operator FString() const
{
	return ToString();
}

FString FTestbed2Struct4::ToString() const
{
	return ToJSON(true);
}

FString FTestbed2Struct4::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed2NestedStruct1::operator==(const FTestbed2NestedStruct1& rhs) const
{
	return (field1 == rhs.field1);
}

bool FTestbed2NestedStruct1::operator!=(const FTestbed2NestedStruct1& rhs) const
{
	return !operator==(rhs);
}

FTestbed2NestedStruct1::operator FString() const
{
	return ToString();
}

FString FTestbed2NestedStruct1::ToString() const
{
	return ToJSON(true);
}

FString FTestbed2NestedStruct1::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed2NestedStruct2::operator==(const FTestbed2NestedStruct2& rhs) const
{
	return (field1 == rhs.field1) && (field2 == rhs.field2);
}

bool FTestbed2NestedStruct2::operator!=(const FTestbed2NestedStruct2& rhs) const
{
	return !operator==(rhs);
}

FTestbed2NestedStruct2::operator FString() const
{
	return ToString();
}

FString FTestbed2NestedStruct2::ToString() const
{
	return ToJSON(true);
}

FString FTestbed2NestedStruct2::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTestbed2NestedStruct3::operator==(const FTestbed2NestedStruct3& rhs) const
{
	return (field1 == rhs.field1) && (field2 == rhs.field2) && (field3 == rhs.field3);
}

bool FTestbed2NestedStruct3::operator!=(const FTestbed2NestedStruct3& rhs) const
{
	return !operator==(rhs);
}

FTestbed2NestedStruct3::operator FString() const
{
	return ToString();
}

FString FTestbed2NestedStruct3::ToString() const
{
	return ToJSON(true);
}

FString FTestbed2NestedStruct3::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

/* Returns true if Testbed2Struct1 A is equal to Testbed2Struct1 B (A == B) */
bool UTestbed2Library::EqualEqual_Testbed2Struct1Testbed2Struct1(FTestbed2Struct1 A, FTestbed2Struct1 B)
{
	return A == B;
}

/* Returns true if Testbed2Struct1 A is not equal to Testbed2Struct1 B (A != B) */
bool UTestbed2Library::NotEqual_Testbed2Struct1Testbed2Struct1(FTestbed2Struct1 A, FTestbed2Struct1 B)
{
	return A != B;
}

FString UTestbed2Library::Conv_Testbed2Struct1ToString(const FTestbed2Struct1& InTestbed2Struct1)
{
	return InTestbed2Struct1.ToString();
}

FString UTestbed2Library::Conv_Testbed2Struct1ToJSON(const FTestbed2Struct1& InTestbed2Struct1)
{
	return InTestbed2Struct1.ToJSON();
}

/* Returns true if Testbed2Struct2 A is equal to Testbed2Struct2 B (A == B) */
bool UTestbed2Library::EqualEqual_Testbed2Struct2Testbed2Struct2(FTestbed2Struct2 A, FTestbed2Struct2 B)
{
	return A == B;
}

/* Returns true if Testbed2Struct2 A is not equal to Testbed2Struct2 B (A != B) */
bool UTestbed2Library::NotEqual_Testbed2Struct2Testbed2Struct2(FTestbed2Struct2 A, FTestbed2Struct2 B)
{
	return A != B;
}

FString UTestbed2Library::Conv_Testbed2Struct2ToString(const FTestbed2Struct2& InTestbed2Struct2)
{
	return InTestbed2Struct2.ToString();
}

FString UTestbed2Library::Conv_Testbed2Struct2ToJSON(const FTestbed2Struct2& InTestbed2Struct2)
{
	return InTestbed2Struct2.ToJSON();
}

/* Returns true if Testbed2Struct3 A is equal to Testbed2Struct3 B (A == B) */
bool UTestbed2Library::EqualEqual_Testbed2Struct3Testbed2Struct3(FTestbed2Struct3 A, FTestbed2Struct3 B)
{
	return A == B;
}

/* Returns true if Testbed2Struct3 A is not equal to Testbed2Struct3 B (A != B) */
bool UTestbed2Library::NotEqual_Testbed2Struct3Testbed2Struct3(FTestbed2Struct3 A, FTestbed2Struct3 B)
{
	return A != B;
}

FString UTestbed2Library::Conv_Testbed2Struct3ToString(const FTestbed2Struct3& InTestbed2Struct3)
{
	return InTestbed2Struct3.ToString();
}

FString UTestbed2Library::Conv_Testbed2Struct3ToJSON(const FTestbed2Struct3& InTestbed2Struct3)
{
	return InTestbed2Struct3.ToJSON();
}

/* Returns true if Testbed2Struct4 A is equal to Testbed2Struct4 B (A == B) */
bool UTestbed2Library::EqualEqual_Testbed2Struct4Testbed2Struct4(FTestbed2Struct4 A, FTestbed2Struct4 B)
{
	return A == B;
}

/* Returns true if Testbed2Struct4 A is not equal to Testbed2Struct4 B (A != B) */
bool UTestbed2Library::NotEqual_Testbed2Struct4Testbed2Struct4(FTestbed2Struct4 A, FTestbed2Struct4 B)
{
	return A != B;
}

FString UTestbed2Library::Conv_Testbed2Struct4ToString(const FTestbed2Struct4& InTestbed2Struct4)
{
	return InTestbed2Struct4.ToString();
}

FString UTestbed2Library::Conv_Testbed2Struct4ToJSON(const FTestbed2Struct4& InTestbed2Struct4)
{
	return InTestbed2Struct4.ToJSON();
}

/* Returns true if Testbed2NestedStruct1 A is equal to Testbed2NestedStruct1 B (A == B) */
bool UTestbed2Library::EqualEqual_Testbed2NestedStruct1Testbed2NestedStruct1(FTestbed2NestedStruct1 A, FTestbed2NestedStruct1 B)
{
	return A == B;
}

/* Returns true if Testbed2NestedStruct1 A is not equal to Testbed2NestedStruct1 B (A != B) */
bool UTestbed2Library::NotEqual_Testbed2NestedStruct1Testbed2NestedStruct1(FTestbed2NestedStruct1 A, FTestbed2NestedStruct1 B)
{
	return A != B;
}

FString UTestbed2Library::Conv_Testbed2NestedStruct1ToString(const FTestbed2NestedStruct1& InTestbed2NestedStruct1)
{
	return InTestbed2NestedStruct1.ToString();
}

FString UTestbed2Library::Conv_Testbed2NestedStruct1ToJSON(const FTestbed2NestedStruct1& InTestbed2NestedStruct1)
{
	return InTestbed2NestedStruct1.ToJSON();
}

/* Returns true if Testbed2NestedStruct2 A is equal to Testbed2NestedStruct2 B (A == B) */
bool UTestbed2Library::EqualEqual_Testbed2NestedStruct2Testbed2NestedStruct2(FTestbed2NestedStruct2 A, FTestbed2NestedStruct2 B)
{
	return A == B;
}

/* Returns true if Testbed2NestedStruct2 A is not equal to Testbed2NestedStruct2 B (A != B) */
bool UTestbed2Library::NotEqual_Testbed2NestedStruct2Testbed2NestedStruct2(FTestbed2NestedStruct2 A, FTestbed2NestedStruct2 B)
{
	return A != B;
}

FString UTestbed2Library::Conv_Testbed2NestedStruct2ToString(const FTestbed2NestedStruct2& InTestbed2NestedStruct2)
{
	return InTestbed2NestedStruct2.ToString();
}

FString UTestbed2Library::Conv_Testbed2NestedStruct2ToJSON(const FTestbed2NestedStruct2& InTestbed2NestedStruct2)
{
	return InTestbed2NestedStruct2.ToJSON();
}

/* Returns true if Testbed2NestedStruct3 A is equal to Testbed2NestedStruct3 B (A == B) */
bool UTestbed2Library::EqualEqual_Testbed2NestedStruct3Testbed2NestedStruct3(FTestbed2NestedStruct3 A, FTestbed2NestedStruct3 B)
{
	return A == B;
}

/* Returns true if Testbed2NestedStruct3 A is not equal to Testbed2NestedStruct3 B (A != B) */
bool UTestbed2Library::NotEqual_Testbed2NestedStruct3Testbed2NestedStruct3(FTestbed2NestedStruct3 A, FTestbed2NestedStruct3 B)
{
	return A != B;
}

FString UTestbed2Library::Conv_Testbed2NestedStruct3ToString(const FTestbed2NestedStruct3& InTestbed2NestedStruct3)
{
	return InTestbed2NestedStruct3.ToString();
}

FString UTestbed2Library::Conv_Testbed2NestedStruct3ToJSON(const FTestbed2NestedStruct3& InTestbed2NestedStruct3)
{
	return InTestbed2NestedStruct3.ToJSON();
}
