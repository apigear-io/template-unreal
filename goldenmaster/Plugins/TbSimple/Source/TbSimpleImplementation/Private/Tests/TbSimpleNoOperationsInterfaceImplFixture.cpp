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
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterface>();
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
