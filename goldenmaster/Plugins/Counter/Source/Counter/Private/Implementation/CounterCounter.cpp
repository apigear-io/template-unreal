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

#include "Implementation/CounterCounter.h"

UCounterCounter::~UCounterCounter() = default;
FCustomTypesVector3D UCounterCounter::GetVector_Implementation() const
{
	return Vector;
}

void UCounterCounter::SetVector_Implementation(const FCustomTypesVector3D& InVector)
{
	if (Vector != InVector)
	{
		Vector = InVector;
		Execute__GetSignals(this)->OnVectorChanged.Broadcast(Vector);
	}
}
FVector UCounterCounter::GetExternVector_Implementation() const
{
	return ExternVector;
}

void UCounterCounter::SetExternVector_Implementation(const FVector& InExternVector)
{
	if (ExternVector != InExternVector)
	{
		ExternVector = InExternVector;
		Execute__GetSignals(this)->OnExternVectorChanged.Broadcast(ExternVector);
	}
}
TArray<FCustomTypesVector3D> UCounterCounter::GetVectorArray_Implementation() const
{
	return VectorArray;
}

void UCounterCounter::SetVectorArray_Implementation(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	if (VectorArray != InVectorArray)
	{
		VectorArray = InVectorArray;
		Execute__GetSignals(this)->OnVectorArrayChanged.Broadcast(VectorArray);
	}
}
TArray<FVector> UCounterCounter::GetExternVectorArray_Implementation() const
{
	return ExternVectorArray;
}

void UCounterCounter::SetExternVectorArray_Implementation(const TArray<FVector>& InExternVectorArray)
{
	if (ExternVectorArray != InExternVectorArray)
	{
		ExternVectorArray = InExternVectorArray;
		Execute__GetSignals(this)->OnExternVectorArrayChanged.Broadcast(ExternVectorArray);
	}
}

FVector UCounterCounter::Increment_Implementation(const FVector& Vec)
{
	(void)Vec;
	// do business logic here
	return FVector(0.f,0.f,0.f);
}

TArray<FVector> UCounterCounter::IncrementArray_Implementation(const TArray<FVector>& Vec)
{
	(void)Vec;
	// do business logic here
	return TArray<FVector>();
}

FCustomTypesVector3D UCounterCounter::Decrement_Implementation(const FCustomTypesVector3D& Vec)
{
	(void)Vec;
	// do business logic here
	return FCustomTypesVector3D();
}

TArray<FCustomTypesVector3D> UCounterCounter::DecrementArray_Implementation(const TArray<FCustomTypesVector3D>& Vec)
{
	(void)Vec;
	// do business logic here
	return TArray<FCustomTypesVector3D>();
}
