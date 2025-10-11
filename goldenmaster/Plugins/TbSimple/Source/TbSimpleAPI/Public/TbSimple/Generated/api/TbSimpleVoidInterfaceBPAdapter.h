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
#include "TbSimple/Generated/api/TbSimpleVoidInterfaceInterface.h"
#include "TbSimple/Generated/api/TbSimpleVoidInterfaceBPInterface.h"
#include "TbSimpleVoidInterfaceBPAdapter.generated.h"

/**
 * Adapter UTbSimpleVoidInterfaceBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TBSIMPLEAPI_API UTbSimpleVoidInterfaceBPAdapter : public UObject, public ITbSimpleVoidInterfaceInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|TbSimple|VoidInterface")
	TScriptInterface<ITbSimpleVoidInterfaceBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|VoidInterface")
	void Initialize(TScriptInterface<ITbSimpleVoidInterfaceBPInterface> InTarget);

	// signals
	UTbSimpleVoidInterfacePublisher* _GetPublisher() override;

	// methods
	void FuncVoid() override;

	// properties
};
