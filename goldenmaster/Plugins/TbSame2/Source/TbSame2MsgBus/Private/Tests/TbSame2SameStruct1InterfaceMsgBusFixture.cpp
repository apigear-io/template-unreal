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
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSame2/Generated/MsgBus/TbSame2SameStruct1InterfaceMsgBusClient.h"
#include "TbSame2/Generated/MsgBus/TbSame2SameStruct1InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameStruct1Interface
{
namespace MsgBus
{
namespace Tests
{
FTbSame2SameStruct1InterfaceMsgBusFixture::FTbSame2SameStruct1InterfaceMsgBusFixture()
{
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
} // namespace Tests
} // namespace MsgBus
} // namespace SameStruct1Interface
} // namespace TbSame2
#endif // WITH_DEV_AUTOMATION_TESTS
