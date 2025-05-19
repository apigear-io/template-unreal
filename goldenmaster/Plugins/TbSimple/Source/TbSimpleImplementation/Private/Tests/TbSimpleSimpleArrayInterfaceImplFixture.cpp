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
#include "TbSimpleSimpleArrayInterfaceImplFixture.h"
#include "TbSimple/Implementation/TbSimpleSimpleArrayInterface.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleSimpleArrayInterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSimpleSimpleArrayInterfaceImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::PropBoolPropertyCb(const TArray<bool>& InPropBool)
{
	TArray<bool> TestValue = TArray<bool>();
	// use different test value
	TestValue.Add(true);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropBool(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceImplHelper::PropIntPropertyCb(const TArray<int32>& InPropInt)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropInt(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceImplHelper::PropInt32PropertyCb(const TArray<int32>& InPropInt32)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropInt32(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceImplHelper::PropInt64PropertyCb(const TArray<int64>& InPropInt64)
{
	TArray<int64> TestValue = TArray<int64>();
	// use different test value
	TestValue.Add(1LL);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropInt64(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceImplHelper::PropFloatPropertyCb(const TArray<float>& InPropFloat)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropFloat(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceImplHelper::PropFloat32PropertyCb(const TArray<float>& InPropFloat32)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropFloat32(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceImplHelper::PropFloat64PropertyCb(const TArray<double>& InPropFloat64)
{
	TArray<double> TestValue = TArray<double>();
	// use different test value
	TestValue.Add(1.0);
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropFloat64(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceImplHelper::PropStringPropertyCb(const TArray<FString>& InPropString)
{
	TArray<FString> TestValue = TArray<FString>();
	// use different test value
	TestValue.Add(FString("xyz"));
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTbSimpleSimpleArrayInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropString(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigBoolSignalCb(const TArray<bool>& InParamBool)
{
	// known test value
	TArray<bool> ParamBoolTestValue = TArray<bool>(); // default value
	ParamBoolTestValue.Add(true);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigIntSignalCb(const TArray<int32>& InParamInt)
{
	// known test value
	TArray<int32> ParamIntTestValue = TArray<int32>(); // default value
	ParamIntTestValue.Add(1);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigInt32SignalCb(const TArray<int32>& InParamInt32)
{
	// known test value
	TArray<int32> ParamInt32TestValue = TArray<int32>(); // default value
	ParamInt32TestValue.Add(1);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt32, ParamInt32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigInt64SignalCb(const TArray<int64>& InParamInt64)
{
	// known test value
	TArray<int64> ParamInt64TestValue = TArray<int64>(); // default value
	ParamInt64TestValue.Add(1LL);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt64, ParamInt64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigFloatSignalCb(const TArray<float>& InParamFloat)
{
	// known test value
	TArray<float> ParamFloatTestValue = TArray<float>(); // default value
	ParamFloatTestValue.Add(1.0f);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigFloat32SignalCb(const TArray<float>& InParamFloa32)
{
	// known test value
	TArray<float> ParamFloa32TestValue = TArray<float>(); // default value
	ParamFloa32TestValue.Add(1.0f);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloa32, ParamFloa32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigFloat64SignalCb(const TArray<double>& InParamFloat64)
{
	// known test value
	TArray<double> ParamFloat64TestValue = TArray<double>(); // default value
	ParamFloat64TestValue.Add(1.0);
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat64, ParamFloat64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigStringSignalCb(const TArray<FString>& InParamString)
{
	// known test value
	TArray<FString> ParamStringTestValue = TArray<FString>(); // default value
	ParamStringTestValue.Add(FString("xyz"));
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}

FTbSimpleSimpleArrayInterfaceImplFixture::FTbSimpleSimpleArrayInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceImplementation>();
	Helper = NewObject<UTbSimpleSimpleArrayInterfaceImplHelper>();
}

FTbSimpleSimpleArrayInterfaceImplFixture::~FTbSimpleSimpleArrayInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> FTbSimpleSimpleArrayInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbSimpleSimpleArrayInterfaceImplHelper> FTbSimpleSimpleArrayInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleSimpleArrayInterfaceImplFixture::GetGameInstance()
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

void FTbSimpleSimpleArrayInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSimpleSimpleArrayInterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSimpleSimpleArrayInterfaceImplFixture> /*InFixture*/)
{
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSimpleSimpleArrayInterfaceImplHelper::PropBoolPropertyCb(const TArray<bool>& PropBool)
{
	(void)PropBool;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::PropIntPropertyCb(const TArray<int32>& PropInt)
{
	(void)PropInt;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::PropInt32PropertyCb(const TArray<int32>& PropInt32)
{
	(void)PropInt32;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::PropInt64PropertyCb(const TArray<int64>& PropInt64)
{
	(void)PropInt64;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::PropFloatPropertyCb(const TArray<float>& PropFloat)
{
	(void)PropFloat;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::PropFloat32PropertyCb(const TArray<float>& PropFloat32)
{
	(void)PropFloat32;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::PropFloat64PropertyCb(const TArray<double>& PropFloat64)
{
	(void)PropFloat64;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::PropStringPropertyCb(const TArray<FString>& PropString)
{
	(void)PropString;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigBoolSignalCb(const TArray<bool>& ParamBool)
{
	(void)ParamBool;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigIntSignalCb(const TArray<int32>& ParamInt)
{
	(void)ParamInt;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigInt32SignalCb(const TArray<int32>& ParamInt32)
{
	(void)ParamInt32;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigInt64SignalCb(const TArray<int64>& ParamInt64)
{
	(void)ParamInt64;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigFloatSignalCb(const TArray<float>& ParamFloat)
{
	(void)ParamFloat;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigFloat32SignalCb(const TArray<float>& ParamFloa32)
{
	(void)ParamFloa32;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigFloat64SignalCb(const TArray<double>& ParamFloat64)
{
	(void)ParamFloat64;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigStringSignalCb(const TArray<FString>& ParamString)
{
	(void)ParamString;
}
#endif // WITH_DEV_AUTOMATION_TESTS
