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
#include "Testbed2_data.h"
#include "Testbed2/Generated/api/Testbed2NestedStruct2InterfaceInterface.h"
#include "Testbed2/Generated/api/Testbed2NestedStruct2InterfaceBPInterface.h"
#include "Testbed2NestedStruct2InterfaceBPAdapter.generated.h"

/**
 * Adapter UTestbed2NestedStruct2InterfaceBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TESTBED2API_API UTestbed2NestedStruct2InterfaceBPAdapter : public UObject, public ITestbed2NestedStruct2InterfaceInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|Testbed2|NestedStruct2Interface")
	TScriptInterface<ITestbed2NestedStruct2InterfaceBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	void Initialize(TScriptInterface<ITestbed2NestedStruct2InterfaceBPInterface> InTarget);

	// signals
	UTestbed2NestedStruct2InterfacePublisher* _GetPublisher() override;

	// methods
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) override;
	TFuture<FTestbed2NestedStruct1> Func1Async(const FTestbed2NestedStruct1& Param1) override;
	FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1) override;

	void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;
	TFuture<FTestbed2NestedStruct1> Func2Async(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;
	FTestbed2NestedStruct1 Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;

	// properties
	FTestbed2NestedStruct1 GetProp1() const override;
	void SetProp1(const FTestbed2NestedStruct1& InProp1) override;

	FTestbed2NestedStruct2 GetProp2() const override;
	void SetProp2(const FTestbed2NestedStruct2& InProp2) override;
};
