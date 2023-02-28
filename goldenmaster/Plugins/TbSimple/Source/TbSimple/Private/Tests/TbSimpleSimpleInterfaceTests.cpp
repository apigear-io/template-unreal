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

#include "Implementation/TbSimpleSimpleInterface.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationPropertyPropBoolTest, "TbSimple.SimpleInterface.Implementation.Property.PropBool", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleInterfaceImplementationPropertyPropBoolTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>();
	test->Execute_SetPropBool(test.GetObject(), false);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropBool(test.GetObject()), false);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationPropertyPropIntTest, "TbSimple.SimpleInterface.Implementation.Property.PropInt", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleInterfaceImplementationPropertyPropIntTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>();
	test->Execute_SetPropInt(test.GetObject(), 0);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropInt(test.GetObject()), 0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationPropertyPropInt32Test, "TbSimple.SimpleInterface.Implementation.Property.PropInt32", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleInterfaceImplementationPropertyPropInt32Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>();
	test->Execute_SetPropInt32(test.GetObject(), 0);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropInt32(test.GetObject()), 0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationPropertyPropInt64Test, "TbSimple.SimpleInterface.Implementation.Property.PropInt64", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleInterfaceImplementationPropertyPropInt64Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>();
	test->Execute_SetPropInt64(test.GetObject(), 0LL);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropInt64(test.GetObject()), 0LL);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationPropertyPropFloatTest, "TbSimple.SimpleInterface.Implementation.Property.PropFloat", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleInterfaceImplementationPropertyPropFloatTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>();
	test->Execute_SetPropFloat(test.GetObject(), 0.0f);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropFloat(test.GetObject()), 0.0f);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationPropertyPropFloat32Test, "TbSimple.SimpleInterface.Implementation.Property.PropFloat32", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleInterfaceImplementationPropertyPropFloat32Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>();
	test->Execute_SetPropFloat32(test.GetObject(), 0.0f);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropFloat32(test.GetObject()), 0.0f);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationPropertyPropFloat64Test, "TbSimple.SimpleInterface.Implementation.Property.PropFloat64", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleInterfaceImplementationPropertyPropFloat64Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>();
	test->Execute_SetPropFloat64(test.GetObject(), 0.0);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropFloat64(test.GetObject()), 0.0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationPropertyPropStringTest, "TbSimple.SimpleInterface.Implementation.Property.PropString", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleInterfaceImplementationPropertyPropStringTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>();
	test->Execute_SetPropString(test.GetObject(), FString());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropString(test.GetObject()), FString());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationOperationFuncVoidTest, "TbSimple.SimpleInterface.Implementation.Operation.FuncVoid", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleInterfaceImplementationOperationFuncVoidTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>();
	test->Execute_FuncVoid(test.GetObject());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationOperationFuncBoolTest, "TbSimple.SimpleInterface.Implementation.Operation.FuncBool", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleInterfaceImplementationOperationFuncBoolTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>();
	test->Execute_FuncBool(test.GetObject(), false);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationOperationFuncIntTest, "TbSimple.SimpleInterface.Implementation.Operation.FuncInt", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleInterfaceImplementationOperationFuncIntTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>();
	test->Execute_FuncInt(test.GetObject(), 0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationOperationFuncInt32Test, "TbSimple.SimpleInterface.Implementation.Operation.FuncInt32", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleInterfaceImplementationOperationFuncInt32Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>();
	test->Execute_FuncInt32(test.GetObject(), 0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationOperationFuncInt64Test, "TbSimple.SimpleInterface.Implementation.Operation.FuncInt64", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleInterfaceImplementationOperationFuncInt64Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>();
	test->Execute_FuncInt64(test.GetObject(), 0LL);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationOperationFuncFloatTest, "TbSimple.SimpleInterface.Implementation.Operation.FuncFloat", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleInterfaceImplementationOperationFuncFloatTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>();
	test->Execute_FuncFloat(test.GetObject(), 0.0f);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationOperationFuncFloat32Test, "TbSimple.SimpleInterface.Implementation.Operation.FuncFloat32", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleInterfaceImplementationOperationFuncFloat32Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>();
	test->Execute_FuncFloat32(test.GetObject(), 0.0f);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationOperationFuncFloat64Test, "TbSimple.SimpleInterface.Implementation.Operation.FuncFloat64", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleInterfaceImplementationOperationFuncFloat64Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>();
	test->Execute_FuncFloat64(test.GetObject(), 0.0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationOperationFuncStringTest, "TbSimple.SimpleInterface.Implementation.Operation.FuncString", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleSimpleInterfaceImplementationOperationFuncStringTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>();
	test->Execute_FuncString(test.GetObject(), FString());
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
