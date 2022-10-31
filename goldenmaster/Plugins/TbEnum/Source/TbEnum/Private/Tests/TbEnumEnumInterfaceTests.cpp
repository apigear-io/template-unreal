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

#include "../Implementation/TbEnumEnumInterface.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbEnumEnumInterfaceImplementationPropertyProp0Test, "TbEnum.EnumInterface.Implementation.Property.Prop0", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbEnumEnumInterfaceImplementationPropertyProp0Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbEnumEnumInterfaceInterface> test = NewObject<UTbEnumEnumInterface>();
	test->Execute_SetProp0(test.GetObject(), ETbEnumEnum0::VALUE0);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetProp0(test.GetObject()), ETbEnumEnum0::VALUE0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbEnumEnumInterfaceImplementationPropertyProp1Test, "TbEnum.EnumInterface.Implementation.Property.Prop1", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbEnumEnumInterfaceImplementationPropertyProp1Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbEnumEnumInterfaceInterface> test = NewObject<UTbEnumEnumInterface>();
	test->Execute_SetProp1(test.GetObject(), ETbEnumEnum1::VALUE1);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetProp1(test.GetObject()), ETbEnumEnum1::VALUE1);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbEnumEnumInterfaceImplementationPropertyProp2Test, "TbEnum.EnumInterface.Implementation.Property.Prop2", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbEnumEnumInterfaceImplementationPropertyProp2Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbEnumEnumInterfaceInterface> test = NewObject<UTbEnumEnumInterface>();
	test->Execute_SetProp2(test.GetObject(), ETbEnumEnum2::VALUE2);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetProp2(test.GetObject()), ETbEnumEnum2::VALUE2);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UTbEnumEnumInterfaceImplementationPropertyProp3Test, "TbEnum.EnumInterface.Implementation.Property.Prop3", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)
bool UTbEnumEnumInterfaceImplementationPropertyProp3Test::RunTest(const FString& Parameters)
{
	// Do implement test here
	TScriptInterface<ITbEnumEnumInterfaceInterface> test = NewObject<UTbEnumEnumInterface>();
	test->Execute_SetProp3(test.GetObject(), ETbEnumEnum3::VALUE3);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), test->Execute_GetProp3(test.GetObject()), ETbEnumEnum3::VALUE3);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
