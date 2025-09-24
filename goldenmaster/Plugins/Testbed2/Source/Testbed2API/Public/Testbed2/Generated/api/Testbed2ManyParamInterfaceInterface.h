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
#include "Testbed2_data.h"
#include "Testbed2ManyParamInterfaceInterface.generated.h"

/**
 * Declaration for ManyParamInterface
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceSig1Delegate, int32 /* Param1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceSig1DelegateBP, int32, Param1);

DECLARE_MULTICAST_DELEGATE_TwoParams(FTestbed2ManyParamInterfaceSig2Delegate, int32 /* Param1 */, int32 /* Param2 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTestbed2ManyParamInterfaceSig2DelegateBP, int32, Param1, int32, Param2);

DECLARE_MULTICAST_DELEGATE_ThreeParams(FTestbed2ManyParamInterfaceSig3Delegate, int32 /* Param1 */, int32 /* Param2 */, int32 /* Param3 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTestbed2ManyParamInterfaceSig3DelegateBP, int32, Param1, int32, Param2, int32, Param3);

DECLARE_MULTICAST_DELEGATE_FourParams(FTestbed2ManyParamInterfaceSig4Delegate, int32 /* Param1 */, int32 /* Param2 */, int32 /* Param3 */, int32 /* Param4 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FTestbed2ManyParamInterfaceSig4DelegateBP, int32, Param1, int32, Param2, int32, Param3, int32, Param4);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceProp1ChangedDelegate, int32 /* Prop1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceProp1ChangedDelegateBP, int32, Prop1);
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceProp2ChangedDelegate, int32 /* Prop2 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceProp2ChangedDelegateBP, int32, Prop2);
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceProp3ChangedDelegate, int32 /* Prop3 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceProp3ChangedDelegateBP, int32, Prop3);
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceProp4ChangedDelegate, int32 /* Prop4 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceProp4ChangedDelegateBP, int32, Prop4);

/**
 * Helper interface for Testbed2ManyParamInterface events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events and property-changed events.
 */
UINTERFACE(BlueprintType)
class UTestbed2ManyParamInterfaceBPSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TESTBED2API_API ITestbed2ManyParamInterfaceBPSubscriberInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "On Sig1 Signal")
	void OnSig1Signal(int32 Param1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "On Sig2 Signal")
	void OnSig2Signal(int32 Param1, int32 Param2);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "On Sig3 Signal")
	void OnSig3Signal(int32 Param1, int32 Param2, int32 Param3);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "On Sig4 Signal")
	void OnSig4Signal(int32 Param1, int32 Param2, int32 Param3, int32 Param4);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "On Property Prop1 Changed")
	void OnProp1Changed(UPARAM(DisplayName = "Prop1") int32 InProp1);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "On Property Prop2 Changed")
	void OnProp2Changed(UPARAM(DisplayName = "Prop2") int32 InProp2);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "On Property Prop3 Changed")
	void OnProp3Changed(UPARAM(DisplayName = "Prop3") int32 InProp3);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "On Property Prop4 Changed")
	void OnProp4Changed(UPARAM(DisplayName = "Prop4") int32 InProp4);
};

UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTestbed2ManyParamInterfaceSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TESTBED2API_API ITestbed2ManyParamInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	virtual void OnSig1Signal(int32 Param1) = 0;

	virtual void OnSig2Signal(int32 Param1, int32 Param2) = 0;

	virtual void OnSig3Signal(int32 Param1, int32 Param2, int32 Param3) = 0;

	virtual void OnSig4Signal(int32 Param1, int32 Param2, int32 Param3, int32 Param4) = 0;

	virtual void OnProp1Changed(UPARAM(DisplayName = "Prop1") int32 InProp1) = 0;

	virtual void OnProp2Changed(UPARAM(DisplayName = "Prop2") int32 InProp2) = 0;

	virtual void OnProp3Changed(UPARAM(DisplayName = "Prop3") int32 InProp3) = 0;

	virtual void OnProp4Changed(UPARAM(DisplayName = "Prop4") int32 InProp4) = 0;
};

/**
 * Class UTestbed2ManyParamInterfaceInterfacePublisher
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TESTBED2API_API UTestbed2ManyParamInterfacePublisher : public UObject
{
	GENERATED_BODY()

public:
	FTestbed2ManyParamInterfaceSig1Delegate OnSig1Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Sig1 Signal")
	FTestbed2ManyParamInterfaceSig1DelegateBP OnSig1SignalBP;
	/// C++ wrapper for BP functions to safely call Sig1Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Broadcast Sig1 Signal")
	void BroadcastSig1Signal(int32 Param1);

	FTestbed2ManyParamInterfaceSig2Delegate OnSig2Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Sig2 Signal")
	FTestbed2ManyParamInterfaceSig2DelegateBP OnSig2SignalBP;
	/// C++ wrapper for BP functions to safely call Sig2Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Broadcast Sig2 Signal")
	void BroadcastSig2Signal(int32 Param1, int32 Param2);

	FTestbed2ManyParamInterfaceSig3Delegate OnSig3Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Sig3 Signal")
	FTestbed2ManyParamInterfaceSig3DelegateBP OnSig3SignalBP;
	/// C++ wrapper for BP functions to safely call Sig3Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Broadcast Sig3 Signal")
	void BroadcastSig3Signal(int32 Param1, int32 Param2, int32 Param3);

	FTestbed2ManyParamInterfaceSig4Delegate OnSig4Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Sig4 Signal")
	FTestbed2ManyParamInterfaceSig4DelegateBP OnSig4SignalBP;
	/// C++ wrapper for BP functions to safely call Sig4Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Broadcast Sig4 Signal")
	void BroadcastSig4Signal(int32 Param1, int32 Param2, int32 Param3, int32 Param4);

	FTestbed2ManyParamInterfaceProp1ChangedDelegate OnProp1Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Property Prop1 Changed")
	FTestbed2ManyParamInterfaceProp1ChangedDelegateBP OnProp1ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp1Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Broadcast Property Prop1 Changed")
	void BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") int32 InProp1);

	FTestbed2ManyParamInterfaceProp2ChangedDelegate OnProp2Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Property Prop2 Changed")
	FTestbed2ManyParamInterfaceProp2ChangedDelegateBP OnProp2ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp2Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Broadcast Property Prop2 Changed")
	void BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") int32 InProp2);

	FTestbed2ManyParamInterfaceProp3ChangedDelegate OnProp3Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Property Prop3 Changed")
	FTestbed2ManyParamInterfaceProp3ChangedDelegateBP OnProp3ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp3Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Broadcast Property Prop3 Changed")
	void BroadcastProp3Changed(UPARAM(DisplayName = "Prop3") int32 InProp3);

	FTestbed2ManyParamInterfaceProp4ChangedDelegate OnProp4Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Property Prop4 Changed")
	FTestbed2ManyParamInterfaceProp4ChangedDelegateBP OnProp4ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp4Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Broadcast Property Prop4 Changed")
	void BroadcastProp4Changed(UPARAM(DisplayName = "Prop4") int32 InProp4);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals")
	void Subscribe(const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber);
	void Subscribe(const TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>& Subscriber);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals")
	void Unsubscribe(const TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>& Subscriber);
	void Unsubscribe(const TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>& Subscriber);

private:
	UPROPERTY()
	TArray<TScriptInterface<ITestbed2ManyParamInterfaceBPSubscriberInterface>> BPSubscribers;
	FRWLock BPSubscribersLock;
	TArray<TWeakInterfacePtr<ITestbed2ManyParamInterfaceSubscriberInterface>> Subscribers;
	FRWLock SubscribersLock;
};

/**
 * Interface UTestbed2ManyParamInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTestbed2ManyParamInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed2ManyParamInterfaceInterface
 */
class TESTBED2API_API ITestbed2ManyParamInterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	virtual UTestbed2ManyParamInterfacePublisher* _GetPublisher() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Operations")
	virtual int32 Func1(int32 Param1) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Operations")
	virtual int32 Func2(int32 Param1, int32 Param2) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Operations")
	virtual int32 Func3(int32 Param1, int32 Param2, int32 Param3) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func4Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Operations")
	virtual int32 Func4(int32 Param1, int32 Param2, int32 Param3, int32 Param4) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	virtual int32 GetProp1() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	virtual void SetProp1(UPARAM(DisplayName = "Prop1") int32 InProp1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	virtual int32 GetProp2() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	virtual void SetProp2(UPARAM(DisplayName = "Prop2") int32 InProp2) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	virtual int32 GetProp3() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	virtual void SetProp3(UPARAM(DisplayName = "Prop3") int32 InProp3) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	virtual int32 GetProp4() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	virtual void SetProp4(UPARAM(DisplayName = "Prop4") int32 InProp4) = 0;
};
