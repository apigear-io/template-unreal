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
#include "TbSame1SameEnum2InterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "TbSame1/Generated/MsgBus/TbSame1SameEnum2InterfaceMsgBusClient.h"
#include "TbSame1/Generated/MsgBus/TbSame1SameEnum2InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

FTbSame1SameEnum2InterfaceMsgBusFixture::FTbSame1SameEnum2InterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceMsgBusClient>();
}

FTbSame1SameEnum2InterfaceMsgBusFixture::~FTbSame1SameEnum2InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> FTbSame1SameEnum2InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame1SameEnum2InterfaceMsgBusAdapter* FTbSame1SameEnum2InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceMsgBusAdapter>();
}

UGameInstance* FTbSame1SameEnum2InterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame1SameEnum2InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
