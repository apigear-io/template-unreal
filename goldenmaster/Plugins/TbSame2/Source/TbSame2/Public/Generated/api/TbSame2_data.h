
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
#include "TbSame2_data.generated.h"

/**
 * Enumeration ETbSame2Enum1
 */
UENUM(BlueprintType)
enum class ETbSame2Enum1 : uint8
{
	VALUE1 UMETA(Displayname = "value1"),
	VALUE2 UMETA(Displayname = "value2")
};

/**
 * Convert from uint8 to ETbSame2Enum1
 */
bool toUE4Type(ETbSame2Enum1& value, uint8 v);

/**
 * Enumeration ETbSame2Enum2
 */
UENUM(BlueprintType)
enum class ETbSame2Enum2 : uint8
{
	VALUE1 UMETA(Displayname = "value1"),
	VALUE2 UMETA(Displayname = "value2")
};

/**
 * Convert from uint8 to ETbSame2Enum2
 */
bool toUE4Type(ETbSame2Enum2& value, uint8 v);

/**
 * Struct FTbSame2Struct1
 */
USTRUCT(BlueprintType)
struct TBSAME2_API FTbSame2Struct1 : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|TbSame2")
	int32 field1{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|TbSame2")
	int32 field2{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|TbSame2")
	int32 field3{0};

	bool operator==(const FTbSame2Struct1& rhs) const;
	bool operator!=(const FTbSame2Struct1& rhs) const;
};

/**
 * Struct FTbSame2Struct2
 */
USTRUCT(BlueprintType)
struct TBSAME2_API FTbSame2Struct2 : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|TbSame2")
	int32 field1{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|TbSame2")
	int32 field2{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|TbSame2")
	int32 field3{0};

	bool operator==(const FTbSame2Struct2& rhs) const;
	bool operator!=(const FTbSame2Struct2& rhs) const;
};

/**
 * @brief BP Function library for data types
 */
UCLASS(meta = (BlueprintThreadSafe))
class TBSAME2_API UTbSame2Library : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	/* Returns true if TbSame2Struct1 A is equal to TbSame2Struct1 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (TbSame2Struct1)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|TbSame2")
	static bool EqualEqual_TbSame2Struct1TbSame2Struct1(FTbSame2Struct1 A, FTbSame2Struct1 B);

	/* Returns true if TbSame2Struct1 A is not equal to TbSame2Struct1 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (TbSame2Struct1)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|TbSame2")
	static bool NotEqual_TbSame2Struct1TbSame2Struct1(FTbSame2Struct1 A, FTbSame2Struct1 B);

	/* Returns true if TbSame2Struct2 A is equal to TbSame2Struct2 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (TbSame2Struct2)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|TbSame2")
	static bool EqualEqual_TbSame2Struct2TbSame2Struct2(FTbSame2Struct2 A, FTbSame2Struct2 B);

	/* Returns true if TbSame2Struct2 A is not equal to TbSame2Struct2 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (TbSame2Struct2)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|TbSame2")
	static bool NotEqual_TbSame2Struct2TbSame2Struct2(FTbSame2Struct2 A, FTbSame2Struct2 B);
};
