
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
	FScopeLock Lock(&(VectorCS));
	Vector = InVector;
}

FCustomTypesVector3D CounterCounterPropertiesData::GetVector() const
{
	FScopeLock Lock(&(VectorCS));
	return Vector;
}

void CounterCounterPropertiesData::SetExternVector(const FVector& InExternVector)
{
	FScopeLock Lock(&(ExternVectorCS));
	ExternVector = InExternVector;
}

FVector CounterCounterPropertiesData::GetExternVector() const
{
	FScopeLock Lock(&(ExternVectorCS));
	return ExternVector;
}

void CounterCounterPropertiesData::SetVectorArray(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	FScopeLock Lock(&(VectorArrayCS));
	VectorArray = InVectorArray;
}

TArray<FCustomTypesVector3D> CounterCounterPropertiesData::GetVectorArray() const
{
	FScopeLock Lock(&(VectorArrayCS));
	return VectorArray;
}

void CounterCounterPropertiesData::SetExternVectorArray(const TArray<FVector>& InExternVectorArray)
{
	FScopeLock Lock(&(ExternVectorArrayCS));
	ExternVectorArray = InExternVectorArray;
}

TArray<FVector> CounterCounterPropertiesData::GetExternVectorArray() const
{
	FScopeLock Lock(&(ExternVectorArrayCS));
	return ExternVectorArray;
}
