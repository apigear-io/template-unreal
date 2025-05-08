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
#include "Testbed2NestedStruct1InterfaceMsgBusFixture.h"
#include "Testbed2TestsCommon.h"
#include "Generated/MsgBus/Testbed2NestedStruct1InterfaceMsgBusClient.h"
#include "Generated/MsgBus/Testbed2NestedStruct1InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTestbed2NestedStruct1InterfaceMsgBusHelper::~UTestbed2NestedStruct1InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTestbed2NestedStruct1InterfaceMsgBusFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& InProp1)
{
	FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct1();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTestbed2NestedStruct1InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct1& InProp1)
{
	FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct1();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTestbed2NestedStruct1InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct1& InProp1)
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
		if (TSharedPtr<FTestbed2NestedStruct1InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed2NestedStruct1(); // default value
		if (TSharedPtr<FTestbed2NestedStruct1InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp1(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTestbed2NestedStruct1InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::Sig1SignalCb(const FTestbed2NestedStruct1& InParam1)
{
	// known test value
	FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

FTestbed2NestedStruct1InterfaceMsgBusFixture::FTestbed2NestedStruct1InterfaceMsgBusFixture()
{
	Helper = NewObject<UTestbed2NestedStruct1InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2NestedStruct1InterfaceMsgBusClient>();
}

FTestbed2NestedStruct1InterfaceMsgBusFixture::~FTestbed2NestedStruct1InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> FTestbed2NestedStruct1InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed2NestedStruct1InterfaceMsgBusAdapter* FTestbed2NestedStruct1InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2NestedStruct1InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTestbed2NestedStruct1InterfaceMsgBusHelper> FTestbed2NestedStruct1InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed2NestedStruct1InterfaceMsgBusFixture::GetGameInstance()
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

void FTestbed2NestedStruct1InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTestbed2NestedStruct1InterfaceMsgBusHelper::~UTestbed2NestedStruct1InterfaceMsgBusHelper()
{
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTestbed2NestedStruct1InterfaceMsgBusFixture> /*InFixture*/)
{
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& InProp1)
{
	(void)InProp1;
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct1& InProp1)
{
	(void)InProp1;
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct1& InProp1)
{
	(void)InProp1;
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
