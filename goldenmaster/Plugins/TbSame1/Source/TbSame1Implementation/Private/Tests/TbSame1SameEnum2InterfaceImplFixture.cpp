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
#include "TbSame1SameEnum2InterfaceImplFixture.h"
#include "TbSame1/Implementation/TbSame1SameEnum2Interface.h"
#include "TbSame1/Tests/TbSame1TestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSame1SameEnum2InterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSame1SameEnum2InterfaceImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSame1SameEnum2InterfaceImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSame1SameEnum2InterfaceImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSame1SameEnum2InterfaceImplHelper::Prop1PropertyCb(ETbSame1Enum1 InProp1)
{
	ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_VALUE1;
	// use different test value
	TestValue = ETbSame1Enum1::TS1E1_VALUE2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame1SameEnum2InterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetProp1(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceImplHelper::Prop2PropertyCb(ETbSame1Enum2 InProp2)
{
	ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_VALUE1;
	// use different test value
	TestValue = ETbSame1Enum2::TS1E2_VALUE2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTbSame1SameEnum2InterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetProp2(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceImplHelper::Sig1SignalCb(ETbSame1Enum1 InParam1)
{
	// known test value
	ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_VALUE2;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceImplHelper::Sig2SignalCb(ETbSame1Enum1 InParam1, ETbSame1Enum2 InParam2)
{
	// known test value
	ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_VALUE2;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	ETbSame1Enum2 Param2TestValue = ETbSame1Enum2::TS1E2_VALUE2;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

FTbSame1SameEnum2InterfaceImplFixture::FTbSame1SameEnum2InterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameEnum2Interface>();
	Helper = NewObject<UTbSame1SameEnum2InterfaceImplHelper>();
}

FTbSame1SameEnum2InterfaceImplFixture::~FTbSame1SameEnum2InterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> FTbSame1SameEnum2InterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbSame1SameEnum2InterfaceImplHelper> FTbSame1SameEnum2InterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame1SameEnum2InterfaceImplFixture::GetGameInstance()
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

void FTbSame1SameEnum2InterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSame1SameEnum2InterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSame1SameEnum2InterfaceImplFixture> /*InFixture*/)
{
}

void UTbSame1SameEnum2InterfaceImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSame1SameEnum2InterfaceImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSame1SameEnum2InterfaceImplHelper::Prop1PropertyCb(ETbSame1Enum1 Prop1)
{
	(void)Prop1;
}

void UTbSame1SameEnum2InterfaceImplHelper::Prop2PropertyCb(ETbSame1Enum2 Prop2)
{
	(void)Prop2;
}

void UTbSame1SameEnum2InterfaceImplHelper::Sig1SignalCb(ETbSame1Enum1 Param1)
{
	(void)Param1;
}

void UTbSame1SameEnum2InterfaceImplHelper::Sig2SignalCb(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	(void)Param1;
	(void)Param2;
}
#endif // WITH_DEV_AUTOMATION_TESTS
