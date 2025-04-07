
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
 * Enumeration ETestbed1Enum0
 */
UENUM(BlueprintType)
enum class ETestbed1Enum0 : uint8
{
	T1E0_VALUE0 = 0 UMETA(Displayname = "value0"),
	T1E0_VALUE1 = 1 UMETA(Displayname = "value1"),
	T1E0_VALUE2 = 2 UMETA(Displayname = "value2")
};

/**
 * Struct FTestbed1StructBool
 */
USTRUCT(BlueprintType)
struct TESTBED1API_API FTestbed1StructBool : public FTableRowBase
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
struct TESTBED1API_API FTestbed1StructInt : public FTableRowBase
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
struct TESTBED1API_API FTestbed1StructFloat : public FTableRowBase
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
struct TESTBED1API_API FTestbed1StructString : public FTableRowBase
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
 * Struct FTestbed1StructStruct
 */
USTRUCT(BlueprintType)
struct TESTBED1API_API FTestbed1StructStruct : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed1")
	FTestbed1StructString fieldString{FTestbed1StructString()};

	/**
	 * FTestbed1StructStruct to JSON formatted FString
	 * @param bPrettyPrint Specify whether to use pretty print (e.g., with line endings) or condensed print.
	 *
	 * @return JSON formatted FString
	 */
	FString ToJSON(bool bPrettyPrint = false) const;

	/**
	 * FTestbed1StructStruct to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed1StructStruct to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 *
	 * @return FString
	 */
	explicit operator FString() const;

	bool operator==(const FTestbed1StructStruct& rhs) const;
	bool operator!=(const FTestbed1StructStruct& rhs) const;
};

/**
 * Struct FTestbed1StructEnum
 */
USTRUCT(BlueprintType)
struct TESTBED1API_API FTestbed1StructEnum : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed1")
	ETestbed1Enum0 fieldEnum{ETestbed1Enum0::T1E0_VALUE0};

	/**
	 * FTestbed1StructEnum to JSON formatted FString
	 * @param bPrettyPrint Specify whether to use pretty print (e.g., with line endings) or condensed print.
	 *
	 * @return JSON formatted FString
	 */
	FString ToJSON(bool bPrettyPrint = false) const;

	/**
	 * FTestbed1StructEnum to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed1StructEnum to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 *
	 * @return FString
	 */
	explicit operator FString() const;

	bool operator==(const FTestbed1StructEnum& rhs) const;
	bool operator!=(const FTestbed1StructEnum& rhs) const;
};

/**
 * Struct FTestbed1StructBoolWithArray
 */
USTRUCT(BlueprintType)
struct TESTBED1API_API FTestbed1StructBoolWithArray : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed1")
	TArray<bool> fieldBool{TArray<bool>()};

	/**
	 * FTestbed1StructBoolWithArray to JSON formatted FString
	 * @param bPrettyPrint Specify whether to use pretty print (e.g., with line endings) or condensed print.
	 *
	 * @return JSON formatted FString
	 */
	FString ToJSON(bool bPrettyPrint = false) const;

	/**
	 * FTestbed1StructBoolWithArray to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed1StructBoolWithArray to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 *
	 * @return FString
	 */
	explicit operator FString() const;

	bool operator==(const FTestbed1StructBoolWithArray& rhs) const;
	bool operator!=(const FTestbed1StructBoolWithArray& rhs) const;
};

/**
 * Struct FTestbed1StructIntWithArray
 */
USTRUCT(BlueprintType)
struct TESTBED1API_API FTestbed1StructIntWithArray : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed1")
	TArray<int32> fieldInt{TArray<int32>()};

	/**
	 * FTestbed1StructIntWithArray to JSON formatted FString
	 * @param bPrettyPrint Specify whether to use pretty print (e.g., with line endings) or condensed print.
	 *
	 * @return JSON formatted FString
	 */
	FString ToJSON(bool bPrettyPrint = false) const;

	/**
	 * FTestbed1StructIntWithArray to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed1StructIntWithArray to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 *
	 * @return FString
	 */
	explicit operator FString() const;

	bool operator==(const FTestbed1StructIntWithArray& rhs) const;
	bool operator!=(const FTestbed1StructIntWithArray& rhs) const;
};

/**
 * Struct FTestbed1StructFloatWithArray
 */
USTRUCT(BlueprintType)
struct TESTBED1API_API FTestbed1StructFloatWithArray : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed1")
	TArray<float> fieldFloat{TArray<float>()};

	/**
	 * FTestbed1StructFloatWithArray to JSON formatted FString
	 * @param bPrettyPrint Specify whether to use pretty print (e.g., with line endings) or condensed print.
	 *
	 * @return JSON formatted FString
	 */
	FString ToJSON(bool bPrettyPrint = false) const;

	/**
	 * FTestbed1StructFloatWithArray to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed1StructFloatWithArray to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 *
	 * @return FString
	 */
	explicit operator FString() const;

	bool operator==(const FTestbed1StructFloatWithArray& rhs) const;
	bool operator!=(const FTestbed1StructFloatWithArray& rhs) const;
};

/**
 * Struct FTestbed1StructStringWithArray
 */
USTRUCT(BlueprintType)
struct TESTBED1API_API FTestbed1StructStringWithArray : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed1")
	TArray<FString> fieldString{TArray<FString>()};

	/**
	 * FTestbed1StructStringWithArray to JSON formatted FString
	 * @param bPrettyPrint Specify whether to use pretty print (e.g., with line endings) or condensed print.
	 *
	 * @return JSON formatted FString
	 */
	FString ToJSON(bool bPrettyPrint = false) const;

	/**
	 * FTestbed1StructStringWithArray to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed1StructStringWithArray to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 *
	 * @return FString
	 */
	explicit operator FString() const;

	bool operator==(const FTestbed1StructStringWithArray& rhs) const;
	bool operator!=(const FTestbed1StructStringWithArray& rhs) const;
};

/**
 * Struct FTestbed1StructStructWithArray
 */
USTRUCT(BlueprintType)
struct TESTBED1API_API FTestbed1StructStructWithArray : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed1")
	TArray<FTestbed1StructStringWithArray> fieldStruct{TArray<FTestbed1StructStringWithArray>()};

	/**
	 * FTestbed1StructStructWithArray to JSON formatted FString
	 * @param bPrettyPrint Specify whether to use pretty print (e.g., with line endings) or condensed print.
	 *
	 * @return JSON formatted FString
	 */
	FString ToJSON(bool bPrettyPrint = false) const;

	/**
	 * FTestbed1StructStructWithArray to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed1StructStructWithArray to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 *
	 * @return FString
	 */
	explicit operator FString() const;

	bool operator==(const FTestbed1StructStructWithArray& rhs) const;
	bool operator!=(const FTestbed1StructStructWithArray& rhs) const;
};

/**
 * Struct FTestbed1StructEnumWithArray
 */
USTRUCT(BlueprintType)
struct TESTBED1API_API FTestbed1StructEnumWithArray : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed1")
	TArray<ETestbed1Enum0> fieldEnum{TArray<ETestbed1Enum0>()};

	/**
	 * FTestbed1StructEnumWithArray to JSON formatted FString
	 * @param bPrettyPrint Specify whether to use pretty print (e.g., with line endings) or condensed print.
	 *
	 * @return JSON formatted FString
	 */
	FString ToJSON(bool bPrettyPrint = false) const;

	/**
	 * FTestbed1StructEnumWithArray to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed1StructEnumWithArray to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 *
	 * @return FString
	 */
	explicit operator FString() const;

	bool operator==(const FTestbed1StructEnumWithArray& rhs) const;
	bool operator!=(const FTestbed1StructEnumWithArray& rhs) const;
};

/**
 * @brief BP Function library for data types
 */
UCLASS(meta = (BlueprintThreadSafe))
class TESTBED1API_API UTestbed1Library : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/* Convert from uint8 to ETestbed1Enum0 @return true if successful */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1")
	static bool toTestbed1Enum0(ETestbed1Enum0& ConvertedEnum, UPARAM(DisplayName = "Value") uint8 InValue);

	/* Returns true if Testbed1StructBool A is equal to Testbed1StructBool B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed1StructBool)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed1")
	static bool EqualEqual_Testbed1StructBoolTestbed1StructBool(FTestbed1StructBool A, FTestbed1StructBool B);

	/* Returns true if Testbed1StructBool A is not equal to Testbed1StructBool B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed1StructBool)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed1")
	static bool NotEqual_Testbed1StructBoolTestbed1StructBool(FTestbed1StructBool A, FTestbed1StructBool B);

	/** Converts a Testbed1StructBool to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed1StructBool)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed1StructBoolToJSON(UPARAM(DisplayName = "Testbed1StructBool") const FTestbed1StructBool& InTestbed1StructBool);

	/** Converts a Testbed1StructBool to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed1StructBool)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed1StructBoolToString(UPARAM(DisplayName = "Testbed1StructBool") const FTestbed1StructBool& InTestbed1StructBool);

	/* Returns true if Testbed1StructInt A is equal to Testbed1StructInt B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed1StructInt)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed1")
	static bool EqualEqual_Testbed1StructIntTestbed1StructInt(FTestbed1StructInt A, FTestbed1StructInt B);

	/* Returns true if Testbed1StructInt A is not equal to Testbed1StructInt B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed1StructInt)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed1")
	static bool NotEqual_Testbed1StructIntTestbed1StructInt(FTestbed1StructInt A, FTestbed1StructInt B);

	/** Converts a Testbed1StructInt to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed1StructInt)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed1StructIntToJSON(UPARAM(DisplayName = "Testbed1StructInt") const FTestbed1StructInt& InTestbed1StructInt);

	/** Converts a Testbed1StructInt to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed1StructInt)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed1StructIntToString(UPARAM(DisplayName = "Testbed1StructInt") const FTestbed1StructInt& InTestbed1StructInt);

	/* Returns true if Testbed1StructFloat A is equal to Testbed1StructFloat B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed1StructFloat)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed1")
	static bool EqualEqual_Testbed1StructFloatTestbed1StructFloat(FTestbed1StructFloat A, FTestbed1StructFloat B);

	/* Returns true if Testbed1StructFloat A is not equal to Testbed1StructFloat B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed1StructFloat)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed1")
	static bool NotEqual_Testbed1StructFloatTestbed1StructFloat(FTestbed1StructFloat A, FTestbed1StructFloat B);

	/** Converts a Testbed1StructFloat to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed1StructFloat)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed1StructFloatToJSON(UPARAM(DisplayName = "Testbed1StructFloat") const FTestbed1StructFloat& InTestbed1StructFloat);

	/** Converts a Testbed1StructFloat to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed1StructFloat)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed1StructFloatToString(UPARAM(DisplayName = "Testbed1StructFloat") const FTestbed1StructFloat& InTestbed1StructFloat);

	/* Returns true if Testbed1StructString A is equal to Testbed1StructString B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed1StructString)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed1")
	static bool EqualEqual_Testbed1StructStringTestbed1StructString(FTestbed1StructString A, FTestbed1StructString B);

	/* Returns true if Testbed1StructString A is not equal to Testbed1StructString B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed1StructString)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed1")
	static bool NotEqual_Testbed1StructStringTestbed1StructString(FTestbed1StructString A, FTestbed1StructString B);

	/** Converts a Testbed1StructString to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed1StructString)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed1StructStringToJSON(UPARAM(DisplayName = "Testbed1StructString") const FTestbed1StructString& InTestbed1StructString);

	/** Converts a Testbed1StructString to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed1StructString)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed1StructStringToString(UPARAM(DisplayName = "Testbed1StructString") const FTestbed1StructString& InTestbed1StructString);

	/* Returns true if Testbed1StructStruct A is equal to Testbed1StructStruct B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed1StructStruct)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed1")
	static bool EqualEqual_Testbed1StructStructTestbed1StructStruct(FTestbed1StructStruct A, FTestbed1StructStruct B);

	/* Returns true if Testbed1StructStruct A is not equal to Testbed1StructStruct B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed1StructStruct)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed1")
	static bool NotEqual_Testbed1StructStructTestbed1StructStruct(FTestbed1StructStruct A, FTestbed1StructStruct B);

	/** Converts a Testbed1StructStruct to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed1StructStruct)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed1StructStructToJSON(UPARAM(DisplayName = "Testbed1StructStruct") const FTestbed1StructStruct& InTestbed1StructStruct);

	/** Converts a Testbed1StructStruct to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed1StructStruct)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed1StructStructToString(UPARAM(DisplayName = "Testbed1StructStruct") const FTestbed1StructStruct& InTestbed1StructStruct);

	/* Returns true if Testbed1StructEnum A is equal to Testbed1StructEnum B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed1StructEnum)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed1")
	static bool EqualEqual_Testbed1StructEnumTestbed1StructEnum(FTestbed1StructEnum A, FTestbed1StructEnum B);

	/* Returns true if Testbed1StructEnum A is not equal to Testbed1StructEnum B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed1StructEnum)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed1")
	static bool NotEqual_Testbed1StructEnumTestbed1StructEnum(FTestbed1StructEnum A, FTestbed1StructEnum B);

	/** Converts a Testbed1StructEnum to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed1StructEnum)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed1StructEnumToJSON(UPARAM(DisplayName = "Testbed1StructEnum") const FTestbed1StructEnum& InTestbed1StructEnum);

	/** Converts a Testbed1StructEnum to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed1StructEnum)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed1StructEnumToString(UPARAM(DisplayName = "Testbed1StructEnum") const FTestbed1StructEnum& InTestbed1StructEnum);

	/* Returns true if Testbed1StructBoolWithArray A is equal to Testbed1StructBoolWithArray B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed1StructBoolWithArray)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed1")
	static bool EqualEqual_Testbed1StructBoolWithArrayTestbed1StructBoolWithArray(FTestbed1StructBoolWithArray A, FTestbed1StructBoolWithArray B);

	/* Returns true if Testbed1StructBoolWithArray A is not equal to Testbed1StructBoolWithArray B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed1StructBoolWithArray)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed1")
	static bool NotEqual_Testbed1StructBoolWithArrayTestbed1StructBoolWithArray(FTestbed1StructBoolWithArray A, FTestbed1StructBoolWithArray B);

	/** Converts a Testbed1StructBoolWithArray to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed1StructBoolWithArray)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed1StructBoolWithArrayToJSON(UPARAM(DisplayName = "Testbed1StructBoolWithArray") const FTestbed1StructBoolWithArray& InTestbed1StructBoolWithArray);

	/** Converts a Testbed1StructBoolWithArray to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed1StructBoolWithArray)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed1StructBoolWithArrayToString(UPARAM(DisplayName = "Testbed1StructBoolWithArray") const FTestbed1StructBoolWithArray& InTestbed1StructBoolWithArray);

	/* Returns true if Testbed1StructIntWithArray A is equal to Testbed1StructIntWithArray B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed1StructIntWithArray)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed1")
	static bool EqualEqual_Testbed1StructIntWithArrayTestbed1StructIntWithArray(FTestbed1StructIntWithArray A, FTestbed1StructIntWithArray B);

	/* Returns true if Testbed1StructIntWithArray A is not equal to Testbed1StructIntWithArray B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed1StructIntWithArray)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed1")
	static bool NotEqual_Testbed1StructIntWithArrayTestbed1StructIntWithArray(FTestbed1StructIntWithArray A, FTestbed1StructIntWithArray B);

	/** Converts a Testbed1StructIntWithArray to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed1StructIntWithArray)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed1StructIntWithArrayToJSON(UPARAM(DisplayName = "Testbed1StructIntWithArray") const FTestbed1StructIntWithArray& InTestbed1StructIntWithArray);

	/** Converts a Testbed1StructIntWithArray to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed1StructIntWithArray)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed1StructIntWithArrayToString(UPARAM(DisplayName = "Testbed1StructIntWithArray") const FTestbed1StructIntWithArray& InTestbed1StructIntWithArray);

	/* Returns true if Testbed1StructFloatWithArray A is equal to Testbed1StructFloatWithArray B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed1StructFloatWithArray)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed1")
	static bool EqualEqual_Testbed1StructFloatWithArrayTestbed1StructFloatWithArray(FTestbed1StructFloatWithArray A, FTestbed1StructFloatWithArray B);

	/* Returns true if Testbed1StructFloatWithArray A is not equal to Testbed1StructFloatWithArray B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed1StructFloatWithArray)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed1")
	static bool NotEqual_Testbed1StructFloatWithArrayTestbed1StructFloatWithArray(FTestbed1StructFloatWithArray A, FTestbed1StructFloatWithArray B);

	/** Converts a Testbed1StructFloatWithArray to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed1StructFloatWithArray)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed1StructFloatWithArrayToJSON(UPARAM(DisplayName = "Testbed1StructFloatWithArray") const FTestbed1StructFloatWithArray& InTestbed1StructFloatWithArray);

	/** Converts a Testbed1StructFloatWithArray to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed1StructFloatWithArray)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed1StructFloatWithArrayToString(UPARAM(DisplayName = "Testbed1StructFloatWithArray") const FTestbed1StructFloatWithArray& InTestbed1StructFloatWithArray);

	/* Returns true if Testbed1StructStringWithArray A is equal to Testbed1StructStringWithArray B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed1StructStringWithArray)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed1")
	static bool EqualEqual_Testbed1StructStringWithArrayTestbed1StructStringWithArray(FTestbed1StructStringWithArray A, FTestbed1StructStringWithArray B);

	/* Returns true if Testbed1StructStringWithArray A is not equal to Testbed1StructStringWithArray B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed1StructStringWithArray)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed1")
	static bool NotEqual_Testbed1StructStringWithArrayTestbed1StructStringWithArray(FTestbed1StructStringWithArray A, FTestbed1StructStringWithArray B);

	/** Converts a Testbed1StructStringWithArray to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed1StructStringWithArray)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed1StructStringWithArrayToJSON(UPARAM(DisplayName = "Testbed1StructStringWithArray") const FTestbed1StructStringWithArray& InTestbed1StructStringWithArray);

	/** Converts a Testbed1StructStringWithArray to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed1StructStringWithArray)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed1StructStringWithArrayToString(UPARAM(DisplayName = "Testbed1StructStringWithArray") const FTestbed1StructStringWithArray& InTestbed1StructStringWithArray);

	/* Returns true if Testbed1StructStructWithArray A is equal to Testbed1StructStructWithArray B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed1StructStructWithArray)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed1")
	static bool EqualEqual_Testbed1StructStructWithArrayTestbed1StructStructWithArray(FTestbed1StructStructWithArray A, FTestbed1StructStructWithArray B);

	/* Returns true if Testbed1StructStructWithArray A is not equal to Testbed1StructStructWithArray B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed1StructStructWithArray)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed1")
	static bool NotEqual_Testbed1StructStructWithArrayTestbed1StructStructWithArray(FTestbed1StructStructWithArray A, FTestbed1StructStructWithArray B);

	/** Converts a Testbed1StructStructWithArray to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed1StructStructWithArray)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed1StructStructWithArrayToJSON(UPARAM(DisplayName = "Testbed1StructStructWithArray") const FTestbed1StructStructWithArray& InTestbed1StructStructWithArray);

	/** Converts a Testbed1StructStructWithArray to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed1StructStructWithArray)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed1StructStructWithArrayToString(UPARAM(DisplayName = "Testbed1StructStructWithArray") const FTestbed1StructStructWithArray& InTestbed1StructStructWithArray);

	/* Returns true if Testbed1StructEnumWithArray A is equal to Testbed1StructEnumWithArray B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed1StructEnumWithArray)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed1")
	static bool EqualEqual_Testbed1StructEnumWithArrayTestbed1StructEnumWithArray(FTestbed1StructEnumWithArray A, FTestbed1StructEnumWithArray B);

	/* Returns true if Testbed1StructEnumWithArray A is not equal to Testbed1StructEnumWithArray B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed1StructEnumWithArray)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed1")
	static bool NotEqual_Testbed1StructEnumWithArrayTestbed1StructEnumWithArray(FTestbed1StructEnumWithArray A, FTestbed1StructEnumWithArray B);

	/** Converts a Testbed1StructEnumWithArray to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed1StructEnumWithArray)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed1StructEnumWithArrayToJSON(UPARAM(DisplayName = "Testbed1StructEnumWithArray") const FTestbed1StructEnumWithArray& InTestbed1StructEnumWithArray);

	/** Converts a Testbed1StructEnumWithArray to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed1StructEnumWithArray)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed1StructEnumWithArrayToString(UPARAM(DisplayName = "Testbed1StructEnumWithArray") const FTestbed1StructEnumWithArray& InTestbed1StructEnumWithArray);
};
