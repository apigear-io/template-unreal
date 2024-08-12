
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
#include "CustomTypes_data.generated.h"

/**
 * Struct FCustomTypesVector3D
 */
USTRUCT(BlueprintType)
struct CUSTOMTYPES_API FCustomTypesVector3D : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|CustomTypes")
	float x{0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|CustomTypes")
	float y{0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ApiGear|CustomTypes")
	float z{0.0f};

	/**
	 * FCustomTypesVector3D to JSON formatted FString
	 * @param bPrettyPrint Specify whether to use pretty print (e.g., with line endings) or condensed print.
	 *
	 * @return JSON formatted FString
	 */
	FString ToJSON(bool bPrettyPrint = false) const;

	/**
	 * FCustomTypesVector3D to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 */
	FString ToString() const;

	/**
	 * FCustomTypesVector3D to FString
	 * WARNING: Do not rely on the format of the string, it may change in the future
	 *
	 * @return FString
	 */
	explicit operator FString() const;

	bool operator==(const FCustomTypesVector3D& rhs) const;
	bool operator!=(const FCustomTypesVector3D& rhs) const;
};

/**
 * @brief BP Function library for data types
 */
UCLASS(meta = (BlueprintThreadSafe))
class CUSTOMTYPES_API UCustomTypesLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/* Returns true if CustomTypesVector3D A is equal to CustomTypesVector3D B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Equal (CustomTypesVector3D)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "ApiGear|CustomTypes")
	static bool EqualEqual_CustomTypesVector3DCustomTypesVector3D(FCustomTypesVector3D A, FCustomTypesVector3D B);

	/* Returns true if CustomTypesVector3D A is not equal to CustomTypesVector3D B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Not Equal (CustomTypesVector3D)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "ApiGear|CustomTypes")
	static bool NotEqual_CustomTypesVector3DCustomTypesVector3D(FCustomTypesVector3D A, FCustomTypesVector3D B);

	/** Converts a CustomTypesVector3D to a JSON formatted FString */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To JSON (CustomTypesVector3D)", CompactNodeTitle = "->"), Category = "Utilities|String")
	static FString Conv_CustomTypesVector3DToJSON(const FCustomTypesVector3D& InCustomTypesVector3D);

	/** Converts a CustomTypesVector3D to a string. WARNING: Do not rely on the format of the string, it may change in the future */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "To String (CustomTypesVector3D)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_CustomTypesVector3DToString(const FCustomTypesVector3D& InCustomTypesVector3D);
};
