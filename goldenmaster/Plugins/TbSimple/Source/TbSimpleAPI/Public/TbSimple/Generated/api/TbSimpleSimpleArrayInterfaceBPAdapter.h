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
#include "TbSimple/Generated/api/TbSimpleSimpleArrayInterfaceInterface.h"
#include "TbSimple/Generated/api/TbSimpleSimpleArrayInterfaceBPInterface.h"
#include "TbSimpleSimpleArrayInterfaceBPAdapter.generated.h"

/**
 * Adapter UTbSimpleSimpleArrayInterfaceBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class TBSIMPLEAPI_API UTbSimpleSimpleArrayInterfaceBPAdapter : public UObject, public ITbSimpleSimpleArrayInterfaceInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TScriptInterface<ITbSimpleSimpleArrayInterfaceBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void Initialize(TScriptInterface<ITbSimpleSimpleArrayInterfaceBPInterface> InTarget);

	// signals
	UTbSimpleSimpleArrayInterfacePublisher* _GetPublisher() override;

	// methods
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool) override;
	TFuture<TArray<bool>> FuncBoolAsync(const TArray<bool>& ParamBool) override;
	TArray<bool> FuncBool(const TArray<bool>& ParamBool) override;

	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt) override;
	TFuture<TArray<int32>> FuncIntAsync(const TArray<int32>& ParamInt) override;
	TArray<int32> FuncInt(const TArray<int32>& ParamInt) override;

	void FuncInt32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32) override;
	TFuture<TArray<int32>> FuncInt32Async(const TArray<int32>& ParamInt32) override;
	TArray<int32> FuncInt32(const TArray<int32>& ParamInt32) override;

	void FuncInt64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64) override;
	TFuture<TArray<int64>> FuncInt64Async(const TArray<int64>& ParamInt64) override;
	TArray<int64> FuncInt64(const TArray<int64>& ParamInt64) override;

	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat) override;
	TFuture<TArray<float>> FuncFloatAsync(const TArray<float>& ParamFloat) override;
	TArray<float> FuncFloat(const TArray<float>& ParamFloat) override;

	void FuncFloat32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32) override;
	TFuture<TArray<float>> FuncFloat32Async(const TArray<float>& ParamFloat32) override;
	TArray<float> FuncFloat32(const TArray<float>& ParamFloat32) override;

	void FuncFloat64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat) override;
	TFuture<TArray<double>> FuncFloat64Async(const TArray<double>& ParamFloat) override;
	TArray<double> FuncFloat64(const TArray<double>& ParamFloat) override;

	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString) override;
	TFuture<TArray<FString>> FuncStringAsync(const TArray<FString>& ParamString) override;
	TArray<FString> FuncString(const TArray<FString>& ParamString) override;

	// properties
	TArray<bool> GetPropBool() const override;
	void SetPropBool(const TArray<bool>& InPropBool) override;

	TArray<int32> GetPropInt() const override;
	void SetPropInt(const TArray<int32>& InPropInt) override;

	TArray<int32> GetPropInt32() const override;
	void SetPropInt32(const TArray<int32>& InPropInt32) override;

	TArray<int64> GetPropInt64() const override;
	void SetPropInt64(const TArray<int64>& InPropInt64) override;

	TArray<float> GetPropFloat() const override;
	void SetPropFloat(const TArray<float>& InPropFloat) override;

	TArray<float> GetPropFloat32() const override;
	void SetPropFloat32(const TArray<float>& InPropFloat32) override;

	TArray<double> GetPropFloat64() const override;
	void SetPropFloat64(const TArray<double>& InPropFloat64) override;

	TArray<FString> GetPropString() const override;
	void SetPropString(const TArray<FString>& InPropString) override;

	FString GetPropReadOnlyString() const override;
};
