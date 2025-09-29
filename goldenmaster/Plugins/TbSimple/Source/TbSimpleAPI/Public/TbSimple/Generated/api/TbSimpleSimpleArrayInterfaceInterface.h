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
#include "TbSimpleSimpleArrayInterfaceInterface.generated.h"

/**
 * Declaration for SimpleArrayInterface
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigBoolDelegate, const TArray<bool>& /* ParamBool */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigBoolDelegateBP, const TArray<bool>&, ParamBool);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigIntDelegate, const TArray<int32>& /* ParamInt */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigIntDelegateBP, const TArray<int32>&, ParamInt);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigInt32Delegate, const TArray<int32>& /* ParamInt32 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigInt32DelegateBP, const TArray<int32>&, ParamInt32);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigInt64Delegate, const TArray<int64>& /* ParamInt64 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigInt64DelegateBP, const TArray<int64>&, ParamInt64);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigFloatDelegate, const TArray<float>& /* ParamFloat */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigFloatDelegateBP, const TArray<float>&, ParamFloat);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigFloat32Delegate, const TArray<float>& /* ParamFloa32 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigFloat32DelegateBP, const TArray<float>&, ParamFloa32);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigFloat64Delegate, const TArray<double>& /* ParamFloat64 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigFloat64DelegateBP, const TArray<double>&, ParamFloat64);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigStringDelegate, const TArray<FString>& /* ParamString */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigStringDelegateBP, const TArray<FString>&, ParamString);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate, const TArray<bool>& /* PropBool */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropBoolChangedDelegateBP, const TArray<bool>&, PropBool);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropIntChangedDelegate, const TArray<int32>& /* PropInt */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropIntChangedDelegateBP, const TArray<int32>&, PropInt);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropInt32ChangedDelegate, const TArray<int32>& /* PropInt32 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropInt32ChangedDelegateBP, const TArray<int32>&, PropInt32);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropInt64ChangedDelegate, const TArray<int64>& /* PropInt64 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropInt64ChangedDelegateBP, const TArray<int64>&, PropInt64);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate, const TArray<float>& /* PropFloat */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropFloatChangedDelegateBP, const TArray<float>&, PropFloat);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropFloat32ChangedDelegate, const TArray<float>& /* PropFloat32 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropFloat32ChangedDelegateBP, const TArray<float>&, PropFloat32);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropFloat64ChangedDelegate, const TArray<double>& /* PropFloat64 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropFloat64ChangedDelegateBP, const TArray<double>&, PropFloat64);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropStringChangedDelegate, const TArray<FString>& /* PropString */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropStringChangedDelegateBP, const TArray<FString>&, PropString);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropReadOnlyStringChangedDelegate, const FString& /* PropReadOnlyString */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropReadOnlyStringChangedDelegateBP, const FString&, PropReadOnlyString);

/**
 * Subscriber interface for TbSimpleSimpleArrayInterface events. Intended for Blueprint-only use.
 * Does contain signal events and property-changed events.
 * @note Guaranteed to be run from within the GameThread.
 */
UINTERFACE(BlueprintType)
class UTbSimpleSimpleArrayInterfaceBPSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSIMPLEAPI_API ITbSimpleSimpleArrayInterfaceBPSubscriberInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On SigBool Signal")
	void OnSigBoolSignal(const TArray<bool>& ParamBool);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On SigInt Signal")
	void OnSigIntSignal(const TArray<int32>& ParamInt);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On SigInt32 Signal")
	void OnSigInt32Signal(const TArray<int32>& ParamInt32);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On SigInt64 Signal")
	void OnSigInt64Signal(const TArray<int64>& ParamInt64);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On SigFloat Signal")
	void OnSigFloatSignal(const TArray<float>& ParamFloat);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On SigFloat32 Signal")
	void OnSigFloat32Signal(const TArray<float>& ParamFloa32);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On SigFloat64 Signal")
	void OnSigFloat64Signal(const TArray<double>& ParamFloat64);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On SigString Signal")
	void OnSigStringSignal(const TArray<FString>& ParamString);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropBool Changed")
	void OnPropBoolChanged(UPARAM(DisplayName = "PropBool") const TArray<bool>& InPropBool);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropInt Changed")
	void OnPropIntChanged(UPARAM(DisplayName = "PropInt") const TArray<int32>& InPropInt);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropInt32 Changed")
	void OnPropInt32Changed(UPARAM(DisplayName = "PropInt32") const TArray<int32>& InPropInt32);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropInt64 Changed")
	void OnPropInt64Changed(UPARAM(DisplayName = "PropInt64") const TArray<int64>& InPropInt64);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropFloat Changed")
	void OnPropFloatChanged(UPARAM(DisplayName = "PropFloat") const TArray<float>& InPropFloat);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropFloat32 Changed")
	void OnPropFloat32Changed(UPARAM(DisplayName = "PropFloat32") const TArray<float>& InPropFloat32);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropFloat64 Changed")
	void OnPropFloat64Changed(UPARAM(DisplayName = "PropFloat64") const TArray<double>& InPropFloat64);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropString Changed")
	void OnPropStringChanged(UPARAM(DisplayName = "PropString") const TArray<FString>& InPropString);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "On Property PropReadOnlyString Changed")
	void OnPropReadOnlyStringChanged(UPARAM(DisplayName = "PropReadOnlyString") const FString& InPropReadOnlyString);
};

/**
 * Subscriber interface for TbSimpleSimpleArrayInterface events. Intended for C++ use.
 * Does contain signal events and property-changed events.
 * @note Not guaranteed to be run from within the GameThread - can be on any thread.
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSimpleSimpleArrayInterfaceSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSIMPLEAPI_API ITbSimpleSimpleArrayInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	virtual void OnSigBoolSignal(const TArray<bool>& ParamBool) = 0;

	virtual void OnSigIntSignal(const TArray<int32>& ParamInt) = 0;

	virtual void OnSigInt32Signal(const TArray<int32>& ParamInt32) = 0;

	virtual void OnSigInt64Signal(const TArray<int64>& ParamInt64) = 0;

	virtual void OnSigFloatSignal(const TArray<float>& ParamFloat) = 0;

	virtual void OnSigFloat32Signal(const TArray<float>& ParamFloa32) = 0;

	virtual void OnSigFloat64Signal(const TArray<double>& ParamFloat64) = 0;

	virtual void OnSigStringSignal(const TArray<FString>& ParamString) = 0;

	virtual void OnPropBoolChanged(UPARAM(DisplayName = "PropBool") const TArray<bool>& InPropBool) = 0;

	virtual void OnPropIntChanged(UPARAM(DisplayName = "PropInt") const TArray<int32>& InPropInt) = 0;

	virtual void OnPropInt32Changed(UPARAM(DisplayName = "PropInt32") const TArray<int32>& InPropInt32) = 0;

	virtual void OnPropInt64Changed(UPARAM(DisplayName = "PropInt64") const TArray<int64>& InPropInt64) = 0;

	virtual void OnPropFloatChanged(UPARAM(DisplayName = "PropFloat") const TArray<float>& InPropFloat) = 0;

	virtual void OnPropFloat32Changed(UPARAM(DisplayName = "PropFloat32") const TArray<float>& InPropFloat32) = 0;

	virtual void OnPropFloat64Changed(UPARAM(DisplayName = "PropFloat64") const TArray<double>& InPropFloat64) = 0;

	virtual void OnPropStringChanged(UPARAM(DisplayName = "PropString") const TArray<FString>& InPropString) = 0;

	virtual void OnPropReadOnlyStringChanged(UPARAM(DisplayName = "PropReadOnlyString") const FString& InPropReadOnlyString) = 0;
};

/**
 * Class UTbSimpleSimpleArrayInterfaceInterfacePublisher
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBSIMPLEAPI_API UTbSimpleSimpleArrayInterfacePublisher : public UObject
{
	GENERATED_BODY()

public:
	FTbSimpleSimpleArrayInterfaceSigBoolDelegate OnSigBoolSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "SigBool Signal")
	FTbSimpleSimpleArrayInterfaceSigBoolDelegateBP OnSigBoolSignalBP;
	/// C++ wrapper for BP functions to safely call SigBoolSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast SigBool Signal")
	void BroadcastSigBoolSignal(const TArray<bool>& ParamBool);

	FTbSimpleSimpleArrayInterfaceSigIntDelegate OnSigIntSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "SigInt Signal")
	FTbSimpleSimpleArrayInterfaceSigIntDelegateBP OnSigIntSignalBP;
	/// C++ wrapper for BP functions to safely call SigIntSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast SigInt Signal")
	void BroadcastSigIntSignal(const TArray<int32>& ParamInt);

	FTbSimpleSimpleArrayInterfaceSigInt32Delegate OnSigInt32Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "SigInt32 Signal")
	FTbSimpleSimpleArrayInterfaceSigInt32DelegateBP OnSigInt32SignalBP;
	/// C++ wrapper for BP functions to safely call SigInt32Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast SigInt32 Signal")
	void BroadcastSigInt32Signal(const TArray<int32>& ParamInt32);

	FTbSimpleSimpleArrayInterfaceSigInt64Delegate OnSigInt64Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "SigInt64 Signal")
	FTbSimpleSimpleArrayInterfaceSigInt64DelegateBP OnSigInt64SignalBP;
	/// C++ wrapper for BP functions to safely call SigInt64Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast SigInt64 Signal")
	void BroadcastSigInt64Signal(const TArray<int64>& ParamInt64);

	FTbSimpleSimpleArrayInterfaceSigFloatDelegate OnSigFloatSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "SigFloat Signal")
	FTbSimpleSimpleArrayInterfaceSigFloatDelegateBP OnSigFloatSignalBP;
	/// C++ wrapper for BP functions to safely call SigFloatSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast SigFloat Signal")
	void BroadcastSigFloatSignal(const TArray<float>& ParamFloat);

	FTbSimpleSimpleArrayInterfaceSigFloat32Delegate OnSigFloat32Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "SigFloat32 Signal")
	FTbSimpleSimpleArrayInterfaceSigFloat32DelegateBP OnSigFloat32SignalBP;
	/// C++ wrapper for BP functions to safely call SigFloat32Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast SigFloat32 Signal")
	void BroadcastSigFloat32Signal(const TArray<float>& ParamFloa32);

	FTbSimpleSimpleArrayInterfaceSigFloat64Delegate OnSigFloat64Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "SigFloat64 Signal")
	FTbSimpleSimpleArrayInterfaceSigFloat64DelegateBP OnSigFloat64SignalBP;
	/// C++ wrapper for BP functions to safely call SigFloat64Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast SigFloat64 Signal")
	void BroadcastSigFloat64Signal(const TArray<double>& ParamFloat64);

	FTbSimpleSimpleArrayInterfaceSigStringDelegate OnSigStringSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "SigString Signal")
	FTbSimpleSimpleArrayInterfaceSigStringDelegateBP OnSigStringSignalBP;
	/// C++ wrapper for BP functions to safely call SigStringSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast SigString Signal")
	void BroadcastSigStringSignal(const TArray<FString>& ParamString);

	FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate OnPropBoolChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Property PropBool Changed")
	FTbSimpleSimpleArrayInterfacePropBoolChangedDelegateBP OnPropBoolChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropBoolChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast Property PropBool Changed")
	void BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const TArray<bool>& InPropBool);

	FTbSimpleSimpleArrayInterfacePropIntChangedDelegate OnPropIntChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Property PropInt Changed")
	FTbSimpleSimpleArrayInterfacePropIntChangedDelegateBP OnPropIntChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropIntChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast Property PropInt Changed")
	void BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const TArray<int32>& InPropInt);

	FTbSimpleSimpleArrayInterfacePropInt32ChangedDelegate OnPropInt32Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Property PropInt32 Changed")
	FTbSimpleSimpleArrayInterfacePropInt32ChangedDelegateBP OnPropInt32ChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropInt32Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast Property PropInt32 Changed")
	void BroadcastPropInt32Changed(UPARAM(DisplayName = "PropInt32") const TArray<int32>& InPropInt32);

	FTbSimpleSimpleArrayInterfacePropInt64ChangedDelegate OnPropInt64Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Property PropInt64 Changed")
	FTbSimpleSimpleArrayInterfacePropInt64ChangedDelegateBP OnPropInt64ChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropInt64Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast Property PropInt64 Changed")
	void BroadcastPropInt64Changed(UPARAM(DisplayName = "PropInt64") const TArray<int64>& InPropInt64);

	FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate OnPropFloatChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Property PropFloat Changed")
	FTbSimpleSimpleArrayInterfacePropFloatChangedDelegateBP OnPropFloatChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropFloatChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast Property PropFloat Changed")
	void BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const TArray<float>& InPropFloat);

	FTbSimpleSimpleArrayInterfacePropFloat32ChangedDelegate OnPropFloat32Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Property PropFloat32 Changed")
	FTbSimpleSimpleArrayInterfacePropFloat32ChangedDelegateBP OnPropFloat32ChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropFloat32Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast Property PropFloat32 Changed")
	void BroadcastPropFloat32Changed(UPARAM(DisplayName = "PropFloat32") const TArray<float>& InPropFloat32);

	FTbSimpleSimpleArrayInterfacePropFloat64ChangedDelegate OnPropFloat64Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Property PropFloat64 Changed")
	FTbSimpleSimpleArrayInterfacePropFloat64ChangedDelegateBP OnPropFloat64ChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropFloat64Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast Property PropFloat64 Changed")
	void BroadcastPropFloat64Changed(UPARAM(DisplayName = "PropFloat64") const TArray<double>& InPropFloat64);

	FTbSimpleSimpleArrayInterfacePropStringChangedDelegate OnPropStringChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Property PropString Changed")
	FTbSimpleSimpleArrayInterfacePropStringChangedDelegateBP OnPropStringChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropStringChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast Property PropString Changed")
	void BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const TArray<FString>& InPropString);

	FTbSimpleSimpleArrayInterfacePropReadOnlyStringChangedDelegate OnPropReadOnlyStringChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Property PropReadOnlyString Changed")
	FTbSimpleSimpleArrayInterfacePropReadOnlyStringChangedDelegateBP OnPropReadOnlyStringChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropReadOnlyStringChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", DisplayName = "Broadcast Property PropReadOnlyString Changed")
	void BroadcastPropReadOnlyStringChanged(UPARAM(DisplayName = "PropReadOnlyString") const FString& InPropReadOnlyString);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	void Subscribe(const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber);
	void Subscribe(const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	void Unsubscribe(const TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>& Subscriber);
	void Unsubscribe(const TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>& Subscriber);

private:
	void CleanUpSubscribers();

	TArray<TScriptInterface<ITbSimpleSimpleArrayInterfaceBPSubscriberInterface>> BPSubscribers;
	FRWLock BPSubscribersLock;
	TArray<TWeakInterfacePtr<ITbSimpleSimpleArrayInterfaceSubscriberInterface>> Subscribers;
	FRWLock SubscribersLock;
};

/**
 * Interface UTbSimpleSimpleArrayInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSimpleSimpleArrayInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSimpleSimpleArrayInterfaceInterface
 */
class TBSIMPLEAPI_API ITbSimpleSimpleArrayInterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual UTbSimpleSimpleArrayInterfacePublisher* _GetPublisher() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool) = 0;
	virtual TFuture<TArray<bool>> FuncBoolAsync(const TArray<bool>& ParamBool) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	virtual TArray<bool> FuncBool(const TArray<bool>& ParamBool) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt) = 0;
	virtual TFuture<TArray<int32>> FuncIntAsync(const TArray<int32>& ParamInt) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	virtual TArray<int32> FuncInt(const TArray<int32>& ParamInt) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncInt32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32) = 0;
	virtual TFuture<TArray<int32>> FuncInt32Async(const TArray<int32>& ParamInt32) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	virtual TArray<int32> FuncInt32(const TArray<int32>& ParamInt32) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncInt64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64) = 0;
	virtual TFuture<TArray<int64>> FuncInt64Async(const TArray<int64>& ParamInt64) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	virtual TArray<int64> FuncInt64(const TArray<int64>& ParamInt64) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat) = 0;
	virtual TFuture<TArray<float>> FuncFloatAsync(const TArray<float>& ParamFloat) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	virtual TArray<float> FuncFloat(const TArray<float>& ParamFloat) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncFloat32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32) = 0;
	virtual TFuture<TArray<float>> FuncFloat32Async(const TArray<float>& ParamFloat32) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	virtual TArray<float> FuncFloat32(const TArray<float>& ParamFloat32) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncFloat64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat) = 0;
	virtual TFuture<TArray<double>> FuncFloat64Async(const TArray<double>& ParamFloat) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	virtual TArray<double> FuncFloat64(const TArray<double>& ParamFloat) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString) = 0;
	virtual TFuture<TArray<FString>> FuncStringAsync(const TArray<FString>& ParamString) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	virtual TArray<FString> FuncString(const TArray<FString>& ParamString) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	virtual TArray<bool> GetPropBool() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	virtual void SetPropBool(UPARAM(DisplayName = "PropBool") const TArray<bool>& InPropBool) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	virtual TArray<int32> GetPropInt() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	virtual void SetPropInt(UPARAM(DisplayName = "PropInt") const TArray<int32>& InPropInt) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	virtual TArray<int32> GetPropInt32() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	virtual void SetPropInt32(UPARAM(DisplayName = "PropInt32") const TArray<int32>& InPropInt32) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	virtual TArray<int64> GetPropInt64() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	virtual void SetPropInt64(UPARAM(DisplayName = "PropInt64") const TArray<int64>& InPropInt64) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	virtual TArray<float> GetPropFloat() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	virtual void SetPropFloat(UPARAM(DisplayName = "PropFloat") const TArray<float>& InPropFloat) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	virtual TArray<float> GetPropFloat32() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	virtual void SetPropFloat32(UPARAM(DisplayName = "PropFloat32") const TArray<float>& InPropFloat32) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	virtual TArray<double> GetPropFloat64() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	virtual void SetPropFloat64(UPARAM(DisplayName = "PropFloat64") const TArray<double>& InPropFloat64) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	virtual TArray<FString> GetPropString() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	virtual void SetPropString(UPARAM(DisplayName = "PropString") const TArray<FString>& InPropString) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	virtual FString GetPropReadOnlyString() const = 0;
};
