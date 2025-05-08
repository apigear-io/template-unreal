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
#include "Testbed1StructArray2InterfaceImplFixture.h"
#include "Testbed1/Implementation/Testbed1StructArray2Interface.h"
#include "Testbed1/Tests/Testbed1TestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed1StructArray2InterfaceImplHelper::SetParentFixture(TWeakPtr<FTestbed1StructArray2InterfaceImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTestbed1StructArray2InterfaceImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTestbed1StructArray2InterfaceImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTestbed1StructArray2InterfaceImplHelper::PropBoolPropertyCb(const FTestbed1StructBoolWithArray& InPropBool)
{
	FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructBoolWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropBool(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceImplHelper::PropIntPropertyCb(const FTestbed1StructIntWithArray& InPropInt)
{
	FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructIntWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropInt(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceImplHelper::PropFloatPropertyCb(const FTestbed1StructFloatWithArray& InPropFloat)
{
	FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructFloatWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropFloat(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceImplHelper::PropStringPropertyCb(const FTestbed1StructStringWithArray& InPropString)
{
	FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructStringWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropString(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceImplHelper::PropEnumPropertyCb(const FTestbed1StructEnumWithArray& InPropEnum)
{
	FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructEnumWithArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
	if (TSharedPtr<FTestbed1StructArray2InterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropEnum(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceImplHelper::SigBoolSignalCb(const FTestbed1StructBoolWithArray& InParamBool)
{
	// known test value
	FTestbed1StructBoolWithArray ParamBoolTestValue = createTestFTestbed1StructBoolWithArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceImplHelper::SigIntSignalCb(const FTestbed1StructIntWithArray& InParamInt)
{
	// known test value
	FTestbed1StructIntWithArray ParamIntTestValue = createTestFTestbed1StructIntWithArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceImplHelper::SigFloatSignalCb(const FTestbed1StructFloatWithArray& InParamFloat)
{
	// known test value
	FTestbed1StructFloatWithArray ParamFloatTestValue = createTestFTestbed1StructFloatWithArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceImplHelper::SigStringSignalCb(const FTestbed1StructStringWithArray& InParamString)
{
	// known test value
	FTestbed1StructStringWithArray ParamStringTestValue = createTestFTestbed1StructStringWithArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}

FTestbed1StructArray2InterfaceImplFixture::FTestbed1StructArray2InterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructArray2Interface>();
	Helper = NewObject<UTestbed1StructArray2InterfaceImplHelper>();
}

FTestbed1StructArray2InterfaceImplFixture::~FTestbed1StructArray2InterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructArray2InterfaceInterface> FTestbed1StructArray2InterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTestbed1StructArray2InterfaceImplHelper> FTestbed1StructArray2InterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed1StructArray2InterfaceImplFixture::GetGameInstance()
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

void FTestbed1StructArray2InterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTestbed1StructArray2InterfaceImplHelper::SetParentFixture(TWeakPtr<FTestbed1StructArray2InterfaceImplFixture> /*InFixture*/)
{
}

void UTestbed1StructArray2InterfaceImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTestbed1StructArray2InterfaceImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTestbed1StructArray2InterfaceImplHelper::PropBoolPropertyCb(const FTestbed1StructBoolWithArray& PropBool)
{
	(void)PropBool;
}

void UTestbed1StructArray2InterfaceImplHelper::PropIntPropertyCb(const FTestbed1StructIntWithArray& PropInt)
{
	(void)PropInt;
}

void UTestbed1StructArray2InterfaceImplHelper::PropFloatPropertyCb(const FTestbed1StructFloatWithArray& PropFloat)
{
	(void)PropFloat;
}

void UTestbed1StructArray2InterfaceImplHelper::PropStringPropertyCb(const FTestbed1StructStringWithArray& PropString)
{
	(void)PropString;
}

void UTestbed1StructArray2InterfaceImplHelper::PropEnumPropertyCb(const FTestbed1StructEnumWithArray& PropEnum)
{
	(void)PropEnum;
}

void UTestbed1StructArray2InterfaceImplHelper::SigBoolSignalCb(const FTestbed1StructBoolWithArray& ParamBool)
{
	(void)ParamBool;
}

void UTestbed1StructArray2InterfaceImplHelper::SigIntSignalCb(const FTestbed1StructIntWithArray& ParamInt)
{
	(void)ParamInt;
}

void UTestbed1StructArray2InterfaceImplHelper::SigFloatSignalCb(const FTestbed1StructFloatWithArray& ParamFloat)
{
	(void)ParamFloat;
}

void UTestbed1StructArray2InterfaceImplHelper::SigStringSignalCb(const FTestbed1StructStringWithArray& ParamString)
{
	(void)ParamString;
}
#endif // WITH_DEV_AUTOMATION_TESTS
