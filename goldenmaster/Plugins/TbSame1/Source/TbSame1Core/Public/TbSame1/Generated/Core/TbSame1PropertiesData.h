
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
struct TbSame1SameStruct1InterfacePropertiesData
{
	FCriticalSection Prop1Mutex;
	FTbSame1Struct1 Prop1{FTbSame1Struct1()};
};

/**
	\brief data structure to hold the last sent property values
*/
struct TbSame1SameStruct2InterfacePropertiesData
{
	FCriticalSection Prop1Mutex;
	FTbSame1Struct2 Prop1{FTbSame1Struct2()};
	FCriticalSection Prop2Mutex;
	FTbSame1Struct2 Prop2{FTbSame1Struct2()};
};

/**
	\brief data structure to hold the last sent property values
*/
struct TbSame1SameEnum1InterfacePropertiesData
{
	std::atomic<ETbSame1Enum1> Prop1{ETbSame1Enum1::TS1E1_Value1};
};

/**
	\brief data structure to hold the last sent property values
*/
struct TbSame1SameEnum2InterfacePropertiesData
{
	std::atomic<ETbSame1Enum1> Prop1{ETbSame1Enum1::TS1E1_Value1};
	std::atomic<ETbSame1Enum2> Prop2{ETbSame1Enum2::TS1E2_Value1};
};
