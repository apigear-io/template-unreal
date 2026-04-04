// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSimpleNoPropertiesInterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Generated/MsgBus/TbSimpleNoPropertiesInterfaceMsgBusClient.h"
#include "TbSimple/Generated/MsgBus/TbSimpleNoPropertiesInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoPropertiesInterface
{
namespace MsgBus
{
namespace Tests
{
FTbSimpleNoPropertiesInterfaceMsgBusFixture::FTbSimpleNoPropertiesInterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterfaceMsgBusClient>();
}

FTbSimpleNoPropertiesInterfaceMsgBusFixture::~FTbSimpleNoPropertiesInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> FTbSimpleNoPropertiesInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSimpleNoPropertiesInterfaceMsgBusAdapter* FTbSimpleNoPropertiesInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterfaceMsgBusAdapter>();
}

UGameInstance* FTbSimpleNoPropertiesInterfaceMsgBusFixture::GetGameInstance()
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

void FTbSimpleNoPropertiesInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace NoPropertiesInterface
} // namespace TbSimple
#endif // WITH_DEV_AUTOMATION_TESTS
