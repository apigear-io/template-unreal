// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbRefIfacesSimpleLocalIfOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbRefIfaces/Generated/OLink/TbRefIfacesSimpleLocalIfOLinkClient.h"
#include "TbRefIfaces/Generated/OLink/TbRefIfacesSimpleLocalIfOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace SimpleLocalIf
{
namespace OLink
{
namespace Tests
{
FTbRefIfacesSimpleLocalIfOLinkFixture::FTbRefIfacesSimpleLocalIfOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbRefIfacesSimpleLocalIfOLinkClient>();
}

FTbRefIfacesSimpleLocalIfOLinkFixture::~FTbRefIfacesSimpleLocalIfOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> FTbRefIfacesSimpleLocalIfOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbRefIfacesSimpleLocalIfOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbRefIfacesSimpleLocalIfOLinkAdapter* FTbRefIfacesSimpleLocalIfOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbRefIfacesSimpleLocalIfOLinkAdapter>();
}

UGameInstance* FTbRefIfacesSimpleLocalIfOLinkFixture::GetGameInstance()
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

void FTbRefIfacesSimpleLocalIfOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace SimpleLocalIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
