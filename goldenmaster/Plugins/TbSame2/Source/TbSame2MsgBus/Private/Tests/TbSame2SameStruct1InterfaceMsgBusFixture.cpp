// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSame2SameStruct1InterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSame2/Generated/MsgBus/TbSame2SameStruct1InterfaceMsgBusClient.h"
#include "TbSame2/Generated/MsgBus/TbSame2SameStruct1InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameStruct1Interface
{
namespace MsgBus
{
namespace Tests
{
FTbSame2SameStruct1InterfaceMsgBusFixture::FTbSame2SameStruct1InterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameStruct1InterfaceMsgBusClient>();
}

FTbSame2SameStruct1InterfaceMsgBusFixture::~FTbSame2SameStruct1InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameStruct1InterfaceInterface> FTbSame2SameStruct1InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame2SameStruct1InterfaceMsgBusAdapter* FTbSame2SameStruct1InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameStruct1InterfaceMsgBusAdapter>();
}

UGameInstance* FTbSame2SameStruct1InterfaceMsgBusFixture::GetGameInstance()
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

void FTbSame2SameStruct1InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace SameStruct1Interface
} // namespace TbSame2
#endif // WITH_DEV_AUTOMATION_TESTS
