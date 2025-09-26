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
#include "TbSame2_data.h"
#include "TbSame2SameEnum2InterfaceInterface.generated.h"

/**
 * Declaration for SameEnum2Interface
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSame2SameEnum2InterfaceSig1Delegate, ETbSame2Enum1 /* Param1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameEnum2InterfaceSig1DelegateBP, ETbSame2Enum1, Param1);

DECLARE_MULTICAST_DELEGATE_TwoParams(FTbSame2SameEnum2InterfaceSig2Delegate, ETbSame2Enum1 /* Param1 */, ETbSame2Enum2 /* Param2 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTbSame2SameEnum2InterfaceSig2DelegateBP, ETbSame2Enum1, Param1, ETbSame2Enum2, Param2);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSame2SameEnum2InterfaceProp1ChangedDelegate, ETbSame2Enum1 /* Prop1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameEnum2InterfaceProp1ChangedDelegateBP, ETbSame2Enum1, Prop1);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSame2SameEnum2InterfaceProp2ChangedDelegate, ETbSame2Enum2 /* Prop2 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameEnum2InterfaceProp2ChangedDelegateBP, ETbSame2Enum2, Prop2);

/**
 * Helper interface for TbSame2SameEnum2Interface events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events and property-changed events.
 */
UINTERFACE(BlueprintType)
class UTbSame2SameEnum2InterfaceBPSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSAME2API_API ITbSame2SameEnum2InterfaceBPSubscriberInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "On Sig1 Signal")
	void OnSig1Signal(ETbSame2Enum1 Param1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "On Sig2 Signal")
	void OnSig2Signal(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "On Property Prop1 Changed")
	void OnProp1Changed(UPARAM(DisplayName = "Prop1") ETbSame2Enum1 InProp1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "On Property Prop2 Changed")
	void OnProp2Changed(UPARAM(DisplayName = "Prop2") ETbSame2Enum2 InProp2);
};

UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSame2SameEnum2InterfaceSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSAME2API_API ITbSame2SameEnum2InterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	virtual void OnSig1Signal(ETbSame2Enum1 Param1) = 0;

	virtual void OnSig2Signal(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) = 0;

	virtual void OnProp1Changed(UPARAM(DisplayName = "Prop1") ETbSame2Enum1 InProp1) = 0;

	virtual void OnProp2Changed(UPARAM(DisplayName = "Prop2") ETbSame2Enum2 InProp2) = 0;
};

/**
 * Class UTbSame2SameEnum2InterfaceInterfacePublisher
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBSAME2API_API UTbSame2SameEnum2InterfacePublisher : public UObject
{
	GENERATED_BODY()

public:
	FTbSame2SameEnum2InterfaceSig1Delegate OnSig1Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "Sig1 Signal")
	FTbSame2SameEnum2InterfaceSig1DelegateBP OnSig1SignalBP;
	/// C++ wrapper for BP functions to safely call Sig1Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "Broadcast Sig1 Signal")
	void BroadcastSig1Signal(ETbSame2Enum1 Param1);

	FTbSame2SameEnum2InterfaceSig2Delegate OnSig2Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "Sig2 Signal")
	FTbSame2SameEnum2InterfaceSig2DelegateBP OnSig2SignalBP;
	/// C++ wrapper for BP functions to safely call Sig2Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "Broadcast Sig2 Signal")
	void BroadcastSig2Signal(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2);

	FTbSame2SameEnum2InterfaceProp1ChangedDelegate OnProp1Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "Property Prop1 Changed")
	FTbSame2SameEnum2InterfaceProp1ChangedDelegateBP OnProp1ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp1Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "Broadcast Property Prop1 Changed")
	void BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") ETbSame2Enum1 InProp1);

	FTbSame2SameEnum2InterfaceProp2ChangedDelegate OnProp2Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "Property Prop2 Changed")
	FTbSame2SameEnum2InterfaceProp2ChangedDelegateBP OnProp2ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp2Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "Broadcast Property Prop2 Changed")
	void BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") ETbSame2Enum2 InProp2);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals")
	void Subscribe(const TScriptInterface<ITbSame2SameEnum2InterfaceBPSubscriberInterface>& Subscriber);
	void Subscribe(const TWeakInterfacePtr<ITbSame2SameEnum2InterfaceSubscriberInterface>& Subscriber);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals")
	void Unsubscribe(const TScriptInterface<ITbSame2SameEnum2InterfaceBPSubscriberInterface>& Subscriber);
	void Unsubscribe(const TWeakInterfacePtr<ITbSame2SameEnum2InterfaceSubscriberInterface>& Subscriber);

private:
	void CleanUpSubscribers();

	TArray<TScriptInterface<ITbSame2SameEnum2InterfaceBPSubscriberInterface>> BPSubscribers;
	FRWLock BPSubscribersLock;
	TArray<TWeakInterfacePtr<ITbSame2SameEnum2InterfaceSubscriberInterface>> Subscribers;
	FRWLock SubscribersLock;
};

/**
 * Interface UTbSame2SameEnum2InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSame2SameEnum2InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame2SameEnum2InterfaceInterface
 */
class TBSAME2API_API ITbSame2SameEnum2InterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface")
	virtual UTbSame2SameEnum2InterfacePublisher* _GetPublisher() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Operations")
	virtual ETbSame2Enum1 Func1(ETbSame2Enum1 Param1) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Operations")
	virtual ETbSame2Enum1 Func2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties")
	virtual ETbSame2Enum1 GetProp1() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties")
	virtual void SetProp1(UPARAM(DisplayName = "Prop1") ETbSame2Enum1 InProp1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties")
	virtual ETbSame2Enum2 GetProp2() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties")
	virtual void SetProp2(UPARAM(DisplayName = "Prop2") ETbSame2Enum2 InProp2) = 0;
};
