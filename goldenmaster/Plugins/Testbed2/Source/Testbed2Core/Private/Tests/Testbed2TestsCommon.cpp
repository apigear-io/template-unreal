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
#include "Testbed2/Tests/Testbed2TestsCommon.h"
#include "Testbed2/Generated/api/Testbed2_data.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS
FTestbed2Struct1 createTestFTestbed2Struct1()
{
	FTestbed2Struct1 TestValue;

	TestValue.field1 = 1;

	return TestValue;
}

TArray<FTestbed2Struct1> createTestFTestbed2Struct1Array()
{
	TArray<FTestbed2Struct1> TestValueArray;

	TestValueArray.Add(createTestFTestbed2Struct1());

	return TestValueArray;
}

FTestbed2Struct2 createTestFTestbed2Struct2()
{
	FTestbed2Struct2 TestValue;

	TestValue.field1 = 1;
	TestValue.field2 = 1;

	return TestValue;
}

TArray<FTestbed2Struct2> createTestFTestbed2Struct2Array()
{
	TArray<FTestbed2Struct2> TestValueArray;

	TestValueArray.Add(createTestFTestbed2Struct2());

	return TestValueArray;
}

FTestbed2Struct3 createTestFTestbed2Struct3()
{
	FTestbed2Struct3 TestValue;

	TestValue.field1 = 1;
	TestValue.field2 = 1;
	TestValue.field3 = 1;

	return TestValue;
}

TArray<FTestbed2Struct3> createTestFTestbed2Struct3Array()
{
	TArray<FTestbed2Struct3> TestValueArray;

	TestValueArray.Add(createTestFTestbed2Struct3());

	return TestValueArray;
}

FTestbed2Struct4 createTestFTestbed2Struct4()
{
	FTestbed2Struct4 TestValue;

	TestValue.field1 = 1;
	TestValue.field2 = 1;
	TestValue.field3 = 1;
	TestValue.field4 = 1;

	return TestValue;
}

TArray<FTestbed2Struct4> createTestFTestbed2Struct4Array()
{
	TArray<FTestbed2Struct4> TestValueArray;

	TestValueArray.Add(createTestFTestbed2Struct4());

	return TestValueArray;
}

FTestbed2NestedStruct1 createTestFTestbed2NestedStruct1()
{
	FTestbed2NestedStruct1 TestValue;

	TestValue.field1 = createTestFTestbed2Struct1();

	return TestValue;
}

TArray<FTestbed2NestedStruct1> createTestFTestbed2NestedStruct1Array()
{
	TArray<FTestbed2NestedStruct1> TestValueArray;

	TestValueArray.Add(createTestFTestbed2NestedStruct1());

	return TestValueArray;
}

FTestbed2NestedStruct2 createTestFTestbed2NestedStruct2()
{
	FTestbed2NestedStruct2 TestValue;

	TestValue.field1 = createTestFTestbed2Struct1();
	TestValue.field2 = createTestFTestbed2Struct2();

	return TestValue;
}

TArray<FTestbed2NestedStruct2> createTestFTestbed2NestedStruct2Array()
{
	TArray<FTestbed2NestedStruct2> TestValueArray;

	TestValueArray.Add(createTestFTestbed2NestedStruct2());

	return TestValueArray;
}

FTestbed2NestedStruct3 createTestFTestbed2NestedStruct3()
{
	FTestbed2NestedStruct3 TestValue;

	TestValue.field1 = createTestFTestbed2Struct1();
	TestValue.field2 = createTestFTestbed2Struct2();
	TestValue.field3 = createTestFTestbed2Struct3();

	return TestValue;
}

TArray<FTestbed2NestedStruct3> createTestFTestbed2NestedStruct3Array()
{
	TArray<FTestbed2NestedStruct3> TestValueArray;

	TestValueArray.Add(createTestFTestbed2NestedStruct3());

	return TestValueArray;
}

TArray<ETestbed2Enum1> createTestFTestbed2Enum1Array()
{
	TArray<ETestbed2Enum1> TestValueArray;

	ETestbed2Enum1 val = ETestbed2Enum1::T2E1_Value1;
	TestValueArray.Add(val);
	return TestValueArray;
}

TArray<ETestbed2Enum2> createTestFTestbed2Enum2Array()
{
	TArray<ETestbed2Enum2> TestValueArray;

	ETestbed2Enum2 val = ETestbed2Enum2::T2E2_Value1;
	TestValueArray.Add(val);
	return TestValueArray;
}

TArray<ETestbed2Enum3> createTestFTestbed2Enum3Array()
{
	TArray<ETestbed2Enum3> TestValueArray;

	ETestbed2Enum3 val = ETestbed2Enum3::T2E3_Value1;
	TestValueArray.Add(val);
	return TestValueArray;
}

#endif // WITH_DEV_AUTOMATION_TESTS
