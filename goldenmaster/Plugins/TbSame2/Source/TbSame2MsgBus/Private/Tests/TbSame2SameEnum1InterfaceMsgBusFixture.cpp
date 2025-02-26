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
#include "TbSame2SameEnum1InterfaceMsgBusFixture.h"
#include "TbSame2SameEnum1InterfaceMsgBus.spec.h"
#include "TbSame2/Generated/MsgBus/TbSame2SameEnum1InterfaceMsgBusClient.h"
#include "TbSame2/Generated/MsgBus/TbSame2SameEnum1InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

UTbSame2SameEnum1InterfaceMsgBusHelper::~UTbSame2SameEnum1InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSame2SameEnum1InterfaceMsgBusHelper::SetSpec(UTbSame2SameEnum1InterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame2SameEnum1InterfaceMsgBusHelper::Prop1PropertyCb(ETbSame2Enum1 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyCb(Prop1);
	}
}

void UTbSame2SameEnum1InterfaceMsgBusHelper::Sig1SignalCb(ETbSame2Enum1 Param1)
{
	if (Spec)
	{
		Spec->Sig1SignalCb(Param1);
	}
}

void UTbSame2SameEnum1InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTbSame2SameEnum1InterfaceMsgBusFixture::FTbSame2SameEnum1InterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSame2SameEnum1InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameEnum1InterfaceMsgBusClient>();
}

FTbSame2SameEnum1InterfaceMsgBusFixture::~FTbSame2SameEnum1InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameEnum1InterfaceInterface> FTbSame2SameEnum1InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame2SameEnum1InterfaceMsgBusAdapter* FTbSame2SameEnum1InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameEnum1InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSame2SameEnum1InterfaceMsgBusHelper> FTbSame2SameEnum1InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame2SameEnum1InterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame2SameEnum1InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
// create empty implementation in case we do not want to do automated testing
UTbSame2SameEnum1InterfaceMsgBusHelper::~UTbSame2SameEnum1InterfaceMsgBusHelper()
{
}

void UTbSame2SameEnum1InterfaceMsgBusHelper::SetSpec(UTbSame2SameEnum1InterfaceMsgBusSpec* /* InSpec */)
{
}

void UTbSame2SameEnum1InterfaceMsgBusHelper::Prop1PropertyCb(ETbSame2Enum1 Prop1)
{
	(void)Prop1;
}

void UTbSame2SameEnum1InterfaceMsgBusHelper::Sig1SignalCb(ETbSame2Enum1 Param1)
{
	(void)Param1;
}

void UTbSame2SameEnum1InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
