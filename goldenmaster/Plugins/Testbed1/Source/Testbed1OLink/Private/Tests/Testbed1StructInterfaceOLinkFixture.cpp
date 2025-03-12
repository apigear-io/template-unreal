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
#include "Testbed1StructInterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "Testbed1/Generated/OLink/Testbed1StructInterfaceOLinkClient.h"
#include "Testbed1/Generated/OLink/Testbed1StructInterfaceOLinkAdapter.h"
#include "OLinkHost.h"

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
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed1StructInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
