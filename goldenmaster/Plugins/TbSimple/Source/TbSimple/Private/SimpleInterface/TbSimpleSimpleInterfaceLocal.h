
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
#include "apig/TbSimple_apig.h"
#include "TbSimpleSimpleInterfaceLocal.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "TbSimpleSimpleInterface")
class TBSIMPLE_API UTbSimpleSimpleInterfaceLocalService : public UObject, public ITbSimpleSimpleInterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleSimpleInterfaceLocalService();
	virtual ~UTbSimpleSimpleInterfaceLocalService();

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
	bool GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(bool bPropBool) override;

	int32 GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(int32 PropInt) override;

	float GetPropFloat_Implementation() const override;
	void SetPropFloat_Implementation(float PropFloat) override;

	FString GetPropString_Implementation() const override;
	void SetPropString_Implementation(const FString& PropString) override;

	// operations
	void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override{};
	bool FuncBool_Implementation(bool bParamBool) override;

	void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt) override{};
	int32 FuncInt_Implementation(int32 ParamInt) override;

	void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat) override{};
	float FuncFloat_Implementation(float ParamFloat) override;

	void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString) override{};
	FString FuncString_Implementation(const FString& ParamString) override;

private:
	// properties - local copy - use setter functions to emit changed signals
	bool bPropBool;
	int32 PropInt;
	float PropFloat;
	FString PropString;
};
