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
#include "Testbed2NestedStruct3InterfaceImplFixture.h"
#include "Testbed2/Implementation/Testbed2NestedStruct3Interface.h"
#include "Testbed2/Tests/Testbed2TestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed2NestedStruct3InterfaceImplHelper::SetParentFixture(TWeakPtr<FTestbed2NestedStruct3InterfaceImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTestbed2NestedStruct3InterfaceImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTestbed2NestedStruct3InterfaceImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTestbed2NestedStruct3InterfaceImplHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& InProp1)
{
	FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct1();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTestbed2NestedStruct3InterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetProp1(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceImplHelper::Prop2PropertyCb(const FTestbed2NestedStruct2& InProp2)
{
	FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct2();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTestbed2NestedStruct3InterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetProp2(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceImplHelper::Prop3PropertyCb(const FTestbed2NestedStruct3& InProp3)
{
	FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct3();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
	if (TSharedPtr<FTestbed2NestedStruct3InterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetProp3(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceImplHelper::Sig1SignalCb(const FTestbed2NestedStruct1& InParam1)
{
	// known test value
	FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceImplHelper::Sig2SignalCb(const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2)
{
	// known test value
	FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceImplHelper::Sig3SignalCb(const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2, const FTestbed2NestedStruct3& InParam3)
{
	// known test value
	FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	FTestbed2NestedStruct3 Param3TestValue = createTestFTestbed2NestedStruct3();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
	testDoneDelegate.Execute();
}

FTestbed2NestedStruct3InterfaceImplFixture::FTestbed2NestedStruct3InterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2NestedStruct3Interface>();
	Helper = NewObject<UTestbed2NestedStruct3InterfaceImplHelper>();
}

FTestbed2NestedStruct3InterfaceImplFixture::~FTestbed2NestedStruct3InterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> FTestbed2NestedStruct3InterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTestbed2NestedStruct3InterfaceImplHelper> FTestbed2NestedStruct3InterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed2NestedStruct3InterfaceImplFixture::GetGameInstance()
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

void FTestbed2NestedStruct3InterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTestbed2NestedStruct3InterfaceImplHelper::SetParentFixture(TWeakPtr<FTestbed2NestedStruct3InterfaceImplFixture> /*InFixture*/)
{
}

void UTestbed2NestedStruct3InterfaceImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTestbed2NestedStruct3InterfaceImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTestbed2NestedStruct3InterfaceImplHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1)
{
	(void)Prop1;
}

void UTestbed2NestedStruct3InterfaceImplHelper::Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2)
{
	(void)Prop2;
}

void UTestbed2NestedStruct3InterfaceImplHelper::Prop3PropertyCb(const FTestbed2NestedStruct3& Prop3)
{
	(void)Prop3;
}

void UTestbed2NestedStruct3InterfaceImplHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
}

void UTestbed2NestedStruct3InterfaceImplHelper::Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTestbed2NestedStruct3InterfaceImplHelper::Sig3SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
}
#endif // WITH_DEV_AUTOMATION_TESTS
