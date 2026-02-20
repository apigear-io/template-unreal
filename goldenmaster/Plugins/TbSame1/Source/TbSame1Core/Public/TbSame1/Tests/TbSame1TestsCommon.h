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

#include "TbSame1/Generated/api/TbSame1_data.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#if (ENGINE_MAJOR_VERSION >= 5)
#if (ENGINE_MINOR_VERSION >= 5)
inline constexpr EAutomationTestFlags TbSame1TestFilterMask = EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#else
inline constexpr int TbSame1TestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif
#else
constexpr int TbSame1TestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif

FTbSame1Struct1 TBSAME1CORE_API createTestFTbSame1Struct1();

TArray<FTbSame1Struct1> TBSAME1CORE_API createTestFTbSame1Struct1Array();

FTbSame1Struct2 TBSAME1CORE_API createTestFTbSame1Struct2();

TArray<FTbSame1Struct2> TBSAME1CORE_API createTestFTbSame1Struct2Array();

TArray<ETbSame1Enum1> TBSAME1CORE_API createTestFTbSame1Enum1Array();

TArray<ETbSame1Enum2> TBSAME1CORE_API createTestFTbSame1Enum2Array();

#endif // WITH_DEV_AUTOMATION_TESTS
