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
#include "TbSimpleEmptyInterfaceOLinkFixture.h"
#include "TbSimpleEmptyInterfaceOLink.spec.h"
#include "TbSimple/Generated/OLink/TbSimpleEmptyInterfaceOLinkClient.h"
#include "TbSimple/Generated/OLink/TbSimpleEmptyInterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "OLinkHost.h"

void UTbSimpleEmptyInterfaceOLinkHelper::SetSpec(UTbSimpleEmptyInterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleEmptyInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTbSimpleEmptyInterfaceOLinkFixture::FTbSimpleEmptyInterfaceOLinkFixture()
{
	Helper = NewObject<UTbSimpleEmptyInterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleEmptyInterfaceOLinkClient>();
}

FTbSimpleEmptyInterfaceOLinkFixture::~FTbSimpleEmptyInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleEmptyInterfaceInterface> FTbSimpleEmptyInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSimpleEmptyInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSimpleEmptyInterfaceOLinkAdapter* FTbSimpleEmptyInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleEmptyInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSimpleEmptyInterfaceOLinkHelper> FTbSimpleEmptyInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleEmptyInterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleEmptyInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
// create empty implementation in case we do not want to do automated testing
void UTbSimpleEmptyInterfaceOLinkHelper::SetSpec(UTbSimpleEmptyInterfaceOLinkSpec* /* InSpec */)
{
}

void UTbSimpleEmptyInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
