// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSimpleSimpleArrayInterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbSimple/Generated/OLink/TbSimpleSimpleArrayInterfaceOLinkClient.h"
#include "TbSimple/Generated/OLink/TbSimpleSimpleArrayInterfaceOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace SimpleArrayInterface
{
namespace OLink
{
namespace Tests
{
FTbSimpleSimpleArrayInterfaceOLinkFixture::FTbSimpleSimpleArrayInterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceOLinkClient>();
}

FTbSimpleSimpleArrayInterfaceOLinkFixture::~FTbSimpleSimpleArrayInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> FTbSimpleSimpleArrayInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSimpleSimpleArrayInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSimpleSimpleArrayInterfaceOLinkAdapter* FTbSimpleSimpleArrayInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceOLinkAdapter>();
}

UGameInstance* FTbSimpleSimpleArrayInterfaceOLinkFixture::GetGameInstance()
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

void FTbSimpleSimpleArrayInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace SimpleArrayInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
