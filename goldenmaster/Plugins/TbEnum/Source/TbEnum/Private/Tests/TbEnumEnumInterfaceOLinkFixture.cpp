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
#include "TbEnumEnumInterfaceOLinkFixture.h"
#include "TbEnumTestsCommon.h"
#include "OLinkCommon.h"
#include "Generated/OLink/TbEnumEnumInterfaceOLinkClient.h"
#include "Generated/OLink/TbEnumEnumInterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTbEnumEnumInterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTbEnumEnumInterfaceOLinkFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbEnumEnumInterfaceOLinkHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbEnumEnumInterfaceOLinkHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbEnumEnumInterfaceOLinkHelper::Prop0PropertyCb(ETbEnumEnum0 InProp0)
{
	ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_VALUE0;
	// use different test value
	TestValue = ETbEnumEnum0::TEE0_VALUE1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp0, TestValue);
	if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp0(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkHelper::Prop0PropertyChangeLocalCheckRemoteCb(ETbEnumEnum0 InProp0)
{
	ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_VALUE0;
	// use different test value
	TestValue = ETbEnumEnum0::TEE0_VALUE1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp0, TestValue);
	if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp0(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkHelper::Prop0PropertyChangeLocalChangeRemoteCb(ETbEnumEnum0 InProp0)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_VALUE0;
		// use different test value
		TestValue = ETbEnumEnum0::TEE0_VALUE1;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp0, TestValue);
		if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp0(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = ETbEnumEnum0::TEE0_VALUE0; // default value
		if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp0(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_VALUE0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp0, TestValue);
		if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp0(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbEnumEnumInterfaceOLinkHelper::Prop1PropertyCb(ETbEnumEnum1 InProp1)
{
	ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_VALUE1;
	// use different test value
	TestValue = ETbEnumEnum1::TEE1_VALUE2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb(ETbEnumEnum1 InProp1)
{
	ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_VALUE1;
	// use different test value
	TestValue = ETbEnumEnum1::TEE1_VALUE2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb(ETbEnumEnum1 InProp1)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_VALUE1;
		// use different test value
		TestValue = ETbEnumEnum1::TEE1_VALUE2;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = ETbEnumEnum1::TEE1_VALUE1; // default value
		if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp1(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_VALUE1; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbEnumEnumInterfaceOLinkHelper::Prop2PropertyCb(ETbEnumEnum2 InProp2)
{
	ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_VALUE2;
	// use different test value
	TestValue = ETbEnumEnum2::TEE2_VALUE1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkHelper::Prop2PropertyChangeLocalCheckRemoteCb(ETbEnumEnum2 InProp2)
{
	ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_VALUE2;
	// use different test value
	TestValue = ETbEnumEnum2::TEE2_VALUE1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkHelper::Prop2PropertyChangeLocalChangeRemoteCb(ETbEnumEnum2 InProp2)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_VALUE2;
		// use different test value
		TestValue = ETbEnumEnum2::TEE2_VALUE1;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
		if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = ETbEnumEnum2::TEE2_VALUE2; // default value
		if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp2(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_VALUE2; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
		if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbEnumEnumInterfaceOLinkHelper::Prop3PropertyCb(ETbEnumEnum3 InProp3)
{
	ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_VALUE3;
	// use different test value
	TestValue = ETbEnumEnum3::TEE3_VALUE2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
	if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp3(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkHelper::Prop3PropertyChangeLocalCheckRemoteCb(ETbEnumEnum3 InProp3)
{
	ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_VALUE3;
	// use different test value
	TestValue = ETbEnumEnum3::TEE3_VALUE2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
	if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp3(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkHelper::Prop3PropertyChangeLocalChangeRemoteCb(ETbEnumEnum3 InProp3)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_VALUE3;
		// use different test value
		TestValue = ETbEnumEnum3::TEE3_VALUE2;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
		if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp3(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = ETbEnumEnum3::TEE3_VALUE3; // default value
		if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp3(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_VALUE3; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
		if (TSharedPtr<FTbEnumEnumInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp3(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbEnumEnumInterfaceOLinkHelper::Sig0SignalCb(ETbEnumEnum0 InParam0)
{
	// known test value
	ETbEnumEnum0 Param0TestValue = ETbEnumEnum0::TEE0_VALUE1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam0, Param0TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkHelper::Sig1SignalCb(ETbEnumEnum1 InParam1)
{
	// known test value
	ETbEnumEnum1 Param1TestValue = ETbEnumEnum1::TEE1_VALUE2;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkHelper::Sig2SignalCb(ETbEnumEnum2 InParam2)
{
	// known test value
	ETbEnumEnum2 Param2TestValue = ETbEnumEnum2::TEE2_VALUE1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkHelper::Sig3SignalCb(ETbEnumEnum3 InParam3)
{
	// known test value
	ETbEnumEnum3 Param3TestValue = ETbEnumEnum3::TEE3_VALUE2;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

FTbEnumEnumInterfaceOLinkFixture::FTbEnumEnumInterfaceOLinkFixture()
{
	Helper = NewObject<UTbEnumEnumInterfaceOLinkHelper>(GetTransientPackage());
	Helper->AddToRoot();
	testImplementation = GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceOLinkClient>();
}

FTbEnumEnumInterfaceOLinkFixture::~FTbEnumEnumInterfaceOLinkFixture()
{
	CleanUp();
	Helper->RemoveFromRoot();
}

TScriptInterface<ITbEnumEnumInterfaceInterface> FTbEnumEnumInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbEnumEnumInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbEnumEnumInterfaceOLinkAdapter* FTbEnumEnumInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbEnumEnumInterfaceOLinkHelper> FTbEnumEnumInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbEnumEnumInterfaceOLinkFixture::GetGameInstance()
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

void FTbEnumEnumInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTbEnumEnumInterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTbEnumEnumInterfaceOLinkFixture> /*InFixture*/)
{
}

void UTbEnumEnumInterfaceOLinkHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbEnumEnumInterfaceOLinkHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbEnumEnumInterfaceOLinkHelper::Prop0PropertyCb(ETbEnumEnum0 InProp0)
{
	(void)InProp0;
}

void UTbEnumEnumInterfaceOLinkHelper::Prop0PropertyChangeLocalCheckRemoteCb(ETbEnumEnum0 InProp0)
{
	(void)InProp0;
}

void UTbEnumEnumInterfaceOLinkHelper::Prop0PropertyChangeLocalChangeRemoteCb(ETbEnumEnum0 InProp0)
{
	(void)InProp0;
}

void UTbEnumEnumInterfaceOLinkHelper::Prop1PropertyCb(ETbEnumEnum1 InProp1)
{
	(void)InProp1;
}

void UTbEnumEnumInterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb(ETbEnumEnum1 InProp1)
{
	(void)InProp1;
}

void UTbEnumEnumInterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb(ETbEnumEnum1 InProp1)
{
	(void)InProp1;
}

void UTbEnumEnumInterfaceOLinkHelper::Prop2PropertyCb(ETbEnumEnum2 InProp2)
{
	(void)InProp2;
}

void UTbEnumEnumInterfaceOLinkHelper::Prop2PropertyChangeLocalCheckRemoteCb(ETbEnumEnum2 InProp2)
{
	(void)InProp2;
}

void UTbEnumEnumInterfaceOLinkHelper::Prop2PropertyChangeLocalChangeRemoteCb(ETbEnumEnum2 InProp2)
{
	(void)InProp2;
}

void UTbEnumEnumInterfaceOLinkHelper::Prop3PropertyCb(ETbEnumEnum3 InProp3)
{
	(void)InProp3;
}

void UTbEnumEnumInterfaceOLinkHelper::Prop3PropertyChangeLocalCheckRemoteCb(ETbEnumEnum3 InProp3)
{
	(void)InProp3;
}

void UTbEnumEnumInterfaceOLinkHelper::Prop3PropertyChangeLocalChangeRemoteCb(ETbEnumEnum3 InProp3)
{
	(void)InProp3;
}

void UTbEnumEnumInterfaceOLinkHelper::Sig0SignalCb(ETbEnumEnum0 Param0)
{
	(void)Param0;
}

void UTbEnumEnumInterfaceOLinkHelper::Sig1SignalCb(ETbEnumEnum1 Param1)
{
	(void)Param1;
}

void UTbEnumEnumInterfaceOLinkHelper::Sig2SignalCb(ETbEnumEnum2 Param2)
{
	(void)Param2;
}

void UTbEnumEnumInterfaceOLinkHelper::Sig3SignalCb(ETbEnumEnum3 Param3)
{
	(void)Param3;
}

void UTbEnumEnumInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
