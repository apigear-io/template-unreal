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
#include "TbSame2SameEnum1InterfaceOLinkFixture.h"
#include "TbSame2SameEnum1InterfaceOLink.spec.h"
#include "TbSame2/Generated/OLink/TbSame2SameEnum1InterfaceOLinkClient.h"
#include "TbSame2/Generated/OLink/TbSame2SameEnum1InterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "OLinkHost.h"

void UTbSame2SameEnum1InterfaceOLinkHelper::SetSpec(UTbSame2SameEnum1InterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame2SameEnum1InterfaceOLinkHelper::Prop1PropertyCb(ETbSame2Enum1 Prop1)
{
	Spec->Prop1PropertyCb(Prop1);
}

void UTbSame2SameEnum1InterfaceOLinkHelper::Sig1SignalCb(ETbSame2Enum1 Param1)
{
	Spec->Sig1SignalCb(Param1);
}

void UTbSame2SameEnum1InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTbSame2SameEnum1InterfaceOLinkFixture::FTbSame2SameEnum1InterfaceOLinkFixture()
{
	Helper = NewObject<UTbSame2SameEnum1InterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameEnum1InterfaceOLinkClient>();
}

FTbSame2SameEnum1InterfaceOLinkFixture::~FTbSame2SameEnum1InterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameEnum1InterfaceInterface> FTbSame2SameEnum1InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSame2SameEnum1InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSame2SameEnum1InterfaceOLinkAdapter* FTbSame2SameEnum1InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameEnum1InterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSame2SameEnum1InterfaceOLinkHelper> FTbSame2SameEnum1InterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame2SameEnum1InterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame2SameEnum1InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
// create empty implementation in case we do not want to do automated testing
void UTbSame2SameEnum1InterfaceOLinkHelper::SetSpec(UTbSame2SameEnum1InterfaceOLinkSpec* /* InSpec */)
{
}

void UTbSame2SameEnum1InterfaceOLinkHelper::Prop1PropertyCb(ETbSame2Enum1 Prop1)
{
	(void)Prop1;
}

void UTbSame2SameEnum1InterfaceOLinkHelper::Sig1SignalCb(ETbSame2Enum1 Param1)
{
	(void)Param1;
}

void UTbSame2SameEnum1InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
