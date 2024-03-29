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
#include "TbSimpleTestBase.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationPropertyPropBoolTest, FTbSimpleTestBase, "TbSimple.SimpleArrayInterface.Implementation.Property.PropBool", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationPropertyPropBoolTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
	test->Execute_SetPropBool(test.GetObject(), TArray<bool>());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropBool(test.GetObject()), TArray<bool>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationPropertyPropIntTest, FTbSimpleTestBase, "TbSimple.SimpleArrayInterface.Implementation.Property.PropInt", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationPropertyPropIntTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
	test->Execute_SetPropInt(test.GetObject(), TArray<int32>());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropInt(test.GetObject()), TArray<int32>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationPropertyPropInt32Test, FTbSimpleTestBase, "TbSimple.SimpleArrayInterface.Implementation.Property.PropInt32", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationPropertyPropInt32Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
	test->Execute_SetPropInt32(test.GetObject(), TArray<int32>());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropInt32(test.GetObject()), TArray<int32>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationPropertyPropInt64Test, FTbSimpleTestBase, "TbSimple.SimpleArrayInterface.Implementation.Property.PropInt64", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationPropertyPropInt64Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
	test->Execute_SetPropInt64(test.GetObject(), TArray<int64>());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropInt64(test.GetObject()), TArray<int64>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationPropertyPropFloatTest, FTbSimpleTestBase, "TbSimple.SimpleArrayInterface.Implementation.Property.PropFloat", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationPropertyPropFloatTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
	test->Execute_SetPropFloat(test.GetObject(), TArray<float>());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropFloat(test.GetObject()), TArray<float>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationPropertyPropFloat32Test, FTbSimpleTestBase, "TbSimple.SimpleArrayInterface.Implementation.Property.PropFloat32", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationPropertyPropFloat32Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
	test->Execute_SetPropFloat32(test.GetObject(), TArray<float>());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropFloat32(test.GetObject()), TArray<float>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationPropertyPropFloat64Test, FTbSimpleTestBase, "TbSimple.SimpleArrayInterface.Implementation.Property.PropFloat64", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationPropertyPropFloat64Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
	test->Execute_SetPropFloat64(test.GetObject(), TArray<double>());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropFloat64(test.GetObject()), TArray<double>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationPropertyPropStringTest, FTbSimpleTestBase, "TbSimple.SimpleArrayInterface.Implementation.Property.PropString", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationPropertyPropStringTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
	test->Execute_SetPropString(test.GetObject(), TArray<FString>());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropString(test.GetObject()), TArray<FString>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationOperationFuncBoolTest, FTbSimpleTestBase, "TbSimple.SimpleArrayInterface.Implementation.Operation.FuncBool", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationOperationFuncBoolTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
	test->Execute_FuncBool(test.GetObject(), TArray<bool>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationOperationFuncIntTest, FTbSimpleTestBase, "TbSimple.SimpleArrayInterface.Implementation.Operation.FuncInt", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationOperationFuncIntTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
	test->Execute_FuncInt(test.GetObject(), TArray<int32>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationOperationFuncInt32Test, FTbSimpleTestBase, "TbSimple.SimpleArrayInterface.Implementation.Operation.FuncInt32", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationOperationFuncInt32Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
	test->Execute_FuncInt32(test.GetObject(), TArray<int32>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationOperationFuncInt64Test, FTbSimpleTestBase, "TbSimple.SimpleArrayInterface.Implementation.Operation.FuncInt64", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationOperationFuncInt64Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
	test->Execute_FuncInt64(test.GetObject(), TArray<int64>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationOperationFuncFloatTest, FTbSimpleTestBase, "TbSimple.SimpleArrayInterface.Implementation.Operation.FuncFloat", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationOperationFuncFloatTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
	test->Execute_FuncFloat(test.GetObject(), TArray<float>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationOperationFuncFloat32Test, FTbSimpleTestBase, "TbSimple.SimpleArrayInterface.Implementation.Operation.FuncFloat32", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationOperationFuncFloat32Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
	test->Execute_FuncFloat32(test.GetObject(), TArray<float>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationOperationFuncFloat64Test, FTbSimpleTestBase, "TbSimple.SimpleArrayInterface.Implementation.Operation.FuncFloat64", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationOperationFuncFloat64Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
	test->Execute_FuncFloat64(test.GetObject(), TArray<double>());

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleArrayInterfaceImplementationOperationFuncStringTest, FTbSimpleTestBase, "TbSimple.SimpleArrayInterface.Implementation.Operation.FuncString", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleArrayInterfaceImplementationOperationFuncStringTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
	test->Execute_FuncString(test.GetObject(), TArray<FString>());

	CleanUp();
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
