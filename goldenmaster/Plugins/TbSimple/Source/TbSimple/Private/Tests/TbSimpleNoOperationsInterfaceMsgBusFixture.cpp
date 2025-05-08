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
#include "TbSimpleNoOperationsInterfaceMsgBusFixture.h"
#include "TbSimpleTestsCommon.h"
#include "Generated/MsgBus/TbSimpleNoOperationsInterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSimpleNoOperationsInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTbSimpleNoOperationsInterfaceMsgBusHelper::~UTbSimpleNoOperationsInterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTbSimpleNoOperationsInterfaceMsgBusFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropBoolPropertyCb(bool bInPropBool)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
	if (TSharedPtr<FTbSimpleNoOperationsInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropBoolPropertyChangeLocalCheckRemoteCb(bool bInPropBool)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
	if (TSharedPtr<FTbSimpleNoOperationsInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropBoolPropertyChangeLocalChangeRemoteCb(bool bInPropBool)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		bool TestValue = false;
		// use different test value
		TestValue = true;
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
		if (TSharedPtr<FTbSimpleNoOperationsInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = false; // default value
		if (TSharedPtr<FTbSimpleNoOperationsInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropBool(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		bool TestValue = false; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
		if (TSharedPtr<FTbSimpleNoOperationsInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropBool(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropIntPropertyCb(int32 InPropInt)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTbSimpleNoOperationsInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropIntPropertyChangeLocalCheckRemoteCb(int32 InPropInt)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTbSimpleNoOperationsInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropIntPropertyChangeLocalChangeRemoteCb(int32 InPropInt)
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
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		if (TSharedPtr<FTbSimpleNoOperationsInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = 0; // default value
		if (TSharedPtr<FTbSimpleNoOperationsInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetPropInt(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		int32 TestValue = 0; // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		if (TSharedPtr<FTbSimpleNoOperationsInterfaceMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetPropInt(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::SigVoidSignalCb()
{
	// known test value
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::SigBoolSignalCb(bool bInParamBool)
{
	// known test value
	bool bParamBoolTestValue = true;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

FTbSimpleNoOperationsInterfaceMsgBusFixture::FTbSimpleNoOperationsInterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSimpleNoOperationsInterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterfaceMsgBusClient>();
}

FTbSimpleNoOperationsInterfaceMsgBusFixture::~FTbSimpleNoOperationsInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> FTbSimpleNoOperationsInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSimpleNoOperationsInterfaceMsgBusAdapter* FTbSimpleNoOperationsInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSimpleNoOperationsInterfaceMsgBusHelper> FTbSimpleNoOperationsInterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleNoOperationsInterfaceMsgBusFixture::GetGameInstance()
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

void FTbSimpleNoOperationsInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTbSimpleNoOperationsInterfaceMsgBusHelper::~UTbSimpleNoOperationsInterfaceMsgBusHelper()
{
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::SetParentFixture(TWeakPtr<FTbSimpleNoOperationsInterfaceMsgBusFixture> /*InFixture*/)
{
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropBoolPropertyCb(bool bInPropBool)
{
	(void)bInPropBool;
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropBoolPropertyChangeLocalCheckRemoteCb(bool bInPropBool)
{
	(void)bInPropBool;
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropBoolPropertyChangeLocalChangeRemoteCb(bool bInPropBool)
{
	(void)bInPropBool;
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropIntPropertyCb(int32 InPropInt)
{
	(void)InPropInt;
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropIntPropertyChangeLocalCheckRemoteCb(int32 InPropInt)
{
	(void)InPropInt;
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropIntPropertyChangeLocalChangeRemoteCb(int32 InPropInt)
{
	(void)InPropInt;
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::SigVoidSignalCb()
{
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::SigBoolSignalCb(bool bParamBool)
{
	(void)bParamBool;
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
