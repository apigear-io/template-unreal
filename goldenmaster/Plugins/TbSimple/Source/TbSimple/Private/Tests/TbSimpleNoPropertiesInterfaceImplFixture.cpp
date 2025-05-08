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
#include "TbSimpleNoPropertiesInterfaceImplFixture.h"
#include "Implementation/TbSimpleNoPropertiesInterface.h"
#include "TbSimpleTestsCommon.h"
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
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterface>();
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
