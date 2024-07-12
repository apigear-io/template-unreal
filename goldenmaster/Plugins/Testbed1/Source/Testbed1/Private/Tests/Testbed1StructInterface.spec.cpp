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

#include "Implementation/Testbed1StructInterface.h"
#include "Testbed1GameInstanceFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS 


BEGIN_DEFINE_SPEC(UTestbed1StructInterfaceImplementationSpec, "Testbed1.StructInterface.Implementation",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

	TUniquePtr<FTestbed1GameInstanceFixture> GameInstanceFixture;
	TScriptInterface<ITestbed1StructInterfaceInterface> testImplementation;

END_DEFINE_SPEC(UTestbed1StructInterfaceImplementationSpec);

void UTestbed1StructInterfaceImplementationSpec::Define()
{
	BeforeEach([this]()
	{
		GameInstanceFixture = MakeUnique<FTestbed1GameInstanceFixture>();
		TestTrue("Check for valid GameInstanceFixture", GameInstanceFixture.IsValid());
		
		testImplementation = GameInstanceFixture->GetGameInstance()->GetSubsystem<UTestbed1StructInterface>();
		TestTrue("Check for valid testImplementation", testImplementation.GetInterface() != nullptr);
	});

	AfterEach([this]()
	{
		GameInstanceFixture.Reset();
	});

	It("Property.PropBool", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropBool(testImplementation.GetObject(), FTestbed1StructBool());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropBool(testImplementation.GetObject()), FTestbed1StructBool());
	});

	It("Property.PropInt", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropInt(testImplementation.GetObject(), FTestbed1StructInt());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropInt(testImplementation.GetObject()), FTestbed1StructInt());
	});

	It("Property.PropFloat", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropFloat(testImplementation.GetObject(), FTestbed1StructFloat());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropFloat(testImplementation.GetObject()), FTestbed1StructFloat());
	});

	It("Property.PropString", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropString(testImplementation.GetObject(), FTestbed1StructString());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropString(testImplementation.GetObject()), FTestbed1StructString());
	});

	It("Operation.FuncBool", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncBool(testImplementation.GetObject(), FTestbed1StructBool());
	});

	It("Operation.FuncInt", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncInt(testImplementation.GetObject(), FTestbed1StructInt());
	});

	It("Operation.FuncFloat", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncFloat(testImplementation.GetObject(), FTestbed1StructFloat());
	});

	It("Operation.FuncString", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncString(testImplementation.GetObject(), FTestbed1StructString());
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
