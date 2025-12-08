
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
#include <atomic>
#include "HAL/CriticalSection.h"

/**
	\brief data structure to hold the last sent property values
*/
struct TbSimpleSimpleInterfacePropertiesData
{
	std::atomic<bool> bPropBool{false};
	std::atomic<int32> PropInt{0};
	std::atomic<int32> PropInt32{0};
	std::atomic<int64> PropInt64{0LL};
	std::atomic<float> PropFloat{0.0f};
	std::atomic<float> PropFloat32{0.0f};
	std::atomic<double> PropFloat64{0.0};
	FCriticalSection PropStringMutex;
	FString PropString{FString()};
};

/**
	\brief data structure to hold the last sent property values
*/
struct TbSimpleSimpleArrayInterfacePropertiesData
{
	FCriticalSection PropBoolMutex;
	TArray<bool> PropBool{TArray<bool>()};
	FCriticalSection PropIntMutex;
	TArray<int32> PropInt{TArray<int32>()};
	FCriticalSection PropInt32Mutex;
	TArray<int32> PropInt32{TArray<int32>()};
	FCriticalSection PropInt64Mutex;
	TArray<int64> PropInt64{TArray<int64>()};
	FCriticalSection PropFloatMutex;
	TArray<float> PropFloat{TArray<float>()};
	FCriticalSection PropFloat32Mutex;
	TArray<float> PropFloat32{TArray<float>()};
	FCriticalSection PropFloat64Mutex;
	TArray<double> PropFloat64{TArray<double>()};
	FCriticalSection PropStringMutex;
	TArray<FString> PropString{TArray<FString>()};
	FCriticalSection PropReadOnlyStringMutex;
	FString PropReadOnlyString{FString()};
};

/**
	\brief data structure to hold the last sent property values
*/
struct TbSimpleNoOperationsInterfacePropertiesData
{
	std::atomic<bool> bPropBool{false};
	std::atomic<int32> PropInt{0};
};

/**
	\brief data structure to hold the last sent property values
*/
struct TbSimpleNoSignalsInterfacePropertiesData
{
	std::atomic<bool> bPropBool{false};
	std::atomic<int32> PropInt{0};
};
