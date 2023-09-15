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
#include "TbSimpleSimpleInterfaceInterface.h"
#include "AbstractTbSimpleSimpleInterface.generated.h"

/**
 * Abstract UAbstractTbSimpleSimpleInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSIMPLE_API UAbstractTbSimpleSimpleInterface : public UGameInstanceSubsystem, public ITbSimpleSimpleInterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbSimpleSimpleInterface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbSimpleSimpleInterfaceSignals* _GetSignals_Implementation() override
	{
		return TbSimpleSimpleInterfaceSignals;
	};

	// methods
	virtual void FuncVoid_Implementation() override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::FuncVoid_Implementation, return;);

	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override;
	virtual bool FuncBool_Implementation(bool bParamBool) override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::FuncBool_Implementation, return false;);

	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt) override;
	virtual int32 FuncInt_Implementation(int32 ParamInt) override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::FuncInt_Implementation, return 0;);

	virtual void FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt32) override;
	virtual int32 FuncInt32_Implementation(int32 ParamInt32) override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::FuncInt32_Implementation, return 0;);

	virtual void FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int64& Result, int64 ParamInt64) override;
	virtual int64 FuncInt64_Implementation(int64 ParamInt64) override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::FuncInt64_Implementation, return 0LL;);

	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat) override;
	virtual float FuncFloat_Implementation(float ParamFloat) override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::FuncFloat_Implementation, return 0.0f;);

	virtual void FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat32) override;
	virtual float FuncFloat32_Implementation(float ParamFloat32) override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::FuncFloat32_Implementation, return 0.0f;);

	virtual void FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, double& Result, double ParamFloat) override;
	virtual double FuncFloat64_Implementation(double ParamFloat) override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::FuncFloat64_Implementation, return 0.0;);

	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString) override;
	virtual FString FuncString_Implementation(const FString& ParamString) override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::FuncString_Implementation, return FString(););

	// properties
	virtual bool GetPropBool_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::GetPropBool_Implementation, return false;);
	virtual void SetPropBool_Implementation(bool bInPropBool) override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::SetPropBool_Implementation, return;);

	virtual int32 GetPropInt_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::GetPropInt_Implementation, return 0;);
	virtual void SetPropInt_Implementation(int32 InPropInt) override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::SetPropInt_Implementation, return;);

	virtual int32 GetPropInt32_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::GetPropInt32_Implementation, return 0;);
	virtual void SetPropInt32_Implementation(int32 InPropInt32) override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::SetPropInt32_Implementation, return;);

	virtual int64 GetPropInt64_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::GetPropInt64_Implementation, return 0LL;);
	virtual void SetPropInt64_Implementation(int64 InPropInt64) override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::SetPropInt64_Implementation, return;);

	virtual float GetPropFloat_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::GetPropFloat_Implementation, return 0.0f;);
	virtual void SetPropFloat_Implementation(float InPropFloat) override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::SetPropFloat_Implementation, return;);

	virtual float GetPropFloat32_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::GetPropFloat32_Implementation, return 0.0f;);
	virtual void SetPropFloat32_Implementation(float InPropFloat32) override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::SetPropFloat32_Implementation, return;);

	virtual double GetPropFloat64_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::GetPropFloat64_Implementation, return 0.0;);
	virtual void SetPropFloat64_Implementation(double InPropFloat64) override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::SetPropFloat64_Implementation, return;);

	virtual FString GetPropString_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::GetPropString_Implementation, return FString(););
	virtual void SetPropString_Implementation(const FString& InPropString) override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::SetPropString_Implementation, return;);

	virtual FString GetPropReadOnlyString_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleSimpleInterface::GetPropReadOnlyString_Implementation, return FString(););

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	bool bPropBool{false};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface|Properties", BlueprintInternalUseOnly)
	bool GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface|Properties", BlueprintInternalUseOnly)
	void SetPropBool_Private(bool bInPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	int32 PropInt{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface|Properties", BlueprintInternalUseOnly)
	int32 GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface|Properties", BlueprintInternalUseOnly)
	void SetPropInt_Private(int32 InPropInt);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt32_Private, BlueprintSetter = SetPropInt32_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	int32 PropInt32{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface|Properties", BlueprintInternalUseOnly)
	int32 GetPropInt32_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface|Properties", BlueprintInternalUseOnly)
	void SetPropInt32_Private(int32 InPropInt32);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt64_Private, BlueprintSetter = SetPropInt64_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	int64 PropInt64{0LL};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface|Properties", BlueprintInternalUseOnly)
	int64 GetPropInt64_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface|Properties", BlueprintInternalUseOnly)
	void SetPropInt64_Private(int64 InPropInt64);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	float PropFloat{0.0f};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface|Properties", BlueprintInternalUseOnly)
	float GetPropFloat_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface|Properties", BlueprintInternalUseOnly)
	void SetPropFloat_Private(float InPropFloat);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat32_Private, BlueprintSetter = SetPropFloat32_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	float PropFloat32{0.0f};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface|Properties", BlueprintInternalUseOnly)
	float GetPropFloat32_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface|Properties", BlueprintInternalUseOnly)
	void SetPropFloat32_Private(float InPropFloat32);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat64_Private, BlueprintSetter = SetPropFloat64_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	double PropFloat64{0.0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface|Properties", BlueprintInternalUseOnly)
	double GetPropFloat64_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface|Properties", BlueprintInternalUseOnly)
	void SetPropFloat64_Private(double InPropFloat64);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	FString PropString{FString()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface|Properties", BlueprintInternalUseOnly)
	FString GetPropString_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface|Properties", BlueprintInternalUseOnly)
	void SetPropString_Private(const FString& InPropString);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropReadOnlyString_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	FString PropReadOnlyString{FString()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface|Properties", BlueprintInternalUseOnly)
	FString GetPropReadOnlyString_Private() const;

private:
	// signals
	UPROPERTY()
	UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals;
};
