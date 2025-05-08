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
#include "TbNamesNamEsImplFixture.h"
#include "Implementation/TbNamesNamEs.h"
#include "TbNamesTestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbNamesNamEsImplHelper::SetParentFixture(TWeakPtr<FTbNamesNamEsImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbNamesNamEsImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbNamesNamEsImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbNamesNamEsImplHelper::SwitchPropertyCb(bool bInSwitch)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
	if (TSharedPtr<FTbNamesNamEsImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSwitch(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsImplHelper::SomePropertyPropertyCb(int32 InSomeProperty)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
	if (TSharedPtr<FTbNamesNamEsImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomeProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsImplHelper::SomePoperty2PropertyCb(int32 InSomePoperty2)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
	if (TSharedPtr<FTbNamesNamEsImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomePoperty2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsImplHelper::EnumPropertyPropertyCb(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE;
	// use different test value
	TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SECONDVALUE;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
	if (TSharedPtr<FTbNamesNamEsImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetEnumProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsImplHelper::SomeSignalSignalCb(bool bInSomeParam)
{
	// known test value
	bool bSomeParamTestValue = true;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInSomeParam, bSomeParamTestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsImplHelper::SomeSignal2SignalCb(bool bInSomeParam)
{
	// known test value
	bool bSomeParamTestValue = true;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInSomeParam, bSomeParamTestValue);
	testDoneDelegate.Execute();
}

FTbNamesNamEsImplFixture::FTbNamesNamEsImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
	Helper = NewObject<UTbNamesNamEsImplHelper>();
}

FTbNamesNamEsImplFixture::~FTbNamesNamEsImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbNamesNamEsInterface> FTbNamesNamEsImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbNamesNamEsImplHelper> FTbNamesNamEsImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbNamesNamEsImplFixture::GetGameInstance()
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

void FTbNamesNamEsImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbNamesNamEsImplHelper::SetParentFixture(TWeakPtr<FTbNamesNamEsImplFixture> /*InFixture*/)
{
}

void UTbNamesNamEsImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbNamesNamEsImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbNamesNamEsImplHelper::SwitchPropertyCb(bool bSwitch)
{
	(void)bSwitch;
}

void UTbNamesNamEsImplHelper::SomePropertyPropertyCb(int32 SomeProperty)
{
	(void)SomeProperty;
}

void UTbNamesNamEsImplHelper::SomePoperty2PropertyCb(int32 SomePoperty2)
{
	(void)SomePoperty2;
}

void UTbNamesNamEsImplHelper::EnumPropertyPropertyCb(ETbNamesEnum_With_Under_scores EnumProperty)
{
	(void)EnumProperty;
}

void UTbNamesNamEsImplHelper::SomeSignalSignalCb(bool bSomeParam)
{
	(void)bSomeParam;
}

void UTbNamesNamEsImplHelper::SomeSignal2SignalCb(bool bSomeParam)
{
	(void)bSomeParam;
}
#endif // WITH_DEV_AUTOMATION_TESTS
