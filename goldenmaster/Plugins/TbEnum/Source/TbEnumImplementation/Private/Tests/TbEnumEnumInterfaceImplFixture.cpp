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
#include "TbEnumEnumInterfaceImplFixture.h"
#include "TbEnum/Implementation/TbEnumEnumInterface.h"
#include "TbEnum/Tests/TbEnumTestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbEnumEnumInterfaceImplHelper::SetParentFixture(TWeakPtr<FTbEnumEnumInterfaceImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbEnumEnumInterfaceImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbEnumEnumInterfaceImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbEnumEnumInterfaceImplHelper::Prop0PropertyCb(ETbEnumEnum0 InProp0)
{
	ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0;
	// use different test value
	TestValue = ETbEnumEnum0::TEE0_Value1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp0, TestValue);
	if (TSharedPtr<FTbEnumEnumInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetProp0(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceImplHelper::Prop1PropertyCb(ETbEnumEnum1 InProp1)
{
	ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1;
	// use different test value
	TestValue = ETbEnumEnum1::TEE1_Value2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	if (TSharedPtr<FTbEnumEnumInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetProp1(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceImplHelper::Prop2PropertyCb(ETbEnumEnum2 InProp2)
{
	ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2;
	// use different test value
	TestValue = ETbEnumEnum2::TEE2_Value1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	if (TSharedPtr<FTbEnumEnumInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetProp2(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceImplHelper::Prop3PropertyCb(ETbEnumEnum3 InProp3)
{
	ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3;
	// use different test value
	TestValue = ETbEnumEnum3::TEE3_Value2;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
	if (TSharedPtr<FTbEnumEnumInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetProp3(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceImplHelper::Sig0SignalCb(ETbEnumEnum0 InParam0)
{
	// known test value
	ETbEnumEnum0 Param0TestValue = ETbEnumEnum0::TEE0_Value1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam0, Param0TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceImplHelper::Sig1SignalCb(ETbEnumEnum1 InParam1)
{
	// known test value
	ETbEnumEnum1 Param1TestValue = ETbEnumEnum1::TEE1_Value2;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceImplHelper::Sig2SignalCb(ETbEnumEnum2 InParam2)
{
	// known test value
	ETbEnumEnum2 Param2TestValue = ETbEnumEnum2::TEE2_Value1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceImplHelper::Sig3SignalCb(ETbEnumEnum3 InParam3)
{
	// known test value
	ETbEnumEnum3 Param3TestValue = ETbEnumEnum3::TEE3_Value2;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
	testDoneDelegate.Execute();
}

FTbEnumEnumInterfaceImplFixture::FTbEnumEnumInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
	Helper = NewObject<UTbEnumEnumInterfaceImplHelper>();
}

FTbEnumEnumInterfaceImplFixture::~FTbEnumEnumInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbEnumEnumInterfaceInterface> FTbEnumEnumInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbEnumEnumInterfaceImplHelper> FTbEnumEnumInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbEnumEnumInterfaceImplFixture::GetGameInstance()
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

void FTbEnumEnumInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbEnumEnumInterfaceImplHelper::SetParentFixture(TWeakPtr<FTbEnumEnumInterfaceImplFixture> /*InFixture*/)
{
}

void UTbEnumEnumInterfaceImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbEnumEnumInterfaceImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbEnumEnumInterfaceImplHelper::Prop0PropertyCb(ETbEnumEnum0 Prop0)
{
	(void)Prop0;
}

void UTbEnumEnumInterfaceImplHelper::Prop1PropertyCb(ETbEnumEnum1 Prop1)
{
	(void)Prop1;
}

void UTbEnumEnumInterfaceImplHelper::Prop2PropertyCb(ETbEnumEnum2 Prop2)
{
	(void)Prop2;
}

void UTbEnumEnumInterfaceImplHelper::Prop3PropertyCb(ETbEnumEnum3 Prop3)
{
	(void)Prop3;
}

void UTbEnumEnumInterfaceImplHelper::Sig0SignalCb(ETbEnumEnum0 Param0)
{
	(void)Param0;
}

void UTbEnumEnumInterfaceImplHelper::Sig1SignalCb(ETbEnumEnum1 Param1)
{
	(void)Param1;
}

void UTbEnumEnumInterfaceImplHelper::Sig2SignalCb(ETbEnumEnum2 Param2)
{
	(void)Param2;
}

void UTbEnumEnumInterfaceImplHelper::Sig3SignalCb(ETbEnumEnum3 Param3)
{
	(void)Param3;
}
#endif // WITH_DEV_AUTOMATION_TESTS
