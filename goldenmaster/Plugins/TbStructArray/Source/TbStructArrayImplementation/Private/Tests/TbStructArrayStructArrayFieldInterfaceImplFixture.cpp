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
#include "TbStructArrayStructArrayFieldInterfaceImplFixture.h"
#include "TbStructArray/Implementation/TbStructArrayStructArrayFieldInterface.h"
#include "TbStructArray/Tests/TbStructArrayTestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbStructArrayStructArrayFieldInterfaceImplHelper::SetParentFixture(TWeakPtr<FTbStructArrayStructArrayFieldInterfaceImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbStructArrayStructArrayFieldInterfaceImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbStructArrayStructArrayFieldInterfaceImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbStructArrayStructArrayFieldInterfaceImplHelper::PropStructArrayPropertyCb(const FTbStructArrayStructWithArrayOfStructs& InPropStructArray)
{
	FTbStructArrayStructWithArrayOfStructs TestValue = FTbStructArrayStructWithArrayOfStructs();
	// use different test value
	TestValue = createTestFTbStructArrayStructWithArrayOfStructs();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropStructArray, TestValue);
	if (TSharedPtr<FTbStructArrayStructArrayFieldInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropStructArray(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbStructArrayStructArrayFieldInterfaceImplHelper::PropEnumArrayPropertyCb(const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray)
{
	FTbStructArrayStructWithArrayOfEnums TestValue = FTbStructArrayStructWithArrayOfEnums();
	// use different test value
	TestValue = createTestFTbStructArrayStructWithArrayOfEnums();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnumArray, TestValue);
	if (TSharedPtr<FTbStructArrayStructArrayFieldInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropEnumArray(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbStructArrayStructArrayFieldInterfaceImplHelper::PropIntArrayPropertyCb(const FTbStructArrayStructWithArrayOfInts& InPropIntArray)
{
	FTbStructArrayStructWithArrayOfInts TestValue = FTbStructArrayStructWithArrayOfInts();
	// use different test value
	TestValue = createTestFTbStructArrayStructWithArrayOfInts();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropIntArray, TestValue);
	if (TSharedPtr<FTbStructArrayStructArrayFieldInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropIntArray(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbStructArrayStructArrayFieldInterfaceImplHelper::PropMixedPropertyCb(const FTbStructArrayMixedStruct& InPropMixed)
{
	FTbStructArrayMixedStruct TestValue = FTbStructArrayMixedStruct();
	// use different test value
	TestValue = createTestFTbStructArrayMixedStruct();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropMixed, TestValue);
	if (TSharedPtr<FTbStructArrayStructArrayFieldInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropMixed(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbStructArrayStructArrayFieldInterfaceImplHelper::SigMixedSignalCb(const FTbStructArrayMixedStruct& InParamMixed)
{
	// known test value
	FTbStructArrayMixedStruct ParamMixedTestValue = createTestFTbStructArrayMixedStruct();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamMixed, ParamMixedTestValue);
	testDoneDelegate.Execute();
}

void UTbStructArrayStructArrayFieldInterfaceImplHelper::SigStructArraySignalCb(const FTbStructArrayStructWithArrayOfStructs& InParamPoints)
{
	// known test value
	FTbStructArrayStructWithArrayOfStructs ParamPointsTestValue = createTestFTbStructArrayStructWithArrayOfStructs();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamPoints, ParamPointsTestValue);
	testDoneDelegate.Execute();
}

FTbStructArrayStructArrayFieldInterfaceImplFixture::FTbStructArrayStructArrayFieldInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbStructArrayStructArrayFieldInterfaceImplementation>();
	Helper = NewObject<UTbStructArrayStructArrayFieldInterfaceImplHelper>();
}

FTbStructArrayStructArrayFieldInterfaceImplFixture::~FTbStructArrayStructArrayFieldInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> FTbStructArrayStructArrayFieldInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbStructArrayStructArrayFieldInterfaceImplHelper> FTbStructArrayStructArrayFieldInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbStructArrayStructArrayFieldInterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>(GetTransientPackage());
		GameInstance->Init();
		// needed to prevent garbage collection and we can't use UPROPERTY on raw c++ objects
		GameInstance->AddToRoot();
	}

	return GameInstance.Get();
}

void FTbStructArrayStructArrayFieldInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbStructArrayStructArrayFieldInterfaceImplHelper::SetParentFixture(TWeakPtr<FTbStructArrayStructArrayFieldInterfaceImplFixture> /*InFixture*/)
{
}

void UTbStructArrayStructArrayFieldInterfaceImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbStructArrayStructArrayFieldInterfaceImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbStructArrayStructArrayFieldInterfaceImplHelper::PropStructArrayPropertyCb(const FTbStructArrayStructWithArrayOfStructs& PropStructArray)
{
	(void)PropStructArray;
}

void UTbStructArrayStructArrayFieldInterfaceImplHelper::PropEnumArrayPropertyCb(const FTbStructArrayStructWithArrayOfEnums& PropEnumArray)
{
	(void)PropEnumArray;
}

void UTbStructArrayStructArrayFieldInterfaceImplHelper::PropIntArrayPropertyCb(const FTbStructArrayStructWithArrayOfInts& PropIntArray)
{
	(void)PropIntArray;
}

void UTbStructArrayStructArrayFieldInterfaceImplHelper::PropMixedPropertyCb(const FTbStructArrayMixedStruct& PropMixed)
{
	(void)PropMixed;
}

void UTbStructArrayStructArrayFieldInterfaceImplHelper::SigMixedSignalCb(const FTbStructArrayMixedStruct& ParamMixed)
{
	(void)ParamMixed;
}

void UTbStructArrayStructArrayFieldInterfaceImplHelper::SigStructArraySignalCb(const FTbStructArrayStructWithArrayOfStructs& ParamPoints)
{
	(void)ParamPoints;
}
#endif // WITH_DEV_AUTOMATION_TESTS
