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
#include "TbSame1_data.h"
#include "TbSame1/Generated/api/TbSame1SameEnum1InterfaceInterface.h"
#include "TbSame1/Generated/api/TbSame1SameEnum1InterfaceBPInterface.h"
#include "TbSame1SameEnum1InterfaceBPAdapter.generated.h"

/**
 * Adapter UTbSame1SameEnum1InterfaceBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TBSAME1API_API UTbSame1SameEnum1InterfaceBPAdapter : public UObject, public ITbSame1SameEnum1InterfaceInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|TbSame1|SameEnum1Interface")
	TScriptInterface<ITbSame1SameEnum1InterfaceBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface")
	void Initialize(TScriptInterface<ITbSame1SameEnum1InterfaceBPInterface> InTarget);

	// signals
	UTbSame1SameEnum1InterfacePublisher* _GetPublisher() override;

	// methods
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1) override;
	TFuture<ETbSame1Enum1> Func1Async(ETbSame1Enum1 Param1) override;
	ETbSame1Enum1 Func1(ETbSame1Enum1 Param1) override;

	// properties
	ETbSame1Enum1 GetProp1() const override;
	void SetProp1(ETbSame1Enum1 InProp1) override;
};
