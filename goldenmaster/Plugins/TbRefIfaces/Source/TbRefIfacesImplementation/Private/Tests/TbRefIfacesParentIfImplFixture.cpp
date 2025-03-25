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
#include "TbRefIfacesParentIfImplFixture.h"
#include "TbRefIfaces/Implementation/TbRefIfacesParentIf.h"
#include "TbRefIfaces/Tests/TbRefIfacesTestsCommon.h"
#include "TbIfaceimport/Tests/TbIfaceimportTestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbRefIfacesParentIfImplHelper::SetParentFixture(TWeakPtr<FTbRefIfacesParentIfImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbRefIfacesParentIfImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbRefIfacesParentIfImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbRefIfacesParentIfImplHelper::LocalIfPropertyCb(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf)
{
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> TestValue = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
	// use different test value
	TestValue = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InLocalIf, TestValue);
	if (TSharedPtr<FTbRefIfacesParentIfImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetLocalIf(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbRefIfacesParentIfImplHelper::ImportedIfPropertyCb(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf)
{
	TScriptInterface<ITbIfaceimportEmptyIfInterface> TestValue = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
	// use different test value
	TestValue = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InImportedIf, TestValue);
	if (TSharedPtr<FTbRefIfacesParentIfImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetImportedIf(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbRefIfacesParentIfImplHelper::LocalIfSignalSignalCb(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InParam)
{
	// known test value
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> ParamTestValue = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
	testDoneDelegate.Execute();
}

void UTbRefIfacesParentIfImplHelper::ImportedIfSignalSignalCb(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InParam)
{
	// known test value
	TScriptInterface<ITbIfaceimportEmptyIfInterface> ParamTestValue = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
	testDoneDelegate.Execute();
}

FTbRefIfacesParentIfImplFixture::FTbRefIfacesParentIfImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbRefIfacesParentIfImplementation>();
	Helper = NewObject<UTbRefIfacesParentIfImplHelper>();
}

FTbRefIfacesParentIfImplFixture::~FTbRefIfacesParentIfImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbRefIfacesParentIfInterface> FTbRefIfacesParentIfImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbRefIfacesParentIfImplHelper> FTbRefIfacesParentIfImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbRefIfacesParentIfImplFixture::GetGameInstance()
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

void FTbRefIfacesParentIfImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbRefIfacesParentIfImplHelper::SetParentFixture(TWeakPtr<FTbRefIfacesParentIfImplFixture> /*InFixture*/)
{
}

void UTbRefIfacesParentIfImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbRefIfacesParentIfImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbRefIfacesParentIfImplHelper::LocalIfPropertyCb(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& LocalIf)
{
	(void)LocalIf;
}

void UTbRefIfacesParentIfImplHelper::ImportedIfPropertyCb(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& ImportedIf)
{
	(void)ImportedIf;
}

void UTbRefIfacesParentIfImplHelper::LocalIfSignalSignalCb(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
{
	(void)Param;
}

void UTbRefIfacesParentIfImplHelper::ImportedIfSignalSignalCb(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
{
	(void)Param;
}
#endif // WITH_DEV_AUTOMATION_TESTS
