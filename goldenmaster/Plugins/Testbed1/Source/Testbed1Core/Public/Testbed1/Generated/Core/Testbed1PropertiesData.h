
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

/**
	\brief data structure to hold the last sent property values
*/
struct Testbed1StructInterfacePropertiesData
{
	FCriticalSection PropBoolMutex;
	FTestbed1StructBool PropBool{FTestbed1StructBool()};
	FCriticalSection PropIntMutex;
	FTestbed1StructInt PropInt{FTestbed1StructInt()};
	FCriticalSection PropFloatMutex;
	FTestbed1StructFloat PropFloat{FTestbed1StructFloat()};
	FCriticalSection PropStringMutex;
	FTestbed1StructString PropString{FTestbed1StructString()};
};

/**
	\brief data structure to hold the last sent property values
*/
struct Testbed1StructArrayInterfacePropertiesData
{
	FCriticalSection PropBoolMutex;
	TArray<FTestbed1StructBool> PropBool{TArray<FTestbed1StructBool>()};
	FCriticalSection PropIntMutex;
	TArray<FTestbed1StructInt> PropInt{TArray<FTestbed1StructInt>()};
	FCriticalSection PropFloatMutex;
	TArray<FTestbed1StructFloat> PropFloat{TArray<FTestbed1StructFloat>()};
	FCriticalSection PropStringMutex;
	TArray<FTestbed1StructString> PropString{TArray<FTestbed1StructString>()};
	FCriticalSection PropEnumMutex;
	TArray<ETestbed1Enum0> PropEnum{TArray<ETestbed1Enum0>()};
};

/**
	\brief data structure to hold the last sent property values
*/
struct Testbed1StructArray2InterfacePropertiesData
{
	FCriticalSection PropBoolMutex;
	FTestbed1StructBoolWithArray PropBool{FTestbed1StructBoolWithArray()};
	FCriticalSection PropIntMutex;
	FTestbed1StructIntWithArray PropInt{FTestbed1StructIntWithArray()};
	FCriticalSection PropFloatMutex;
	FTestbed1StructFloatWithArray PropFloat{FTestbed1StructFloatWithArray()};
	FCriticalSection PropStringMutex;
	FTestbed1StructStringWithArray PropString{FTestbed1StructStringWithArray()};
	FCriticalSection PropEnumMutex;
	FTestbed1StructEnumWithArray PropEnum{FTestbed1StructEnumWithArray()};
};
