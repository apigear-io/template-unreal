// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "Testbed2ManyParamInterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed2/Generated/MsgBus/Testbed2ManyParamInterfaceMsgBusClient.h"
#include "Testbed2/Generated/MsgBus/Testbed2ManyParamInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace ManyParamInterface
{
namespace MsgBus
{
namespace Tests
{
FTestbed2ManyParamInterfaceMsgBusFixture::FTestbed2ManyParamInterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceMsgBusClient>();
}

FTestbed2ManyParamInterfaceMsgBusFixture::~FTestbed2ManyParamInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> FTestbed2ManyParamInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed2ManyParamInterfaceMsgBusAdapter* FTestbed2ManyParamInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceMsgBusAdapter>();
}

UGameInstance* FTestbed2ManyParamInterfaceMsgBusFixture::GetGameInstance()
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

void FTestbed2ManyParamInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace ManyParamInterface
} // namespace Testbed2
#endif // WITH_DEV_AUTOMATION_TESTS
