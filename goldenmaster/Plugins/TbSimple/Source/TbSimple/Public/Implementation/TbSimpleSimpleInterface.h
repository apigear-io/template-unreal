
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
#include "Generated/api/TbSimpleSimpleInterfaceInterface.h"
#include "TbSimpleSimpleInterface.generated.h"

UCLASS(BlueprintType, Blueprintable)
class TBSIMPLE_API UTbSimpleSimpleInterface : public UObject, public ITbSimpleSimpleInterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleSimpleInterface();

	// signals
	FTbSimpleSimpleInterfaceSigVoidDelegate SigVoidSignal;
	FTbSimpleSimpleInterfaceSigVoidDelegate& GetSigVoidSignalDelegate() override;

	FTbSimpleSimpleInterfaceSigBoolDelegate SigBoolSignal;
	FTbSimpleSimpleInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	FTbSimpleSimpleInterfaceSigIntDelegate SigIntSignal;
	FTbSimpleSimpleInterfaceSigIntDelegate& GetSigIntSignalDelegate() override;

	FTbSimpleSimpleInterfaceSigInt32Delegate SigInt32Signal;
	FTbSimpleSimpleInterfaceSigInt32Delegate& GetSigInt32SignalDelegate() override;

	FTbSimpleSimpleInterfaceSigInt64Delegate SigInt64Signal;
	FTbSimpleSimpleInterfaceSigInt64Delegate& GetSigInt64SignalDelegate() override;

	FTbSimpleSimpleInterfaceSigFloatDelegate SigFloatSignal;
	FTbSimpleSimpleInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override;

	FTbSimpleSimpleInterfaceSigFloat32Delegate SigFloat32Signal;
	FTbSimpleSimpleInterfaceSigFloat32Delegate& GetSigFloat32SignalDelegate() override;

	FTbSimpleSimpleInterfaceSigFloat64Delegate SigFloat64Signal;
	FTbSimpleSimpleInterfaceSigFloat64Delegate& GetSigFloat64SignalDelegate() override;

	FTbSimpleSimpleInterfaceSigStringDelegate SigStringSignal;
	FTbSimpleSimpleInterfaceSigStringDelegate& GetSigStringSignalDelegate() override;

	FTbSimpleSimpleInterfacePropBoolChangedDelegate PropBoolChanged;
	FTbSimpleSimpleInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	FTbSimpleSimpleInterfacePropIntChangedDelegate PropIntChanged;
	FTbSimpleSimpleInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	FTbSimpleSimpleInterfacePropInt32ChangedDelegate PropInt32Changed;
	FTbSimpleSimpleInterfacePropInt32ChangedDelegate& GetPropInt32ChangedDelegate() override;

	FTbSimpleSimpleInterfacePropInt64ChangedDelegate PropInt64Changed;
	FTbSimpleSimpleInterfacePropInt64ChangedDelegate& GetPropInt64ChangedDelegate() override;

	FTbSimpleSimpleInterfacePropFloatChangedDelegate PropFloatChanged;
	FTbSimpleSimpleInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override;

	FTbSimpleSimpleInterfacePropFloat32ChangedDelegate PropFloat32Changed;
	FTbSimpleSimpleInterfacePropFloat32ChangedDelegate& GetPropFloat32ChangedDelegate() override;

	FTbSimpleSimpleInterfacePropFloat64ChangedDelegate PropFloat64Changed;
	FTbSimpleSimpleInterfacePropFloat64ChangedDelegate& GetPropFloat64ChangedDelegate() override;

	FTbSimpleSimpleInterfacePropStringChangedDelegate PropStringChanged;
	FTbSimpleSimpleInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override;

	// properties
	bool GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(bool bPropBool) override;

	int32 GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(int32 PropInt) override;

	int32 GetPropInt32_Implementation() const override;
	void SetPropInt32_Implementation(int32 PropInt32) override;

	int64 GetPropInt64_Implementation() const override;
	void SetPropInt64_Implementation(int64 PropInt64) override;

	float GetPropFloat_Implementation() const override;
	void SetPropFloat_Implementation(float PropFloat) override;

	float GetPropFloat32_Implementation() const override;
	void SetPropFloat32_Implementation(float PropFloat32) override;

	double GetPropFloat64_Implementation() const override;
	void SetPropFloat64_Implementation(double PropFloat64) override;

	FString GetPropString_Implementation() const override;
	void SetPropString_Implementation(const FString& PropString) override;

	// operations
	void FuncVoid_Implementation() override;

	void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override{};
	bool FuncBool_Implementation(bool bParamBool) override;

	void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt) override{};
	int32 FuncInt_Implementation(int32 ParamInt) override;

	void FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt32) override{};
	int32 FuncInt32_Implementation(int32 ParamInt32) override;

	void FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int64& Result, int64 ParamInt64) override{};
	int64 FuncInt64_Implementation(int64 ParamInt64) override;

	void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat) override{};
	float FuncFloat_Implementation(float ParamFloat) override;

	void FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat32) override{};
	float FuncFloat32_Implementation(float ParamFloat32) override;

	void FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, double& Result, double ParamFloat) override{};
	double FuncFloat64_Implementation(double ParamFloat) override;

	void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString) override{};
	FString FuncString_Implementation(const FString& ParamString) override;

protected:
	// signals
	void BroadcastSigVoid_Implementation() override;

	void BroadcastSigBool_Implementation(bool bParamBool) override;

	void BroadcastSigInt_Implementation(int32 ParamInt) override;

	void BroadcastSigInt32_Implementation(int32 ParamInt32) override;

	void BroadcastSigInt64_Implementation(int64 ParamInt64) override;

	void BroadcastSigFloat_Implementation(float ParamFloat) override;

	void BroadcastSigFloat32_Implementation(float ParamFloa32) override;

	void BroadcastSigFloat64_Implementation(double ParamFloat64) override;

	void BroadcastSigString_Implementation(const FString& ParamString) override;

	void BroadcastPropBoolChanged_Implementation(bool bPropBool) override;

	void BroadcastPropIntChanged_Implementation(int32 PropInt) override;

	void BroadcastPropInt32Changed_Implementation(int32 PropInt32) override;

	void BroadcastPropInt64Changed_Implementation(int64 PropInt64) override;

	void BroadcastPropFloatChanged_Implementation(float PropFloat) override;

	void BroadcastPropFloat32Changed_Implementation(float PropFloat32) override;

	void BroadcastPropFloat64Changed_Implementation(double PropFloat64) override;

	void BroadcastPropStringChanged_Implementation(const FString& PropString) override;

private:
	// properties - local copy - use setter functions to emit changed signals
	bool bPropBool{false};
	int32 PropInt{0};
	int32 PropInt32{0};
	int64 PropInt64{0LL};
	float PropFloat{0.0f};
	float PropFloat32{0.0f};
	double PropFloat64{0.0};
	FString PropString{FString()};
};
