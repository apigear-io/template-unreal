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
#include "TbSame1SameEnum2InterfaceOLinkFixture.h"
#include "TbSame1SameEnum2InterfaceOLink.spec.h"
#include "OLinkCommon.h"
#include "Generated/OLink/TbSame1SameEnum2InterfaceOLinkClient.h"
#include "Generated/OLink/TbSame1SameEnum2InterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTbSame1SameEnum2InterfaceOLinkHelper::SetSpec(UTbSame1SameEnum2InterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop1PropertyCb(ETbSame1Enum1 Prop1)
{
	Spec->Prop1PropertyCb(Prop1);
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb(ETbSame1Enum1 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalCheckRemoteCb(Prop1);
	}
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb(ETbSame1Enum1 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalChangeRemoteCb(Prop1);
	}
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop2PropertyCb(ETbSame1Enum2 Prop2)
{
	Spec->Prop2PropertyCb(Prop2);
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop2PropertyChangeLocalCheckRemoteCb(ETbSame1Enum2 Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyChangeLocalCheckRemoteCb(Prop2);
	}
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop2PropertyChangeLocalChangeRemoteCb(ETbSame1Enum2 Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyChangeLocalChangeRemoteCb(Prop2);
	}
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Sig1SignalCb(ETbSame1Enum1 Param1)
{
	Spec->Sig1SignalCb(Param1);
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Sig2SignalCb(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	Spec->Sig2SignalCb(Param1, Param2);
}

void UTbSame1SameEnum2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTbSame1SameEnum2InterfaceOLinkFixture::FTbSame1SameEnum2InterfaceOLinkFixture()
{
	Helper = NewObject<UTbSame1SameEnum2InterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceOLinkClient>();
}

FTbSame1SameEnum2InterfaceOLinkFixture::~FTbSame1SameEnum2InterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> FTbSame1SameEnum2InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSame1SameEnum2InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSame1SameEnum2InterfaceOLinkAdapter* FTbSame1SameEnum2InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSame1SameEnum2InterfaceOLinkHelper> FTbSame1SameEnum2InterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame1SameEnum2InterfaceOLinkFixture::GetGameInstance()
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

void FTbSame1SameEnum2InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTbSame1SameEnum2InterfaceOLinkHelper::SetSpec(UTbSame1SameEnum2InterfaceOLinkSpec* /* InSpec */)
{
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop1PropertyCb(ETbSame1Enum1 Prop1)
{
	(void)Prop1;
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Prop2PropertyCb(ETbSame1Enum2 Prop2)
{
	(void)Prop2;
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Sig1SignalCb(ETbSame1Enum1 Param1)
{
	(void)Param1;
}

void UTbSame1SameEnum2InterfaceOLinkHelper::Sig2SignalCb(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTbSame1SameEnum2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
