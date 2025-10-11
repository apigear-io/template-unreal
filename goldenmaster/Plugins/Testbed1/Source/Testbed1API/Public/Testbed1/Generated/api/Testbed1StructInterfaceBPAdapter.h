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
#include "Testbed1/Generated/api/Testbed1StructInterfaceInterface.h"
#include "Testbed1/Generated/api/Testbed1StructInterfaceBPInterface.h"
#include "Testbed1StructInterfaceBPAdapter.generated.h"

/**
 * Adapter UTestbed1StructInterfaceBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TESTBED1API_API UTestbed1StructInterfaceBPAdapter : public UObject, public ITestbed1StructInterfaceInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|Testbed1|StructInterface")
	TScriptInterface<ITestbed1StructInterfaceBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	void Initialize(TScriptInterface<ITestbed1StructInterfaceBPInterface> InTarget);

	// signals
	UTestbed1StructInterfacePublisher* _GetPublisher() override;

	// methods
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool) override;
	TFuture<FTestbed1StructBool> FuncBoolAsync(const FTestbed1StructBool& ParamBool) override;
	FTestbed1StructBool FuncBool(const FTestbed1StructBool& ParamBool) override;

	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructInt& Result, const FTestbed1StructInt& ParamInt) override;
	TFuture<FTestbed1StructInt> FuncIntAsync(const FTestbed1StructInt& ParamInt) override;
	FTestbed1StructInt FuncInt(const FTestbed1StructInt& ParamInt) override;

	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat) override;
	TFuture<FTestbed1StructFloat> FuncFloatAsync(const FTestbed1StructFloat& ParamFloat) override;
	FTestbed1StructFloat FuncFloat(const FTestbed1StructFloat& ParamFloat) override;

	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString) override;
	TFuture<FTestbed1StructString> FuncStringAsync(const FTestbed1StructString& ParamString) override;
	FTestbed1StructString FuncString(const FTestbed1StructString& ParamString) override;

	// properties
	FTestbed1StructBool GetPropBool() const override;
	void SetPropBool(const FTestbed1StructBool& InPropBool) override;

	FTestbed1StructInt GetPropInt() const override;
	void SetPropInt(const FTestbed1StructInt& InPropInt) override;

	FTestbed1StructFloat GetPropFloat() const override;
	void SetPropFloat(const FTestbed1StructFloat& InPropFloat) override;

	FTestbed1StructString GetPropString() const override;
	void SetPropString(const FTestbed1StructString& InPropString) override;
};
