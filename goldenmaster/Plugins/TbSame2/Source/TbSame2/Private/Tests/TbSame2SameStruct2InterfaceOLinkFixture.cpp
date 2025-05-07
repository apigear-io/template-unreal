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
#include "TbSame2SameStruct2InterfaceOLinkFixture.h"
#include "TbSame2SameStruct2InterfaceOLink.spec.h"
#include "OLinkCommon.h"
#include "Generated/OLink/TbSame2SameStruct2InterfaceOLinkClient.h"
#include "Generated/OLink/TbSame2SameStruct2InterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTbSame2SameStruct2InterfaceOLinkHelper::SetSpec(UTbSame2SameStruct2InterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop1PropertyCb(const FTbSame2Struct2& Prop1)
{
	Spec->Prop1PropertyCb(Prop1);
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTbSame2Struct2& Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalCheckRemoteCb(Prop1);
	}
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTbSame2Struct2& Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalChangeRemoteCb(Prop1);
	}
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop2PropertyCb(const FTbSame2Struct2& Prop2)
{
	Spec->Prop2PropertyCb(Prop2);
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop2PropertyChangeLocalCheckRemoteCb(const FTbSame2Struct2& Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyChangeLocalCheckRemoteCb(Prop2);
	}
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop2PropertyChangeLocalChangeRemoteCb(const FTbSame2Struct2& Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyChangeLocalChangeRemoteCb(Prop2);
	}
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Sig1SignalCb(const FTbSame2Struct1& Param1)
{
	Spec->Sig1SignalCb(Param1);
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Sig2SignalCb(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	Spec->Sig2SignalCb(Param1, Param2);
}

void UTbSame2SameStruct2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTbSame2SameStruct2InterfaceOLinkFixture::FTbSame2SameStruct2InterfaceOLinkFixture()
{
	Helper = NewObject<UTbSame2SameStruct2InterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameStruct2InterfaceOLinkClient>();
}

FTbSame2SameStruct2InterfaceOLinkFixture::~FTbSame2SameStruct2InterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> FTbSame2SameStruct2InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSame2SameStruct2InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSame2SameStruct2InterfaceOLinkAdapter* FTbSame2SameStruct2InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameStruct2InterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSame2SameStruct2InterfaceOLinkHelper> FTbSame2SameStruct2InterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame2SameStruct2InterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame2SameStruct2InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTbSame2SameStruct2InterfaceOLinkHelper::SetSpec(UTbSame2SameStruct2InterfaceOLinkSpec* /* InSpec */)
{
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop1PropertyCb(const FTbSame2Struct2& Prop1)
{
	(void)Prop1;
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Prop2PropertyCb(const FTbSame2Struct2& Prop2)
{
	(void)Prop2;
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Sig1SignalCb(const FTbSame2Struct1& Param1)
{
	(void)Param1;
}

void UTbSame2SameStruct2InterfaceOLinkHelper::Sig2SignalCb(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTbSame2SameStruct2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
