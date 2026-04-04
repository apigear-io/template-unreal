// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSame1SameStruct2InterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSame1/Generated/MsgBus/TbSame1SameStruct2InterfaceMsgBusClient.h"
#include "TbSame1/Generated/MsgBus/TbSame1SameStruct2InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameStruct2Interface
{
namespace MsgBus
{
namespace Tests
{
FTbSame1SameStruct2InterfaceMsgBusFixture::FTbSame1SameStruct2InterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceMsgBusClient>();
}

FTbSame1SameStruct2InterfaceMsgBusFixture::~FTbSame1SameStruct2InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> FTbSame1SameStruct2InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame1SameStruct2InterfaceMsgBusAdapter* FTbSame1SameStruct2InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceMsgBusAdapter>();
}

UGameInstance* FTbSame1SameStruct2InterfaceMsgBusFixture::GetGameInstance()
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

void FTbSame1SameStruct2InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace SameStruct2Interface
} // namespace TbSame1
#endif // WITH_DEV_AUTOMATION_TESTS
