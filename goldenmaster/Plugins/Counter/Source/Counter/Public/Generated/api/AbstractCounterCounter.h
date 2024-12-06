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
#include "Generated/api/Counter_data.h"
#include "Generated/api/CounterCounterInterface.h"
#include "AbstractCounterCounter.generated.h"

/**
 * Abstract UAbstractCounterCounter
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class COUNTER_API UAbstractCounterCounter : public UGameInstanceSubsystem, public ICounterCounterInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractCounterCounter();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UCounterCounterSignals* _GetSignals_Implementation() override;

	// methods
	virtual void IncrementAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FVector& Result, const FVector& Vec) override;
	virtual FVector Increment_Implementation(const FVector& Vec) override PURE_VIRTUAL(UAbstractCounterCounter::Increment_Implementation, return FVector(0.f, 0.f, 0.f););

	virtual void IncrementArrayAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FVector>& Result, const TArray<FVector>& Vec) override;
	virtual TArray<FVector> IncrementArray_Implementation(const TArray<FVector>& Vec) override PURE_VIRTUAL(UAbstractCounterCounter::IncrementArray_Implementation, return TArray<FVector>(););

	virtual void DecrementAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FCustomTypesVector3D& Result, const FCustomTypesVector3D& Vec) override;
	virtual FCustomTypesVector3D Decrement_Implementation(const FCustomTypesVector3D& Vec) override PURE_VIRTUAL(UAbstractCounterCounter::Decrement_Implementation, return FCustomTypesVector3D(););

	virtual void DecrementArrayAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FCustomTypesVector3D>& Result, const TArray<FCustomTypesVector3D>& Vec) override;
	virtual TArray<FCustomTypesVector3D> DecrementArray_Implementation(const TArray<FCustomTypesVector3D>& Vec) override PURE_VIRTUAL(UAbstractCounterCounter::DecrementArray_Implementation, return TArray<FCustomTypesVector3D>(););

	// properties
	virtual FCustomTypesVector3D GetVector_Implementation() const override PURE_VIRTUAL(UAbstractCounterCounter::GetVector_Implementation, return FCustomTypesVector3D(););
	virtual void SetVector_Implementation(const FCustomTypesVector3D& InVector) override PURE_VIRTUAL(UAbstractCounterCounter::SetVector_Implementation, return;);

	virtual FVector GetExternVector_Implementation() const override PURE_VIRTUAL(UAbstractCounterCounter::GetExternVector_Implementation, return FVector(0.f, 0.f, 0.f););
	virtual void SetExternVector_Implementation(const FVector& InExternVector) override PURE_VIRTUAL(UAbstractCounterCounter::SetExternVector_Implementation, return;);

	virtual TArray<FCustomTypesVector3D> GetVectorArray_Implementation() const override PURE_VIRTUAL(UAbstractCounterCounter::GetVectorArray_Implementation, return TArray<FCustomTypesVector3D>(););
	virtual void SetVectorArray_Implementation(const TArray<FCustomTypesVector3D>& InVectorArray) override PURE_VIRTUAL(UAbstractCounterCounter::SetVectorArray_Implementation, return;);

	virtual TArray<FVector> GetExternVectorArray_Implementation() const override PURE_VIRTUAL(UAbstractCounterCounter::GetExternVectorArray_Implementation, return TArray<FVector>(););
	virtual void SetExternVectorArray_Implementation(const TArray<FVector>& InExternVectorArray) override PURE_VIRTUAL(UAbstractCounterCounter::SetExternVectorArray_Implementation, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetVector_Private, BlueprintSetter = SetVector_Private, Category = "ApiGear|Counter|Counter")
	FCustomTypesVector3D Vector{FCustomTypesVector3D()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Counter|Counter|Properties", BlueprintInternalUseOnly)
	FCustomTypesVector3D GetVector_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Counter|Counter|Properties", BlueprintInternalUseOnly)
	void SetVector_Private(const FCustomTypesVector3D& InVector);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetExternVector_Private, BlueprintSetter = SetExternVector_Private, Category = "ApiGear|Counter|Counter")
	FVector ExternVector{FVector(0.f, 0.f, 0.f)};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Counter|Counter|Properties", BlueprintInternalUseOnly)
	FVector GetExternVector_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Counter|Counter|Properties", BlueprintInternalUseOnly)
	void SetExternVector_Private(const FVector& InExternVector);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetVectorArray_Private, BlueprintSetter = SetVectorArray_Private, Category = "ApiGear|Counter|Counter")
	TArray<FCustomTypesVector3D> VectorArray{TArray<FCustomTypesVector3D>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Counter|Counter|Properties", BlueprintInternalUseOnly)
	TArray<FCustomTypesVector3D> GetVectorArray_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Counter|Counter|Properties", BlueprintInternalUseOnly)
	void SetVectorArray_Private(const TArray<FCustomTypesVector3D>& InVectorArray);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetExternVectorArray_Private, BlueprintSetter = SetExternVectorArray_Private, Category = "ApiGear|Counter|Counter")
	TArray<FVector> ExternVectorArray{TArray<FVector>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Counter|Counter|Properties", BlueprintInternalUseOnly)
	TArray<FVector> GetExternVectorArray_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Counter|Counter|Properties", BlueprintInternalUseOnly)
	void SetExternVectorArray_Private(const TArray<FVector>& InExternVectorArray);

private:
	// signals
	UPROPERTY()
	UCounterCounterSignals* CounterCounterSignals;
};
