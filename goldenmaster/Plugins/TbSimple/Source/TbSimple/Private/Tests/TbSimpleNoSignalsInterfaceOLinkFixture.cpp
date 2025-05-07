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
#include "TbSimpleNoSignalsInterfaceOLinkFixture.h"
#include "TbSimpleNoSignalsInterfaceOLink.spec.h"
#include "OLinkCommon.h"
#include "Generated/OLink/TbSimpleNoSignalsInterfaceOLinkClient.h"
#include "Generated/OLink/TbSimpleNoSignalsInterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTbSimpleNoSignalsInterfaceOLinkHelper::SetSpec(UTbSimpleNoSignalsInterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleNoSignalsInterfaceOLinkHelper::PropBoolPropertyCb(bool bPropBool)
{
	Spec->PropBoolPropertyCb(bPropBool);
}

void UTbSimpleNoSignalsInterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb(bool bPropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyChangeLocalCheckRemoteCb(bPropBool);
	}
}

void UTbSimpleNoSignalsInterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb(bool bPropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyChangeLocalChangeRemoteCb(bPropBool);
	}
}

void UTbSimpleNoSignalsInterfaceOLinkHelper::PropIntPropertyCb(int32 PropInt)
{
	Spec->PropIntPropertyCb(PropInt);
}

void UTbSimpleNoSignalsInterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb(int32 PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyChangeLocalCheckRemoteCb(PropInt);
	}
}

void UTbSimpleNoSignalsInterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb(int32 PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyChangeLocalChangeRemoteCb(PropInt);
	}
}

void UTbSimpleNoSignalsInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTbSimpleNoSignalsInterfaceOLinkFixture::FTbSimpleNoSignalsInterfaceOLinkFixture()
{
	Helper = NewObject<UTbSimpleNoSignalsInterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoSignalsInterfaceOLinkClient>();
}

FTbSimpleNoSignalsInterfaceOLinkFixture::~FTbSimpleNoSignalsInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> FTbSimpleNoSignalsInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSimpleNoSignalsInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSimpleNoSignalsInterfaceOLinkAdapter* FTbSimpleNoSignalsInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoSignalsInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSimpleNoSignalsInterfaceOLinkHelper> FTbSimpleNoSignalsInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleNoSignalsInterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleNoSignalsInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTbSimpleNoSignalsInterfaceOLinkHelper::SetSpec(UTbSimpleNoSignalsInterfaceOLinkSpec* /* InSpec */)
{
}

void UTbSimpleNoSignalsInterfaceOLinkHelper::PropBoolPropertyCb(bool bPropBool)
{
	(void)bPropBool;
}

void UTbSimpleNoSignalsInterfaceOLinkHelper::PropIntPropertyCb(int32 PropInt)
{
	(void)PropInt;
}

void UTbSimpleNoSignalsInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
