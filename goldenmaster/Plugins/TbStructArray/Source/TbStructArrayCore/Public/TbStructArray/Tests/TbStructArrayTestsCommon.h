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

#include "TbStructArray/Generated/api/TbStructArray_data.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#if (ENGINE_MAJOR_VERSION >= 5)
#if (ENGINE_MINOR_VERSION >= 5)
inline constexpr EAutomationTestFlags TbStructArrayTestFilterMask = EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#else
inline constexpr int TbStructArrayTestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif
#else
constexpr int TbStructArrayTestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif

FTbStructArrayPoint TBSTRUCTARRAYCORE_API createTestFTbStructArrayPoint();

TArray<FTbStructArrayPoint> TBSTRUCTARRAYCORE_API createTestFTbStructArrayPointArray();

FTbStructArrayStructWithArrayOfStructs TBSTRUCTARRAYCORE_API createTestFTbStructArrayStructWithArrayOfStructs();

TArray<FTbStructArrayStructWithArrayOfStructs> TBSTRUCTARRAYCORE_API createTestFTbStructArrayStructWithArrayOfStructsArray();

FTbStructArrayStructWithArrayOfEnums TBSTRUCTARRAYCORE_API createTestFTbStructArrayStructWithArrayOfEnums();

TArray<FTbStructArrayStructWithArrayOfEnums> TBSTRUCTARRAYCORE_API createTestFTbStructArrayStructWithArrayOfEnumsArray();

FTbStructArrayStructWithArrayOfInts TBSTRUCTARRAYCORE_API createTestFTbStructArrayStructWithArrayOfInts();

TArray<FTbStructArrayStructWithArrayOfInts> TBSTRUCTARRAYCORE_API createTestFTbStructArrayStructWithArrayOfIntsArray();

FTbStructArrayMixedStruct TBSTRUCTARRAYCORE_API createTestFTbStructArrayMixedStruct();

TArray<FTbStructArrayMixedStruct> TBSTRUCTARRAYCORE_API createTestFTbStructArrayMixedStructArray();

#endif // WITH_DEV_AUTOMATION_TESTS
