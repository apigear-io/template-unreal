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

#include "OrgObjectapiTestbed_data.h"
/**
 * Enumeration EEnum1
 */
bool toUE4Type(EEnum1& value, uint8 v)
{
    bool bSuccessful = false;
    switch (v) {
        case 0:
            value = EEnum1::MEMBER1;
            bSuccessful = true;
            break;
        case 1:
            value = EEnum1::MEMBER2;
            bSuccessful = true;
            break;
        case 2:
            value = EEnum1::MEMBER3;
            bSuccessful = true;
            break;
        case 3:
            value = EEnum1::MEMBER4;
            bSuccessful = true;
            break;
        default:
            value = EEnum1::MEMBER1;
    }
    return bSuccessful;
}
/**
 * Enumeration EEnum2
 */
bool toUE4Type(EEnum2& value, uint8 v)
{
    bool bSuccessful = false;
    switch (v) {
        case 0:
            value = EEnum2::MEMBER1;
            bSuccessful = true;
            break;
        case 1:
            value = EEnum2::MEMBER2;
            bSuccessful = true;
            break;
        case 2:
            value = EEnum2::MEMBER3;
            bSuccessful = true;
            break;
        case 3:
            value = EEnum2::MEMBER4;
            bSuccessful = true;
            break;
        default:
            value = EEnum2::MEMBER1;
    }
    return bSuccessful;
}
bool FStruct1::operator==(const FStruct1& rhs) const
{
	return(field1 == rhs.field1)&&(field2 == rhs.field2)&&(field3 == rhs.field3)&&(field4 == rhs.field4);
}

bool FStruct1::operator!=(const FStruct1& rhs) const
{
	return !operator==(rhs);
}