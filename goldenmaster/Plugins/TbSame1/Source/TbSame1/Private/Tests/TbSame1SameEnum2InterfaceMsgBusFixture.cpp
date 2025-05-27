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
#include "TbSame1SameEnum2InterfaceMsgBusFixture.h"
#include "TbSame1TestsCommon.h"
#include "Generated/MsgBus/TbSame1SameEnum2InterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSame1SameEnum2InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTbSame1SameEnum2InterfaceMsgBusHelper::~UTbSame1SameEnum2InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTbSame1SameEnum2InterfaceMsgBusFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Prop1PropertyCb(ETbSame1Enum1 InProp1)
{
	ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_Value1;
	// use different test value
	TestValue = ETbSame1Enum1::TS1E1_Value2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame1SameEnum2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(ETbSame1Enum1 InProp1)
{
	ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_Value1;
	// use different test value
	TestValue = ETbSame1Enum1::TS1E1_Value2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame1SameEnum2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(ETbSame1Enum1 InProp1)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_Value1;
		// use different test value
		TestValue = ETbSame1Enum1::TS1E1_Value2;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTbSame1SameEnum2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = ETbSame1Enum1::TS1E1_Value1; // default value
		if (TSharedPtr<FTbSame1SameEnum2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp1(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_Value1; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTbSame1SameEnum2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Prop2PropertyCb(ETbSame1Enum2 InProp2)
{
	ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_Value1;
	// use different test value
	TestValue = ETbSame1Enum2::TS1E2_Value2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTbSame1SameEnum2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Prop2PropertyChangeLocalCheckRemoteCb(ETbSame1Enum2 InProp2)
{
	ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_Value1;
	// use different test value
	TestValue = ETbSame1Enum2::TS1E2_Value2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTbSame1SameEnum2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Prop2PropertyChangeLocalChangeRemoteCb(ETbSame1Enum2 InProp2)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_Value1;
		// use different test value
		TestValue = ETbSame1Enum2::TS1E2_Value2;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
		if (TSharedPtr<FTbSame1SameEnum2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = ETbSame1Enum2::TS1E2_Value1; // default value
		if (TSharedPtr<FTbSame1SameEnum2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp2(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_Value1; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
		if (TSharedPtr<FTbSame1SameEnum2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Sig1SignalCb(ETbSame1Enum1 InParam1)
{
	// known test value
	ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_Value2;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Sig2SignalCb(ETbSame1Enum1 InParam1, ETbSame1Enum2 InParam2)
{
	// known test value
	ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_Value2;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	ETbSame1Enum2 Param2TestValue = ETbSame1Enum2::TS1E2_Value2;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

FTbSame1SameEnum2InterfaceMsgBusFixture::FTbSame1SameEnum2InterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSame1SameEnum2InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceMsgBusClient>();
}

FTbSame1SameEnum2InterfaceMsgBusFixture::~FTbSame1SameEnum2InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> FTbSame1SameEnum2InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame1SameEnum2InterfaceMsgBusAdapter* FTbSame1SameEnum2InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSame1SameEnum2InterfaceMsgBusHelper> FTbSame1SameEnum2InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame1SameEnum2InterfaceMsgBusFixture::GetGameInstance()
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

void FTbSame1SameEnum2InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTbSame1SameEnum2InterfaceMsgBusHelper::~UTbSame1SameEnum2InterfaceMsgBusHelper()
{
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTbSame1SameEnum2InterfaceMsgBusFixture> /*InFixture*/)
{
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Prop1PropertyCb(ETbSame1Enum1 InProp1)
{
	(void)InProp1;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(ETbSame1Enum1 InProp1)
{
	(void)InProp1;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(ETbSame1Enum1 InProp1)
{
	(void)InProp1;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Prop2PropertyCb(ETbSame1Enum2 InProp2)
{
	(void)InProp2;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Prop2PropertyChangeLocalCheckRemoteCb(ETbSame1Enum2 InProp2)
{
	(void)InProp2;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Prop2PropertyChangeLocalChangeRemoteCb(ETbSame1Enum2 InProp2)
{
	(void)InProp2;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Sig1SignalCb(ETbSame1Enum1 Param1)
{
	(void)Param1;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Sig2SignalCb(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
