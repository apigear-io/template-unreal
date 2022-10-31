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

#include "../Implementation/TbSimpleSimpleInterface.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationPropertyPropBoolTest, "TbSimple.SimpleInterface.Implementation.Property.PropBool", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleSimpleInterfaceImplementationPropertyPropBoolTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = NewObject<UTbSimpleSimpleInterface>();
	test->Execute_SetPropBool(test.GetObject(), false);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropBool(test.GetObject()), false);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationPropertyPropIntTest, "TbSimple.SimpleInterface.Implementation.Property.PropInt", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleSimpleInterfaceImplementationPropertyPropIntTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = NewObject<UTbSimpleSimpleInterface>();
	test->Execute_SetPropInt(test.GetObject(), 0);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropInt(test.GetObject()), 0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationPropertyPropFloatTest, "TbSimple.SimpleInterface.Implementation.Property.PropFloat", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleSimpleInterfaceImplementationPropertyPropFloatTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = NewObject<UTbSimpleSimpleInterface>();
	test->Execute_SetPropFloat(test.GetObject(), 0.0f);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropFloat(test.GetObject()), 0.0f);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleSimpleInterfaceImplementationPropertyPropStringTest, "TbSimple.SimpleInterface.Implementation.Property.PropString", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleSimpleInterfaceImplementationPropertyPropStringTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> test = NewObject<UTbSimpleSimpleInterface>();
	test->Execute_SetPropString(test.GetObject(), FString());
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropString(test.GetObject()), FString());
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
