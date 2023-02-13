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
#include "TbSimpleSimpleArrayInterfaceInterface.generated.h"

/**
 * Declaration for SimpleArrayInterface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigBoolDelegate, const TArray<bool>&, ParamBool);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigIntDelegate, const TArray<int32>&, ParamInt);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigInt32Delegate, const TArray<int32>&, ParamInt32);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigInt64Delegate, const TArray<int64>&, ParamInt64);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigFloatDelegate, const TArray<float>&, ParamFloat);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigFloat32Delegate, const TArray<float>&, ParamFloa32);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigFloat64Delegate, const TArray<double>&, ParamFloat64);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigStringDelegate, const TArray<FString>&, ParamString);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate, const TArray<bool>&, PropBool);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropIntChangedDelegate, const TArray<int32>&, PropInt);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropInt32ChangedDelegate, const TArray<int32>&, PropInt32);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropInt64ChangedDelegate, const TArray<int64>&, PropInt64);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate, const TArray<float>&, PropFloat);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropFloat32ChangedDelegate, const TArray<float>&, PropFloat32);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropFloat64ChangedDelegate, const TArray<double>&, PropFloat64);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropStringChangedDelegate, const TArray<FString>&, PropString);

/**
 * Interface UTbSimpleSimpleArrayInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbSimpleSimpleArrayInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSimpleSimpleArrayInterfaceInterface
 */
class TBSIMPLE_API ITbSimpleSimpleArrayInterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigIntDelegate& GetSigIntSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigInt32Delegate& GetSigInt32SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigInt64Delegate& GetSigInt64SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigFloat32Delegate& GetSigFloat32SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigFloat64Delegate& GetSigFloat64SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigStringDelegate& GetSigStringSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropInt32ChangedDelegate& GetPropInt32ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropInt64ChangedDelegate& GetPropInt64ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropFloat32ChangedDelegate& GetPropFloat32ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropFloat64ChangedDelegate& GetPropFloat64ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool);
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<bool> FuncBool(const TArray<bool>& ParamBool);
	virtual TArray<bool> FuncBool_Implementation(const TArray<bool>& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt);
	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int32> FuncInt(const TArray<int32>& ParamInt);
	virtual TArray<int32> FuncInt_Implementation(const TArray<int32>& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncInt32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32);
	virtual void FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int32> FuncInt32(const TArray<int32>& ParamInt32);
	virtual TArray<int32> FuncInt32_Implementation(const TArray<int32>& ParamInt32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncInt64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64);
	virtual void FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int64> FuncInt64(const TArray<int64>& ParamInt64);
	virtual TArray<int64> FuncInt64_Implementation(const TArray<int64>& ParamInt64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat);
	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<float> FuncFloat(const TArray<float>& ParamFloat);
	virtual TArray<float> FuncFloat_Implementation(const TArray<float>& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloat32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32);
	virtual void FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<float> FuncFloat32(const TArray<float>& ParamFloat32);
	virtual TArray<float> FuncFloat32_Implementation(const TArray<float>& ParamFloat32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloat64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat);
	virtual void FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<double> FuncFloat64(const TArray<double>& ParamFloat);
	virtual TArray<double> FuncFloat64_Implementation(const TArray<double>& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString);
	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<FString> FuncString(const TArray<FString>& ParamString);
	virtual TArray<FString> FuncString_Implementation(const TArray<FString>& ParamString) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<bool> GetPropBool() const;
	virtual TArray<bool> GetPropBool_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void SetPropBool(const TArray<bool>& InPropBool);
	virtual void SetPropBool_Implementation(const TArray<bool>& InPropBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int32> GetPropInt() const;
	virtual TArray<int32> GetPropInt_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void SetPropInt(const TArray<int32>& InPropInt);
	virtual void SetPropInt_Implementation(const TArray<int32>& InPropInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int32> GetPropInt32() const;
	virtual TArray<int32> GetPropInt32_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void SetPropInt32(const TArray<int32>& InPropInt32);
	virtual void SetPropInt32_Implementation(const TArray<int32>& InPropInt32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int64> GetPropInt64() const;
	virtual TArray<int64> GetPropInt64_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void SetPropInt64(const TArray<int64>& InPropInt64);
	virtual void SetPropInt64_Implementation(const TArray<int64>& InPropInt64) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<float> GetPropFloat() const;
	virtual TArray<float> GetPropFloat_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void SetPropFloat(const TArray<float>& InPropFloat);
	virtual void SetPropFloat_Implementation(const TArray<float>& InPropFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<float> GetPropFloat32() const;
	virtual TArray<float> GetPropFloat32_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void SetPropFloat32(const TArray<float>& InPropFloat32);
	virtual void SetPropFloat32_Implementation(const TArray<float>& InPropFloat32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<double> GetPropFloat64() const;
	virtual TArray<double> GetPropFloat64_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void SetPropFloat64(const TArray<double>& InPropFloat64);
	virtual void SetPropFloat64_Implementation(const TArray<double>& InPropFloat64) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<FString> GetPropString() const;
	virtual TArray<FString> GetPropString_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void SetPropString(const TArray<FString>& InPropString);
	virtual void SetPropString_Implementation(const TArray<FString>& InPropString) = 0;

protected:
	// signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigBool(const TArray<bool>& ParamBool);
	virtual void BroadcastSigBool_Implementation(const TArray<bool>& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigInt(const TArray<int32>& ParamInt);
	virtual void BroadcastSigInt_Implementation(const TArray<int32>& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigInt32(const TArray<int32>& ParamInt32);
	virtual void BroadcastSigInt32_Implementation(const TArray<int32>& ParamInt32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigInt64(const TArray<int64>& ParamInt64);
	virtual void BroadcastSigInt64_Implementation(const TArray<int64>& ParamInt64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigFloat(const TArray<float>& ParamFloat);
	virtual void BroadcastSigFloat_Implementation(const TArray<float>& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigFloat32(const TArray<float>& ParamFloa32);
	virtual void BroadcastSigFloat32_Implementation(const TArray<float>& ParamFloa32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigFloat64(const TArray<double>& ParamFloat64);
	virtual void BroadcastSigFloat64_Implementation(const TArray<double>& ParamFloat64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigString(const TArray<FString>& ParamString);
	virtual void BroadcastSigString_Implementation(const TArray<FString>& ParamString) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropBoolChanged(const TArray<bool>& PropBool);
	virtual void BroadcastPropBoolChanged_Implementation(const TArray<bool>& PropBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropIntChanged(const TArray<int32>& PropInt);
	virtual void BroadcastPropIntChanged_Implementation(const TArray<int32>& PropInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropInt32Changed(const TArray<int32>& PropInt32);
	virtual void BroadcastPropInt32Changed_Implementation(const TArray<int32>& PropInt32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropInt64Changed(const TArray<int64>& PropInt64);
	virtual void BroadcastPropInt64Changed_Implementation(const TArray<int64>& PropInt64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropFloatChanged(const TArray<float>& PropFloat);
	virtual void BroadcastPropFloatChanged_Implementation(const TArray<float>& PropFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropFloat32Changed(const TArray<float>& PropFloat32);
	virtual void BroadcastPropFloat32Changed_Implementation(const TArray<float>& PropFloat32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropFloat64Changed(const TArray<double>& PropFloat64);
	virtual void BroadcastPropFloat64Changed_Implementation(const TArray<double>& PropFloat64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropStringChanged(const TArray<FString>& PropString);
	virtual void BroadcastPropStringChanged_Implementation(const TArray<FString>& PropString) = 0;
};

/**
 * Abstract UAbstractTbSimpleSimpleArrayInterface
 */
UCLASS(Abstract, Blueprintable)
class TBSIMPLE_API UAbstractTbSimpleSimpleArrayInterface : public UGameInstanceSubsystem, public ITbSimpleSimpleArrayInterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "SigBool Signal")
	FTbSimpleSimpleArrayInterfaceSigBoolDelegate SigBoolSignal;
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override
	{
		return SigBoolSignal;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "SigInt Signal")
	FTbSimpleSimpleArrayInterfaceSigIntDelegate SigIntSignal;
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigIntDelegate& GetSigIntSignalDelegate() override
	{
		return SigIntSignal;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "SigInt32 Signal")
	FTbSimpleSimpleArrayInterfaceSigInt32Delegate SigInt32Signal;
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigInt32Delegate& GetSigInt32SignalDelegate() override
	{
		return SigInt32Signal;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "SigInt64 Signal")
	FTbSimpleSimpleArrayInterfaceSigInt64Delegate SigInt64Signal;
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigInt64Delegate& GetSigInt64SignalDelegate() override
	{
		return SigInt64Signal;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "SigFloat Signal")
	FTbSimpleSimpleArrayInterfaceSigFloatDelegate SigFloatSignal;
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override
	{
		return SigFloatSignal;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "SigFloat32 Signal")
	FTbSimpleSimpleArrayInterfaceSigFloat32Delegate SigFloat32Signal;
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigFloat32Delegate& GetSigFloat32SignalDelegate() override
	{
		return SigFloat32Signal;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "SigFloat64 Signal")
	FTbSimpleSimpleArrayInterfaceSigFloat64Delegate SigFloat64Signal;
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigFloat64Delegate& GetSigFloat64SignalDelegate() override
	{
		return SigFloat64Signal;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "SigString Signal")
	FTbSimpleSimpleArrayInterfaceSigStringDelegate SigStringSignal;
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigStringDelegate& GetSigStringSignalDelegate() override
	{
		return SigStringSignal;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "PropBool Changed")
	FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate PropBoolChanged;
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override
	{
		return PropBoolChanged;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "PropInt Changed")
	FTbSimpleSimpleArrayInterfacePropIntChangedDelegate PropIntChanged;
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override
	{
		return PropIntChanged;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "PropInt32 Changed")
	FTbSimpleSimpleArrayInterfacePropInt32ChangedDelegate PropInt32Changed;
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropInt32ChangedDelegate& GetPropInt32ChangedDelegate() override
	{
		return PropInt32Changed;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "PropInt64 Changed")
	FTbSimpleSimpleArrayInterfacePropInt64ChangedDelegate PropInt64Changed;
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropInt64ChangedDelegate& GetPropInt64ChangedDelegate() override
	{
		return PropInt64Changed;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "PropFloat Changed")
	FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate PropFloatChanged;
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override
	{
		return PropFloatChanged;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "PropFloat32 Changed")
	FTbSimpleSimpleArrayInterfacePropFloat32ChangedDelegate PropFloat32Changed;
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropFloat32ChangedDelegate& GetPropFloat32ChangedDelegate() override
	{
		return PropFloat32Changed;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "PropFloat64 Changed")
	FTbSimpleSimpleArrayInterfacePropFloat64ChangedDelegate PropFloat64Changed;
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropFloat64ChangedDelegate& GetPropFloat64ChangedDelegate() override
	{
		return PropFloat64Changed;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "PropString Changed")
	FTbSimpleSimpleArrayInterfacePropStringChangedDelegate PropStringChanged;
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override
	{
		return PropStringChanged;
	};

	// methods
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncBoolAsync_Implementation, return;);
	virtual TArray<bool> FuncBool_Implementation(const TArray<bool>& ParamBool) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncBool_Implementation, return TArray<bool>(););

	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncIntAsync_Implementation, return;);
	virtual TArray<int32> FuncInt_Implementation(const TArray<int32>& ParamInt) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncInt_Implementation, return TArray<int32>(););

	virtual void FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncInt32Async_Implementation, return;);
	virtual TArray<int32> FuncInt32_Implementation(const TArray<int32>& ParamInt32) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncInt32_Implementation, return TArray<int32>(););

	virtual void FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncInt64Async_Implementation, return;);
	virtual TArray<int64> FuncInt64_Implementation(const TArray<int64>& ParamInt64) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncInt64_Implementation, return TArray<int64>(););

	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncFloatAsync_Implementation, return;);
	virtual TArray<float> FuncFloat_Implementation(const TArray<float>& ParamFloat) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncFloat_Implementation, return TArray<float>(););

	virtual void FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncFloat32Async_Implementation, return;);
	virtual TArray<float> FuncFloat32_Implementation(const TArray<float>& ParamFloat32) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncFloat32_Implementation, return TArray<float>(););

	virtual void FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncFloat64Async_Implementation, return;);
	virtual TArray<double> FuncFloat64_Implementation(const TArray<double>& ParamFloat) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncFloat64_Implementation, return TArray<double>(););

	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString) override PURE_VIRTUAL(UAbstractTbSimpleSimpleArrayInterface::FuncStringAsync_Implementation, return;);
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

protected:
	// signals
	virtual void BroadcastSigBool_Implementation(const TArray<bool>& ParamBool) override
	{
		SigBoolSignal.Broadcast(ParamBool);
	};

	virtual void BroadcastSigInt_Implementation(const TArray<int32>& ParamInt) override
	{
		SigIntSignal.Broadcast(ParamInt);
	};

	virtual void BroadcastSigInt32_Implementation(const TArray<int32>& ParamInt32) override
	{
		SigInt32Signal.Broadcast(ParamInt32);
	};

	virtual void BroadcastSigInt64_Implementation(const TArray<int64>& ParamInt64) override
	{
		SigInt64Signal.Broadcast(ParamInt64);
	};

	virtual void BroadcastSigFloat_Implementation(const TArray<float>& ParamFloat) override
	{
		SigFloatSignal.Broadcast(ParamFloat);
	};

	virtual void BroadcastSigFloat32_Implementation(const TArray<float>& ParamFloa32) override
	{
		SigFloat32Signal.Broadcast(ParamFloa32);
	};

	virtual void BroadcastSigFloat64_Implementation(const TArray<double>& ParamFloat64) override
	{
		SigFloat64Signal.Broadcast(ParamFloat64);
	};

	virtual void BroadcastSigString_Implementation(const TArray<FString>& ParamString) override
	{
		SigStringSignal.Broadcast(ParamString);
	};

	virtual void BroadcastPropBoolChanged_Implementation(const TArray<bool>& InPropBool) override
	{
		PropBoolChanged.Broadcast(InPropBool);
	}

	virtual void BroadcastPropIntChanged_Implementation(const TArray<int32>& InPropInt) override
	{
		PropIntChanged.Broadcast(InPropInt);
	}

	virtual void BroadcastPropInt32Changed_Implementation(const TArray<int32>& InPropInt32) override
	{
		PropInt32Changed.Broadcast(InPropInt32);
	}

	virtual void BroadcastPropInt64Changed_Implementation(const TArray<int64>& InPropInt64) override
	{
		PropInt64Changed.Broadcast(InPropInt64);
	}

	virtual void BroadcastPropFloatChanged_Implementation(const TArray<float>& InPropFloat) override
	{
		PropFloatChanged.Broadcast(InPropFloat);
	}

	virtual void BroadcastPropFloat32Changed_Implementation(const TArray<float>& InPropFloat32) override
	{
		PropFloat32Changed.Broadcast(InPropFloat32);
	}

	virtual void BroadcastPropFloat64Changed_Implementation(const TArray<double>& InPropFloat64) override
	{
		PropFloat64Changed.Broadcast(InPropFloat64);
	}

	virtual void BroadcastPropStringChanged_Implementation(const TArray<FString>& InPropString) override
	{
		PropStringChanged.Broadcast(InPropString);
	}

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<bool> PropBool{TArray<bool>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	TArray<bool> GetPropBool_Private() const
	{
		return Execute_GetPropBool(this);
	};

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void SetPropBool_Private(const TArray<bool>& InPropBool)
	{
		Execute_SetPropBool(this, InPropBool);
	};

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int32> PropInt{TArray<int32>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	TArray<int32> GetPropInt_Private() const
	{
		return Execute_GetPropInt(this);
	};

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void SetPropInt_Private(const TArray<int32>& InPropInt)
	{
		Execute_SetPropInt(this, InPropInt);
	};

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt32_Private, BlueprintSetter = SetPropInt32_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int32> PropInt32{TArray<int32>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	TArray<int32> GetPropInt32_Private() const
	{
		return Execute_GetPropInt32(this);
	};

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void SetPropInt32_Private(const TArray<int32>& InPropInt32)
	{
		Execute_SetPropInt32(this, InPropInt32);
	};

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt64_Private, BlueprintSetter = SetPropInt64_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int64> PropInt64{TArray<int64>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	TArray<int64> GetPropInt64_Private() const
	{
		return Execute_GetPropInt64(this);
	};

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void SetPropInt64_Private(const TArray<int64>& InPropInt64)
	{
		Execute_SetPropInt64(this, InPropInt64);
	};

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<float> PropFloat{TArray<float>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	TArray<float> GetPropFloat_Private() const
	{
		return Execute_GetPropFloat(this);
	};

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void SetPropFloat_Private(const TArray<float>& InPropFloat)
	{
		Execute_SetPropFloat(this, InPropFloat);
	};

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat32_Private, BlueprintSetter = SetPropFloat32_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<float> PropFloat32{TArray<float>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	TArray<float> GetPropFloat32_Private() const
	{
		return Execute_GetPropFloat32(this);
	};

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void SetPropFloat32_Private(const TArray<float>& InPropFloat32)
	{
		Execute_SetPropFloat32(this, InPropFloat32);
	};

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat64_Private, BlueprintSetter = SetPropFloat64_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<double> PropFloat64{TArray<double>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	TArray<double> GetPropFloat64_Private() const
	{
		return Execute_GetPropFloat64(this);
	};

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void SetPropFloat64_Private(const TArray<double>& InPropFloat64)
	{
		Execute_SetPropFloat64(this, InPropFloat64);
	};

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<FString> PropString{TArray<FString>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	TArray<FString> GetPropString_Private() const
	{
		return Execute_GetPropString(this);
	};

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void SetPropString_Private(const TArray<FString>& InPropString)
	{
		Execute_SetPropString(this, InPropString);
	};
};
