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
#include "Counter_data.h"
#include "CounterCounterInterface.generated.h"

/**
 * Declaration for Counter
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_FourParams(FCounterCounterValueChangedDelegate, const FCustomTypesVector3D& /* Vector */, const FVector& /* ExternVector */, const TArray<FCustomTypesVector3D>& /* VectorArray */, const TArray<FVector>& /* ExternVectorArray */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FCounterCounterValueChangedDelegateBP, const FCustomTypesVector3D&, Vector, const FVector&, ExternVector, const TArray<FCustomTypesVector3D>&, VectorArray, const TArray<FVector>&, ExternVectorArray);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FCounterCounterVectorChangedDelegate, const FCustomTypesVector3D& /* Vector */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCounterCounterVectorChangedDelegateBP, const FCustomTypesVector3D&, Vector);
DECLARE_MULTICAST_DELEGATE_OneParam(FCounterCounterExternVectorChangedDelegate, const FVector& /* ExternVector */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCounterCounterExternVectorChangedDelegateBP, const FVector&, ExternVector);
DECLARE_MULTICAST_DELEGATE_OneParam(FCounterCounterVectorArrayChangedDelegate, const TArray<FCustomTypesVector3D>& /* VectorArray */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCounterCounterVectorArrayChangedDelegateBP, const TArray<FCustomTypesVector3D>&, VectorArray);
DECLARE_MULTICAST_DELEGATE_OneParam(FCounterCounterExternVectorArrayChangedDelegate, const TArray<FVector>& /* ExternVectorArray */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCounterCounterExternVectorArrayChangedDelegateBP, const TArray<FVector>&, ExternVectorArray);

/**
 * Helper interface for CounterCounter events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events and property-changed events.
 */
UINTERFACE(BlueprintType)
class UCounterCounterBPSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class COUNTERAPI_API ICounterCounterBPSubscriberInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "On ValueChanged Signal")
	void OnValueChangedSignal(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "On Property Vector Changed")
	void OnVectorChanged(UPARAM(DisplayName = "Vector") const FCustomTypesVector3D& InVector);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "On Property ExternVector Changed")
	void OnExternVectorChanged(UPARAM(DisplayName = "ExternVector") const FVector& InExternVector);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "On Property VectorArray Changed")
	void OnVectorArrayChanged(UPARAM(DisplayName = "VectorArray") const TArray<FCustomTypesVector3D>& InVectorArray);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "On Property ExternVectorArray Changed")
	void OnExternVectorArrayChanged(UPARAM(DisplayName = "ExternVectorArray") const TArray<FVector>& InExternVectorArray);
};

UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UCounterCounterSubscriberInterface : public UInterface
{
	GENERATED_BODY()
};

class COUNTERAPI_API ICounterCounterSubscriberInterface
{
	GENERATED_BODY()
public:
	virtual void OnValueChangedSignal(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray) = 0;

	virtual void OnVectorChanged(UPARAM(DisplayName = "Vector") const FCustomTypesVector3D& InVector) = 0;

	virtual void OnExternVectorChanged(UPARAM(DisplayName = "ExternVector") const FVector& InExternVector) = 0;

	virtual void OnVectorArrayChanged(UPARAM(DisplayName = "VectorArray") const TArray<FCustomTypesVector3D>& InVectorArray) = 0;

	virtual void OnExternVectorArrayChanged(UPARAM(DisplayName = "ExternVectorArray") const TArray<FVector>& InExternVectorArray) = 0;
};

/**
 * Class UCounterCounterInterfacePublisher
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class COUNTERAPI_API UCounterCounterPublisher : public UObject
{
	GENERATED_BODY()

public:
	FCounterCounterValueChangedDelegate OnValueChangedSignal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "ValueChanged Signal")
	FCounterCounterValueChangedDelegateBP OnValueChangedSignalBP;
	/// C++ wrapper for BP functions to safely call ValueChangedSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Broadcast ValueChanged Signal")
	void BroadcastValueChangedSignal(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray);

	FCounterCounterVectorChangedDelegate OnVectorChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Property Vector Changed")
	FCounterCounterVectorChangedDelegateBP OnVectorChangedBP;
	/// C++ wrapper for BP functions to safely call OnVectorChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Broadcast Property Vector Changed")
	void BroadcastVectorChanged(UPARAM(DisplayName = "Vector") const FCustomTypesVector3D& InVector);

	FCounterCounterExternVectorChangedDelegate OnExternVectorChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Property ExternVector Changed")
	FCounterCounterExternVectorChangedDelegateBP OnExternVectorChangedBP;
	/// C++ wrapper for BP functions to safely call OnExternVectorChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Broadcast Property ExternVector Changed")
	void BroadcastExternVectorChanged(UPARAM(DisplayName = "ExternVector") const FVector& InExternVector);

	FCounterCounterVectorArrayChangedDelegate OnVectorArrayChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Property VectorArray Changed")
	FCounterCounterVectorArrayChangedDelegateBP OnVectorArrayChangedBP;
	/// C++ wrapper for BP functions to safely call OnVectorArrayChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Broadcast Property VectorArray Changed")
	void BroadcastVectorArrayChanged(UPARAM(DisplayName = "VectorArray") const TArray<FCustomTypesVector3D>& InVectorArray);

	FCounterCounterExternVectorArrayChangedDelegate OnExternVectorArrayChanged;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Property ExternVectorArray Changed")
	FCounterCounterExternVectorArrayChangedDelegateBP OnExternVectorArrayChangedBP;
	/// C++ wrapper for BP functions to safely call OnExternVectorArrayChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Broadcast Property ExternVectorArray Changed")
	void BroadcastExternVectorArrayChanged(UPARAM(DisplayName = "ExternVectorArray") const TArray<FVector>& InExternVectorArray);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Signals")
	void Subscribe(const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber);
	void Subscribe(const TWeakInterfacePtr<ICounterCounterSubscriberInterface>& Subscriber);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Signals")
	void Unsubscribe(const TScriptInterface<ICounterCounterBPSubscriberInterface>& Subscriber);
	void Unsubscribe(const TWeakInterfacePtr<ICounterCounterSubscriberInterface>& Subscriber);

private:
	UPROPERTY()
	TArray<TScriptInterface<ICounterCounterBPSubscriberInterface>> BPSubscribers;
	FRWLock BPSubscribersLock;
	TArray<TWeakInterfacePtr<ICounterCounterSubscriberInterface>> Subscribers;
	FRWLock SubscribersLock;
};

/**
 * Interface UCounterCounterInterface only for Unreal Engine's reflection system
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UCounterCounterInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ICounterCounterInterface
 */
class COUNTERAPI_API ICounterCounterInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter")
	virtual UCounterCounterPublisher* _GetPublisher() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void IncrementAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FVector& Result, const FVector& Vec) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Operations")
	virtual FVector Increment(const FVector& Vec) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void IncrementArrayAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FVector>& Result, const TArray<FVector>& Vec) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Operations")
	virtual TArray<FVector> IncrementArray(const TArray<FVector>& Vec) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void DecrementAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FCustomTypesVector3D& Result, const FCustomTypesVector3D& Vec) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Operations")
	virtual FCustomTypesVector3D Decrement(const FCustomTypesVector3D& Vec) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void DecrementArrayAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FCustomTypesVector3D>& Result, const TArray<FCustomTypesVector3D>& Vec) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Operations")
	virtual TArray<FCustomTypesVector3D> DecrementArray(const TArray<FCustomTypesVector3D>& Vec) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Properties")
	virtual FCustomTypesVector3D GetVector() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Properties")
	virtual void SetVector(UPARAM(DisplayName = "Vector") const FCustomTypesVector3D& InVector) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Properties")
	virtual FVector GetExternVector() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Properties")
	virtual void SetExternVector(UPARAM(DisplayName = "ExternVector") const FVector& InExternVector) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Properties")
	virtual TArray<FCustomTypesVector3D> GetVectorArray() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Properties")
	virtual void SetVectorArray(UPARAM(DisplayName = "VectorArray") const TArray<FCustomTypesVector3D>& InVectorArray) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Properties")
	virtual TArray<FVector> GetExternVectorArray() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Properties")
	virtual void SetExternVectorArray(UPARAM(DisplayName = "ExternVectorArray") const TArray<FVector>& InExternVectorArray) = 0;
};
