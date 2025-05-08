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
#include "Testbed1StructInterfaceOLinkFixture.h"
#include "Testbed1TestsCommon.h"
#include "OLinkCommon.h"
#include "Generated/OLink/Testbed1StructInterfaceOLinkClient.h"
#include "Generated/OLink/Testbed1StructInterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTestbed1StructInterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTestbed1StructInterfaceOLinkFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTestbed1StructInterfaceOLinkHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTestbed1StructInterfaceOLinkHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTestbed1StructInterfaceOLinkHelper::PropBoolPropertyCb(const FTestbed1StructBool& InPropBool)
{
	FTestbed1StructBool TestValue = FTestbed1StructBool();
	// use different test value
	TestValue = createTestFTestbed1StructBool();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const FTestbed1StructBool& InPropBool)
{
	FTestbed1StructBool TestValue = FTestbed1StructBool();
	// use different test value
	TestValue = createTestFTestbed1StructBool();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const FTestbed1StructBool& InPropBool)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTestbed1StructBool TestValue = FTestbed1StructBool();
		// use different test value
		TestValue = createTestFTestbed1StructBool();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
		if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed1StructBool(); // default value
		if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropBool(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed1StructBool TestValue = FTestbed1StructBool(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
		if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructInterfaceOLinkHelper::PropIntPropertyCb(const FTestbed1StructInt& InPropInt)
{
	FTestbed1StructInt TestValue = FTestbed1StructInt();
	// use different test value
	TestValue = createTestFTestbed1StructInt();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb(const FTestbed1StructInt& InPropInt)
{
	FTestbed1StructInt TestValue = FTestbed1StructInt();
	// use different test value
	TestValue = createTestFTestbed1StructInt();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb(const FTestbed1StructInt& InPropInt)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTestbed1StructInt TestValue = FTestbed1StructInt();
		// use different test value
		TestValue = createTestFTestbed1StructInt();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed1StructInt(); // default value
		if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropInt(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed1StructInt TestValue = FTestbed1StructInt(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructInterfaceOLinkHelper::PropFloatPropertyCb(const FTestbed1StructFloat& InPropFloat)
{
	FTestbed1StructFloat TestValue = FTestbed1StructFloat();
	// use different test value
	TestValue = createTestFTestbed1StructFloat();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceOLinkHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const FTestbed1StructFloat& InPropFloat)
{
	FTestbed1StructFloat TestValue = FTestbed1StructFloat();
	// use different test value
	TestValue = createTestFTestbed1StructFloat();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceOLinkHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const FTestbed1StructFloat& InPropFloat)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTestbed1StructFloat TestValue = FTestbed1StructFloat();
		// use different test value
		TestValue = createTestFTestbed1StructFloat();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
		if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed1StructFloat(); // default value
		if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropFloat(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed1StructFloat TestValue = FTestbed1StructFloat(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
		if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropFloat(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructInterfaceOLinkHelper::PropStringPropertyCb(const FTestbed1StructString& InPropString)
{
	FTestbed1StructString TestValue = FTestbed1StructString();
	// use different test value
	TestValue = createTestFTestbed1StructString();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceOLinkHelper::PropStringPropertyChangeLocalCheckRemoteCb(const FTestbed1StructString& InPropString)
{
	FTestbed1StructString TestValue = FTestbed1StructString();
	// use different test value
	TestValue = createTestFTestbed1StructString();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceOLinkHelper::PropStringPropertyChangeLocalChangeRemoteCb(const FTestbed1StructString& InPropString)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTestbed1StructString TestValue = FTestbed1StructString();
		// use different test value
		TestValue = createTestFTestbed1StructString();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
		if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FTestbed1StructString(); // default value
		if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropString(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FTestbed1StructString TestValue = FTestbed1StructString(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
		if (TSharedPtr<FTestbed1StructInterfaceOLinkFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropString(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructInterfaceOLinkHelper::SigBoolSignalCb(const FTestbed1StructBool& InParamBool)
{
	// known test value
	FTestbed1StructBool ParamBoolTestValue = createTestFTestbed1StructBool();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceOLinkHelper::SigIntSignalCb(const FTestbed1StructInt& InParamInt)
{
	// known test value
	FTestbed1StructInt ParamIntTestValue = createTestFTestbed1StructInt();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceOLinkHelper::SigFloatSignalCb(const FTestbed1StructFloat& InParamFloat)
{
	// known test value
	FTestbed1StructFloat ParamFloatTestValue = createTestFTestbed1StructFloat();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceOLinkHelper::SigStringSignalCb(const FTestbed1StructString& InParamString)
{
	// known test value
	FTestbed1StructString ParamStringTestValue = createTestFTestbed1StructString();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

FTestbed1StructInterfaceOLinkFixture::FTestbed1StructInterfaceOLinkFixture()
{
	Helper = NewObject<UTestbed1StructInterfaceOLinkHelper>(GetTransientPackage());
	Helper->AddToRoot();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructInterfaceOLinkClient>();
}

FTestbed1StructInterfaceOLinkFixture::~FTestbed1StructInterfaceOLinkFixture()
{
	CleanUp();
	Helper->RemoveFromRoot();
}

TScriptInterface<ITestbed1StructInterfaceInterface> FTestbed1StructInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTestbed1StructInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTestbed1StructInterfaceOLinkAdapter* FTestbed1StructInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTestbed1StructInterfaceOLinkHelper> FTestbed1StructInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed1StructInterfaceOLinkFixture::GetGameInstance()
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

void FTestbed1StructInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTestbed1StructInterfaceOLinkHelper::SetParentFixture(TWeakPtr<FTestbed1StructInterfaceOLinkFixture> /*InFixture*/)
{
}

void UTestbed1StructInterfaceOLinkHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTestbed1StructInterfaceOLinkHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTestbed1StructInterfaceOLinkHelper::PropBoolPropertyCb(const FTestbed1StructBool& InPropBool)
{
	(void)InPropBool;
}

void UTestbed1StructInterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const FTestbed1StructBool& InPropBool)
{
	(void)InPropBool;
}

void UTestbed1StructInterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const FTestbed1StructBool& InPropBool)
{
	(void)InPropBool;
}

void UTestbed1StructInterfaceOLinkHelper::PropIntPropertyCb(const FTestbed1StructInt& InPropInt)
{
	(void)InPropInt;
}

void UTestbed1StructInterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb(const FTestbed1StructInt& InPropInt)
{
	(void)InPropInt;
}

void UTestbed1StructInterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb(const FTestbed1StructInt& InPropInt)
{
	(void)InPropInt;
}

void UTestbed1StructInterfaceOLinkHelper::PropFloatPropertyCb(const FTestbed1StructFloat& InPropFloat)
{
	(void)InPropFloat;
}

void UTestbed1StructInterfaceOLinkHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const FTestbed1StructFloat& InPropFloat)
{
	(void)InPropFloat;
}

void UTestbed1StructInterfaceOLinkHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const FTestbed1StructFloat& InPropFloat)
{
	(void)InPropFloat;
}

void UTestbed1StructInterfaceOLinkHelper::PropStringPropertyCb(const FTestbed1StructString& InPropString)
{
	(void)InPropString;
}

void UTestbed1StructInterfaceOLinkHelper::PropStringPropertyChangeLocalCheckRemoteCb(const FTestbed1StructString& InPropString)
{
	(void)InPropString;
}

void UTestbed1StructInterfaceOLinkHelper::PropStringPropertyChangeLocalChangeRemoteCb(const FTestbed1StructString& InPropString)
{
	(void)InPropString;
}

void UTestbed1StructInterfaceOLinkHelper::SigBoolSignalCb(const FTestbed1StructBool& ParamBool)
{
	(void)ParamBool;
}

void UTestbed1StructInterfaceOLinkHelper::SigIntSignalCb(const FTestbed1StructInt& ParamInt)
{
	(void)ParamInt;
}

void UTestbed1StructInterfaceOLinkHelper::SigFloatSignalCb(const FTestbed1StructFloat& ParamFloat)
{
	(void)ParamFloat;
}

void UTestbed1StructInterfaceOLinkHelper::SigStringSignalCb(const FTestbed1StructString& ParamString)
{
	(void)ParamString;
}

void UTestbed1StructInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
