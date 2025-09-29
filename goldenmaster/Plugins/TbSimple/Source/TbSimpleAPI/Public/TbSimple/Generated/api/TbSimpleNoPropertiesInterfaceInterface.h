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
#include "TbSimpleNoPropertiesInterfaceInterface.generated.h"

/**
 * Declaration for NoPropertiesInterface
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE(FTbSimpleNoPropertiesInterfaceSigVoidDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTbSimpleNoPropertiesInterfaceSigVoidDelegateBP);

DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleNoPropertiesInterfaceSigBoolDelegate, bool /* bParamBool */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoPropertiesInterfaceSigBoolDelegateBP, bool, bParamBool);

// property delegates

/**
 * Subscriber interface for TbSimpleNoPropertiesInterface events. Intended for Blueprint-only use.
 * Does contain signal events and property-changed events.
 * @note Guaranteed to be run from within the GameThread.
 */
UINTERFACE(BlueprintType)
class UTbSimpleNoPropertiesInterfaceBPSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSIMPLEAPI_API ITbSimpleNoPropertiesInterfaceBPSubscriberInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|NoPropertiesInterface|Signals", DisplayName = "On SigVoid Signal")
	void OnSigVoidSignal();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|NoPropertiesInterface|Signals", DisplayName = "On SigBool Signal")
	void OnSigBoolSignal(bool bParamBool);
};

/**
 * Subscriber interface for TbSimpleNoPropertiesInterface events. Intended for C++ use.
 * Does contain signal events and property-changed events.
 * @note Not guaranteed to be run from within the GameThread - can be on any thread.
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSimpleNoPropertiesInterfaceSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSIMPLEAPI_API ITbSimpleNoPropertiesInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	virtual void OnSigVoidSignal() = 0;

	virtual void OnSigBoolSignal(bool bParamBool) = 0;
};

/**
 * Class UTbSimpleNoPropertiesInterfaceInterfacePublisher
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBSIMPLEAPI_API UTbSimpleNoPropertiesInterfacePublisher : public UObject
{
	GENERATED_BODY()

public:
	FTbSimpleNoPropertiesInterfaceSigVoidDelegate OnSigVoidSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Signals", DisplayName = "SigVoid Signal")
	FTbSimpleNoPropertiesInterfaceSigVoidDelegateBP OnSigVoidSignalBP;
	/// C++ wrapper for BP functions to safely call SigVoidSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Signals", DisplayName = "Broadcast SigVoid Signal")
	void BroadcastSigVoidSignal();

	FTbSimpleNoPropertiesInterfaceSigBoolDelegate OnSigBoolSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Signals", DisplayName = "SigBool Signal")
	FTbSimpleNoPropertiesInterfaceSigBoolDelegateBP OnSigBoolSignalBP;
	/// C++ wrapper for BP functions to safely call SigBoolSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Signals", DisplayName = "Broadcast SigBool Signal")
	void BroadcastSigBoolSignal(bool bParamBool);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Signals")
	void Subscribe(const TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>& Subscriber);
	void Subscribe(const TWeakInterfacePtr<ITbSimpleNoPropertiesInterfaceSubscriberInterface>& Subscriber);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Signals")
	void Unsubscribe(const TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>& Subscriber);
	void Unsubscribe(const TWeakInterfacePtr<ITbSimpleNoPropertiesInterfaceSubscriberInterface>& Subscriber);

private:
	void CleanUpSubscribers();

	TArray<TScriptInterface<ITbSimpleNoPropertiesInterfaceBPSubscriberInterface>> BPSubscribers;
	FRWLock BPSubscribersLock;
	TArray<TWeakInterfacePtr<ITbSimpleNoPropertiesInterfaceSubscriberInterface>> Subscribers;
	FRWLock SubscribersLock;
};

/**
 * Interface UTbSimpleNoPropertiesInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSimpleNoPropertiesInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSimpleNoPropertiesInterfaceInterface
 */
class TBSIMPLEAPI_API ITbSimpleNoPropertiesInterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface")
	virtual UTbSimpleNoPropertiesInterfacePublisher* _GetPublisher() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Operations")
	virtual void FuncVoid() = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) = 0;
	virtual TFuture<bool> FuncBoolAsync(bool bParamBool) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface|Operations")
	virtual bool FuncBool(bool bParamBool) = 0;

	// properties
};
