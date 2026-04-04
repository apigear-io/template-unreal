// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbStructArrayStructArrayFieldInterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbStructArray/Generated/OLink/TbStructArrayStructArrayFieldInterfaceOLinkClient.h"
#include "TbStructArray/Generated/OLink/TbStructArrayStructArrayFieldInterfaceOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbStructArray
{
namespace StructArrayFieldInterface
{
namespace OLink
{
namespace Tests
{
FTbStructArrayStructArrayFieldInterfaceOLinkFixture::FTbStructArrayStructArrayFieldInterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbStructArrayStructArrayFieldInterfaceOLinkClient>();
}

FTbStructArrayStructArrayFieldInterfaceOLinkFixture::~FTbStructArrayStructArrayFieldInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> FTbStructArrayStructArrayFieldInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbStructArrayStructArrayFieldInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbStructArrayStructArrayFieldInterfaceOLinkAdapter* FTbStructArrayStructArrayFieldInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbStructArrayStructArrayFieldInterfaceOLinkAdapter>();
}

UGameInstance* FTbStructArrayStructArrayFieldInterfaceOLinkFixture::GetGameInstance()
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

void FTbStructArrayStructArrayFieldInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace StructArrayFieldInterface
} // namespace TbStructArray

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
