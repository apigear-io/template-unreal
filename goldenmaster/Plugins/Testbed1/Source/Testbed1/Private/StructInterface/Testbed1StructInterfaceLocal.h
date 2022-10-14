
/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

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

#include "CoreMinimal.h"
#include "apig/Testbed1_apig.h"
#include "Testbed1StructInterfaceLocal.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "Testbed1StructInterface")
class TESTBED1_API UTestbed1StructInterfaceLocalService : public UObject, public ITestbed1StructInterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructInterfaceLocalService();
	virtual ~UTestbed1StructInterfaceLocalService();

	// signals
	FTestbed1StructInterfaceSigBoolDelegate SigBoolSignal;
	FTestbed1StructInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	FTestbed1StructInterfaceSigIntDelegate SigIntSignal;
	FTestbed1StructInterfaceSigIntDelegate& GetSigIntSignalDelegate() override;

	FTestbed1StructInterfaceSigFloatDelegate SigFloatSignal;
	FTestbed1StructInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override;

	FTestbed1StructInterfaceSigStringDelegate SigStringSignal;
	FTestbed1StructInterfaceSigStringDelegate& GetSigStringSignalDelegate() override;

	FTestbed1StructInterfacePropBoolChangedDelegate PropBoolChanged;
	FTestbed1StructInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	FTestbed1StructInterfacePropIntChangedDelegate PropIntChanged;
	FTestbed1StructInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	FTestbed1StructInterfacePropFloatChangedDelegate PropFloatChanged;
	FTestbed1StructInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override;

	FTestbed1StructInterfacePropStringChangedDelegate PropStringChanged;
	FTestbed1StructInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override;

	// properties
	void GetPropBool_Implementation(FTestbed1StructBool& ReturnValue) const override;
	void SetPropBool_Implementation(const FTestbed1StructBool& PropBool) override;

	void GetPropInt_Implementation(FTestbed1StructInt& ReturnValue) const override;
	void SetPropInt_Implementation(const FTestbed1StructInt& PropInt) override;

	void GetPropFloat_Implementation(FTestbed1StructFloat& ReturnValue) const override;
	void SetPropFloat_Implementation(const FTestbed1StructFloat& PropFloat) override;

	void GetPropString_Implementation(FTestbed1StructString& ReturnValue) const override;
	void SetPropString_Implementation(const FTestbed1StructString& PropString) override;

	// operations
	void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool) override{};
	void FuncBool_Implementation(FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool) override;

	void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructInt& ParamInt) override{};
	void FuncInt_Implementation(FTestbed1StructBool& Result, const FTestbed1StructInt& ParamInt) override;

	void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat) override{};
	void FuncFloat_Implementation(FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat) override;

	void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString) override{};
	void FuncString_Implementation(FTestbed1StructString& Result, const FTestbed1StructString& ParamString) override;

private:
	// properties - local copy - use setter functions to emit changed signals
	FTestbed1StructBool PropBool;
	FTestbed1StructInt PropInt;
	FTestbed1StructFloat PropFloat;
	FTestbed1StructString PropString;
};
