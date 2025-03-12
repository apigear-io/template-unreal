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
#include "TbEnumEnumInterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbEnum/Generated/OLink/TbEnumEnumInterfaceOLinkClient.h"
#include "TbEnum/Generated/OLink/TbEnumEnumInterfaceOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbEnum
{
namespace EnumInterface
{
namespace OLink
{
namespace Tests
{
FTbEnumEnumInterfaceOLinkFixture::FTbEnumEnumInterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceOLinkClient>();
}

FTbEnumEnumInterfaceOLinkFixture::~FTbEnumEnumInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbEnumEnumInterfaceInterface> FTbEnumEnumInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbEnumEnumInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbEnumEnumInterfaceOLinkAdapter* FTbEnumEnumInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceOLinkAdapter>();
}

UGameInstance* FTbEnumEnumInterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbEnumEnumInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace EnumInterface
} // namespace TbEnum

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
