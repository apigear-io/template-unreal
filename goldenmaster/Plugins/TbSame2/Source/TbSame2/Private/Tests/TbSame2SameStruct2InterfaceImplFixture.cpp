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
#include "TbSame2SameStruct2InterfaceImplFixture.h"
#include "Implementation/TbSame2SameStruct2Interface.h"
#include "TbSame2TestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSame2SameStruct2InterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSame2SameStruct2InterfaceImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSame2SameStruct2InterfaceImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSame2SameStruct2InterfaceImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSame2SameStruct2InterfaceImplHelper::Prop1PropertyCb(const FTbSame2Struct2& InProp1)
{
	FTbSame2Struct2 TestValue = FTbSame2Struct2();
	// use different test value
	TestValue = createTestFTbSame2Struct2();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame2SameStruct2InterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceImplHelper::Prop2PropertyCb(const FTbSame2Struct2& InProp2)
{
	FTbSame2Struct2 TestValue = FTbSame2Struct2();
	// use different test value
	TestValue = createTestFTbSame2Struct2();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTbSame2SameStruct2InterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceImplHelper::Sig1SignalCb(const FTbSame2Struct1& InParam1)
{
	// known test value
	FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceImplHelper::Sig2SignalCb(const FTbSame2Struct1& InParam1, const FTbSame2Struct2& InParam2)
{
	// known test value
	FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	FTbSame2Struct2 Param2TestValue = createTestFTbSame2Struct2();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

FTbSame2SameStruct2InterfaceImplFixture::FTbSame2SameStruct2InterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameStruct2Interface>();
	Helper = NewObject<UTbSame2SameStruct2InterfaceImplHelper>();
}

FTbSame2SameStruct2InterfaceImplFixture::~FTbSame2SameStruct2InterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> FTbSame2SameStruct2InterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbSame2SameStruct2InterfaceImplHelper> FTbSame2SameStruct2InterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame2SameStruct2InterfaceImplFixture::GetGameInstance()
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

void FTbSame2SameStruct2InterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSame2SameStruct2InterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSame2SameStruct2InterfaceImplFixture> /*InFixture*/)
{
}

void UTbSame2SameStruct2InterfaceImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSame2SameStruct2InterfaceImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSame2SameStruct2InterfaceImplHelper::Prop1PropertyCb(const FTbSame2Struct2& Prop1)
{
	(void)Prop1;
}

void UTbSame2SameStruct2InterfaceImplHelper::Prop2PropertyCb(const FTbSame2Struct2& Prop2)
{
	(void)Prop2;
}

void UTbSame2SameStruct2InterfaceImplHelper::Sig1SignalCb(const FTbSame2Struct1& Param1)
{
	(void)Param1;
}

void UTbSame2SameStruct2InterfaceImplHelper::Sig2SignalCb(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	(void)Param1;
	(void)Param2;
}
#endif // WITH_DEV_AUTOMATION_TESTS
