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

#include "Implementation/TbSame2SameStruct2Interface.h"
#include "TbSame2GameInstanceFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS 


BEGIN_DEFINE_SPEC(UTbSame2SameStruct2InterfaceImplementationSpec, "TbSame2.SameStruct2Interface.Implementation",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

	TUniquePtr<FTbSame2GameInstanceFixture> GameInstanceFixture;
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> testImplementation;

END_DEFINE_SPEC(UTbSame2SameStruct2InterfaceImplementationSpec);

void UTbSame2SameStruct2InterfaceImplementationSpec::Define()
{
	BeforeEach([this]()
	{
		GameInstanceFixture = MakeUnique<FTbSame2GameInstanceFixture>();
		TestTrue("Check for valid GameInstanceFixture", GameInstanceFixture.IsValid());
		
		testImplementation = GameInstanceFixture->GetGameInstance()->GetSubsystem<UTbSame2SameStruct2Interface>();
		TestTrue("Check for valid testImplementation", testImplementation.GetInterface() != nullptr);
	});

	AfterEach([this]()
	{
		GameInstanceFixture.Reset();
	});

	It("Property.Prop1", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetProp1(testImplementation.GetObject(), FTbSame2Struct2());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetProp1(testImplementation.GetObject()), FTbSame2Struct2());
	});

	It("Property.Prop2", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetProp2(testImplementation.GetObject(), FTbSame2Struct2());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetProp2(testImplementation.GetObject()), FTbSame2Struct2());
	});

	It("Operation.Func1", [this]()
	{
		// Do implement test here
		testImplementation->Execute_Func1(testImplementation.GetObject(), FTbSame2Struct1());
	});

	It("Operation.Func2", [this]()
	{
		// Do implement test here
		testImplementation->Execute_Func2(testImplementation.GetObject(), FTbSame2Struct1(), FTbSame2Struct2());
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
