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
#include "Testbed1StructInterfaceImplFixture.h"
#include "Testbed1/Implementation/Testbed1StructInterface.h"
#include "Testbed1/Tests/Testbed1TestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed1StructInterfaceImplHelper::SetParentFixture(TWeakPtr<FTestbed1StructInterfaceImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTestbed1StructInterfaceImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTestbed1StructInterfaceImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTestbed1StructInterfaceImplHelper::PropBoolPropertyCb(const FTestbed1StructBool& InPropBool)
{
	FTestbed1StructBool TestValue = FTestbed1StructBool();
	// use different test value
	TestValue = createTestFTestbed1StructBool();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	if (TSharedPtr<FTestbed1StructInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropBool(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceImplHelper::PropIntPropertyCb(const FTestbed1StructInt& InPropInt)
{
	FTestbed1StructInt TestValue = FTestbed1StructInt();
	// use different test value
	TestValue = createTestFTestbed1StructInt();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTestbed1StructInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropInt(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceImplHelper::PropFloatPropertyCb(const FTestbed1StructFloat& InPropFloat)
{
	FTestbed1StructFloat TestValue = FTestbed1StructFloat();
	// use different test value
	TestValue = createTestFTestbed1StructFloat();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTestbed1StructInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropFloat(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceImplHelper::PropStringPropertyCb(const FTestbed1StructString& InPropString)
{
	FTestbed1StructString TestValue = FTestbed1StructString();
	// use different test value
	TestValue = createTestFTestbed1StructString();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTestbed1StructInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropString(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceImplHelper::SigBoolSignalCb(const FTestbed1StructBool& InParamBool)
{
	// known test value
	FTestbed1StructBool ParamBoolTestValue = createTestFTestbed1StructBool();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceImplHelper::SigIntSignalCb(const FTestbed1StructInt& InParamInt)
{
	// known test value
	FTestbed1StructInt ParamIntTestValue = createTestFTestbed1StructInt();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceImplHelper::SigFloatSignalCb(const FTestbed1StructFloat& InParamFloat)
{
	// known test value
	FTestbed1StructFloat ParamFloatTestValue = createTestFTestbed1StructFloat();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceImplHelper::SigStringSignalCb(const FTestbed1StructString& InParamString)
{
	// known test value
	FTestbed1StructString ParamStringTestValue = createTestFTestbed1StructString();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}

FTestbed1StructInterfaceImplFixture::FTestbed1StructInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructInterface>();
	Helper = NewObject<UTestbed1StructInterfaceImplHelper>();
}

FTestbed1StructInterfaceImplFixture::~FTestbed1StructInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructInterfaceInterface> FTestbed1StructInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTestbed1StructInterfaceImplHelper> FTestbed1StructInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed1StructInterfaceImplFixture::GetGameInstance()
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

void FTestbed1StructInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTestbed1StructInterfaceImplHelper::SetParentFixture(TWeakPtr<FTestbed1StructInterfaceImplFixture> /*InFixture*/)
{
}

void UTestbed1StructInterfaceImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTestbed1StructInterfaceImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTestbed1StructInterfaceImplHelper::PropBoolPropertyCb(const FTestbed1StructBool& PropBool)
{
	(void)PropBool;
}

void UTestbed1StructInterfaceImplHelper::PropIntPropertyCb(const FTestbed1StructInt& PropInt)
{
	(void)PropInt;
}

void UTestbed1StructInterfaceImplHelper::PropFloatPropertyCb(const FTestbed1StructFloat& PropFloat)
{
	(void)PropFloat;
}

void UTestbed1StructInterfaceImplHelper::PropStringPropertyCb(const FTestbed1StructString& PropString)
{
	(void)PropString;
}

void UTestbed1StructInterfaceImplHelper::SigBoolSignalCb(const FTestbed1StructBool& ParamBool)
{
	(void)ParamBool;
}

void UTestbed1StructInterfaceImplHelper::SigIntSignalCb(const FTestbed1StructInt& ParamInt)
{
	(void)ParamInt;
}

void UTestbed1StructInterfaceImplHelper::SigFloatSignalCb(const FTestbed1StructFloat& ParamFloat)
{
	(void)ParamFloat;
}

void UTestbed1StructInterfaceImplHelper::SigStringSignalCb(const FTestbed1StructString& ParamString)
{
	(void)ParamString;
}
#endif // WITH_DEV_AUTOMATION_TESTS
