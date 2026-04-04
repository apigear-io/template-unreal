// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbNamesNamEsMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbNames/Generated/MsgBus/TbNamesNamEsMsgBusClient.h"
#include "TbNames/Generated/MsgBus/TbNamesNamEsMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbNames
{
namespace NamEs
{
namespace MsgBus
{
namespace Tests
{
FTbNamesNamEsMsgBusFixture::FTbNamesNamEsMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbNamesNamEsMsgBusClient>();
}

FTbNamesNamEsMsgBusFixture::~FTbNamesNamEsMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbNamesNamEsInterface> FTbNamesNamEsMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbNamesNamEsMsgBusAdapter* FTbNamesNamEsMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbNamesNamEsMsgBusAdapter>();
}

UGameInstance* FTbNamesNamEsMsgBusFixture::GetGameInstance()
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

void FTbNamesNamEsMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace NamEs
} // namespace TbNames
#endif // WITH_DEV_AUTOMATION_TESTS
