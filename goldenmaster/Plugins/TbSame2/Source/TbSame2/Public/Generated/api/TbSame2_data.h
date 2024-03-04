
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
	TSE_VALUE1 = 1 UMETA(Displayname = "value1"),
	TSE_VALUE2 = 2 UMETA(Displayname = "value2"),
	UNSPECIFIED = 0 UMETA(Hidden)
};

/**
 * Enumeration ETbSame2Enum2
 */
UENUM(BlueprintType)
enum class ETbSame2Enum2 : uint8
{
	TSE_VALUE1 = 1 UMETA(Displayname = "value1"),
	TSE_VALUE2 = 2 UMETA(Displayname = "value2"),
	UNSPECIFIED = 0 UMETA(Hidden)
};

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

	/**
	 * FTbSame2Struct1 to JSON formatted FString
	 * @return JSON formatted FString
	 */
	FString ToJSON() const;

	/** 
	 * FTbSame2Struct1 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTbSame2Struct1 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 * 
	 * @return FString 
	 */
	explicit operator FString() const;

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

	/**
	 * FTbSame2Struct2 to JSON formatted FString
	 * @return JSON formatted FString
	 */
	FString ToJSON() const;

	/** 
	 * FTbSame2Struct2 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTbSame2Struct2 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 * 
	 * @return FString 
	 */
	explicit operator FString() const;

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

public:
	/* Convert from uint8 to ETbSame2Enum1 @return true if successful */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2")
	static bool toTbSame2Enum1(ETbSame2Enum1& ConvertedEnum, uint8 InValue);

	/* Convert from uint8 to ETbSame2Enum2 @return true if successful */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2")
	static bool toTbSame2Enum2(ETbSame2Enum2& ConvertedEnum, uint8 InValue);

	/* Returns true if TbSame2Struct1 A is equal to TbSame2Struct1 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (TbSame2Struct1)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|TbSame2")
	static bool EqualEqual_TbSame2Struct1TbSame2Struct1(FTbSame2Struct1 A, FTbSame2Struct1 B);

	/* Returns true if TbSame2Struct1 A is not equal to TbSame2Struct1 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (TbSame2Struct1)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|TbSame2")
	static bool NotEqual_TbSame2Struct1TbSame2Struct1(FTbSame2Struct1 A, FTbSame2Struct1 B);
	
	/** Converts a TbSame2Struct1 to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (TbSame2Struct1)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_TbSame2Struct1ToJSON(const FTbSame2Struct1& InTbSame2Struct1);

	/** Converts a TbSame2Struct1 to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (TbSame2Struct1)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_TbSame2Struct1ToString(const FTbSame2Struct1& InTbSame2Struct1);

	/* Returns true if TbSame2Struct2 A is equal to TbSame2Struct2 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (TbSame2Struct2)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|TbSame2")
	static bool EqualEqual_TbSame2Struct2TbSame2Struct2(FTbSame2Struct2 A, FTbSame2Struct2 B);

	/* Returns true if TbSame2Struct2 A is not equal to TbSame2Struct2 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (TbSame2Struct2)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|TbSame2")
	static bool NotEqual_TbSame2Struct2TbSame2Struct2(FTbSame2Struct2 A, FTbSame2Struct2 B);
	
	/** Converts a TbSame2Struct2 to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (TbSame2Struct2)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_TbSame2Struct2ToJSON(const FTbSame2Struct2& InTbSame2Struct2);

	/** Converts a TbSame2Struct2 to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (TbSame2Struct2)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_TbSame2Struct2ToString(const FTbSame2Struct2& InTbSame2Struct2);
};
