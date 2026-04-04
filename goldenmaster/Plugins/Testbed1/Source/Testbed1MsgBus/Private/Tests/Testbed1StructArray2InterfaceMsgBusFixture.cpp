// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "Testbed1StructArray2InterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed1/Generated/MsgBus/Testbed1StructArray2InterfaceMsgBusClient.h"
#include "Testbed1/Generated/MsgBus/Testbed1StructArray2InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructArray2Interface
{
namespace MsgBus
{
namespace Tests
{
FTestbed1StructArray2InterfaceMsgBusFixture::FTestbed1StructArray2InterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceMsgBusClient>();
}

FTestbed1StructArray2InterfaceMsgBusFixture::~FTestbed1StructArray2InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructArray2InterfaceInterface> FTestbed1StructArray2InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed1StructArray2InterfaceMsgBusAdapter* FTestbed1StructArray2InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceMsgBusAdapter>();
}

UGameInstance* FTestbed1StructArray2InterfaceMsgBusFixture::GetGameInstance()
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

void FTestbed1StructArray2InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace StructArray2Interface
} // namespace Testbed1
#endif // WITH_DEV_AUTOMATION_TESTS
