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
#include "Testbed1TestsCommon.h"
#include "Generated/api/Testbed1_data.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS
FTestbed1StructBool createTestFTestbed1StructBool()
{
	FTestbed1StructBool TestValue;

	TestValue.fieldBool = true;

	return TestValue;
}

TArray<FTestbed1StructBool> createTestFTestbed1StructBoolArray()
{
	TArray<FTestbed1StructBool> TestValueArray;

	TestValueArray.Add(createTestFTestbed1StructBool());

	return TestValueArray;
}

FTestbed1StructInt createTestFTestbed1StructInt()
{
	FTestbed1StructInt TestValue;

	TestValue.fieldInt = 1;

	return TestValue;
}

TArray<FTestbed1StructInt> createTestFTestbed1StructIntArray()
{
	TArray<FTestbed1StructInt> TestValueArray;

	TestValueArray.Add(createTestFTestbed1StructInt());

	return TestValueArray;
}

FTestbed1StructFloat createTestFTestbed1StructFloat()
{
	FTestbed1StructFloat TestValue;

	TestValue.fieldFloat = 1.0f;

	return TestValue;
}

TArray<FTestbed1StructFloat> createTestFTestbed1StructFloatArray()
{
	TArray<FTestbed1StructFloat> TestValueArray;

	TestValueArray.Add(createTestFTestbed1StructFloat());

	return TestValueArray;
}

FTestbed1StructString createTestFTestbed1StructString()
{
	FTestbed1StructString TestValue;

	TestValue.fieldString = FString("xyz");

	return TestValue;
}

TArray<FTestbed1StructString> createTestFTestbed1StructStringArray()
{
	TArray<FTestbed1StructString> TestValueArray;

	TestValueArray.Add(createTestFTestbed1StructString());

	return TestValueArray;
}

#endif // WITH_DEV_AUTOMATION_TESTS
