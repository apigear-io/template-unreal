// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbStructArrayStructArrayFieldInterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbStructArray/Generated/MsgBus/TbStructArrayStructArrayFieldInterfaceMsgBusClient.h"
#include "TbStructArray/Generated/MsgBus/TbStructArrayStructArrayFieldInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbStructArray
{
namespace StructArrayFieldInterface
{
namespace MsgBus
{
namespace Tests
{
FTbStructArrayStructArrayFieldInterfaceMsgBusFixture::FTbStructArrayStructArrayFieldInterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbStructArrayStructArrayFieldInterfaceMsgBusClient>();
}

FTbStructArrayStructArrayFieldInterfaceMsgBusFixture::~FTbStructArrayStructArrayFieldInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> FTbStructArrayStructArrayFieldInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbStructArrayStructArrayFieldInterfaceMsgBusAdapter* FTbStructArrayStructArrayFieldInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbStructArrayStructArrayFieldInterfaceMsgBusAdapter>();
}

UGameInstance* FTbStructArrayStructArrayFieldInterfaceMsgBusFixture::GetGameInstance()
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

void FTbStructArrayStructArrayFieldInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace StructArrayFieldInterface
} // namespace TbStructArray
#endif // WITH_DEV_AUTOMATION_TESTS
