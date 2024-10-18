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
#include "Testbed2NestedStruct2InterfaceOLinkFixture.h"
#include "Testbed2NestedStruct2InterfaceOLink.spec.h"
#include "Testbed2/Generated/OLink/Testbed2NestedStruct2InterfaceOLinkClient.h"
#include "Testbed2/Generated/OLink/Testbed2NestedStruct2InterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "OLinkHost.h"

void UTestbed2NestedStruct2InterfaceOLinkHelper::SetSpec(UTestbed2NestedStruct2InterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1)
{
	Spec->Prop1PropertyCb(Prop1);
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2)
{
	Spec->Prop2PropertyCb(Prop2);
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	Spec->Sig1SignalCb(Param1);
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Spec->Sig2SignalCb(Param1, Param2);
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTestbed2NestedStruct2InterfaceOLinkFixture::FTestbed2NestedStruct2InterfaceOLinkFixture()
{
	Helper = NewObject<UTestbed2NestedStruct2InterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2NestedStruct2InterfaceOLinkClient>();
}

FTestbed2NestedStruct2InterfaceOLinkFixture::~FTestbed2NestedStruct2InterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> FTestbed2NestedStruct2InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTestbed2NestedStruct2InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTestbed2NestedStruct2InterfaceOLinkAdapter* FTestbed2NestedStruct2InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2NestedStruct2InterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTestbed2NestedStruct2InterfaceOLinkHelper> FTestbed2NestedStruct2InterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed2NestedStruct2InterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed2NestedStruct2InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
// create empty implementation in case we do not want to do automated testing
void UTestbed2NestedStruct2InterfaceOLinkHelper::SetSpec(UTestbed2NestedStruct2InterfaceOLinkSpec* /* InSpec */)
{
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1)
{
	(void)Prop1;
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2)
{
	(void)Prop2;
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTestbed2NestedStruct2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
