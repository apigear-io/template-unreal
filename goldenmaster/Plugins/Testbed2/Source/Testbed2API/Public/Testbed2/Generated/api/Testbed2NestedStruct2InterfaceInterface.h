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
#include "Testbed2_data.h"
#include "Testbed2NestedStruct2InterfaceInterface.generated.h"

/**
 * Declaration for NestedStruct2Interface
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct2InterfaceSig1Delegate, const FTestbed2NestedStruct1& /* Param1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct2InterfaceSig1DelegateBP, const FTestbed2NestedStruct1&, Param1);

DECLARE_MULTICAST_DELEGATE_TwoParams(FTestbed2NestedStruct2InterfaceSig2Delegate, const FTestbed2NestedStruct1& /* Param1 */, const FTestbed2NestedStruct2& /* Param2 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTestbed2NestedStruct2InterfaceSig2DelegateBP, const FTestbed2NestedStruct1&, Param1, const FTestbed2NestedStruct2&, Param2);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct2InterfaceProp1ChangedDelegate, const FTestbed2NestedStruct1& /* Prop1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct2InterfaceProp1ChangedDelegateBP, const FTestbed2NestedStruct1&, Prop1);
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct2InterfaceProp2ChangedDelegate, const FTestbed2NestedStruct2& /* Prop2 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct2InterfaceProp2ChangedDelegateBP, const FTestbed2NestedStruct2&, Prop2);

/**
 * Subscriber interface for Testbed2NestedStruct2Interface events. Intended for Blueprint-only use.
 * Does contain signal events and property-changed events.
 * @note Guaranteed to be run from within the GameThread.
 */
UINTERFACE(BlueprintType)
class UTestbed2NestedStruct2InterfaceBPSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TESTBED2API_API ITestbed2NestedStruct2InterfaceBPSubscriberInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|NestedStruct2Interface|Signals", DisplayName = "On Sig1 Signal")
	void OnSig1Signal(const FTestbed2NestedStruct1& Param1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|NestedStruct2Interface|Signals", DisplayName = "On Sig2 Signal")
	void OnSig2Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|NestedStruct2Interface|Signals", DisplayName = "On Property Prop1 Changed")
	void OnProp1Changed(UPARAM(DisplayName = "Prop1") const FTestbed2NestedStruct1& InProp1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|NestedStruct2Interface|Signals", DisplayName = "On Property Prop2 Changed")
	void OnProp2Changed(UPARAM(DisplayName = "Prop2") const FTestbed2NestedStruct2& InProp2);
};

/**
 * Subscriber interface for Testbed2NestedStruct2Interface events. Intended for C++ use.
 * Does contain signal events and property-changed events.
 * @note Not guaranteed to be run from within the GameThread - can be on any thread.
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTestbed2NestedStruct2InterfaceSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TESTBED2API_API ITestbed2NestedStruct2InterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	virtual void OnSig1Signal(const FTestbed2NestedStruct1& Param1) = 0;

	virtual void OnSig2Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) = 0;

	virtual void OnProp1Changed(UPARAM(DisplayName = "Prop1") const FTestbed2NestedStruct1& InProp1) = 0;

	virtual void OnProp2Changed(UPARAM(DisplayName = "Prop2") const FTestbed2NestedStruct2& InProp2) = 0;
};

/**
 * Class UTestbed2NestedStruct2InterfaceInterfacePublisher
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TESTBED2API_API UTestbed2NestedStruct2InterfacePublisher : public UObject
{
	GENERATED_BODY()

public:
	FTestbed2NestedStruct2InterfaceSig1Delegate OnSig1Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Signals", DisplayName = "Sig1 Signal")
	FTestbed2NestedStruct2InterfaceSig1DelegateBP OnSig1SignalBP;
	/// C++ wrapper for BP functions to safely call Sig1Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Signals", DisplayName = "Broadcast Sig1 Signal")
	void BroadcastSig1Signal(const FTestbed2NestedStruct1& Param1);

	FTestbed2NestedStruct2InterfaceSig2Delegate OnSig2Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Signals", DisplayName = "Sig2 Signal")
	FTestbed2NestedStruct2InterfaceSig2DelegateBP OnSig2SignalBP;
	/// C++ wrapper for BP functions to safely call Sig2Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Signals", DisplayName = "Broadcast Sig2 Signal")
	void BroadcastSig2Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);

	FTestbed2NestedStruct2InterfaceProp1ChangedDelegate OnProp1Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Signals", DisplayName = "Property Prop1 Changed")
	FTestbed2NestedStruct2InterfaceProp1ChangedDelegateBP OnProp1ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp1Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Signals", DisplayName = "Broadcast Property Prop1 Changed")
	void BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") const FTestbed2NestedStruct1& InProp1);

	FTestbed2NestedStruct2InterfaceProp2ChangedDelegate OnProp2Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Signals", DisplayName = "Property Prop2 Changed")
	FTestbed2NestedStruct2InterfaceProp2ChangedDelegateBP OnProp2ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp2Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Signals", DisplayName = "Broadcast Property Prop2 Changed")
	void BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") const FTestbed2NestedStruct2& InProp2);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Signals")
	void Subscribe(const TScriptInterface<ITestbed2NestedStruct2InterfaceBPSubscriberInterface>& Subscriber);
	void Subscribe(const TWeakInterfacePtr<ITestbed2NestedStruct2InterfaceSubscriberInterface>& Subscriber);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Signals")
	void Unsubscribe(const TScriptInterface<ITestbed2NestedStruct2InterfaceBPSubscriberInterface>& Subscriber);
	void Unsubscribe(const TWeakInterfacePtr<ITestbed2NestedStruct2InterfaceSubscriberInterface>& Subscriber);

private:
	void CleanUpSubscribers();

	TArray<TScriptInterface<ITestbed2NestedStruct2InterfaceBPSubscriberInterface>> BPSubscribers;
	FRWLock BPSubscribersLock;
	TArray<TWeakInterfacePtr<ITestbed2NestedStruct2InterfaceSubscriberInterface>> Subscribers;
	FRWLock SubscribersLock;
};

/**
 * Interface UTestbed2NestedStruct2InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTestbed2NestedStruct2InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed2NestedStruct2InterfaceInterface
 */
class TESTBED2API_API ITestbed2NestedStruct2InterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	virtual UTestbed2NestedStruct2InterfacePublisher* _GetPublisher() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) = 0;
	virtual TFuture<FTestbed2NestedStruct1> Func1Async(const FTestbed2NestedStruct1& Param1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Operations")
	virtual FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) = 0;
	virtual TFuture<FTestbed2NestedStruct1> Func2Async(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Operations")
	virtual FTestbed2NestedStruct1 Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Properties")
	virtual FTestbed2NestedStruct1 GetProp1() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Properties")
	virtual void SetProp1(UPARAM(DisplayName = "Prop1") const FTestbed2NestedStruct1& InProp1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Properties")
	virtual FTestbed2NestedStruct2 GetProp2() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface|Properties")
	virtual void SetProp2(UPARAM(DisplayName = "Prop2") const FTestbed2NestedStruct2& InProp2) = 0;
};
