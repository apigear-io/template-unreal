// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSimpleNoOperationsInterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Generated/MsgBus/TbSimpleNoOperationsInterfaceMsgBusClient.h"
#include "TbSimple/Generated/MsgBus/TbSimpleNoOperationsInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoOperationsInterface
{
namespace MsgBus
{
namespace Tests
{
FTbSimpleNoOperationsInterfaceMsgBusFixture::FTbSimpleNoOperationsInterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterfaceMsgBusClient>();
}

FTbSimpleNoOperationsInterfaceMsgBusFixture::~FTbSimpleNoOperationsInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> FTbSimpleNoOperationsInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSimpleNoOperationsInterfaceMsgBusAdapter* FTbSimpleNoOperationsInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterfaceMsgBusAdapter>();
}

UGameInstance* FTbSimpleNoOperationsInterfaceMsgBusFixture::GetGameInstance()
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

void FTbSimpleNoOperationsInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace NoOperationsInterface
} // namespace TbSimple
#endif // WITH_DEV_AUTOMATION_TESTS
