
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
#include "Testbed2_data.generated.h"

/**
 * Enumeration ETestbed2Enum1
 */
UENUM(BlueprintType)
enum class ETestbed2Enum1 : uint8
{
	VALUE1 UMETA(Displayname = "value1"),
	VALUE2 UMETA(Displayname = "value2"),
	VALUE3 UMETA(Displayname = "value3"),
	VALUE4 UMETA(Displayname = "value4")
};

/**
 * Convert from uint8 to ETestbed2Enum1
 */
bool toUE4Type(ETestbed2Enum1& value, uint8 v);

/**
 * Enumeration ETestbed2Enum2
 */
UENUM(BlueprintType)
enum class ETestbed2Enum2 : uint8
{
	VALUE1 UMETA(Displayname = "value1"),
	VALUE2 UMETA(Displayname = "value2"),
	VALUE3 UMETA(Displayname = "value3"),
	VALUE4 UMETA(Displayname = "value4")
};

/**
 * Convert from uint8 to ETestbed2Enum2
 */
bool toUE4Type(ETestbed2Enum2& value, uint8 v);

/**
 * Enumeration ETestbed2Enum3
 */
UENUM(BlueprintType)
enum class ETestbed2Enum3 : uint8
{
	VALUE1 UMETA(Displayname = "value1"),
	VALUE2 UMETA(Displayname = "value2"),
	VALUE3 UMETA(Displayname = "value3"),
	VALUE4 UMETA(Displayname = "value4")
};

/**
 * Convert from uint8 to ETestbed2Enum3
 */
bool toUE4Type(ETestbed2Enum3& value, uint8 v);

/**
 * Struct FTestbed2Struct1
 */
USTRUCT(BlueprintType)
struct TESTBED2_API FTestbed2Struct1
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field1;

	bool operator==(const FTestbed2Struct1& rhs) const;
	bool operator!=(const FTestbed2Struct1& rhs) const;
};

/**
 * Struct FTestbed2Struct2
 */
USTRUCT(BlueprintType)
struct TESTBED2_API FTestbed2Struct2
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field2;

	bool operator==(const FTestbed2Struct2& rhs) const;
	bool operator!=(const FTestbed2Struct2& rhs) const;
};

/**
 * Struct FTestbed2Struct3
 */
USTRUCT(BlueprintType)
struct TESTBED2_API FTestbed2Struct3
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field3;

	bool operator==(const FTestbed2Struct3& rhs) const;
	bool operator!=(const FTestbed2Struct3& rhs) const;
};

/**
 * Struct FTestbed2Struct4
 */
USTRUCT(BlueprintType)
struct TESTBED2_API FTestbed2Struct4
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field4;

	bool operator==(const FTestbed2Struct4& rhs) const;
	bool operator!=(const FTestbed2Struct4& rhs) const;
};

/**
 * Struct FTestbed2NestedStruct1
 */
USTRUCT(BlueprintType)
struct TESTBED2_API FTestbed2NestedStruct1
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	FTestbed2Struct1 field1;

	bool operator==(const FTestbed2NestedStruct1& rhs) const;
	bool operator!=(const FTestbed2NestedStruct1& rhs) const;
};

/**
 * Struct FTestbed2NestedStruct2
 */
USTRUCT(BlueprintType)
struct TESTBED2_API FTestbed2NestedStruct2
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	FTestbed2Struct1 field1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	FTestbed2Struct2 field2;

	bool operator==(const FTestbed2NestedStruct2& rhs) const;
	bool operator!=(const FTestbed2NestedStruct2& rhs) const;
};

/**
 * Struct FTestbed2NestedStruct3
 */
USTRUCT(BlueprintType)
struct TESTBED2_API FTestbed2NestedStruct3
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	FTestbed2Struct1 field1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	FTestbed2Struct2 field2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	FTestbed2Struct3 field3;

	bool operator==(const FTestbed2NestedStruct3& rhs) const;
	bool operator!=(const FTestbed2NestedStruct3& rhs) const;
};
