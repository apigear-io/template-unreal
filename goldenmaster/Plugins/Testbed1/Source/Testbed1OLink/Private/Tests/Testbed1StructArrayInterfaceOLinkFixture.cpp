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
#include "Testbed1StructArrayInterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "Testbed1/Generated/OLink/Testbed1StructArrayInterfaceOLinkClient.h"
#include "Testbed1/Generated/OLink/Testbed1StructArrayInterfaceOLinkAdapter.h"
#include "OLinkHost.h"

FTestbed1StructArrayInterfaceOLinkFixture::FTestbed1StructArrayInterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceOLinkClient>();
}

FTestbed1StructArrayInterfaceOLinkFixture::~FTestbed1StructArrayInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> FTestbed1StructArrayInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTestbed1StructArrayInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTestbed1StructArrayInterfaceOLinkAdapter* FTestbed1StructArrayInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceOLinkAdapter>();
}

UGameInstance* FTestbed1StructArrayInterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed1StructArrayInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
