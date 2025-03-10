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
#include "TbSimpleVoidInterfaceMsgBusFixture.h"
#include "TbSimpleVoidInterfaceMsgBus.spec.h"
#include "TbSimple/Generated/MsgBus/TbSimpleVoidInterfaceMsgBusClient.h"
#include "TbSimple/Generated/MsgBus/TbSimpleVoidInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

UTbSimpleVoidInterfaceMsgBusHelper::~UTbSimpleVoidInterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSimpleVoidInterfaceMsgBusHelper::SetSpec(UTbSimpleVoidInterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleVoidInterfaceMsgBusHelper::SigVoidSignalCb()
{
	if (Spec)
	{
		Spec->SigVoidSignalCb();
	}
}

void UTbSimpleVoidInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTbSimpleVoidInterfaceMsgBusFixture::FTbSimpleVoidInterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSimpleVoidInterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleVoidInterfaceMsgBusClient>();
}

FTbSimpleVoidInterfaceMsgBusFixture::~FTbSimpleVoidInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleVoidInterfaceInterface> FTbSimpleVoidInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSimpleVoidInterfaceMsgBusAdapter* FTbSimpleVoidInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleVoidInterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSimpleVoidInterfaceMsgBusHelper> FTbSimpleVoidInterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleVoidInterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleVoidInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
// create empty implementation in case we do not want to do automated testing
UTbSimpleVoidInterfaceMsgBusHelper::~UTbSimpleVoidInterfaceMsgBusHelper()
{
}

void UTbSimpleVoidInterfaceMsgBusHelper::SetSpec(UTbSimpleVoidInterfaceMsgBusSpec* /* InSpec */)
{
}

void UTbSimpleVoidInterfaceMsgBusHelper::SigVoidSignalCb()
{
}

void UTbSimpleVoidInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
