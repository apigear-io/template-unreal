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
#include "TbSimple/Generated/api/TbSimpleNoPropertiesInterfaceInterface.h"
#include "TbSimple/Generated/api/TbSimpleNoPropertiesInterfaceBPInterface.h"
#include "TbSimpleNoPropertiesInterfaceBPAdapter.generated.h"

/**
 * Adapter UTbSimpleNoPropertiesInterfaceBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TBSIMPLEAPI_API UTbSimpleNoPropertiesInterfaceBPAdapter : public UObject, public ITbSimpleNoPropertiesInterfaceInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|TbSimple|NoPropertiesInterface")
	TScriptInterface<ITbSimpleNoPropertiesInterfaceBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface")
	void Initialize(TScriptInterface<ITbSimpleNoPropertiesInterfaceBPInterface> InTarget);

	// signals
	UTbSimpleNoPropertiesInterfacePublisher* _GetPublisher() override;

	// methods
	void FuncVoid() override;

	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override;
	TFuture<bool> FuncBoolAsync(bool bParamBool) override;
	bool FuncBool(bool bParamBool) override;

	// properties
};
