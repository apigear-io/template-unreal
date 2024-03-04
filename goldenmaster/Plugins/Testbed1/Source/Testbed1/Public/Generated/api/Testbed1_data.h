
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
#include "Testbed1_data.generated.h"

/**
 * Struct FTestbed1StructBool
 */
USTRUCT(BlueprintType)
struct TESTBED1_API FTestbed1StructBool : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed1")
	bool fieldBool{false};

	/**
	 * FTestbed1StructBool to JSON formatted FString
	 * @param bPrettyPrint Specify whether to use pretty print (e.g., with line endings) or condensed print.
	 * 
	 * @return JSON formatted FString
	 */
	FString ToJSON(bool bPrettyPrint = false) const;

	/** 
	 * FTestbed1StructBool to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed1StructBool to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 * 
	 * @return FString 
	 */
	explicit operator FString() const;

	bool operator==(const FTestbed1StructBool& rhs) const;
	bool operator!=(const FTestbed1StructBool& rhs) const;
};

/**
 * Struct FTestbed1StructInt
 */
USTRUCT(BlueprintType)
struct TESTBED1_API FTestbed1StructInt : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed1")
	int32 fieldInt{0};

	/**
	 * FTestbed1StructInt to JSON formatted FString
	 * @param bPrettyPrint Specify whether to use pretty print (e.g., with line endings) or condensed print.
	 * 
	 * @return JSON formatted FString
	 */
	FString ToJSON(bool bPrettyPrint = false) const;

	/** 
	 * FTestbed1StructInt to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed1StructInt to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 * 
	 * @return FString 
	 */
	explicit operator FString() const;

	bool operator==(const FTestbed1StructInt& rhs) const;
	bool operator!=(const FTestbed1StructInt& rhs) const;
};

/**
 * Struct FTestbed1StructFloat
 */
USTRUCT(BlueprintType)
struct TESTBED1_API FTestbed1StructFloat : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed1")
	float fieldFloat{0.0f};

	/**
	 * FTestbed1StructFloat to JSON formatted FString
	 * @param bPrettyPrint Specify whether to use pretty print (e.g., with line endings) or condensed print.
	 * 
	 * @return JSON formatted FString
	 */
	FString ToJSON(bool bPrettyPrint = false) const;

	/** 
	 * FTestbed1StructFloat to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed1StructFloat to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 * 
	 * @return FString 
	 */
	explicit operator FString() const;

	bool operator==(const FTestbed1StructFloat& rhs) const;
	bool operator!=(const FTestbed1StructFloat& rhs) const;
};

/**
 * Struct FTestbed1StructString
 */
USTRUCT(BlueprintType)
struct TESTBED1_API FTestbed1StructString : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed1")
	FString fieldString{FString()};

	/**
	 * FTestbed1StructString to JSON formatted FString
	 * @param bPrettyPrint Specify whether to use pretty print (e.g., with line endings) or condensed print.
	 * 
	 * @return JSON formatted FString
	 */
	FString ToJSON(bool bPrettyPrint = false) const;

	/** 
	 * FTestbed1StructString to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed1StructString to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 * 
	 * @return FString 
	 */
	explicit operator FString() const;

	bool operator==(const FTestbed1StructString& rhs) const;
	bool operator!=(const FTestbed1StructString& rhs) const;
};

/**
 * @brief BP Function library for data types
 */
UCLASS(meta = (BlueprintThreadSafe))
class TESTBED1_API UTestbed1Library : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/* Returns true if Testbed1StructBool A is equal to Testbed1StructBool B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed1StructBool)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed1")
	static bool EqualEqual_Testbed1StructBoolTestbed1StructBool(FTestbed1StructBool A, FTestbed1StructBool B);

	/* Returns true if Testbed1StructBool A is not equal to Testbed1StructBool B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed1StructBool)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed1")
	static bool NotEqual_Testbed1StructBoolTestbed1StructBool(FTestbed1StructBool A, FTestbed1StructBool B);

	/** Converts a Testbed1StructBool to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed1StructBool)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed1StructBoolToJSON(const FTestbed1StructBool& InTestbed1StructBool);

	/** Converts a Testbed1StructBool to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed1StructBool)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed1StructBoolToString(const FTestbed1StructBool& InTestbed1StructBool);

	/* Returns true if Testbed1StructInt A is equal to Testbed1StructInt B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed1StructInt)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed1")
	static bool EqualEqual_Testbed1StructIntTestbed1StructInt(FTestbed1StructInt A, FTestbed1StructInt B);

	/* Returns true if Testbed1StructInt A is not equal to Testbed1StructInt B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed1StructInt)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed1")
	static bool NotEqual_Testbed1StructIntTestbed1StructInt(FTestbed1StructInt A, FTestbed1StructInt B);

	/** Converts a Testbed1StructInt to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed1StructInt)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed1StructIntToJSON(const FTestbed1StructInt& InTestbed1StructInt);

	/** Converts a Testbed1StructInt to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed1StructInt)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed1StructIntToString(const FTestbed1StructInt& InTestbed1StructInt);

	/* Returns true if Testbed1StructFloat A is equal to Testbed1StructFloat B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed1StructFloat)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed1")
	static bool EqualEqual_Testbed1StructFloatTestbed1StructFloat(FTestbed1StructFloat A, FTestbed1StructFloat B);

	/* Returns true if Testbed1StructFloat A is not equal to Testbed1StructFloat B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed1StructFloat)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed1")
	static bool NotEqual_Testbed1StructFloatTestbed1StructFloat(FTestbed1StructFloat A, FTestbed1StructFloat B);

	/** Converts a Testbed1StructFloat to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed1StructFloat)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed1StructFloatToJSON(const FTestbed1StructFloat& InTestbed1StructFloat);

	/** Converts a Testbed1StructFloat to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed1StructFloat)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed1StructFloatToString(const FTestbed1StructFloat& InTestbed1StructFloat);

	/* Returns true if Testbed1StructString A is equal to Testbed1StructString B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed1StructString)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed1")
	static bool EqualEqual_Testbed1StructStringTestbed1StructString(FTestbed1StructString A, FTestbed1StructString B);

	/* Returns true if Testbed1StructString A is not equal to Testbed1StructString B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed1StructString)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed1")
	static bool NotEqual_Testbed1StructStringTestbed1StructString(FTestbed1StructString A, FTestbed1StructString B);

	/** Converts a Testbed1StructString to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed1StructString)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed1StructStringToJSON(const FTestbed1StructString& InTestbed1StructString);

	/** Converts a Testbed1StructString to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed1StructString)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed1StructStringToString(const FTestbed1StructString& InTestbed1StructString);
};
