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
#include "TbSame2SameStruct2InterfaceMsgBusFixture.h"
#include "TbSame2TestsCommon.h"
#include "Generated/MsgBus/TbSame2SameStruct2InterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSame2SameStruct2InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTbSame2SameStruct2InterfaceMsgBusHelper::~UTbSame2SameStruct2InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTbSame2SameStruct2InterfaceMsgBusFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Prop1PropertyCb(const FTbSame2Struct2& InProp1)
{
	FTbSame2Struct2 TestValue = FTbSame2Struct2();
	// use different test value
	TestValue = createTestFTbSame2Struct2();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame2SameStruct2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTbSame2Struct2& InProp1)
{
	FTbSame2Struct2 TestValue = FTbSame2Struct2();
	// use different test value
	TestValue = createTestFTbSame2Struct2();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame2SameStruct2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTbSame2Struct2& InProp1)
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
		if (TSharedPtr<FTbSame2SameStruct2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTbSame2Struct2(); // default value
		if (TSharedPtr<FTbSame2SameStruct2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp1(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTbSame2Struct2 TestValue = FTbSame2Struct2(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		if (TSharedPtr<FTbSame2SameStruct2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Prop2PropertyCb(const FTbSame2Struct2& InProp2)
{
	FTbSame2Struct2 TestValue = FTbSame2Struct2();
	// use different test value
	TestValue = createTestFTbSame2Struct2();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTbSame2SameStruct2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Prop2PropertyChangeLocalCheckRemoteCb(const FTbSame2Struct2& InProp2)
{
	FTbSame2Struct2 TestValue = FTbSame2Struct2();
	// use different test value
	TestValue = createTestFTbSame2Struct2();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTbSame2SameStruct2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Prop2PropertyChangeLocalChangeRemoteCb(const FTbSame2Struct2& InProp2)
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
		if (TSharedPtr<FTbSame2SameStruct2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTbSame2Struct2(); // default value
		if (TSharedPtr<FTbSame2SameStruct2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetProp2(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTbSame2Struct2 TestValue = FTbSame2Struct2(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
		if (TSharedPtr<FTbSame2SameStruct2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Sig1SignalCb(const FTbSame2Struct1& InParam1)
{
	// known test value
	FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Sig2SignalCb(const FTbSame2Struct1& InParam1, const FTbSame2Struct2& InParam2)
{
	// known test value
	FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	FTbSame2Struct2 Param2TestValue = createTestFTbSame2Struct2();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

FTbSame2SameStruct2InterfaceMsgBusFixture::FTbSame2SameStruct2InterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSame2SameStruct2InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameStruct2InterfaceMsgBusClient>();
}

FTbSame2SameStruct2InterfaceMsgBusFixture::~FTbSame2SameStruct2InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> FTbSame2SameStruct2InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame2SameStruct2InterfaceMsgBusAdapter* FTbSame2SameStruct2InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameStruct2InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSame2SameStruct2InterfaceMsgBusHelper> FTbSame2SameStruct2InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame2SameStruct2InterfaceMsgBusFixture::GetGameInstance()
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

void FTbSame2SameStruct2InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTbSame2SameStruct2InterfaceMsgBusHelper::~UTbSame2SameStruct2InterfaceMsgBusHelper()
{
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTbSame2SameStruct2InterfaceMsgBusFixture> /*InFixture*/)
{
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Prop1PropertyCb(const FTbSame2Struct2& InProp1)
{
	(void)InProp1;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTbSame2Struct2& InProp1)
{
	(void)InProp1;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTbSame2Struct2& InProp1)
{
	(void)InProp1;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Prop2PropertyCb(const FTbSame2Struct2& InProp2)
{
	(void)InProp2;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Prop2PropertyChangeLocalCheckRemoteCb(const FTbSame2Struct2& InProp2)
{
	(void)InProp2;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Prop2PropertyChangeLocalChangeRemoteCb(const FTbSame2Struct2& InProp2)
{
	(void)InProp2;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Sig1SignalCb(const FTbSame2Struct1& Param1)
{
	(void)Param1;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Sig2SignalCb(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
