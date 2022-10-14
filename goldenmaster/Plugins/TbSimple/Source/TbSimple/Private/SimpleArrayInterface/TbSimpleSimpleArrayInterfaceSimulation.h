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

#include "apig/TbSimple_apig.h"
#include "TbSimpleSimpleArrayInterfaceSimulation.generated.h"

UCLASS(BlueprintType)
class UTbSimpleSimpleArrayInterfaceSimulationService : public UObject, public ITbSimpleSimpleArrayInterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleSimpleArrayInterfaceSimulationService();
	virtual ~UTbSimpleSimpleArrayInterfaceSimulationService();

	// signals
	FTbSimpleSimpleArrayInterfaceSigBoolDelegate SigBoolSignal;
	FTbSimpleSimpleArrayInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	FTbSimpleSimpleArrayInterfaceSigIntDelegate SigIntSignal;
	FTbSimpleSimpleArrayInterfaceSigIntDelegate& GetSigIntSignalDelegate() override;

	FTbSimpleSimpleArrayInterfaceSigFloatDelegate SigFloatSignal;
	FTbSimpleSimpleArrayInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override;

	FTbSimpleSimpleArrayInterfaceSigStringDelegate SigStringSignal;
	FTbSimpleSimpleArrayInterfaceSigStringDelegate& GetSigStringSignalDelegate() override;

	FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate PropBoolChanged;
	FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	FTbSimpleSimpleArrayInterfacePropIntChangedDelegate PropIntChanged;
	FTbSimpleSimpleArrayInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate PropFloatChanged;
	FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override;

	FTbSimpleSimpleArrayInterfacePropStringChangedDelegate PropStringChanged;
	FTbSimpleSimpleArrayInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override;

	// properties
	void GetPropBool_Implementation(TArray<bool>& ReturnValue) const override;
	void SetPropBool_Implementation(const TArray<bool>& PropBool) override;

	void GetPropInt_Implementation(TArray<int32>& ReturnValue) const override;
	void SetPropInt_Implementation(const TArray<int32>& PropInt) override;

	void GetPropFloat_Implementation(TArray<float>& ReturnValue) const override;
	void SetPropFloat_Implementation(const TArray<float>& PropFloat) override;

	void GetPropString_Implementation(TArray<FString>& ReturnValue) const override;
	void SetPropString_Implementation(const TArray<FString>& PropString) override;

	// operations
	void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool) override{};
	void FuncBool_Implementation(TArray<bool>& Result, const TArray<bool>& ParamBool) override;

	void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt) override{};
	void FuncInt_Implementation(TArray<int32>& Result, const TArray<int32>& ParamInt) override;

	void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat) override{};
	void FuncFloat_Implementation(TArray<float>& Result, const TArray<float>& ParamFloat) override;

	void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString) override{};
	void FuncString_Implementation(TArray<FString>& Result, const TArray<FString>& ParamString) override;

private:
	// properties - local copy
	TArray<bool> PropBool;
	TArray<int32> PropInt;
	TArray<float> PropFloat;
	TArray<FString> PropString;
};
