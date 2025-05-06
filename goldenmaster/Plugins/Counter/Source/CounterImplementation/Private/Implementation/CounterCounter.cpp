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

#include "Counter/Implementation/CounterCounter.h"

UCounterCounter::~UCounterCounter() = default;
FCustomTypesVector3D UCounterCounter::GetVector() const
{
	return Vector;
}

void UCounterCounter::SetVector(const FCustomTypesVector3D& InVector)
{
	if (Vector != InVector)
	{
		Vector = InVector;
		_GetSignals()->BroadcastVectorChanged(Vector);
	}
}
FVector UCounterCounter::GetExternVector() const
{
	return ExternVector;
}

void UCounterCounter::SetExternVector(const FVector& InExternVector)
{
	if (ExternVector != InExternVector)
	{
		ExternVector = InExternVector;
		_GetSignals()->BroadcastExternVectorChanged(ExternVector);
	}
}
TArray<FCustomTypesVector3D> UCounterCounter::GetVectorArray() const
{
	return VectorArray;
}

void UCounterCounter::SetVectorArray(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	if (VectorArray != InVectorArray)
	{
		VectorArray = InVectorArray;
		_GetSignals()->BroadcastVectorArrayChanged(VectorArray);
	}
}
TArray<FVector> UCounterCounter::GetExternVectorArray() const
{
	return ExternVectorArray;
}

void UCounterCounter::SetExternVectorArray(const TArray<FVector>& InExternVectorArray)
{
	if (ExternVectorArray != InExternVectorArray)
	{
		ExternVectorArray = InExternVectorArray;
		_GetSignals()->BroadcastExternVectorArrayChanged(ExternVectorArray);
	}
}

FVector UCounterCounter::Increment(const FVector& Vec)
{
	(void)Vec;
	// do business logic here
	return FVector(0.f, 0.f, 0.f);
}

TArray<FVector> UCounterCounter::IncrementArray(const TArray<FVector>& Vec)
{
	(void)Vec;
	// do business logic here
	return TArray<FVector>();
}

FCustomTypesVector3D UCounterCounter::Decrement(const FCustomTypesVector3D& Vec)
{
	(void)Vec;
	// do business logic here
	return FCustomTypesVector3D();
}

TArray<FCustomTypesVector3D> UCounterCounter::DecrementArray(const TArray<FCustomTypesVector3D>& Vec)
{
	(void)Vec;
	// do business logic here
	return TArray<FCustomTypesVector3D>();
}

void UCounterCounter::_ResetProperties()
{
	if (Vector != FCustomTypesVector3D())
	{
		Vector = FCustomTypesVector3D();
		_GetSignals()->BroadcastVectorChanged(Vector);
	}
	if (ExternVector != FVector(0.f, 0.f, 0.f))
	{
		ExternVector = FVector(0.f, 0.f, 0.f);
		_GetSignals()->BroadcastExternVectorChanged(ExternVector);
	}
	if (VectorArray != TArray<FCustomTypesVector3D>())
	{
		VectorArray = TArray<FCustomTypesVector3D>();
		_GetSignals()->BroadcastVectorArrayChanged(VectorArray);
	}
	if (ExternVectorArray != TArray<FVector>())
	{
		ExternVectorArray = TArray<FVector>();
		_GetSignals()->BroadcastExternVectorArrayChanged(ExternVectorArray);
	}
}
