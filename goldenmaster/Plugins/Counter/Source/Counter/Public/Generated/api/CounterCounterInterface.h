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
#include "Generated/api/Counter_data.h"
#include "Generated/api/CustomTypes_data.h"
#include "Generated/api/ExternTypes_data.h"
#include "CounterCounterInterface.generated.h"

/**
 * Declaration for Counter
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FCounterCounterValueChangedDelegate, const FCustomTypesVector3D&, Vector, const FVector&, ExternVector, const TArray<FCustomTypesVector3D>&, VectorArray, const TArray<FVector>&, ExternVectorArray);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCounterCounterVectorChangedDelegate, const FCustomTypesVector3D&, Vector);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCounterCounterExternVectorChangedDelegate, const FVector&, ExternVector);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCounterCounterVectorArrayChangedDelegate, const TArray<FCustomTypesVector3D>&, VectorArray);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCounterCounterExternVectorArrayChangedDelegate, const TArray<FVector>&, ExternVectorArray);

/**
 * Class UCounterCounterInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class COUNTER_API UCounterCounterSignals : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "ValueChanged Signal")
	FCounterCounterValueChangedDelegate OnValueChangedSignal;
	/// C++ wrapper for BP functions to safely call ValueChangedSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Broadcast ValueChanged Signal")
	void BroadcastValueChangedSignal(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray)
	{
		OnValueChangedSignal.Broadcast(Vector, ExternVector, VectorArray, ExternVectorArray);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Property Vector Changed")
	FCounterCounterVectorChangedDelegate OnVectorChanged;
	/// C++ wrapper for BP functions to safely call OnVectorChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Broadcast Property Vector Changed")
	void BroadcastVectorChanged(UPARAM(DisplayName = "Vector") const FCustomTypesVector3D& InVector)
	{
		OnVectorChanged.Broadcast(InVector);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Property ExternVector Changed")
	FCounterCounterExternVectorChangedDelegate OnExternVectorChanged;
	/// C++ wrapper for BP functions to safely call OnExternVectorChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Broadcast Property ExternVector Changed")
	void BroadcastExternVectorChanged(UPARAM(DisplayName = "ExternVector") const FVector& InExternVector)
	{
		OnExternVectorChanged.Broadcast(InExternVector);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Property VectorArray Changed")
	FCounterCounterVectorArrayChangedDelegate OnVectorArrayChanged;
	/// C++ wrapper for BP functions to safely call OnVectorArrayChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Broadcast Property VectorArray Changed")
	void BroadcastVectorArrayChanged(UPARAM(DisplayName = "VectorArray") const TArray<FCustomTypesVector3D>& InVectorArray)
	{
		OnVectorArrayChanged.Broadcast(InVectorArray);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Property ExternVectorArray Changed")
	FCounterCounterExternVectorArrayChangedDelegate OnExternVectorArrayChanged;
	/// C++ wrapper for BP functions to safely call OnExternVectorArrayChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Signals", DisplayName = "Broadcast Property ExternVectorArray Changed")
	void BroadcastExternVectorArrayChanged(UPARAM(DisplayName = "ExternVectorArray") const TArray<FVector>& InExternVectorArray)
	{
		OnExternVectorArrayChanged.Broadcast(InExternVectorArray);
	}
};

/**
 * Interface UCounterCounterInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UCounterCounterInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ICounterCounterInterface
 */
class COUNTER_API ICounterCounterInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Counter|Counter")
	UCounterCounterSignals* _GetSignals();
	virtual UCounterCounterSignals* _GetSignals_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Counter|Counter|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void IncrementAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FVector& Result, const FVector& Vec);
	virtual void IncrementAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FVector& Result, const FVector& Vec) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Counter|Counter|Operations")
	FVector Increment(const FVector& Vec);
	virtual FVector Increment_Implementation(const FVector& Vec) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Counter|Counter|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void IncrementArrayAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FVector>& Result, const TArray<FVector>& Vec);
	virtual void IncrementArrayAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FVector>& Result, const TArray<FVector>& Vec) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Counter|Counter|Operations")
	TArray<FVector> IncrementArray(const TArray<FVector>& Vec);
	virtual TArray<FVector> IncrementArray_Implementation(const TArray<FVector>& Vec) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Counter|Counter|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void DecrementAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FCustomTypesVector3D& Result, const FCustomTypesVector3D& Vec);
	virtual void DecrementAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FCustomTypesVector3D& Result, const FCustomTypesVector3D& Vec) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Counter|Counter|Operations")
	FCustomTypesVector3D Decrement(const FCustomTypesVector3D& Vec);
	virtual FCustomTypesVector3D Decrement_Implementation(const FCustomTypesVector3D& Vec) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Counter|Counter|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void DecrementArrayAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FCustomTypesVector3D>& Result, const TArray<FCustomTypesVector3D>& Vec);
	virtual void DecrementArrayAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FCustomTypesVector3D>& Result, const TArray<FCustomTypesVector3D>& Vec) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Counter|Counter|Operations")
	TArray<FCustomTypesVector3D> DecrementArray(const TArray<FCustomTypesVector3D>& Vec);
	virtual TArray<FCustomTypesVector3D> DecrementArray_Implementation(const TArray<FCustomTypesVector3D>& Vec) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Counter|Counter|Properties")
	FCustomTypesVector3D GetVector() const;
	virtual FCustomTypesVector3D GetVector_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Counter|Counter|Properties")
	void SetVector(const FCustomTypesVector3D& InVector);
	virtual void SetVector_Implementation(UPARAM(DisplayName = "Vector") const FCustomTypesVector3D& InVector) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Counter|Counter|Properties")
	FVector GetExternVector() const;
	virtual FVector GetExternVector_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Counter|Counter|Properties")
	void SetExternVector(const FVector& InExternVector);
	virtual void SetExternVector_Implementation(UPARAM(DisplayName = "ExternVector") const FVector& InExternVector) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Counter|Counter|Properties")
	TArray<FCustomTypesVector3D> GetVectorArray() const;
	virtual TArray<FCustomTypesVector3D> GetVectorArray_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Counter|Counter|Properties")
	void SetVectorArray(const TArray<FCustomTypesVector3D>& InVectorArray);
	virtual void SetVectorArray_Implementation(UPARAM(DisplayName = "VectorArray") const TArray<FCustomTypesVector3D>& InVectorArray) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Counter|Counter|Properties")
	TArray<FVector> GetExternVectorArray() const;
	virtual TArray<FVector> GetExternVectorArray_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Counter|Counter|Properties")
	void SetExternVectorArray(const TArray<FVector>& InExternVectorArray);
	virtual void SetExternVectorArray_Implementation(UPARAM(DisplayName = "ExternVectorArray") const TArray<FVector>& InExternVectorArray) = 0;
};
