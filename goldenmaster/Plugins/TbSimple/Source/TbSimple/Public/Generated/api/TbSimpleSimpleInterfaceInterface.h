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

#include "UObject/Interface.h"
#include "Engine/LatentActionManager.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSimple_data.h"
#include "TbSimpleSimpleInterfaceInterface.generated.h"

/**
 * Declaration for SimpleInterface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTbSimpleSimpleInterfaceSigVoidDelegate);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigBoolDelegate, bool, bParamBool);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigIntDelegate, int32, ParamInt);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigInt32Delegate, int32, ParamInt32);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigInt64Delegate, int64, ParamInt64);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigFloatDelegate, float, ParamFloat);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigFloat32Delegate, float, ParamFloa32);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigFloat64Delegate, double, ParamFloat64);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigStringDelegate, const FString&, ParamString);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropBoolChangedDelegate, bool, bPropBool);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropIntChangedDelegate, int32, PropInt);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropInt32ChangedDelegate, int32, PropInt32);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropInt64ChangedDelegate, int64, PropInt64);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropFloatChangedDelegate, float, PropFloat);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropFloat32ChangedDelegate, float, PropFloat32);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropFloat64ChangedDelegate, double, PropFloat64);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropStringChangedDelegate, const FString&, PropString);

/**
 * Interface UTbSimpleSimpleInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbSimpleSimpleInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSimpleSimpleInterfaceInterface
 */
class TBSIMPLE_API ITbSimpleSimpleInterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfaceSigVoidDelegate& GetSigVoidSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfaceSigIntDelegate& GetSigIntSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfaceSigInt32Delegate& GetSigInt32SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfaceSigInt64Delegate& GetSigInt64SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfaceSigFloat32Delegate& GetSigFloat32SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfaceSigFloat64Delegate& GetSigFloat64SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfaceSigStringDelegate& GetSigStringSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfacePropInt32ChangedDelegate& GetPropInt32ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfacePropInt64ChangedDelegate& GetPropInt64ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfacePropFloat32ChangedDelegate& GetPropFloat32ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfacePropFloat64ChangedDelegate& GetPropFloat64ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void FuncVoid();
	virtual void FuncVoid_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool);
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	bool FuncBool(bool bParamBool);
	virtual bool FuncBool_Implementation(bool bParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt);
	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	int32 FuncInt(int32 ParamInt);
	virtual int32 FuncInt_Implementation(int32 ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncInt32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt32);
	virtual void FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	int32 FuncInt32(int32 ParamInt32);
	virtual int32 FuncInt32_Implementation(int32 ParamInt32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncInt64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int64& Result, int64 ParamInt64);
	virtual void FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int64& Result, int64 ParamInt64) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	int64 FuncInt64(int64 ParamInt64);
	virtual int64 FuncInt64_Implementation(int64 ParamInt64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat);
	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	float FuncFloat(float ParamFloat);
	virtual float FuncFloat_Implementation(float ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloat32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat32);
	virtual void FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	float FuncFloat32(float ParamFloat32);
	virtual float FuncFloat32_Implementation(float ParamFloat32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloat64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, double& Result, double ParamFloat);
	virtual void FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, double& Result, double ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	double FuncFloat64(double ParamFloat);
	virtual double FuncFloat64_Implementation(double ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString);
	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	FString FuncString(const FString& ParamString);
	virtual FString FuncString_Implementation(const FString& ParamString) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	bool GetPropBool() const;
	virtual bool GetPropBool_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void SetPropBool(bool bInPropBool);
	virtual void SetPropBool_Implementation(bool bInPropBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	int32 GetPropInt() const;
	virtual int32 GetPropInt_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void SetPropInt(int32 InPropInt);
	virtual void SetPropInt_Implementation(int32 InPropInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	int32 GetPropInt32() const;
	virtual int32 GetPropInt32_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void SetPropInt32(int32 InPropInt32);
	virtual void SetPropInt32_Implementation(int32 InPropInt32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	int64 GetPropInt64() const;
	virtual int64 GetPropInt64_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void SetPropInt64(int64 InPropInt64);
	virtual void SetPropInt64_Implementation(int64 InPropInt64) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	float GetPropFloat() const;
	virtual float GetPropFloat_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void SetPropFloat(float InPropFloat);
	virtual void SetPropFloat_Implementation(float InPropFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	float GetPropFloat32() const;
	virtual float GetPropFloat32_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void SetPropFloat32(float InPropFloat32);
	virtual void SetPropFloat32_Implementation(float InPropFloat32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	double GetPropFloat64() const;
	virtual double GetPropFloat64_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void SetPropFloat64(double InPropFloat64);
	virtual void SetPropFloat64_Implementation(double InPropFloat64) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	FString GetPropString() const;
	virtual FString GetPropString_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void SetPropString(const FString& InPropString);
	virtual void SetPropString_Implementation(const FString& InPropString) = 0;

protected:
	// signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigVoid();
	virtual void BroadcastSigVoid_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigBool(bool bParamBool);
	virtual void BroadcastSigBool_Implementation(bool bParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigInt(int32 ParamInt);
	virtual void BroadcastSigInt_Implementation(int32 ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigInt32(int32 ParamInt32);
	virtual void BroadcastSigInt32_Implementation(int32 ParamInt32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigInt64(int64 ParamInt64);
	virtual void BroadcastSigInt64_Implementation(int64 ParamInt64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigFloat(float ParamFloat);
	virtual void BroadcastSigFloat_Implementation(float ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigFloat32(float ParamFloa32);
	virtual void BroadcastSigFloat32_Implementation(float ParamFloa32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigFloat64(double ParamFloat64);
	virtual void BroadcastSigFloat64_Implementation(double ParamFloat64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigString(const FString& ParamString);
	virtual void BroadcastSigString_Implementation(const FString& ParamString) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropBoolChanged(bool bPropBool);
	virtual void BroadcastPropBoolChanged_Implementation(bool bPropBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropIntChanged(int32 PropInt);
	virtual void BroadcastPropIntChanged_Implementation(int32 PropInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropInt32Changed(int32 PropInt32);
	virtual void BroadcastPropInt32Changed_Implementation(int32 PropInt32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropInt64Changed(int64 PropInt64);
	virtual void BroadcastPropInt64Changed_Implementation(int64 PropInt64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropFloatChanged(float PropFloat);
	virtual void BroadcastPropFloatChanged_Implementation(float PropFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropFloat32Changed(float PropFloat32);
	virtual void BroadcastPropFloat32Changed_Implementation(float PropFloat32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropFloat64Changed(double PropFloat64);
	virtual void BroadcastPropFloat64Changed_Implementation(double PropFloat64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropStringChanged(const FString& PropString);
	virtual void BroadcastPropStringChanged_Implementation(const FString& PropString) = 0;
};

/**
 * Abstract UAbstractTbSimpleSimpleInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSIMPLE_API UAbstractTbSimpleSimpleInterface : public UGameInstanceSubsystem, public ITbSimpleSimpleInterfaceInterface
{
	GENERATED_BODY()

public:
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigVoid Signal")
	FTbSimpleSimpleInterfaceSigVoidDelegate SigVoidSignal;
	virtual FTbSimpleSimpleInterfaceSigVoidDelegate& GetSigVoidSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigBool Signal")
	FTbSimpleSimpleInterfaceSigBoolDelegate SigBoolSignal;
	virtual FTbSimpleSimpleInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigInt Signal")
	FTbSimpleSimpleInterfaceSigIntDelegate SigIntSignal;
	virtual FTbSimpleSimpleInterfaceSigIntDelegate& GetSigIntSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigInt32 Signal")
	FTbSimpleSimpleInterfaceSigInt32Delegate SigInt32Signal;
	virtual FTbSimpleSimpleInterfaceSigInt32Delegate& GetSigInt32SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigInt64 Signal")
	FTbSimpleSimpleInterfaceSigInt64Delegate SigInt64Signal;
	virtual FTbSimpleSimpleInterfaceSigInt64Delegate& GetSigInt64SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigFloat Signal")
	FTbSimpleSimpleInterfaceSigFloatDelegate SigFloatSignal;
	virtual FTbSimpleSimpleInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigFloat32 Signal")
	FTbSimpleSimpleInterfaceSigFloat32Delegate SigFloat32Signal;
	virtual FTbSimpleSimpleInterfaceSigFloat32Delegate& GetSigFloat32SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigFloat64 Signal")
	FTbSimpleSimpleInterfaceSigFloat64Delegate SigFloat64Signal;
	virtual FTbSimpleSimpleInterfaceSigFloat64Delegate& GetSigFloat64SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigString Signal")
	FTbSimpleSimpleInterfaceSigStringDelegate SigStringSignal;
	virtual FTbSimpleSimpleInterfaceSigStringDelegate& GetSigStringSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropBool Changed")
	FTbSimpleSimpleInterfacePropBoolChangedDelegate PropBoolChanged;
	virtual FTbSimpleSimpleInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropInt Changed")
	FTbSimpleSimpleInterfacePropIntChangedDelegate PropIntChanged;
	virtual FTbSimpleSimpleInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropInt32 Changed")
	FTbSimpleSimpleInterfacePropInt32ChangedDelegate PropInt32Changed;
	virtual FTbSimpleSimpleInterfacePropInt32ChangedDelegate& GetPropInt32ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropInt64 Changed")
	FTbSimpleSimpleInterfacePropInt64ChangedDelegate PropInt64Changed;
	virtual FTbSimpleSimpleInterfacePropInt64ChangedDelegate& GetPropInt64ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropFloat Changed")
	FTbSimpleSimpleInterfacePropFloatChangedDelegate PropFloatChanged;
	virtual FTbSimpleSimpleInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropFloat32 Changed")
	FTbSimpleSimpleInterfacePropFloat32ChangedDelegate PropFloat32Changed;
	virtual FTbSimpleSimpleInterfacePropFloat32ChangedDelegate& GetPropFloat32ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropFloat64 Changed")
	FTbSimpleSimpleInterfacePropFloat64ChangedDelegate PropFloat64Changed;
	virtual FTbSimpleSimpleInterfacePropFloat64ChangedDelegate& GetPropFloat64ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropString Changed")
	FTbSimpleSimpleInterfacePropStringChangedDelegate PropStringChanged;
	virtual FTbSimpleSimpleInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override;

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

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;
	// signals
	virtual void BroadcastSigVoid_Implementation() override;

	virtual void BroadcastSigBool_Implementation(bool bParamBool) override;

	virtual void BroadcastSigInt_Implementation(int32 ParamInt) override;

	virtual void BroadcastSigInt32_Implementation(int32 ParamInt32) override;

	virtual void BroadcastSigInt64_Implementation(int64 ParamInt64) override;

	virtual void BroadcastSigFloat_Implementation(float ParamFloat) override;

	virtual void BroadcastSigFloat32_Implementation(float ParamFloa32) override;

	virtual void BroadcastSigFloat64_Implementation(double ParamFloat64) override;

	virtual void BroadcastSigString_Implementation(const FString& ParamString) override;

	virtual void BroadcastPropBoolChanged_Implementation(bool bInPropBool) override;

	virtual void BroadcastPropIntChanged_Implementation(int32 InPropInt) override;

	virtual void BroadcastPropInt32Changed_Implementation(int32 InPropInt32) override;

	virtual void BroadcastPropInt64Changed_Implementation(int64 InPropInt64) override;

	virtual void BroadcastPropFloatChanged_Implementation(float InPropFloat) override;

	virtual void BroadcastPropFloat32Changed_Implementation(float InPropFloat32) override;

	virtual void BroadcastPropFloat64Changed_Implementation(double InPropFloat64) override;

	virtual void BroadcastPropStringChanged_Implementation(const FString& InPropString) override;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	bool bPropBool{false};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	bool GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropBool_Private(bool bInPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	int32 PropInt{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	int32 GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropInt_Private(int32 InPropInt);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt32_Private, BlueprintSetter = SetPropInt32_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	int32 PropInt32{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	int32 GetPropInt32_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropInt32_Private(int32 InPropInt32);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt64_Private, BlueprintSetter = SetPropInt64_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	int64 PropInt64{0LL};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	int64 GetPropInt64_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropInt64_Private(int64 InPropInt64);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	float PropFloat{0.0f};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	float GetPropFloat_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropFloat_Private(float InPropFloat);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat32_Private, BlueprintSetter = SetPropFloat32_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	float PropFloat32{0.0f};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	float GetPropFloat32_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropFloat32_Private(float InPropFloat32);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat64_Private, BlueprintSetter = SetPropFloat64_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	double PropFloat64{0.0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	double GetPropFloat64_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropFloat64_Private(double InPropFloat64);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	FString PropString{FString()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	FString GetPropString_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropString_Private(const FString& InPropString);
};
