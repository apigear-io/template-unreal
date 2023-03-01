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

#include "Implementation/TbEnumEnumInterface.h"
#include "TbEnumTestBase.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbEnumEnumInterfaceImplementationPropertyProp0Test, FTbEnumTestBase, "TbEnum.EnumInterface.Implementation.Property.Prop0", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbEnumEnumInterfaceImplementationPropertyProp0Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbEnumEnumInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
	test->Execute_SetProp0(test.GetObject(), ETbEnumEnum0::TEE_VALUE0);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetProp0(test.GetObject()), ETbEnumEnum0::TEE_VALUE0);

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbEnumEnumInterfaceImplementationPropertyProp1Test, FTbEnumTestBase, "TbEnum.EnumInterface.Implementation.Property.Prop1", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbEnumEnumInterfaceImplementationPropertyProp1Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbEnumEnumInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
	test->Execute_SetProp1(test.GetObject(), ETbEnumEnum1::TEE_VALUE1);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetProp1(test.GetObject()), ETbEnumEnum1::TEE_VALUE1);

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbEnumEnumInterfaceImplementationPropertyProp2Test, FTbEnumTestBase, "TbEnum.EnumInterface.Implementation.Property.Prop2", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbEnumEnumInterfaceImplementationPropertyProp2Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbEnumEnumInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
	test->Execute_SetProp2(test.GetObject(), ETbEnumEnum2::TEE_VALUE2);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetProp2(test.GetObject()), ETbEnumEnum2::TEE_VALUE2);

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbEnumEnumInterfaceImplementationPropertyProp3Test, FTbEnumTestBase, "TbEnum.EnumInterface.Implementation.Property.Prop3", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbEnumEnumInterfaceImplementationPropertyProp3Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbEnumEnumInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
	test->Execute_SetProp3(test.GetObject(), ETbEnumEnum3::TEE_VALUE3);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetProp3(test.GetObject()), ETbEnumEnum3::TEE_VALUE3);

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbEnumEnumInterfaceImplementationOperationFunc0Test, FTbEnumTestBase, "TbEnum.EnumInterface.Implementation.Operation.Func0", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbEnumEnumInterfaceImplementationOperationFunc0Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbEnumEnumInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
	test->Execute_Func0(test.GetObject(), ETbEnumEnum0::TEE_VALUE0);

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbEnumEnumInterfaceImplementationOperationFunc1Test, FTbEnumTestBase, "TbEnum.EnumInterface.Implementation.Operation.Func1", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbEnumEnumInterfaceImplementationOperationFunc1Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbEnumEnumInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
	test->Execute_Func1(test.GetObject(), ETbEnumEnum1::TEE_VALUE1);

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbEnumEnumInterfaceImplementationOperationFunc2Test, FTbEnumTestBase, "TbEnum.EnumInterface.Implementation.Operation.Func2", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbEnumEnumInterfaceImplementationOperationFunc2Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbEnumEnumInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
	test->Execute_Func2(test.GetObject(), ETbEnumEnum2::TEE_VALUE2);

	CleanUp();
	return true;
}

IMPLEMENT_CUSTOM_SIMPLE_AUTOMATION_TEST(UTbEnumEnumInterfaceImplementationOperationFunc3Test, FTbEnumTestBase, "TbEnum.EnumInterface.Implementation.Operation.Func3", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbEnumEnumInterfaceImplementationOperationFunc3Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbEnumEnumInterfaceInterface> test = GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
	test->Execute_Func3(test.GetObject(), ETbEnumEnum3::TEE_VALUE3);

	CleanUp();
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
