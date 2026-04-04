// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
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
		GameInstance = NewObject<UGameInstance>(GetTransientPackage());
		GameInstance->Init();
		// needed to prevent garbage collection and we can't use UPROPERTY on raw c++ objects
		GameInstance->AddToRoot();
	}

	return GameInstance.Get();
}

void FTestbed1StructArrayInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace StructArrayInterface
} // namespace Testbed1
#endif // WITH_DEV_AUTOMATION_TESTS
