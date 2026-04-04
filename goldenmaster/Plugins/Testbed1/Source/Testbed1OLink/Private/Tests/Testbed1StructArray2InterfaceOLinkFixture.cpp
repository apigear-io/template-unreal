// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "Testbed1StructArray2InterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "Testbed1/Generated/OLink/Testbed1StructArray2InterfaceOLinkClient.h"
#include "Testbed1/Generated/OLink/Testbed1StructArray2InterfaceOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructArray2Interface
{
namespace OLink
{
namespace Tests
{
FTestbed1StructArray2InterfaceOLinkFixture::FTestbed1StructArray2InterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceOLinkClient>();
}

FTestbed1StructArray2InterfaceOLinkFixture::~FTestbed1StructArray2InterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructArray2InterfaceInterface> FTestbed1StructArray2InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTestbed1StructArray2InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTestbed1StructArray2InterfaceOLinkAdapter* FTestbed1StructArray2InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceOLinkAdapter>();
}

UGameInstance* FTestbed1StructArray2InterfaceOLinkFixture::GetGameInstance()
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

void FTestbed1StructArray2InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace StructArray2Interface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
