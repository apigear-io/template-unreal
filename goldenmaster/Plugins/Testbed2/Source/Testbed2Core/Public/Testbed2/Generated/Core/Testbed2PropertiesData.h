
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
struct Testbed2ManyParamInterfacePropertiesData
{
	std::atomic<int32> Prop1{0};
	std::atomic<int32> Prop2{0};
	std::atomic<int32> Prop3{0};
	std::atomic<int32> Prop4{0};
};

/**
	\brief data structure to hold the last sent property values
*/
struct Testbed2NestedStruct1InterfacePropertiesData
{
	FCriticalSection Prop1Mutex;
	FTestbed2NestedStruct1 Prop1{FTestbed2NestedStruct1()};
};

/**
	\brief data structure to hold the last sent property values
*/
struct Testbed2NestedStruct2InterfacePropertiesData
{
	FCriticalSection Prop1Mutex;
	FTestbed2NestedStruct1 Prop1{FTestbed2NestedStruct1()};
	FCriticalSection Prop2Mutex;
	FTestbed2NestedStruct2 Prop2{FTestbed2NestedStruct2()};
};

/**
	\brief data structure to hold the last sent property values
*/
struct Testbed2NestedStruct3InterfacePropertiesData
{
	FCriticalSection Prop1Mutex;
	FTestbed2NestedStruct1 Prop1{FTestbed2NestedStruct1()};
	FCriticalSection Prop2Mutex;
	FTestbed2NestedStruct2 Prop2{FTestbed2NestedStruct2()};
	FCriticalSection Prop3Mutex;
	FTestbed2NestedStruct3 Prop3{FTestbed2NestedStruct3()};
};
