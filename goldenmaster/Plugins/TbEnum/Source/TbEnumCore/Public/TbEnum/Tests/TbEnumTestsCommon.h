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

#include "TbEnum/Generated/api/TbEnum_data.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#if (ENGINE_MAJOR_VERSION >= 5)
#if (ENGINE_MINOR_VERSION >= 5)
inline constexpr EAutomationTestFlags TbEnumTestFilterMask = EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#else
inline constexpr int TbEnumTestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif
#else
constexpr int TbEnumTestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif

TArray<ETbEnumEnum0> TBENUMCORE_API createTestFTbEnumEnum0Array();

TArray<ETbEnumEnum1> TBENUMCORE_API createTestFTbEnumEnum1Array();

TArray<ETbEnumEnum2> TBENUMCORE_API createTestFTbEnumEnum2Array();

TArray<ETbEnumEnum3> TBENUMCORE_API createTestFTbEnumEnum3Array();

#endif // WITH_DEV_AUTOMATION_TESTS
