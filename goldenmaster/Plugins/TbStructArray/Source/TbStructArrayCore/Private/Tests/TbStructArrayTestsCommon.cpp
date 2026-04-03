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
#include "TbStructArray/Tests/TbStructArrayTestsCommon.h"
#include "TbStructArray/Generated/api/TbStructArray_data.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS
FTbStructArrayPoint createTestFTbStructArrayPoint()
{
	FTbStructArrayPoint TestValue;

	TestValue.x = 1.0f;
	TestValue.y = 1.0f;

	return TestValue;
}

TArray<FTbStructArrayPoint> createTestFTbStructArrayPointArray()
{
	TArray<FTbStructArrayPoint> TestValueArray;

	TestValueArray.Add(createTestFTbStructArrayPoint());

	return TestValueArray;
}

FTbStructArrayStructWithArrayOfStructs createTestFTbStructArrayStructWithArrayOfStructs()
{
	FTbStructArrayStructWithArrayOfStructs TestValue;

	TestValue.points = createTestFTbStructArrayPointArray();

	return TestValue;
}

TArray<FTbStructArrayStructWithArrayOfStructs> createTestFTbStructArrayStructWithArrayOfStructsArray()
{
	TArray<FTbStructArrayStructWithArrayOfStructs> TestValueArray;

	TestValueArray.Add(createTestFTbStructArrayStructWithArrayOfStructs());

	return TestValueArray;
}

FTbStructArrayStructWithArrayOfEnums createTestFTbStructArrayStructWithArrayOfEnums()
{
	FTbStructArrayStructWithArrayOfEnums TestValue;

	TestValue.tags.Add(ETbStructArrayTestEnum::TSATE_Value2);

	return TestValue;
}

TArray<FTbStructArrayStructWithArrayOfEnums> createTestFTbStructArrayStructWithArrayOfEnumsArray()
{
	TArray<FTbStructArrayStructWithArrayOfEnums> TestValueArray;

	TestValueArray.Add(createTestFTbStructArrayStructWithArrayOfEnums());

	return TestValueArray;
}

FTbStructArrayStructWithArrayOfInts createTestFTbStructArrayStructWithArrayOfInts()
{
	FTbStructArrayStructWithArrayOfInts TestValue;

	TestValue.values.Add(1);

	return TestValue;
}

TArray<FTbStructArrayStructWithArrayOfInts> createTestFTbStructArrayStructWithArrayOfIntsArray()
{
	TArray<FTbStructArrayStructWithArrayOfInts> TestValueArray;

	TestValueArray.Add(createTestFTbStructArrayStructWithArrayOfInts());

	return TestValueArray;
}

FTbStructArrayMixedStruct createTestFTbStructArrayMixedStruct()
{
	FTbStructArrayMixedStruct TestValue;

	TestValue.id = 1;
	TestValue.name = FString("xyz");
	TestValue.origin = createTestFTbStructArrayPoint();
	TestValue.points = createTestFTbStructArrayPointArray();
	TestValue.flags.Add(ETbStructArrayTestEnum::TSATE_Value2);
	TestValue.scores.Add(1);

	return TestValue;
}

TArray<FTbStructArrayMixedStruct> createTestFTbStructArrayMixedStructArray()
{
	TArray<FTbStructArrayMixedStruct> TestValueArray;

	TestValueArray.Add(createTestFTbStructArrayMixedStruct());

	return TestValueArray;
}

#endif // WITH_DEV_AUTOMATION_TESTS
