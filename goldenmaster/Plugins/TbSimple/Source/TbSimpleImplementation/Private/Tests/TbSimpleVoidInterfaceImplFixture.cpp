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
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleVoidInterface>();
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
