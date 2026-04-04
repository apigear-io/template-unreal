// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSame2SameEnum2InterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSame2/Generated/MsgBus/TbSame2SameEnum2InterfaceMsgBusClient.h"
#include "TbSame2/Generated/MsgBus/TbSame2SameEnum2InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameEnum2Interface
{
namespace MsgBus
{
namespace Tests
{
FTbSame2SameEnum2InterfaceMsgBusFixture::FTbSame2SameEnum2InterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameEnum2InterfaceMsgBusClient>();
}

FTbSame2SameEnum2InterfaceMsgBusFixture::~FTbSame2SameEnum2InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> FTbSame2SameEnum2InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame2SameEnum2InterfaceMsgBusAdapter* FTbSame2SameEnum2InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameEnum2InterfaceMsgBusAdapter>();
}

UGameInstance* FTbSame2SameEnum2InterfaceMsgBusFixture::GetGameInstance()
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

void FTbSame2SameEnum2InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace SameEnum2Interface
} // namespace TbSame2
#endif // WITH_DEV_AUTOMATION_TESTS
