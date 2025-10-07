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
#include "TbSame1/Generated/api/TbSame1SameEnum2InterfaceInterface.h"
#include "TbSame1/Generated/api/TbSame1SameEnum2InterfaceBPInterface.h"
#include "TbSame1SameEnum2InterfaceBPAdapter.generated.h"

/**
 * Adapter UTbSame1SameEnum2InterfaceBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TBSAME1API_API UTbSame1SameEnum2InterfaceBPAdapter : public UObject, public ITbSame1SameEnum2InterfaceInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|TbSame1|SameEnum2Interface")
	TScriptInterface<ITbSame1SameEnum2InterfaceBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
	void Initialize(TScriptInterface<ITbSame1SameEnum2InterfaceBPInterface> InTarget);

	// signals
	UTbSame1SameEnum2InterfacePublisher* _GetPublisher() override;

	// methods
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1) override;
	TFuture<ETbSame1Enum1> Func1Async(ETbSame1Enum1 Param1) override;
	ETbSame1Enum1 Func1(ETbSame1Enum1 Param1) override;

	void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1, ETbSame1Enum2 Param2) override;
	TFuture<ETbSame1Enum1> Func2Async(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2) override;
	ETbSame1Enum1 Func2(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2) override;

	// properties
	ETbSame1Enum1 GetProp1() const override;
	void SetProp1(ETbSame1Enum1 InProp1) override;

	ETbSame1Enum2 GetProp2() const override;
	void SetProp2(ETbSame1Enum2 InProp2) override;
};
