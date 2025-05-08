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
#include "Testbed1StructArrayInterfaceOLinkFixture.h"
#include "Testbed1TestsCommon.h"
#include "OLinkCommon.h"
#include "Generated/OLink/Testbed1StructArrayInterfaceOLinkClient.h"
#include "Generated/OLink/Testbed1StructArrayInterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTestbed1StructArrayInterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTestbed1StructArrayInterfaceOLinkFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTestbed1StructArrayInterfaceOLinkHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTestbed1StructArrayInterfaceOLinkHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropBoolPropertyCb(const TArray<FTestbed1StructBool>& InPropBool)
{
	TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
	// use different test value
	TestValue = createTestFTestbed1StructBoolArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructBool>& InPropBool)
{
	TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
	// use different test value
	TestValue = createTestFTestbed1StructBoolArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructBool>& InPropBool)
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
		if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<FTestbed1StructBool>(); // default value
		if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropBool(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
		if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropIntPropertyCb(const TArray<FTestbed1StructInt>& InPropInt)
{
	TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
	// use different test value
	TestValue = createTestFTestbed1StructIntArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructInt>& InPropInt)
{
	TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
	// use different test value
	TestValue = createTestFTestbed1StructIntArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructInt>& InPropInt)
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
		if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<FTestbed1StructInt>(); // default value
		if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropInt(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropFloatPropertyCb(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
	// use different test value
	TestValue = createTestFTestbed1StructFloatArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
	// use different test value
	TestValue = createTestFTestbed1StructFloatArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructFloat>& InPropFloat)
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
		if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<FTestbed1StructFloat>(); // default value
		if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropFloat(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
		if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropStringPropertyCb(const TArray<FTestbed1StructString>& InPropString)
{
	TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
	// use different test value
	TestValue = createTestFTestbed1StructStringArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropStringPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructString>& InPropString)
{
	TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
	// use different test value
	TestValue = createTestFTestbed1StructStringArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropStringPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructString>& InPropString)
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
		if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<FTestbed1StructString>(); // default value
		if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropString(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
		if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropEnumPropertyCb(const TArray<ETestbed1Enum0>& InPropEnum)
{
	TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
	// use different test value
	TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropEnum(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropEnumPropertyChangeLocalCheckRemoteCb(const TArray<ETestbed1Enum0>& InPropEnum)
{
	TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
	// use different test value
	TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
	if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropEnum(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropEnumPropertyChangeLocalChangeRemoteCb(const TArray<ETestbed1Enum0>& InPropEnum)
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
		TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
		if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropEnum(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<ETestbed1Enum0>(); // default value
		if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropEnum(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
		if (TSharedPtr<FTestbed1StructArrayInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropEnum(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigBoolSignalCb(const TArray<FTestbed1StructBool>& InParamBool)
{
	// known test value
	TArray<FTestbed1StructBool> ParamBoolTestValue = createTestFTestbed1StructBoolArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigIntSignalCb(const TArray<FTestbed1StructInt>& InParamInt)
{
	// known test value
	TArray<FTestbed1StructInt> ParamIntTestValue = createTestFTestbed1StructIntArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigFloatSignalCb(const TArray<FTestbed1StructFloat>& InParamFloat)
{
	// known test value
	TArray<FTestbed1StructFloat> ParamFloatTestValue = createTestFTestbed1StructFloatArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigStringSignalCb(const TArray<FTestbed1StructString>& InParamString)
{
	// known test value
	TArray<FTestbed1StructString> ParamStringTestValue = createTestFTestbed1StructStringArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigEnumSignalCb(const TArray<ETestbed1Enum0>& InParamEnum)
{
	// known test value
	TArray<ETestbed1Enum0> ParamEnumTestValue = TArray<ETestbed1Enum0>(); // default value
	ParamEnumTestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamEnum, ParamEnumTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

FTestbed1StructArrayInterfaceOLinkFixture::FTestbed1StructArrayInterfaceOLinkFixture()
{
	Helper = NewObject<UTestbed1StructArrayInterfaceOLinkHelper>(GetTransientPackage());
	Helper->AddToRoot();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceOLinkClient>();
}

FTestbed1StructArrayInterfaceOLinkFixture::~FTestbed1StructArrayInterfaceOLinkFixture()
{
	CleanUp();
	Helper->RemoveFromRoot();
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> FTestbed1StructArrayInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTestbed1StructArrayInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTestbed1StructArrayInterfaceOLinkAdapter* FTestbed1StructArrayInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTestbed1StructArrayInterfaceOLinkHelper> FTestbed1StructArrayInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed1StructArrayInterfaceOLinkFixture::GetGameInstance()
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

void FTestbed1StructArrayInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTestbed1StructArrayInterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTestbed1StructArrayInterfaceOLinkFixture> /*InFixture*/)
{
}

void UTestbed1StructArrayInterfaceOLinkHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTestbed1StructArrayInterfaceOLinkHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropBoolPropertyCb(const TArray<FTestbed1StructBool>& InPropBool)
{
	(void)InPropBool;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructBool>& InPropBool)
{
	(void)InPropBool;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructBool>& InPropBool)
{
	(void)InPropBool;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropIntPropertyCb(const TArray<FTestbed1StructInt>& InPropInt)
{
	(void)InPropInt;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructInt>& InPropInt)
{
	(void)InPropInt;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructInt>& InPropInt)
{
	(void)InPropInt;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropFloatPropertyCb(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	(void)InPropFloat;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	(void)InPropFloat;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	(void)InPropFloat;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropStringPropertyCb(const TArray<FTestbed1StructString>& InPropString)
{
	(void)InPropString;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropStringPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructString>& InPropString)
{
	(void)InPropString;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropStringPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructString>& InPropString)
{
	(void)InPropString;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropEnumPropertyCb(const TArray<ETestbed1Enum0>& InPropEnum)
{
	(void)InPropEnum;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropEnumPropertyChangeLocalCheckRemoteCb(const TArray<ETestbed1Enum0>& InPropEnum)
{
	(void)InPropEnum;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropEnumPropertyChangeLocalChangeRemoteCb(const TArray<ETestbed1Enum0>& InPropEnum)
{
	(void)InPropEnum;
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigBoolSignalCb(const TArray<FTestbed1StructBool>& ParamBool)
{
	(void)ParamBool;
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigIntSignalCb(const TArray<FTestbed1StructInt>& ParamInt)
{
	(void)ParamInt;
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigFloatSignalCb(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	(void)ParamFloat;
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigStringSignalCb(const TArray<FTestbed1StructString>& ParamString)
{
	(void)ParamString;
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigEnumSignalCb(const TArray<ETestbed1Enum0>& ParamEnum)
{
	(void)ParamEnum;
}

void UTestbed1StructArrayInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
