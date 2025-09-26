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
#include "TbSame1_data.h"
#include "TbSame1SameStruct1InterfaceInterface.generated.h"

/**
 * Declaration for SameStruct1Interface
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSame1SameStruct1InterfaceSig1Delegate, const FTbSame1Struct1& /* Param1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameStruct1InterfaceSig1DelegateBP, const FTbSame1Struct1&, Param1);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSame1SameStruct1InterfaceProp1ChangedDelegate, const FTbSame1Struct1& /* Prop1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameStruct1InterfaceProp1ChangedDelegateBP, const FTbSame1Struct1&, Prop1);

/**
 * Helper interface for TbSame1SameStruct1Interface events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events and property-changed events.
 */
UINTERFACE(BlueprintType)
class UTbSame1SameStruct1InterfaceBPSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSAME1API_API ITbSame1SameStruct1InterfaceBPSubscriberInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSame1|SameStruct1Interface|Signals", DisplayName = "On Sig1 Signal")
	void OnSig1Signal(const FTbSame1Struct1& Param1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSame1|SameStruct1Interface|Signals", DisplayName = "On Property Prop1 Changed")
	void OnProp1Changed(UPARAM(DisplayName = "Prop1") const FTbSame1Struct1& InProp1);
};

UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSame1SameStruct1InterfaceSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSAME1API_API ITbSame1SameStruct1InterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	virtual void OnSig1Signal(const FTbSame1Struct1& Param1) = 0;

	virtual void OnProp1Changed(UPARAM(DisplayName = "Prop1") const FTbSame1Struct1& InProp1) = 0;
};

/**
 * Class UTbSame1SameStruct1InterfaceInterfacePublisher
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBSAME1API_API UTbSame1SameStruct1InterfacePublisher : public UObject
{
	GENERATED_BODY()

public:
	FTbSame1SameStruct1InterfaceSig1Delegate OnSig1Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameStruct1Interface|Signals", DisplayName = "Sig1 Signal")
	FTbSame1SameStruct1InterfaceSig1DelegateBP OnSig1SignalBP;
	/// C++ wrapper for BP functions to safely call Sig1Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface|Signals", DisplayName = "Broadcast Sig1 Signal")
	void BroadcastSig1Signal(const FTbSame1Struct1& Param1);

	FTbSame1SameStruct1InterfaceProp1ChangedDelegate OnProp1Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameStruct1Interface|Signals", DisplayName = "Property Prop1 Changed")
	FTbSame1SameStruct1InterfaceProp1ChangedDelegateBP OnProp1ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp1Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface|Signals", DisplayName = "Broadcast Property Prop1 Changed")
	void BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") const FTbSame1Struct1& InProp1);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface|Signals")
	void Subscribe(const TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>& Subscriber);
	void Subscribe(const TWeakInterfacePtr<ITbSame1SameStruct1InterfaceSubscriberInterface>& Subscriber);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface|Signals")
	void Unsubscribe(const TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>& Subscriber);
	void Unsubscribe(const TWeakInterfacePtr<ITbSame1SameStruct1InterfaceSubscriberInterface>& Subscriber);

private:
	void CleanUpSubscribers();

	TArray<TScriptInterface<ITbSame1SameStruct1InterfaceBPSubscriberInterface>> BPSubscribers;
	FRWLock BPSubscribersLock;
	TArray<TWeakInterfacePtr<ITbSame1SameStruct1InterfaceSubscriberInterface>> Subscribers;
	FRWLock SubscribersLock;
};

/**
 * Interface UTbSame1SameStruct1InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSame1SameStruct1InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame1SameStruct1InterfaceInterface
 */
class TBSAME1API_API ITbSame1SameStruct1InterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface")
	virtual UTbSame1SameStruct1InterfacePublisher* _GetPublisher() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface|Operations")
	virtual FTbSame1Struct1 Func1(const FTbSame1Struct1& Param1) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface|Properties")
	virtual FTbSame1Struct1 GetProp1() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface|Properties")
	virtual void SetProp1(UPARAM(DisplayName = "Prop1") const FTbSame1Struct1& InProp1) = 0;
};
