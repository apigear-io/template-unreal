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
#include "TbRefIfaces_data.h"
#include "TbRefIfacesSimpleLocalIfInterface.generated.h"

/**
 * Declaration for SimpleLocalIf
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefIfacesSimpleLocalIfIntSignalDelegate, int32 /* Param */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesSimpleLocalIfIntSignalDelegateBP, int32, Param);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefIfacesSimpleLocalIfIntPropertyChangedDelegate, int32 /* IntProperty */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesSimpleLocalIfIntPropertyChangedDelegateBP, int32, IntProperty);

/**
 * Subscriber interface for TbRefIfacesSimpleLocalIf events. Intended for Blueprint-only use.
 * Does contain signal events and property-changed events.
 * @note Guaranteed to be run from within the GameThread.
 */
UINTERFACE(BlueprintType)
class UTbRefIfacesSimpleLocalIfBPSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBREFIFACESAPI_API ITbRefIfacesSimpleLocalIfBPSubscriberInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Signals", DisplayName = "On IntSignal Signal")
	void OnIntSignalSignal(int32 Param);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Signals", DisplayName = "On Property IntProperty Changed")
	void OnIntPropertyChanged(UPARAM(DisplayName = "IntProperty") int32 InIntProperty);
};

/**
 * Subscriber interface for TbRefIfacesSimpleLocalIf events. Intended for C++ use.
 * Does contain signal events and property-changed events.
 * @note Not guaranteed to be run from within the GameThread - can be on any thread.
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbRefIfacesSimpleLocalIfSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBREFIFACESAPI_API ITbRefIfacesSimpleLocalIfSubscriberInterface
{
	GENERATED_BODY()
public:
	virtual void OnIntSignalSignal(int32 Param) = 0;

	virtual void OnIntPropertyChanged(UPARAM(DisplayName = "IntProperty") int32 InIntProperty) = 0;
};

/**
 * Class UTbRefIfacesSimpleLocalIfInterfacePublisher
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBREFIFACESAPI_API UTbRefIfacesSimpleLocalIfPublisher : public UObject
{
	GENERATED_BODY()

public:
	FTbRefIfacesSimpleLocalIfIntSignalDelegate OnIntSignalSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Signals", DisplayName = "IntSignal Signal")
	FTbRefIfacesSimpleLocalIfIntSignalDelegateBP OnIntSignalSignalBP;
	/// C++ wrapper for BP functions to safely call IntSignalSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Signals", DisplayName = "Broadcast IntSignal Signal")
	void BroadcastIntSignalSignal(int32 Param);

	FTbRefIfacesSimpleLocalIfIntPropertyChangedDelegate OnIntPropertyChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Signals", DisplayName = "Property IntProperty Changed")
	FTbRefIfacesSimpleLocalIfIntPropertyChangedDelegateBP OnIntPropertyChangedBP;
	/// C++ wrapper for BP functions to safely call OnIntPropertyChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Signals", DisplayName = "Broadcast Property IntProperty Changed")
	void BroadcastIntPropertyChanged(UPARAM(DisplayName = "IntProperty") int32 InIntProperty);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Signals")
	void Subscribe(const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber);
	void Subscribe(const TWeakInterfacePtr<ITbRefIfacesSimpleLocalIfSubscriberInterface>& Subscriber);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Signals")
	void Unsubscribe(const TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>& Subscriber);
	void Unsubscribe(const TWeakInterfacePtr<ITbRefIfacesSimpleLocalIfSubscriberInterface>& Subscriber);

private:
	void CleanUpSubscribers();

	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfBPSubscriberInterface>> BPSubscribers;
	FRWLock BPSubscribersLock;
	TArray<TWeakInterfacePtr<ITbRefIfacesSimpleLocalIfSubscriberInterface>> Subscribers;
	FRWLock SubscribersLock;
};

/**
 * Interface UTbRefIfacesSimpleLocalIfInterface only for Unreal Engine's reflection system
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbRefIfacesSimpleLocalIfInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbRefIfacesSimpleLocalIfInterface
 */
class TBREFIFACESAPI_API ITbRefIfacesSimpleLocalIfInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf")
	virtual UTbRefIfacesSimpleLocalIfPublisher* _GetPublisher() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void IntMethodAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param) = 0;
	virtual TFuture<int32> IntMethodAsync(int32 Param) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Operations")
	virtual int32 IntMethod(int32 Param) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Properties")
	virtual int32 GetIntProperty() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Properties")
	virtual void SetIntProperty(UPARAM(DisplayName = "IntProperty") int32 InIntProperty) = 0;
};
