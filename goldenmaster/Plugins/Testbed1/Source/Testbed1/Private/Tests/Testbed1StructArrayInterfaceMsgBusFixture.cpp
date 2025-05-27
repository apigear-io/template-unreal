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
#include "Testbed1StructArrayInterfaceMsgBusFixture.h"
#include "Testbed1TestsCommon.h"
#include "Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusClient.h"
#include "Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTestbed1StructArrayInterfaceMsgBusHelper::~UTestbed1StructArrayInterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTestbed1StructArrayInterfaceMsgBusFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropBoolPropertyCb(const TArray<FTestbed1StructBool>& InPropBool)
{
	TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
	// use different test value
	TestValue = createTestFTestbed1StructBoolArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructBool>& InPropBool)
{
	TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
	// use different test value
	TestValue = createTestFTestbed1StructBoolArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructBool>& InPropBool)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
		// use different test value
		TestValue = createTestFTestbed1StructBoolArray();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
		if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<FTestbed1StructBool>(); // default value
		if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropBool(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
		if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropIntPropertyCb(const TArray<FTestbed1StructInt>& InPropInt)
{
	TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
	// use different test value
	TestValue = createTestFTestbed1StructIntArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropIntPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructInt>& InPropInt)
{
	TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
	// use different test value
	TestValue = createTestFTestbed1StructIntArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropIntPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructInt>& InPropInt)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
		// use different test value
		TestValue = createTestFTestbed1StructIntArray();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<FTestbed1StructInt>(); // default value
		if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropInt(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropFloatPropertyCb(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
	// use different test value
	TestValue = createTestFTestbed1StructFloatArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
	// use different test value
	TestValue = createTestFTestbed1StructFloatArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
		// use different test value
		TestValue = createTestFTestbed1StructFloatArray();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
		if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<FTestbed1StructFloat>(); // default value
		if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropFloat(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
		if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropStringPropertyCb(const TArray<FTestbed1StructString>& InPropString)
{
	TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
	// use different test value
	TestValue = createTestFTestbed1StructStringArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropStringPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructString>& InPropString)
{
	TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
	// use different test value
	TestValue = createTestFTestbed1StructStringArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropStringPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructString>& InPropString)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
		// use different test value
		TestValue = createTestFTestbed1StructStringArray();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
		if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<FTestbed1StructString>(); // default value
		if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropString(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
		if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropEnumPropertyCb(const TArray<ETestbed1Enum0>& InPropEnum)
{
	TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
	// use different test value
	TestValue.Add(ETestbed1Enum0::T1E0_Value1);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropEnum(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropEnumPropertyChangeLocalCheckRemoteCb(const TArray<ETestbed1Enum0>& InPropEnum)
{
	TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
	// use different test value
	TestValue.Add(ETestbed1Enum0::T1E0_Value1);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropEnum(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropEnumPropertyChangeLocalChangeRemoteCb(const TArray<ETestbed1Enum0>& InPropEnum)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
		// use different test value
		TestValue.Add(ETestbed1Enum0::T1E0_Value1);
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
		if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropEnum(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<ETestbed1Enum0>(); // default value
		if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropEnum(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
		if (TSharedPtr<FTestbed1StructArrayInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropEnum(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigBoolSignalCb(const TArray<FTestbed1StructBool>& InParamBool)
{
	// known test value
	TArray<FTestbed1StructBool> ParamBoolTestValue = createTestFTestbed1StructBoolArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigIntSignalCb(const TArray<FTestbed1StructInt>& InParamInt)
{
	// known test value
	TArray<FTestbed1StructInt> ParamIntTestValue = createTestFTestbed1StructIntArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigFloatSignalCb(const TArray<FTestbed1StructFloat>& InParamFloat)
{
	// known test value
	TArray<FTestbed1StructFloat> ParamFloatTestValue = createTestFTestbed1StructFloatArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigStringSignalCb(const TArray<FTestbed1StructString>& InParamString)
{
	// known test value
	TArray<FTestbed1StructString> ParamStringTestValue = createTestFTestbed1StructStringArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigEnumSignalCb(const TArray<ETestbed1Enum0>& InParamEnum)
{
	// known test value
	TArray<ETestbed1Enum0> ParamEnumTestValue = TArray<ETestbed1Enum0>(); // default value
	ParamEnumTestValue.Add(ETestbed1Enum0::T1E0_Value1);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamEnum, ParamEnumTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

FTestbed1StructArrayInterfaceMsgBusFixture::FTestbed1StructArrayInterfaceMsgBusFixture()
{
	Helper = NewObject<UTestbed1StructArrayInterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceMsgBusClient>();
}

FTestbed1StructArrayInterfaceMsgBusFixture::~FTestbed1StructArrayInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> FTestbed1StructArrayInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed1StructArrayInterfaceMsgBusAdapter* FTestbed1StructArrayInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTestbed1StructArrayInterfaceMsgBusHelper> FTestbed1StructArrayInterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed1StructArrayInterfaceMsgBusFixture::GetGameInstance()
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

void FTestbed1StructArrayInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTestbed1StructArrayInterfaceMsgBusHelper::~UTestbed1StructArrayInterfaceMsgBusHelper()
{
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTestbed1StructArrayInterfaceMsgBusFixture> /*InFixture*/)
{
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropBoolPropertyCb(const TArray<FTestbed1StructBool>& InPropBool)
{
	(void)InPropBool;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructBool>& InPropBool)
{
	(void)InPropBool;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructBool>& InPropBool)
{
	(void)InPropBool;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropIntPropertyCb(const TArray<FTestbed1StructInt>& InPropInt)
{
	(void)InPropInt;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropIntPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructInt>& InPropInt)
{
	(void)InPropInt;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropIntPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructInt>& InPropInt)
{
	(void)InPropInt;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropFloatPropertyCb(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	(void)InPropFloat;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	(void)InPropFloat;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	(void)InPropFloat;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropStringPropertyCb(const TArray<FTestbed1StructString>& InPropString)
{
	(void)InPropString;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropStringPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructString>& InPropString)
{
	(void)InPropString;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropStringPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructString>& InPropString)
{
	(void)InPropString;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropEnumPropertyCb(const TArray<ETestbed1Enum0>& InPropEnum)
{
	(void)InPropEnum;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropEnumPropertyChangeLocalCheckRemoteCb(const TArray<ETestbed1Enum0>& InPropEnum)
{
	(void)InPropEnum;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropEnumPropertyChangeLocalChangeRemoteCb(const TArray<ETestbed1Enum0>& InPropEnum)
{
	(void)InPropEnum;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigBoolSignalCb(const TArray<FTestbed1StructBool>& ParamBool)
{
	(void)ParamBool;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigIntSignalCb(const TArray<FTestbed1StructInt>& ParamInt)
{
	(void)ParamInt;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigFloatSignalCb(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	(void)ParamFloat;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigStringSignalCb(const TArray<FTestbed1StructString>& ParamString)
{
	(void)ParamString;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigEnumSignalCb(const TArray<ETestbed1Enum0>& ParamEnum)
{
	(void)ParamEnum;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
