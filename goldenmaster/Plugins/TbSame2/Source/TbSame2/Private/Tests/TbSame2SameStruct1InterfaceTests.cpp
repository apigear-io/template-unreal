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

#include "Implementation/TbSame2SameStruct1Interface.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSame2SameStruct1InterfaceImplementationPropertyProp1Test, "TbSame2.SameStruct1Interface.Implementation.Property.Prop1", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSame2SameStruct1InterfaceImplementationPropertyProp1Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> test = NewObject<UTbSame2SameStruct1Interface>();
	test->Execute_SetProp1(test.GetObject(), FTbSame2Struct1());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetProp1(test.GetObject()), FTbSame2Struct1());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSame2SameStruct1InterfaceImplementationOperationFunc1Test, "TbSame2.SameStruct1Interface.Implementation.Operation.Func1", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSame2SameStruct1InterfaceImplementationOperationFunc1Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> test = NewObject<UTbSame2SameStruct1Interface>();
	test->Execute_Func1(test.GetObject(), FTbSame2Struct1());
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
