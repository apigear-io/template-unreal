/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
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
