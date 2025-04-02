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
#include "Generated/api/TbSame2_data.h"
#include "TbSame2SameStruct2InterfaceInterfaceBPSignals.generated.h"

/**
 * Helper interface for TbSame2SameStruct2Interface events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events, property-changed events and void-function events only.
 */
UINTERFACE(BlueprintType)
class UTbSame2SameStruct2InterfaceBPSignalsInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSAME2_API ITbSame2SameStruct2InterfaceBPSignalsInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSame2|SameStruct2Interface|Signals", DisplayName = "On Sig1 Signal")
	void OnSig1Signal(const FTbSame2Struct1& Param1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSame2|SameStruct2Interface|Signals", DisplayName = "On Sig2 Signal")
	void OnSig2Signal(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSame2|SameStruct2Interface|Signals", DisplayName = "On Property Prop1 Changed")
	void OnProp1Changed(UPARAM(DisplayName = "Prop1") const FTbSame2Struct2& InProp1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSame2|SameStruct2Interface|Signals", DisplayName = "On Property Prop2 Changed")
	void OnProp2Changed(UPARAM(DisplayName = "Prop2") const FTbSame2Struct2& InProp2);
};
