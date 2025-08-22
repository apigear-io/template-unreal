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
#include "Testbed2/Generated/api/Testbed2_data.h"
#include "Testbed2NestedStruct1InterfaceBPHelperInterface.generated.h"

/**
 * Helper interface for Testbed2NestedStruct1Interface events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events, property-changed events and void-function events only.
 */
UINTERFACE(BlueprintType)
class UTestbed2NestedStruct1InterfaceBPHelperInterface : public UInterface
{
	GENERATED_BODY()
};

class TESTBED2API_API ITestbed2NestedStruct1InterfaceBPHelperInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed2|NestedStruct1Interface|Signals", DisplayName = "On Sig1 Signal")
	void OnSig1Signal(const FTestbed2NestedStruct1& Param1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed2|NestedStruct1Interface|Signals", DisplayName = "On Property Prop1 Changed")
	void OnProp1Changed(UPARAM(DisplayName = "Prop1") const FTestbed2NestedStruct1& InProp1);
};
