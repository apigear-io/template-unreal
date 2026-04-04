// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSimpleNoSignalsInterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Generated/MsgBus/TbSimpleNoSignalsInterfaceMsgBusClient.h"
#include "TbSimple/Generated/MsgBus/TbSimpleNoSignalsInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoSignalsInterface
{
namespace MsgBus
{
namespace Tests
{
FTbSimpleNoSignalsInterfaceMsgBusFixture::FTbSimpleNoSignalsInterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoSignalsInterfaceMsgBusClient>();
}

FTbSimpleNoSignalsInterfaceMsgBusFixture::~FTbSimpleNoSignalsInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> FTbSimpleNoSignalsInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSimpleNoSignalsInterfaceMsgBusAdapter* FTbSimpleNoSignalsInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoSignalsInterfaceMsgBusAdapter>();
}

UGameInstance* FTbSimpleNoSignalsInterfaceMsgBusFixture::GetGameInstance()
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

void FTbSimpleNoSignalsInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace NoSignalsInterface
} // namespace TbSimple
#endif // WITH_DEV_AUTOMATION_TESTS
