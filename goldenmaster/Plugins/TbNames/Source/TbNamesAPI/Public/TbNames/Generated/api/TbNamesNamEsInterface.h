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
#include "TbNames_data.h"
#include "TbNamesNamEsInterface.generated.h"

/**
 * Declaration for Nam_Es
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsSomeSignalDelegate, bool /* bSomeParam */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsSomeSignalDelegateBP, bool, bSomeParam);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsSomeSignal2Delegate, bool /* bSomeParam */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsSomeSignal2DelegateBP, bool, bSomeParam);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsSwitchChangedDelegate, bool /* bSwitch */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsSwitchChangedDelegateBP, bool, bSwitch);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsSomePropertyChangedDelegate, int32 /* SomeProperty */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsSomePropertyChangedDelegateBP, int32, SomeProperty);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsSomePoperty2ChangedDelegate, int32 /* SomePoperty2 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsSomePoperty2ChangedDelegateBP, int32, SomePoperty2);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsEnumPropertyChangedDelegate, ETbNamesEnum_With_Under_scores /* EnumProperty */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsEnumPropertyChangedDelegateBP, ETbNamesEnum_With_Under_scores, EnumProperty);

/**
 * Helper interface for TbNamesNamEs events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events and property-changed events.
 */
UINTERFACE(BlueprintType)
class UTbNamesNamEsBPSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBNAMESAPI_API ITbNamesNamEsBPSubscriberInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "On SomeSignal Signal")
	void OnSomeSignalSignal(bool bSomeParam);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "On SomeSignal2 Signal")
	void OnSomeSignal2Signal(bool bSomeParam);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "On Property Switch Changed")
	void OnSwitchChanged(UPARAM(DisplayName = "bSwitch") bool bInSwitch);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "On Property SomeProperty Changed")
	void OnSomePropertyChanged(UPARAM(DisplayName = "SomeProperty") int32 InSomeProperty);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "On Property SomePoperty2 Changed")
	void OnSomePoperty2Changed(UPARAM(DisplayName = "SomePoperty2") int32 InSomePoperty2);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "On Property EnumProperty Changed")
	void OnEnumPropertyChanged(UPARAM(DisplayName = "EnumProperty") ETbNamesEnum_With_Under_scores InEnumProperty);
};

UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbNamesNamEsSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBNAMESAPI_API ITbNamesNamEsSubscriberInterface
{
	GENERATED_BODY()
public:
	virtual void OnSomeSignalSignal(bool bSomeParam) = 0;

	virtual void OnSomeSignal2Signal(bool bSomeParam) = 0;

	virtual void OnSwitchChanged(UPARAM(DisplayName = "bSwitch") bool bInSwitch) = 0;

	virtual void OnSomePropertyChanged(UPARAM(DisplayName = "SomeProperty") int32 InSomeProperty) = 0;

	virtual void OnSomePoperty2Changed(UPARAM(DisplayName = "SomePoperty2") int32 InSomePoperty2) = 0;

	virtual void OnEnumPropertyChanged(UPARAM(DisplayName = "EnumProperty") ETbNamesEnum_With_Under_scores InEnumProperty) = 0;
};

/**
 * Class UTbNamesNamEsInterfacePublisher
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBNAMESAPI_API UTbNamesNamEsPublisher : public UObject
{
	GENERATED_BODY()

public:
	FTbNamesNamEsSomeSignalDelegate OnSomeSignalSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "SomeSignal Signal")
	FTbNamesNamEsSomeSignalDelegateBP OnSomeSignalSignalBP;
	/// C++ wrapper for BP functions to safely call SomeSignalSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Broadcast SomeSignal Signal")
	void BroadcastSomeSignalSignal(bool bSomeParam);

	FTbNamesNamEsSomeSignal2Delegate OnSomeSignal2Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "SomeSignal2 Signal")
	FTbNamesNamEsSomeSignal2DelegateBP OnSomeSignal2SignalBP;
	/// C++ wrapper for BP functions to safely call SomeSignal2Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Broadcast SomeSignal2 Signal")
	void BroadcastSomeSignal2Signal(bool bSomeParam);

	FTbNamesNamEsSwitchChangedDelegate OnSwitchChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Property Switch Changed")
	FTbNamesNamEsSwitchChangedDelegateBP OnSwitchChangedBP;
	/// C++ wrapper for BP functions to safely call OnSwitchChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Broadcast Property Switch Changed")
	void BroadcastSwitchChanged(UPARAM(DisplayName = "bSwitch") bool bInSwitch);

	FTbNamesNamEsSomePropertyChangedDelegate OnSomePropertyChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Property SomeProperty Changed")
	FTbNamesNamEsSomePropertyChangedDelegateBP OnSomePropertyChangedBP;
	/// C++ wrapper for BP functions to safely call OnSomePropertyChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Broadcast Property SomeProperty Changed")
	void BroadcastSomePropertyChanged(UPARAM(DisplayName = "SomeProperty") int32 InSomeProperty);

	FTbNamesNamEsSomePoperty2ChangedDelegate OnSomePoperty2Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Property SomePoperty2 Changed")
	FTbNamesNamEsSomePoperty2ChangedDelegateBP OnSomePoperty2ChangedBP;
	/// C++ wrapper for BP functions to safely call OnSomePoperty2Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Broadcast Property SomePoperty2 Changed")
	void BroadcastSomePoperty2Changed(UPARAM(DisplayName = "SomePoperty2") int32 InSomePoperty2);

	FTbNamesNamEsEnumPropertyChangedDelegate OnEnumPropertyChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Property EnumProperty Changed")
	FTbNamesNamEsEnumPropertyChangedDelegateBP OnEnumPropertyChangedBP;
	/// C++ wrapper for BP functions to safely call OnEnumPropertyChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Broadcast Property EnumProperty Changed")
	void BroadcastEnumPropertyChanged(UPARAM(DisplayName = "EnumProperty") ETbNamesEnum_With_Under_scores InEnumProperty);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Signals")
	void Subscribe(const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber);
	void Subscribe(const TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>& Subscriber);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Signals")
	void Unsubscribe(const TScriptInterface<ITbNamesNamEsBPSubscriberInterface>& Subscriber);
	void Unsubscribe(const TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>& Subscriber);

private:
	UPROPERTY()
	TArray<TScriptInterface<ITbNamesNamEsBPSubscriberInterface>> BPSubscribers;
	FRWLock BPSubscribersLock;
	TArray<TWeakInterfacePtr<ITbNamesNamEsSubscriberInterface>> Subscribers;
	FRWLock SubscribersLock;
};

/**
 * Interface UTbNamesNamEsInterface only for Unreal Engine's reflection system
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbNamesNamEsInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbNamesNamEsInterface
 */
class TBNAMESAPI_API ITbNamesNamEsInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs")
	virtual UTbNamesNamEsPublisher* _GetPublisher() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Operations")
	virtual void SomeFunction(bool bSomeParam) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Operations")
	virtual void SomeFunction2(bool bSomeParam) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	virtual bool GetSwitch() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	virtual void SetSwitch(UPARAM(DisplayName = "bSwitch") bool bInSwitch) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	virtual int32 GetSomeProperty() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	virtual void SetSomeProperty(UPARAM(DisplayName = "SomeProperty") int32 InSomeProperty) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	virtual int32 GetSomePoperty2() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	virtual void SetSomePoperty2(UPARAM(DisplayName = "SomePoperty2") int32 InSomePoperty2) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	virtual ETbNamesEnum_With_Under_scores GetEnumProperty() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	virtual void SetEnumProperty(UPARAM(DisplayName = "EnumProperty") ETbNamesEnum_With_Under_scores InEnumProperty) = 0;
};
