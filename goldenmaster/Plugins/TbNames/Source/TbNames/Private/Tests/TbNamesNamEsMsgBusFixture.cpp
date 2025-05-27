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
#include "TbNamesNamEsMsgBusFixture.h"
#include "TbNamesTestsCommon.h"
#include "Generated/MsgBus/TbNamesNamEsMsgBusClient.h"
#include "Generated/MsgBus/TbNamesNamEsMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTbNamesNamEsMsgBusHelper::~UTbNamesNamEsMsgBusHelper()
{
	Spec = nullptr;
}

void UTbNamesNamEsMsgBusHelper::SetParentFixture(TWeakPtr<FTbNamesNamEsMsgBusFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbNamesNamEsMsgBusHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbNamesNamEsMsgBusHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbNamesNamEsMsgBusHelper::SwitchPropertyCb(bool bInSwitch)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
	if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSwitch(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusHelper::SwitchPropertyChangeLocalCheckRemoteCb(bool bInSwitch)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
	if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSwitch(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusHelper::SwitchPropertyChangeLocalChangeRemoteCb(bool bInSwitch)
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
		if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSwitch(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = false; // default value
		if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetSwitch(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		bool TestValue = false; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
		if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSwitch(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbNamesNamEsMsgBusHelper::SomePropertyPropertyCb(int32 InSomeProperty)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
	if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomeProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusHelper::SomePropertyPropertyChangeLocalCheckRemoteCb(int32 InSomeProperty)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
	if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomeProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusHelper::SomePropertyPropertyChangeLocalChangeRemoteCb(int32 InSomeProperty)
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
		if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomeProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0; // default value
		if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetSomeProperty(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		int32 TestValue = 0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
		if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomeProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbNamesNamEsMsgBusHelper::SomePoperty2PropertyCb(int32 InSomePoperty2)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
	if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomePoperty2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusHelper::SomePoperty2PropertyChangeLocalCheckRemoteCb(int32 InSomePoperty2)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
	if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomePoperty2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusHelper::SomePoperty2PropertyChangeLocalChangeRemoteCb(int32 InSomePoperty2)
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
		if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomePoperty2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0; // default value
		if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetSomePoperty2(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		int32 TestValue = 0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
		if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetSomePoperty2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbNamesNamEsMsgBusHelper::EnumPropertyPropertyCb(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue;
	// use different test value
	TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SecondValue;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
	if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetEnumProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusHelper::EnumPropertyPropertyChangeLocalCheckRemoteCb(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue;
	// use different test value
	TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SecondValue;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
	if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetEnumProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusHelper::EnumPropertyPropertyChangeLocalChangeRemoteCb(ETbNamesEnum_With_Under_scores InEnumProperty)
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
		if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetEnumProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue; // default value
		if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetEnumProperty(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
		if (TSharedPtr<FTbNamesNamEsMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetEnumProperty(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbNamesNamEsMsgBusHelper::SomeSignalSignalCb(bool bInSomeParam)
{
	// known test value
	bool bSomeParamTestValue = true;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInSomeParam, bSomeParamTestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusHelper::SomeSignal2SignalCb(bool bInSomeParam)
{
	// known test value
	bool bSomeParamTestValue = true;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInSomeParam, bSomeParamTestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

FTbNamesNamEsMsgBusFixture::FTbNamesNamEsMsgBusFixture()
{
	Helper = NewObject<UTbNamesNamEsMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbNamesNamEsMsgBusClient>();
}

FTbNamesNamEsMsgBusFixture::~FTbNamesNamEsMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbNamesNamEsInterface> FTbNamesNamEsMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbNamesNamEsMsgBusAdapter* FTbNamesNamEsMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbNamesNamEsMsgBusAdapter>();
}

TSoftObjectPtr<UTbNamesNamEsMsgBusHelper> FTbNamesNamEsMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbNamesNamEsMsgBusFixture::GetGameInstance()
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

void FTbNamesNamEsMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTbNamesNamEsMsgBusHelper::~UTbNamesNamEsMsgBusHelper()
{
}

void UTbNamesNamEsMsgBusHelper::SetParentFixture(TWeakPtr<FTbNamesNamEsMsgBusFixture> /*InFixture*/)
{
}

void UTbNamesNamEsMsgBusHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbNamesNamEsMsgBusHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbNamesNamEsMsgBusHelper::SwitchPropertyCb(bool bInSwitch)
{
	(void)bInSwitch;
}

void UTbNamesNamEsMsgBusHelper::SwitchPropertyChangeLocalCheckRemoteCb(bool bInSwitch)
{
	(void)bInSwitch;
}

void UTbNamesNamEsMsgBusHelper::SwitchPropertyChangeLocalChangeRemoteCb(bool bInSwitch)
{
	(void)bInSwitch;
}

void UTbNamesNamEsMsgBusHelper::SomePropertyPropertyCb(int32 InSomeProperty)
{
	(void)InSomeProperty;
}

void UTbNamesNamEsMsgBusHelper::SomePropertyPropertyChangeLocalCheckRemoteCb(int32 InSomeProperty)
{
	(void)InSomeProperty;
}

void UTbNamesNamEsMsgBusHelper::SomePropertyPropertyChangeLocalChangeRemoteCb(int32 InSomeProperty)
{
	(void)InSomeProperty;
}

void UTbNamesNamEsMsgBusHelper::SomePoperty2PropertyCb(int32 InSomePoperty2)
{
	(void)InSomePoperty2;
}

void UTbNamesNamEsMsgBusHelper::SomePoperty2PropertyChangeLocalCheckRemoteCb(int32 InSomePoperty2)
{
	(void)InSomePoperty2;
}

void UTbNamesNamEsMsgBusHelper::SomePoperty2PropertyChangeLocalChangeRemoteCb(int32 InSomePoperty2)
{
	(void)InSomePoperty2;
}

void UTbNamesNamEsMsgBusHelper::EnumPropertyPropertyCb(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	(void)InEnumProperty;
}

void UTbNamesNamEsMsgBusHelper::EnumPropertyPropertyChangeLocalCheckRemoteCb(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	(void)InEnumProperty;
}

void UTbNamesNamEsMsgBusHelper::EnumPropertyPropertyChangeLocalChangeRemoteCb(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	(void)InEnumProperty;
}

void UTbNamesNamEsMsgBusHelper::SomeSignalSignalCb(bool bSomeParam)
{
	(void)bSomeParam;
}

void UTbNamesNamEsMsgBusHelper::SomeSignal2SignalCb(bool bSomeParam)
{
	(void)bSomeParam;
}

void UTbNamesNamEsMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
