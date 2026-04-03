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

#include "UObject/Interface.h"
#include "TbStructArray/Generated/api/TbStructArray_data.h"
#include "TbStructArrayStructArrayFieldInterfaceBPHelperInterface.generated.h"

/**
 * Helper interface for TbStructArrayStructArrayFieldInterface events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events, property-changed events and void-function events only.
 */
UINTERFACE(BlueprintType)
class UTbStructArrayStructArrayFieldInterfaceBPHelperInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSTRUCTARRAYAPI_API ITbStructArrayStructArrayFieldInterfaceBPHelperInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbStructArray|StructArrayFieldInterface|Signals", DisplayName = "On SigMixed Signal")
	void OnSigMixedSignal(const FTbStructArrayMixedStruct& ParamMixed);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbStructArray|StructArrayFieldInterface|Signals", DisplayName = "On SigStructArray Signal")
	void OnSigStructArraySignal(const FTbStructArrayStructWithArrayOfStructs& ParamPoints);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbStructArray|StructArrayFieldInterface|Signals", DisplayName = "On Property PropStructArray Changed")
	void OnPropStructArrayChanged(UPARAM(DisplayName = "PropStructArray") const FTbStructArrayStructWithArrayOfStructs& InPropStructArray);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbStructArray|StructArrayFieldInterface|Signals", DisplayName = "On Property PropEnumArray Changed")
	void OnPropEnumArrayChanged(UPARAM(DisplayName = "PropEnumArray") const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbStructArray|StructArrayFieldInterface|Signals", DisplayName = "On Property PropIntArray Changed")
	void OnPropIntArrayChanged(UPARAM(DisplayName = "PropIntArray") const FTbStructArrayStructWithArrayOfInts& InPropIntArray);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbStructArray|StructArrayFieldInterface|Signals", DisplayName = "On Property PropMixed Changed")
	void OnPropMixedChanged(UPARAM(DisplayName = "PropMixed") const FTbStructArrayMixedStruct& InPropMixed);
};
