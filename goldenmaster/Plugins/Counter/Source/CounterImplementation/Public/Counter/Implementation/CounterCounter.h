
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
#include "Counter/Generated/api/AbstractCounterCounter.h"
#include "CounterCounter.generated.h"

UCLASS(BlueprintType)
class COUNTERIMPLEMENTATION_API UCounterCounter : public UAbstractCounterCounter
{
	GENERATED_BODY()
public:
	virtual ~UCounterCounter();

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
