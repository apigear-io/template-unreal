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
#include "TbSimpleEmptyInterfaceMsgBusFixture.h"
#include "TbSimpleEmptyInterfaceMsgBus.spec.h"
#include "Generated/MsgBus/TbSimpleEmptyInterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSimpleEmptyInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTbSimpleEmptyInterfaceMsgBusHelper::~UTbSimpleEmptyInterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSimpleEmptyInterfaceMsgBusHelper::SetSpec(UTbSimpleEmptyInterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleEmptyInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTbSimpleEmptyInterfaceMsgBusFixture::FTbSimpleEmptyInterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSimpleEmptyInterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleEmptyInterfaceMsgBusClient>();
}

FTbSimpleEmptyInterfaceMsgBusFixture::~FTbSimpleEmptyInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleEmptyInterfaceInterface> FTbSimpleEmptyInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSimpleEmptyInterfaceMsgBusAdapter* FTbSimpleEmptyInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleEmptyInterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSimpleEmptyInterfaceMsgBusHelper> FTbSimpleEmptyInterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleEmptyInterfaceMsgBusFixture::GetGameInstance()
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

void FTbSimpleEmptyInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTbSimpleEmptyInterfaceMsgBusHelper::~UTbSimpleEmptyInterfaceMsgBusHelper()
{
}

void UTbSimpleEmptyInterfaceMsgBusHelper::SetSpec(UTbSimpleEmptyInterfaceMsgBusSpec* /* InSpec */)
{
}

void UTbSimpleEmptyInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
