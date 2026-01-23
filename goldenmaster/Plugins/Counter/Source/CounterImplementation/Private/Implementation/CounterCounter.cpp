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
#include "Misc/ScopeRWLock.h"

UCounterCounterImplementation::~UCounterCounterImplementation() = default;
FCustomTypesVector3D UCounterCounterImplementation::GetVector() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(VectorRWLock);
#endif
	return Vector;
}

void UCounterCounterImplementation::SetVector(const FCustomTypesVector3D& InVector)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Counter.Counter.Impl.SetVector");
	if (Vector != InVector)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(VectorRWLock);
			Vector = InVector;
		}
#else
		Vector = InVector;
#endif
		_GetPublisher()->BroadcastVectorChanged(Vector);
	}
}
FVector UCounterCounterImplementation::GetExternVector() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(ExternVectorRWLock);
#endif
	return ExternVector;
}

void UCounterCounterImplementation::SetExternVector(const FVector& InExternVector)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Counter.Counter.Impl.SetExternVector");
	if (ExternVector != InExternVector)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(ExternVectorRWLock);
			ExternVector = InExternVector;
		}
#else
		ExternVector = InExternVector;
#endif
		_GetPublisher()->BroadcastExternVectorChanged(ExternVector);
	}
}
TArray<FCustomTypesVector3D> UCounterCounterImplementation::GetVectorArray() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(VectorArrayRWLock);
#endif
	return VectorArray;
}

void UCounterCounterImplementation::SetVectorArray(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Counter.Counter.Impl.SetVectorArray");
	if (VectorArray != InVectorArray)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(VectorArrayRWLock);
			VectorArray = InVectorArray;
		}
#else
		VectorArray = InVectorArray;
#endif
		_GetPublisher()->BroadcastVectorArrayChanged(VectorArray);
	}
}
TArray<FVector> UCounterCounterImplementation::GetExternVectorArray() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(ExternVectorArrayRWLock);
#endif
	return ExternVectorArray;
}

void UCounterCounterImplementation::SetExternVectorArray(const TArray<FVector>& InExternVectorArray)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Counter.Counter.Impl.SetExternVectorArray");
	if (ExternVectorArray != InExternVectorArray)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(ExternVectorArrayRWLock);
			ExternVectorArray = InExternVectorArray;
		}
#else
		ExternVectorArray = InExternVectorArray;
#endif
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
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(VectorRWLock);
			Vector = FCustomTypesVector3D();
		}
#else
		Vector = FCustomTypesVector3D();
#endif
		_GetPublisher()->BroadcastVectorChanged(Vector);
	}
	if (ExternVector != FVector(0.f, 0.f, 0.f))
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(ExternVectorRWLock);
			ExternVector = FVector(0.f, 0.f, 0.f);
		}
#else
		ExternVector = FVector(0.f, 0.f, 0.f);
#endif
		_GetPublisher()->BroadcastExternVectorChanged(ExternVector);
	}
	if (VectorArray != TArray<FCustomTypesVector3D>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(VectorArrayRWLock);
			VectorArray = TArray<FCustomTypesVector3D>();
		}
#else
		VectorArray = TArray<FCustomTypesVector3D>();
#endif
		_GetPublisher()->BroadcastVectorArrayChanged(VectorArray);
	}
	if (ExternVectorArray != TArray<FVector>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(ExternVectorArrayRWLock);
			ExternVectorArray = TArray<FVector>();
		}
#else
		ExternVectorArray = TArray<FVector>();
#endif
		_GetPublisher()->BroadcastExternVectorArrayChanged(ExternVectorArray);
	}
}
