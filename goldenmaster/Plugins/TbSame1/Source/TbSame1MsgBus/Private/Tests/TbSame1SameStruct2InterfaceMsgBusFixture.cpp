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
#include "TbSame1SameStruct2InterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSame1/Generated/MsgBus/TbSame1SameStruct2InterfaceMsgBusClient.h"
#include "TbSame1/Generated/MsgBus/TbSame1SameStruct2InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameStruct2Interface
{
namespace MsgBus
{
namespace Tests
{
FTbSame1SameStruct2InterfaceMsgBusFixture::FTbSame1SameStruct2InterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceMsgBusClient>();
}

FTbSame1SameStruct2InterfaceMsgBusFixture::~FTbSame1SameStruct2InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> FTbSame1SameStruct2InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame1SameStruct2InterfaceMsgBusAdapter* FTbSame1SameStruct2InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceMsgBusAdapter>();
}

UGameInstance* FTbSame1SameStruct2InterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame1SameStruct2InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace SameStruct2Interface
} // namespace TbSame1
#endif // WITH_DEV_AUTOMATION_TESTS
