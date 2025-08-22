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
#include "TbSimpleSimpleInterfaceBPHelperInterface.generated.h"

/**
 * Helper interface for TbSimpleSimpleInterface events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events, property-changed events and void-function events only.
 */
UINTERFACE(BlueprintType)
class UTbSimpleSimpleInterfaceBPHelperInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSIMPLEAPI_API ITbSimpleSimpleInterfaceBPHelperInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleInterface|Signals", DisplayName = "On SigBool Signal")
	void OnSigBoolSignal(bool bParamBool);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleInterface|Signals", DisplayName = "On SigInt Signal")
	void OnSigIntSignal(int32 ParamInt);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleInterface|Signals", DisplayName = "On SigInt32 Signal")
	void OnSigInt32Signal(int32 ParamInt32);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleInterface|Signals", DisplayName = "On SigInt64 Signal")
	void OnSigInt64Signal(int64 ParamInt64);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleInterface|Signals", DisplayName = "On SigFloat Signal")
	void OnSigFloatSignal(float ParamFloat);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleInterface|Signals", DisplayName = "On SigFloat32 Signal")
	void OnSigFloat32Signal(float ParamFloat32);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleInterface|Signals", DisplayName = "On SigFloat64 Signal")
	void OnSigFloat64Signal(double ParamFloat64);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleInterface|Signals", DisplayName = "On SigString Signal")
	void OnSigStringSignal(const FString& ParamString);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleInterface|Signals", DisplayName = "On Property PropBool Changed")
	void OnPropBoolChanged(UPARAM(DisplayName = "bPropBool") bool bInPropBool);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleInterface|Signals", DisplayName = "On Property PropInt Changed")
	void OnPropIntChanged(UPARAM(DisplayName = "PropInt") int32 InPropInt);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleInterface|Signals", DisplayName = "On Property PropInt32 Changed")
	void OnPropInt32Changed(UPARAM(DisplayName = "PropInt32") int32 InPropInt32);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleInterface|Signals", DisplayName = "On Property PropInt64 Changed")
	void OnPropInt64Changed(UPARAM(DisplayName = "PropInt64") int64 InPropInt64);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleInterface|Signals", DisplayName = "On Property PropFloat Changed")
	void OnPropFloatChanged(UPARAM(DisplayName = "PropFloat") float InPropFloat);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleInterface|Signals", DisplayName = "On Property PropFloat32 Changed")
	void OnPropFloat32Changed(UPARAM(DisplayName = "PropFloat32") float InPropFloat32);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleInterface|Signals", DisplayName = "On Property PropFloat64 Changed")
	void OnPropFloat64Changed(UPARAM(DisplayName = "PropFloat64") double InPropFloat64);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleInterface|Signals", DisplayName = "On Property PropString Changed")
	void OnPropStringChanged(UPARAM(DisplayName = "PropString") const FString& InPropString);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbSimple|SimpleInterface|Signals", DisplayName = "Do FuncNoReturnValue")
	void FuncNoReturnValue(bool bParamBool);
};
