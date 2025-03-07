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
#include "CounterCounterInterface.h"
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "Counter_data.h"
#include "CustomTypes/Generated/api/CustomTypes_data.h"
#include "ExternTypes/Generated/api/ExternTypes_data.h"
#include "CounterCounterBPInterface.generated.h"

/**
 * Interface UCounterCounterBPInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UCounterCounterBPInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ICounterCounterBPInterface
 */
class COUNTERAPI_API ICounterCounterBPInterface
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
