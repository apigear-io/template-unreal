
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
#include "Generated/api/AbstractCounterCounter.h"
#include "CounterCounter.generated.h"

UCLASS(BlueprintType)
class COUNTER_API UCounterCounter : public UAbstractCounterCounter
{
	GENERATED_BODY()
public:
	virtual ~UCounterCounter();

	// properties
	FCustomTypesVector3D GetVector_Implementation() const override;
	void SetVector_Implementation(const FCustomTypesVector3D& Vector) override;

	FVector GetExternVector_Implementation() const override;
	void SetExternVector_Implementation(const FVector& ExternVector) override;

	TArray<FCustomTypesVector3D> GetVectorArray_Implementation() const override;
	void SetVectorArray_Implementation(const TArray<FCustomTypesVector3D>& VectorArray) override;

	TArray<FVector> GetExternVectorArray_Implementation() const override;
	void SetExternVectorArray_Implementation(const TArray<FVector>& ExternVectorArray) override;

	// operations
	FVector Increment_Implementation(const FVector& Vec) override;

	TArray<FVector> IncrementArray_Implementation(const TArray<FVector>& Vec) override;

	FCustomTypesVector3D Decrement_Implementation(const FCustomTypesVector3D& Vec) override;

	TArray<FCustomTypesVector3D> DecrementArray_Implementation(const TArray<FCustomTypesVector3D>& Vec) override;
};
