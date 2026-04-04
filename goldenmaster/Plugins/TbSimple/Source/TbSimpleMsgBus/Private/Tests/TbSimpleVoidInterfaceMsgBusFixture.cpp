// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSimpleVoidInterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Generated/MsgBus/TbSimpleVoidInterfaceMsgBusClient.h"
#include "TbSimple/Generated/MsgBus/TbSimpleVoidInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace VoidInterface
{
namespace MsgBus
{
namespace Tests
{
FTbSimpleVoidInterfaceMsgBusFixture::FTbSimpleVoidInterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleVoidInterfaceMsgBusClient>();
}

FTbSimpleVoidInterfaceMsgBusFixture::~FTbSimpleVoidInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleVoidInterfaceInterface> FTbSimpleVoidInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSimpleVoidInterfaceMsgBusAdapter* FTbSimpleVoidInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleVoidInterfaceMsgBusAdapter>();
}

UGameInstance* FTbSimpleVoidInterfaceMsgBusFixture::GetGameInstance()
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

void FTbSimpleVoidInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace VoidInterface
} // namespace TbSimple
#endif // WITH_DEV_AUTOMATION_TESTS
