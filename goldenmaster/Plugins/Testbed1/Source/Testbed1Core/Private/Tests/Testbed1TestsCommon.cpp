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
#include "Testbed1/Tests/Testbed1TestsCommon.h"
#include "Testbed1/Generated/api/Testbed1_data.h"
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

FTestbed1StructStruct createTestFTestbed1StructStruct()
{
	FTestbed1StructStruct TestValue;

	TestValue.fieldString = createTestFTestbed1StructString();

	return TestValue;
}

TArray<FTestbed1StructStruct> createTestFTestbed1StructStructArray()
{
	TArray<FTestbed1StructStruct> TestValueArray;

	TestValueArray.Add(createTestFTestbed1StructStruct());

	return TestValueArray;
}

FTestbed1StructEnum createTestFTestbed1StructEnum()
{
	FTestbed1StructEnum TestValue;

	TestValue.fieldEnum = ETestbed1Enum0::T1E0_VALUE1;

	return TestValue;
}

TArray<FTestbed1StructEnum> createTestFTestbed1StructEnumArray()
{
	TArray<FTestbed1StructEnum> TestValueArray;

	TestValueArray.Add(createTestFTestbed1StructEnum());

	return TestValueArray;
}

FTestbed1StructBoolWithArray createTestFTestbed1StructBoolWithArray()
{
	FTestbed1StructBoolWithArray TestValue;

	TestValue.fieldBool.Add(true);

	return TestValue;
}

TArray<FTestbed1StructBoolWithArray> createTestFTestbed1StructBoolWithArrayArray()
{
	TArray<FTestbed1StructBoolWithArray> TestValueArray;

	TestValueArray.Add(createTestFTestbed1StructBoolWithArray());

	return TestValueArray;
}

FTestbed1StructIntWithArray createTestFTestbed1StructIntWithArray()
{
	FTestbed1StructIntWithArray TestValue;

	TestValue.fieldInt.Add(1);

	return TestValue;
}

TArray<FTestbed1StructIntWithArray> createTestFTestbed1StructIntWithArrayArray()
{
	TArray<FTestbed1StructIntWithArray> TestValueArray;

	TestValueArray.Add(createTestFTestbed1StructIntWithArray());

	return TestValueArray;
}

FTestbed1StructFloatWithArray createTestFTestbed1StructFloatWithArray()
{
	FTestbed1StructFloatWithArray TestValue;

	TestValue.fieldFloat.Add(1.0f);

	return TestValue;
}

TArray<FTestbed1StructFloatWithArray> createTestFTestbed1StructFloatWithArrayArray()
{
	TArray<FTestbed1StructFloatWithArray> TestValueArray;

	TestValueArray.Add(createTestFTestbed1StructFloatWithArray());

	return TestValueArray;
}

FTestbed1StructStringWithArray createTestFTestbed1StructStringWithArray()
{
	FTestbed1StructStringWithArray TestValue;

	TestValue.fieldString.Add(FString("xyz"));

	return TestValue;
}

TArray<FTestbed1StructStringWithArray> createTestFTestbed1StructStringWithArrayArray()
{
	TArray<FTestbed1StructStringWithArray> TestValueArray;

	TestValueArray.Add(createTestFTestbed1StructStringWithArray());

	return TestValueArray;
}

FTestbed1StructStructWithArray createTestFTestbed1StructStructWithArray()
{
	FTestbed1StructStructWithArray TestValue;

	TestValue.fieldStruct = createTestFTestbed1StructStringWithArrayArray();

	return TestValue;
}

TArray<FTestbed1StructStructWithArray> createTestFTestbed1StructStructWithArrayArray()
{
	TArray<FTestbed1StructStructWithArray> TestValueArray;

	TestValueArray.Add(createTestFTestbed1StructStructWithArray());

	return TestValueArray;
}

FTestbed1StructEnumWithArray createTestFTestbed1StructEnumWithArray()
{
	FTestbed1StructEnumWithArray TestValue;

	TestValue.fieldEnum.Add(ETestbed1Enum0::T1E0_VALUE1);

	return TestValue;
}

TArray<FTestbed1StructEnumWithArray> createTestFTestbed1StructEnumWithArrayArray()
{
	TArray<FTestbed1StructEnumWithArray> TestValueArray;

	TestValueArray.Add(createTestFTestbed1StructEnumWithArray());

	return TestValueArray;
}

#endif // WITH_DEV_AUTOMATION_TESTS
