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
#include "TbSimpleVoidInterfaceOLinkFixture.h"
#include "TbSimpleVoidInterfaceOLink.spec.h"
#include "TbSimple/Generated/OLink/TbSimpleVoidInterfaceOLinkClient.h"
#include "TbSimple/Generated/OLink/TbSimpleVoidInterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "OLinkHost.h"

void UTbSimpleVoidInterfaceOLinkHelper::SetSpec(UTbSimpleVoidInterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleVoidInterfaceOLinkHelper::SigVoidSignalCb()
{
	Spec->SigVoidSignalCb();
}

void UTbSimpleVoidInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTbSimpleVoidInterfaceOLinkFixture::FTbSimpleVoidInterfaceOLinkFixture()
{
	Helper = NewObject<UTbSimpleVoidInterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleVoidInterfaceOLinkClient>();
}

FTbSimpleVoidInterfaceOLinkFixture::~FTbSimpleVoidInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleVoidInterfaceInterface> FTbSimpleVoidInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSimpleVoidInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSimpleVoidInterfaceOLinkAdapter* FTbSimpleVoidInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleVoidInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSimpleVoidInterfaceOLinkHelper> FTbSimpleVoidInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleVoidInterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleVoidInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
// create empty implementation in case we do not want to do automated testing
void UTbSimpleVoidInterfaceOLinkHelper::SetSpec(UTbSimpleVoidInterfaceOLinkSpec* /* InSpec */)
{
}

void UTbSimpleVoidInterfaceOLinkHelper::SigVoidSignalCb()
{
}

void UTbSimpleVoidInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
