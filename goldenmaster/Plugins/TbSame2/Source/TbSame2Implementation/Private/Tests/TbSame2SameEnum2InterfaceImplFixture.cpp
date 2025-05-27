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
#include "TbSame2SameEnum2InterfaceImplFixture.h"
#include "TbSame2/Implementation/TbSame2SameEnum2Interface.h"
#include "TbSame2/Tests/TbSame2TestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSame2SameEnum2InterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSame2SameEnum2InterfaceImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSame2SameEnum2InterfaceImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSame2SameEnum2InterfaceImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSame2SameEnum2InterfaceImplHelper::Prop1PropertyCb(ETbSame2Enum1 InProp1)
{
	ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_Value1;
	// use different test value
	TestValue = ETbSame2Enum1::TS2E1_Value2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame2SameEnum2InterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetProp1(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame2SameEnum2InterfaceImplHelper::Prop2PropertyCb(ETbSame2Enum2 InProp2)
{
	ETbSame2Enum2 TestValue = ETbSame2Enum2::TS2E2_Value1;
	// use different test value
	TestValue = ETbSame2Enum2::TS2E2_Value2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTbSame2SameEnum2InterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetProp2(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame2SameEnum2InterfaceImplHelper::Sig1SignalCb(ETbSame2Enum1 InParam1)
{
	// known test value
	ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_Value2;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameEnum2InterfaceImplHelper::Sig2SignalCb(ETbSame2Enum1 InParam1, ETbSame2Enum2 InParam2)
{
	// known test value
	ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_Value2;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	ETbSame2Enum2 Param2TestValue = ETbSame2Enum2::TS2E2_Value2;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

FTbSame2SameEnum2InterfaceImplFixture::FTbSame2SameEnum2InterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameEnum2Interface>();
	Helper = NewObject<UTbSame2SameEnum2InterfaceImplHelper>();
}

FTbSame2SameEnum2InterfaceImplFixture::~FTbSame2SameEnum2InterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> FTbSame2SameEnum2InterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbSame2SameEnum2InterfaceImplHelper> FTbSame2SameEnum2InterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame2SameEnum2InterfaceImplFixture::GetGameInstance()
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

void FTbSame2SameEnum2InterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSame2SameEnum2InterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSame2SameEnum2InterfaceImplFixture> /*InFixture*/)
{
}

void UTbSame2SameEnum2InterfaceImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSame2SameEnum2InterfaceImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSame2SameEnum2InterfaceImplHelper::Prop1PropertyCb(ETbSame2Enum1 Prop1)
{
	(void)Prop1;
}

void UTbSame2SameEnum2InterfaceImplHelper::Prop2PropertyCb(ETbSame2Enum2 Prop2)
{
	(void)Prop2;
}

void UTbSame2SameEnum2InterfaceImplHelper::Sig1SignalCb(ETbSame2Enum1 Param1)
{
	(void)Param1;
}

void UTbSame2SameEnum2InterfaceImplHelper::Sig2SignalCb(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	(void)Param1;
	(void)Param2;
}
#endif // WITH_DEV_AUTOMATION_TESTS
