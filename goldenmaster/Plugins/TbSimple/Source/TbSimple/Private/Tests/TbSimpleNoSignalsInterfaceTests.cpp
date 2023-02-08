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

#include "Implementation/TbSimpleNoSignalsInterface.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleNoSignalsInterfaceImplementationPropertyPropBoolTest, "TbSimple.NoSignalsInterface.Implementation.Property.PropBool", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleNoSignalsInterfaceImplementationPropertyPropBoolTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> test = NewObject<UTbSimpleNoSignalsInterface>();
	test->Execute_SetPropBool(test.GetObject(), false);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropBool(test.GetObject()), false);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleNoSignalsInterfaceImplementationPropertyPropIntTest, "TbSimple.NoSignalsInterface.Implementation.Property.PropInt", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleNoSignalsInterfaceImplementationPropertyPropIntTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> test = NewObject<UTbSimpleNoSignalsInterface>();
	test->Execute_SetPropInt(test.GetObject(), 0);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetPropInt(test.GetObject()), 0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleNoSignalsInterfaceImplementationOperationFuncVoidTest, "TbSimple.NoSignalsInterface.Implementation.Operation.FuncVoid", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleNoSignalsInterfaceImplementationOperationFuncVoidTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> test = NewObject<UTbSimpleNoSignalsInterface>();
	test->Execute_FuncVoid(test.GetObject());
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbSimpleNoSignalsInterfaceImplementationOperationFuncBoolTest, "TbSimple.NoSignalsInterface.Implementation.Operation.FuncBool", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbSimpleNoSignalsInterfaceImplementationOperationFuncBoolTest::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> test = NewObject<UTbSimpleNoSignalsInterface>();
	test->Execute_FuncBool(test.GetObject(), false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
