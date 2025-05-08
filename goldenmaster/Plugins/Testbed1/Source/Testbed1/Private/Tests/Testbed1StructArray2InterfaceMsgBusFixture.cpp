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
#include "Testbed1StructArray2InterfaceMsgBusFixture.h"
#include "Testbed1TestsCommon.h"
#include "Generated/MsgBus/Testbed1StructArray2InterfaceMsgBusClient.h"
#include "Generated/MsgBus/Testbed1StructArray2InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTestbed1StructArray2InterfaceMsgBusHelper::~UTestbed1StructArray2InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTestbed1StructArray2InterfaceMsgBusFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropBoolPropertyCb(const FTestbed1StructBoolWithArray& InPropBool)
{
	FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructBoolWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const FTestbed1StructBoolWithArray& InPropBool)
{
	FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructBoolWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const FTestbed1StructBoolWithArray& InPropBool)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray();
		// use different test value
		TestValue = createTestFTestbed1StructBoolWithArray();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
		if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed1StructBoolWithArray(); // default value
		if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropBool(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
		if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropIntPropertyCb(const FTestbed1StructIntWithArray& InPropInt)
{
	FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructIntWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropIntPropertyChangeLocalCheckRemoteCb(const FTestbed1StructIntWithArray& InPropInt)
{
	FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructIntWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropIntPropertyChangeLocalChangeRemoteCb(const FTestbed1StructIntWithArray& InPropInt)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray();
		// use different test value
		TestValue = createTestFTestbed1StructIntWithArray();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed1StructIntWithArray(); // default value
		if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropInt(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropFloatPropertyCb(const FTestbed1StructFloatWithArray& InPropFloat)
{
	FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructFloatWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const FTestbed1StructFloatWithArray& InPropFloat)
{
	FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructFloatWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const FTestbed1StructFloatWithArray& InPropFloat)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray();
		// use different test value
		TestValue = createTestFTestbed1StructFloatWithArray();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
		if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed1StructFloatWithArray(); // default value
		if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropFloat(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
		if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropStringPropertyCb(const FTestbed1StructStringWithArray& InPropString)
{
	FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructStringWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropStringPropertyChangeLocalCheckRemoteCb(const FTestbed1StructStringWithArray& InPropString)
{
	FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructStringWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropStringPropertyChangeLocalChangeRemoteCb(const FTestbed1StructStringWithArray& InPropString)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray();
		// use different test value
		TestValue = createTestFTestbed1StructStringWithArray();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
		if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed1StructStringWithArray(); // default value
		if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropString(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
		if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropEnumPropertyCb(const FTestbed1StructEnumWithArray& InPropEnum)
{
	FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructEnumWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropEnum(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropEnumPropertyChangeLocalCheckRemoteCb(const FTestbed1StructEnumWithArray& InPropEnum)
{
	FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructEnumWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropEnum(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropEnumPropertyChangeLocalChangeRemoteCb(const FTestbed1StructEnumWithArray& InPropEnum)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray();
		// use different test value
		TestValue = createTestFTestbed1StructEnumWithArray();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
		if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropEnum(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed1StructEnumWithArray(); // default value
		if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropEnum(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
		if (TSharedPtr<FTestbed1StructArray2InterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropEnum(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SigBoolSignalCb(const FTestbed1StructBoolWithArray& InParamBool)
{
	// known test value
	FTestbed1StructBoolWithArray ParamBoolTestValue = createTestFTestbed1StructBoolWithArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SigIntSignalCb(const FTestbed1StructIntWithArray& InParamInt)
{
	// known test value
	FTestbed1StructIntWithArray ParamIntTestValue = createTestFTestbed1StructIntWithArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SigFloatSignalCb(const FTestbed1StructFloatWithArray& InParamFloat)
{
	// known test value
	FTestbed1StructFloatWithArray ParamFloatTestValue = createTestFTestbed1StructFloatWithArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SigStringSignalCb(const FTestbed1StructStringWithArray& InParamString)
{
	// known test value
	FTestbed1StructStringWithArray ParamStringTestValue = createTestFTestbed1StructStringWithArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

FTestbed1StructArray2InterfaceMsgBusFixture::FTestbed1StructArray2InterfaceMsgBusFixture()
{
	Helper = NewObject<UTestbed1StructArray2InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceMsgBusClient>();
}

FTestbed1StructArray2InterfaceMsgBusFixture::~FTestbed1StructArray2InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructArray2InterfaceInterface> FTestbed1StructArray2InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed1StructArray2InterfaceMsgBusAdapter* FTestbed1StructArray2InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTestbed1StructArray2InterfaceMsgBusHelper> FTestbed1StructArray2InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed1StructArray2InterfaceMsgBusFixture::GetGameInstance()
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

void FTestbed1StructArray2InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTestbed1StructArray2InterfaceMsgBusHelper::~UTestbed1StructArray2InterfaceMsgBusHelper()
{
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTestbed1StructArray2InterfaceMsgBusFixture> /*InFixture*/)
{
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropBoolPropertyCb(const FTestbed1StructBoolWithArray& InPropBool)
{
	(void)InPropBool;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const FTestbed1StructBoolWithArray& InPropBool)
{
	(void)InPropBool;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const FTestbed1StructBoolWithArray& InPropBool)
{
	(void)InPropBool;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropIntPropertyCb(const FTestbed1StructIntWithArray& InPropInt)
{
	(void)InPropInt;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropIntPropertyChangeLocalCheckRemoteCb(const FTestbed1StructIntWithArray& InPropInt)
{
	(void)InPropInt;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropIntPropertyChangeLocalChangeRemoteCb(const FTestbed1StructIntWithArray& InPropInt)
{
	(void)InPropInt;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropFloatPropertyCb(const FTestbed1StructFloatWithArray& InPropFloat)
{
	(void)InPropFloat;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const FTestbed1StructFloatWithArray& InPropFloat)
{
	(void)InPropFloat;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const FTestbed1StructFloatWithArray& InPropFloat)
{
	(void)InPropFloat;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropStringPropertyCb(const FTestbed1StructStringWithArray& InPropString)
{
	(void)InPropString;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropStringPropertyChangeLocalCheckRemoteCb(const FTestbed1StructStringWithArray& InPropString)
{
	(void)InPropString;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropStringPropertyChangeLocalChangeRemoteCb(const FTestbed1StructStringWithArray& InPropString)
{
	(void)InPropString;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropEnumPropertyCb(const FTestbed1StructEnumWithArray& InPropEnum)
{
	(void)InPropEnum;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropEnumPropertyChangeLocalCheckRemoteCb(const FTestbed1StructEnumWithArray& InPropEnum)
{
	(void)InPropEnum;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropEnumPropertyChangeLocalChangeRemoteCb(const FTestbed1StructEnumWithArray& InPropEnum)
{
	(void)InPropEnum;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SigBoolSignalCb(const FTestbed1StructBoolWithArray& ParamBool)
{
	(void)ParamBool;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SigIntSignalCb(const FTestbed1StructIntWithArray& ParamInt)
{
	(void)ParamInt;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SigFloatSignalCb(const FTestbed1StructFloatWithArray& ParamFloat)
{
	(void)ParamFloat;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SigStringSignalCb(const FTestbed1StructStringWithArray& ParamString)
{
	(void)ParamString;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
