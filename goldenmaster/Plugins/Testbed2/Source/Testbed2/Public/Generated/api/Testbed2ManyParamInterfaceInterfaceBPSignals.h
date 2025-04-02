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
#include "Generated/api/Testbed2_data.h"
#include "Testbed2ManyParamInterfaceInterfaceBPSignals.generated.h"

/**
 * Helper interface for Testbed2ManyParamInterface events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events, property-changed events and void-function events only.
 */
UINTERFACE(BlueprintType)
class UTestbed2ManyParamInterfaceBPSignalsInterface : public UInterface
{
	GENERATED_BODY()
};

class TESTBED2_API ITestbed2ManyParamInterfaceBPSignalsInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed2|ManyParamInterface|Signals", DisplayName = "On Sig1 Signal")
	void OnSig1Signal(int32 Param1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed2|ManyParamInterface|Signals", DisplayName = "On Sig2 Signal")
	void OnSig2Signal(int32 Param1, int32 Param2);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed2|ManyParamInterface|Signals", DisplayName = "On Sig3 Signal")
	void OnSig3Signal(int32 Param1, int32 Param2, int32 Param3);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed2|ManyParamInterface|Signals", DisplayName = "On Sig4 Signal")
	void OnSig4Signal(int32 Param1, int32 Param2, int32 Param3, int32 Param4);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed2|ManyParamInterface|Signals", DisplayName = "On Property Prop1 Changed")
	void OnProp1Changed(UPARAM(DisplayName = "Prop1") int32 InProp1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed2|ManyParamInterface|Signals", DisplayName = "On Property Prop2 Changed")
	void OnProp2Changed(UPARAM(DisplayName = "Prop2") int32 InProp2);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed2|ManyParamInterface|Signals", DisplayName = "On Property Prop3 Changed")
	void OnProp3Changed(UPARAM(DisplayName = "Prop3") int32 InProp3);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Testbed2|ManyParamInterface|Signals", DisplayName = "On Property Prop4 Changed")
	void OnProp4Changed(UPARAM(DisplayName = "Prop4") int32 InProp4);
};
