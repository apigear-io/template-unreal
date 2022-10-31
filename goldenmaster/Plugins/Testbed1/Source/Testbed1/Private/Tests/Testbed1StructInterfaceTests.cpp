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

#include "../Implementation/Testbed1StructInterface.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTestbed1StructInterfaceImplementationPropertyPropBoolTest, "Testbed1.StructInterface.Implementation.Property.PropBool", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTestbed1StructInterfaceImplementationPropertyPropBoolTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITestbed1StructInterfaceInterface> test = NewObject<UTestbed1StructInterface>();
	test->Execute_SetPropBool(test.GetObject(), FTestbed1StructBool());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropBool(test.GetObject()), FTestbed1StructBool());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTestbed1StructInterfaceImplementationPropertyPropIntTest, "Testbed1.StructInterface.Implementation.Property.PropInt", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTestbed1StructInterfaceImplementationPropertyPropIntTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITestbed1StructInterfaceInterface> test = NewObject<UTestbed1StructInterface>();
	test->Execute_SetPropInt(test.GetObject(), FTestbed1StructInt());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropInt(test.GetObject()), FTestbed1StructInt());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTestbed1StructInterfaceImplementationPropertyPropFloatTest, "Testbed1.StructInterface.Implementation.Property.PropFloat", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTestbed1StructInterfaceImplementationPropertyPropFloatTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITestbed1StructInterfaceInterface> test = NewObject<UTestbed1StructInterface>();
	test->Execute_SetPropFloat(test.GetObject(), FTestbed1StructFloat());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropFloat(test.GetObject()), FTestbed1StructFloat());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTestbed1StructInterfaceImplementationPropertyPropStringTest, "Testbed1.StructInterface.Implementation.Property.PropString", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTestbed1StructInterfaceImplementationPropertyPropStringTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITestbed1StructInterfaceInterface> test = NewObject<UTestbed1StructInterface>();
	test->Execute_SetPropString(test.GetObject(), FTestbed1StructString());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropString(test.GetObject()), FTestbed1StructString());
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
