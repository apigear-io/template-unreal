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
bool toUE4Type(ETbEnumEnum0& value, uint8 v)
{
    bool bSuccessful = false;
    switch (v) {
        case 0:
            value = ETbEnumEnum0::VALUE0;
            bSuccessful = true;
            break;
        case 1:
            value = ETbEnumEnum0::VALUE1;
            bSuccessful = true;
            break;
        case 2:
            value = ETbEnumEnum0::VALUE2;
            bSuccessful = true;
            break;
        default:
            value = ETbEnumEnum0::VALUE0;
    }
    return bSuccessful;
}
/**
 * Enumeration ETbEnumEnum1
 */
bool toUE4Type(ETbEnumEnum1& value, uint8 v)
{
    bool bSuccessful = false;
    switch (v) {
        case 1:
            value = ETbEnumEnum1::VALUE1;
            bSuccessful = true;
            break;
        case 2:
            value = ETbEnumEnum1::VALUE2;
            bSuccessful = true;
            break;
        case 3:
            value = ETbEnumEnum1::VALUE3;
            bSuccessful = true;
            break;
        default:
            value = ETbEnumEnum1::VALUE1;
    }
    return bSuccessful;
}
/**
 * Enumeration ETbEnumEnum2
 */
bool toUE4Type(ETbEnumEnum2& value, uint8 v)
{
    bool bSuccessful = false;
    switch (v) {
        case 2:
            value = ETbEnumEnum2::VALUE2;
            bSuccessful = true;
            break;
        case 1:
            value = ETbEnumEnum2::VALUE1;
            bSuccessful = true;
            break;
        case 0:
            value = ETbEnumEnum2::VALUE0;
            bSuccessful = true;
            break;
        default:
            value = ETbEnumEnum2::VALUE2;
    }
    return bSuccessful;
}
/**
 * Enumeration ETbEnumEnum3
 */
bool toUE4Type(ETbEnumEnum3& value, uint8 v)
{
    bool bSuccessful = false;
    switch (v) {
        case 3:
            value = ETbEnumEnum3::VALUE3;
            bSuccessful = true;
            break;
        case 2:
            value = ETbEnumEnum3::VALUE2;
            bSuccessful = true;
            break;
        case 1:
            value = ETbEnumEnum3::VALUE1;
            bSuccessful = true;
            break;
        default:
            value = ETbEnumEnum3::VALUE3;
    }
    return bSuccessful;
}
