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
#include "Async/Future.h"
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "Misc/ScopeRWLock.h"
#include "UObject/WeakInterfacePtr.h"
#include "TbSimple_data.h"
#include "TbSimpleSimpleInterfaceInterface.generated.h"

/**
 * Declaration for SimpleInterface
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigBoolDelegate, bool /* bParamBool */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigBoolDelegateBP, bool, bParamBool);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigIntDelegate, int32 /* ParamInt */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigIntDelegateBP, int32, ParamInt);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigInt32Delegate, int32 /* ParamInt32 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigInt32DelegateBP, int32, ParamInt32);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigInt64Delegate, int64 /* ParamInt64 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigInt64DelegateBP, int64, ParamInt64);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigFloatDelegate, float /* ParamFloat */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigFloatDelegateBP, float, ParamFloat);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigFloat32Delegate, float /* ParamFloat32 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigFloat32DelegateBP, float, ParamFloat32);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigFloat64Delegate, double /* ParamFloat64 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigFloat64DelegateBP, double, ParamFloat64);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigStringDelegate, const FString& /* ParamString */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigStringDelegateBP, const FString&, ParamString);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropBoolChangedDelegate, bool /* bPropBool */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropBoolChangedDelegateBP, bool, bPropBool);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropIntChangedDelegate, int32 /* PropInt */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropIntChangedDelegateBP, int32, PropInt);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropInt32ChangedDelegate, int32 /* PropInt32 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropInt32ChangedDelegateBP, int32, PropInt32);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropInt64ChangedDelegate, int64 /* PropInt64 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropInt64ChangedDelegateBP, int64, PropInt64);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropFloatChangedDelegate, float /* PropFloat */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropFloatChangedDelegateBP, float, PropFloat);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropFloat32ChangedDelegate, float /* PropFloat32 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropFloat32ChangedDelegateBP, float, PropFloat32);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropFloat64ChangedDelegate, double /* PropFloat64 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropFloat64ChangedDelegateBP, double, PropFloat64);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropStringChangedDelegate, const FString& /* PropString */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropStringChangedDelegateBP, const FString&, PropString);

/**
 * Subscriber interface for TbSimpleSimpleInterface events. Intended for Blueprint-only use.
 * Does contain signal events and property-changed events.
 * @note Guaranteed to be run from within the GameThread.
 */
UINTERFACE(BlueprintType)
class UTbSimpleSimpleInterfaceBPSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSIMPLEAPI_API ITbSimpleSimpleInterfaceBPSubscriberInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "On SigBool Signal")
	void OnSigBoolSignal(bool bParamBool);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "On SigInt Signal")
	void OnSigIntSignal(int32 ParamInt);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "On SigInt32 Signal")
	void OnSigInt32Signal(int32 ParamInt32);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "On SigInt64 Signal")
	void OnSigInt64Signal(int64 ParamInt64);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "On SigFloat Signal")
	void OnSigFloatSignal(float ParamFloat);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "On SigFloat32 Signal")
	void OnSigFloat32Signal(float ParamFloat32);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "On SigFloat64 Signal")
	void OnSigFloat64Signal(double ParamFloat64);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "On SigString Signal")
	void OnSigStringSignal(const FString& ParamString);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "On Property PropBool Changed")
	void OnPropBoolChanged(UPARAM(DisplayName = "bPropBool") bool bInPropBool);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "On Property PropInt Changed")
	void OnPropIntChanged(UPARAM(DisplayName = "PropInt") int32 InPropInt);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "On Property PropInt32 Changed")
	void OnPropInt32Changed(UPARAM(DisplayName = "PropInt32") int32 InPropInt32);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "On Property PropInt64 Changed")
	void OnPropInt64Changed(UPARAM(DisplayName = "PropInt64") int64 InPropInt64);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "On Property PropFloat Changed")
	void OnPropFloatChanged(UPARAM(DisplayName = "PropFloat") float InPropFloat);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "On Property PropFloat32 Changed")
	void OnPropFloat32Changed(UPARAM(DisplayName = "PropFloat32") float InPropFloat32);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "On Property PropFloat64 Changed")
	void OnPropFloat64Changed(UPARAM(DisplayName = "PropFloat64") double InPropFloat64);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "On Property PropString Changed")
	void OnPropStringChanged(UPARAM(DisplayName = "PropString") const FString& InPropString);
};

/**
 * Subscriber interface for TbSimpleSimpleInterface events. Intended for C++ use.
 * Does contain signal events and property-changed events.
 * @note Not guaranteed to be run from within the GameThread - can be on any thread.
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSimpleSimpleInterfaceSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSIMPLEAPI_API ITbSimpleSimpleInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	virtual void OnSigBoolSignal(bool bParamBool) = 0;

	virtual void OnSigIntSignal(int32 ParamInt) = 0;

	virtual void OnSigInt32Signal(int32 ParamInt32) = 0;

	virtual void OnSigInt64Signal(int64 ParamInt64) = 0;

	virtual void OnSigFloatSignal(float ParamFloat) = 0;

	virtual void OnSigFloat32Signal(float ParamFloat32) = 0;

	virtual void OnSigFloat64Signal(double ParamFloat64) = 0;

	virtual void OnSigStringSignal(const FString& ParamString) = 0;

	virtual void OnPropBoolChanged(UPARAM(DisplayName = "bPropBool") bool bInPropBool) = 0;

	virtual void OnPropIntChanged(UPARAM(DisplayName = "PropInt") int32 InPropInt) = 0;

	virtual void OnPropInt32Changed(UPARAM(DisplayName = "PropInt32") int32 InPropInt32) = 0;

	virtual void OnPropInt64Changed(UPARAM(DisplayName = "PropInt64") int64 InPropInt64) = 0;

	virtual void OnPropFloatChanged(UPARAM(DisplayName = "PropFloat") float InPropFloat) = 0;

	virtual void OnPropFloat32Changed(UPARAM(DisplayName = "PropFloat32") float InPropFloat32) = 0;

	virtual void OnPropFloat64Changed(UPARAM(DisplayName = "PropFloat64") double InPropFloat64) = 0;

	virtual void OnPropStringChanged(UPARAM(DisplayName = "PropString") const FString& InPropString) = 0;
};

/**
 * Class UTbSimpleSimpleInterfaceInterfacePublisher
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBSIMPLEAPI_API UTbSimpleSimpleInterfacePublisher : public UObject
{
	GENERATED_BODY()

public:
	FTbSimpleSimpleInterfaceSigBoolDelegate OnSigBoolSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "SigBool Signal")
	FTbSimpleSimpleInterfaceSigBoolDelegateBP OnSigBoolSignalBP;
	/// C++ wrapper for BP functions to safely call SigBoolSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Broadcast SigBool Signal")
	void BroadcastSigBoolSignal(bool bParamBool);

	FTbSimpleSimpleInterfaceSigIntDelegate OnSigIntSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "SigInt Signal")
	FTbSimpleSimpleInterfaceSigIntDelegateBP OnSigIntSignalBP;
	/// C++ wrapper for BP functions to safely call SigIntSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Broadcast SigInt Signal")
	void BroadcastSigIntSignal(int32 ParamInt);

	FTbSimpleSimpleInterfaceSigInt32Delegate OnSigInt32Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "SigInt32 Signal")
	FTbSimpleSimpleInterfaceSigInt32DelegateBP OnSigInt32SignalBP;
	/// C++ wrapper for BP functions to safely call SigInt32Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Broadcast SigInt32 Signal")
	void BroadcastSigInt32Signal(int32 ParamInt32);

	FTbSimpleSimpleInterfaceSigInt64Delegate OnSigInt64Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "SigInt64 Signal")
	FTbSimpleSimpleInterfaceSigInt64DelegateBP OnSigInt64SignalBP;
	/// C++ wrapper for BP functions to safely call SigInt64Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Broadcast SigInt64 Signal")
	void BroadcastSigInt64Signal(int64 ParamInt64);

	FTbSimpleSimpleInterfaceSigFloatDelegate OnSigFloatSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "SigFloat Signal")
	FTbSimpleSimpleInterfaceSigFloatDelegateBP OnSigFloatSignalBP;
	/// C++ wrapper for BP functions to safely call SigFloatSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Broadcast SigFloat Signal")
	void BroadcastSigFloatSignal(float ParamFloat);

	FTbSimpleSimpleInterfaceSigFloat32Delegate OnSigFloat32Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "SigFloat32 Signal")
	FTbSimpleSimpleInterfaceSigFloat32DelegateBP OnSigFloat32SignalBP;
	/// C++ wrapper for BP functions to safely call SigFloat32Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Broadcast SigFloat32 Signal")
	void BroadcastSigFloat32Signal(float ParamFloat32);

	FTbSimpleSimpleInterfaceSigFloat64Delegate OnSigFloat64Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "SigFloat64 Signal")
	FTbSimpleSimpleInterfaceSigFloat64DelegateBP OnSigFloat64SignalBP;
	/// C++ wrapper for BP functions to safely call SigFloat64Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Broadcast SigFloat64 Signal")
	void BroadcastSigFloat64Signal(double ParamFloat64);

	FTbSimpleSimpleInterfaceSigStringDelegate OnSigStringSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "SigString Signal")
	FTbSimpleSimpleInterfaceSigStringDelegateBP OnSigStringSignalBP;
	/// C++ wrapper for BP functions to safely call SigStringSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Broadcast SigString Signal")
	void BroadcastSigStringSignal(const FString& ParamString);

	FTbSimpleSimpleInterfacePropBoolChangedDelegate OnPropBoolChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Property PropBool Changed")
	FTbSimpleSimpleInterfacePropBoolChangedDelegateBP OnPropBoolChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropBoolChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Broadcast Property PropBool Changed")
	void BroadcastPropBoolChanged(UPARAM(DisplayName = "bPropBool") bool bInPropBool);

	FTbSimpleSimpleInterfacePropIntChangedDelegate OnPropIntChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Property PropInt Changed")
	FTbSimpleSimpleInterfacePropIntChangedDelegateBP OnPropIntChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropIntChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Broadcast Property PropInt Changed")
	void BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") int32 InPropInt);

	FTbSimpleSimpleInterfacePropInt32ChangedDelegate OnPropInt32Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Property PropInt32 Changed")
	FTbSimpleSimpleInterfacePropInt32ChangedDelegateBP OnPropInt32ChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropInt32Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Broadcast Property PropInt32 Changed")
	void BroadcastPropInt32Changed(UPARAM(DisplayName = "PropInt32") int32 InPropInt32);

	FTbSimpleSimpleInterfacePropInt64ChangedDelegate OnPropInt64Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Property PropInt64 Changed")
	FTbSimpleSimpleInterfacePropInt64ChangedDelegateBP OnPropInt64ChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropInt64Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Broadcast Property PropInt64 Changed")
	void BroadcastPropInt64Changed(UPARAM(DisplayName = "PropInt64") int64 InPropInt64);

	FTbSimpleSimpleInterfacePropFloatChangedDelegate OnPropFloatChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Property PropFloat Changed")
	FTbSimpleSimpleInterfacePropFloatChangedDelegateBP OnPropFloatChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropFloatChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Broadcast Property PropFloat Changed")
	void BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") float InPropFloat);

	FTbSimpleSimpleInterfacePropFloat32ChangedDelegate OnPropFloat32Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Property PropFloat32 Changed")
	FTbSimpleSimpleInterfacePropFloat32ChangedDelegateBP OnPropFloat32ChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropFloat32Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Broadcast Property PropFloat32 Changed")
	void BroadcastPropFloat32Changed(UPARAM(DisplayName = "PropFloat32") float InPropFloat32);

	FTbSimpleSimpleInterfacePropFloat64ChangedDelegate OnPropFloat64Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Property PropFloat64 Changed")
	FTbSimpleSimpleInterfacePropFloat64ChangedDelegateBP OnPropFloat64ChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropFloat64Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Broadcast Property PropFloat64 Changed")
	void BroadcastPropFloat64Changed(UPARAM(DisplayName = "PropFloat64") double InPropFloat64);

	FTbSimpleSimpleInterfacePropStringChangedDelegate OnPropStringChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Property PropString Changed")
	FTbSimpleSimpleInterfacePropStringChangedDelegateBP OnPropStringChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropStringChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Broadcast Property PropString Changed")
	void BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const FString& InPropString);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals")
	void Subscribe(const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber);
	void Subscribe(const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals")
	void Unsubscribe(const TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>& Subscriber);
	void Unsubscribe(const TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>& Subscriber);

private:
	void CleanUpSubscribers();

	TArray<TScriptInterface<ITbSimpleSimpleInterfaceBPSubscriberInterface>> BPSubscribers;
	FRWLock BPSubscribersLock;
	TArray<TWeakInterfacePtr<ITbSimpleSimpleInterfaceSubscriberInterface>> Subscribers;
	FRWLock SubscribersLock;
};

/**
 * Interface UTbSimpleSimpleInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSimpleSimpleInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSimpleSimpleInterfaceInterface
 */
class TBSIMPLEAPI_API ITbSimpleSimpleInterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	virtual UTbSimpleSimpleInterfacePublisher* _GetPublisher() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	virtual void FuncNoReturnValue(bool bParamBool) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncNoParamsAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result) = 0;
	virtual TFuture<bool> FuncNoParamsAsync() = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	virtual bool FuncNoParams() = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) = 0;
	virtual TFuture<bool> FuncBoolAsync(bool bParamBool) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	virtual bool FuncBool(bool bParamBool) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt) = 0;
	virtual TFuture<int32> FuncIntAsync(int32 ParamInt) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	virtual int32 FuncInt(int32 ParamInt) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncInt32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt32) = 0;
	virtual TFuture<int32> FuncInt32Async(int32 ParamInt32) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	virtual int32 FuncInt32(int32 ParamInt32) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncInt64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int64& Result, int64 ParamInt64) = 0;
	virtual TFuture<int64> FuncInt64Async(int64 ParamInt64) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	virtual int64 FuncInt64(int64 ParamInt64) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat) = 0;
	virtual TFuture<float> FuncFloatAsync(float ParamFloat) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	virtual float FuncFloat(float ParamFloat) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncFloat32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat32) = 0;
	virtual TFuture<float> FuncFloat32Async(float ParamFloat32) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	virtual float FuncFloat32(float ParamFloat32) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncFloat64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, double& Result, double ParamFloat) = 0;
	virtual TFuture<double> FuncFloat64Async(double ParamFloat) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	virtual double FuncFloat64(double ParamFloat) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString) = 0;
	virtual TFuture<FString> FuncStringAsync(const FString& ParamString) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	virtual FString FuncString(const FString& ParamString) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	virtual bool GetPropBool() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	virtual void SetPropBool(UPARAM(DisplayName = "bPropBool") bool bInPropBool) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	virtual int32 GetPropInt() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	virtual void SetPropInt(UPARAM(DisplayName = "PropInt") int32 InPropInt) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	virtual int32 GetPropInt32() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	virtual void SetPropInt32(UPARAM(DisplayName = "PropInt32") int32 InPropInt32) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	virtual int64 GetPropInt64() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	virtual void SetPropInt64(UPARAM(DisplayName = "PropInt64") int64 InPropInt64) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	virtual float GetPropFloat() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	virtual void SetPropFloat(UPARAM(DisplayName = "PropFloat") float InPropFloat) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	virtual float GetPropFloat32() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	virtual void SetPropFloat32(UPARAM(DisplayName = "PropFloat32") float InPropFloat32) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	virtual double GetPropFloat64() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	virtual void SetPropFloat64(UPARAM(DisplayName = "PropFloat64") double InPropFloat64) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	virtual FString GetPropString() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	virtual void SetPropString(UPARAM(DisplayName = "PropString") const FString& InPropString) = 0;
};
