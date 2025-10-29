/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "CounterCounterJniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "Counter/Generated/Jni/CounterCounterJniClient.h"
#include "Counter/Generated/Jni/CounterCounterJniAdapter.h"
#include "Counter/Implementation/CounterCounter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Counter
{
namespace Counter
{
namespace Jni
{
namespace Tests
{
FCounterCounterJniFixture::FCounterCounterJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UCounterCounterImplementation>();
}

FCounterCounterJniFixture::~FCounterCounterJniFixture()
{
	CleanUp();
}

UCounterCounterJniClient* FCounterCounterJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UCounterCounterJniClient>();
}

TScriptInterface<ICounterCounterInterface> FCounterCounterJniFixture::GetLocalImplementation()
{
	return source;
}

UCounterCounterJniAdapter* FCounterCounterJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UCounterCounterJniAdapter>();
}

UGameInstance* FCounterCounterJniFixture::GetGameInstance()
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

void FCounterCounterJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace Counter
} // namespace Counter
#endif // WITH_DEV_AUTOMATION_TESTS
