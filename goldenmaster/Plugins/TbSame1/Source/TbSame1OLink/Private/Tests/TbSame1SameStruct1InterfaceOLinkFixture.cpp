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
#include "TbSame1SameStruct1InterfaceOLinkFixture.h"
#include "TbSame1SameStruct1InterfaceOLink.spec.h"
#include "TbSame1/Generated/OLink/TbSame1SameStruct1InterfaceOLinkClient.h"
#include "TbSame1/Generated/OLink/TbSame1SameStruct1InterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "OLinkHost.h"

void UTbSame1SameStruct1InterfaceOLinkHelper::SetSpec(UTbSame1SameStruct1InterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame1SameStruct1InterfaceOLinkHelper::Prop1PropertyCb(const FTbSame1Struct1& Prop1)
{
	Spec->Prop1PropertyCb(Prop1);
}

void UTbSame1SameStruct1InterfaceOLinkHelper::Sig1SignalCb(const FTbSame1Struct1& Param1)
{
	Spec->Sig1SignalCb(Param1);
}

void UTbSame1SameStruct1InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTbSame1SameStruct1InterfaceOLinkFixture::FTbSame1SameStruct1InterfaceOLinkFixture()
{
	Helper = NewObject<UTbSame1SameStruct1InterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameStruct1InterfaceOLinkClient>();
}

FTbSame1SameStruct1InterfaceOLinkFixture::~FTbSame1SameStruct1InterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> FTbSame1SameStruct1InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSame1SameStruct1InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSame1SameStruct1InterfaceOLinkAdapter* FTbSame1SameStruct1InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameStruct1InterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSame1SameStruct1InterfaceOLinkHelper> FTbSame1SameStruct1InterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame1SameStruct1InterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame1SameStruct1InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
// create empty implementation in case we do not want to do automated testing
void UTbSame1SameStruct1InterfaceOLinkHelper::SetSpec(UTbSame1SameStruct1InterfaceOLinkSpec* /* InSpec */)
{
}

void UTbSame1SameStruct1InterfaceOLinkHelper::Prop1PropertyCb(const FTbSame1Struct1& Prop1)
{
	(void)Prop1;
}

void UTbSame1SameStruct1InterfaceOLinkHelper::Sig1SignalCb(const FTbSame1Struct1& Param1)
{
	(void)Param1;
}

void UTbSame1SameStruct1InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
