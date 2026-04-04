// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSimpleEmptyInterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Generated/MsgBus/TbSimpleEmptyInterfaceMsgBusClient.h"
#include "TbSimple/Generated/MsgBus/TbSimpleEmptyInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace EmptyInterface
{
namespace MsgBus
{
namespace Tests
{
FTbSimpleEmptyInterfaceMsgBusFixture::FTbSimpleEmptyInterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleEmptyInterfaceMsgBusClient>();
}

FTbSimpleEmptyInterfaceMsgBusFixture::~FTbSimpleEmptyInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleEmptyInterfaceInterface> FTbSimpleEmptyInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSimpleEmptyInterfaceMsgBusAdapter* FTbSimpleEmptyInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleEmptyInterfaceMsgBusAdapter>();
}

UGameInstance* FTbSimpleEmptyInterfaceMsgBusFixture::GetGameInstance()
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

void FTbSimpleEmptyInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace EmptyInterface
} // namespace TbSimple
#endif // WITH_DEV_AUTOMATION_TESTS
