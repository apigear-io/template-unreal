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
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSimple_data.h"
#include "TbSimple/Generated/api/TbSimpleNoSignalsInterfaceInterface.h"
#include "TbSimple/Generated/api/TbSimpleNoSignalsInterfaceBPInterface.h"
#include "TbSimpleNoSignalsInterfaceBPAdapter.generated.h"

/**
 * Adapter UTbSimpleNoSignalsInterfaceBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TBSIMPLEAPI_API UTbSimpleNoSignalsInterfaceBPAdapter : public UObject, public ITbSimpleNoSignalsInterfaceInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|TbSimple|NoSignalsInterface")
	TScriptInterface<ITbSimpleNoSignalsInterfaceBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface")
	void Initialize(TScriptInterface<ITbSimpleNoSignalsInterfaceBPInterface> InTarget);

	// signals
	UTbSimpleNoSignalsInterfacePublisher* _GetPublisher() override;

	// methods
	void FuncVoid() override;

	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override;
	TFuture<bool> FuncBoolAsync(bool bParamBool) override;
	bool FuncBool(bool bParamBool) override;

	// properties
	bool GetPropBool() const override;
	void SetPropBool(bool bInPropBool) override;

	int32 GetPropInt() const override;
	void SetPropInt(int32 InPropInt) override;
};
