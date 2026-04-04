// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSimpleNoPropertiesInterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbSimple/Generated/OLink/TbSimpleNoPropertiesInterfaceOLinkClient.h"
#include "TbSimple/Generated/OLink/TbSimpleNoPropertiesInterfaceOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoPropertiesInterface
{
namespace OLink
{
namespace Tests
{
FTbSimpleNoPropertiesInterfaceOLinkFixture::FTbSimpleNoPropertiesInterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterfaceOLinkClient>();
}

FTbSimpleNoPropertiesInterfaceOLinkFixture::~FTbSimpleNoPropertiesInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> FTbSimpleNoPropertiesInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSimpleNoPropertiesInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSimpleNoPropertiesInterfaceOLinkAdapter* FTbSimpleNoPropertiesInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterfaceOLinkAdapter>();
}

UGameInstance* FTbSimpleNoPropertiesInterfaceOLinkFixture::GetGameInstance()
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

void FTbSimpleNoPropertiesInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace NoPropertiesInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
