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
#include "TbSame2SameEnum2InterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "TbSame2/Generated/MsgBus/TbSame2SameEnum2InterfaceMsgBusClient.h"
#include "TbSame2/Generated/MsgBus/TbSame2SameEnum2InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

FTbSame2SameEnum2InterfaceMsgBusFixture::FTbSame2SameEnum2InterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameEnum2InterfaceMsgBusClient>();
}

FTbSame2SameEnum2InterfaceMsgBusFixture::~FTbSame2SameEnum2InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> FTbSame2SameEnum2InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame2SameEnum2InterfaceMsgBusAdapter* FTbSame2SameEnum2InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameEnum2InterfaceMsgBusAdapter>();
}

UGameInstance* FTbSame2SameEnum2InterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame2SameEnum2InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
