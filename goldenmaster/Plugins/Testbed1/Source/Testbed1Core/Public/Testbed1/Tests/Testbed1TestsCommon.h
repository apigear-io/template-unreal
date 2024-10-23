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

#include "Testbed1/Generated/api/Testbed1_data.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#if (ENGINE_MAJOR_VERSION >= 5)
#if (ENGINE_MINOR_VERSION >= 5)
inline constexpr EAutomationTestFlags Testbed1TestFilterMask = EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#else
inline constexpr int Testbed1TestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif
#else
constexpr int Testbed1TestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif

FTestbed1StructBool TESTBED1CORE_API createTestFTestbed1StructBool();

TArray<FTestbed1StructBool> TESTBED1CORE_API createTestFTestbed1StructBoolArray();

FTestbed1StructInt TESTBED1CORE_API createTestFTestbed1StructInt();

TArray<FTestbed1StructInt> TESTBED1CORE_API createTestFTestbed1StructIntArray();

FTestbed1StructFloat TESTBED1CORE_API createTestFTestbed1StructFloat();

TArray<FTestbed1StructFloat> TESTBED1CORE_API createTestFTestbed1StructFloatArray();

FTestbed1StructString TESTBED1CORE_API createTestFTestbed1StructString();

TArray<FTestbed1StructString> TESTBED1CORE_API createTestFTestbed1StructStringArray();

#endif // WITH_DEV_AUTOMATION_TESTS
