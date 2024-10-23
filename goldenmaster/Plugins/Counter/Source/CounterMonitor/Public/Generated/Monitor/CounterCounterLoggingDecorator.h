
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
class COUNTERMONITOR_API UCounterCounterLoggingDecorator : public UAbstractCounterCounter
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
	FCustomTypesVector3D GetVector_Implementation() const override;

	void SetVector_Implementation(const FCustomTypesVector3D& InVector) override;

	FVector GetExternVector_Implementation() const override;

	void SetExternVector_Implementation(const FVector& InExternVector) override;

	TArray<FCustomTypesVector3D> GetVectorArray_Implementation() const override;

	void SetVectorArray_Implementation(const TArray<FCustomTypesVector3D>& InVectorArray) override;

	TArray<FVector> GetExternVectorArray_Implementation() const override;

	void SetExternVectorArray_Implementation(const TArray<FVector>& InExternVectorArray) override;

	// operations
	FVector Increment_Implementation(const FVector& Vec) override;

	TArray<FVector> IncrementArray_Implementation(const TArray<FVector>& Vec) override;

	FCustomTypesVector3D Decrement_Implementation(const FCustomTypesVector3D& Vec) override;

	TArray<FCustomTypesVector3D> DecrementArray_Implementation(const TArray<FCustomTypesVector3D>& Vec) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Counter|Counter")
	TScriptInterface<ICounterCounterInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|Counter|Counter", BlueprintInternalUseOnly)
	void OnValueChanged(const FCustomTypesVector3D& InVector, const FVector& InExternVector, const TArray<FCustomTypesVector3D>& InVectorArray, const TArray<FVector>& InExternVectorArray);

	UFUNCTION(Category = "ApiGear|Counter|Counter", BlueprintInternalUseOnly)
	void OnVectorChanged(const FCustomTypesVector3D& InVector);

	UFUNCTION(Category = "ApiGear|Counter|Counter", BlueprintInternalUseOnly)
	void OnExternVectorChanged(const FVector& InExternVector);

	UFUNCTION(Category = "ApiGear|Counter|Counter", BlueprintInternalUseOnly)
	void OnVectorArrayChanged(const TArray<FCustomTypesVector3D>& InVectorArray);

	UFUNCTION(Category = "ApiGear|Counter|Counter", BlueprintInternalUseOnly)
	void OnExternVectorArrayChanged(const TArray<FVector>& InExternVectorArray);
};
