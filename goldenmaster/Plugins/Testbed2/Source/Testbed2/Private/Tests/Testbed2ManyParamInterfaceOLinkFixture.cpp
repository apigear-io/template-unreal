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
#include "Testbed2ManyParamInterfaceOLinkFixture.h"
#include "Testbed2TestsCommon.h"
#include "OLinkCommon.h"
#include "Generated/OLink/Testbed2ManyParamInterfaceOLinkClient.h"
#include "Generated/OLink/Testbed2ManyParamInterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTestbed2ManyParamInterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTestbed2ManyParamInterfaceOLinkFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTestbed2ManyParamInterfaceOLinkHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTestbed2ManyParamInterfaceOLinkHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop1PropertyCb(int32 InProp1)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb(int32 InProp1)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb(int32 InProp1)
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
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0; // default value
		if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp1(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		int32 TestValue = 0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop2PropertyCb(int32 InProp2)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop2PropertyChangeLocalCheckRemoteCb(int32 InProp2)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop2PropertyChangeLocalChangeRemoteCb(int32 InProp2)
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
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
		if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0; // default value
		if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp2(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		int32 TestValue = 0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
		if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop3PropertyCb(int32 InProp3)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp3(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop3PropertyChangeLocalCheckRemoteCb(int32 InProp3)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp3(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop3PropertyChangeLocalChangeRemoteCb(int32 InProp3)
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
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
		if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp3(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0; // default value
		if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp3(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		int32 TestValue = 0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
		if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp3(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop4PropertyCb(int32 InProp4)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp4(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop4PropertyChangeLocalCheckRemoteCb(int32 InProp4)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp4(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop4PropertyChangeLocalChangeRemoteCb(int32 InProp4)
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
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
		if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp4(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0; // default value
		if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp4(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		int32 TestValue = 0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
		if (TSharedPtr<FTestbed2ManyParamInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp4(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed2ManyParamInterfaceOLinkHelper::Sig1SignalCb(int32 InParam1)
{
	// known test value
	int32 Param1TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceOLinkHelper::Sig2SignalCb(int32 InParam1, int32 InParam2)
{
	// known test value
	int32 Param1TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	int32 Param2TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceOLinkHelper::Sig3SignalCb(int32 InParam1, int32 InParam2, int32 InParam3)
{
	// known test value
	int32 Param1TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	int32 Param2TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	int32 Param3TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceOLinkHelper::Sig4SignalCb(int32 InParam1, int32 InParam2, int32 InParam3, int32 InParam4)
{
	// known test value
	int32 Param1TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	int32 Param2TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	int32 Param3TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
	int32 Param4TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam4, Param4TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

FTestbed2ManyParamInterfaceOLinkFixture::FTestbed2ManyParamInterfaceOLinkFixture()
{
	Helper = NewObject<UTestbed2ManyParamInterfaceOLinkHelper>(GetTransientPackage());
	Helper->AddToRoot();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceOLinkClient>();
}

FTestbed2ManyParamInterfaceOLinkFixture::~FTestbed2ManyParamInterfaceOLinkFixture()
{
	CleanUp();
	Helper->RemoveFromRoot();
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> FTestbed2ManyParamInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTestbed2ManyParamInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTestbed2ManyParamInterfaceOLinkAdapter* FTestbed2ManyParamInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTestbed2ManyParamInterfaceOLinkHelper> FTestbed2ManyParamInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed2ManyParamInterfaceOLinkFixture::GetGameInstance()
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

void FTestbed2ManyParamInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTestbed2ManyParamInterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTestbed2ManyParamInterfaceOLinkFixture> /*InFixture*/)
{
}

void UTestbed2ManyParamInterfaceOLinkHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTestbed2ManyParamInterfaceOLinkHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop1PropertyCb(int32 InProp1)
{
	(void)InProp1;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb(int32 InProp1)
{
	(void)InProp1;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb(int32 InProp1)
{
	(void)InProp1;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop2PropertyCb(int32 InProp2)
{
	(void)InProp2;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop2PropertyChangeLocalCheckRemoteCb(int32 InProp2)
{
	(void)InProp2;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop2PropertyChangeLocalChangeRemoteCb(int32 InProp2)
{
	(void)InProp2;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop3PropertyCb(int32 InProp3)
{
	(void)InProp3;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop3PropertyChangeLocalCheckRemoteCb(int32 InProp3)
{
	(void)InProp3;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop3PropertyChangeLocalChangeRemoteCb(int32 InProp3)
{
	(void)InProp3;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop4PropertyCb(int32 InProp4)
{
	(void)InProp4;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop4PropertyChangeLocalCheckRemoteCb(int32 InProp4)
{
	(void)InProp4;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop4PropertyChangeLocalChangeRemoteCb(int32 InProp4)
{
	(void)InProp4;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Sig1SignalCb(int32 Param1)
{
	(void)Param1;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Sig2SignalCb(int32 Param1, int32 Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Sig3SignalCb(int32 Param1, int32 Param2, int32 Param3)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Sig4SignalCb(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
	(void)Param4;
}

void UTestbed2ManyParamInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
