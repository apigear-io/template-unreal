
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
#include "CustomTypes/Generated/api/CustomTypes_apig.h"
#include "ExternTypes/Generated/api/ExternTypes_apig.h"

/**
	\brief data structure to hold the last sent property values
*/
struct CounterCounterPropertiesData
{
	FCriticalSection VectorMutex;
	FCustomTypesVector3D Vector{FCustomTypesVector3D()};
	FCriticalSection ExternVectorMutex;
	FVector ExternVector{FVector(0.f, 0.f, 0.f)};
	FCriticalSection VectorArrayMutex;
	TArray<FCustomTypesVector3D> VectorArray{TArray<FCustomTypesVector3D>()};
	FCriticalSection ExternVectorArrayMutex;
	TArray<FVector> ExternVectorArray{TArray<FVector>()};
};
