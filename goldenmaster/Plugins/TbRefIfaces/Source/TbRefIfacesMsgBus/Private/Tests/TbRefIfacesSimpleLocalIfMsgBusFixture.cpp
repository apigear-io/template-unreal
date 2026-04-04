// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbRefIfacesSimpleLocalIfMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbRefIfaces/Generated/MsgBus/TbRefIfacesSimpleLocalIfMsgBusClient.h"
#include "TbRefIfaces/Generated/MsgBus/TbRefIfacesSimpleLocalIfMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace SimpleLocalIf
{
namespace MsgBus
{
namespace Tests
{
FTbRefIfacesSimpleLocalIfMsgBusFixture::FTbRefIfacesSimpleLocalIfMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbRefIfacesSimpleLocalIfMsgBusClient>();
}

FTbRefIfacesSimpleLocalIfMsgBusFixture::~FTbRefIfacesSimpleLocalIfMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> FTbRefIfacesSimpleLocalIfMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbRefIfacesSimpleLocalIfMsgBusAdapter* FTbRefIfacesSimpleLocalIfMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbRefIfacesSimpleLocalIfMsgBusAdapter>();
}

UGameInstance* FTbRefIfacesSimpleLocalIfMsgBusFixture::GetGameInstance()
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

void FTbRefIfacesSimpleLocalIfMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace SimpleLocalIf
} // namespace TbRefIfaces
#endif // WITH_DEV_AUTOMATION_TESTS
