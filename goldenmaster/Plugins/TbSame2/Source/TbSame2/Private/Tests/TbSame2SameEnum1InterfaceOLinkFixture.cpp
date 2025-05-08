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
#include "TbSame2SameEnum1InterfaceOLinkFixture.h"
#include "TbSame2TestsCommon.h"
#include "OLinkCommon.h"
#include "Generated/OLink/TbSame2SameEnum1InterfaceOLinkClient.h"
#include "Generated/OLink/TbSame2SameEnum1InterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTbSame2SameEnum1InterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTbSame2SameEnum1InterfaceOLinkFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSame2SameEnum1InterfaceOLinkHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSame2SameEnum1InterfaceOLinkHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSame2SameEnum1InterfaceOLinkHelper::Prop1PropertyCb(ETbSame2Enum1 InProp1)
{
	ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_VALUE1;
	// use different test value
	TestValue = ETbSame2Enum1::TS2E1_VALUE2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame2SameEnum1InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame2SameEnum1InterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb(ETbSame2Enum1 InProp1)
{
	ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_VALUE1;
	// use different test value
	TestValue = ETbSame2Enum1::TS2E1_VALUE2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame2SameEnum1InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame2SameEnum1InterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb(ETbSame2Enum1 InProp1)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_VALUE1;
		// use different test value
		TestValue = ETbSame2Enum1::TS2E1_VALUE2;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTbSame2SameEnum1InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = ETbSame2Enum1::TS2E1_VALUE1; // default value
		if (TSharedPtr<FTbSame2SameEnum1InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp1(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_VALUE1; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTbSame2SameEnum1InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSame2SameEnum1InterfaceOLinkHelper::Sig1SignalCb(ETbSame2Enum1 InParam1)
{
	// known test value
	ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_VALUE2;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameEnum1InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

FTbSame2SameEnum1InterfaceOLinkFixture::FTbSame2SameEnum1InterfaceOLinkFixture()
{
	Helper = NewObject<UTbSame2SameEnum1InterfaceOLinkHelper>(GetTransientPackage());
	Helper->AddToRoot();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameEnum1InterfaceOLinkClient>();
}

FTbSame2SameEnum1InterfaceOLinkFixture::~FTbSame2SameEnum1InterfaceOLinkFixture()
{
	CleanUp();
	Helper->RemoveFromRoot();
}

TScriptInterface<ITbSame2SameEnum1InterfaceInterface> FTbSame2SameEnum1InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSame2SameEnum1InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSame2SameEnum1InterfaceOLinkAdapter* FTbSame2SameEnum1InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameEnum1InterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSame2SameEnum1InterfaceOLinkHelper> FTbSame2SameEnum1InterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame2SameEnum1InterfaceOLinkFixture::GetGameInstance()
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

void FTbSame2SameEnum1InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTbSame2SameEnum1InterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTbSame2SameEnum1InterfaceOLinkFixture> /*InFixture*/)
{
}

void UTbSame2SameEnum1InterfaceOLinkHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSame2SameEnum1InterfaceOLinkHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSame2SameEnum1InterfaceOLinkHelper::Prop1PropertyCb(ETbSame2Enum1 InProp1)
{
	(void)InProp1;
}

void UTbSame2SameEnum1InterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb(ETbSame2Enum1 InProp1)
{
	(void)InProp1;
}

void UTbSame2SameEnum1InterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb(ETbSame2Enum1 InProp1)
{
	(void)InProp1;
}

void UTbSame2SameEnum1InterfaceOLinkHelper::Sig1SignalCb(ETbSame2Enum1 Param1)
{
	(void)Param1;
}

void UTbSame2SameEnum1InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
