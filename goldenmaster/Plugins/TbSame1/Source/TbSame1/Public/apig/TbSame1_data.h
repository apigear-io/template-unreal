
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
#include "TbSame1_data.generated.h"

/**
 * Enumeration ETbSame1Enum1
 */
UENUM(BlueprintType)
enum class ETbSame1Enum1 : uint8
{
    VALUE1  UMETA(Displayname = "value1"),
    VALUE2  UMETA(Displayname = "value2")
};

/**
 * Convert from uint8 to ETbSame1Enum1
 */
bool toUE4Type(ETbSame1Enum1& value, uint8 v);

/**
 * Enumeration ETbSame1Enum2
 */
UENUM(BlueprintType)
enum class ETbSame1Enum2 : uint8
{
    VALUE1  UMETA(Displayname = "value1"),
    VALUE2  UMETA(Displayname = "value2")
};

/**
 * Convert from uint8 to ETbSame1Enum2
 */
bool toUE4Type(ETbSame1Enum2& value, uint8 v);

/**
 * Struct FTbSame1Struct1
 */
USTRUCT(BlueprintType)
struct TBSAME1_API FTbSame1Struct1
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 field1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 field2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 field3;

	bool operator==(const FTbSame1Struct1& rhs) const;
	bool operator!=(const FTbSame1Struct1& rhs) const;
};

/**
 * Struct FTbSame1Struct2
 */
USTRUCT(BlueprintType)
struct TBSAME1_API FTbSame1Struct2
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 field1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 field2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 field3;

	bool operator==(const FTbSame1Struct2& rhs) const;
	bool operator!=(const FTbSame1Struct2& rhs) const;
};
