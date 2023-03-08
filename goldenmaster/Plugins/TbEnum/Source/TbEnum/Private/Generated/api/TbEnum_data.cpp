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

#include "TbEnum_data.h"
/**
 * Enumeration ETbEnumEnum0
 */
bool UTbEnumLibrary::toTbEnumEnum0(ETbEnumEnum0& ConvertedEnum, uint8 InValue)
{
	bool bSuccessful = false;
	switch (InValue)
	{
	case 0:
		ConvertedEnum = ETbEnumEnum0::TEE_VALUE0;
		bSuccessful = true;
		break;
	case 1:
		ConvertedEnum = ETbEnumEnum0::TEE_VALUE1;
		bSuccessful = true;
		break;
	case 2:
		ConvertedEnum = ETbEnumEnum0::TEE_VALUE2;
		bSuccessful = true;
		break;
	default:
		ConvertedEnum = ETbEnumEnum0::TEE_VALUE0;
	}
	return bSuccessful;
}
/**
 * Enumeration ETbEnumEnum1
 */
bool UTbEnumLibrary::toTbEnumEnum1(ETbEnumEnum1& ConvertedEnum, uint8 InValue)
{
	bool bSuccessful = false;
	switch (InValue)
	{
	case 1:
		ConvertedEnum = ETbEnumEnum1::TEE_VALUE1;
		bSuccessful = true;
		break;
	case 2:
		ConvertedEnum = ETbEnumEnum1::TEE_VALUE2;
		bSuccessful = true;
		break;
	case 3:
		ConvertedEnum = ETbEnumEnum1::TEE_VALUE3;
		bSuccessful = true;
		break;
	default:
		ConvertedEnum = ETbEnumEnum1::TEE_VALUE1;
	}
	return bSuccessful;
}
/**
 * Enumeration ETbEnumEnum2
 */
bool UTbEnumLibrary::toTbEnumEnum2(ETbEnumEnum2& ConvertedEnum, uint8 InValue)
{
	bool bSuccessful = false;
	switch (InValue)
	{
	case 2:
		ConvertedEnum = ETbEnumEnum2::TEE_VALUE2;
		bSuccessful = true;
		break;
	case 1:
		ConvertedEnum = ETbEnumEnum2::TEE_VALUE1;
		bSuccessful = true;
		break;
	case 0:
		ConvertedEnum = ETbEnumEnum2::TEE_VALUE0;
		bSuccessful = true;
		break;
	default:
		ConvertedEnum = ETbEnumEnum2::TEE_VALUE2;
	}
	return bSuccessful;
}
/**
 * Enumeration ETbEnumEnum3
 */
bool UTbEnumLibrary::toTbEnumEnum3(ETbEnumEnum3& ConvertedEnum, uint8 InValue)
{
	bool bSuccessful = false;
	switch (InValue)
	{
	case 3:
		ConvertedEnum = ETbEnumEnum3::TEE_VALUE3;
		bSuccessful = true;
		break;
	case 2:
		ConvertedEnum = ETbEnumEnum3::TEE_VALUE2;
		bSuccessful = true;
		break;
	case 1:
		ConvertedEnum = ETbEnumEnum3::TEE_VALUE1;
		bSuccessful = true;
		break;
	default:
		ConvertedEnum = ETbEnumEnum3::TEE_VALUE3;
	}
	return bSuccessful;
}
