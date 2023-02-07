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

#include "Implementation/TbSimpleSimpleArrayInterface.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationPropertyPropBoolTest, "TbSimple.SimpleArrayInterface.Implementation.Property.PropBool", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationPropertyPropBoolTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = NewObject<UTbSimpleSimpleArrayInterface>();
	test->Execute_SetPropBool(test.GetObject(), TArray<bool>());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropBool(test.GetObject()), TArray<bool>());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationPropertyPropIntTest, "TbSimple.SimpleArrayInterface.Implementation.Property.PropInt", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationPropertyPropIntTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = NewObject<UTbSimpleSimpleArrayInterface>();
	test->Execute_SetPropInt(test.GetObject(), TArray<int32>());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropInt(test.GetObject()), TArray<int32>());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationPropertyPropFloatTest, "TbSimple.SimpleArrayInterface.Implementation.Property.PropFloat", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationPropertyPropFloatTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = NewObject<UTbSimpleSimpleArrayInterface>();
	test->Execute_SetPropFloat(test.GetObject(), TArray<float>());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropFloat(test.GetObject()), TArray<float>());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationPropertyPropStringTest, "TbSimple.SimpleArrayInterface.Implementation.Property.PropString", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationPropertyPropStringTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = NewObject<UTbSimpleSimpleArrayInterface>();
	test->Execute_SetPropString(test.GetObject(), TArray<FString>());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropString(test.GetObject()), TArray<FString>());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationOperationFuncBoolTest, "TbSimple.SimpleArrayInterface.Implementation.Operation.FuncBool", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationOperationFuncBoolTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = NewObject<UTbSimpleSimpleArrayInterface>();
	test->Execute_FuncBool(test.GetObject(), TArray<bool>());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationOperationFuncIntTest, "TbSimple.SimpleArrayInterface.Implementation.Operation.FuncInt", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationOperationFuncIntTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = NewObject<UTbSimpleSimpleArrayInterface>();
	test->Execute_FuncInt(test.GetObject(), TArray<int32>());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationOperationFuncFloatTest, "TbSimple.SimpleArrayInterface.Implementation.Operation.FuncFloat", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationOperationFuncFloatTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = NewObject<UTbSimpleSimpleArrayInterface>();
	test->Execute_FuncFloat(test.GetObject(), TArray<float>());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationOperationFuncStringTest, "TbSimple.SimpleArrayInterface.Implementation.Operation.FuncString", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationOperationFuncStringTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = NewObject<UTbSimpleSimpleArrayInterface>();
	test->Execute_FuncString(test.GetObject(), TArray<FString>());
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
