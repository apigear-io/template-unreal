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

#include "Generated/api/Testbed2_data.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS
FTestbed2Struct1 TESTBED2_API createTestFTestbed2Struct1();

TArray<FTestbed2Struct1> TESTBED2_API createTestFTestbed2Struct1Array();

FTestbed2Struct2 TESTBED2_API createTestFTestbed2Struct2();

TArray<FTestbed2Struct2> TESTBED2_API createTestFTestbed2Struct2Array();

FTestbed2Struct3 TESTBED2_API createTestFTestbed2Struct3();

TArray<FTestbed2Struct3> TESTBED2_API createTestFTestbed2Struct3Array();

FTestbed2Struct4 TESTBED2_API createTestFTestbed2Struct4();

TArray<FTestbed2Struct4> TESTBED2_API createTestFTestbed2Struct4Array();

FTestbed2NestedStruct1 TESTBED2_API createTestFTestbed2NestedStruct1();

TArray<FTestbed2NestedStruct1> TESTBED2_API createTestFTestbed2NestedStruct1Array();

FTestbed2NestedStruct2 TESTBED2_API createTestFTestbed2NestedStruct2();

TArray<FTestbed2NestedStruct2> TESTBED2_API createTestFTestbed2NestedStruct2Array();

FTestbed2NestedStruct3 TESTBED2_API createTestFTestbed2NestedStruct3();

TArray<FTestbed2NestedStruct3> TESTBED2_API createTestFTestbed2NestedStruct3Array();

#endif // WITH_DEV_AUTOMATION_TESTS
