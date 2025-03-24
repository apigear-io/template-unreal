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
#include "TbSimpleSimpleArrayInterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Generated/MsgBus/TbSimpleSimpleArrayInterfaceMsgBusClient.h"
#include "TbSimple/Generated/MsgBus/TbSimpleSimpleArrayInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace SimpleArrayInterface
{
namespace MsgBus
{
namespace Tests
{
FTbSimpleSimpleArrayInterfaceMsgBusFixture::FTbSimpleSimpleArrayInterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceMsgBusClient>();
}

FTbSimpleSimpleArrayInterfaceMsgBusFixture::~FTbSimpleSimpleArrayInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> FTbSimpleSimpleArrayInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSimpleSimpleArrayInterfaceMsgBusAdapter* FTbSimpleSimpleArrayInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceMsgBusAdapter>();
}

UGameInstance* FTbSimpleSimpleArrayInterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleSimpleArrayInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace SimpleArrayInterface
} // namespace TbSimple
#endif // WITH_DEV_AUTOMATION_TESTS
