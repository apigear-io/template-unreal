// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbRefIfacesParentIfOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbRefIfaces/Generated/OLink/TbRefIfacesParentIfOLinkClient.h"
#include "TbRefIfaces/Generated/OLink/TbRefIfacesParentIfOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace ParentIf
{
namespace OLink
{
namespace Tests
{
FTbRefIfacesParentIfOLinkFixture::FTbRefIfacesParentIfOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbRefIfacesParentIfOLinkClient>();
}

FTbRefIfacesParentIfOLinkFixture::~FTbRefIfacesParentIfOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbRefIfacesParentIfInterface> FTbRefIfacesParentIfOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbRefIfacesParentIfOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbRefIfacesParentIfOLinkAdapter* FTbRefIfacesParentIfOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbRefIfacesParentIfOLinkAdapter>();
}

UGameInstance* FTbRefIfacesParentIfOLinkFixture::GetGameInstance()
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

void FTbRefIfacesParentIfOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace ParentIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
