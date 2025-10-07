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
#include "Testbed1_data.h"
#include "Testbed1/Generated/api/Testbed1StructArrayInterfaceInterface.h"
#include "Testbed1/Generated/api/Testbed1StructArrayInterfaceBPInterface.h"
#include "Testbed1StructArrayInterfaceBPAdapter.generated.h"

/**
 * Adapter UTestbed1StructArrayInterfaceBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TESTBED1API_API UTestbed1StructArrayInterfaceBPAdapter : public UObject, public ITestbed1StructArrayInterfaceInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|Testbed1|StructArrayInterface")
	TScriptInterface<ITestbed1StructArrayInterfaceBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	void Initialize(TScriptInterface<ITestbed1StructArrayInterfaceBPInterface> InTarget);

	// signals
	UTestbed1StructArrayInterfacePublisher* _GetPublisher() override;

	// methods
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructBool>& Result, const TArray<FTestbed1StructBool>& ParamBool) override;
	TFuture<TArray<FTestbed1StructBool>> FuncBoolAsync(const TArray<FTestbed1StructBool>& ParamBool) override;
	TArray<FTestbed1StructBool> FuncBool(const TArray<FTestbed1StructBool>& ParamBool) override;

	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructInt>& Result, const TArray<FTestbed1StructInt>& ParamInt) override;
	TFuture<TArray<FTestbed1StructInt>> FuncIntAsync(const TArray<FTestbed1StructInt>& ParamInt) override;
	TArray<FTestbed1StructInt> FuncInt(const TArray<FTestbed1StructInt>& ParamInt) override;

	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructFloat>& Result, const TArray<FTestbed1StructFloat>& ParamFloat) override;
	TFuture<TArray<FTestbed1StructFloat>> FuncFloatAsync(const TArray<FTestbed1StructFloat>& ParamFloat) override;
	TArray<FTestbed1StructFloat> FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat) override;

	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructString>& Result, const TArray<FTestbed1StructString>& ParamString) override;
	TFuture<TArray<FTestbed1StructString>> FuncStringAsync(const TArray<FTestbed1StructString>& ParamString) override;
	TArray<FTestbed1StructString> FuncString(const TArray<FTestbed1StructString>& ParamString) override;

	void FuncEnumAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<ETestbed1Enum0>& Result, const TArray<ETestbed1Enum0>& ParamEnum) override;
	TFuture<TArray<ETestbed1Enum0>> FuncEnumAsync(const TArray<ETestbed1Enum0>& ParamEnum) override;
	TArray<ETestbed1Enum0> FuncEnum(const TArray<ETestbed1Enum0>& ParamEnum) override;

	// properties
	TArray<FTestbed1StructBool> GetPropBool() const override;
	void SetPropBool(const TArray<FTestbed1StructBool>& InPropBool) override;

	TArray<FTestbed1StructInt> GetPropInt() const override;
	void SetPropInt(const TArray<FTestbed1StructInt>& InPropInt) override;

	TArray<FTestbed1StructFloat> GetPropFloat() const override;
	void SetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat) override;

	TArray<FTestbed1StructString> GetPropString() const override;
	void SetPropString(const TArray<FTestbed1StructString>& InPropString) override;

	TArray<ETestbed1Enum0> GetPropEnum() const override;
	void SetPropEnum(const TArray<ETestbed1Enum0>& InPropEnum) override;
};
