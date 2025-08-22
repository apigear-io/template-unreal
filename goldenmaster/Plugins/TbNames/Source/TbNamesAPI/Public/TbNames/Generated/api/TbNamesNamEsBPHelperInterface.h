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
#include "TbNames/Generated/api/TbNames_data.h"
#include "TbNamesNamEsBPHelperInterface.generated.h"

/**
 * Helper interface for TbNamesNamEs events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events, property-changed events and void-function events only.
 */
UINTERFACE(BlueprintType)
class UTbNamesNamEsBPHelperInterface : public UInterface
{
	GENERATED_BODY()
};

class TBNAMESAPI_API ITbNamesNamEsBPHelperInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbNames|NamEs|Signals", DisplayName = "On SomeSignal Signal")
	void OnSomeSignalSignal(bool bSomeParam);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbNames|NamEs|Signals", DisplayName = "On SomeSignal2 Signal")
	void OnSomeSignal2Signal(bool bSomeParam);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbNames|NamEs|Signals", DisplayName = "On Property Switch Changed")
	void OnSwitchChanged(UPARAM(DisplayName = "bSwitch") bool bInSwitch);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbNames|NamEs|Signals", DisplayName = "On Property SomeProperty Changed")
	void OnSomePropertyChanged(UPARAM(DisplayName = "SomeProperty") int32 InSomeProperty);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbNames|NamEs|Signals", DisplayName = "On Property SomePoperty2 Changed")
	void OnSomePoperty2Changed(UPARAM(DisplayName = "SomePoperty2") int32 InSomePoperty2);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbNames|NamEs|Signals", DisplayName = "On Property EnumProperty Changed")
	void OnEnumPropertyChanged(UPARAM(DisplayName = "EnumProperty") ETbNamesEnum_With_Under_scores InEnumProperty);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbNames|NamEs|Signals", DisplayName = "Do SomeFunction")
	void SomeFunction(bool bSomeParam);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbNames|NamEs|Signals", DisplayName = "Do SomeFunction2")
	void SomeFunction2(bool bSomeParam);
};
