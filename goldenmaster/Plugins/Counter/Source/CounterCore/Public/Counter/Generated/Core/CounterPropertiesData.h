
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
#include "HAL/CriticalSection.h"
#include "Counter/Generated/api/Counter_data.h"
#include "CustomTypes/Generated/api/CustomTypes_data.h"
#include "ExternTypes/Generated/api/ExternTypes_data.h"

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class COUNTERCORE_API CounterCounterPropertiesData
{
public:
	void SetVector(const FCustomTypesVector3D& InVector);
	FCustomTypesVector3D GetVector() const;
	void SetExternVector(const FVector& InExternVector);
	FVector GetExternVector() const;
	void SetVectorArray(const TArray<FCustomTypesVector3D>& InVectorArray);
	TArray<FCustomTypesVector3D> GetVectorArray() const;
	void SetExternVectorArray(const TArray<FVector>& InExternVectorArray);
	TArray<FVector> GetExternVectorArray() const;

private:
	mutable FCriticalSection VectorCS;
	FCustomTypesVector3D Vector{FCustomTypesVector3D()};
	mutable FCriticalSection ExternVectorCS;
	FVector ExternVector{FVector(0.f, 0.f, 0.f)};
	mutable FCriticalSection VectorArrayCS;
	TArray<FCustomTypesVector3D> VectorArray{TArray<FCustomTypesVector3D>()};
	mutable FCriticalSection ExternVectorArrayCS;
	TArray<FVector> ExternVectorArray{TArray<FVector>()};
};
