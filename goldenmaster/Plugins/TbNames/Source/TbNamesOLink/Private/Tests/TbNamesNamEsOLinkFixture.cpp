// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbNamesNamEsOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbNames/Generated/OLink/TbNamesNamEsOLinkClient.h"
#include "TbNames/Generated/OLink/TbNamesNamEsOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbNames
{
namespace NamEs
{
namespace OLink
{
namespace Tests
{
FTbNamesNamEsOLinkFixture::FTbNamesNamEsOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbNamesNamEsOLinkClient>();
}

FTbNamesNamEsOLinkFixture::~FTbNamesNamEsOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbNamesNamEsInterface> FTbNamesNamEsOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbNamesNamEsOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbNamesNamEsOLinkAdapter* FTbNamesNamEsOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbNamesNamEsOLinkAdapter>();
}

UGameInstance* FTbNamesNamEsOLinkFixture::GetGameInstance()
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

void FTbNamesNamEsOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace NamEs
} // namespace TbNames

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
