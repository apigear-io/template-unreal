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
#include "CustomTypes/Tests/CustomTypesTestsCommon.h"
#include "CustomTypes/Generated/api/CustomTypes_data.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS
FCustomTypesVector3D createTestFCustomTypesVector3D()
{
	FCustomTypesVector3D TestValue;

	TestValue.x = 1.0f;
	TestValue.y = 1.0f;
	TestValue.z = 1.0f;

	return TestValue;
}

TArray<FCustomTypesVector3D> createTestFCustomTypesVector3DArray()
{
	TArray<FCustomTypesVector3D> TestValueArray;

	TestValueArray.Add(createTestFCustomTypesVector3D());

	return TestValueArray;
}

#endif // WITH_DEV_AUTOMATION_TESTS
