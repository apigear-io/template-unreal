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

namespace TbSimple
{
namespace SimpleArrayInterface
{
namespace Private
{

class SimulationService : public ITbSimpleSimpleArrayInterfaceInterface
{
public:
	explicit SimulationService();
	virtual ~SimulationService();

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
	TArray<bool> GetPropBool() const override;
	void SetPropBool(const TArray<bool>& PropBool) override;

	TArray<int32> GetPropInt() const override;
	void SetPropInt(const TArray<int32>& PropInt) override;

	TArray<float> GetPropFloat() const override;
	void SetPropFloat(const TArray<float>& PropFloat) override;

	TArray<FString> GetPropString() const override;
	void SetPropString(const TArray<FString>& PropString) override;

	// operations
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool) override{};
	TArray<bool> FuncBool(const TArray<bool>& ParamBool) override;

	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt) override{};
	TArray<int32> FuncInt(const TArray<int32>& ParamInt) override;

	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat) override{};
	TArray<float> FuncFloat(const TArray<float>& ParamFloat) override;

	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString) override{};
	TArray<FString> FuncString(const TArray<FString>& ParamString) override;

private:
	// properties - local copy
	TArray<bool> PropBool;
	TArray<int32> PropInt;
	TArray<float> PropFloat;
	TArray<FString> PropString;
};

} // namespace Private
} // namespace SimpleArrayInterface
} // namespace TbSimple
