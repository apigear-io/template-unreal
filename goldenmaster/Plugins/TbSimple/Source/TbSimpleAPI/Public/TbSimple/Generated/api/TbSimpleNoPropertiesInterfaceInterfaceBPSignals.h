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
#include "TbSimple/Generated/api/TbSimple_data.h"
#include "TbSimpleNoPropertiesInterfaceInterfaceBPSignals.generated.h"

/**
 * Helper interface for TbSimpleNoPropertiesInterface events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events, property-changed events and void-function events only.
 */
UINTERFACE(BlueprintType)
class UTbSimpleNoPropertiesInterfaceBPSignalsInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSIMPLEAPI_API ITbSimpleNoPropertiesInterfaceBPSignalsInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|NoPropertiesInterface|Signals", DisplayName = "On SigVoid Signal")
	void OnSigVoidSignal();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|NoPropertiesInterface|Signals", DisplayName = "On SigBool Signal")
	void OnSigBoolSignal(bool bParamBool);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|NoPropertiesInterface|Signals", DisplayName = "Do FuncVoid")
	void FuncVoid();
};
