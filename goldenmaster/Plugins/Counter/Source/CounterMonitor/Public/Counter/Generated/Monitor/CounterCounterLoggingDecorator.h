
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

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Counter/Generated/api/AbstractCounterCounter.h"
#include "CounterCounterLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogCounterCounterLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class COUNTERMONITOR_API UCounterCounterLoggingDecorator : public UAbstractCounterCounter, public ICounterCounterSubscriberInterface
{
	GENERATED_BODY()

public:
	explicit UCounterCounterLoggingDecorator();
	virtual ~UCounterCounterLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter")
	void setBackendService(TScriptInterface<ICounterCounterInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	FCustomTypesVector3D GetVector() const override;

	void SetVector(const FCustomTypesVector3D& InVector) override;

	FVector GetExternVector() const override;

	void SetExternVector(const FVector& InExternVector) override;

	TArray<FCustomTypesVector3D> GetVectorArray() const override;

	void SetVectorArray(const TArray<FCustomTypesVector3D>& InVectorArray) override;

	TArray<FVector> GetExternVectorArray() const override;

	void SetExternVectorArray(const TArray<FVector>& InExternVectorArray) override;

	// operations
	FVector Increment(const FVector& Vec) override;

	TArray<FVector> IncrementArray(const TArray<FVector>& Vec) override;

	FCustomTypesVector3D Decrement(const FCustomTypesVector3D& Vec) override;

	TArray<FCustomTypesVector3D> DecrementArray(const TArray<FCustomTypesVector3D>& Vec) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Counter|Counter")
	TScriptInterface<ICounterCounterInterface> BackendService;

	// signals
	void OnValueChangedSignal(const FCustomTypesVector3D& InVector, const FVector& InExternVector, const TArray<FCustomTypesVector3D>& InVectorArray, const TArray<FVector>& InExternVectorArray);

	void OnVectorChanged(const FCustomTypesVector3D& InVector);

	void OnExternVectorChanged(const FVector& InExternVector);

	void OnVectorArrayChanged(const TArray<FCustomTypesVector3D>& InVectorArray);

	void OnExternVectorArrayChanged(const TArray<FVector>& InExternVectorArray);
};
