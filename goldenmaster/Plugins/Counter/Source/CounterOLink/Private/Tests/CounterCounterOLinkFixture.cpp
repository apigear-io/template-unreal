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
#include "CounterCounterOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "Counter/Generated/OLink/CounterCounterOLinkClient.h"
#include "Counter/Generated/OLink/CounterCounterOLinkAdapter.h"
#include "OLinkHost.h"

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
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FCounterCounterOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
