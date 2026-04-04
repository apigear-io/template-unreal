// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSimpleSimpleInterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbSimple/Generated/OLink/TbSimpleSimpleInterfaceOLinkClient.h"
#include "TbSimple/Generated/OLink/TbSimpleSimpleInterfaceOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace SimpleInterface
{
namespace OLink
{
namespace Tests
{
FTbSimpleSimpleInterfaceOLinkFixture::FTbSimpleSimpleInterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleSimpleInterfaceOLinkClient>();
}

FTbSimpleSimpleInterfaceOLinkFixture::~FTbSimpleSimpleInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleSimpleInterfaceInterface> FTbSimpleSimpleInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSimpleSimpleInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSimpleSimpleInterfaceOLinkAdapter* FTbSimpleSimpleInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleSimpleInterfaceOLinkAdapter>();
}

UGameInstance* FTbSimpleSimpleInterfaceOLinkFixture::GetGameInstance()
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

void FTbSimpleSimpleInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace SimpleInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
