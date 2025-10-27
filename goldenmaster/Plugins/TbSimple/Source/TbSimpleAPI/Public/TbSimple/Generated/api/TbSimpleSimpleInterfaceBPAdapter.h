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
#include "TbSimple_data.h"
#include "TbSimple/Generated/api/TbSimpleSimpleInterfaceInterface.h"
#include "TbSimple/Generated/api/TbSimpleSimpleInterfaceBPInterface.h"
#include "TbSimpleSimpleInterfaceBPAdapter.generated.h"

/**
 * Adapter UTbSimpleSimpleInterfaceBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TBSIMPLEAPI_API UTbSimpleSimpleInterfaceBPAdapter : public UObject, public ITbSimpleSimpleInterfaceInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|TbSimple|SimpleInterface")
	TScriptInterface<ITbSimpleSimpleInterfaceBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void Initialize(TScriptInterface<ITbSimpleSimpleInterfaceBPInterface> InTarget);

	// signals
	UTbSimpleSimpleInterfacePublisher* _GetPublisher() override;

	// methods
	void FuncNoReturnValue(bool bParamBool) override;

	void FuncNoParamsAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result ) override;
	TFuture<bool> FuncNoParamsAsync() override;
	bool FuncNoParams() override;

	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override;
	TFuture<bool> FuncBoolAsync(bool bParamBool) override;
	bool FuncBool(bool bParamBool) override;

	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt) override;
	TFuture<int32> FuncIntAsync(int32 ParamInt) override;
	int32 FuncInt(int32 ParamInt) override;

	void FuncInt32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt32) override;
	TFuture<int32> FuncInt32Async(int32 ParamInt32) override;
	int32 FuncInt32(int32 ParamInt32) override;

	void FuncInt64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int64& Result, int64 ParamInt64) override;
	TFuture<int64> FuncInt64Async(int64 ParamInt64) override;
	int64 FuncInt64(int64 ParamInt64) override;

	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat) override;
	TFuture<float> FuncFloatAsync(float ParamFloat) override;
	float FuncFloat(float ParamFloat) override;

	void FuncFloat32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat32) override;
	TFuture<float> FuncFloat32Async(float ParamFloat32) override;
	float FuncFloat32(float ParamFloat32) override;

	void FuncFloat64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, double& Result, double ParamFloat) override;
	TFuture<double> FuncFloat64Async(double ParamFloat) override;
	double FuncFloat64(double ParamFloat) override;

	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString) override;
	TFuture<FString> FuncStringAsync(const FString& ParamString) override;
	FString FuncString(const FString& ParamString) override;

	// properties
	bool GetPropBool() const override;
	void SetPropBool(bool bInPropBool) override;

	int32 GetPropInt() const override;
	void SetPropInt(int32 InPropInt) override;

	int32 GetPropInt32() const override;
	void SetPropInt32(int32 InPropInt32) override;

	int64 GetPropInt64() const override;
	void SetPropInt64(int64 InPropInt64) override;

	float GetPropFloat() const override;
	void SetPropFloat(float InPropFloat) override;

	float GetPropFloat32() const override;
	void SetPropFloat32(float InPropFloat32) override;

	double GetPropFloat64() const override;
	void SetPropFloat64(double InPropFloat64) override;

	FString GetPropString() const override;
	void SetPropString(const FString& InPropString) override;
};
