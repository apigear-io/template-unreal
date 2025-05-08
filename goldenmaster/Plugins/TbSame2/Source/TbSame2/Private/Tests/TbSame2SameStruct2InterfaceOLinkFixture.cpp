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
#include "TbSame2SameStruct2InterfaceOLinkFixture.h"
#include "TbSame2TestsCommon.h"
#include "OLinkCommon.h"
#include "Generated/OLink/TbSame2SameStruct2InterfaceOLinkClient.h"
#include "Generated/OLink/TbSame2SameStruct2InterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTbSame2SameStruct2InterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTbSame2SameStruct2InterfaceOLinkFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSame2SameStruct2InterfaceOLinkHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSame2SameStruct2InterfaceOLinkHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop1PropertyCb(const FTbSame2Struct2& InProp1)
{
	FTbSame2Struct2 TestValue = FTbSame2Struct2();
	// use different test value
	TestValue = createTestFTbSame2Struct2();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame2SameStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTbSame2Struct2& InProp1)
{
	FTbSame2Struct2 TestValue = FTbSame2Struct2();
	// use different test value
	TestValue = createTestFTbSame2Struct2();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame2SameStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTbSame2Struct2& InProp1)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTbSame2Struct2 TestValue = FTbSame2Struct2();
		// use different test value
		TestValue = createTestFTbSame2Struct2();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTbSame2SameStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTbSame2Struct2(); // default value
		if (TSharedPtr<FTbSame2SameStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp1(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTbSame2Struct2 TestValue = FTbSame2Struct2(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTbSame2SameStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop2PropertyCb(const FTbSame2Struct2& InProp2)
{
	FTbSame2Struct2 TestValue = FTbSame2Struct2();
	// use different test value
	TestValue = createTestFTbSame2Struct2();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTbSame2SameStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop2PropertyChangeLocalCheckRemoteCb(const FTbSame2Struct2& InProp2)
{
	FTbSame2Struct2 TestValue = FTbSame2Struct2();
	// use different test value
	TestValue = createTestFTbSame2Struct2();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTbSame2SameStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop2PropertyChangeLocalChangeRemoteCb(const FTbSame2Struct2& InProp2)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTbSame2Struct2 TestValue = FTbSame2Struct2();
		// use different test value
		TestValue = createTestFTbSame2Struct2();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
		if (TSharedPtr<FTbSame2SameStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTbSame2Struct2(); // default value
		if (TSharedPtr<FTbSame2SameStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp2(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTbSame2Struct2 TestValue = FTbSame2Struct2(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
		if (TSharedPtr<FTbSame2SameStruct2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Sig1SignalCb(const FTbSame2Struct1& InParam1)
{
	// known test value
	FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Sig2SignalCb(const FTbSame2Struct1& InParam1, const FTbSame2Struct2& InParam2)
{
	// known test value
	FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	FTbSame2Struct2 Param2TestValue = createTestFTbSame2Struct2();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

FTbSame2SameStruct2InterfaceOLinkFixture::FTbSame2SameStruct2InterfaceOLinkFixture()
{
	Helper = NewObject<UTbSame2SameStruct2InterfaceOLinkHelper>(GetTransientPackage());
	Helper->AddToRoot();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameStruct2InterfaceOLinkClient>();
}

FTbSame2SameStruct2InterfaceOLinkFixture::~FTbSame2SameStruct2InterfaceOLinkFixture()
{
	CleanUp();
	Helper->RemoveFromRoot();
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> FTbSame2SameStruct2InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSame2SameStruct2InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSame2SameStruct2InterfaceOLinkAdapter* FTbSame2SameStruct2InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameStruct2InterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSame2SameStruct2InterfaceOLinkHelper> FTbSame2SameStruct2InterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame2SameStruct2InterfaceOLinkFixture::GetGameInstance()
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

void FTbSame2SameStruct2InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTbSame2SameStruct2InterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTbSame2SameStruct2InterfaceOLinkFixture> /*InFixture*/)
{
}

void UTbSame2SameStruct2InterfaceOLinkHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSame2SameStruct2InterfaceOLinkHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop1PropertyCb(const FTbSame2Struct2& InProp1)
{
	(void)InProp1;
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTbSame2Struct2& InProp1)
{
	(void)InProp1;
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTbSame2Struct2& InProp1)
{
	(void)InProp1;
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop2PropertyCb(const FTbSame2Struct2& InProp2)
{
	(void)InProp2;
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop2PropertyChangeLocalCheckRemoteCb(const FTbSame2Struct2& InProp2)
{
	(void)InProp2;
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop2PropertyChangeLocalChangeRemoteCb(const FTbSame2Struct2& InProp2)
{
	(void)InProp2;
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Sig1SignalCb(const FTbSame2Struct1& Param1)
{
	(void)Param1;
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Sig2SignalCb(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTbSame2SameStruct2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
