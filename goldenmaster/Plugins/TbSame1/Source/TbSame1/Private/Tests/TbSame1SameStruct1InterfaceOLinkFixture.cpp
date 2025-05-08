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
#include "TbSame1SameStruct1InterfaceOLinkFixture.h"
#include "TbSame1TestsCommon.h"
#include "OLinkCommon.h"
#include "Generated/OLink/TbSame1SameStruct1InterfaceOLinkClient.h"
#include "Generated/OLink/TbSame1SameStruct1InterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTbSame1SameStruct1InterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTbSame1SameStruct1InterfaceOLinkFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSame1SameStruct1InterfaceOLinkHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSame1SameStruct1InterfaceOLinkHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSame1SameStruct1InterfaceOLinkHelper::Prop1PropertyCb(const FTbSame1Struct1& InProp1)
{
	FTbSame1Struct1 TestValue = FTbSame1Struct1();
	// use different test value
	TestValue = createTestFTbSame1Struct1();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame1SameStruct1InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame1SameStruct1InterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTbSame1Struct1& InProp1)
{
	FTbSame1Struct1 TestValue = FTbSame1Struct1();
	// use different test value
	TestValue = createTestFTbSame1Struct1();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame1SameStruct1InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame1SameStruct1InterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTbSame1Struct1& InProp1)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTbSame1Struct1 TestValue = FTbSame1Struct1();
		// use different test value
		TestValue = createTestFTbSame1Struct1();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTbSame1SameStruct1InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTbSame1Struct1(); // default value
		if (TSharedPtr<FTbSame1SameStruct1InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp1(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTbSame1Struct1 TestValue = FTbSame1Struct1(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTbSame1SameStruct1InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSame1SameStruct1InterfaceOLinkHelper::Sig1SignalCb(const FTbSame1Struct1& InParam1)
{
	// known test value
	FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbSame1SameStruct1InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

FTbSame1SameStruct1InterfaceOLinkFixture::FTbSame1SameStruct1InterfaceOLinkFixture()
{
	Helper = NewObject<UTbSame1SameStruct1InterfaceOLinkHelper>(GetTransientPackage());
	Helper->AddToRoot();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameStruct1InterfaceOLinkClient>();
}

FTbSame1SameStruct1InterfaceOLinkFixture::~FTbSame1SameStruct1InterfaceOLinkFixture()
{
	CleanUp();
	Helper->RemoveFromRoot();
}

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> FTbSame1SameStruct1InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSame1SameStruct1InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSame1SameStruct1InterfaceOLinkAdapter* FTbSame1SameStruct1InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameStruct1InterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSame1SameStruct1InterfaceOLinkHelper> FTbSame1SameStruct1InterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame1SameStruct1InterfaceOLinkFixture::GetGameInstance()
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

void FTbSame1SameStruct1InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTbSame1SameStruct1InterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTbSame1SameStruct1InterfaceOLinkFixture> /*InFixture*/)
{
}

void UTbSame1SameStruct1InterfaceOLinkHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSame1SameStruct1InterfaceOLinkHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSame1SameStruct1InterfaceOLinkHelper::Prop1PropertyCb(const FTbSame1Struct1& InProp1)
{
	(void)InProp1;
}

void UTbSame1SameStruct1InterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTbSame1Struct1& InProp1)
{
	(void)InProp1;
}

void UTbSame1SameStruct1InterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTbSame1Struct1& InProp1)
{
	(void)InProp1;
}

void UTbSame1SameStruct1InterfaceOLinkHelper::Sig1SignalCb(const FTbSame1Struct1& Param1)
{
	(void)Param1;
}

void UTbSame1SameStruct1InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
