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
#include "Misc/ScopeRWLock.h"
#include "UObject/WeakInterfacePtr.h"
#include "Testbed1_data.h"
#include "Testbed1StructArray2InterfaceInterface.generated.h"

/**
 * Declaration for StructArray2Interface
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceSigBoolDelegate, const FTestbed1StructBoolWithArray& /* ParamBool */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceSigBoolDelegateBP, const FTestbed1StructBoolWithArray&, ParamBool);

DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceSigIntDelegate, const FTestbed1StructIntWithArray& /* ParamInt */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceSigIntDelegateBP, const FTestbed1StructIntWithArray&, ParamInt);

DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceSigFloatDelegate, const FTestbed1StructFloatWithArray& /* ParamFloat */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceSigFloatDelegateBP, const FTestbed1StructFloatWithArray&, ParamFloat);

DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceSigStringDelegate, const FTestbed1StructStringWithArray& /* ParamString */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceSigStringDelegateBP, const FTestbed1StructStringWithArray&, ParamString);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfacePropBoolChangedDelegate, const FTestbed1StructBoolWithArray& /* PropBool */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfacePropBoolChangedDelegateBP, const FTestbed1StructBoolWithArray&, PropBool);
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfacePropIntChangedDelegate, const FTestbed1StructIntWithArray& /* PropInt */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfacePropIntChangedDelegateBP, const FTestbed1StructIntWithArray&, PropInt);
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfacePropFloatChangedDelegate, const FTestbed1StructFloatWithArray& /* PropFloat */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfacePropFloatChangedDelegateBP, const FTestbed1StructFloatWithArray&, PropFloat);
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfacePropStringChangedDelegate, const FTestbed1StructStringWithArray& /* PropString */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfacePropStringChangedDelegateBP, const FTestbed1StructStringWithArray&, PropString);
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfacePropEnumChangedDelegate, const FTestbed1StructEnumWithArray& /* PropEnum */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfacePropEnumChangedDelegateBP, const FTestbed1StructEnumWithArray&, PropEnum);

/**
 * Helper interface for Testbed1StructArray2Interface events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events and property-changed events.
 */
UINTERFACE(BlueprintType)
class UTestbed1StructArray2InterfaceBPSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TESTBED1API_API ITestbed1StructArray2InterfaceBPSubscriberInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "On SigBool Signal")
	void OnSigBoolSignal(const FTestbed1StructBoolWithArray& ParamBool);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "On SigInt Signal")
	void OnSigIntSignal(const FTestbed1StructIntWithArray& ParamInt);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "On SigFloat Signal")
	void OnSigFloatSignal(const FTestbed1StructFloatWithArray& ParamFloat);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "On SigString Signal")
	void OnSigStringSignal(const FTestbed1StructStringWithArray& ParamString);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "On Property PropBool Changed")
	void OnPropBoolChanged(UPARAM(DisplayName = "PropBool") const FTestbed1StructBoolWithArray& InPropBool);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "On Property PropInt Changed")
	void OnPropIntChanged(UPARAM(DisplayName = "PropInt") const FTestbed1StructIntWithArray& InPropInt);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "On Property PropFloat Changed")
	void OnPropFloatChanged(UPARAM(DisplayName = "PropFloat") const FTestbed1StructFloatWithArray& InPropFloat);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "On Property PropString Changed")
	void OnPropStringChanged(UPARAM(DisplayName = "PropString") const FTestbed1StructStringWithArray& InPropString);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "On Property PropEnum Changed")
	void OnPropEnumChanged(UPARAM(DisplayName = "PropEnum") const FTestbed1StructEnumWithArray& InPropEnum);
};

UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTestbed1StructArray2InterfaceSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TESTBED1API_API ITestbed1StructArray2InterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	virtual void OnSigBoolSignal(const FTestbed1StructBoolWithArray& ParamBool) = 0;

	virtual void OnSigIntSignal(const FTestbed1StructIntWithArray& ParamInt) = 0;

	virtual void OnSigFloatSignal(const FTestbed1StructFloatWithArray& ParamFloat) = 0;

	virtual void OnSigStringSignal(const FTestbed1StructStringWithArray& ParamString) = 0;

	virtual void OnPropBoolChanged(UPARAM(DisplayName = "PropBool") const FTestbed1StructBoolWithArray& InPropBool) = 0;

	virtual void OnPropIntChanged(UPARAM(DisplayName = "PropInt") const FTestbed1StructIntWithArray& InPropInt) = 0;

	virtual void OnPropFloatChanged(UPARAM(DisplayName = "PropFloat") const FTestbed1StructFloatWithArray& InPropFloat) = 0;

	virtual void OnPropStringChanged(UPARAM(DisplayName = "PropString") const FTestbed1StructStringWithArray& InPropString) = 0;

	virtual void OnPropEnumChanged(UPARAM(DisplayName = "PropEnum") const FTestbed1StructEnumWithArray& InPropEnum) = 0;
};

/**
 * Class UTestbed1StructArray2InterfaceInterfacePublisher
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TESTBED1API_API UTestbed1StructArray2InterfacePublisher : public UObject
{
	GENERATED_BODY()

public:
	FTestbed1StructArray2InterfaceSigBoolDelegate OnSigBoolSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "SigBool Signal")
	FTestbed1StructArray2InterfaceSigBoolDelegateBP OnSigBoolSignalBP;
	/// C++ wrapper for BP functions to safely call SigBoolSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast SigBool Signal")
	void BroadcastSigBoolSignal(const FTestbed1StructBoolWithArray& ParamBool);

	FTestbed1StructArray2InterfaceSigIntDelegate OnSigIntSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "SigInt Signal")
	FTestbed1StructArray2InterfaceSigIntDelegateBP OnSigIntSignalBP;
	/// C++ wrapper for BP functions to safely call SigIntSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast SigInt Signal")
	void BroadcastSigIntSignal(const FTestbed1StructIntWithArray& ParamInt);

	FTestbed1StructArray2InterfaceSigFloatDelegate OnSigFloatSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "SigFloat Signal")
	FTestbed1StructArray2InterfaceSigFloatDelegateBP OnSigFloatSignalBP;
	/// C++ wrapper for BP functions to safely call SigFloatSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast SigFloat Signal")
	void BroadcastSigFloatSignal(const FTestbed1StructFloatWithArray& ParamFloat);

	FTestbed1StructArray2InterfaceSigStringDelegate OnSigStringSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "SigString Signal")
	FTestbed1StructArray2InterfaceSigStringDelegateBP OnSigStringSignalBP;
	/// C++ wrapper for BP functions to safely call SigStringSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast SigString Signal")
	void BroadcastSigStringSignal(const FTestbed1StructStringWithArray& ParamString);

	FTestbed1StructArray2InterfacePropBoolChangedDelegate OnPropBoolChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Property PropBool Changed")
	FTestbed1StructArray2InterfacePropBoolChangedDelegateBP OnPropBoolChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropBoolChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast Property PropBool Changed")
	void BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const FTestbed1StructBoolWithArray& InPropBool);

	FTestbed1StructArray2InterfacePropIntChangedDelegate OnPropIntChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Property PropInt Changed")
	FTestbed1StructArray2InterfacePropIntChangedDelegateBP OnPropIntChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropIntChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast Property PropInt Changed")
	void BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const FTestbed1StructIntWithArray& InPropInt);

	FTestbed1StructArray2InterfacePropFloatChangedDelegate OnPropFloatChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Property PropFloat Changed")
	FTestbed1StructArray2InterfacePropFloatChangedDelegateBP OnPropFloatChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropFloatChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast Property PropFloat Changed")
	void BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const FTestbed1StructFloatWithArray& InPropFloat);

	FTestbed1StructArray2InterfacePropStringChangedDelegate OnPropStringChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Property PropString Changed")
	FTestbed1StructArray2InterfacePropStringChangedDelegateBP OnPropStringChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropStringChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast Property PropString Changed")
	void BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const FTestbed1StructStringWithArray& InPropString);

	FTestbed1StructArray2InterfacePropEnumChangedDelegate OnPropEnumChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Property PropEnum Changed")
	FTestbed1StructArray2InterfacePropEnumChangedDelegateBP OnPropEnumChangedBP;
	/// C++ wrapper for BP functions to safely call OnPropEnumChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast Property PropEnum Changed")
	void BroadcastPropEnumChanged(UPARAM(DisplayName = "PropEnum") const FTestbed1StructEnumWithArray& InPropEnum);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals")
	void Subscribe(const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber);
	void Subscribe(const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals")
	void Unsubscribe(const TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>& Subscriber);
	void Unsubscribe(const TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>& Subscriber);

private:
	UPROPERTY()
	TArray<TScriptInterface<ITestbed1StructArray2InterfaceBPSubscriberInterface>> BPSubscribers;
	FRWLock BPSubscribersLock;
	TArray<TWeakInterfacePtr<ITestbed1StructArray2InterfaceSubscriberInterface>> Subscribers;
	FRWLock SubscribersLock;
};

/**
 * Interface UTestbed1StructArray2InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTestbed1StructArray2InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed1StructArray2InterfaceInterface
 */
class TESTBED1API_API ITestbed1StructArray2InterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface")
	virtual UTestbed1StructArray2InterfacePublisher* _GetPublisher() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructBool>& Result, const FTestbed1StructBoolWithArray& ParamBool) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations")
	virtual TArray<FTestbed1StructBool> FuncBool(const FTestbed1StructBoolWithArray& ParamBool) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructInt>& Result, const FTestbed1StructIntWithArray& ParamInt) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations")
	virtual TArray<FTestbed1StructInt> FuncInt(const FTestbed1StructIntWithArray& ParamInt) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructFloat>& Result, const FTestbed1StructFloatWithArray& ParamFloat) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations")
	virtual TArray<FTestbed1StructFloat> FuncFloat(const FTestbed1StructFloatWithArray& ParamFloat) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructString>& Result, const FTestbed1StructStringWithArray& ParamString) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations")
	virtual TArray<FTestbed1StructString> FuncString(const FTestbed1StructStringWithArray& ParamString) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncEnumAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<ETestbed1Enum0>& Result, const FTestbed1StructEnumWithArray& ParamEnum) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations")
	virtual TArray<ETestbed1Enum0> FuncEnum(const FTestbed1StructEnumWithArray& ParamEnum) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	virtual FTestbed1StructBoolWithArray GetPropBool() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	virtual void SetPropBool(UPARAM(DisplayName = "PropBool") const FTestbed1StructBoolWithArray& InPropBool) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	virtual FTestbed1StructIntWithArray GetPropInt() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	virtual void SetPropInt(UPARAM(DisplayName = "PropInt") const FTestbed1StructIntWithArray& InPropInt) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	virtual FTestbed1StructFloatWithArray GetPropFloat() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	virtual void SetPropFloat(UPARAM(DisplayName = "PropFloat") const FTestbed1StructFloatWithArray& InPropFloat) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	virtual FTestbed1StructStringWithArray GetPropString() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	virtual void SetPropString(UPARAM(DisplayName = "PropString") const FTestbed1StructStringWithArray& InPropString) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	virtual FTestbed1StructEnumWithArray GetPropEnum() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	virtual void SetPropEnum(UPARAM(DisplayName = "PropEnum") const FTestbed1StructEnumWithArray& InPropEnum) = 0;
};
