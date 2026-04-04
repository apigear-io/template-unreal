// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "Testbed1StructInterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed1/Generated/MsgBus/Testbed1StructInterfaceMsgBusClient.h"
#include "Testbed1/Generated/MsgBus/Testbed1StructInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructInterface
{
namespace MsgBus
{
namespace Tests
{
FTestbed1StructInterfaceMsgBusFixture::FTestbed1StructInterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructInterfaceMsgBusClient>();
}

FTestbed1StructInterfaceMsgBusFixture::~FTestbed1StructInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructInterfaceInterface> FTestbed1StructInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed1StructInterfaceMsgBusAdapter* FTestbed1StructInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructInterfaceMsgBusAdapter>();
}

UGameInstance* FTestbed1StructInterfaceMsgBusFixture::GetGameInstance()
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

void FTestbed1StructInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace StructInterface
} // namespace Testbed1
#endif // WITH_DEV_AUTOMATION_TESTS
