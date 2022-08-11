
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
#include "Testbed1_data.generated.h"

/**
 * Struct FTestbed1StructBool
 */
USTRUCT(BlueprintType)
struct TESTBED1_API FTestbed1StructBool
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool fieldBool;

	bool operator==(const FTestbed1StructBool& rhs) const;
	bool operator!=(const FTestbed1StructBool& rhs) const;
};

/**
 * Struct FTestbed1StructInt
 */
USTRUCT(BlueprintType)
struct TESTBED1_API FTestbed1StructInt
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 fieldInt;

	bool operator==(const FTestbed1StructInt& rhs) const;
	bool operator!=(const FTestbed1StructInt& rhs) const;
};

/**
 * Struct FTestbed1StructFloat
 */
USTRUCT(BlueprintType)
struct TESTBED1_API FTestbed1StructFloat
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float fieldFloat;

	bool operator==(const FTestbed1StructFloat& rhs) const;
	bool operator!=(const FTestbed1StructFloat& rhs) const;
};

/**
 * Struct FTestbed1StructString
 */
USTRUCT(BlueprintType)
struct TESTBED1_API FTestbed1StructString
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString fieldString;

	bool operator==(const FTestbed1StructString& rhs) const;
	bool operator!=(const FTestbed1StructString& rhs) const;
};
