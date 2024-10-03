
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
#include "Engine/DataTable.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TbEnum_data.generated.h"

/**
 * Enumeration ETbEnumEnum0
 */
UENUM(BlueprintType)
enum class ETbEnumEnum0 : uint8
{
	TEE0_VALUE0 = 0 UMETA(Displayname = "value0"),
	TEE0_VALUE1 = 1 UMETA(Displayname = "value1"),
	TEE0_VALUE2 = 2 UMETA(Displayname = "value2")
};

/**
 * Enumeration ETbEnumEnum1
 */
UENUM(BlueprintType)
enum class ETbEnumEnum1 : uint8
{
	TEE1_VALUE1 = 1 UMETA(Displayname = "value1"),
	TEE1_VALUE2 = 2 UMETA(Displayname = "value2"),
	TEE1_VALUE3 = 3 UMETA(Displayname = "value3"),
	UNSPECIFIED = 0 UMETA(Hidden)
};

/**
 * Enumeration ETbEnumEnum2
 */
UENUM(BlueprintType)
enum class ETbEnumEnum2 : uint8
{
	TEE2_VALUE2 = 2 UMETA(Displayname = "value2"),
	TEE2_VALUE1 = 1 UMETA(Displayname = "value1"),
	TEE2_VALUE0 = 0 UMETA(Displayname = "value0")
};

/**
 * Enumeration ETbEnumEnum3
 */
UENUM(BlueprintType)
enum class ETbEnumEnum3 : uint8
{
	TEE3_VALUE3 = 3 UMETA(Displayname = "value3"),
	TEE3_VALUE2 = 2 UMETA(Displayname = "value2"),
	TEE3_VALUE1 = 1 UMETA(Displayname = "value1"),
	UNSPECIFIED = 0 UMETA(Hidden)
};

/**
 * @brief BP Function library for data types
 */
UCLASS(meta = (BlueprintThreadSafe))
class TBENUMAPI_API UTbEnumLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/* Convert from uint8 to ETbEnumEnum0 @return true if successful */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum")
	static bool toTbEnumEnum0(ETbEnumEnum0& ConvertedEnum, UPARAM(DisplayName = "Value") uint8 InValue);

	/* Convert from uint8 to ETbEnumEnum1 @return true if successful */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum")
	static bool toTbEnumEnum1(ETbEnumEnum1& ConvertedEnum, UPARAM(DisplayName = "Value") uint8 InValue);

	/* Convert from uint8 to ETbEnumEnum2 @return true if successful */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum")
	static bool toTbEnumEnum2(ETbEnumEnum2& ConvertedEnum, UPARAM(DisplayName = "Value") uint8 InValue);

	/* Convert from uint8 to ETbEnumEnum3 @return true if successful */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum")
	static bool toTbEnumEnum3(ETbEnumEnum3& ConvertedEnum, UPARAM(DisplayName = "Value") uint8 InValue);
};
