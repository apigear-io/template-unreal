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
#include "Testbed2ManyParamInterfaceOLinkFixture.h"
#include "Testbed2ManyParamInterfaceOLink.spec.h"
#include "OLinkCommon.h"
#include "Generated/OLink/Testbed2ManyParamInterfaceOLinkClient.h"
#include "Generated/OLink/Testbed2ManyParamInterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTestbed2ManyParamInterfaceOLinkHelper::SetSpec(UTestbed2ManyParamInterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop1PropertyCb(int32 Prop1)
{
	Spec->Prop1PropertyCb(Prop1);
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop2PropertyCb(int32 Prop2)
{
	Spec->Prop2PropertyCb(Prop2);
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop3PropertyCb(int32 Prop3)
{
	Spec->Prop3PropertyCb(Prop3);
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop4PropertyCb(int32 Prop4)
{
	Spec->Prop4PropertyCb(Prop4);
}

void UTestbed2ManyParamInterfaceOLinkHelper::Sig1SignalCb(int32 Param1)
{
	Spec->Sig1SignalCb(Param1);
}

void UTestbed2ManyParamInterfaceOLinkHelper::Sig2SignalCb(int32 Param1, int32 Param2)
{
	Spec->Sig2SignalCb(Param1, Param2);
}

void UTestbed2ManyParamInterfaceOLinkHelper::Sig3SignalCb(int32 Param1, int32 Param2, int32 Param3)
{
	Spec->Sig3SignalCb(Param1, Param2, Param3);
}

void UTestbed2ManyParamInterfaceOLinkHelper::Sig4SignalCb(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	Spec->Sig4SignalCb(Param1, Param2, Param3, Param4);
}

void UTestbed2ManyParamInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTestbed2ManyParamInterfaceOLinkFixture::FTestbed2ManyParamInterfaceOLinkFixture()
{
	Helper = NewObject<UTestbed2ManyParamInterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceOLinkClient>();
}

FTestbed2ManyParamInterfaceOLinkFixture::~FTestbed2ManyParamInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> FTestbed2ManyParamInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTestbed2ManyParamInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTestbed2ManyParamInterfaceOLinkAdapter* FTestbed2ManyParamInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTestbed2ManyParamInterfaceOLinkHelper> FTestbed2ManyParamInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed2ManyParamInterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed2ManyParamInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTestbed2ManyParamInterfaceOLinkHelper::SetSpec(UTestbed2ManyParamInterfaceOLinkSpec* /* InSpec */)
{
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop1PropertyCb(int32 Prop1)
{
	(void)Prop1;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop2PropertyCb(int32 Prop2)
{
	(void)Prop2;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop3PropertyCb(int32 Prop3)
{
	(void)Prop3;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Prop4PropertyCb(int32 Prop4)
{
	(void)Prop4;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Sig1SignalCb(int32 Param1)
{
	(void)Param1;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Sig2SignalCb(int32 Param1, int32 Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Sig3SignalCb(int32 Param1, int32 Param2, int32 Param3)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
}

void UTestbed2ManyParamInterfaceOLinkHelper::Sig4SignalCb(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
	(void)Param4;
}

void UTestbed2ManyParamInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
