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

#include "Implementation/Testbed1StructArrayInterface.h"
#include "Testbed1TestBase.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTestbed1StructArrayInterfaceImplementationPropertyPropBoolTest, FTestbed1TestBase, "Testbed1.StructArrayInterface.Implementation.Property.PropBool", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTestbed1StructArrayInterfaceImplementationPropertyPropBoolTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
	test->Execute_SetPropBool(test.GetObject(), TArray<FTestbed1StructBool>());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropBool(test.GetObject()), TArray<FTestbed1StructBool>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTestbed1StructArrayInterfaceImplementationPropertyPropIntTest, FTestbed1TestBase, "Testbed1.StructArrayInterface.Implementation.Property.PropInt", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTestbed1StructArrayInterfaceImplementationPropertyPropIntTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
	test->Execute_SetPropInt(test.GetObject(), TArray<FTestbed1StructInt>());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropInt(test.GetObject()), TArray<FTestbed1StructInt>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTestbed1StructArrayInterfaceImplementationPropertyPropFloatTest, FTestbed1TestBase, "Testbed1.StructArrayInterface.Implementation.Property.PropFloat", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTestbed1StructArrayInterfaceImplementationPropertyPropFloatTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
	test->Execute_SetPropFloat(test.GetObject(), TArray<FTestbed1StructFloat>());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropFloat(test.GetObject()), TArray<FTestbed1StructFloat>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTestbed1StructArrayInterfaceImplementationPropertyPropStringTest, FTestbed1TestBase, "Testbed1.StructArrayInterface.Implementation.Property.PropString", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTestbed1StructArrayInterfaceImplementationPropertyPropStringTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
	test->Execute_SetPropString(test.GetObject(), TArray<FTestbed1StructString>());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropString(test.GetObject()), TArray<FTestbed1StructString>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTestbed1StructArrayInterfaceImplementationOperationFuncBoolTest, FTestbed1TestBase, "Testbed1.StructArrayInterface.Implementation.Operation.FuncBool", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTestbed1StructArrayInterfaceImplementationOperationFuncBoolTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
	test->Execute_FuncBool(test.GetObject(), TArray<FTestbed1StructBool>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTestbed1StructArrayInterfaceImplementationOperationFuncIntTest, FTestbed1TestBase, "Testbed1.StructArrayInterface.Implementation.Operation.FuncInt", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTestbed1StructArrayInterfaceImplementationOperationFuncIntTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
	test->Execute_FuncInt(test.GetObject(), TArray<FTestbed1StructInt>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTestbed1StructArrayInterfaceImplementationOperationFuncFloatTest, FTestbed1TestBase, "Testbed1.StructArrayInterface.Implementation.Operation.FuncFloat", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTestbed1StructArrayInterfaceImplementationOperationFuncFloatTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
	test->Execute_FuncFloat(test.GetObject(), TArray<FTestbed1StructFloat>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTestbed1StructArrayInterfaceImplementationOperationFuncStringTest, FTestbed1TestBase, "Testbed1.StructArrayInterface.Implementation.Operation.FuncString", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTestbed1StructArrayInterfaceImplementationOperationFuncStringTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
	test->Execute_FuncString(test.GetObject(), TArray<FTestbed1StructString>());

	CleanUp();
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
