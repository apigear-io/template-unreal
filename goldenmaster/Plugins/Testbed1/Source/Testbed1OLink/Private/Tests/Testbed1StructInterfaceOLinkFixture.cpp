// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "Testbed1StructInterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "Testbed1/Generated/OLink/Testbed1StructInterfaceOLinkClient.h"
#include "Testbed1/Generated/OLink/Testbed1StructInterfaceOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructInterface
{
namespace OLink
{
namespace Tests
{
FTestbed1StructInterfaceOLinkFixture::FTestbed1StructInterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructInterfaceOLinkClient>();
}

FTestbed1StructInterfaceOLinkFixture::~FTestbed1StructInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructInterfaceInterface> FTestbed1StructInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTestbed1StructInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTestbed1StructInterfaceOLinkAdapter* FTestbed1StructInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructInterfaceOLinkAdapter>();
}

UGameInstance* FTestbed1StructInterfaceOLinkFixture::GetGameInstance()
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

void FTestbed1StructInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace StructInterface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
