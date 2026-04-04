// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "Counter/Generated/api/AbstractCounterCounter.h"
#include "CounterCounter.generated.h"

UCLASS(BlueprintType)
class COUNTERIMPLEMENTATION_API UCounterCounterImplementation : public UAbstractCounterCounter
{
	GENERATED_BODY()
public:
	virtual ~UCounterCounterImplementation();

	// properties
	FCustomTypesVector3D GetVector() const override;
	void SetVector(const FCustomTypesVector3D& Vector) override;

	FVector GetExternVector() const override;
	void SetExternVector(const FVector& ExternVector) override;

	TArray<FCustomTypesVector3D> GetVectorArray() const override;
	void SetVectorArray(const TArray<FCustomTypesVector3D>& VectorArray) override;

	TArray<FVector> GetExternVectorArray() const override;
	void SetExternVectorArray(const TArray<FVector>& ExternVectorArray) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Properties")
	void _ResetProperties();

	// operations
	FVector Increment(const FVector& Vec) override;

	TArray<FVector> IncrementArray(const TArray<FVector>& Vec) override;

	FCustomTypesVector3D Decrement(const FCustomTypesVector3D& Vec) override;

	TArray<FCustomTypesVector3D> DecrementArray(const TArray<FCustomTypesVector3D>& Vec) override;
};
