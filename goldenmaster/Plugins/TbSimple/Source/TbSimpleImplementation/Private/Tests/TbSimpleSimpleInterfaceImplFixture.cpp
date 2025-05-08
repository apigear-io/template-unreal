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
#include "TbSimpleSimpleInterfaceImplFixture.h"
#include "TbSimple/Implementation/TbSimpleSimpleInterface.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleSimpleInterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSimpleSimpleInterfaceImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UTbSimpleSimpleInterfaceImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleSimpleInterfaceImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UTbSimpleSimpleInterfaceImplHelper::PropBoolPropertyCb(bool bInPropBool)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropBool(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplHelper::PropIntPropertyCb(int32 InPropInt)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropInt(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplHelper::PropInt32PropertyCb(int32 InPropInt32)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropInt32(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplHelper::PropInt64PropertyCb(int64 InPropInt64)
{
	int64 TestValue = 0LL;
	// use different test value
	TestValue = 1LL;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropInt64(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplHelper::PropFloatPropertyCb(float InPropFloat)
{
	float TestValue = 0.0f;
	// use different test value
	TestValue = 1.0f;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropFloat(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplHelper::PropFloat32PropertyCb(float InPropFloat32)
{
	float TestValue = 0.0f;
	// use different test value
	TestValue = 1.0f;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropFloat32(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplHelper::PropFloat64PropertyCb(double InPropFloat64)
{
	double TestValue = 0.0;
	// use different test value
	TestValue = 1.0;
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropFloat64(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplHelper::PropStringPropertyCb(const FString& InPropString)
{
	FString TestValue = FString();
	// use different test value
	TestValue = FString("xyz");
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	if (TSharedPtr<FTbSimpleSimpleInterfaceImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetPropString(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplHelper::SigBoolSignalCb(bool bInParamBool)
{
	// known test value
	bool bParamBoolTestValue = true;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplHelper::SigIntSignalCb(int32 InParamInt)
{
	// known test value
	int32 ParamIntTestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplHelper::SigInt32SignalCb(int32 InParamInt32)
{
	// known test value
	int32 ParamInt32TestValue = 1;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt32, ParamInt32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplHelper::SigInt64SignalCb(int64 InParamInt64)
{
	// known test value
	int64 ParamInt64TestValue = 1LL;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt64, ParamInt64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplHelper::SigFloatSignalCb(float InParamFloat)
{
	// known test value
	float ParamFloatTestValue = 1.0f;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplHelper::SigFloat32SignalCb(float InParamFloat32)
{
	// known test value
	float ParamFloat32TestValue = 1.0f;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat32, ParamFloat32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplHelper::SigFloat64SignalCb(double InParamFloat64)
{
	// known test value
	double ParamFloat64TestValue = 1.0;
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat64, ParamFloat64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplHelper::SigStringSignalCb(const FString& InParamString)
{
	// known test value
	FString ParamStringTestValue = FString("xyz");
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}

FTbSimpleSimpleInterfaceImplFixture::FTbSimpleSimpleInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleSimpleInterface>();
	Helper = NewObject<UTbSimpleSimpleInterfaceImplHelper>();
}

FTbSimpleSimpleInterfaceImplFixture::~FTbSimpleSimpleInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleSimpleInterfaceInterface> FTbSimpleSimpleInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbSimpleSimpleInterfaceImplHelper> FTbSimpleSimpleInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleSimpleInterfaceImplFixture::GetGameInstance()
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

void FTbSimpleSimpleInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSimpleSimpleInterfaceImplHelper::SetParentFixture(TWeakPtr<FTbSimpleSimpleInterfaceImplFixture> /*InFixture*/)
{
}

void UTbSimpleSimpleInterfaceImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UTbSimpleSimpleInterfaceImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UTbSimpleSimpleInterfaceImplHelper::PropBoolPropertyCb(bool bPropBool)
{
	(void)bPropBool;
}

void UTbSimpleSimpleInterfaceImplHelper::PropIntPropertyCb(int32 PropInt)
{
	(void)PropInt;
}

void UTbSimpleSimpleInterfaceImplHelper::PropInt32PropertyCb(int32 PropInt32)
{
	(void)PropInt32;
}

void UTbSimpleSimpleInterfaceImplHelper::PropInt64PropertyCb(int64 PropInt64)
{
	(void)PropInt64;
}

void UTbSimpleSimpleInterfaceImplHelper::PropFloatPropertyCb(float PropFloat)
{
	(void)PropFloat;
}

void UTbSimpleSimpleInterfaceImplHelper::PropFloat32PropertyCb(float PropFloat32)
{
	(void)PropFloat32;
}

void UTbSimpleSimpleInterfaceImplHelper::PropFloat64PropertyCb(double PropFloat64)
{
	(void)PropFloat64;
}

void UTbSimpleSimpleInterfaceImplHelper::PropStringPropertyCb(const FString& PropString)
{
	(void)PropString;
}

void UTbSimpleSimpleInterfaceImplHelper::SigBoolSignalCb(bool bParamBool)
{
	(void)bParamBool;
}

void UTbSimpleSimpleInterfaceImplHelper::SigIntSignalCb(int32 ParamInt)
{
	(void)ParamInt;
}

void UTbSimpleSimpleInterfaceImplHelper::SigInt32SignalCb(int32 ParamInt32)
{
	(void)ParamInt32;
}

void UTbSimpleSimpleInterfaceImplHelper::SigInt64SignalCb(int64 ParamInt64)
{
	(void)ParamInt64;
}

void UTbSimpleSimpleInterfaceImplHelper::SigFloatSignalCb(float ParamFloat)
{
	(void)ParamFloat;
}

void UTbSimpleSimpleInterfaceImplHelper::SigFloat32SignalCb(float ParamFloat32)
{
	(void)ParamFloat32;
}

void UTbSimpleSimpleInterfaceImplHelper::SigFloat64SignalCb(double ParamFloat64)
{
	(void)ParamFloat64;
}

void UTbSimpleSimpleInterfaceImplHelper::SigStringSignalCb(const FString& ParamString)
{
	(void)ParamString;
}
#endif // WITH_DEV_AUTOMATION_TESTS
