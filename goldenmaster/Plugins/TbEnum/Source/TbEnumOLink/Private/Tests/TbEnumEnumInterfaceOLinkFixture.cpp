// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbEnumEnumInterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbEnum/Generated/OLink/TbEnumEnumInterfaceOLinkClient.h"
#include "TbEnum/Generated/OLink/TbEnumEnumInterfaceOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbEnum
{
namespace EnumInterface
{
namespace OLink
{
namespace Tests
{
FTbEnumEnumInterfaceOLinkFixture::FTbEnumEnumInterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceOLinkClient>();
}

FTbEnumEnumInterfaceOLinkFixture::~FTbEnumEnumInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbEnumEnumInterfaceInterface> FTbEnumEnumInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbEnumEnumInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbEnumEnumInterfaceOLinkAdapter* FTbEnumEnumInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceOLinkAdapter>();
}

UGameInstance* FTbEnumEnumInterfaceOLinkFixture::GetGameInstance()
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

void FTbEnumEnumInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace EnumInterface
} // namespace TbEnum

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
