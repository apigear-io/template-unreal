
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
 * Enumeration EEnum1
 */
UENUM(BlueprintType)
enum class EEnum1 : uint8
{
    MEMBER1  UMETA(Displayname = "Member1"),
    MEMBER2  UMETA(Displayname = "Member2"),
    MEMBER3  UMETA(Displayname = "Member3"),
    MEMBER4  UMETA(Displayname = "Member4")
};

/**
 * Convert from uint8 to EEnum1
 */
bool toUE4Type(EEnum1& value, uint8 v);

/**
 * Enumeration EEnum2
 */
UENUM(BlueprintType)
enum class EEnum2 : uint8
{
    MEMBER1  UMETA(Displayname = "Member1"),
    MEMBER2  UMETA(Displayname = "Member2"),
    MEMBER3  UMETA(Displayname = "Member3"),
    MEMBER4  UMETA(Displayname = "Member4")
};

/**
 * Convert from uint8 to EEnum2
 */
bool toUE4Type(EEnum2& value, uint8 v);

/**
 * Struct FStruct1
 */
USTRUCT(BlueprintType)
struct ORGOBJECTAPITESTBED_API FStruct1
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

	bool operator==(const FStruct1& rhs) const;
	bool operator!=(const FStruct1& rhs) const;
};
