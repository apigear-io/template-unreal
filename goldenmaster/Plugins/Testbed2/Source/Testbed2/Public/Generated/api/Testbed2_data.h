
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
 * Struct FTestbed2Struct1
 */
USTRUCT(BlueprintType)
struct TESTBED2_API FTestbed2Struct1 : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field1{0};

	/**
	 * FTestbed2Struct1 to JSON formatted FString
	 * @return JSON formatted FString
	 */
	FString ToJSON() const;

	/** 
	 * FTestbed2Struct1 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed2Struct1 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 * 
	 * @return FString 
	 */
	explicit operator FString() const;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field1{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field2{0};

	/**
	 * FTestbed2Struct2 to JSON formatted FString
	 * @return JSON formatted FString
	 */
	FString ToJSON() const;

	/** 
	 * FTestbed2Struct2 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed2Struct2 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 * 
	 * @return FString 
	 */
	explicit operator FString() const;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field1{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field2{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field3{0};

	/**
	 * FTestbed2Struct3 to JSON formatted FString
	 * @return JSON formatted FString
	 */
	FString ToJSON() const;

	/** 
	 * FTestbed2Struct3 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed2Struct3 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 * 
	 * @return FString 
	 */
	explicit operator FString() const;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field1{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field2{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field3{0};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	int32 field4{0};

	/**
	 * FTestbed2Struct4 to JSON formatted FString
	 * @return JSON formatted FString
	 */
	FString ToJSON() const;

	/** 
	 * FTestbed2Struct4 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed2Struct4 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 * 
	 * @return FString 
	 */
	explicit operator FString() const;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	FTestbed2Struct1 field1{FTestbed2Struct1()};

	/**
	 * FTestbed2NestedStruct1 to JSON formatted FString
	 * @return JSON formatted FString
	 */
	FString ToJSON() const;

	/** 
	 * FTestbed2NestedStruct1 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed2NestedStruct1 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 * 
	 * @return FString 
	 */
	explicit operator FString() const;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	FTestbed2Struct1 field1{FTestbed2Struct1()};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	FTestbed2Struct2 field2{FTestbed2Struct2()};

	/**
	 * FTestbed2NestedStruct2 to JSON formatted FString
	 * @return JSON formatted FString
	 */
	FString ToJSON() const;

	/** 
	 * FTestbed2NestedStruct2 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed2NestedStruct2 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 * 
	 * @return FString 
	 */
	explicit operator FString() const;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	FTestbed2Struct1 field1{FTestbed2Struct1()};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	FTestbed2Struct2 field2{FTestbed2Struct2()};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|Testbed2")
	FTestbed2Struct3 field3{FTestbed2Struct3()};

	/**
	 * FTestbed2NestedStruct3 to JSON formatted FString
	 * @return JSON formatted FString
	 */
	FString ToJSON() const;

	/** 
	 * FTestbed2NestedStruct3 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FTestbed2NestedStruct3 to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 * 
	 * @return FString 
	 */
	explicit operator FString() const;

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

public:
	/* Convert from uint8 to ETestbed2Enum1 @return true if successful */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2")
	static bool toTestbed2Enum1(ETestbed2Enum1& ConvertedEnum, uint8 InValue);

	/* Convert from uint8 to ETestbed2Enum2 @return true if successful */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2")
	static bool toTestbed2Enum2(ETestbed2Enum2& ConvertedEnum, uint8 InValue);

	/* Convert from uint8 to ETestbed2Enum3 @return true if successful */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2")
	static bool toTestbed2Enum3(ETestbed2Enum3& ConvertedEnum, uint8 InValue);

	/* Returns true if Testbed2Struct1 A is equal to Testbed2Struct1 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed2Struct1)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed2")
	static bool EqualEqual_Testbed2Struct1Testbed2Struct1(FTestbed2Struct1 A, FTestbed2Struct1 B);

	/* Returns true if Testbed2Struct1 A is not equal to Testbed2Struct1 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed2Struct1)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed2")
	static bool NotEqual_Testbed2Struct1Testbed2Struct1(FTestbed2Struct1 A, FTestbed2Struct1 B);
	
	/** Converts a Testbed2Struct1 to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed2Struct1)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed2Struct1ToJSON(const FTestbed2Struct1& InTestbed2Struct1);

	/** Converts a Testbed2Struct1 to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed2Struct1)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed2Struct1ToString(const FTestbed2Struct1& InTestbed2Struct1);

	/* Returns true if Testbed2Struct2 A is equal to Testbed2Struct2 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed2Struct2)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed2")
	static bool EqualEqual_Testbed2Struct2Testbed2Struct2(FTestbed2Struct2 A, FTestbed2Struct2 B);

	/* Returns true if Testbed2Struct2 A is not equal to Testbed2Struct2 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed2Struct2)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed2")
	static bool NotEqual_Testbed2Struct2Testbed2Struct2(FTestbed2Struct2 A, FTestbed2Struct2 B);
	
	/** Converts a Testbed2Struct2 to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed2Struct2)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed2Struct2ToJSON(const FTestbed2Struct2& InTestbed2Struct2);

	/** Converts a Testbed2Struct2 to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed2Struct2)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed2Struct2ToString(const FTestbed2Struct2& InTestbed2Struct2);

	/* Returns true if Testbed2Struct3 A is equal to Testbed2Struct3 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed2Struct3)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed2")
	static bool EqualEqual_Testbed2Struct3Testbed2Struct3(FTestbed2Struct3 A, FTestbed2Struct3 B);

	/* Returns true if Testbed2Struct3 A is not equal to Testbed2Struct3 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed2Struct3)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed2")
	static bool NotEqual_Testbed2Struct3Testbed2Struct3(FTestbed2Struct3 A, FTestbed2Struct3 B);
	
	/** Converts a Testbed2Struct3 to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed2Struct3)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed2Struct3ToJSON(const FTestbed2Struct3& InTestbed2Struct3);

	/** Converts a Testbed2Struct3 to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed2Struct3)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed2Struct3ToString(const FTestbed2Struct3& InTestbed2Struct3);

	/* Returns true if Testbed2Struct4 A is equal to Testbed2Struct4 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed2Struct4)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed2")
	static bool EqualEqual_Testbed2Struct4Testbed2Struct4(FTestbed2Struct4 A, FTestbed2Struct4 B);

	/* Returns true if Testbed2Struct4 A is not equal to Testbed2Struct4 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed2Struct4)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed2")
	static bool NotEqual_Testbed2Struct4Testbed2Struct4(FTestbed2Struct4 A, FTestbed2Struct4 B);
	
	/** Converts a Testbed2Struct4 to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed2Struct4)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed2Struct4ToJSON(const FTestbed2Struct4& InTestbed2Struct4);

	/** Converts a Testbed2Struct4 to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed2Struct4)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed2Struct4ToString(const FTestbed2Struct4& InTestbed2Struct4);

	/* Returns true if Testbed2NestedStruct1 A is equal to Testbed2NestedStruct1 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed2NestedStruct1)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed2")
	static bool EqualEqual_Testbed2NestedStruct1Testbed2NestedStruct1(FTestbed2NestedStruct1 A, FTestbed2NestedStruct1 B);

	/* Returns true if Testbed2NestedStruct1 A is not equal to Testbed2NestedStruct1 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed2NestedStruct1)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed2")
	static bool NotEqual_Testbed2NestedStruct1Testbed2NestedStruct1(FTestbed2NestedStruct1 A, FTestbed2NestedStruct1 B);
	
	/** Converts a Testbed2NestedStruct1 to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed2NestedStruct1)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed2NestedStruct1ToJSON(const FTestbed2NestedStruct1& InTestbed2NestedStruct1);

	/** Converts a Testbed2NestedStruct1 to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed2NestedStruct1)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed2NestedStruct1ToString(const FTestbed2NestedStruct1& InTestbed2NestedStruct1);

	/* Returns true if Testbed2NestedStruct2 A is equal to Testbed2NestedStruct2 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed2NestedStruct2)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed2")
	static bool EqualEqual_Testbed2NestedStruct2Testbed2NestedStruct2(FTestbed2NestedStruct2 A, FTestbed2NestedStruct2 B);

	/* Returns true if Testbed2NestedStruct2 A is not equal to Testbed2NestedStruct2 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed2NestedStruct2)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed2")
	static bool NotEqual_Testbed2NestedStruct2Testbed2NestedStruct2(FTestbed2NestedStruct2 A, FTestbed2NestedStruct2 B);
	
	/** Converts a Testbed2NestedStruct2 to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed2NestedStruct2)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed2NestedStruct2ToJSON(const FTestbed2NestedStruct2& InTestbed2NestedStruct2);

	/** Converts a Testbed2NestedStruct2 to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed2NestedStruct2)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed2NestedStruct2ToString(const FTestbed2NestedStruct2& InTestbed2NestedStruct2);

	/* Returns true if Testbed2NestedStruct3 A is equal to Testbed2NestedStruct3 B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (Testbed2NestedStruct3)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|Testbed2")
	static bool EqualEqual_Testbed2NestedStruct3Testbed2NestedStruct3(FTestbed2NestedStruct3 A, FTestbed2NestedStruct3 B);

	/* Returns true if Testbed2NestedStruct3 A is not equal to Testbed2NestedStruct3 B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (Testbed2NestedStruct3)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|Testbed2")
	static bool NotEqual_Testbed2NestedStruct3Testbed2NestedStruct3(FTestbed2NestedStruct3 A, FTestbed2NestedStruct3 B);
	
	/** Converts a Testbed2NestedStruct3 to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (Testbed2NestedStruct3)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_Testbed2NestedStruct3ToJSON(const FTestbed2NestedStruct3& InTestbed2NestedStruct3);

	/** Converts a Testbed2NestedStruct3 to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (Testbed2NestedStruct3)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_Testbed2NestedStruct3ToString(const FTestbed2NestedStruct3& InTestbed2NestedStruct3);
};
