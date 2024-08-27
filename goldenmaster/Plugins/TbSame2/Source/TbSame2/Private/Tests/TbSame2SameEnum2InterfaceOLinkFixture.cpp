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
#include "TbSame2SameEnum2InterfaceOLinkFixture.h"
#include "TbSame2SameEnum2InterfaceOLink.spec.h"
#include "Generated/OLink/TbSame2SameEnum2InterfaceOLinkClient.h"
#include "Generated/OLink/TbSame2SameEnum2InterfaceOLinkAdapter.h"
#include "OLinkHost.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSame2SameEnum2InterfaceOLinkHelper::SetSpec(UTbSame2SameEnum2InterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame2SameEnum2InterfaceOLinkHelper::Prop1PropertyCb(ETbSame2Enum1 Prop1)
{
	Spec->Prop1PropertyCb(Prop1);
}

void UTbSame2SameEnum2InterfaceOLinkHelper::Prop2PropertyCb(ETbSame2Enum2 Prop2)
{
	Spec->Prop2PropertyCb(Prop2);
}

void UTbSame2SameEnum2InterfaceOLinkHelper::Sig1SignalCb(ETbSame2Enum1 Param1)
{
	Spec->Sig1SignalCb(Param1);
}

void UTbSame2SameEnum2InterfaceOLinkHelper::Sig2SignalCb(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	Spec->Sig2SignalCb(Param1, Param2);
}

void UTbSame2SameEnum2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTbSame2SameEnum2InterfaceOLinkFixture::FTbSame2SameEnum2InterfaceOLinkFixture()
{
	Helper = NewObject<UTbSame2SameEnum2InterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameEnum2InterfaceOLinkClient>();
}

FTbSame2SameEnum2InterfaceOLinkFixture::~FTbSame2SameEnum2InterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> FTbSame2SameEnum2InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSame2SameEnum2InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSame2SameEnum2InterfaceOLinkAdapter* FTbSame2SameEnum2InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameEnum2InterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSame2SameEnum2InterfaceOLinkHelper> FTbSame2SameEnum2InterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame2SameEnum2InterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame2SameEnum2InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSame2SameEnum2InterfaceOLinkHelper::SetSpec(UTbSame2SameEnum2InterfaceOLinkSpec* /* InSpec */)
{
}

void UTbSame2SameEnum2InterfaceOLinkHelper::Prop1PropertyCb(ETbSame2Enum1 Prop1)
{
	(void)Prop1;
}

void UTbSame2SameEnum2InterfaceOLinkHelper::Prop2PropertyCb(ETbSame2Enum2 Prop2)
{
	(void)Prop2;
}

void UTbSame2SameEnum2InterfaceOLinkHelper::Sig1SignalCb(ETbSame2Enum1 Param1)
{
	(void)Param1;
}

void UTbSame2SameEnum2InterfaceOLinkHelper::Sig2SignalCb(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTbSame2SameEnum2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS
