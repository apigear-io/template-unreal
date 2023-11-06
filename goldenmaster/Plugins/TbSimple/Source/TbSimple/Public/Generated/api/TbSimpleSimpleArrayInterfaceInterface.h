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

#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
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
 * Class UTbSimpleSimpleArrayInterfaceInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleSimpleArrayInterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "SigBool Signal")
	FTbSimpleSimpleArrayInterfaceSigBoolDelegate OnSigBoolSignal;
	/// C++ wrapper for BP functions to safely call SigBoolSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast SigBool Signal")
	void BroadcastSigBoolSignal(const TArray<bool>& ParamBool)
	{
		OnSigBoolSignal.Broadcast(ParamBool);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "SigInt Signal")
	FTbSimpleSimpleArrayInterfaceSigIntDelegate OnSigIntSignal;
	/// C++ wrapper for BP functions to safely call SigIntSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast SigInt Signal")
	void BroadcastSigIntSignal(const TArray<int32>& ParamInt)
	{
		OnSigIntSignal.Broadcast(ParamInt);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "SigInt32 Signal")
	FTbSimpleSimpleArrayInterfaceSigInt32Delegate OnSigInt32Signal;
	/// C++ wrapper for BP functions to safely call SigInt32Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast SigInt32 Signal")
	void BroadcastSigInt32Signal(const TArray<int32>& ParamInt32)
	{
		OnSigInt32Signal.Broadcast(ParamInt32);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "SigInt64 Signal")
	FTbSimpleSimpleArrayInterfaceSigInt64Delegate OnSigInt64Signal;
	/// C++ wrapper for BP functions to safely call SigInt64Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast SigInt64 Signal")
	void BroadcastSigInt64Signal(const TArray<int64>& ParamInt64)
	{
		OnSigInt64Signal.Broadcast(ParamInt64);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "SigFloat Signal")
	FTbSimpleSimpleArrayInterfaceSigFloatDelegate OnSigFloatSignal;
	/// C++ wrapper for BP functions to safely call SigFloatSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast SigFloat Signal")
	void BroadcastSigFloatSignal(const TArray<float>& ParamFloat)
	{
		OnSigFloatSignal.Broadcast(ParamFloat);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "SigFloat32 Signal")
	FTbSimpleSimpleArrayInterfaceSigFloat32Delegate OnSigFloat32Signal;
	/// C++ wrapper for BP functions to safely call SigFloat32Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast SigFloat32 Signal")
	void BroadcastSigFloat32Signal(const TArray<float>& ParamFloa32)
	{
		OnSigFloat32Signal.Broadcast(ParamFloa32);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "SigFloat64 Signal")
	FTbSimpleSimpleArrayInterfaceSigFloat64Delegate OnSigFloat64Signal;
	/// C++ wrapper for BP functions to safely call SigFloat64Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast SigFloat64 Signal")
	void BroadcastSigFloat64Signal(const TArray<double>& ParamFloat64)
	{
		OnSigFloat64Signal.Broadcast(ParamFloat64);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "SigString Signal")
	FTbSimpleSimpleArrayInterfaceSigStringDelegate OnSigStringSignal;
	/// C++ wrapper for BP functions to safely call SigStringSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast SigString Signal")
	void BroadcastSigStringSignal(const TArray<FString>& ParamString)
	{
		OnSigStringSignal.Broadcast(ParamString);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Property PropBool Changed")
	FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate OnPropBoolChanged;
	/// C++ wrapper for BP functions to safely call OnPropBoolChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast Property PropBool Changed")
	void BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const TArray<bool>& InPropBool)
	{
		OnPropBoolChanged.Broadcast(InPropBool);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Property PropInt Changed")
	FTbSimpleSimpleArrayInterfacePropIntChangedDelegate OnPropIntChanged;
	/// C++ wrapper for BP functions to safely call OnPropIntChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast Property PropInt Changed")
	void BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const TArray<int32>& InPropInt)
	{
		OnPropIntChanged.Broadcast(InPropInt);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Property PropInt32 Changed")
	FTbSimpleSimpleArrayInterfacePropInt32ChangedDelegate OnPropInt32Changed;
	/// C++ wrapper for BP functions to safely call OnPropInt32Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast Property PropInt32 Changed")
	void BroadcastPropInt32Changed(UPARAM(DisplayName = "PropInt32") const TArray<int32>& InPropInt32)
	{
		OnPropInt32Changed.Broadcast(InPropInt32);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Property PropInt64 Changed")
	FTbSimpleSimpleArrayInterfacePropInt64ChangedDelegate OnPropInt64Changed;
	/// C++ wrapper for BP functions to safely call OnPropInt64Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast Property PropInt64 Changed")
	void BroadcastPropInt64Changed(UPARAM(DisplayName = "PropInt64") const TArray<int64>& InPropInt64)
	{
		OnPropInt64Changed.Broadcast(InPropInt64);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Property PropFloat Changed")
	FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate OnPropFloatChanged;
	/// C++ wrapper for BP functions to safely call OnPropFloatChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast Property PropFloat Changed")
	void BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const TArray<float>& InPropFloat)
	{
		OnPropFloatChanged.Broadcast(InPropFloat);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Property PropFloat32 Changed")
	FTbSimpleSimpleArrayInterfacePropFloat32ChangedDelegate OnPropFloat32Changed;
	/// C++ wrapper for BP functions to safely call OnPropFloat32Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast Property PropFloat32 Changed")
	void BroadcastPropFloat32Changed(UPARAM(DisplayName = "PropFloat32") const TArray<float>& InPropFloat32)
	{
		OnPropFloat32Changed.Broadcast(InPropFloat32);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Property PropFloat64 Changed")
	FTbSimpleSimpleArrayInterfacePropFloat64ChangedDelegate OnPropFloat64Changed;
	/// C++ wrapper for BP functions to safely call OnPropFloat64Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast Property PropFloat64 Changed")
	void BroadcastPropFloat64Changed(UPARAM(DisplayName = "PropFloat64") const TArray<double>& InPropFloat64)
	{
		OnPropFloat64Changed.Broadcast(InPropFloat64);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Property PropString Changed")
	FTbSimpleSimpleArrayInterfacePropStringChangedDelegate OnPropStringChanged;
	/// C++ wrapper for BP functions to safely call OnPropStringChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast Property PropString Changed")
	void BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const TArray<FString>& InPropString)
	{
		OnPropStringChanged.Broadcast(InPropString);
	}
};

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
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	UTbSimpleSimpleArrayInterfaceSignals* _GetSignals();
	virtual UTbSimpleSimpleArrayInterfaceSignals* _GetSignals_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool);
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	TArray<bool> FuncBool(const TArray<bool>& ParamBool);
	virtual TArray<bool> FuncBool_Implementation(const TArray<bool>& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt);
	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	TArray<int32> FuncInt(const TArray<int32>& ParamInt);
	virtual TArray<int32> FuncInt_Implementation(const TArray<int32>& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncInt32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32);
	virtual void FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	TArray<int32> FuncInt32(const TArray<int32>& ParamInt32);
	virtual TArray<int32> FuncInt32_Implementation(const TArray<int32>& ParamInt32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncInt64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64);
	virtual void FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	TArray<int64> FuncInt64(const TArray<int64>& ParamInt64);
	virtual TArray<int64> FuncInt64_Implementation(const TArray<int64>& ParamInt64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat);
	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	TArray<float> FuncFloat(const TArray<float>& ParamFloat);
	virtual TArray<float> FuncFloat_Implementation(const TArray<float>& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloat32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32);
	virtual void FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	TArray<float> FuncFloat32(const TArray<float>& ParamFloat32);
	virtual TArray<float> FuncFloat32_Implementation(const TArray<float>& ParamFloat32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloat64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat);
	virtual void FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	TArray<double> FuncFloat64(const TArray<double>& ParamFloat);
	virtual TArray<double> FuncFloat64_Implementation(const TArray<double>& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString);
	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	TArray<FString> FuncString(const TArray<FString>& ParamString);
	virtual TArray<FString> FuncString_Implementation(const TArray<FString>& ParamString) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	TArray<bool> GetPropBool() const;
	virtual TArray<bool> GetPropBool_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void SetPropBool(const TArray<bool>& InPropBool);
	virtual void SetPropBool_Implementation(const TArray<bool>& InPropBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	TArray<int32> GetPropInt() const;
	virtual TArray<int32> GetPropInt_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void SetPropInt(const TArray<int32>& InPropInt);
	virtual void SetPropInt_Implementation(const TArray<int32>& InPropInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	TArray<int32> GetPropInt32() const;
	virtual TArray<int32> GetPropInt32_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void SetPropInt32(const TArray<int32>& InPropInt32);
	virtual void SetPropInt32_Implementation(const TArray<int32>& InPropInt32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	TArray<int64> GetPropInt64() const;
	virtual TArray<int64> GetPropInt64_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void SetPropInt64(const TArray<int64>& InPropInt64);
	virtual void SetPropInt64_Implementation(const TArray<int64>& InPropInt64) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	TArray<float> GetPropFloat() const;
	virtual TArray<float> GetPropFloat_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void SetPropFloat(const TArray<float>& InPropFloat);
	virtual void SetPropFloat_Implementation(const TArray<float>& InPropFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	TArray<float> GetPropFloat32() const;
	virtual TArray<float> GetPropFloat32_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void SetPropFloat32(const TArray<float>& InPropFloat32);
	virtual void SetPropFloat32_Implementation(const TArray<float>& InPropFloat32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	TArray<double> GetPropFloat64() const;
	virtual TArray<double> GetPropFloat64_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void SetPropFloat64(const TArray<double>& InPropFloat64);
	virtual void SetPropFloat64_Implementation(const TArray<double>& InPropFloat64) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	TArray<FString> GetPropString() const;
	virtual TArray<FString> GetPropString_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void SetPropString(const TArray<FString>& InPropString);
	virtual void SetPropString_Implementation(const TArray<FString>& InPropString) = 0;
};
