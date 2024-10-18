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
#include "TbSimpleNoPropertiesInterfaceOLinkFixture.h"
#include "TbSimpleNoPropertiesInterfaceOLink.spec.h"
#include "TbSimple/Generated/OLink/TbSimpleNoPropertiesInterfaceOLinkClient.h"
#include "TbSimple/Generated/OLink/TbSimpleNoPropertiesInterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "OLinkHost.h"

void UTbSimpleNoPropertiesInterfaceOLinkHelper::SetSpec(UTbSimpleNoPropertiesInterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleNoPropertiesInterfaceOLinkHelper::SigVoidSignalCb()
{
	Spec->SigVoidSignalCb();
}

void UTbSimpleNoPropertiesInterfaceOLinkHelper::SigBoolSignalCb(bool bParamBool)
{
	Spec->SigBoolSignalCb(bParamBool);
}

void UTbSimpleNoPropertiesInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTbSimpleNoPropertiesInterfaceOLinkFixture::FTbSimpleNoPropertiesInterfaceOLinkFixture()
{
	Helper = NewObject<UTbSimpleNoPropertiesInterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterfaceOLinkClient>();
}

FTbSimpleNoPropertiesInterfaceOLinkFixture::~FTbSimpleNoPropertiesInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> FTbSimpleNoPropertiesInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSimpleNoPropertiesInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSimpleNoPropertiesInterfaceOLinkAdapter* FTbSimpleNoPropertiesInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSimpleNoPropertiesInterfaceOLinkHelper> FTbSimpleNoPropertiesInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleNoPropertiesInterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleNoPropertiesInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
// create empty implementation in case we do not want to do automated testing
void UTbSimpleNoPropertiesInterfaceOLinkHelper::SetSpec(UTbSimpleNoPropertiesInterfaceOLinkSpec* /* InSpec */)
{
}

void UTbSimpleNoPropertiesInterfaceOLinkHelper::SigVoidSignalCb()
{
}

void UTbSimpleNoPropertiesInterfaceOLinkHelper::SigBoolSignalCb(bool bParamBool)
{
	(void)bParamBool;
}

void UTbSimpleNoPropertiesInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
