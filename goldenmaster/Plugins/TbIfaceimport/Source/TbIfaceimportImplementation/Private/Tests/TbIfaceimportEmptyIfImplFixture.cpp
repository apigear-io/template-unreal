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
#include "TbIfaceimportEmptyIfImplFixture.h"
#include "TbIfaceimport/Implementation/TbIfaceimportEmptyIf.h"
#include "TbIfaceimport/Tests/TbIfaceimportTestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbIfaceimportEmptyIfImplHelper::SetParentFixture(TWeakPtr<FTbIfaceimportEmptyIfImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbIfaceimportEmptyIfImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbIfaceimportEmptyIfImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

FTbIfaceimportEmptyIfImplFixture::FTbIfaceimportEmptyIfImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbIfaceimportEmptyIfImplementation>();
	Helper = NewObject<UTbIfaceimportEmptyIfImplHelper>();
}

FTbIfaceimportEmptyIfImplFixture::~FTbIfaceimportEmptyIfImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbIfaceimportEmptyIfInterface> FTbIfaceimportEmptyIfImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbIfaceimportEmptyIfImplHelper> FTbIfaceimportEmptyIfImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbIfaceimportEmptyIfImplFixture::GetGameInstance()
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

void FTbIfaceimportEmptyIfImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbIfaceimportEmptyIfImplHelper::SetParentFixture(TWeakPtr<FTbIfaceimportEmptyIfImplFixture> /*InFixture*/)
{
}

void UTbIfaceimportEmptyIfImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbIfaceimportEmptyIfImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}
#endif // WITH_DEV_AUTOMATION_TESTS
