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

#include "Runtime/Launch/Resources/Version.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSimple_data.h"
#include "TbSimpleSimpleArrayInterfaceInterface.h"
#include "AbstractTbSimpleSimpleArrayInterface.generated.h"

/**
 * Abstract UAbstractTbSimpleSimpleArrayInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSIMPLE_API UAbstractTbSimpleSimpleArrayInterface : public UGameInstanceSubsystem, public ITbSimpleSimpleArrayInterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbSimpleSimpleArrayInterface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbSimpleSimpleArrayInterfaceSignals* _GetSignals_Implementation() override
	{
		return TbSimpleSimpleArrayInterfaceSignals;
	};

	// methods
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool) override;
	virtual TArray<bool> FuncBool_Implementation(const TArray<bool>& ParamBool) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncBool_Implementation, return TArray<bool>(););

	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt) override;
	virtual TArray<int32> FuncInt_Implementation(const TArray<int32>& ParamInt) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncInt_Implementation, return TArray<int32>(););

	virtual void FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32) override;
	virtual TArray<int32> FuncInt32_Implementation(const TArray<int32>& ParamInt32) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncInt32_Implementation, return TArray<int32>(););

	virtual void FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64) override;
	virtual TArray<int64> FuncInt64_Implementation(const TArray<int64>& ParamInt64) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncInt64_Implementation, return TArray<int64>(););

	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat) override;
	virtual TArray<float> FuncFloat_Implementation(const TArray<float>& ParamFloat) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncFloat_Implementation, return TArray<float>(););

	virtual void FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32) override;
	virtual TArray<float> FuncFloat32_Implementation(const TArray<float>& ParamFloat32) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncFloat32_Implementation, return TArray<float>(););

	virtual void FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat) override;
	virtual TArray<double> FuncFloat64_Implementation(const TArray<double>& ParamFloat) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncFloat64_Implementation, return TArray<double>(););

	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString) override;
	virtual TArray<FString> FuncString_Implementation(const TArray<FString>& ParamString) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncString_Implementation, return TArray<FString>(););

	// properties
	virtual TArray<bool> GetPropBool_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::GetPropBool_Implementation, return TArray<bool>(););
	virtual void SetPropBool_Implementation(const TArray<bool>& InPropBool) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::SetPropBool_Implementation, return;);

	virtual TArray<int32> GetPropInt_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::GetPropInt_Implementation, return TArray<int32>(););
	virtual void SetPropInt_Implementation(const TArray<int32>& InPropInt) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::SetPropInt_Implementation, return;);

	virtual TArray<int32> GetPropInt32_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::GetPropInt32_Implementation, return TArray<int32>(););
	virtual void SetPropInt32_Implementation(const TArray<int32>& InPropInt32) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::SetPropInt32_Implementation, return;);

	virtual TArray<int64> GetPropInt64_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::GetPropInt64_Implementation, return TArray<int64>(););
	virtual void SetPropInt64_Implementation(const TArray<int64>& InPropInt64) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::SetPropInt64_Implementation, return;);

	virtual TArray<float> GetPropFloat_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::GetPropFloat_Implementation, return TArray<float>(););
	virtual void SetPropFloat_Implementation(const TArray<float>& InPropFloat) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::SetPropFloat_Implementation, return;);

	virtual TArray<float> GetPropFloat32_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::GetPropFloat32_Implementation, return TArray<float>(););
	virtual void SetPropFloat32_Implementation(const TArray<float>& InPropFloat32) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::SetPropFloat32_Implementation, return;);

	virtual TArray<double> GetPropFloat64_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::GetPropFloat64_Implementation, return TArray<double>(););
	virtual void SetPropFloat64_Implementation(const TArray<double>& InPropFloat64) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::SetPropFloat64_Implementation, return;);

	virtual TArray<FString> GetPropString_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::GetPropString_Implementation, return TArray<FString>(););
	virtual void SetPropString_Implementation(const TArray<FString>& InPropString) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::SetPropString_Implementation, return;);

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

private:
	// signals
	UPROPERTY()
	UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals;
};
