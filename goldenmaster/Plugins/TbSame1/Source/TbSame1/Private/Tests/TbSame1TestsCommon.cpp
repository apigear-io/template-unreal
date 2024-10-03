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
#include "TbSame1TestsCommon.h"
#include "TbSame1/Generated/api/TbSame1_data.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS
FTbSame1Struct1 createTestFTbSame1Struct1()
{
	FTbSame1Struct1 TestValue;

	TestValue.field1 = 1;
	TestValue.field2 = 1;
	TestValue.field3 = 1;

	return TestValue;
}

TArray<FTbSame1Struct1> createTestFTbSame1Struct1Array()
{
	TArray<FTbSame1Struct1> TestValueArray;

	TestValueArray.Add(createTestFTbSame1Struct1());

	return TestValueArray;
}

FTbSame1Struct2 createTestFTbSame1Struct2()
{
	FTbSame1Struct2 TestValue;

	TestValue.field1 = 1;
	TestValue.field2 = 1;
	TestValue.field3 = 1;

	return TestValue;
}

TArray<FTbSame1Struct2> createTestFTbSame1Struct2Array()
{
	TArray<FTbSame1Struct2> TestValueArray;

	TestValueArray.Add(createTestFTbSame1Struct2());

	return TestValueArray;
}

#endif // WITH_DEV_AUTOMATION_TESTS
