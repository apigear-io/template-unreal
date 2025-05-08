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
#include "Testbed2NestedStruct2InterfaceOLinkFixture.h"
#include "Testbed2TestsCommon.h"
#include "OLinkCommon.h"
#include "Generated/OLink/Testbed2NestedStruct2InterfaceOLinkClient.h"
#include "Generated/OLink/Testbed2NestedStruct2InterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTestbed2NestedStruct2InterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTestbed2NestedStruct2InterfaceOLinkFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& InProp1)
{
	FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct1();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTestbed2NestedStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct1& InProp1)
{
	FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct1();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTestbed2NestedStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct1& InProp1)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1();
		// use different test value
		TestValue = createTestFTestbed2NestedStruct1();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTestbed2NestedStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed2NestedStruct1(); // default value
		if (TSharedPtr<FTestbed2NestedStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp1(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTestbed2NestedStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Prop2PropertyCb(const FTestbed2NestedStruct2& InProp2)
{
	FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct2();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTestbed2NestedStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Prop2PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct2& InProp2)
{
	FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct2();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTestbed2NestedStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Prop2PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct2& InProp2)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2();
		// use different test value
		TestValue = createTestFTestbed2NestedStruct2();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
		if (TSharedPtr<FTestbed2NestedStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed2NestedStruct2(); // default value
		if (TSharedPtr<FTestbed2NestedStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp2(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
		if (TSharedPtr<FTestbed2NestedStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Sig1SignalCb(const FTestbed2NestedStruct1& InParam1)
{
	// known test value
	FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Sig2SignalCb(const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2)
{
	// known test value
	FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

FTestbed2NestedStruct2InterfaceOLinkFixture::FTestbed2NestedStruct2InterfaceOLinkFixture()
{
	Helper = NewObject<UTestbed2NestedStruct2InterfaceOLinkHelper>(GetTransientPackage());
	Helper->AddToRoot();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2NestedStruct2InterfaceOLinkClient>();
}

FTestbed2NestedStruct2InterfaceOLinkFixture::~FTestbed2NestedStruct2InterfaceOLinkFixture()
{
	CleanUp();
	Helper->RemoveFromRoot();
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> FTestbed2NestedStruct2InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTestbed2NestedStruct2InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTestbed2NestedStruct2InterfaceOLinkAdapter* FTestbed2NestedStruct2InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2NestedStruct2InterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTestbed2NestedStruct2InterfaceOLinkHelper> FTestbed2NestedStruct2InterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed2NestedStruct2InterfaceOLinkFixture::GetGameInstance()
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

void FTestbed2NestedStruct2InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTestbed2NestedStruct2InterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTestbed2NestedStruct2InterfaceOLinkFixture> /*InFixture*/)
{
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& InProp1)
{
	(void)InProp1;
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct1& InProp1)
{
	(void)InProp1;
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct1& InProp1)
{
	(void)InProp1;
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Prop2PropertyCb(const FTestbed2NestedStruct2& InProp2)
{
	(void)InProp2;
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Prop2PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct2& InProp2)
{
	(void)InProp2;
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Prop2PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct2& InProp2)
{
	(void)InProp2;
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
