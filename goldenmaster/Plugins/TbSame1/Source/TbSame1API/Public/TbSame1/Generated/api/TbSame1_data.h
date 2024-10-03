
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
#include "TbSame1_data.generated.h"

/**
 * Enumeration ETbSame1Enum1
 */
UENUM(BlueprintType)
enum class ETbSame1Enum1 : uint8
{
	TS1E1_VALUE1 = 1 UMETA(Displayname = "value1"),
	TS1E1_VALUE2 = 2 UMETA(Displayname = "value2"),
	UNSPECIFIED = 0 UMETA(Hidden)
};

/**
 * Enumeration ETbSame1Enum2
 */
UENUM(BlueprintType)
enum class ETbSame1Enum2 : uint8
{
	TS1E2_VALUE1 = 1 UMETA(Displayname = "value1"),
	TS1E2_VALUE2 = 2 UMETA(Displayname = "value2"),
	UNSPECIFIED = 0 UMETA(Hidden)
};

/**
 * Struct FTbSame1Struct1
 */
USTRUCT(BlueprintType)
struct TBSAME1API_API FTbSame1Struct1 : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|TbSame1")
	int32 field1{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|TbSame1")
	int32 field2{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|TbSame1")
	int32 field3{0};

	/**
	 * FTbSame1Struct1 to JSON formatted FString
	 * @param bPrettyPrint Specify whether to use pretty print (e.g., with line endings) or condensed print.
	 *
	 * @return JSON formatted FString
	 */
	FString ToJSON(bool bPrettyPrint = false) const;

	/**
	 * FTbSame1Struct1 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTbSame1Struct1 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 *
	 * @return FString
	 */
	explicit operator FString() const;

	bool operator==(const FTbSame1Struct1& rhs) const;
	bool operator!=(const FTbSame1Struct1& rhs) const;
};

/**
 * Struct FTbSame1Struct2
 */
USTRUCT(BlueprintType)
struct TBSAME1API_API FTbSame1Struct2 : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|TbSame1")
	int32 field1{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|TbSame1")
	int32 field2{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|TbSame1")
	int32 field3{0};

	/**
	 * FTbSame1Struct2 to JSON formatted FString
	 * @param bPrettyPrint Specify whether to use pretty print (e.g., with line endings) or condensed print.
	 *
	 * @return JSON formatted FString
	 */
	FString ToJSON(bool bPrettyPrint = false) const;

	/**
	 * FTbSame1Struct2 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTbSame1Struct2 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 *
	 * @return FString
	 */
	explicit operator FString() const;

	bool operator==(const FTbSame1Struct2& rhs) const;
	bool operator!=(const FTbSame1Struct2& rhs) const;
};

/**
 * @brief BP Function library for data types
 */
UCLASS(meta = (BlueprintThreadSafe))
class TBSAME1API_API UTbSame1Library : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/* Convert from uint8 to ETbSame1Enum1 @return true if successful */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1")
	static bool toTbSame1Enum1(ETbSame1Enum1& ConvertedEnum, UPARAM(DisplayName = "Value") uint8 InValue);

	/* Convert from uint8 to ETbSame1Enum2 @return true if successful */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1")
	static bool toTbSame1Enum2(ETbSame1Enum2& ConvertedEnum, UPARAM(DisplayName = "Value") uint8 InValue);

	/* Returns true if TbSame1Struct1 A is equal to TbSame1Struct1 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (TbSame1Struct1)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|TbSame1")
	static bool EqualEqual_TbSame1Struct1TbSame1Struct1(FTbSame1Struct1 A, FTbSame1Struct1 B);

	/* Returns true if TbSame1Struct1 A is not equal to TbSame1Struct1 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (TbSame1Struct1)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|TbSame1")
	static bool NotEqual_TbSame1Struct1TbSame1Struct1(FTbSame1Struct1 A, FTbSame1Struct1 B);

	/** Converts a TbSame1Struct1 to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (TbSame1Struct1)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_TbSame1Struct1ToJSON(UPARAM(DisplayName = "TbSame1Struct1") const FTbSame1Struct1& InTbSame1Struct1);

	/** Converts a TbSame1Struct1 to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (TbSame1Struct1)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_TbSame1Struct1ToString(UPARAM(DisplayName = "TbSame1Struct1") const FTbSame1Struct1& InTbSame1Struct1);

	/* Returns true if TbSame1Struct2 A is equal to TbSame1Struct2 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (TbSame1Struct2)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|TbSame1")
	static bool EqualEqual_TbSame1Struct2TbSame1Struct2(FTbSame1Struct2 A, FTbSame1Struct2 B);

	/* Returns true if TbSame1Struct2 A is not equal to TbSame1Struct2 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (TbSame1Struct2)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|TbSame1")
	static bool NotEqual_TbSame1Struct2TbSame1Struct2(FTbSame1Struct2 A, FTbSame1Struct2 B);

	/** Converts a TbSame1Struct2 to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (TbSame1Struct2)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_TbSame1Struct2ToJSON(UPARAM(DisplayName = "TbSame1Struct2") const FTbSame1Struct2& InTbSame1Struct2);

	/** Converts a TbSame1Struct2 to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (TbSame1Struct2)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_TbSame1Struct2ToString(UPARAM(DisplayName = "TbSame1Struct2") const FTbSame1Struct2& InTbSame1Struct2);
};
