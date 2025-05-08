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
#include "TbSame1SameEnum2InterfaceOLinkFixture.h"
#include "TbSame1TestsCommon.h"
#include "OLinkCommon.h"
#include "Generated/OLink/TbSame1SameEnum2InterfaceOLinkClient.h"
#include "Generated/OLink/TbSame1SameEnum2InterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTbSame1SameEnum2InterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTbSame1SameEnum2InterfaceOLinkFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSame1SameEnum2InterfaceOLinkHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSame1SameEnum2InterfaceOLinkHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop1PropertyCb(ETbSame1Enum1 InProp1)
{
	ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_VALUE1;
	// use different test value
	TestValue = ETbSame1Enum1::TS1E1_VALUE2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame1SameEnum2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb(ETbSame1Enum1 InProp1)
{
	ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_VALUE1;
	// use different test value
	TestValue = ETbSame1Enum1::TS1E1_VALUE2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame1SameEnum2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb(ETbSame1Enum1 InProp1)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_VALUE1;
		// use different test value
		TestValue = ETbSame1Enum1::TS1E1_VALUE2;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTbSame1SameEnum2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = ETbSame1Enum1::TS1E1_VALUE1; // default value
		if (TSharedPtr<FTbSame1SameEnum2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp1(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_VALUE1; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTbSame1SameEnum2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop2PropertyCb(ETbSame1Enum2 InProp2)
{
	ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_VALUE1;
	// use different test value
	TestValue = ETbSame1Enum2::TS1E2_VALUE2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTbSame1SameEnum2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop2PropertyChangeLocalCheckRemoteCb(ETbSame1Enum2 InProp2)
{
	ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_VALUE1;
	// use different test value
	TestValue = ETbSame1Enum2::TS1E2_VALUE2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTbSame1SameEnum2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop2PropertyChangeLocalChangeRemoteCb(ETbSame1Enum2 InProp2)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_VALUE1;
		// use different test value
		TestValue = ETbSame1Enum2::TS1E2_VALUE2;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
		if (TSharedPtr<FTbSame1SameEnum2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = ETbSame1Enum2::TS1E2_VALUE1; // default value
		if (TSharedPtr<FTbSame1SameEnum2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp2(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_VALUE1; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
		if (TSharedPtr<FTbSame1SameEnum2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Sig1SignalCb(ETbSame1Enum1 InParam1)
{
	// known test value
	ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_VALUE2;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Sig2SignalCb(ETbSame1Enum1 InParam1, ETbSame1Enum2 InParam2)
{
	// known test value
	ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_VALUE2;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	ETbSame1Enum2 Param2TestValue = ETbSame1Enum2::TS1E2_VALUE2;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

FTbSame1SameEnum2InterfaceOLinkFixture::FTbSame1SameEnum2InterfaceOLinkFixture()
{
	Helper = NewObject<UTbSame1SameEnum2InterfaceOLinkHelper>(GetTransientPackage());
	Helper->AddToRoot();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceOLinkClient>();
}

FTbSame1SameEnum2InterfaceOLinkFixture::~FTbSame1SameEnum2InterfaceOLinkFixture()
{
	CleanUp();
	Helper->RemoveFromRoot();
}

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> FTbSame1SameEnum2InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSame1SameEnum2InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSame1SameEnum2InterfaceOLinkAdapter* FTbSame1SameEnum2InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSame1SameEnum2InterfaceOLinkHelper> FTbSame1SameEnum2InterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame1SameEnum2InterfaceOLinkFixture::GetGameInstance()
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

void FTbSame1SameEnum2InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTbSame1SameEnum2InterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTbSame1SameEnum2InterfaceOLinkFixture> /*InFixture*/)
{
}

void UTbSame1SameEnum2InterfaceOLinkHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSame1SameEnum2InterfaceOLinkHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop1PropertyCb(ETbSame1Enum1 InProp1)
{
	(void)InProp1;
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb(ETbSame1Enum1 InProp1)
{
	(void)InProp1;
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb(ETbSame1Enum1 InProp1)
{
	(void)InProp1;
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop2PropertyCb(ETbSame1Enum2 InProp2)
{
	(void)InProp2;
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop2PropertyChangeLocalCheckRemoteCb(ETbSame1Enum2 InProp2)
{
	(void)InProp2;
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop2PropertyChangeLocalChangeRemoteCb(ETbSame1Enum2 InProp2)
{
	(void)InProp2;
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Sig1SignalCb(ETbSame1Enum1 Param1)
{
	(void)Param1;
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Sig2SignalCb(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTbSame1SameEnum2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
