
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
