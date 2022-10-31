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

#include "../Implementation/Testbed2NoPropertyInterface.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTestbed2NoPropertyInterfaceImplementationOperationFunc1Test, "Testbed2.NoPropertyInterface.Implementation.Operation.Func1", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTestbed2NoPropertyInterfaceImplementationOperationFunc1Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITestbed2NoPropertyInterfaceInterface> test = NewObject<UTestbed2NoPropertyInterface>();
	test->Execute_Func1(test.GetObject(), FTestbed2NestedStruct1());
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
