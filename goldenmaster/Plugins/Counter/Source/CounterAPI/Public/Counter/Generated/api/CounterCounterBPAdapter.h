/**
Copyright 2024 ApiGear UG
Copyright 2024 Epic Games, Inc.

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

#include "Runtime/Launch/Resources/Version.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Counter_data.h"
#include "Counter/Generated/api/CounterCounterInterface.h"
#include "Counter/Generated/api/CounterCounterBPInterface.h"
#include "CounterCounterBPAdapter.generated.h"

/**
 * Adapter UCounterCounterBPAdapter from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class COUNTERAPI_API UCounterCounterBPAdapter : public UObject, public ICounterCounterInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "ApiGear|Counter|Counter")
	TScriptInterface<ICounterCounterBPInterface> Target;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter")
	void Initialize(TScriptInterface<ICounterCounterBPInterface> InTarget);

	// signals
	UCounterCounterPublisher* _GetPublisher() override;

	// methods
	void IncrementAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FVector& Result, const FVector& Vec) override;
	TFuture<FVector> IncrementAsync(const FVector& Vec) override;
	FVector Increment(const FVector& Vec) override;

	void IncrementArrayAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FVector>& Result, const TArray<FVector>& Vec) override;
	TFuture<TArray<FVector>> IncrementArrayAsync(const TArray<FVector>& Vec) override;
	TArray<FVector> IncrementArray(const TArray<FVector>& Vec) override;

	void DecrementAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FCustomTypesVector3D& Result, const FCustomTypesVector3D& Vec) override;
	TFuture<FCustomTypesVector3D> DecrementAsync(const FCustomTypesVector3D& Vec) override;
	FCustomTypesVector3D Decrement(const FCustomTypesVector3D& Vec) override;

	void DecrementArrayAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FCustomTypesVector3D>& Result, const TArray<FCustomTypesVector3D>& Vec) override;
	TFuture<TArray<FCustomTypesVector3D>> DecrementArrayAsync(const TArray<FCustomTypesVector3D>& Vec) override;
	TArray<FCustomTypesVector3D> DecrementArray(const TArray<FCustomTypesVector3D>& Vec) override;

	// properties
	FCustomTypesVector3D GetVector() const override;
	void SetVector(const FCustomTypesVector3D& InVector) override;

	FVector GetExternVector() const override;
	void SetExternVector(const FVector& InExternVector) override;

	TArray<FCustomTypesVector3D> GetVectorArray() const override;
	void SetVectorArray(const TArray<FCustomTypesVector3D>& InVectorArray) override;

	TArray<FVector> GetExternVectorArray() const override;
	void SetExternVectorArray(const TArray<FVector>& InExternVectorArray) override;
};
