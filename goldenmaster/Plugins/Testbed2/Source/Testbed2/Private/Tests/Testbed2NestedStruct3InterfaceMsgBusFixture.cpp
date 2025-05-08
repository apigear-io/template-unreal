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
#include "Testbed2NestedStruct3InterfaceMsgBusFixture.h"
#include "Testbed2TestsCommon.h"
#include "Generated/MsgBus/Testbed2NestedStruct3InterfaceMsgBusClient.h"
#include "Generated/MsgBus/Testbed2NestedStruct3InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTestbed2NestedStruct3InterfaceMsgBusHelper::~UTestbed2NestedStruct3InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTestbed2NestedStruct3InterfaceMsgBusFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& InProp1)
{
	FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct1();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTestbed2NestedStruct3InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct1& InProp1)
{
	FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct1();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTestbed2NestedStruct3InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct1& InProp1)
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
		if (TSharedPtr<FTestbed2NestedStruct3InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed2NestedStruct1(); // default value
		if (TSharedPtr<FTestbed2NestedStruct3InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp1(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTestbed2NestedStruct3InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop2PropertyCb(const FTestbed2NestedStruct2& InProp2)
{
	FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct2();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTestbed2NestedStruct3InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop2PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct2& InProp2)
{
	FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct2();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTestbed2NestedStruct3InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop2PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct2& InProp2)
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
		if (TSharedPtr<FTestbed2NestedStruct3InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed2NestedStruct2(); // default value
		if (TSharedPtr<FTestbed2NestedStruct3InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp2(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
		if (TSharedPtr<FTestbed2NestedStruct3InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop3PropertyCb(const FTestbed2NestedStruct3& InProp3)
{
	FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct3();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
	if (TSharedPtr<FTestbed2NestedStruct3InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp3(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop3PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct3& InProp3)
{
	FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct3();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
	if (TSharedPtr<FTestbed2NestedStruct3InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp3(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop3PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct3& InProp3)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3();
		// use different test value
		TestValue = createTestFTestbed2NestedStruct3();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
		if (TSharedPtr<FTestbed2NestedStruct3InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp3(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed2NestedStruct3(); // default value
		if (TSharedPtr<FTestbed2NestedStruct3InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp3(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
		if (TSharedPtr<FTestbed2NestedStruct3InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp3(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Sig1SignalCb(const FTestbed2NestedStruct1& InParam1)
{
	// known test value
	FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Sig2SignalCb(const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2)
{
	// known test value
	FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Sig3SignalCb(const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2, const FTestbed2NestedStruct3& InParam3)
{
	// known test value
	FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	FTestbed2NestedStruct3 Param3TestValue = createTestFTestbed2NestedStruct3();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

FTestbed2NestedStruct3InterfaceMsgBusFixture::FTestbed2NestedStruct3InterfaceMsgBusFixture()
{
	Helper = NewObject<UTestbed2NestedStruct3InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2NestedStruct3InterfaceMsgBusClient>();
}

FTestbed2NestedStruct3InterfaceMsgBusFixture::~FTestbed2NestedStruct3InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> FTestbed2NestedStruct3InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed2NestedStruct3InterfaceMsgBusAdapter* FTestbed2NestedStruct3InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2NestedStruct3InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTestbed2NestedStruct3InterfaceMsgBusHelper> FTestbed2NestedStruct3InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed2NestedStruct3InterfaceMsgBusFixture::GetGameInstance()
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

void FTestbed2NestedStruct3InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTestbed2NestedStruct3InterfaceMsgBusHelper::~UTestbed2NestedStruct3InterfaceMsgBusHelper()
{
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTestbed2NestedStruct3InterfaceMsgBusFixture> /*InFixture*/)
{
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& InProp1)
{
	(void)InProp1;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct1& InProp1)
{
	(void)InProp1;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct1& InProp1)
{
	(void)InProp1;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop2PropertyCb(const FTestbed2NestedStruct2& InProp2)
{
	(void)InProp2;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop2PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct2& InProp2)
{
	(void)InProp2;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop2PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct2& InProp2)
{
	(void)InProp2;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop3PropertyCb(const FTestbed2NestedStruct3& InProp3)
{
	(void)InProp3;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop3PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct3& InProp3)
{
	(void)InProp3;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop3PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct3& InProp3)
{
	(void)InProp3;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Sig3SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
