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
#include "TbSimpleSimpleArrayInterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbSimple/Generated/OLink/TbSimpleSimpleArrayInterfaceOLinkClient.h"
#include "TbSimple/Generated/OLink/TbSimpleSimpleArrayInterfaceOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace SimpleArrayInterface
{
namespace OLink
{
namespace Tests
{
FTbSimpleSimpleArrayInterfaceOLinkFixture::FTbSimpleSimpleArrayInterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceOLinkClient>();
}

FTbSimpleSimpleArrayInterfaceOLinkFixture::~FTbSimpleSimpleArrayInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> FTbSimpleSimpleArrayInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSimpleSimpleArrayInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSimpleSimpleArrayInterfaceOLinkAdapter* FTbSimpleSimpleArrayInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceOLinkAdapter>();
}

UGameInstance* FTbSimpleSimpleArrayInterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleSimpleArrayInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace SimpleArrayInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
