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

#include "Implementation/TbSimpleNoOperationsInterface.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleNoOperationsInterfaceImplementationPropertyPropBoolTest, "TbSimple.NoOperationsInterface.Implementation.Property.PropBool", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleNoOperationsInterfaceImplementationPropertyPropBoolTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> test = NewObject<UTbSimpleNoOperationsInterface>();
	test->Execute_SetPropBool(test.GetObject(), false);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropBool(test.GetObject()), false);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleNoOperationsInterfaceImplementationPropertyPropIntTest, "TbSimple.NoOperationsInterface.Implementation.Property.PropInt", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleNoOperationsInterfaceImplementationPropertyPropIntTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> test = NewObject<UTbSimpleNoOperationsInterface>();
	test->Execute_SetPropInt(test.GetObject(), 0);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropInt(test.GetObject()), 0);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
