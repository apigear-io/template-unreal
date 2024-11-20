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
#include "TbSimpleNoOperationsInterfaceOLinkFixture.h"
#include "TbSimpleNoOperationsInterfaceOLink.spec.h"
#include "Generated/OLink/TbSimpleNoOperationsInterfaceOLinkClient.h"
#include "Generated/OLink/TbSimpleNoOperationsInterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "OLinkHost.h"

void UTbSimpleNoOperationsInterfaceOLinkHelper::SetSpec(UTbSimpleNoOperationsInterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::PropBoolPropertyCb(bool bPropBool)
{
	Spec->PropBoolPropertyCb(bPropBool);
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::PropIntPropertyCb(int32 PropInt)
{
	Spec->PropIntPropertyCb(PropInt);
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::SigVoidSignalCb()
{
	Spec->SigVoidSignalCb();
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::SigBoolSignalCb(bool bParamBool)
{
	Spec->SigBoolSignalCb(bParamBool);
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTbSimpleNoOperationsInterfaceOLinkFixture::FTbSimpleNoOperationsInterfaceOLinkFixture()
{
	Helper = NewObject<UTbSimpleNoOperationsInterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterfaceOLinkClient>();
}

FTbSimpleNoOperationsInterfaceOLinkFixture::~FTbSimpleNoOperationsInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> FTbSimpleNoOperationsInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSimpleNoOperationsInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSimpleNoOperationsInterfaceOLinkAdapter* FTbSimpleNoOperationsInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSimpleNoOperationsInterfaceOLinkHelper> FTbSimpleNoOperationsInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleNoOperationsInterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleNoOperationsInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
// create empty implementation in case we do not want to do automated testing
void UTbSimpleNoOperationsInterfaceOLinkHelper::SetSpec(UTbSimpleNoOperationsInterfaceOLinkSpec* /* InSpec */)
{
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::PropBoolPropertyCb(bool bPropBool)
{
	(void)bPropBool;
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::PropIntPropertyCb(int32 PropInt)
{
	(void)PropInt;
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::SigVoidSignalCb()
{
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::SigBoolSignalCb(bool bParamBool)
{
	(void)bParamBool;
}

void UTbSimpleNoOperationsInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
