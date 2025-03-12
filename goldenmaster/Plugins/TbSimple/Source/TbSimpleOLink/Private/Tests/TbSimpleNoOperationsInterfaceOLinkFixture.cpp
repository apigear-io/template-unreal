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
#include "TbSimpleNoOperationsInterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbSimple/Generated/OLink/TbSimpleNoOperationsInterfaceOLinkClient.h"
#include "TbSimple/Generated/OLink/TbSimpleNoOperationsInterfaceOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoOperationsInterface
{
namespace OLink
{
namespace Tests
{
FTbSimpleNoOperationsInterfaceOLinkFixture::FTbSimpleNoOperationsInterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterfaceOLinkClient>();
}

FTbSimpleNoOperationsInterfaceOLinkFixture::~FTbSimpleNoOperationsInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> FTbSimpleNoOperationsInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSimpleNoOperationsInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSimpleNoOperationsInterfaceOLinkAdapter* FTbSimpleNoOperationsInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterfaceOLinkAdapter>();
}

UGameInstance* FTbSimpleNoOperationsInterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleNoOperationsInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace NoOperationsInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
