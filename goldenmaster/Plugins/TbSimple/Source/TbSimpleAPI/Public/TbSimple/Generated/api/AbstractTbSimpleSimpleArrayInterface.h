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
#include "AbstractTbSimpleSimpleArrayInterface.generated.h"

/**
 * Abstract UAbstractTbSimpleSimpleArrayInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSIMPLEAPI_API UAbstractTbSimpleSimpleArrayInterface : public UGameInstanceSubsystem, public ITbSimpleSimpleArrayInterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbSimpleSimpleArrayInterface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbSimpleSimpleArrayInterfacePublisher* _GetPublisher() override;

	// methods
	virtual void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool) override;
	virtual TFuture<TArray<bool>> FuncBoolAsync(const TArray<bool>& ParamBool) override;
	virtual TArray<bool> FuncBool(const TArray<bool>& ParamBool) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncBool, return TArray<bool>(););

	virtual void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt) override;
	virtual TFuture<TArray<int32>> FuncIntAsync(const TArray<int32>& ParamInt) override;
	virtual TArray<int32> FuncInt(const TArray<int32>& ParamInt) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncInt, return TArray<int32>(););

	virtual void FuncInt32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32) override;
	virtual TFuture<TArray<int32>> FuncInt32Async(const TArray<int32>& ParamInt32) override;
	virtual TArray<int32> FuncInt32(const TArray<int32>& ParamInt32) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncInt32, return TArray<int32>(););

	virtual void FuncInt64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64) override;
	virtual TFuture<TArray<int64>> FuncInt64Async(const TArray<int64>& ParamInt64) override;
	virtual TArray<int64> FuncInt64(const TArray<int64>& ParamInt64) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncInt64, return TArray<int64>(););

	virtual void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat) override;
	virtual TFuture<TArray<float>> FuncFloatAsync(const TArray<float>& ParamFloat) override;
	virtual TArray<float> FuncFloat(const TArray<float>& ParamFloat) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncFloat, return TArray<float>(););

	virtual void FuncFloat32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32) override;
	virtual TFuture<TArray<float>> FuncFloat32Async(const TArray<float>& ParamFloat32) override;
	virtual TArray<float> FuncFloat32(const TArray<float>& ParamFloat32) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncFloat32, return TArray<float>(););

	virtual void FuncFloat64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat) override;
	virtual TFuture<TArray<double>> FuncFloat64Async(const TArray<double>& ParamFloat) override;
	virtual TArray<double> FuncFloat64(const TArray<double>& ParamFloat) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncFloat64, return TArray<double>(););

	virtual void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString) override;
	virtual TFuture<TArray<FString>> FuncStringAsync(const TArray<FString>& ParamString) override;
	virtual TArray<FString> FuncString(const TArray<FString>& ParamString) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncString, return TArray<FString>(););

	// properties
	virtual TArray<bool> GetPropBool() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::GetPropBool, return TArray<bool>(););
	virtual void SetPropBool(const TArray<bool>& InPropBool) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::SetPropBool, return;);

	virtual TArray<int32> GetPropInt() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::GetPropInt, return TArray<int32>(););
	virtual void SetPropInt(const TArray<int32>& InPropInt) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::SetPropInt, return;);

	virtual TArray<int32> GetPropInt32() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::GetPropInt32, return TArray<int32>(););
	virtual void SetPropInt32(const TArray<int32>& InPropInt32) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::SetPropInt32, return;);

	virtual TArray<int64> GetPropInt64() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::GetPropInt64, return TArray<int64>(););
	virtual void SetPropInt64(const TArray<int64>& InPropInt64) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::SetPropInt64, return;);

	virtual TArray<float> GetPropFloat() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::GetPropFloat, return TArray<float>(););
	virtual void SetPropFloat(const TArray<float>& InPropFloat) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::SetPropFloat, return;);

	virtual TArray<float> GetPropFloat32() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::GetPropFloat32, return TArray<float>(););
	virtual void SetPropFloat32(const TArray<float>& InPropFloat32) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::SetPropFloat32, return;);

	virtual TArray<double> GetPropFloat64() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::GetPropFloat64, return TArray<double>(););
	virtual void SetPropFloat64(const TArray<double>& InPropFloat64) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::SetPropFloat64, return;);

	virtual TArray<FString> GetPropString() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::GetPropString, return TArray<FString>(););
	virtual void SetPropString(const TArray<FString>& InPropString) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::SetPropString, return;);

	virtual FString GetPropReadOnlyString() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::GetPropReadOnlyString, return FString(););

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<bool> PropBool{TArray<bool>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<bool> GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropBool_Private(const TArray<bool>& InPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int32> PropInt{TArray<int32>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<int32> GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropInt_Private(const TArray<int32>& InPropInt);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt32_Private, BlueprintSetter = SetPropInt32_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int32> PropInt32{TArray<int32>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<int32> GetPropInt32_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropInt32_Private(const TArray<int32>& InPropInt32);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt64_Private, BlueprintSetter = SetPropInt64_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int64> PropInt64{TArray<int64>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<int64> GetPropInt64_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropInt64_Private(const TArray<int64>& InPropInt64);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<float> PropFloat{TArray<float>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<float> GetPropFloat_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropFloat_Private(const TArray<float>& InPropFloat);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat32_Private, BlueprintSetter = SetPropFloat32_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<float> PropFloat32{TArray<float>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<float> GetPropFloat32_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropFloat32_Private(const TArray<float>& InPropFloat32);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat64_Private, BlueprintSetter = SetPropFloat64_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<double> PropFloat64{TArray<double>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<double> GetPropFloat64_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropFloat64_Private(const TArray<double>& InPropFloat64);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<FString> PropString{TArray<FString>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<FString> GetPropString_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropString_Private(const TArray<FString>& InPropString);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropReadOnlyString_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	FString PropReadOnlyString{FString()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties", BlueprintInternalUseOnly)
	FString GetPropReadOnlyString_Private() const;

private:
	// signals
	UPROPERTY()
	UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher;
};
