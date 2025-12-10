
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
#include "Counter/Generated/Core/CounterPropertiesData.h"

void CounterCounterPropertiesData::SetVector(const FCustomTypesVector3D& InVector)
{
	FWriteScopeLock WriteLock(VectorLock);
	Vector = InVector;
}

FCustomTypesVector3D CounterCounterPropertiesData::GetVector() const
{
	FReadScopeLock ReadLock(VectorLock);
	return Vector;
}

void CounterCounterPropertiesData::SetExternVector(const FVector& InExternVector)
{
	FWriteScopeLock WriteLock(ExternVectorLock);
	ExternVector = InExternVector;
}

FVector CounterCounterPropertiesData::GetExternVector() const
{
	FReadScopeLock ReadLock(ExternVectorLock);
	return ExternVector;
}

void CounterCounterPropertiesData::SetVectorArray(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	FWriteScopeLock WriteLock(VectorArrayLock);
	VectorArray = InVectorArray;
}

TArray<FCustomTypesVector3D> CounterCounterPropertiesData::GetVectorArray() const
{
	FReadScopeLock ReadLock(VectorArrayLock);
	return VectorArray;
}

void CounterCounterPropertiesData::SetExternVectorArray(const TArray<FVector>& InExternVectorArray)
{
	FWriteScopeLock WriteLock(ExternVectorArrayLock);
	ExternVectorArray = InExternVectorArray;
}

TArray<FVector> CounterCounterPropertiesData::GetExternVectorArray() const
{
	FReadScopeLock ReadLock(ExternVectorArrayLock);
	return ExternVectorArray;
}
