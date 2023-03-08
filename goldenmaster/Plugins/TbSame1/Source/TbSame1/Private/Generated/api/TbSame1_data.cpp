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

#include "TbSame1_data.h"
/**
 * Enumeration ETbSame1Enum1
 */
bool UTbSame1Library::toTbSame1Enum1(ETbSame1Enum1& ConvertedEnum, uint8 InValue)
{
	bool bSuccessful = false;
	switch (InValue)
	{
	case 1:
		ConvertedEnum = ETbSame1Enum1::TSE_VALUE1;
		bSuccessful = true;
		break;
	case 2:
		ConvertedEnum = ETbSame1Enum1::TSE_VALUE2;
		bSuccessful = true;
		break;
	default:
		ConvertedEnum = ETbSame1Enum1::TSE_VALUE1;
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
		ConvertedEnum = ETbSame1Enum2::TSE_VALUE1;
		bSuccessful = true;
		break;
	case 2:
		ConvertedEnum = ETbSame1Enum2::TSE_VALUE2;
		bSuccessful = true;
		break;
	default:
		ConvertedEnum = ETbSame1Enum2::TSE_VALUE1;
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
bool FTbSame1Struct2::operator==(const FTbSame1Struct2& rhs) const
{
	return (field1 == rhs.field1) && (field2 == rhs.field2) && (field3 == rhs.field3);
}

bool FTbSame1Struct2::operator!=(const FTbSame1Struct2& rhs) const
{
	return !operator==(rhs);
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
