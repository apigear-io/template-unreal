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
#include "TbEnumGameInstanceFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS 


BEGIN_DEFINE_SPEC(UTbEnumEnumInterfaceImplementationSpec, "TbEnum.EnumInterface.Implementation",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

	TUniquePtr<FTbEnumGameInstanceFixture> GameInstanceFixture;
	TScriptInterface<ITbEnumEnumInterfaceInterface> testImplementation;

END_DEFINE_SPEC(UTbEnumEnumInterfaceImplementationSpec);

void UTbEnumEnumInterfaceImplementationSpec::Define()
{
	BeforeEach([this]()
	{
		GameInstanceFixture = MakeUnique<FTbEnumGameInstanceFixture>();
		TestTrue("Check for valid GameInstanceFixture", GameInstanceFixture.IsValid());
		
		testImplementation = GameInstanceFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		TestTrue("Check for valid testImplementation", testImplementation.GetInterface() != nullptr);
	});

	AfterEach([this]()
	{
		GameInstanceFixture.Reset();
	});

	It("Property.Prop0", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetProp0(testImplementation.GetObject(), ETbEnumEnum0::TEE_VALUE0);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetProp0(testImplementation.GetObject()), ETbEnumEnum0::TEE_VALUE0);
	});

	It("Property.Prop1", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetProp1(testImplementation.GetObject(), ETbEnumEnum1::TEE_VALUE1);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetProp1(testImplementation.GetObject()), ETbEnumEnum1::TEE_VALUE1);
	});

	It("Property.Prop2", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetProp2(testImplementation.GetObject(), ETbEnumEnum2::TEE_VALUE2);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetProp2(testImplementation.GetObject()), ETbEnumEnum2::TEE_VALUE2);
	});

	It("Property.Prop3", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetProp3(testImplementation.GetObject(), ETbEnumEnum3::TEE_VALUE3);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetProp3(testImplementation.GetObject()), ETbEnumEnum3::TEE_VALUE3);
	});

	It("Operation.Func0", [this]()
	{
		// Do implement test here
		testImplementation->Execute_Func0(testImplementation.GetObject(), ETbEnumEnum0::TEE_VALUE0);
	});

	It("Operation.Func1", [this]()
	{
		// Do implement test here
		testImplementation->Execute_Func1(testImplementation.GetObject(), ETbEnumEnum1::TEE_VALUE1);
	});

	It("Operation.Func2", [this]()
	{
		// Do implement test here
		testImplementation->Execute_Func2(testImplementation.GetObject(), ETbEnumEnum2::TEE_VALUE2);
	});

	It("Operation.Func3", [this]()
	{
		// Do implement test here
		testImplementation->Execute_Func3(testImplementation.GetObject(), ETbEnumEnum3::TEE_VALUE3);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
