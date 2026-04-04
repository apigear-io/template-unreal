// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbEnumEnumInterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbEnum/Generated/MsgBus/TbEnumEnumInterfaceMsgBusClient.h"
#include "TbEnum/Generated/MsgBus/TbEnumEnumInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbEnum
{
namespace EnumInterface
{
namespace MsgBus
{
namespace Tests
{
FTbEnumEnumInterfaceMsgBusFixture::FTbEnumEnumInterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceMsgBusClient>();
}

FTbEnumEnumInterfaceMsgBusFixture::~FTbEnumEnumInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbEnumEnumInterfaceInterface> FTbEnumEnumInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbEnumEnumInterfaceMsgBusAdapter* FTbEnumEnumInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceMsgBusAdapter>();
}

UGameInstance* FTbEnumEnumInterfaceMsgBusFixture::GetGameInstance()
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

void FTbEnumEnumInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace EnumInterface
} // namespace TbEnum
#endif // WITH_DEV_AUTOMATION_TESTS
