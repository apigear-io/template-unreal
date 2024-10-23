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
#include "Testbed1StructArrayInterfaceOLinkFixture.h"
#include "Testbed1StructArrayInterfaceOLink.spec.h"
#include "Generated/OLink/Testbed1StructArrayInterfaceOLinkClient.h"
#include "Generated/OLink/Testbed1StructArrayInterfaceOLinkAdapter.h"
#include "OLinkHost.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed1StructArrayInterfaceOLinkHelper::SetSpec(UTestbed1StructArrayInterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropBoolPropertyCb(const TArray<FTestbed1StructBool>& PropBool)
{
	Spec->PropBoolPropertyCb(PropBool);
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropIntPropertyCb(const TArray<FTestbed1StructInt>& PropInt)
{
	Spec->PropIntPropertyCb(PropInt);
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropFloatPropertyCb(const TArray<FTestbed1StructFloat>& PropFloat)
{
	Spec->PropFloatPropertyCb(PropFloat);
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropStringPropertyCb(const TArray<FTestbed1StructString>& PropString)
{
	Spec->PropStringPropertyCb(PropString);
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigBoolSignalCb(const TArray<FTestbed1StructBool>& ParamBool)
{
	Spec->SigBoolSignalCb(ParamBool);
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigIntSignalCb(const TArray<FTestbed1StructInt>& ParamInt)
{
	Spec->SigIntSignalCb(ParamInt);
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigFloatSignalCb(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	Spec->SigFloatSignalCb(ParamFloat);
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigStringSignalCb(const TArray<FTestbed1StructString>& ParamString)
{
	Spec->SigStringSignalCb(ParamString);
}

void UTestbed1StructArrayInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTestbed1StructArrayInterfaceOLinkFixture::FTestbed1StructArrayInterfaceOLinkFixture()
{
	Helper = NewObject<UTestbed1StructArrayInterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceOLinkClient>();
}

FTestbed1StructArrayInterfaceOLinkFixture::~FTestbed1StructArrayInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> FTestbed1StructArrayInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTestbed1StructArrayInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTestbed1StructArrayInterfaceOLinkAdapter* FTestbed1StructArrayInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTestbed1StructArrayInterfaceOLinkHelper> FTestbed1StructArrayInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed1StructArrayInterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed1StructArrayInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTestbed1StructArrayInterfaceOLinkHelper::SetSpec(UTestbed1StructArrayInterfaceOLinkSpec* /* InSpec */)
{
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropBoolPropertyCb(const TArray<FTestbed1StructBool>& PropBool)
{
	(void)PropBool;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropIntPropertyCb(const TArray<FTestbed1StructInt>& PropInt)
{
	(void)PropInt;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropFloatPropertyCb(const TArray<FTestbed1StructFloat>& PropFloat)
{
	(void)PropFloat;
}

void UTestbed1StructArrayInterfaceOLinkHelper::PropStringPropertyCb(const TArray<FTestbed1StructString>& PropString)
{
	(void)PropString;
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigBoolSignalCb(const TArray<FTestbed1StructBool>& ParamBool)
{
	(void)ParamBool;
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigIntSignalCb(const TArray<FTestbed1StructInt>& ParamInt)
{
	(void)ParamInt;
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigFloatSignalCb(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	(void)ParamFloat;
}

void UTestbed1StructArrayInterfaceOLinkHelper::SigStringSignalCb(const TArray<FTestbed1StructString>& ParamString)
{
	(void)ParamString;
}

void UTestbed1StructArrayInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS
