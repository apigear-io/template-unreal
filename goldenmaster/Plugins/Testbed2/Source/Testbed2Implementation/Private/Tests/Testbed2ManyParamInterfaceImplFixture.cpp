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
#include "Testbed2ManyParamInterfaceImplFixture.h"
#include "Testbed2/Implementation/Testbed2ManyParamInterface.h"
#include "Testbed2/Tests/Testbed2TestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed2ManyParamInterfaceImplHelper::SetParentFixture(TWeakPtr<FTestbed2ManyParamInterfaceImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTestbed2ManyParamInterfaceImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTestbed2ManyParamInterfaceImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTestbed2ManyParamInterfaceImplHelper::Prop1PropertyCb(int32 InProp1)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetProp1(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceImplHelper::Prop2PropertyCb(int32 InProp2)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetProp2(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceImplHelper::Prop3PropertyCb(int32 InProp3)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetProp3(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceImplHelper::Prop4PropertyCb(int32 InProp4)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
	if (TSharedPtr<FTestbed2ManyParamInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetProp4(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceImplHelper::Sig1SignalCb(int32 InParam1)
{
	// known test value
	int32 Param1TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceImplHelper::Sig2SignalCb(int32 InParam1, int32 InParam2)
{
	// known test value
	int32 Param1TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	int32 Param2TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceImplHelper::Sig3SignalCb(int32 InParam1, int32 InParam2, int32 InParam3)
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

void UTestbed2ManyParamInterfaceImplHelper::Sig4SignalCb(int32 InParam1, int32 InParam2, int32 InParam3, int32 InParam4)
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

FTestbed2ManyParamInterfaceImplFixture::FTestbed2ManyParamInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceImplementation>();
	Helper = NewObject<UTestbed2ManyParamInterfaceImplHelper>();
}

FTestbed2ManyParamInterfaceImplFixture::~FTestbed2ManyParamInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> FTestbed2ManyParamInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTestbed2ManyParamInterfaceImplHelper> FTestbed2ManyParamInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed2ManyParamInterfaceImplFixture::GetGameInstance()
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

void FTestbed2ManyParamInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTestbed2ManyParamInterfaceImplHelper::SetParentFixture(TWeakPtr<FTestbed2ManyParamInterfaceImplFixture> /*InFixture*/)
{
}

void UTestbed2ManyParamInterfaceImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTestbed2ManyParamInterfaceImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTestbed2ManyParamInterfaceImplHelper::Prop1PropertyCb(int32 Prop1)
{
	(void)Prop1;
}

void UTestbed2ManyParamInterfaceImplHelper::Prop2PropertyCb(int32 Prop2)
{
	(void)Prop2;
}

void UTestbed2ManyParamInterfaceImplHelper::Prop3PropertyCb(int32 Prop3)
{
	(void)Prop3;
}

void UTestbed2ManyParamInterfaceImplHelper::Prop4PropertyCb(int32 Prop4)
{
	(void)Prop4;
}

void UTestbed2ManyParamInterfaceImplHelper::Sig1SignalCb(int32 Param1)
{
	(void)Param1;
}

void UTestbed2ManyParamInterfaceImplHelper::Sig2SignalCb(int32 Param1, int32 Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTestbed2ManyParamInterfaceImplHelper::Sig3SignalCb(int32 Param1, int32 Param2, int32 Param3)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
}

void UTestbed2ManyParamInterfaceImplHelper::Sig4SignalCb(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
	(void)Param4;
}
#endif // WITH_DEV_AUTOMATION_TESTS
