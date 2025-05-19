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
#include "TbSimpleEmptyInterfaceImplFixture.h"
#include "TbSimple/Implementation/TbSimpleEmptyInterface.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleEmptyInterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSimpleEmptyInterfaceImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSimpleEmptyInterfaceImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleEmptyInterfaceImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

FTbSimpleEmptyInterfaceImplFixture::FTbSimpleEmptyInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleEmptyInterfaceImplementation>();
	Helper = NewObject<UTbSimpleEmptyInterfaceImplHelper>();
}

FTbSimpleEmptyInterfaceImplFixture::~FTbSimpleEmptyInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleEmptyInterfaceInterface> FTbSimpleEmptyInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbSimpleEmptyInterfaceImplHelper> FTbSimpleEmptyInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleEmptyInterfaceImplFixture::GetGameInstance()
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

void FTbSimpleEmptyInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSimpleEmptyInterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSimpleEmptyInterfaceImplFixture> /*InFixture*/)
{
}

void UTbSimpleEmptyInterfaceImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSimpleEmptyInterfaceImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}
#endif // WITH_DEV_AUTOMATION_TESTS
