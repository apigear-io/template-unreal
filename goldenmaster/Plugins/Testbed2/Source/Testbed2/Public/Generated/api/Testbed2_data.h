
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
#include "Testbed2_data.generated.h"

/**
 * Enumeration ETestbed2Enum1
 */
UENUM(BlueprintType)
enum class ETestbed2Enum1 : uint8
{
	TE_VALUE1 = 1 UMETA(Displayname = "value1"),
	TE_VALUE2 = 2 UMETA(Displayname = "value2"),
	TE_VALUE3 = 3 UMETA(Displayname = "value3"),
	TE_VALUE4 = 4 UMETA(Displayname = "value4"),
	UNSPECIFIED = 0 UMETA(Hidden)
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
	TE_VALUE1 = 1 UMETA(Displayname = "value1"),
	TE_VALUE2 = 2 UMETA(Displayname = "value2"),
	TE_VALUE3 = 3 UMETA(Displayname = "value3"),
	TE_VALUE4 = 4 UMETA(Displayname = "value4"),
	UNSPECIFIED = 0 UMETA(Hidden)
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
	TE_VALUE1 = 1 UMETA(Displayname = "value1"),
	TE_VALUE2 = 2 UMETA(Displayname = "value2"),
	TE_VALUE3 = 3 UMETA(Displayname = "value3"),
	TE_VALUE4 = 4 UMETA(Displayname = "value4"),
	UNSPECIFIED = 0 UMETA(Hidden)
};

/**
 * Convert from uint8 to ETestbed2Enum3
 */
bool toUE4Type(ETestbed2Enum3& value, uint8 v);

/**
 * Struct FTestbed2Struct1
 */
USTRUCT(BlueprintType)
struct TESTBED2_API FTestbed2Struct1 : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 field1{0};

	bool operator==(const FTestbed2Struct1& rhs) const;
	bool operator!=(const FTestbed2Struct1& rhs) const;
};

/**
 * Struct FTestbed2Struct2
 */
USTRUCT(BlueprintType)
struct TESTBED2_API FTestbed2Struct2 : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 field1{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 field2{0};

	bool operator==(const FTestbed2Struct2& rhs) const;
	bool operator!=(const FTestbed2Struct2& rhs) const;
};

/**
 * Struct FTestbed2Struct3
 */
USTRUCT(BlueprintType)
struct TESTBED2_API FTestbed2Struct3 : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 field1{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 field2{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 field3{0};

	bool operator==(const FTestbed2Struct3& rhs) const;
	bool operator!=(const FTestbed2Struct3& rhs) const;
};

/**
 * Struct FTestbed2Struct4
 */
USTRUCT(BlueprintType)
struct TESTBED2_API FTestbed2Struct4 : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 field1{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 field2{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 field3{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 field4{0};

	bool operator==(const FTestbed2Struct4& rhs) const;
	bool operator!=(const FTestbed2Struct4& rhs) const;
};

/**
 * Struct FTestbed2NestedStruct1
 */
USTRUCT(BlueprintType)
struct TESTBED2_API FTestbed2NestedStruct1 : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTestbed2Struct1 field1{FTestbed2Struct1()};

	bool operator==(const FTestbed2NestedStruct1& rhs) const;
	bool operator!=(const FTestbed2NestedStruct1& rhs) const;
};

/**
 * Struct FTestbed2NestedStruct2
 */
USTRUCT(BlueprintType)
struct TESTBED2_API FTestbed2NestedStruct2 : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTestbed2Struct1 field1{FTestbed2Struct1()};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTestbed2Struct2 field2{FTestbed2Struct2()};

	bool operator==(const FTestbed2NestedStruct2& rhs) const;
	bool operator!=(const FTestbed2NestedStruct2& rhs) const;
};

/**
 * Struct FTestbed2NestedStruct3
 */
USTRUCT(BlueprintType)
struct TESTBED2_API FTestbed2NestedStruct3 : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTestbed2Struct1 field1{FTestbed2Struct1()};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTestbed2Struct2 field2{FTestbed2Struct2()};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTestbed2Struct3 field3{FTestbed2Struct3()};

	bool operator==(const FTestbed2NestedStruct3& rhs) const;
	bool operator!=(const FTestbed2NestedStruct3& rhs) const;
};

/**
 * @brief BP Function library for data types
 */
UCLASS(meta = (BlueprintThreadSafe))
class TESTBED2_API UTestbed2Library : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	/* Returns true if Testbed2Struct1 A is equal to Testbed2Struct1 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed2Struct1)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed2")
	static bool EqualEqual_Testbed2Struct1Testbed2Struct1(FTestbed2Struct1 A, FTestbed2Struct1 B);

	/* Returns true if Testbed2Struct1 A is not equal to Testbed2Struct1 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed2Struct1)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed2")
	static bool NotEqual_Testbed2Struct1Testbed2Struct1(FTestbed2Struct1 A, FTestbed2Struct1 B);

	/* Returns true if Testbed2Struct2 A is equal to Testbed2Struct2 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed2Struct2)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed2")
	static bool EqualEqual_Testbed2Struct2Testbed2Struct2(FTestbed2Struct2 A, FTestbed2Struct2 B);

	/* Returns true if Testbed2Struct2 A is not equal to Testbed2Struct2 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed2Struct2)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed2")
	static bool NotEqual_Testbed2Struct2Testbed2Struct2(FTestbed2Struct2 A, FTestbed2Struct2 B);

	/* Returns true if Testbed2Struct3 A is equal to Testbed2Struct3 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed2Struct3)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed2")
	static bool EqualEqual_Testbed2Struct3Testbed2Struct3(FTestbed2Struct3 A, FTestbed2Struct3 B);

	/* Returns true if Testbed2Struct3 A is not equal to Testbed2Struct3 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed2Struct3)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed2")
	static bool NotEqual_Testbed2Struct3Testbed2Struct3(FTestbed2Struct3 A, FTestbed2Struct3 B);

	/* Returns true if Testbed2Struct4 A is equal to Testbed2Struct4 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed2Struct4)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed2")
	static bool EqualEqual_Testbed2Struct4Testbed2Struct4(FTestbed2Struct4 A, FTestbed2Struct4 B);

	/* Returns true if Testbed2Struct4 A is not equal to Testbed2Struct4 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed2Struct4)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed2")
	static bool NotEqual_Testbed2Struct4Testbed2Struct4(FTestbed2Struct4 A, FTestbed2Struct4 B);

	/* Returns true if Testbed2NestedStruct1 A is equal to Testbed2NestedStruct1 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed2NestedStruct1)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed2")
	static bool EqualEqual_Testbed2NestedStruct1Testbed2NestedStruct1(FTestbed2NestedStruct1 A, FTestbed2NestedStruct1 B);

	/* Returns true if Testbed2NestedStruct1 A is not equal to Testbed2NestedStruct1 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed2NestedStruct1)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed2")
	static bool NotEqual_Testbed2NestedStruct1Testbed2NestedStruct1(FTestbed2NestedStruct1 A, FTestbed2NestedStruct1 B);

	/* Returns true if Testbed2NestedStruct2 A is equal to Testbed2NestedStruct2 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed2NestedStruct2)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed2")
	static bool EqualEqual_Testbed2NestedStruct2Testbed2NestedStruct2(FTestbed2NestedStruct2 A, FTestbed2NestedStruct2 B);

	/* Returns true if Testbed2NestedStruct2 A is not equal to Testbed2NestedStruct2 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed2NestedStruct2)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed2")
	static bool NotEqual_Testbed2NestedStruct2Testbed2NestedStruct2(FTestbed2NestedStruct2 A, FTestbed2NestedStruct2 B);

	/* Returns true if Testbed2NestedStruct3 A is equal to Testbed2NestedStruct3 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed2NestedStruct3)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed2")
	static bool EqualEqual_Testbed2NestedStruct3Testbed2NestedStruct3(FTestbed2NestedStruct3 A, FTestbed2NestedStruct3 B);

	/* Returns true if Testbed2NestedStruct3 A is not equal to Testbed2NestedStruct3 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed2NestedStruct3)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed2")
	static bool NotEqual_Testbed2NestedStruct3Testbed2NestedStruct3(FTestbed2NestedStruct3 A, FTestbed2NestedStruct3 B);
};
