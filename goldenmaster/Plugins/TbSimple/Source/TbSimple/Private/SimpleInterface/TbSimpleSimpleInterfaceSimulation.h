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
namespace SimpleInterface
{
namespace Private
{

class SimulationService : public ITbSimpleSimpleInterfaceInterface
{
public:
	explicit SimulationService();
	virtual ~SimulationService();

	// signals
	FTbSimpleSimpleInterfaceSigBoolDelegate SigBoolSignal;
	FTbSimpleSimpleInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	FTbSimpleSimpleInterfaceSigIntDelegate SigIntSignal;
	FTbSimpleSimpleInterfaceSigIntDelegate& GetSigIntSignalDelegate() override;

	FTbSimpleSimpleInterfaceSigFloatDelegate SigFloatSignal;
	FTbSimpleSimpleInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override;

	FTbSimpleSimpleInterfaceSigStringDelegate SigStringSignal;
	FTbSimpleSimpleInterfaceSigStringDelegate& GetSigStringSignalDelegate() override;

	FTbSimpleSimpleInterfacePropBoolChangedDelegate PropBoolChanged;
	FTbSimpleSimpleInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	FTbSimpleSimpleInterfacePropIntChangedDelegate PropIntChanged;
	FTbSimpleSimpleInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	FTbSimpleSimpleInterfacePropFloatChangedDelegate PropFloatChanged;
	FTbSimpleSimpleInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override;

	FTbSimpleSimpleInterfacePropStringChangedDelegate PropStringChanged;
	FTbSimpleSimpleInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override;

	// properties
	bool GetPropBool() const override;
	void SetPropBool(bool bPropBool) override;

	int32 GetPropInt() const override;
	void SetPropInt(int32 PropInt) override;

	float GetPropFloat() const override;
	void SetPropFloat(float PropFloat) override;

	FString GetPropString() const override;
	void SetPropString(const FString& PropString) override;

	// operations
	bool FuncBool(bool bParamBool) override;

	int32 FuncInt(int32 ParamInt) override;

	float FuncFloat(float ParamFloat) override;

	FString FuncString(const FString& ParamString) override;

private:
	// properties - local copy
	bool bPropBool;
	int32 PropInt;
	float PropFloat;
	FString PropString;
};

} // namespace Private
} // namespace SimpleInterface
} // namespace TbSimple
