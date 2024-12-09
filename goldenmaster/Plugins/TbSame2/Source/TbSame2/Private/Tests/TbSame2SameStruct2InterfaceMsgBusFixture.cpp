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
#include "TbSame2SameStruct2InterfaceMsgBusFixture.h"
#include "TbSame2SameStruct2InterfaceMsgBus.spec.h"
#include "Generated/MsgBus/TbSame2SameStruct2InterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSame2SameStruct2InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

UTbSame2SameStruct2InterfaceMsgBusHelper::~UTbSame2SameStruct2InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::SetSpec(UTbSame2SameStruct2InterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Prop1PropertyCb(const FTbSame2Struct2& Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyCb(Prop1);
	}
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Prop2PropertyCb(const FTbSame2Struct2& Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyCb(Prop2);
	}
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Sig1SignalCb(const FTbSame2Struct1& Param1)
{
	if (Spec)
	{
		Spec->Sig1SignalCb(Param1);
	}
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Sig2SignalCb(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	if (Spec)
	{
		Spec->Sig2SignalCb(Param1, Param2);
	}
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTbSame2SameStruct2InterfaceMsgBusFixture::FTbSame2SameStruct2InterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSame2SameStruct2InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameStruct2InterfaceMsgBusClient>();
}

FTbSame2SameStruct2InterfaceMsgBusFixture::~FTbSame2SameStruct2InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> FTbSame2SameStruct2InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame2SameStruct2InterfaceMsgBusAdapter* FTbSame2SameStruct2InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameStruct2InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSame2SameStruct2InterfaceMsgBusHelper> FTbSame2SameStruct2InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame2SameStruct2InterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame2SameStruct2InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
// create empty implementation in case we do not want to do automated testing
UTbSame2SameStruct2InterfaceMsgBusHelper::~UTbSame2SameStruct2InterfaceMsgBusHelper()
{
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::SetSpec(UTbSame2SameStruct2InterfaceMsgBusSpec* /* InSpec */)
{
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Prop1PropertyCb(const FTbSame2Struct2& Prop1)
{
	(void)Prop1;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Prop2PropertyCb(const FTbSame2Struct2& Prop2)
{
	(void)Prop2;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Sig1SignalCb(const FTbSame2Struct1& Param1)
{
	(void)Param1;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::Sig2SignalCb(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTbSame2SameStruct2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
