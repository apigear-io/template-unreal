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

#include "TbStructArray/Generated/api/TbStructArray_data.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"

/**
 * Enumeration ETbStructArrayTestEnum
 */
bool UTbStructArrayLibrary::toTbStructArrayTestEnum(ETbStructArrayTestEnum& ConvertedEnum, uint8 InValue)
{
	bool bSuccessful = false;
	switch (InValue)
	{
	case 1:
		ConvertedEnum = ETbStructArrayTestEnum::TSATE_Value1;
		bSuccessful = true;
		break;
	case 2:
		ConvertedEnum = ETbStructArrayTestEnum::TSATE_Value2;
		bSuccessful = true;
		break;
	default:
		ConvertedEnum = ETbStructArrayTestEnum::TSATE_Value1;
	}
	return bSuccessful;
}

bool FTbStructArrayPoint::operator==(const FTbStructArrayPoint& rhs) const
{
	return (x == rhs.x) && (y == rhs.y);
}

bool FTbStructArrayPoint::operator!=(const FTbStructArrayPoint& rhs) const
{
	return !operator==(rhs);
}

FTbStructArrayPoint::operator FString() const
{
	return ToString();
}

FString FTbStructArrayPoint::ToString() const
{
	return ToJSON(true);
}

FString FTbStructArrayPoint::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTbStructArrayStructWithArrayOfStructs::operator==(const FTbStructArrayStructWithArrayOfStructs& rhs) const
{
	return (points == rhs.points);
}

bool FTbStructArrayStructWithArrayOfStructs::operator!=(const FTbStructArrayStructWithArrayOfStructs& rhs) const
{
	return !operator==(rhs);
}

FTbStructArrayStructWithArrayOfStructs::operator FString() const
{
	return ToString();
}

FString FTbStructArrayStructWithArrayOfStructs::ToString() const
{
	return ToJSON(true);
}

FString FTbStructArrayStructWithArrayOfStructs::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTbStructArrayStructWithArrayOfEnums::operator==(const FTbStructArrayStructWithArrayOfEnums& rhs) const
{
	return (tags == rhs.tags);
}

bool FTbStructArrayStructWithArrayOfEnums::operator!=(const FTbStructArrayStructWithArrayOfEnums& rhs) const
{
	return !operator==(rhs);
}

FTbStructArrayStructWithArrayOfEnums::operator FString() const
{
	return ToString();
}

FString FTbStructArrayStructWithArrayOfEnums::ToString() const
{
	return ToJSON(true);
}

FString FTbStructArrayStructWithArrayOfEnums::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTbStructArrayStructWithArrayOfInts::operator==(const FTbStructArrayStructWithArrayOfInts& rhs) const
{
	return (values == rhs.values);
}

bool FTbStructArrayStructWithArrayOfInts::operator!=(const FTbStructArrayStructWithArrayOfInts& rhs) const
{
	return !operator==(rhs);
}

FTbStructArrayStructWithArrayOfInts::operator FString() const
{
	return ToString();
}

FString FTbStructArrayStructWithArrayOfInts::ToString() const
{
	return ToJSON(true);
}

FString FTbStructArrayStructWithArrayOfInts::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

bool FTbStructArrayMixedStruct::operator==(const FTbStructArrayMixedStruct& rhs) const
{
	return (id == rhs.id) && (name == rhs.name) && (origin == rhs.origin) && (points == rhs.points) && (flags == rhs.flags) && (scores == rhs.scores);
}

bool FTbStructArrayMixedStruct::operator!=(const FTbStructArrayMixedStruct& rhs) const
{
	return !operator==(rhs);
}

FTbStructArrayMixedStruct::operator FString() const
{
	return ToString();
}

FString FTbStructArrayMixedStruct::ToString() const
{
	return ToJSON(true);
}

FString FTbStructArrayMixedStruct::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}

/* Returns true if TbStructArrayPoint A is equal to TbStructArrayPoint B (A == B) */
bool UTbStructArrayLibrary::EqualEqual_TbStructArrayPointTbStructArrayPoint(FTbStructArrayPoint A, FTbStructArrayPoint B)
{
	return A == B;
}

/* Returns true if TbStructArrayPoint A is not equal to TbStructArrayPoint B (A != B) */
bool UTbStructArrayLibrary::NotEqual_TbStructArrayPointTbStructArrayPoint(FTbStructArrayPoint A, FTbStructArrayPoint B)
{
	return A != B;
}

FString UTbStructArrayLibrary::Conv_TbStructArrayPointToString(const FTbStructArrayPoint& InTbStructArrayPoint)
{
	return InTbStructArrayPoint.ToString();
}

FString UTbStructArrayLibrary::Conv_TbStructArrayPointToJSON(const FTbStructArrayPoint& InTbStructArrayPoint)
{
	return InTbStructArrayPoint.ToJSON();
}

/* Returns true if TbStructArrayStructWithArrayOfStructs A is equal to TbStructArrayStructWithArrayOfStructs B (A == B) */
bool UTbStructArrayLibrary::EqualEqual_TbStructArrayStructWithArrayOfStructsTbStructArrayStructWithArrayOfStructs(FTbStructArrayStructWithArrayOfStructs A, FTbStructArrayStructWithArrayOfStructs B)
{
	return A == B;
}

/* Returns true if TbStructArrayStructWithArrayOfStructs A is not equal to TbStructArrayStructWithArrayOfStructs B (A != B) */
bool UTbStructArrayLibrary::NotEqual_TbStructArrayStructWithArrayOfStructsTbStructArrayStructWithArrayOfStructs(FTbStructArrayStructWithArrayOfStructs A, FTbStructArrayStructWithArrayOfStructs B)
{
	return A != B;
}

FString UTbStructArrayLibrary::Conv_TbStructArrayStructWithArrayOfStructsToString(const FTbStructArrayStructWithArrayOfStructs& InTbStructArrayStructWithArrayOfStructs)
{
	return InTbStructArrayStructWithArrayOfStructs.ToString();
}

FString UTbStructArrayLibrary::Conv_TbStructArrayStructWithArrayOfStructsToJSON(const FTbStructArrayStructWithArrayOfStructs& InTbStructArrayStructWithArrayOfStructs)
{
	return InTbStructArrayStructWithArrayOfStructs.ToJSON();
}

/* Returns true if TbStructArrayStructWithArrayOfEnums A is equal to TbStructArrayStructWithArrayOfEnums B (A == B) */
bool UTbStructArrayLibrary::EqualEqual_TbStructArrayStructWithArrayOfEnumsTbStructArrayStructWithArrayOfEnums(FTbStructArrayStructWithArrayOfEnums A, FTbStructArrayStructWithArrayOfEnums B)
{
	return A == B;
}

/* Returns true if TbStructArrayStructWithArrayOfEnums A is not equal to TbStructArrayStructWithArrayOfEnums B (A != B) */
bool UTbStructArrayLibrary::NotEqual_TbStructArrayStructWithArrayOfEnumsTbStructArrayStructWithArrayOfEnums(FTbStructArrayStructWithArrayOfEnums A, FTbStructArrayStructWithArrayOfEnums B)
{
	return A != B;
}

FString UTbStructArrayLibrary::Conv_TbStructArrayStructWithArrayOfEnumsToString(const FTbStructArrayStructWithArrayOfEnums& InTbStructArrayStructWithArrayOfEnums)
{
	return InTbStructArrayStructWithArrayOfEnums.ToString();
}

FString UTbStructArrayLibrary::Conv_TbStructArrayStructWithArrayOfEnumsToJSON(const FTbStructArrayStructWithArrayOfEnums& InTbStructArrayStructWithArrayOfEnums)
{
	return InTbStructArrayStructWithArrayOfEnums.ToJSON();
}

/* Returns true if TbStructArrayStructWithArrayOfInts A is equal to TbStructArrayStructWithArrayOfInts B (A == B) */
bool UTbStructArrayLibrary::EqualEqual_TbStructArrayStructWithArrayOfIntsTbStructArrayStructWithArrayOfInts(FTbStructArrayStructWithArrayOfInts A, FTbStructArrayStructWithArrayOfInts B)
{
	return A == B;
}

/* Returns true if TbStructArrayStructWithArrayOfInts A is not equal to TbStructArrayStructWithArrayOfInts B (A != B) */
bool UTbStructArrayLibrary::NotEqual_TbStructArrayStructWithArrayOfIntsTbStructArrayStructWithArrayOfInts(FTbStructArrayStructWithArrayOfInts A, FTbStructArrayStructWithArrayOfInts B)
{
	return A != B;
}

FString UTbStructArrayLibrary::Conv_TbStructArrayStructWithArrayOfIntsToString(const FTbStructArrayStructWithArrayOfInts& InTbStructArrayStructWithArrayOfInts)
{
	return InTbStructArrayStructWithArrayOfInts.ToString();
}

FString UTbStructArrayLibrary::Conv_TbStructArrayStructWithArrayOfIntsToJSON(const FTbStructArrayStructWithArrayOfInts& InTbStructArrayStructWithArrayOfInts)
{
	return InTbStructArrayStructWithArrayOfInts.ToJSON();
}

/* Returns true if TbStructArrayMixedStruct A is equal to TbStructArrayMixedStruct B (A == B) */
bool UTbStructArrayLibrary::EqualEqual_TbStructArrayMixedStructTbStructArrayMixedStruct(FTbStructArrayMixedStruct A, FTbStructArrayMixedStruct B)
{
	return A == B;
}

/* Returns true if TbStructArrayMixedStruct A is not equal to TbStructArrayMixedStruct B (A != B) */
bool UTbStructArrayLibrary::NotEqual_TbStructArrayMixedStructTbStructArrayMixedStruct(FTbStructArrayMixedStruct A, FTbStructArrayMixedStruct B)
{
	return A != B;
}

FString UTbStructArrayLibrary::Conv_TbStructArrayMixedStructToString(const FTbStructArrayMixedStruct& InTbStructArrayMixedStruct)
{
	return InTbStructArrayMixedStruct.ToString();
}

FString UTbStructArrayLibrary::Conv_TbStructArrayMixedStructToJSON(const FTbStructArrayMixedStruct& InTbStructArrayMixedStruct)
{
	return InTbStructArrayMixedStruct.ToJSON();
}
