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

#include "Implementation/TbSimpleNoPropertiesInterface.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleNoPropertiesInterfaceImplementationOperationFuncVoidTest, "TbSimple.NoPropertiesInterface.Implementation.Operation.FuncVoid", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleNoPropertiesInterfaceImplementationOperationFuncVoidTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleNoPropertiesInterface>();
	test->Execute_FuncVoid(test.GetObject());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleNoPropertiesInterfaceImplementationOperationFuncBoolTest, "TbSimple.NoPropertiesInterface.Implementation.Operation.FuncBool", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
bool UTbSimpleNoPropertiesInterfaceImplementationOperationFuncBoolTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	GameInstance->Init();
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> test = GameInstance->GetSubsystem<UTbSimpleNoPropertiesInterface>();
	test->Execute_FuncBool(test.GetObject(), false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
