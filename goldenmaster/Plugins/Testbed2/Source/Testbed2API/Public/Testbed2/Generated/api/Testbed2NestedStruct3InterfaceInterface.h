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
#include "Testbed2_data.h"
#include "Testbed2NestedStruct3InterfaceInterface.generated.h"

/**
 * Declaration for NestedStruct3Interface
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceSig1Delegate, const FTestbed2NestedStruct1& /* Param1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceSig1DelegateBP, const FTestbed2NestedStruct1&, Param1);

DECLARE_MULTICAST_DELEGATE_TwoParams(FTestbed2NestedStruct3InterfaceSig2Delegate, const FTestbed2NestedStruct1& /* Param1 */, const FTestbed2NestedStruct2& /* Param2 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTestbed2NestedStruct3InterfaceSig2DelegateBP, const FTestbed2NestedStruct1&, Param1, const FTestbed2NestedStruct2&, Param2);

DECLARE_MULTICAST_DELEGATE_ThreeParams(FTestbed2NestedStruct3InterfaceSig3Delegate, const FTestbed2NestedStruct1& /* Param1 */, const FTestbed2NestedStruct2& /* Param2 */, const FTestbed2NestedStruct3& /* Param3 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTestbed2NestedStruct3InterfaceSig3DelegateBP, const FTestbed2NestedStruct1&, Param1, const FTestbed2NestedStruct2&, Param2, const FTestbed2NestedStruct3&, Param3);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp1ChangedDelegate, const FTestbed2NestedStruct1& /* Prop1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp1ChangedDelegateBP, const FTestbed2NestedStruct1&, Prop1);
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp2ChangedDelegate, const FTestbed2NestedStruct2& /* Prop2 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp2ChangedDelegateBP, const FTestbed2NestedStruct2&, Prop2);
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp3ChangedDelegate, const FTestbed2NestedStruct3& /* Prop3 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp3ChangedDelegateBP, const FTestbed2NestedStruct3&, Prop3);

/**
 * Helper interface for Testbed2NestedStruct3Interface events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events and property-changed events.
 */
UINTERFACE(BlueprintType)
class UTestbed2NestedStruct3InterfaceBPSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TESTBED2API_API ITestbed2NestedStruct3InterfaceBPSubscriberInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "On Sig1 Signal")
	void OnSig1Signal(const FTestbed2NestedStruct1& Param1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "On Sig2 Signal")
	void OnSig2Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "On Sig3 Signal")
	void OnSig3Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "On Property Prop1 Changed")
	void OnProp1Changed(UPARAM(DisplayName = "Prop1") const FTestbed2NestedStruct1& InProp1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "On Property Prop2 Changed")
	void OnProp2Changed(UPARAM(DisplayName = "Prop2") const FTestbed2NestedStruct2& InProp2);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "On Property Prop3 Changed")
	void OnProp3Changed(UPARAM(DisplayName = "Prop3") const FTestbed2NestedStruct3& InProp3);
};

/**
 * Class UTestbed2NestedStruct3InterfaceInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TESTBED2API_API UTestbed2NestedStruct3InterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	FTestbed2NestedStruct3InterfaceSig1Delegate OnSig1Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Sig1 Signal")
	FTestbed2NestedStruct3InterfaceSig1DelegateBP OnSig1SignalBP;
	/// C++ wrapper for BP functions to safely call Sig1Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Sig1 Signal")
	void BroadcastSig1Signal(const FTestbed2NestedStruct1& Param1)
	{
		OnSig1Signal.Broadcast(Param1);
		OnSig1SignalBP.Broadcast(Param1);

		TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnSig1Signal(Obj, Param1);
			}
		}
	}

	FTestbed2NestedStruct3InterfaceSig2Delegate OnSig2Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Sig2 Signal")
	FTestbed2NestedStruct3InterfaceSig2DelegateBP OnSig2SignalBP;
	/// C++ wrapper for BP functions to safely call Sig2Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Sig2 Signal")
	void BroadcastSig2Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
	{
		OnSig2Signal.Broadcast(Param1, Param2);
		OnSig2SignalBP.Broadcast(Param1, Param2);

		TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnSig2Signal(Obj, Param1, Param2);
			}
		}
	}

	FTestbed2NestedStruct3InterfaceSig3Delegate OnSig3Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Sig3 Signal")
	FTestbed2NestedStruct3InterfaceSig3DelegateBP OnSig3SignalBP;
	/// C++ wrapper for BP functions to safely call Sig3Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Sig3 Signal")
	void BroadcastSig3Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
	{
		OnSig3Signal.Broadcast(Param1, Param2, Param3);
		OnSig3SignalBP.Broadcast(Param1, Param2, Param3);

		TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnSig3Signal(Obj, Param1, Param2, Param3);
			}
		}
	}

	FTestbed2NestedStruct3InterfaceProp1ChangedDelegate OnProp1Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Property Prop1 Changed")
	FTestbed2NestedStruct3InterfaceProp1ChangedDelegateBP OnProp1ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp1Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Property Prop1 Changed")
	void BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") const FTestbed2NestedStruct1& InProp1)
	{
		OnProp1Changed.Broadcast(InProp1);
		OnProp1ChangedBP.Broadcast(InProp1);

		TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnProp1Changed(Obj, InProp1);
			}
		}
	}

	FTestbed2NestedStruct3InterfaceProp2ChangedDelegate OnProp2Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Property Prop2 Changed")
	FTestbed2NestedStruct3InterfaceProp2ChangedDelegateBP OnProp2ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp2Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Property Prop2 Changed")
	void BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") const FTestbed2NestedStruct2& InProp2)
	{
		OnProp2Changed.Broadcast(InProp2);
		OnProp2ChangedBP.Broadcast(InProp2);

		TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnProp2Changed(Obj, InProp2);
			}
		}
	}

	FTestbed2NestedStruct3InterfaceProp3ChangedDelegate OnProp3Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Property Prop3 Changed")
	FTestbed2NestedStruct3InterfaceProp3ChangedDelegateBP OnProp3ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp3Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Property Prop3 Changed")
	void BroadcastProp3Changed(UPARAM(DisplayName = "Prop3") const FTestbed2NestedStruct3& InProp3)
	{
		OnProp3Changed.Broadcast(InProp3);
		OnProp3ChangedBP.Broadcast(InProp3);

		TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> SubscribersCopy = Subscribers;
		for (const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber : SubscribersCopy)
		{
			if (UObject* Obj = Subscriber.GetObject())
			{
				ITestbed2NestedStruct3InterfaceBPSubscriberInterface::Execute_OnProp3Changed(Obj, InProp3);
			}
		}
	}

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals")
	void Subscribe(const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber)
	{
		if (!Subscriber.GetObject()) return;
		Subscribers.Remove(Subscriber);
		Subscribers.Add(Subscriber);
	}
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals")
	void Unsubscribe(const TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>& Subscriber)
	{
		Subscribers.Remove(Subscriber);
	}
private:
	UPROPERTY()
	TArray<TScriptInterface<ITestbed2NestedStruct3InterfaceBPSubscriberInterface>> Subscribers;
};

/**
 * Interface UTestbed2NestedStruct3InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTestbed2NestedStruct3InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed2NestedStruct3InterfaceInterface
 */
class TESTBED2API_API ITestbed2NestedStruct3InterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	virtual UTestbed2NestedStruct3InterfaceSignals* _GetSignals() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations")
	virtual FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations")
	virtual FTestbed2NestedStruct1 Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations")
	virtual FTestbed2NestedStruct1 Func3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	virtual FTestbed2NestedStruct1 GetProp1() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	virtual void SetProp1(UPARAM(DisplayName = "Prop1") const FTestbed2NestedStruct1& InProp1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	virtual FTestbed2NestedStruct2 GetProp2() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	virtual void SetProp2(UPARAM(DisplayName = "Prop2") const FTestbed2NestedStruct2& InProp2) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	virtual FTestbed2NestedStruct3 GetProp3() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	virtual void SetProp3(UPARAM(DisplayName = "Prop3") const FTestbed2NestedStruct3& InProp3) = 0;
};
