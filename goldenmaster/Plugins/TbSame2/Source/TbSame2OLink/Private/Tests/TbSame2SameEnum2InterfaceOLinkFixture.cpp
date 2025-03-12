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
#include "TbSame2SameEnum2InterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbSame2/Generated/OLink/TbSame2SameEnum2InterfaceOLinkClient.h"
#include "TbSame2/Generated/OLink/TbSame2SameEnum2InterfaceOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameEnum2Interface
{
namespace OLink
{
namespace Tests
{
FTbSame2SameEnum2InterfaceOLinkFixture::FTbSame2SameEnum2InterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameEnum2InterfaceOLinkClient>();
}

FTbSame2SameEnum2InterfaceOLinkFixture::~FTbSame2SameEnum2InterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> FTbSame2SameEnum2InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSame2SameEnum2InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSame2SameEnum2InterfaceOLinkAdapter* FTbSame2SameEnum2InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameEnum2InterfaceOLinkAdapter>();
}

UGameInstance* FTbSame2SameEnum2InterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame2SameEnum2InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace SameEnum2Interface
} // namespace TbSame2

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
