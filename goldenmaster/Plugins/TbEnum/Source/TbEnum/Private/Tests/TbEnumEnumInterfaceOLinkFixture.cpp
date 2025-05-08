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
#include "TbEnumEnumInterfaceOLinkFixture.h"
#include "TbEnumEnumInterfaceOLink.spec.h"
#include "OLinkCommon.h"
#include "Generated/OLink/TbEnumEnumInterfaceOLinkClient.h"
#include "Generated/OLink/TbEnumEnumInterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTbEnumEnumInterfaceOLinkHelper::SetSpec(UTbEnumEnumInterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTbEnumEnumInterfaceOLinkHelper::Prop0PropertyCb(ETbEnumEnum0 Prop0)
{
	Spec->Prop0PropertyCb(Prop0);
}

void UTbEnumEnumInterfaceOLinkHelper::Prop0PropertyChangeLocalCheckRemoteCb(ETbEnumEnum0 Prop0)
{
	if (Spec)
	{
		Spec->Prop0PropertyChangeLocalCheckRemoteCb(Prop0);
	}
}

void UTbEnumEnumInterfaceOLinkHelper::Prop0PropertyChangeLocalChangeRemoteCb(ETbEnumEnum0 Prop0)
{
	if (Spec)
	{
		Spec->Prop0PropertyChangeLocalChangeRemoteCb(Prop0);
	}
}

void UTbEnumEnumInterfaceOLinkHelper::Prop1PropertyCb(ETbEnumEnum1 Prop1)
{
	Spec->Prop1PropertyCb(Prop1);
}

void UTbEnumEnumInterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb(ETbEnumEnum1 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalCheckRemoteCb(Prop1);
	}
}

void UTbEnumEnumInterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb(ETbEnumEnum1 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalChangeRemoteCb(Prop1);
	}
}

void UTbEnumEnumInterfaceOLinkHelper::Prop2PropertyCb(ETbEnumEnum2 Prop2)
{
	Spec->Prop2PropertyCb(Prop2);
}

void UTbEnumEnumInterfaceOLinkHelper::Prop2PropertyChangeLocalCheckRemoteCb(ETbEnumEnum2 Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyChangeLocalCheckRemoteCb(Prop2);
	}
}

void UTbEnumEnumInterfaceOLinkHelper::Prop2PropertyChangeLocalChangeRemoteCb(ETbEnumEnum2 Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyChangeLocalChangeRemoteCb(Prop2);
	}
}

void UTbEnumEnumInterfaceOLinkHelper::Prop3PropertyCb(ETbEnumEnum3 Prop3)
{
	Spec->Prop3PropertyCb(Prop3);
}

void UTbEnumEnumInterfaceOLinkHelper::Prop3PropertyChangeLocalCheckRemoteCb(ETbEnumEnum3 Prop3)
{
	if (Spec)
	{
		Spec->Prop3PropertyChangeLocalCheckRemoteCb(Prop3);
	}
}

void UTbEnumEnumInterfaceOLinkHelper::Prop3PropertyChangeLocalChangeRemoteCb(ETbEnumEnum3 Prop3)
{
	if (Spec)
	{
		Spec->Prop3PropertyChangeLocalChangeRemoteCb(Prop3);
	}
}

void UTbEnumEnumInterfaceOLinkHelper::Sig0SignalCb(ETbEnumEnum0 Param0)
{
	Spec->Sig0SignalCb(Param0);
}

void UTbEnumEnumInterfaceOLinkHelper::Sig1SignalCb(ETbEnumEnum1 Param1)
{
	Spec->Sig1SignalCb(Param1);
}

void UTbEnumEnumInterfaceOLinkHelper::Sig2SignalCb(ETbEnumEnum2 Param2)
{
	Spec->Sig2SignalCb(Param2);
}

void UTbEnumEnumInterfaceOLinkHelper::Sig3SignalCb(ETbEnumEnum3 Param3)
{
	Spec->Sig3SignalCb(Param3);
}

void UTbEnumEnumInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTbEnumEnumInterfaceOLinkFixture::FTbEnumEnumInterfaceOLinkFixture()
{
	Helper = NewObject<UTbEnumEnumInterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceOLinkClient>();
}

FTbEnumEnumInterfaceOLinkFixture::~FTbEnumEnumInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbEnumEnumInterfaceInterface> FTbEnumEnumInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbEnumEnumInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbEnumEnumInterfaceOLinkAdapter* FTbEnumEnumInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbEnumEnumInterfaceOLinkHelper> FTbEnumEnumInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbEnumEnumInterfaceOLinkFixture::GetGameInstance()
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

void FTbEnumEnumInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTbEnumEnumInterfaceOLinkHelper::SetSpec(UTbEnumEnumInterfaceOLinkSpec* /* InSpec */)
{
}

void UTbEnumEnumInterfaceOLinkHelper::Prop0PropertyCb(ETbEnumEnum0 Prop0)
{
	(void)Prop0;
}

void UTbEnumEnumInterfaceOLinkHelper::Prop1PropertyCb(ETbEnumEnum1 Prop1)
{
	(void)Prop1;
}

void UTbEnumEnumInterfaceOLinkHelper::Prop2PropertyCb(ETbEnumEnum2 Prop2)
{
	(void)Prop2;
}

void UTbEnumEnumInterfaceOLinkHelper::Prop3PropertyCb(ETbEnumEnum3 Prop3)
{
	(void)Prop3;
}

void UTbEnumEnumInterfaceOLinkHelper::Sig0SignalCb(ETbEnumEnum0 Param0)
{
	(void)Param0;
}

void UTbEnumEnumInterfaceOLinkHelper::Sig1SignalCb(ETbEnumEnum1 Param1)
{
	(void)Param1;
}

void UTbEnumEnumInterfaceOLinkHelper::Sig2SignalCb(ETbEnumEnum2 Param2)
{
	(void)Param2;
}

void UTbEnumEnumInterfaceOLinkHelper::Sig3SignalCb(ETbEnumEnum3 Param3)
{
	(void)Param3;
}

void UTbEnumEnumInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
