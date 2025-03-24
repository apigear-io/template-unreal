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
#include "Testbed1StructArrayInterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed1/Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusClient.h"
#include "Testbed1/Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructArrayInterface
{
namespace MsgBus
{
namespace Tests
{
FTestbed1StructArrayInterfaceMsgBusFixture::FTestbed1StructArrayInterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceMsgBusClient>();
}

FTestbed1StructArrayInterfaceMsgBusFixture::~FTestbed1StructArrayInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> FTestbed1StructArrayInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed1StructArrayInterfaceMsgBusAdapter* FTestbed1StructArrayInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceMsgBusAdapter>();
}

UGameInstance* FTestbed1StructArrayInterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed1StructArrayInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace StructArrayInterface
} // namespace Testbed1
#endif // WITH_DEV_AUTOMATION_TESTS
