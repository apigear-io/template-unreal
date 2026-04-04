// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbIfaceimportEmptyIfMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbIfaceimport/Generated/MsgBus/TbIfaceimportEmptyIfMsgBusClient.h"
#include "TbIfaceimport/Generated/MsgBus/TbIfaceimportEmptyIfMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbIfaceimport
{
namespace EmptyIf
{
namespace MsgBus
{
namespace Tests
{
FTbIfaceimportEmptyIfMsgBusFixture::FTbIfaceimportEmptyIfMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbIfaceimportEmptyIfMsgBusClient>();
}

FTbIfaceimportEmptyIfMsgBusFixture::~FTbIfaceimportEmptyIfMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbIfaceimportEmptyIfInterface> FTbIfaceimportEmptyIfMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbIfaceimportEmptyIfMsgBusAdapter* FTbIfaceimportEmptyIfMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbIfaceimportEmptyIfMsgBusAdapter>();
}

UGameInstance* FTbIfaceimportEmptyIfMsgBusFixture::GetGameInstance()
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

void FTbIfaceimportEmptyIfMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace EmptyIf
} // namespace TbIfaceimport
#endif // WITH_DEV_AUTOMATION_TESTS
