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
#include "TbSame2SameStruct2InterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "TbSame2/Generated/OLink/TbSame2SameStruct2InterfaceOLinkClient.h"
#include "TbSame2/Generated/OLink/TbSame2SameStruct2InterfaceOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameStruct2Interface
{
namespace OLink
{
namespace Tests
{
FTbSame2SameStruct2InterfaceOLinkFixture::FTbSame2SameStruct2InterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameStruct2InterfaceOLinkClient>();
}

FTbSame2SameStruct2InterfaceOLinkFixture::~FTbSame2SameStruct2InterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> FTbSame2SameStruct2InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSame2SameStruct2InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSame2SameStruct2InterfaceOLinkAdapter* FTbSame2SameStruct2InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameStruct2InterfaceOLinkAdapter>();
}

UGameInstance* FTbSame2SameStruct2InterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame2SameStruct2InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace SameStruct2Interface
} // namespace TbSame2

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
