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
#include "TbSimpleNoOperationsInterfaceOLinkFixture.h"
#include "TbSimpleTestsCommon.h"
#include "OLinkCommon.h"
#include "Generated/OLink/TbSimpleNoOperationsInterfaceOLinkClient.h"
#include "Generated/OLink/TbSimpleNoOperationsInterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTbSimpleNoOperationsInterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTbSimpleNoOperationsInterfaceOLinkFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::PropBoolPropertyCb(bool bInPropBool)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
	if (TSharedPtr<FTbSimpleNoOperationsInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb(bool bInPropBool)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
	if (TSharedPtr<FTbSimpleNoOperationsInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb(bool bInPropBool)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		bool TestValue = false;
		// use different test value
		TestValue = true;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
		if (TSharedPtr<FTbSimpleNoOperationsInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = false; // default value
		if (TSharedPtr<FTbSimpleNoOperationsInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropBool(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		bool TestValue = false; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
		if (TSharedPtr<FTbSimpleNoOperationsInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::PropIntPropertyCb(int32 InPropInt)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTbSimpleNoOperationsInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb(int32 InPropInt)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTbSimpleNoOperationsInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb(int32 InPropInt)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		int32 TestValue = 0;
		// use different test value
		TestValue = 1;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		if (TSharedPtr<FTbSimpleNoOperationsInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0; // default value
		if (TSharedPtr<FTbSimpleNoOperationsInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropInt(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		int32 TestValue = 0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		if (TSharedPtr<FTbSimpleNoOperationsInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::SigVoidSignalCb()
{
	// known test value
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::SigBoolSignalCb(bool bInParamBool)
{
	// known test value
	bool bParamBoolTestValue = true;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

FTbSimpleNoOperationsInterfaceOLinkFixture::FTbSimpleNoOperationsInterfaceOLinkFixture()
{
	Helper = NewObject<UTbSimpleNoOperationsInterfaceOLinkHelper>(GetTransientPackage());
	Helper->AddToRoot();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterfaceOLinkClient>();
}

FTbSimpleNoOperationsInterfaceOLinkFixture::~FTbSimpleNoOperationsInterfaceOLinkFixture()
{
	CleanUp();
	Helper->RemoveFromRoot();
}

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> FTbSimpleNoOperationsInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSimpleNoOperationsInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSimpleNoOperationsInterfaceOLinkAdapter* FTbSimpleNoOperationsInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSimpleNoOperationsInterfaceOLinkHelper> FTbSimpleNoOperationsInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleNoOperationsInterfaceOLinkFixture::GetGameInstance()
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

void FTbSimpleNoOperationsInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTbSimpleNoOperationsInterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTbSimpleNoOperationsInterfaceOLinkFixture> /*InFixture*/)
{
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::PropBoolPropertyCb(bool bInPropBool)
{
	(void)bInPropBool;
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb(bool bInPropBool)
{
	(void)bInPropBool;
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb(bool bInPropBool)
{
	(void)bInPropBool;
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::PropIntPropertyCb(int32 InPropInt)
{
	(void)InPropInt;
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb(int32 InPropInt)
{
	(void)InPropInt;
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb(int32 InPropInt)
{
	(void)InPropInt;
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::SigVoidSignalCb()
{
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::SigBoolSignalCb(bool bParamBool)
{
	(void)bParamBool;
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
