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

#include "Implementation/TbSimpleSimpleArrayInterface.h"
#include "TbSimpleGameInstanceFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS 


BEGIN_DEFINE_SPEC(UTbSimpleSimpleArrayInterfaceImplementationSpec, "TbSimple.SimpleArrayInterface.Implementation",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

	TUniquePtr<FTbSimpleGameInstanceFixture> GameInstanceFixture;
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> testImplementation;

END_DEFINE_SPEC(UTbSimpleSimpleArrayInterfaceImplementationSpec);

void UTbSimpleSimpleArrayInterfaceImplementationSpec::Define()
{
	BeforeEach([this]()
	{
		GameInstanceFixture = MakeUnique<FTbSimpleGameInstanceFixture>();
		TestTrue("Check for valid GameInstanceFixture", GameInstanceFixture.IsValid());
		
		testImplementation = GameInstanceFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		TestTrue("Check for valid testImplementation", testImplementation.GetInterface() != nullptr);
	});

	AfterEach([this]()
	{
		GameInstanceFixture.Reset();
	});

	It("Property.PropBool", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropBool(testImplementation.GetObject(), TArray<bool>());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropBool(testImplementation.GetObject()), TArray<bool>());
	});

	It("Property.PropInt", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropInt(testImplementation.GetObject(), TArray<int32>());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropInt(testImplementation.GetObject()), TArray<int32>());
	});

	It("Property.PropInt32", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropInt32(testImplementation.GetObject(), TArray<int32>());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropInt32(testImplementation.GetObject()), TArray<int32>());
	});

	It("Property.PropInt64", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropInt64(testImplementation.GetObject(), TArray<int64>());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropInt64(testImplementation.GetObject()), TArray<int64>());
	});

	It("Property.PropFloat", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropFloat(testImplementation.GetObject(), TArray<float>());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropFloat(testImplementation.GetObject()), TArray<float>());
	});

	It("Property.PropFloat32", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropFloat32(testImplementation.GetObject(), TArray<float>());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropFloat32(testImplementation.GetObject()), TArray<float>());
	});

	It("Property.PropFloat64", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropFloat64(testImplementation.GetObject(), TArray<double>());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropFloat64(testImplementation.GetObject()), TArray<double>());
	});

	It("Property.PropString", [this]()
	{
		// Do implement test here
		testImplementation->Execute_SetPropString(testImplementation.GetObject(), TArray<FString>());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), testImplementation->Execute_GetPropString(testImplementation.GetObject()), TArray<FString>());
	});

	It("Operation.FuncBool", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncBool(testImplementation.GetObject(), TArray<bool>());
	});

	It("Operation.FuncInt", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncInt(testImplementation.GetObject(), TArray<int32>());
	});

	It("Operation.FuncInt32", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncInt32(testImplementation.GetObject(), TArray<int32>());
	});

	It("Operation.FuncInt64", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncInt64(testImplementation.GetObject(), TArray<int64>());
	});

	It("Operation.FuncFloat", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncFloat(testImplementation.GetObject(), TArray<float>());
	});

	It("Operation.FuncFloat32", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncFloat32(testImplementation.GetObject(), TArray<float>());
	});

	It("Operation.FuncFloat64", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncFloat64(testImplementation.GetObject(), TArray<double>());
	});

	It("Operation.FuncString", [this]()
	{
		// Do implement test here
		testImplementation->Execute_FuncString(testImplementation.GetObject(), TArray<FString>());
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
