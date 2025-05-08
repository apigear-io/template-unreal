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
#include "TbNamesNamEsOLinkFixture.h"
#include "TbNamesNamEsOLink.spec.h"
#include "OLinkCommon.h"
#include "Generated/OLink/TbNamesNamEsOLinkClient.h"
#include "Generated/OLink/TbNamesNamEsOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTbNamesNamEsOLinkHelper::SetSpec(UTbNamesNamEsOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTbNamesNamEsOLinkHelper::SwitchPropertyCb(bool bSwitch)
{
	Spec->SwitchPropertyCb(bSwitch);
}

void UTbNamesNamEsOLinkHelper::SwitchPropertyChangeLocalCheckRemoteCb(bool bSwitch)
{
	if (Spec)
	{
		Spec->SwitchPropertyChangeLocalCheckRemoteCb(bSwitch);
	}
}

void UTbNamesNamEsOLinkHelper::SwitchPropertyChangeLocalChangeRemoteCb(bool bSwitch)
{
	if (Spec)
	{
		Spec->SwitchPropertyChangeLocalChangeRemoteCb(bSwitch);
	}
}

void UTbNamesNamEsOLinkHelper::SomePropertyPropertyCb(int32 SomeProperty)
{
	Spec->SomePropertyPropertyCb(SomeProperty);
}

void UTbNamesNamEsOLinkHelper::SomePropertyPropertyChangeLocalCheckRemoteCb(int32 SomeProperty)
{
	if (Spec)
	{
		Spec->SomePropertyPropertyChangeLocalCheckRemoteCb(SomeProperty);
	}
}

void UTbNamesNamEsOLinkHelper::SomePropertyPropertyChangeLocalChangeRemoteCb(int32 SomeProperty)
{
	if (Spec)
	{
		Spec->SomePropertyPropertyChangeLocalChangeRemoteCb(SomeProperty);
	}
}

void UTbNamesNamEsOLinkHelper::SomePoperty2PropertyCb(int32 SomePoperty2)
{
	Spec->SomePoperty2PropertyCb(SomePoperty2);
}

void UTbNamesNamEsOLinkHelper::SomePoperty2PropertyChangeLocalCheckRemoteCb(int32 SomePoperty2)
{
	if (Spec)
	{
		Spec->SomePoperty2PropertyChangeLocalCheckRemoteCb(SomePoperty2);
	}
}

void UTbNamesNamEsOLinkHelper::SomePoperty2PropertyChangeLocalChangeRemoteCb(int32 SomePoperty2)
{
	if (Spec)
	{
		Spec->SomePoperty2PropertyChangeLocalChangeRemoteCb(SomePoperty2);
	}
}

void UTbNamesNamEsOLinkHelper::EnumPropertyPropertyCb(ETbNamesEnum_With_Under_scores EnumProperty)
{
	Spec->EnumPropertyPropertyCb(EnumProperty);
}

void UTbNamesNamEsOLinkHelper::EnumPropertyPropertyChangeLocalCheckRemoteCb(ETbNamesEnum_With_Under_scores EnumProperty)
{
	if (Spec)
	{
		Spec->EnumPropertyPropertyChangeLocalCheckRemoteCb(EnumProperty);
	}
}

void UTbNamesNamEsOLinkHelper::EnumPropertyPropertyChangeLocalChangeRemoteCb(ETbNamesEnum_With_Under_scores EnumProperty)
{
	if (Spec)
	{
		Spec->EnumPropertyPropertyChangeLocalChangeRemoteCb(EnumProperty);
	}
}

void UTbNamesNamEsOLinkHelper::SomeSignalSignalCb(bool bSomeParam)
{
	Spec->SomeSignalSignalCb(bSomeParam);
}

void UTbNamesNamEsOLinkHelper::SomeSignal2SignalCb(bool bSomeParam)
{
	Spec->SomeSignal2SignalCb(bSomeParam);
}

void UTbNamesNamEsOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTbNamesNamEsOLinkFixture::FTbNamesNamEsOLinkFixture()
{
	Helper = NewObject<UTbNamesNamEsOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbNamesNamEsOLinkClient>();
}

FTbNamesNamEsOLinkFixture::~FTbNamesNamEsOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbNamesNamEsInterface> FTbNamesNamEsOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbNamesNamEsOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbNamesNamEsOLinkAdapter* FTbNamesNamEsOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbNamesNamEsOLinkAdapter>();
}

TSoftObjectPtr<UTbNamesNamEsOLinkHelper> FTbNamesNamEsOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbNamesNamEsOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>(GetTransientPackage());
		GameInstance->Init();
		// needed to prevent garbage collection and we can't use UPROPERTY on raw c++ objects
		GameInstance->AddToRoot();
	}

	return GameInstance.Get();
}

void FTbNamesNamEsOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTbNamesNamEsOLinkHelper::SetSpec(UTbNamesNamEsOLinkSpec* /* InSpec */)
{
}

void UTbNamesNamEsOLinkHelper::SwitchPropertyCb(bool bSwitch)
{
	(void)bSwitch;
}

void UTbNamesNamEsOLinkHelper::SomePropertyPropertyCb(int32 SomeProperty)
{
	(void)SomeProperty;
}

void UTbNamesNamEsOLinkHelper::SomePoperty2PropertyCb(int32 SomePoperty2)
{
	(void)SomePoperty2;
}

void UTbNamesNamEsOLinkHelper::EnumPropertyPropertyCb(ETbNamesEnum_With_Under_scores EnumProperty)
{
	(void)EnumProperty;
}

void UTbNamesNamEsOLinkHelper::SomeSignalSignalCb(bool bSomeParam)
{
	(void)bSomeParam;
}

void UTbNamesNamEsOLinkHelper::SomeSignal2SignalCb(bool bSomeParam)
{
	(void)bSomeParam;
}

void UTbNamesNamEsOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
