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
#include "Testbed2ManyParamInterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "Testbed2/Generated/OLink/Testbed2ManyParamInterfaceOLinkClient.h"
#include "Testbed2/Generated/OLink/Testbed2ManyParamInterfaceOLinkAdapter.h"
#include "OLinkHost.h"

FTestbed2ManyParamInterfaceOLinkFixture::FTestbed2ManyParamInterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceOLinkClient>();
}

FTestbed2ManyParamInterfaceOLinkFixture::~FTestbed2ManyParamInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> FTestbed2ManyParamInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTestbed2ManyParamInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTestbed2ManyParamInterfaceOLinkAdapter* FTestbed2ManyParamInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceOLinkAdapter>();
}

UGameInstance* FTestbed2ManyParamInterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed2ManyParamInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
