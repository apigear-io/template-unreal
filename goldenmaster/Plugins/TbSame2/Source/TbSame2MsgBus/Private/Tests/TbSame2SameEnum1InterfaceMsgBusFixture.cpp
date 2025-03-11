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
#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "TbSame2/Generated/MsgBus/TbSame2SameEnum1InterfaceMsgBusClient.h"
#include "TbSame2/Generated/MsgBus/TbSame2SameEnum1InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

FTbSame2SameEnum1InterfaceMsgBusFixture::FTbSame2SameEnum1InterfaceMsgBusFixture()
{
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
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
