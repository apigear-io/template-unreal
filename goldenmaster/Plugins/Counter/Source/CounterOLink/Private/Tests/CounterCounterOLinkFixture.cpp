// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "CounterCounterOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "Counter/Generated/OLink/CounterCounterOLinkClient.h"
#include "Counter/Generated/OLink/CounterCounterOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Counter
{
namespace Counter
{
namespace OLink
{
namespace Tests
{
FCounterCounterOLinkFixture::FCounterCounterOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UCounterCounterOLinkClient>();
}

FCounterCounterOLinkFixture::~FCounterCounterOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ICounterCounterInterface> FCounterCounterOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FCounterCounterOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UCounterCounterOLinkAdapter* FCounterCounterOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UCounterCounterOLinkAdapter>();
}

UGameInstance* FCounterCounterOLinkFixture::GetGameInstance()
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

void FCounterCounterOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace Counter
} // namespace Counter

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
