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
#include "Generated/api/TbEnum_data.h"
#include "TbEnumEnumInterfaceInterfaceBPSignals.generated.h"

/**
 * Helper interface for TbEnumEnumInterface events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events, property-changed events and void-function events only.
 */
UINTERFACE(BlueprintType)
class UTbEnumEnumInterfaceBPSignalsInterface : public UInterface
{
	GENERATED_BODY()
};

class TBENUM_API ITbEnumEnumInterfaceBPSignalsInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbEnum|EnumInterface|Signals", DisplayName = "On Sig0 Signal")
	void OnSig0Signal(ETbEnumEnum0 Param0);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbEnum|EnumInterface|Signals", DisplayName = "On Sig1 Signal")
	void OnSig1Signal(ETbEnumEnum1 Param1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbEnum|EnumInterface|Signals", DisplayName = "On Sig2 Signal")
	void OnSig2Signal(ETbEnumEnum2 Param2);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbEnum|EnumInterface|Signals", DisplayName = "On Sig3 Signal")
	void OnSig3Signal(ETbEnumEnum3 Param3);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbEnum|EnumInterface|Signals", DisplayName = "On Property Prop0 Changed")
	void OnProp0Changed(UPARAM(DisplayName = "Prop0") ETbEnumEnum0 InProp0);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbEnum|EnumInterface|Signals", DisplayName = "On Property Prop1 Changed")
	void OnProp1Changed(UPARAM(DisplayName = "Prop1") ETbEnumEnum1 InProp1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbEnum|EnumInterface|Signals", DisplayName = "On Property Prop2 Changed")
	void OnProp2Changed(UPARAM(DisplayName = "Prop2") ETbEnumEnum2 InProp2);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbEnum|EnumInterface|Signals", DisplayName = "On Property Prop3 Changed")
	void OnProp3Changed(UPARAM(DisplayName = "Prop3") ETbEnumEnum3 InProp3);
};
