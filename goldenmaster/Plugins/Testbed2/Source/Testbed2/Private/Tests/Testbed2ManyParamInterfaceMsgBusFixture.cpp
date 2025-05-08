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
#include "Testbed2ManyParamInterfaceMsgBusFixture.h"
#include "Testbed2TestsCommon.h"
#include "Generated/MsgBus/Testbed2ManyParamInterfaceMsgBusClient.h"
#include "Generated/MsgBus/Testbed2ManyParamInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTestbed2ManyParamInterfaceMsgBusHelper::~UTestbed2ManyParamInterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTestbed2ManyParamInterfaceMsgBusFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop1PropertyCb(int32 InProp1)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(int32 InProp1)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(int32 InProp1)
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
		if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0; // default value
		if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp1(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		int32 TestValue = 0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop2PropertyCb(int32 InProp2)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop2PropertyChangeLocalCheckRemoteCb(int32 InProp2)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop2PropertyChangeLocalChangeRemoteCb(int32 InProp2)
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
		if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0; // default value
		if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp2(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		int32 TestValue = 0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
		if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop3PropertyCb(int32 InProp3)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp3(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop3PropertyChangeLocalCheckRemoteCb(int32 InProp3)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp3(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop3PropertyChangeLocalChangeRemoteCb(int32 InProp3)
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
		if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp3(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0; // default value
		if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp3(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		int32 TestValue = 0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
		if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp3(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop4PropertyCb(int32 InProp4)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp4(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop4PropertyChangeLocalCheckRemoteCb(int32 InProp4)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp4(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop4PropertyChangeLocalChangeRemoteCb(int32 InProp4)
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
		if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp4(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0; // default value
		if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp4(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		int32 TestValue = 0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
		if (TSharedPtr<FTestbed2ManyParamInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp4(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Sig1SignalCb(int32 InParam1)
{
	// known test value
	int32 Param1TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Sig2SignalCb(int32 InParam1, int32 InParam2)
{
	// known test value
	int32 Param1TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	int32 Param2TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Sig3SignalCb(int32 InParam1, int32 InParam2, int32 InParam3)
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

void UTestbed2ManyParamInterfaceMsgBusHelper::Sig4SignalCb(int32 InParam1, int32 InParam2, int32 InParam3, int32 InParam4)
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

void UTestbed2ManyParamInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

FTestbed2ManyParamInterfaceMsgBusFixture::FTestbed2ManyParamInterfaceMsgBusFixture()
{
	Helper = NewObject<UTestbed2ManyParamInterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceMsgBusClient>();
}

FTestbed2ManyParamInterfaceMsgBusFixture::~FTestbed2ManyParamInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> FTestbed2ManyParamInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed2ManyParamInterfaceMsgBusAdapter* FTestbed2ManyParamInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTestbed2ManyParamInterfaceMsgBusHelper> FTestbed2ManyParamInterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed2ManyParamInterfaceMsgBusFixture::GetGameInstance()
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

void FTestbed2ManyParamInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTestbed2ManyParamInterfaceMsgBusHelper::~UTestbed2ManyParamInterfaceMsgBusHelper()
{
}

void UTestbed2ManyParamInterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTestbed2ManyParamInterfaceMsgBusFixture> /*InFixture*/)
{
}

void UTestbed2ManyParamInterfaceMsgBusHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTestbed2ManyParamInterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop1PropertyCb(int32 InProp1)
{
	(void)InProp1;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(int32 InProp1)
{
	(void)InProp1;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(int32 InProp1)
{
	(void)InProp1;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop2PropertyCb(int32 InProp2)
{
	(void)InProp2;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop2PropertyChangeLocalCheckRemoteCb(int32 InProp2)
{
	(void)InProp2;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop2PropertyChangeLocalChangeRemoteCb(int32 InProp2)
{
	(void)InProp2;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop3PropertyCb(int32 InProp3)
{
	(void)InProp3;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop3PropertyChangeLocalCheckRemoteCb(int32 InProp3)
{
	(void)InProp3;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop3PropertyChangeLocalChangeRemoteCb(int32 InProp3)
{
	(void)InProp3;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop4PropertyCb(int32 InProp4)
{
	(void)InProp4;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop4PropertyChangeLocalCheckRemoteCb(int32 InProp4)
{
	(void)InProp4;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop4PropertyChangeLocalChangeRemoteCb(int32 InProp4)
{
	(void)InProp4;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Sig1SignalCb(int32 Param1)
{
	(void)Param1;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Sig2SignalCb(int32 Param1, int32 Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Sig3SignalCb(int32 Param1, int32 Param2, int32 Param3)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Sig4SignalCb(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
	(void)Param4;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
