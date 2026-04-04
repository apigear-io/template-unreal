// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbRefIfacesSimpleLocalIfImplFixture.h"
#include "TbRefIfaces/Implementation/TbRefIfacesSimpleLocalIf.h"
#include "TbRefIfaces/Tests/TbRefIfacesTestsCommon.h"
#include "TbIfaceimport/Tests/TbIfaceimportTestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbRefIfacesSimpleLocalIfImplHelper::SetParentFixture(TWeakPtr<FTbRefIfacesSimpleLocalIfImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbRefIfacesSimpleLocalIfImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbRefIfacesSimpleLocalIfImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbRefIfacesSimpleLocalIfImplHelper::IntPropertyPropertyCb(int32 InIntProperty)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InIntProperty, TestValue);
	if (TSharedPtr<FTbRefIfacesSimpleLocalIfImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetIntProperty(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbRefIfacesSimpleLocalIfImplHelper::IntSignalSignalCb(int32 InParam)
{
	// known test value
	int32 ParamTestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
	testDoneDelegate.Execute();
}

FTbRefIfacesSimpleLocalIfImplFixture::FTbRefIfacesSimpleLocalIfImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbRefIfacesSimpleLocalIfImplementation>();
	Helper = NewObject<UTbRefIfacesSimpleLocalIfImplHelper>();
}

FTbRefIfacesSimpleLocalIfImplFixture::~FTbRefIfacesSimpleLocalIfImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> FTbRefIfacesSimpleLocalIfImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbRefIfacesSimpleLocalIfImplHelper> FTbRefIfacesSimpleLocalIfImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbRefIfacesSimpleLocalIfImplFixture::GetGameInstance()
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

void FTbRefIfacesSimpleLocalIfImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbRefIfacesSimpleLocalIfImplHelper::SetParentFixture(TWeakPtr<FTbRefIfacesSimpleLocalIfImplFixture> /*InFixture*/)
{
}

void UTbRefIfacesSimpleLocalIfImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbRefIfacesSimpleLocalIfImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbRefIfacesSimpleLocalIfImplHelper::IntPropertyPropertyCb(int32 IntProperty)
{
	(void)IntProperty;
}

void UTbRefIfacesSimpleLocalIfImplHelper::IntSignalSignalCb(int32 Param)
{
	(void)Param;
}
#endif // WITH_DEV_AUTOMATION_TESTS
