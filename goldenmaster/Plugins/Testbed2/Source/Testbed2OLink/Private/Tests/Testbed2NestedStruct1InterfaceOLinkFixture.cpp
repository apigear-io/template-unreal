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
#include "Testbed2NestedStruct1InterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "Testbed2/Generated/OLink/Testbed2NestedStruct1InterfaceOLinkClient.h"
#include "Testbed2/Generated/OLink/Testbed2NestedStruct1InterfaceOLinkAdapter.h"
#include "OLinkHost.h"

FTestbed2NestedStruct1InterfaceOLinkFixture::FTestbed2NestedStruct1InterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2NestedStruct1InterfaceOLinkClient>();
}

FTestbed2NestedStruct1InterfaceOLinkFixture::~FTestbed2NestedStruct1InterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> FTestbed2NestedStruct1InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTestbed2NestedStruct1InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTestbed2NestedStruct1InterfaceOLinkAdapter* FTestbed2NestedStruct1InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2NestedStruct1InterfaceOLinkAdapter>();
}

UGameInstance* FTestbed2NestedStruct1InterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed2NestedStruct1InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
