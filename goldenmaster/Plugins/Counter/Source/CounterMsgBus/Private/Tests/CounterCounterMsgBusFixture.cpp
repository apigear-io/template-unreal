// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "CounterCounterMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Counter/Generated/MsgBus/CounterCounterMsgBusClient.h"
#include "Counter/Generated/MsgBus/CounterCounterMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Counter
{
namespace Counter
{
namespace MsgBus
{
namespace Tests
{
FCounterCounterMsgBusFixture::FCounterCounterMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UCounterCounterMsgBusClient>();
}

FCounterCounterMsgBusFixture::~FCounterCounterMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ICounterCounterInterface> FCounterCounterMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UCounterCounterMsgBusAdapter* FCounterCounterMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UCounterCounterMsgBusAdapter>();
}

UGameInstance* FCounterCounterMsgBusFixture::GetGameInstance()
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

void FCounterCounterMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace Counter
} // namespace Counter
#endif // WITH_DEV_AUTOMATION_TESTS
