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
#include "TbEnum_data.h"
#include "TbEnum/Generated/api/TbEnumEnumInterfaceInterface.h"
#include "TbEnum/Generated/api/TbEnumEnumInterfaceBPInterface.h"
#include "TbEnumEnumInterfaceBPAdapter.generated.h"

/**
 * Adapter UTbEnumEnumInterfaceBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TBENUMAPI_API UTbEnumEnumInterfaceBPAdapter : public UObject, public ITbEnumEnumInterfaceInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|TbEnum|EnumInterface")
	TScriptInterface<ITbEnumEnumInterfaceBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void Initialize(TScriptInterface<ITbEnumEnumInterfaceBPInterface> InTarget);

	// signals
	UTbEnumEnumInterfacePublisher* _GetPublisher() override;

	// methods
	void Func0Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, ETbEnumEnum0 Param0) override;
	TFuture<ETbEnumEnum0> Func0Async(ETbEnumEnum0 Param0) override;
	ETbEnumEnum0 Func0(ETbEnumEnum0 Param0) override;

	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, ETbEnumEnum1 Param1) override;
	TFuture<ETbEnumEnum1> Func1Async(ETbEnumEnum1 Param1) override;
	ETbEnumEnum1 Func1(ETbEnumEnum1 Param1) override;

	void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, ETbEnumEnum2 Param2) override;
	TFuture<ETbEnumEnum2> Func2Async(ETbEnumEnum2 Param2) override;
	ETbEnumEnum2 Func2(ETbEnumEnum2 Param2) override;

	void Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, ETbEnumEnum3 Param3) override;
	TFuture<ETbEnumEnum3> Func3Async(ETbEnumEnum3 Param3) override;
	ETbEnumEnum3 Func3(ETbEnumEnum3 Param3) override;

	// properties
	ETbEnumEnum0 GetProp0() const override;
	void SetProp0(ETbEnumEnum0 InProp0) override;

	ETbEnumEnum1 GetProp1() const override;
	void SetProp1(ETbEnumEnum1 InProp1) override;

	ETbEnumEnum2 GetProp2() const override;
	void SetProp2(ETbEnumEnum2 InProp2) override;

	ETbEnumEnum3 GetProp3() const override;
	void SetProp3(ETbEnumEnum3 InProp3) override;
};
