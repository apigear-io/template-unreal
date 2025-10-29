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
#include "TbEnum/Tests/TbEnumTestsCommon.h"
#include "TbEnum/Generated/api/TbEnum_data.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS
TArray<ETbEnumEnum0> createTestFTbEnumEnum0Array()
{
	TArray<ETbEnumEnum0> TestValueArray;

	ETbEnumEnum0 val = ETbEnumEnum0::TEE0_Value0;
	TestValueArray.Add(val);
	return TestValueArray;
}


TArray<ETbEnumEnum1> createTestFTbEnumEnum1Array()
{
	TArray<ETbEnumEnum1> TestValueArray;

	ETbEnumEnum1 val = ETbEnumEnum1::TEE1_Value1;
	TestValueArray.Add(val);
	return TestValueArray;
}


TArray<ETbEnumEnum2> createTestFTbEnumEnum2Array()
{
	TArray<ETbEnumEnum2> TestValueArray;

	ETbEnumEnum2 val = ETbEnumEnum2::TEE2_Value2;
	TestValueArray.Add(val);
	return TestValueArray;
}


TArray<ETbEnumEnum3> createTestFTbEnumEnum3Array()
{
	TArray<ETbEnumEnum3> TestValueArray;

	ETbEnumEnum3 val = ETbEnumEnum3::TEE3_Value3;
	TestValueArray.Add(val);
	return TestValueArray;
}



#endif // WITH_DEV_AUTOMATION_TESTS
