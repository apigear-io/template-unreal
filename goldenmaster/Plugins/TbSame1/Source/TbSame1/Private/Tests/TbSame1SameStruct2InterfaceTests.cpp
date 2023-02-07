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

#include "Implementation/TbSame1SameStruct2Interface.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSame1SameStruct2InterfaceImplementationPropertyProp1Test, "TbSame1.SameStruct2Interface.Implementation.Property.Prop1", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSame1SameStruct2InterfaceImplementationPropertyProp1Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> test = NewObject<UTbSame1SameStruct2Interface>();
	test->Execute_SetProp1(test.GetObject(), FTbSame1Struct2());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetProp1(test.GetObject()), FTbSame1Struct2());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSame1SameStruct2InterfaceImplementationPropertyProp2Test, "TbSame1.SameStruct2Interface.Implementation.Property.Prop2", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSame1SameStruct2InterfaceImplementationPropertyProp2Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> test = NewObject<UTbSame1SameStruct2Interface>();
	test->Execute_SetProp2(test.GetObject(), FTbSame1Struct2());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetProp2(test.GetObject()), FTbSame1Struct2());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSame1SameStruct2InterfaceImplementationOperationFunc1Test, "TbSame1.SameStruct2Interface.Implementation.Operation.Func1", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSame1SameStruct2InterfaceImplementationOperationFunc1Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> test = NewObject<UTbSame1SameStruct2Interface>();
	test->Execute_Func1(test.GetObject(), FTbSame1Struct1());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSame1SameStruct2InterfaceImplementationOperationFunc2Test, "TbSame1.SameStruct2Interface.Implementation.Operation.Func2", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSame1SameStruct2InterfaceImplementationOperationFunc2Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> test = NewObject<UTbSame1SameStruct2Interface>();
	test->Execute_Func2(test.GetObject(), FTbSame1Struct1(), FTbSame1Struct2());
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
