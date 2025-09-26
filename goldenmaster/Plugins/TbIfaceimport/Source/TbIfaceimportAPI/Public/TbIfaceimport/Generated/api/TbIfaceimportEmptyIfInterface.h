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
#include "TbIfaceimport_data.h"
#include "TbIfaceimportEmptyIfInterface.generated.h"

/**
 * Declaration for EmptyIf
 */
// signal delegates
// property delegates

/**
 * Helper interface for TbIfaceimportEmptyIf events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events and property-changed events.
 */
UINTERFACE(BlueprintType)
class UTbIfaceimportEmptyIfBPSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBIFACEIMPORTAPI_API ITbIfaceimportEmptyIfBPSubscriberInterface
{
	GENERATED_BODY()

public:
};

UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbIfaceimportEmptyIfSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class TBIFACEIMPORTAPI_API ITbIfaceimportEmptyIfSubscriberInterface
{
	GENERATED_BODY()
public:
};

/**
 * Class UTbIfaceimportEmptyIfInterfacePublisher
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBIFACEIMPORTAPI_API UTbIfaceimportEmptyIfPublisher : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf|Signals")
	void Subscribe(const TScriptInterface<ITbIfaceimportEmptyIfBPSubscriberInterface>& Subscriber);
	void Subscribe(const TWeakInterfacePtr<ITbIfaceimportEmptyIfSubscriberInterface>& Subscriber);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf|Signals")
	void Unsubscribe(const TScriptInterface<ITbIfaceimportEmptyIfBPSubscriberInterface>& Subscriber);
	void Unsubscribe(const TWeakInterfacePtr<ITbIfaceimportEmptyIfSubscriberInterface>& Subscriber);

private:
	void CleanUpSubscribers();

	TArray<TScriptInterface<ITbIfaceimportEmptyIfBPSubscriberInterface>> BPSubscribers;
	FRWLock BPSubscribersLock;
	TArray<TWeakInterfacePtr<ITbIfaceimportEmptyIfSubscriberInterface>> Subscribers;
	FRWLock SubscribersLock;
};

/**
 * Interface UTbIfaceimportEmptyIfInterface only for Unreal Engine's reflection system
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbIfaceimportEmptyIfInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbIfaceimportEmptyIfInterface
 */
class TBIFACEIMPORTAPI_API ITbIfaceimportEmptyIfInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbIfaceimport|EmptyIf")
	virtual UTbIfaceimportEmptyIfPublisher* _GetPublisher() = 0;

	// methods

	// properties
};
