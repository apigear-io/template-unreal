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
#include "TbSimple_data.h"
#include "TbSimpleVoidInterfaceInterface.generated.h"

/**
 * Declaration for VoidInterface
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE(FTbSimpleVoidInterfaceSigVoidDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTbSimpleVoidInterfaceSigVoidDelegateBP);

// property delegates

/**
 * Helper interface for TbSimpleVoidInterface events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events and property-changed events.
 */
UINTERFACE(BlueprintType)
class UTbSimpleVoidInterfaceBPSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSIMPLEAPI_API ITbSimpleVoidInterfaceBPSubscriberInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|TbSimple|VoidInterface|Signals", DisplayName = "On SigVoid Signal")
	void OnSigVoidSignal();
};

UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSimpleVoidInterfaceSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBSIMPLEAPI_API ITbSimpleVoidInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	virtual void OnSigVoidSignal() = 0;
};

/**
 * Class UTbSimpleVoidInterfaceInterfacePublisher
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBSIMPLEAPI_API UTbSimpleVoidInterfacePublisher : public UObject
{
	GENERATED_BODY()

public:
	FTbSimpleVoidInterfaceSigVoidDelegate OnSigVoidSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|VoidInterface|Signals", DisplayName = "SigVoid Signal")
	FTbSimpleVoidInterfaceSigVoidDelegateBP OnSigVoidSignalBP;
	/// C++ wrapper for BP functions to safely call SigVoidSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|VoidInterface|Signals", DisplayName = "Broadcast SigVoid Signal")
	void BroadcastSigVoidSignal();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|VoidInterface|Signals")
	void Subscribe(const TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>& Subscriber);
	void Subscribe(const TWeakInterfacePtr<ITbSimpleVoidInterfaceSubscriberInterface>& Subscriber);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|VoidInterface|Signals")
	void Unsubscribe(const TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>& Subscriber);
	void Unsubscribe(const TWeakInterfacePtr<ITbSimpleVoidInterfaceSubscriberInterface>& Subscriber);

private:
	UPROPERTY()
	TArray<TScriptInterface<ITbSimpleVoidInterfaceBPSubscriberInterface>> BPSubscribers;
	FRWLock BPSubscribersLock;
	TArray<TWeakInterfacePtr<ITbSimpleVoidInterfaceSubscriberInterface>> Subscribers;
	FRWLock SubscribersLock;
};

/**
 * Interface UTbSimpleVoidInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSimpleVoidInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSimpleVoidInterfaceInterface
 */
class TBSIMPLEAPI_API ITbSimpleVoidInterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|VoidInterface")
	virtual UTbSimpleVoidInterfacePublisher* _GetPublisher() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|VoidInterface|Operations")
	virtual void FuncVoid() = 0;

	// properties
};
