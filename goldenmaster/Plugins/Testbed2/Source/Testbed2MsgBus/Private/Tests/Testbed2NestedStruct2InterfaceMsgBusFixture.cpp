// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "Testbed2NestedStruct2InterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed2/Generated/MsgBus/Testbed2NestedStruct2InterfaceMsgBusClient.h"
#include "Testbed2/Generated/MsgBus/Testbed2NestedStruct2InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace NestedStruct2Interface
{
namespace MsgBus
{
namespace Tests
{
FTestbed2NestedStruct2InterfaceMsgBusFixture::FTestbed2NestedStruct2InterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2NestedStruct2InterfaceMsgBusClient>();
}

FTestbed2NestedStruct2InterfaceMsgBusFixture::~FTestbed2NestedStruct2InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> FTestbed2NestedStruct2InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed2NestedStruct2InterfaceMsgBusAdapter* FTestbed2NestedStruct2InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2NestedStruct2InterfaceMsgBusAdapter>();
}

UGameInstance* FTestbed2NestedStruct2InterfaceMsgBusFixture::GetGameInstance()
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

void FTestbed2NestedStruct2InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace NestedStruct2Interface
} // namespace Testbed2
#endif // WITH_DEV_AUTOMATION_TESTS
