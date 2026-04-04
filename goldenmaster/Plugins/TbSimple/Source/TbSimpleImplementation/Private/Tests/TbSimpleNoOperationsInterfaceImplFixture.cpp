// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSimpleNoOperationsInterfaceImplFixture.h"
#include "TbSimple/Implementation/TbSimpleNoOperationsInterface.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleNoOperationsInterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSimpleNoOperationsInterfaceImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSimpleNoOperationsInterfaceImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleNoOperationsInterfaceImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSimpleNoOperationsInterfaceImplHelper::PropBoolPropertyCb(bool bInPropBool)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
	if (TSharedPtr<FTbSimpleNoOperationsInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropBool(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceImplHelper::PropIntPropertyCb(int32 InPropInt)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTbSimpleNoOperationsInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropInt(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceImplHelper::SigVoidSignalCb()
{
	// known test value
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceImplHelper::SigBoolSignalCb(bool bInParamBool)
{
	// known test value
	bool bParamBoolTestValue = true;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
	testDoneDelegate.Execute();
}

FTbSimpleNoOperationsInterfaceImplFixture::FTbSimpleNoOperationsInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterfaceImplementation>();
	Helper = NewObject<UTbSimpleNoOperationsInterfaceImplHelper>();
}

FTbSimpleNoOperationsInterfaceImplFixture::~FTbSimpleNoOperationsInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> FTbSimpleNoOperationsInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbSimpleNoOperationsInterfaceImplHelper> FTbSimpleNoOperationsInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleNoOperationsInterfaceImplFixture::GetGameInstance()
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

void FTbSimpleNoOperationsInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSimpleNoOperationsInterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSimpleNoOperationsInterfaceImplFixture> /*InFixture*/)
{
}

void UTbSimpleNoOperationsInterfaceImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSimpleNoOperationsInterfaceImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSimpleNoOperationsInterfaceImplHelper::PropBoolPropertyCb(bool bPropBool)
{
	(void)bPropBool;
}

void UTbSimpleNoOperationsInterfaceImplHelper::PropIntPropertyCb(int32 PropInt)
{
	(void)PropInt;
}

void UTbSimpleNoOperationsInterfaceImplHelper::SigVoidSignalCb()
{
}

void UTbSimpleNoOperationsInterfaceImplHelper::SigBoolSignalCb(bool bParamBool)
{
	(void)bParamBool;
}
#endif // WITH_DEV_AUTOMATION_TESTS
