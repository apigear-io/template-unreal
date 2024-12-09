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
#include "TbSame2SameStruct1InterfaceMsgBusFixture.h"
#include "TbSame2SameStruct1InterfaceMsgBus.spec.h"
#include "Generated/MsgBus/TbSame2SameStruct1InterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSame2SameStruct1InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

UTbSame2SameStruct1InterfaceMsgBusHelper::~UTbSame2SameStruct1InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::SetSpec(UTbSame2SameStruct1InterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::Prop1PropertyCb(const FTbSame2Struct1& Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyCb(Prop1);
	}
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::Sig1SignalCb(const FTbSame2Struct1& Param1)
{
	if (Spec)
	{
		Spec->Sig1SignalCb(Param1);
	}
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTbSame2SameStruct1InterfaceMsgBusFixture::FTbSame2SameStruct1InterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSame2SameStruct1InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameStruct1InterfaceMsgBusClient>();
}

FTbSame2SameStruct1InterfaceMsgBusFixture::~FTbSame2SameStruct1InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameStruct1InterfaceInterface> FTbSame2SameStruct1InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame2SameStruct1InterfaceMsgBusAdapter* FTbSame2SameStruct1InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameStruct1InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSame2SameStruct1InterfaceMsgBusHelper> FTbSame2SameStruct1InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame2SameStruct1InterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame2SameStruct1InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
// create empty implementation in case we do not want to do automated testing
UTbSame2SameStruct1InterfaceMsgBusHelper::~UTbSame2SameStruct1InterfaceMsgBusHelper()
{
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::SetSpec(UTbSame2SameStruct1InterfaceMsgBusSpec* /* InSpec */)
{
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::Prop1PropertyCb(const FTbSame2Struct1& Prop1)
{
	(void)Prop1;
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::Sig1SignalCb(const FTbSame2Struct1& Param1)
{
	(void)Param1;
}

void UTbSame2SameStruct1InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
