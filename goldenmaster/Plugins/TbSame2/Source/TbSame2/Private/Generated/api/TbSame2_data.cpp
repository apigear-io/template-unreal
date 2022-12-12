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

#include "TbSame2_data.h"
/**
 * Enumeration ETbSame2Enum1
 */
bool toUE4Type(ETbSame2Enum1& value, uint8 v)
{
	bool bSuccessful = false;
	switch (v)
	{
	case 1:
		value = ETbSame2Enum1::VALUE1;
		bSuccessful = true;
		break;
	case 2:
		value = ETbSame2Enum1::VALUE2;
		bSuccessful = true;
		break;
	default:
		value = ETbSame2Enum1::VALUE1;
	}
	return bSuccessful;
}
/**
 * Enumeration ETbSame2Enum2
 */
bool toUE4Type(ETbSame2Enum2& value, uint8 v)
{
	bool bSuccessful = false;
	switch (v)
	{
	case 1:
		value = ETbSame2Enum2::VALUE1;
		bSuccessful = true;
		break;
	case 2:
		value = ETbSame2Enum2::VALUE2;
		bSuccessful = true;
		break;
	default:
		value = ETbSame2Enum2::VALUE1;
	}
	return bSuccessful;
}
bool FTbSame2Struct1::operator==(const FTbSame2Struct1& rhs) const
{
	return (field1 == rhs.field1) && (field2 == rhs.field2) && (field3 == rhs.field3);
}

bool FTbSame2Struct1::operator!=(const FTbSame2Struct1& rhs) const
{
	return !operator==(rhs);
}
bool FTbSame2Struct2::operator==(const FTbSame2Struct2& rhs) const
{
	return (field1 == rhs.field1) && (field2 == rhs.field2) && (field3 == rhs.field3);
}

bool FTbSame2Struct2::operator!=(const FTbSame2Struct2& rhs) const
{
	return !operator==(rhs);
}

/* Returns true if TbSame2Struct1 A is equal to TbSame2Struct1 B (A == B) */
bool UTbSame2Library::EqualEqual_TbSame2Struct1TbSame2Struct1(FTbSame2Struct1 A, FTbSame2Struct1 B)
{
	return A == B;
}

/* Returns true if TbSame2Struct1 A is not equal to TbSame2Struct1 B (A != B) */
bool UTbSame2Library::NotEqual_TbSame2Struct1TbSame2Struct1(FTbSame2Struct1 A, FTbSame2Struct1 B)
{
	return A != B;
}

/* Returns true if TbSame2Struct2 A is equal to TbSame2Struct2 B (A == B) */
bool UTbSame2Library::EqualEqual_TbSame2Struct2TbSame2Struct2(FTbSame2Struct2 A, FTbSame2Struct2 B)
{
	return A == B;
}

/* Returns true if TbSame2Struct2 A is not equal to TbSame2Struct2 B (A != B) */
bool UTbSame2Library::NotEqual_TbSame2Struct2TbSame2Struct2(FTbSame2Struct2 A, FTbSame2Struct2 B)
{
	return A != B;
}
