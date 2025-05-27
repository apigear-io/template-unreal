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
#include "TbNamesNamEsOLinkFixture.h"
#include "TbNamesTestsCommon.h"
#include "OLinkCommon.h"
#include "Generated/OLink/TbNamesNamEsOLinkClient.h"
#include "Generated/OLink/TbNamesNamEsOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTbNamesNamEsOLinkHelper::SetParentFixture(TWeakPtr<FTbNamesNamEsOLinkFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbNamesNamEsOLinkHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbNamesNamEsOLinkHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbNamesNamEsOLinkHelper::SwitchPropertyCb(bool bInSwitch)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
	if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSwitch(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsOLinkHelper::SwitchPropertyChangeLocalCheckRemoteCb(bool bInSwitch)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
	if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSwitch(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsOLinkHelper::SwitchPropertyChangeLocalChangeRemoteCb(bool bInSwitch)
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
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
		if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSwitch(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = false; // default value
		if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetSwitch(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		bool TestValue = false; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
		if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSwitch(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbNamesNamEsOLinkHelper::SomePropertyPropertyCb(int32 InSomeProperty)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
	if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomeProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsOLinkHelper::SomePropertyPropertyChangeLocalCheckRemoteCb(int32 InSomeProperty)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
	if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomeProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsOLinkHelper::SomePropertyPropertyChangeLocalChangeRemoteCb(int32 InSomeProperty)
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
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
		if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomeProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0; // default value
		if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetSomeProperty(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		int32 TestValue = 0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
		if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomeProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbNamesNamEsOLinkHelper::SomePoperty2PropertyCb(int32 InSomePoperty2)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
	if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomePoperty2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsOLinkHelper::SomePoperty2PropertyChangeLocalCheckRemoteCb(int32 InSomePoperty2)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
	if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomePoperty2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsOLinkHelper::SomePoperty2PropertyChangeLocalChangeRemoteCb(int32 InSomePoperty2)
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
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
		if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomePoperty2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0; // default value
		if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetSomePoperty2(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		int32 TestValue = 0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
		if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomePoperty2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbNamesNamEsOLinkHelper::EnumPropertyPropertyCb(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue;
	// use different test value
	TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SecondValue;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
	if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetEnumProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsOLinkHelper::EnumPropertyPropertyChangeLocalCheckRemoteCb(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue;
	// use different test value
	TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SecondValue;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
	if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetEnumProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsOLinkHelper::EnumPropertyPropertyChangeLocalChangeRemoteCb(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue;
		// use different test value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SecondValue;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
		if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetEnumProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue; // default value
		if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetEnumProperty(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
		if (TSharedPtr<FTbNamesNamEsOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetEnumProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbNamesNamEsOLinkHelper::SomeSignalSignalCb(bool bInSomeParam)
{
	// known test value
	bool bSomeParamTestValue = true;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInSomeParam, bSomeParamTestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsOLinkHelper::SomeSignal2SignalCb(bool bInSomeParam)
{
	// known test value
	bool bSomeParamTestValue = true;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInSomeParam, bSomeParamTestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

FTbNamesNamEsOLinkFixture::FTbNamesNamEsOLinkFixture()
{
	Helper = NewObject<UTbNamesNamEsOLinkHelper>(GetTransientPackage());
	Helper->AddToRoot();
	testImplementation = GetGameInstance()->GetSubsystem<UTbNamesNamEsOLinkClient>();
}

FTbNamesNamEsOLinkFixture::~FTbNamesNamEsOLinkFixture()
{
	CleanUp();
	Helper->RemoveFromRoot();
}

TScriptInterface<ITbNamesNamEsInterface> FTbNamesNamEsOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbNamesNamEsOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbNamesNamEsOLinkAdapter* FTbNamesNamEsOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbNamesNamEsOLinkAdapter>();
}

TSoftObjectPtr<UTbNamesNamEsOLinkHelper> FTbNamesNamEsOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbNamesNamEsOLinkFixture::GetGameInstance()
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

void FTbNamesNamEsOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTbNamesNamEsOLinkHelper::SetParentFixture(TWeakPtr<FTbNamesNamEsOLinkFixture> /*InFixture*/)
{
}

void UTbNamesNamEsOLinkHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbNamesNamEsOLinkHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbNamesNamEsOLinkHelper::SwitchPropertyCb(bool bInSwitch)
{
	(void)bInSwitch;
}

void UTbNamesNamEsOLinkHelper::SwitchPropertyChangeLocalCheckRemoteCb(bool bInSwitch)
{
	(void)bInSwitch;
}

void UTbNamesNamEsOLinkHelper::SwitchPropertyChangeLocalChangeRemoteCb(bool bInSwitch)
{
	(void)bInSwitch;
}

void UTbNamesNamEsOLinkHelper::SomePropertyPropertyCb(int32 InSomeProperty)
{
	(void)InSomeProperty;
}

void UTbNamesNamEsOLinkHelper::SomePropertyPropertyChangeLocalCheckRemoteCb(int32 InSomeProperty)
{
	(void)InSomeProperty;
}

void UTbNamesNamEsOLinkHelper::SomePropertyPropertyChangeLocalChangeRemoteCb(int32 InSomeProperty)
{
	(void)InSomeProperty;
}

void UTbNamesNamEsOLinkHelper::SomePoperty2PropertyCb(int32 InSomePoperty2)
{
	(void)InSomePoperty2;
}

void UTbNamesNamEsOLinkHelper::SomePoperty2PropertyChangeLocalCheckRemoteCb(int32 InSomePoperty2)
{
	(void)InSomePoperty2;
}

void UTbNamesNamEsOLinkHelper::SomePoperty2PropertyChangeLocalChangeRemoteCb(int32 InSomePoperty2)
{
	(void)InSomePoperty2;
}

void UTbNamesNamEsOLinkHelper::EnumPropertyPropertyCb(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	(void)InEnumProperty;
}

void UTbNamesNamEsOLinkHelper::EnumPropertyPropertyChangeLocalCheckRemoteCb(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	(void)InEnumProperty;
}

void UTbNamesNamEsOLinkHelper::EnumPropertyPropertyChangeLocalChangeRemoteCb(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	(void)InEnumProperty;
}

void UTbNamesNamEsOLinkHelper::SomeSignalSignalCb(bool bSomeParam)
{
	(void)bSomeParam;
}

void UTbNamesNamEsOLinkHelper::SomeSignal2SignalCb(bool bSomeParam)
{
	(void)bSomeParam;
}

void UTbNamesNamEsOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
