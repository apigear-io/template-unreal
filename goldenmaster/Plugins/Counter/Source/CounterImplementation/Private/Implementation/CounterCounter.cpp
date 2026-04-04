// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Counter/Implementation/CounterCounter.h"

UCounterCounterImplementation::~UCounterCounterImplementation() = default;
FCustomTypesVector3D UCounterCounterImplementation::GetVector() const
{
	return Vector;
}

void UCounterCounterImplementation::SetVector(const FCustomTypesVector3D& InVector)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Counter.Counter.Impl.SetVector");
	if (Vector != InVector)
	{
		Vector = InVector;
		_GetPublisher()->BroadcastVectorChanged(Vector);
	}
}
FVector UCounterCounterImplementation::GetExternVector() const
{
	return ExternVector;
}

void UCounterCounterImplementation::SetExternVector(const FVector& InExternVector)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Counter.Counter.Impl.SetExternVector");
	if (ExternVector != InExternVector)
	{
		ExternVector = InExternVector;
		_GetPublisher()->BroadcastExternVectorChanged(ExternVector);
	}
}
TArray<FCustomTypesVector3D> UCounterCounterImplementation::GetVectorArray() const
{
	return VectorArray;
}

void UCounterCounterImplementation::SetVectorArray(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Counter.Counter.Impl.SetVectorArray");
	if (VectorArray != InVectorArray)
	{
		VectorArray = InVectorArray;
		_GetPublisher()->BroadcastVectorArrayChanged(VectorArray);
	}
}
TArray<FVector> UCounterCounterImplementation::GetExternVectorArray() const
{
	return ExternVectorArray;
}

void UCounterCounterImplementation::SetExternVectorArray(const TArray<FVector>& InExternVectorArray)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Counter.Counter.Impl.SetExternVectorArray");
	if (ExternVectorArray != InExternVectorArray)
	{
		ExternVectorArray = InExternVectorArray;
		_GetPublisher()->BroadcastExternVectorArrayChanged(ExternVectorArray);
	}
}

FVector UCounterCounterImplementation::Increment(const FVector& Vec)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Counter.Counter.Impl.Increment");
	(void)Vec;
	// do business logic here
	return FVector(0.f, 0.f, 0.f);
}

TArray<FVector> UCounterCounterImplementation::IncrementArray(const TArray<FVector>& Vec)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Counter.Counter.Impl.IncrementArray");
	(void)Vec;
	// do business logic here
	return TArray<FVector>();
}

FCustomTypesVector3D UCounterCounterImplementation::Decrement(const FCustomTypesVector3D& Vec)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Counter.Counter.Impl.Decrement");
	(void)Vec;
	// do business logic here
	return FCustomTypesVector3D();
}

TArray<FCustomTypesVector3D> UCounterCounterImplementation::DecrementArray(const TArray<FCustomTypesVector3D>& Vec)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Counter.Counter.Impl.DecrementArray");
	(void)Vec;
	// do business logic here
	return TArray<FCustomTypesVector3D>();
}

void UCounterCounterImplementation::_ResetProperties()
{
	if (Vector != FCustomTypesVector3D())
	{
		Vector = FCustomTypesVector3D();
		_GetPublisher()->BroadcastVectorChanged(Vector);
	}
	if (ExternVector != FVector(0.f, 0.f, 0.f))
	{
		ExternVector = FVector(0.f, 0.f, 0.f);
		_GetPublisher()->BroadcastExternVectorChanged(ExternVector);
	}
	if (VectorArray != TArray<FCustomTypesVector3D>())
	{
		VectorArray = TArray<FCustomTypesVector3D>();
		_GetPublisher()->BroadcastVectorArrayChanged(VectorArray);
	}
	if (ExternVectorArray != TArray<FVector>())
	{
		ExternVectorArray = TArray<FVector>();
		_GetPublisher()->BroadcastExternVectorArrayChanged(ExternVectorArray);
	}
}
