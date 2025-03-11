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
#include "TbSame1SameStruct1InterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "TbSame1/Generated/MsgBus/TbSame1SameStruct1InterfaceMsgBusClient.h"
#include "TbSame1/Generated/MsgBus/TbSame1SameStruct1InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

FTbSame1SameStruct1InterfaceMsgBusFixture::FTbSame1SameStruct1InterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameStruct1InterfaceMsgBusClient>();
}

FTbSame1SameStruct1InterfaceMsgBusFixture::~FTbSame1SameStruct1InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> FTbSame1SameStruct1InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame1SameStruct1InterfaceMsgBusAdapter* FTbSame1SameStruct1InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameStruct1InterfaceMsgBusAdapter>();
}

UGameInstance* FTbSame1SameStruct1InterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame1SameStruct1InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
