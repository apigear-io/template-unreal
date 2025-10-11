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
#include "Testbed1/Generated/api/Testbed1StructArray2InterfaceInterface.h"
#include "Testbed1/Generated/api/Testbed1StructArray2InterfaceBPInterface.h"
#include "Testbed1StructArray2InterfaceBPAdapter.generated.h"

/**
 * Adapter UTestbed1StructArray2InterfaceBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TESTBED1API_API UTestbed1StructArray2InterfaceBPAdapter : public UObject, public ITestbed1StructArray2InterfaceInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|Testbed1|StructArray2Interface")
	TScriptInterface<ITestbed1StructArray2InterfaceBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface")
	void Initialize(TScriptInterface<ITestbed1StructArray2InterfaceBPInterface> InTarget);

	// signals
	UTestbed1StructArray2InterfacePublisher* _GetPublisher() override;

	// methods
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructBool>& Result, const FTestbed1StructBoolWithArray& ParamBool) override;
	TFuture<TArray<FTestbed1StructBool>> FuncBoolAsync(const FTestbed1StructBoolWithArray& ParamBool) override;
	TArray<FTestbed1StructBool> FuncBool(const FTestbed1StructBoolWithArray& ParamBool) override;

	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructInt>& Result, const FTestbed1StructIntWithArray& ParamInt) override;
	TFuture<TArray<FTestbed1StructInt>> FuncIntAsync(const FTestbed1StructIntWithArray& ParamInt) override;
	TArray<FTestbed1StructInt> FuncInt(const FTestbed1StructIntWithArray& ParamInt) override;

	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructFloat>& Result, const FTestbed1StructFloatWithArray& ParamFloat) override;
	TFuture<TArray<FTestbed1StructFloat>> FuncFloatAsync(const FTestbed1StructFloatWithArray& ParamFloat) override;
	TArray<FTestbed1StructFloat> FuncFloat(const FTestbed1StructFloatWithArray& ParamFloat) override;

	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructString>& Result, const FTestbed1StructStringWithArray& ParamString) override;
	TFuture<TArray<FTestbed1StructString>> FuncStringAsync(const FTestbed1StructStringWithArray& ParamString) override;
	TArray<FTestbed1StructString> FuncString(const FTestbed1StructStringWithArray& ParamString) override;

	void FuncEnumAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<ETestbed1Enum0>& Result, const FTestbed1StructEnumWithArray& ParamEnum) override;
	TFuture<TArray<ETestbed1Enum0>> FuncEnumAsync(const FTestbed1StructEnumWithArray& ParamEnum) override;
	TArray<ETestbed1Enum0> FuncEnum(const FTestbed1StructEnumWithArray& ParamEnum) override;

	// properties
	FTestbed1StructBoolWithArray GetPropBool() const override;
	void SetPropBool(const FTestbed1StructBoolWithArray& InPropBool) override;

	FTestbed1StructIntWithArray GetPropInt() const override;
	void SetPropInt(const FTestbed1StructIntWithArray& InPropInt) override;

	FTestbed1StructFloatWithArray GetPropFloat() const override;
	void SetPropFloat(const FTestbed1StructFloatWithArray& InPropFloat) override;

	FTestbed1StructStringWithArray GetPropString() const override;
	void SetPropString(const FTestbed1StructStringWithArray& InPropString) override;

	FTestbed1StructEnumWithArray GetPropEnum() const override;
	void SetPropEnum(const FTestbed1StructEnumWithArray& InPropEnum) override;
};
