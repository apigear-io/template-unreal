
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

/**
	\brief data structure to hold the last sent property values
*/
struct TbEnumEnumInterfacePropertiesData
{
	std::atomic<ETbEnumEnum0> Prop0{ETbEnumEnum0::TEE0_Value0};
	std::atomic<ETbEnumEnum1> Prop1{ETbEnumEnum1::TEE1_Value1};
	std::atomic<ETbEnumEnum2> Prop2{ETbEnumEnum2::TEE2_Value2};
	std::atomic<ETbEnumEnum3> Prop3{ETbEnumEnum3::TEE3_Value3};
};
