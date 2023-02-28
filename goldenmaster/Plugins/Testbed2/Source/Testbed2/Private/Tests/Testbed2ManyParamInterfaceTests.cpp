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

#include "Implementation/Testbed2ManyParamInterface.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTestbed2ManyParamInterfaceImplementationPropertyProp1Test, "Testbed2.ManyParamInterface.Implementation.Property.Prop1", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTestbed2ManyParamInterfaceImplementationPropertyProp1Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> test = GameInstance->GetSubsystem<UTestbed2ManyParamInterface>();
	test->Execute_SetProp1(test.GetObject(), 0);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetProp1(test.GetObject()), 0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTestbed2ManyParamInterfaceImplementationPropertyProp2Test, "Testbed2.ManyParamInterface.Implementation.Property.Prop2", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTestbed2ManyParamInterfaceImplementationPropertyProp2Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> test = GameInstance->GetSubsystem<UTestbed2ManyParamInterface>();
	test->Execute_SetProp2(test.GetObject(), 0);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetProp2(test.GetObject()), 0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTestbed2ManyParamInterfaceImplementationPropertyProp3Test, "Testbed2.ManyParamInterface.Implementation.Property.Prop3", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTestbed2ManyParamInterfaceImplementationPropertyProp3Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> test = GameInstance->GetSubsystem<UTestbed2ManyParamInterface>();
	test->Execute_SetProp3(test.GetObject(), 0);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetProp3(test.GetObject()), 0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTestbed2ManyParamInterfaceImplementationPropertyProp4Test, "Testbed2.ManyParamInterface.Implementation.Property.Prop4", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTestbed2ManyParamInterfaceImplementationPropertyProp4Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> test = GameInstance->GetSubsystem<UTestbed2ManyParamInterface>();
	test->Execute_SetProp4(test.GetObject(), 0);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetProp4(test.GetObject()), 0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTestbed2ManyParamInterfaceImplementationOperationFunc1Test, "Testbed2.ManyParamInterface.Implementation.Operation.Func1", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTestbed2ManyParamInterfaceImplementationOperationFunc1Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> test = GameInstance->GetSubsystem<UTestbed2ManyParamInterface>();
	test->Execute_Func1(test.GetObject(), 0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTestbed2ManyParamInterfaceImplementationOperationFunc2Test, "Testbed2.ManyParamInterface.Implementation.Operation.Func2", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTestbed2ManyParamInterfaceImplementationOperationFunc2Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> test = GameInstance->GetSubsystem<UTestbed2ManyParamInterface>();
	test->Execute_Func2(test.GetObject(), 0, 0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTestbed2ManyParamInterfaceImplementationOperationFunc3Test, "Testbed2.ManyParamInterface.Implementation.Operation.Func3", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTestbed2ManyParamInterfaceImplementationOperationFunc3Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> test = GameInstance->GetSubsystem<UTestbed2ManyParamInterface>();
	test->Execute_Func3(test.GetObject(), 0, 0, 0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTestbed2ManyParamInterfaceImplementationOperationFunc4Test, "Testbed2.ManyParamInterface.Implementation.Operation.Func4", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTestbed2ManyParamInterfaceImplementationOperationFunc4Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> test = GameInstance->GetSubsystem<UTestbed2ManyParamInterface>();
	test->Execute_Func4(test.GetObject(), 0, 0, 0, 0);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
