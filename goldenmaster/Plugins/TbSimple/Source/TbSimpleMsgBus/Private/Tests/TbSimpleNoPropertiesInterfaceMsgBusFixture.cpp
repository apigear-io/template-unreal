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
#include "TbSimpleNoPropertiesInterfaceMsgBusFixture.h"
#include "TbSimpleNoPropertiesInterfaceMsgBus.spec.h"
#include "TbSimple/Generated/MsgBus/TbSimpleNoPropertiesInterfaceMsgBusClient.h"
#include "TbSimple/Generated/MsgBus/TbSimpleNoPropertiesInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

UTbSimpleNoPropertiesInterfaceMsgBusHelper::~UTbSimpleNoPropertiesInterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSimpleNoPropertiesInterfaceMsgBusHelper::SetSpec(UTbSimpleNoPropertiesInterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleNoPropertiesInterfaceMsgBusHelper::SigVoidSignalCb()
{
	if (Spec)
	{
		Spec->SigVoidSignalCb();
	}
}

void UTbSimpleNoPropertiesInterfaceMsgBusHelper::SigBoolSignalCb(bool bParamBool)
{
	if (Spec)
	{
		Spec->SigBoolSignalCb(bParamBool);
	}
}

void UTbSimpleNoPropertiesInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTbSimpleNoPropertiesInterfaceMsgBusFixture::FTbSimpleNoPropertiesInterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSimpleNoPropertiesInterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterfaceMsgBusClient>();
}

FTbSimpleNoPropertiesInterfaceMsgBusFixture::~FTbSimpleNoPropertiesInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> FTbSimpleNoPropertiesInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSimpleNoPropertiesInterfaceMsgBusAdapter* FTbSimpleNoPropertiesInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSimpleNoPropertiesInterfaceMsgBusHelper> FTbSimpleNoPropertiesInterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleNoPropertiesInterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleNoPropertiesInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
// create empty implementation in case we do not want to do automated testing
UTbSimpleNoPropertiesInterfaceMsgBusHelper::~UTbSimpleNoPropertiesInterfaceMsgBusHelper()
{
}

void UTbSimpleNoPropertiesInterfaceMsgBusHelper::SetSpec(UTbSimpleNoPropertiesInterfaceMsgBusSpec* /* InSpec */)
{
}

void UTbSimpleNoPropertiesInterfaceMsgBusHelper::SigVoidSignalCb()
{
}

void UTbSimpleNoPropertiesInterfaceMsgBusHelper::SigBoolSignalCb(bool bParamBool)
{
	(void)bParamBool;
}

void UTbSimpleNoPropertiesInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
