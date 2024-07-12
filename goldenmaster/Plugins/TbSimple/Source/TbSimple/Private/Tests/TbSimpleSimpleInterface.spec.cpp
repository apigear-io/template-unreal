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

#include "Implementation/TbSimpleSimpleInterface.h"
#include "TbSimpleGameInstanceFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS 


BEGIN_DEFINE_SPEC(UTbSimpleSimpleInterfaceImplementationSpec, "TbSimple.SimpleInterface.Implementation",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

	TUniquePtr<FTbSimpleGameInstanceFixture> GameInstanceFixture;
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> testImplementation;

END_DEFINE_SPEC(UTbSimpleSimpleInterfaceImplementationSpec);

void UTbSimpleSimpleInterfaceImplementationSpec::Define()
{
	BeforeEach([this]()
	{
		GameInstanceFixture = MakeUnique<FTbSimpleGameInstanceFixture>();
		TestTrue("Check for valid GameInstanceFixture", GameInstanceFixture.IsValid());
		
		testImplementation = GameInstanceFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleInterface>();
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

	It("Property.PropInt32", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropInt32(testImplementation.GetObject(), 0);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropInt32(testImplementation.GetObject()), 0);
	});

	It("Property.PropInt64", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropInt64(testImplementation.GetObject(), 0LL);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropInt64(testImplementation.GetObject()), 0LL);
	});

	It("Property.PropFloat", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropFloat(testImplementation.GetObject(), 0.0f);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropFloat(testImplementation.GetObject()), 0.0f);
	});

	It("Property.PropFloat32", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropFloat32(testImplementation.GetObject(), 0.0f);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropFloat32(testImplementation.GetObject()), 0.0f);
	});

	It("Property.PropFloat64", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropFloat64(testImplementation.GetObject(), 0.0);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropFloat64(testImplementation.GetObject()), 0.0);
	});

	It("Property.PropString", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropString(testImplementation.GetObject(), FString());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropString(testImplementation.GetObject()), FString());
	});

	It("Property.PropReadOnlyString", [this]()
	{
		// Do implement test here
		TestEqual(TEXT("Getter should return the default value"), testImplementation->Execute_GetPropReadOnlyString(testImplementation.GetObject()), FString());
	});

	It("Operation.FuncVoid", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncVoid(testImplementation.GetObject());
	});

	It("Operation.FuncBool", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncBool(testImplementation.GetObject(), false);
	});

	It("Operation.FuncInt", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncInt(testImplementation.GetObject(), 0);
	});

	It("Operation.FuncInt32", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncInt32(testImplementation.GetObject(), 0);
	});

	It("Operation.FuncInt64", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncInt64(testImplementation.GetObject(), 0LL);
	});

	It("Operation.FuncFloat", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncFloat(testImplementation.GetObject(), 0.0f);
	});

	It("Operation.FuncFloat32", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncFloat32(testImplementation.GetObject(), 0.0f);
	});

	It("Operation.FuncFloat64", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncFloat64(testImplementation.GetObject(), 0.0);
	});

	It("Operation.FuncString", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncString(testImplementation.GetObject(), FString());
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
