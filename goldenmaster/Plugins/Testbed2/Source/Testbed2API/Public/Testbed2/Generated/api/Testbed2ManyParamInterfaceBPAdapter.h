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
#include "Testbed2/Generated/api/Testbed2ManyParamInterfaceInterface.h"
#include "Testbed2/Generated/api/Testbed2ManyParamInterfaceBPInterface.h"
#include "Testbed2ManyParamInterfaceBPAdapter.generated.h"

/**
 * Adapter UTestbed2ManyParamInterfaceBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TESTBED2API_API UTestbed2ManyParamInterfaceBPAdapter : public UObject, public ITestbed2ManyParamInterfaceInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|Testbed2|ManyParamInterface")
	TScriptInterface<ITestbed2ManyParamInterfaceBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	void Initialize(TScriptInterface<ITestbed2ManyParamInterfaceBPInterface> InTarget);

	// signals
	UTestbed2ManyParamInterfacePublisher* _GetPublisher() override;

	// methods
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1) override;
	TFuture<int32> Func1Async(int32 Param1) override;
	int32 Func1(int32 Param1) override;

	void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2) override;
	TFuture<int32> Func2Async(int32 Param1, int32 Param2) override;
	int32 Func2(int32 Param1, int32 Param2) override;

	void Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3) override;
	TFuture<int32> Func3Async(int32 Param1, int32 Param2, int32 Param3) override;
	int32 Func3(int32 Param1, int32 Param2, int32 Param3) override;

	void Func4Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;
	TFuture<int32> Func4Async(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;
	int32 Func4(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;

	// properties
	int32 GetProp1() const override;
	void SetProp1(int32 InProp1) override;

	int32 GetProp2() const override;
	void SetProp2(int32 InProp2) override;

	int32 GetProp3() const override;
	void SetProp3(int32 InProp3) override;

	int32 GetProp4() const override;
	void SetProp4(int32 InProp4) override;
};
