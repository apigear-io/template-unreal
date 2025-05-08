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
#include "Testbed1StructArray2InterfaceOLinkFixture.h"
#include "Testbed1TestsCommon.h"
#include "OLinkCommon.h"
#include "Generated/OLink/Testbed1StructArray2InterfaceOLinkClient.h"
#include "Generated/OLink/Testbed1StructArray2InterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTestbed1StructArray2InterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTestbed1StructArray2InterfaceOLinkFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTestbed1StructArray2InterfaceOLinkHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTestbed1StructArray2InterfaceOLinkHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropBoolPropertyCb(const FTestbed1StructBoolWithArray& InPropBool)
{
	FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructBoolWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const FTestbed1StructBoolWithArray& InPropBool)
{
	FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructBoolWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const FTestbed1StructBoolWithArray& InPropBool)
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
		if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed1StructBoolWithArray(); // default value
		if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropBool(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
		if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropIntPropertyCb(const FTestbed1StructIntWithArray& InPropInt)
{
	FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructIntWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb(const FTestbed1StructIntWithArray& InPropInt)
{
	FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructIntWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb(const FTestbed1StructIntWithArray& InPropInt)
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
		if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed1StructIntWithArray(); // default value
		if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropInt(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropFloatPropertyCb(const FTestbed1StructFloatWithArray& InPropFloat)
{
	FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructFloatWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const FTestbed1StructFloatWithArray& InPropFloat)
{
	FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructFloatWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const FTestbed1StructFloatWithArray& InPropFloat)
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
		if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed1StructFloatWithArray(); // default value
		if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropFloat(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
		if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropStringPropertyCb(const FTestbed1StructStringWithArray& InPropString)
{
	FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructStringWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropStringPropertyChangeLocalCheckRemoteCb(const FTestbed1StructStringWithArray& InPropString)
{
	FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructStringWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropStringPropertyChangeLocalChangeRemoteCb(const FTestbed1StructStringWithArray& InPropString)
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
		if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed1StructStringWithArray(); // default value
		if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropString(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
		if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropEnumPropertyCb(const FTestbed1StructEnumWithArray& InPropEnum)
{
	FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructEnumWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropEnum(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropEnumPropertyChangeLocalCheckRemoteCb(const FTestbed1StructEnumWithArray& InPropEnum)
{
	FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructEnumWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropEnum(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropEnumPropertyChangeLocalChangeRemoteCb(const FTestbed1StructEnumWithArray& InPropEnum)
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
		if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropEnum(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed1StructEnumWithArray(); // default value
		if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropEnum(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
		if (TSharedPtr<FTestbed1StructArray2InterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropEnum(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArray2InterfaceOLinkHelper::SigBoolSignalCb(const FTestbed1StructBoolWithArray& InParamBool)
{
	// known test value
	FTestbed1StructBoolWithArray ParamBoolTestValue = createTestFTestbed1StructBoolWithArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceOLinkHelper::SigIntSignalCb(const FTestbed1StructIntWithArray& InParamInt)
{
	// known test value
	FTestbed1StructIntWithArray ParamIntTestValue = createTestFTestbed1StructIntWithArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceOLinkHelper::SigFloatSignalCb(const FTestbed1StructFloatWithArray& InParamFloat)
{
	// known test value
	FTestbed1StructFloatWithArray ParamFloatTestValue = createTestFTestbed1StructFloatWithArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceOLinkHelper::SigStringSignalCb(const FTestbed1StructStringWithArray& InParamString)
{
	// known test value
	FTestbed1StructStringWithArray ParamStringTestValue = createTestFTestbed1StructStringWithArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

FTestbed1StructArray2InterfaceOLinkFixture::FTestbed1StructArray2InterfaceOLinkFixture()
{
	Helper = NewObject<UTestbed1StructArray2InterfaceOLinkHelper>(GetTransientPackage());
	Helper->AddToRoot();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceOLinkClient>();
}

FTestbed1StructArray2InterfaceOLinkFixture::~FTestbed1StructArray2InterfaceOLinkFixture()
{
	CleanUp();
	Helper->RemoveFromRoot();
}

TScriptInterface<ITestbed1StructArray2InterfaceInterface> FTestbed1StructArray2InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTestbed1StructArray2InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTestbed1StructArray2InterfaceOLinkAdapter* FTestbed1StructArray2InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTestbed1StructArray2InterfaceOLinkHelper> FTestbed1StructArray2InterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed1StructArray2InterfaceOLinkFixture::GetGameInstance()
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

void FTestbed1StructArray2InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTestbed1StructArray2InterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTestbed1StructArray2InterfaceOLinkFixture> /*InFixture*/)
{
}

void UTestbed1StructArray2InterfaceOLinkHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTestbed1StructArray2InterfaceOLinkHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropBoolPropertyCb(const FTestbed1StructBoolWithArray& InPropBool)
{
	(void)InPropBool;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const FTestbed1StructBoolWithArray& InPropBool)
{
	(void)InPropBool;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const FTestbed1StructBoolWithArray& InPropBool)
{
	(void)InPropBool;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropIntPropertyCb(const FTestbed1StructIntWithArray& InPropInt)
{
	(void)InPropInt;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb(const FTestbed1StructIntWithArray& InPropInt)
{
	(void)InPropInt;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb(const FTestbed1StructIntWithArray& InPropInt)
{
	(void)InPropInt;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropFloatPropertyCb(const FTestbed1StructFloatWithArray& InPropFloat)
{
	(void)InPropFloat;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const FTestbed1StructFloatWithArray& InPropFloat)
{
	(void)InPropFloat;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const FTestbed1StructFloatWithArray& InPropFloat)
{
	(void)InPropFloat;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropStringPropertyCb(const FTestbed1StructStringWithArray& InPropString)
{
	(void)InPropString;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropStringPropertyChangeLocalCheckRemoteCb(const FTestbed1StructStringWithArray& InPropString)
{
	(void)InPropString;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropStringPropertyChangeLocalChangeRemoteCb(const FTestbed1StructStringWithArray& InPropString)
{
	(void)InPropString;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropEnumPropertyCb(const FTestbed1StructEnumWithArray& InPropEnum)
{
	(void)InPropEnum;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropEnumPropertyChangeLocalCheckRemoteCb(const FTestbed1StructEnumWithArray& InPropEnum)
{
	(void)InPropEnum;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropEnumPropertyChangeLocalChangeRemoteCb(const FTestbed1StructEnumWithArray& InPropEnum)
{
	(void)InPropEnum;
}

void UTestbed1StructArray2InterfaceOLinkHelper::SigBoolSignalCb(const FTestbed1StructBoolWithArray& ParamBool)
{
	(void)ParamBool;
}

void UTestbed1StructArray2InterfaceOLinkHelper::SigIntSignalCb(const FTestbed1StructIntWithArray& ParamInt)
{
	(void)ParamInt;
}

void UTestbed1StructArray2InterfaceOLinkHelper::SigFloatSignalCb(const FTestbed1StructFloatWithArray& ParamFloat)
{
	(void)ParamFloat;
}

void UTestbed1StructArray2InterfaceOLinkHelper::SigStringSignalCb(const FTestbed1StructStringWithArray& ParamString)
{
	(void)ParamString;
}

void UTestbed1StructArray2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
