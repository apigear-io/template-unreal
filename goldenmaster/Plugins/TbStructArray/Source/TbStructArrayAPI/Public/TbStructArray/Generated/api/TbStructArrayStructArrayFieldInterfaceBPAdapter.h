/**
Copyright 2024 ApiGear UG
Copyright 2024 Epic Games, Inc.

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

#include "Runtime/Launch/Resources/Version.h"
#include "TbStructArray_data.h"
#include "TbStructArray/Generated/api/TbStructArrayStructArrayFieldInterfaceInterface.h"
#include "TbStructArray/Generated/api/TbStructArrayStructArrayFieldInterfaceBPInterface.h"
#include "TbStructArrayStructArrayFieldInterfaceBPAdapter.generated.h"

/**
 * Adapter UTbStructArrayStructArrayFieldInterfaceBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TBSTRUCTARRAYAPI_API UTbStructArrayStructArrayFieldInterfaceBPAdapter : public UObject, public ITbStructArrayStructArrayFieldInterfaceInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|TbStructArray|StructArrayFieldInterface")
	TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface")
	void Initialize(TScriptInterface<ITbStructArrayStructArrayFieldInterfaceBPInterface> InTarget);

	// signals
	UTbStructArrayStructArrayFieldInterfacePublisher* _GetPublisher() override;

	// methods
	void FuncMixedAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbStructArrayMixedStruct& Result, const FTbStructArrayMixedStruct& ParamMixed) override;
	TFuture<FTbStructArrayMixedStruct> FuncMixedAsync(const FTbStructArrayMixedStruct& ParamMixed) override;
	FTbStructArrayMixedStruct FuncMixed(const FTbStructArrayMixedStruct& ParamMixed) override;

	void FuncStructArrayAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbStructArrayStructWithArrayOfStructs& Result, const FTbStructArrayStructWithArrayOfStructs& ParamPoints) override;
	TFuture<FTbStructArrayStructWithArrayOfStructs> FuncStructArrayAsync(const FTbStructArrayStructWithArrayOfStructs& ParamPoints) override;
	FTbStructArrayStructWithArrayOfStructs FuncStructArray(const FTbStructArrayStructWithArrayOfStructs& ParamPoints) override;

	// properties
	FTbStructArrayStructWithArrayOfStructs GetPropStructArray() const override;
	void SetPropStructArray(const FTbStructArrayStructWithArrayOfStructs& InPropStructArray) override;

	FTbStructArrayStructWithArrayOfEnums GetPropEnumArray() const override;
	void SetPropEnumArray(const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray) override;

	FTbStructArrayStructWithArrayOfInts GetPropIntArray() const override;
	void SetPropIntArray(const FTbStructArrayStructWithArrayOfInts& InPropIntArray) override;

	FTbStructArrayMixedStruct GetPropMixed() const override;
	void SetPropMixed(const FTbStructArrayMixedStruct& InPropMixed) override;
};
