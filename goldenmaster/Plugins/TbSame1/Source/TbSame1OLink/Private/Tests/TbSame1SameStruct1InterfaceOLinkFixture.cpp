// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSame1SameStruct1InterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbSame1/Generated/OLink/TbSame1SameStruct1InterfaceOLinkClient.h"
#include "TbSame1/Generated/OLink/TbSame1SameStruct1InterfaceOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameStruct1Interface
{
namespace OLink
{
namespace Tests
{
FTbSame1SameStruct1InterfaceOLinkFixture::FTbSame1SameStruct1InterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameStruct1InterfaceOLinkClient>();
}

FTbSame1SameStruct1InterfaceOLinkFixture::~FTbSame1SameStruct1InterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> FTbSame1SameStruct1InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSame1SameStruct1InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSame1SameStruct1InterfaceOLinkAdapter* FTbSame1SameStruct1InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameStruct1InterfaceOLinkAdapter>();
}

UGameInstance* FTbSame1SameStruct1InterfaceOLinkFixture::GetGameInstance()
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

void FTbSame1SameStruct1InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace SameStruct1Interface
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
