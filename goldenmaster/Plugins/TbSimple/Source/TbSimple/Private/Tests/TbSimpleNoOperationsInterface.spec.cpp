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
#include "TbSimpleGameInstanceFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS 


BEGIN_DEFINE_SPEC(UTbSimpleNoOperationsInterfaceImplementationSpec, "TbSimple.NoOperationsInterface.Implementation",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

	TUniquePtr<FTbSimpleGameInstanceFixture> GameInstanceFixture;
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> testImplementation;

END_DEFINE_SPEC(UTbSimpleNoOperationsInterfaceImplementationSpec);

void UTbSimpleNoOperationsInterfaceImplementationSpec::Define()
{
	BeforeEach([this]()
	{
		GameInstanceFixture = MakeUnique<FTbSimpleGameInstanceFixture>();
		TestTrue("Check for valid GameInstanceFixture", GameInstanceFixture.IsValid());
		
		testImplementation = GameInstanceFixture->GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterface>();
		TestTrue("Check for valid testImplementation", testImplementation.GetInterface() != nullptr);
	});

	AfterEach([this]()
	{
		GameInstanceFixture.Reset();
	});

	It("Property.PropBool", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropBool(testImplementation.GetObject(), false);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropBool(testImplementation.GetObject()), false);
	});

	It("Property.PropInt", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropInt(testImplementation.GetObject(), 0);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropInt(testImplementation.GetObject()), 0);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
