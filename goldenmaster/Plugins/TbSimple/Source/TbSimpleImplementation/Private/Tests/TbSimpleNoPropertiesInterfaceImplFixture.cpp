// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSimpleNoPropertiesInterfaceImplFixture.h"
#include "TbSimple/Implementation/TbSimpleNoPropertiesInterface.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleNoPropertiesInterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSimpleNoPropertiesInterfaceImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSimpleNoPropertiesInterfaceImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleNoPropertiesInterfaceImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSimpleNoPropertiesInterfaceImplHelper::SigVoidSignalCb()
{
	// known test value
	testDoneDelegate.Execute();
}

void UTbSimpleNoPropertiesInterfaceImplHelper::SigBoolSignalCb(bool bInParamBool)
{
	// known test value
	bool bParamBoolTestValue = true;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
	testDoneDelegate.Execute();
}

FTbSimpleNoPropertiesInterfaceImplFixture::FTbSimpleNoPropertiesInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterfaceImplementation>();
	Helper = NewObject<UTbSimpleNoPropertiesInterfaceImplHelper>();
}

FTbSimpleNoPropertiesInterfaceImplFixture::~FTbSimpleNoPropertiesInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> FTbSimpleNoPropertiesInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbSimpleNoPropertiesInterfaceImplHelper> FTbSimpleNoPropertiesInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleNoPropertiesInterfaceImplFixture::GetGameInstance()
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

void FTbSimpleNoPropertiesInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSimpleNoPropertiesInterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSimpleNoPropertiesInterfaceImplFixture> /*InFixture*/)
{
}

void UTbSimpleNoPropertiesInterfaceImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSimpleNoPropertiesInterfaceImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSimpleNoPropertiesInterfaceImplHelper::SigVoidSignalCb()
{
}

void UTbSimpleNoPropertiesInterfaceImplHelper::SigBoolSignalCb(bool bParamBool)
{
	(void)bParamBool;
}
#endif // WITH_DEV_AUTOMATION_TESTS
