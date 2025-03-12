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
#include "TbSame2SameEnum1InterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbSame2/Generated/OLink/TbSame2SameEnum1InterfaceOLinkClient.h"
#include "TbSame2/Generated/OLink/TbSame2SameEnum1InterfaceOLinkAdapter.h"
#include "OLinkHost.h"

FTbSame2SameEnum1InterfaceOLinkFixture::FTbSame2SameEnum1InterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameEnum1InterfaceOLinkClient>();
}

FTbSame2SameEnum1InterfaceOLinkFixture::~FTbSame2SameEnum1InterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameEnum1InterfaceInterface> FTbSame2SameEnum1InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSame2SameEnum1InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSame2SameEnum1InterfaceOLinkAdapter* FTbSame2SameEnum1InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameEnum1InterfaceOLinkAdapter>();
}

UGameInstance* FTbSame2SameEnum1InterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame2SameEnum1InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
