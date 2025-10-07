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
#include "TbSame2_data.h"
#include "TbSame2/Generated/api/TbSame2SameStruct2InterfaceInterface.h"
#include "TbSame2/Generated/api/TbSame2SameStruct2InterfaceBPInterface.h"
#include "TbSame2SameStruct2InterfaceBPAdapter.generated.h"

/**
 * Adapter UTbSame2SameStruct2InterfaceBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TBSAME2API_API UTbSame2SameStruct2InterfaceBPAdapter : public UObject, public ITbSame2SameStruct2InterfaceInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|TbSame2|SameStruct2Interface")
	TScriptInterface<ITbSame2SameStruct2InterfaceBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface")
	void Initialize(TScriptInterface<ITbSame2SameStruct2InterfaceBPInterface> InTarget);

	// signals
	UTbSame2SameStruct2InterfacePublisher* _GetPublisher() override;

	// methods
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1) override;
	TFuture<FTbSame2Struct1> Func1Async(const FTbSame2Struct1& Param1) override;
	FTbSame2Struct1 Func1(const FTbSame2Struct1& Param1) override;

	void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override;
	TFuture<FTbSame2Struct1> Func2Async(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override;
	FTbSame2Struct1 Func2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override;

	// properties
	FTbSame2Struct2 GetProp1() const override;
	void SetProp1(const FTbSame2Struct2& InProp1) override;

	FTbSame2Struct2 GetProp2() const override;
	void SetProp2(const FTbSame2Struct2& InProp2) override;
};
