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
#include "TbSame1SameStruct2InterfaceImplFixture.h"
#include "Implementation/TbSame1SameStruct2Interface.h"
#include "TbSame1TestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSame1SameStruct2InterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSame1SameStruct2InterfaceImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSame1SameStruct2InterfaceImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSame1SameStruct2InterfaceImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSame1SameStruct2InterfaceImplHelper::Prop1PropertyCb(const FTbSame1Struct2& InProp1)
{
	FTbSame1Struct2 TestValue = FTbSame1Struct2();
	// use different test value
	TestValue = createTestFTbSame1Struct2();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbSame1SameStruct2InterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp1(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame1SameStruct2InterfaceImplHelper::Prop2PropertyCb(const FTbSame1Struct2& InProp2)
{
	FTbSame1Struct2 TestValue = FTbSame1Struct2();
	// use different test value
	TestValue = createTestFTbSame1Struct2();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTbSame1SameStruct2InterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetProp2(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSame1SameStruct2InterfaceImplHelper::Sig1SignalCb(const FTbSame1Struct1& InParam1)
{
	// known test value
	FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbSame1SameStruct2InterfaceImplHelper::Sig2SignalCb(const FTbSame1Struct1& InParam1, const FTbSame1Struct2& InParam2)
{
	// known test value
	FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	FTbSame1Struct2 Param2TestValue = createTestFTbSame1Struct2();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

FTbSame1SameStruct2InterfaceImplFixture::FTbSame1SameStruct2InterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameStruct2Interface>();
	Helper = NewObject<UTbSame1SameStruct2InterfaceImplHelper>();
}

FTbSame1SameStruct2InterfaceImplFixture::~FTbSame1SameStruct2InterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> FTbSame1SameStruct2InterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbSame1SameStruct2InterfaceImplHelper> FTbSame1SameStruct2InterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame1SameStruct2InterfaceImplFixture::GetGameInstance()
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

void FTbSame1SameStruct2InterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSame1SameStruct2InterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSame1SameStruct2InterfaceImplFixture> /*InFixture*/)
{
}

void UTbSame1SameStruct2InterfaceImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSame1SameStruct2InterfaceImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSame1SameStruct2InterfaceImplHelper::Prop1PropertyCb(const FTbSame1Struct2& Prop1)
{
	(void)Prop1;
}

void UTbSame1SameStruct2InterfaceImplHelper::Prop2PropertyCb(const FTbSame1Struct2& Prop2)
{
	(void)Prop2;
}

void UTbSame1SameStruct2InterfaceImplHelper::Sig1SignalCb(const FTbSame1Struct1& Param1)
{
	(void)Param1;
}

void UTbSame1SameStruct2InterfaceImplHelper::Sig2SignalCb(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	(void)Param1;
	(void)Param2;
}
#endif // WITH_DEV_AUTOMATION_TESTS
