// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSimpleVoidInterfaceImplFixture.h"
#include "TbSimple/Implementation/TbSimpleVoidInterface.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleVoidInterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSimpleVoidInterfaceImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSimpleVoidInterfaceImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleVoidInterfaceImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSimpleVoidInterfaceImplHelper::SigVoidSignalCb()
{
	// known test value
	testDoneDelegate.Execute();
}

FTbSimpleVoidInterfaceImplFixture::FTbSimpleVoidInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleVoidInterfaceImplementation>();
	Helper = NewObject<UTbSimpleVoidInterfaceImplHelper>();
}

FTbSimpleVoidInterfaceImplFixture::~FTbSimpleVoidInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleVoidInterfaceInterface> FTbSimpleVoidInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbSimpleVoidInterfaceImplHelper> FTbSimpleVoidInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleVoidInterfaceImplFixture::GetGameInstance()
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

void FTbSimpleVoidInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSimpleVoidInterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSimpleVoidInterfaceImplFixture> /*InFixture*/)
{
}

void UTbSimpleVoidInterfaceImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSimpleVoidInterfaceImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSimpleVoidInterfaceImplHelper::SigVoidSignalCb()
{
}
#endif // WITH_DEV_AUTOMATION_TESTS
