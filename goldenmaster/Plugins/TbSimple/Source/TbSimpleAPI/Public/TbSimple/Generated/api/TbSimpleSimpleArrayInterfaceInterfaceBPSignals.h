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
#include "TbSimpleSimpleArrayInterfaceInterfaceBPSignals.generated.h"

/**
 * Helper interface for TbSimpleSimpleArrayInterface events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events, property-changed events and void-function events only.
 */
UINTERFACE(BlueprintType)
class UTbSimpleSimpleArrayInterfaceBPSignalsInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSIMPLEAPI_API ITbSimpleSimpleArrayInterfaceBPSignalsInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On SigBool Signal")
	void OnSigBoolSignal(const TArray<bool>& ParamBool);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On SigInt Signal")
	void OnSigIntSignal(const TArray<int32>& ParamInt);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On SigInt32 Signal")
	void OnSigInt32Signal(const TArray<int32>& ParamInt32);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On SigInt64 Signal")
	void OnSigInt64Signal(const TArray<int64>& ParamInt64);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On SigFloat Signal")
	void OnSigFloatSignal(const TArray<float>& ParamFloat);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On SigFloat32 Signal")
	void OnSigFloat32Signal(const TArray<float>& ParamFloa32);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On SigFloat64 Signal")
	void OnSigFloat64Signal(const TArray<double>& ParamFloat64);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On SigString Signal")
	void OnSigStringSignal(const TArray<FString>& ParamString);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropBool Changed")
	void OnPropBoolChanged(UPARAM(DisplayName = "PropBool") const TArray<bool>& InPropBool);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropInt Changed")
	void OnPropIntChanged(UPARAM(DisplayName = "PropInt") const TArray<int32>& InPropInt);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropInt32 Changed")
	void OnPropInt32Changed(UPARAM(DisplayName = "PropInt32") const TArray<int32>& InPropInt32);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropInt64 Changed")
	void OnPropInt64Changed(UPARAM(DisplayName = "PropInt64") const TArray<int64>& InPropInt64);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropFloat Changed")
	void OnPropFloatChanged(UPARAM(DisplayName = "PropFloat") const TArray<float>& InPropFloat);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropFloat32 Changed")
	void OnPropFloat32Changed(UPARAM(DisplayName = "PropFloat32") const TArray<float>& InPropFloat32);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropFloat64 Changed")
	void OnPropFloat64Changed(UPARAM(DisplayName = "PropFloat64") const TArray<double>& InPropFloat64);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropString Changed")
	void OnPropStringChanged(UPARAM(DisplayName = "PropString") const TArray<FString>& InPropString);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropReadOnlyString Changed")
	void OnPropReadOnlyStringChanged(UPARAM(DisplayName = "PropReadOnlyString") const FString& InPropReadOnlyString);
};
