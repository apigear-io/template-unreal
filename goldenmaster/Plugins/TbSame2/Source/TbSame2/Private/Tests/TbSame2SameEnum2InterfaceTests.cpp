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

#include "../Implementation/TbSame2SameEnum2Interface.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSame2SameEnum2InterfaceImplementationPropertyProp1Test, "TbSame2.SameEnum2Interface.Implementation.Property.Prop1", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSame2SameEnum2InterfaceImplementationPropertyProp1Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> test = NewObject<UTbSame2SameEnum2Interface>();
	test->Execute_SetProp1(test.GetObject(), ETbSame2Enum1::VALUE1);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetProp1(test.GetObject()), ETbSame2Enum1::VALUE1);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSame2SameEnum2InterfaceImplementationPropertyProp2Test, "TbSame2.SameEnum2Interface.Implementation.Property.Prop2", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSame2SameEnum2InterfaceImplementationPropertyProp2Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> test = NewObject<UTbSame2SameEnum2Interface>();
	test->Execute_SetProp2(test.GetObject(), ETbSame2Enum2::VALUE1);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetProp2(test.GetObject()), ETbSame2Enum2::VALUE1);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
