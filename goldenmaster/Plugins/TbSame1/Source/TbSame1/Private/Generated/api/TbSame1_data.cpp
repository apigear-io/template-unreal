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

#include "Generated/api/TbSame1_data.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"

/**
 * Enumeration ETbSame1Enum1
 */
bool UTbSame1Library::toTbSame1Enum1(ETbSame1Enum1& ConvertedEnum, uint8 InValue)
{
	bool bSuccessful = false;
	switch (InValue)
	{
	case 1:
		ConvertedEnum = ETbSame1Enum1::TS1E1_Value1;
		bSuccessful = true;
		break;
	case 2:
		ConvertedEnum = ETbSame1Enum1::TS1E1_Value2;
		bSuccessful = true;
		break;
	default:
		ConvertedEnum = ETbSame1Enum1::TS1E1_Value1;
	}
	return bSuccessful;
}
/**
 * Enumeration ETbSame1Enum2
 */
bool UTbSame1Library::toTbSame1Enum2(ETbSame1Enum2& ConvertedEnum, uint8 InValue)
{
	bool bSuccessful = false;
	switch (InValue)
	{
	case 1:
		ConvertedEnum = ETbSame1Enum2::TS1E2_Value1;
		bSuccessful = true;
		break;
	case 2:
		ConvertedEnum = ETbSame1Enum2::TS1E2_Value2;
		bSuccessful = true;
		break;
	default:
		ConvertedEnum = ETbSame1Enum2::TS1E2_Value1;
	}
	return bSuccessful;
}

bool FTbSame1Struct1::operator==(const FTbSame1Struct1& rhs) const
{
	return (field1 == rhs.field1) && (field2 == rhs.field2) && (field3 == rhs.field3);
}

bool FTbSame1Struct1::operator!=(const FTbSame1Struct1& rhs) const
{
	return !operator==(rhs);
}

FTbSame1Struct1::operator FString() const
{
	return ToString();
}

FString FTbSame1Struct1::ToString() const
{
	return ToJSON(true);
}

FString FTbSame1Struct1::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTbSame1Struct2::operator==(const FTbSame1Struct2& rhs) const
{
	return (field1 == rhs.field1) && (field2 == rhs.field2) && (field3 == rhs.field3);
}

bool FTbSame1Struct2::operator!=(const FTbSame1Struct2& rhs) const
{
	return !operator==(rhs);
}

FTbSame1Struct2::operator FString() const
{
	return ToString();
}

FString FTbSame1Struct2::ToString() const
{
	return ToJSON(true);
}

FString FTbSame1Struct2::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

/* Returns true if TbSame1Struct1 A is equal to TbSame1Struct1 B (A == B) */
bool UTbSame1Library::EqualEqual_TbSame1Struct1TbSame1Struct1(FTbSame1Struct1 A, FTbSame1Struct1 B)
{
	return A == B;
}

/* Returns true if TbSame1Struct1 A is not equal to TbSame1Struct1 B (A != B) */
bool UTbSame1Library::NotEqual_TbSame1Struct1TbSame1Struct1(FTbSame1Struct1 A, FTbSame1Struct1 B)
{
	return A != B;
}

FString UTbSame1Library::Conv_TbSame1Struct1ToString(const FTbSame1Struct1& InTbSame1Struct1)
{
	return InTbSame1Struct1.ToString();
}

FString UTbSame1Library::Conv_TbSame1Struct1ToJSON(const FTbSame1Struct1& InTbSame1Struct1)
{
	return InTbSame1Struct1.ToJSON();
}

/* Returns true if TbSame1Struct2 A is equal to TbSame1Struct2 B (A == B) */
bool UTbSame1Library::EqualEqual_TbSame1Struct2TbSame1Struct2(FTbSame1Struct2 A, FTbSame1Struct2 B)
{
	return A == B;
}

/* Returns true if TbSame1Struct2 A is not equal to TbSame1Struct2 B (A != B) */
bool UTbSame1Library::NotEqual_TbSame1Struct2TbSame1Struct2(FTbSame1Struct2 A, FTbSame1Struct2 B)
{
	return A != B;
}

FString UTbSame1Library::Conv_TbSame1Struct2ToString(const FTbSame1Struct2& InTbSame1Struct2)
{
	return InTbSame1Struct2.ToString();
}

FString UTbSame1Library::Conv_TbSame1Struct2ToJSON(const FTbSame1Struct2& InTbSame1Struct2)
{
	return InTbSame1Struct2.ToJSON();
}
