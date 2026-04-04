// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbStructArray/Generated/api/AbstractTbStructArrayStructArrayFieldInterface.h"
#include "TbStructArrayStructArrayFieldInterface.generated.h"

UCLASS(BlueprintType)
class TBSTRUCTARRAYIMPLEMENTATION_API UTbStructArrayStructArrayFieldInterfaceImplementation : public UAbstractTbStructArrayStructArrayFieldInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbStructArrayStructArrayFieldInterfaceImplementation();

	// properties
	FTbStructArrayStructWithArrayOfStructs GetPropStructArray() const override;
	void SetPropStructArray(const FTbStructArrayStructWithArrayOfStructs& PropStructArray) override;

	FTbStructArrayStructWithArrayOfEnums GetPropEnumArray() const override;
	void SetPropEnumArray(const FTbStructArrayStructWithArrayOfEnums& PropEnumArray) override;

	FTbStructArrayStructWithArrayOfInts GetPropIntArray() const override;
	void SetPropIntArray(const FTbStructArrayStructWithArrayOfInts& PropIntArray) override;

	FTbStructArrayMixedStruct GetPropMixed() const override;
	void SetPropMixed(const FTbStructArrayMixedStruct& PropMixed) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Properties")
	void _ResetProperties();

	// operations
	FTbStructArrayMixedStruct FuncMixed(const FTbStructArrayMixedStruct& ParamMixed) override;

	FTbStructArrayStructWithArrayOfStructs FuncStructArray(const FTbStructArrayStructWithArrayOfStructs& ParamPoints) override;
};
