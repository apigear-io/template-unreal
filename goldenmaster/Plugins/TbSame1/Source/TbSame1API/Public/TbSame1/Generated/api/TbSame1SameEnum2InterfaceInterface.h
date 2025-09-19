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
#include "TbSame1_data.h"
#include "TbSame1SameEnum2InterfaceInterface.generated.h"

/**
 * Declaration for SameEnum2Interface
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum2InterfaceSig1Delegate, ETbSame1Enum1 /* Param1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum2InterfaceSig1DelegateBP, ETbSame1Enum1, Param1);

DECLARE_MULTICAST_DELEGATE_TwoParams(FTbSame1SameEnum2InterfaceSig2Delegate, ETbSame1Enum1 /* Param1 */, ETbSame1Enum2 /* Param2 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTbSame1SameEnum2InterfaceSig2DelegateBP, ETbSame1Enum1, Param1, ETbSame1Enum2, Param2);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum2InterfaceProp1ChangedDelegate, ETbSame1Enum1 /* Prop1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum2InterfaceProp1ChangedDelegateBP, ETbSame1Enum1, Prop1);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum2InterfaceProp2ChangedDelegate, ETbSame1Enum2 /* Prop2 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameEnum2InterfaceProp2ChangedDelegateBP, ETbSame1Enum2, Prop2);

/**
 * Helper interface for TbSame1SameEnum2Interface events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events and property-changed events.
 */
UINTERFACE(BlueprintType)
class UTbSame1SameEnum2InterfaceBPSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSAME1API_API ITbSame1SameEnum2InterfaceBPSubscriberInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSame1|SameEnum2Interface|Signals", DisplayName = "On Sig1 Signal")
	void OnSig1Signal(ETbSame1Enum1 Param1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSame1|SameEnum2Interface|Signals", DisplayName = "On Sig2 Signal")
	void OnSig2Signal(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSame1|SameEnum2Interface|Signals", DisplayName = "On Property Prop1 Changed")
	void OnProp1Changed(UPARAM(DisplayName = "Prop1") ETbSame1Enum1 InProp1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSame1|SameEnum2Interface|Signals", DisplayName = "On Property Prop2 Changed")
	void OnProp2Changed(UPARAM(DisplayName = "Prop2") ETbSame1Enum2 InProp2);
};

/**
 * Class UTbSame1SameEnum2InterfaceInterfacePublisher
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBSAME1API_API UTbSame1SameEnum2InterfacePublisher : public UObject
{
	GENERATED_BODY()

public:
	FTbSame1SameEnum2InterfaceSig1Delegate OnSig1Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum2Interface|Signals", DisplayName = "Sig1 Signal")
	FTbSame1SameEnum2InterfaceSig1DelegateBP OnSig1SignalBP;
	/// C++ wrapper for BP functions to safely call Sig1Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Signals", DisplayName = "Broadcast Sig1 Signal")
	void BroadcastSig1Signal(ETbSame1Enum1 Param1);

	FTbSame1SameEnum2InterfaceSig2Delegate OnSig2Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum2Interface|Signals", DisplayName = "Sig2 Signal")
	FTbSame1SameEnum2InterfaceSig2DelegateBP OnSig2SignalBP;
	/// C++ wrapper for BP functions to safely call Sig2Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Signals", DisplayName = "Broadcast Sig2 Signal")
	void BroadcastSig2Signal(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2);

	FTbSame1SameEnum2InterfaceProp1ChangedDelegate OnProp1Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum2Interface|Signals", DisplayName = "Property Prop1 Changed")
	FTbSame1SameEnum2InterfaceProp1ChangedDelegateBP OnProp1ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp1Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Signals", DisplayName = "Broadcast Property Prop1 Changed")
	void BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") ETbSame1Enum1 InProp1);

	FTbSame1SameEnum2InterfaceProp2ChangedDelegate OnProp2Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum2Interface|Signals", DisplayName = "Property Prop2 Changed")
	FTbSame1SameEnum2InterfaceProp2ChangedDelegateBP OnProp2ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp2Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Signals", DisplayName = "Broadcast Property Prop2 Changed")
	void BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") ETbSame1Enum2 InProp2);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Signals")
	void Subscribe(const TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>& Subscriber);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Signals")
	void Unsubscribe(const TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>& Subscriber);

private:
	UPROPERTY()
	TArray<TScriptInterface<ITbSame1SameEnum2InterfaceBPSubscriberInterface>> Subscribers;
};

/**
 * Interface UTbSame1SameEnum2InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSame1SameEnum2InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame1SameEnum2InterfaceInterface
 */
class TBSAME1API_API ITbSame1SameEnum2InterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
	virtual UTbSame1SameEnum2InterfacePublisher* _GetPublisher() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Operations")
	virtual ETbSame1Enum1 Func1(ETbSame1Enum1 Param1) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1, ETbSame1Enum2 Param2) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Operations")
	virtual ETbSame1Enum1 Func2(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Properties")
	virtual ETbSame1Enum1 GetProp1() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Properties")
	virtual void SetProp1(UPARAM(DisplayName = "Prop1") ETbSame1Enum1 InProp1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Properties")
	virtual ETbSame1Enum2 GetProp2() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface|Properties")
	virtual void SetProp2(UPARAM(DisplayName = "Prop2") ETbSame1Enum2 InProp2) = 0;
};
