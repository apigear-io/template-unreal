
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
#pragma once

#include "CoreMinimal.h"
#include "TbEnum_data.generated.h"

/**
 * Enumeration ETbEnumEnum0
 */
UENUM(BlueprintType)
enum class ETbEnumEnum0 : uint8
{
    VALUE0  UMETA(Displayname = "value0"),
    VALUE1  UMETA(Displayname = "value1"),
    VALUE2  UMETA(Displayname = "value2")
};

/**
 * Convert from uint8 to ETbEnumEnum0
 */
bool toUE4Type(ETbEnumEnum0& value, uint8 v);

/**
 * Enumeration ETbEnumEnum1
 */
UENUM(BlueprintType)
enum class ETbEnumEnum1 : uint8
{
    VALUE1  UMETA(Displayname = "value1"),
    VALUE2  UMETA(Displayname = "value2"),
    VALUE3  UMETA(Displayname = "value3")
};

/**
 * Convert from uint8 to ETbEnumEnum1
 */
bool toUE4Type(ETbEnumEnum1& value, uint8 v);

/**
 * Enumeration ETbEnumEnum2
 */
UENUM(BlueprintType)
enum class ETbEnumEnum2 : uint8
{
    VALUE2  UMETA(Displayname = "value2"),
    VALUE1  UMETA(Displayname = "value1"),
    VALUE0  UMETA(Displayname = "value0")
};

/**
 * Convert from uint8 to ETbEnumEnum2
 */
bool toUE4Type(ETbEnumEnum2& value, uint8 v);

/**
 * Enumeration ETbEnumEnum3
 */
UENUM(BlueprintType)
enum class ETbEnumEnum3 : uint8
{
    VALUE3  UMETA(Displayname = "value3"),
    VALUE2  UMETA(Displayname = "value2"),
    VALUE1  UMETA(Displayname = "value1")
};

/**
 * Convert from uint8 to ETbEnumEnum3
 */
bool toUE4Type(ETbEnumEnum3& value, uint8 v);
