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
#include "TbSimpleNoSignalsInterfaceMsgBusFixture.h"
#include "TbSimpleNoSignalsInterfaceMsgBus.spec.h"
#include "Generated/MsgBus/TbSimpleNoSignalsInterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSimpleNoSignalsInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

UTbSimpleNoSignalsInterfaceMsgBusHelper::~UTbSimpleNoSignalsInterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSimpleNoSignalsInterfaceMsgBusHelper::SetSpec(UTbSimpleNoSignalsInterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleNoSignalsInterfaceMsgBusHelper::PropBoolPropertyCb(bool bPropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyCb(bPropBool);
	}
}

void UTbSimpleNoSignalsInterfaceMsgBusHelper::PropIntPropertyCb(int32 PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyCb(PropInt);
	}
}

void UTbSimpleNoSignalsInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTbSimpleNoSignalsInterfaceMsgBusFixture::FTbSimpleNoSignalsInterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSimpleNoSignalsInterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoSignalsInterfaceMsgBusClient>();
}

FTbSimpleNoSignalsInterfaceMsgBusFixture::~FTbSimpleNoSignalsInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> FTbSimpleNoSignalsInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSimpleNoSignalsInterfaceMsgBusAdapter* FTbSimpleNoSignalsInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoSignalsInterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSimpleNoSignalsInterfaceMsgBusHelper> FTbSimpleNoSignalsInterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleNoSignalsInterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleNoSignalsInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
// create empty implementation in case we do not want to do automated testing
UTbSimpleNoSignalsInterfaceMsgBusHelper::~UTbSimpleNoSignalsInterfaceMsgBusHelper()
{
}

void UTbSimpleNoSignalsInterfaceMsgBusHelper::SetSpec(UTbSimpleNoSignalsInterfaceMsgBusSpec* /* InSpec */)
{
}

void UTbSimpleNoSignalsInterfaceMsgBusHelper::PropBoolPropertyCb(bool bPropBool)
{
	(void)bPropBool;
}

void UTbSimpleNoSignalsInterfaceMsgBusHelper::PropIntPropertyCb(int32 PropInt)
{
	(void)PropInt;
}

void UTbSimpleNoSignalsInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
