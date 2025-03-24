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
#include "TbSame1SameStruct2InterfaceOLinkFixture.h"
#include "TbSame1SameStruct2InterfaceOLink.spec.h"
#include "OLinkCommon.h"
#include "Generated/OLink/TbSame1SameStruct2InterfaceOLinkClient.h"
#include "Generated/OLink/TbSame1SameStruct2InterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTbSame1SameStruct2InterfaceOLinkHelper::SetSpec(UTbSame1SameStruct2InterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame1SameStruct2InterfaceOLinkHelper::Prop1PropertyCb(const FTbSame1Struct2& Prop1)
{
	Spec->Prop1PropertyCb(Prop1);
}

void UTbSame1SameStruct2InterfaceOLinkHelper::Prop2PropertyCb(const FTbSame1Struct2& Prop2)
{
	Spec->Prop2PropertyCb(Prop2);
}

void UTbSame1SameStruct2InterfaceOLinkHelper::Sig1SignalCb(const FTbSame1Struct1& Param1)
{
	Spec->Sig1SignalCb(Param1);
}

void UTbSame1SameStruct2InterfaceOLinkHelper::Sig2SignalCb(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	Spec->Sig2SignalCb(Param1, Param2);
}

void UTbSame1SameStruct2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTbSame1SameStruct2InterfaceOLinkFixture::FTbSame1SameStruct2InterfaceOLinkFixture()
{
	Helper = NewObject<UTbSame1SameStruct2InterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceOLinkClient>();
}

FTbSame1SameStruct2InterfaceOLinkFixture::~FTbSame1SameStruct2InterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> FTbSame1SameStruct2InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSame1SameStruct2InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSame1SameStruct2InterfaceOLinkAdapter* FTbSame1SameStruct2InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSame1SameStruct2InterfaceOLinkHelper> FTbSame1SameStruct2InterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame1SameStruct2InterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame1SameStruct2InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTbSame1SameStruct2InterfaceOLinkHelper::SetSpec(UTbSame1SameStruct2InterfaceOLinkSpec* /* InSpec */)
{
}

void UTbSame1SameStruct2InterfaceOLinkHelper::Prop1PropertyCb(const FTbSame1Struct2& Prop1)
{
	(void)Prop1;
}

void UTbSame1SameStruct2InterfaceOLinkHelper::Prop2PropertyCb(const FTbSame1Struct2& Prop2)
{
	(void)Prop2;
}

void UTbSame1SameStruct2InterfaceOLinkHelper::Sig1SignalCb(const FTbSame1Struct1& Param1)
{
	(void)Param1;
}

void UTbSame1SameStruct2InterfaceOLinkHelper::Sig2SignalCb(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTbSame1SameStruct2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
