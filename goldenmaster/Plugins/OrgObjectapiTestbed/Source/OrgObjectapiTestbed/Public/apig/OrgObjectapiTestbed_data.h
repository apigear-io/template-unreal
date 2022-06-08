
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
#include "OrgObjectapiTestbed_data.generated.h"

/**
 * Enumeration EOrgObjectapiTestbedEnum1
 */
UENUM(BlueprintType)
enum class EOrgObjectapiTestbedEnum1 : uint8
{
    MEMBER1  UMETA(Displayname = "Member1"),
    MEMBER2  UMETA(Displayname = "Member2"),
    MEMBER3  UMETA(Displayname = "Member3"),
    MEMBER4  UMETA(Displayname = "Member4")
};

/**
 * Convert from uint8 to EOrgObjectapiTestbedEnum1
 */
bool toUE4Type(EOrgObjectapiTestbedEnum1& value, uint8 v);

/**
 * Enumeration EOrgObjectapiTestbedEnum2
 */
UENUM(BlueprintType)
enum class EOrgObjectapiTestbedEnum2 : uint8
{
    MEMBER1  UMETA(Displayname = "Member1"),
    MEMBER2  UMETA(Displayname = "Member2"),
    MEMBER3  UMETA(Displayname = "Member3"),
    MEMBER4  UMETA(Displayname = "Member4")
};

/**
 * Convert from uint8 to EOrgObjectapiTestbedEnum2
 */
bool toUE4Type(EOrgObjectapiTestbedEnum2& value, uint8 v);

/**
 * Struct FOrgObjectapiTestbedStruct1
 */
USTRUCT(BlueprintType)
struct ORGOBJECTAPITESTBED_API FOrgObjectapiTestbedStruct1
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool field1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 field2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float field3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString field4;

	bool operator==(const FOrgObjectapiTestbedStruct1& rhs) const;
	bool operator!=(const FOrgObjectapiTestbedStruct1& rhs) const;
};
