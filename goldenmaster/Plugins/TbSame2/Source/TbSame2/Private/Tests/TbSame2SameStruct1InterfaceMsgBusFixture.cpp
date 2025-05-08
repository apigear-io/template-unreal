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
#include "TbSame2SameStruct1InterfaceMsgBusFixture.h"
#include "TbSame2TestsCommon.h"
#include "Generated/MsgBus/TbSame2SameStruct1InterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSame2SameStruct1InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTbSame2SameStruct1InterfaceMsgBusHelper::~UTbSame2SameStruct1InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTbSame2SameStruct1InterfaceMsgBusFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::Prop1PropertyCb(const FTbSame2Struct1& InProp1)
{
	FTbSame2Struct1 TestValue = FTbSame2Struct1();
	// use different test value
	TestValue = createTestFTbSame2Struct1();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame2SameStruct1InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTbSame2Struct1& InProp1)
{
	FTbSame2Struct1 TestValue = FTbSame2Struct1();
	// use different test value
	TestValue = createTestFTbSame2Struct1();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame2SameStruct1InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTbSame2Struct1& InProp1)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTbSame2Struct1 TestValue = FTbSame2Struct1();
		// use different test value
		TestValue = createTestFTbSame2Struct1();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTbSame2SameStruct1InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTbSame2Struct1(); // default value
		if (TSharedPtr<FTbSame2SameStruct1InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp1(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTbSame2Struct1 TestValue = FTbSame2Struct1(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTbSame2SameStruct1InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::Sig1SignalCb(const FTbSame2Struct1& InParam1)
{
	// known test value
	FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

FTbSame2SameStruct1InterfaceMsgBusFixture::FTbSame2SameStruct1InterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSame2SameStruct1InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameStruct1InterfaceMsgBusClient>();
}

FTbSame2SameStruct1InterfaceMsgBusFixture::~FTbSame2SameStruct1InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameStruct1InterfaceInterface> FTbSame2SameStruct1InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame2SameStruct1InterfaceMsgBusAdapter* FTbSame2SameStruct1InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameStruct1InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSame2SameStruct1InterfaceMsgBusHelper> FTbSame2SameStruct1InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame2SameStruct1InterfaceMsgBusFixture::GetGameInstance()
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

void FTbSame2SameStruct1InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTbSame2SameStruct1InterfaceMsgBusHelper::~UTbSame2SameStruct1InterfaceMsgBusHelper()
{
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTbSame2SameStruct1InterfaceMsgBusFixture> /*InFixture*/)
{
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::Prop1PropertyCb(const FTbSame2Struct1& InProp1)
{
	(void)InProp1;
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTbSame2Struct1& InProp1)
{
	(void)InProp1;
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTbSame2Struct1& InProp1)
{
	(void)InProp1;
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::Sig1SignalCb(const FTbSame2Struct1& Param1)
{
	(void)Param1;
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
