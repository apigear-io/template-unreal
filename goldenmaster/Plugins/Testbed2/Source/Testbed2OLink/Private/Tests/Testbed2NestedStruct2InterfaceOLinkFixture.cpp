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
#include "Testbed2NestedStruct2InterfaceOLinkFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "Testbed2/Generated/OLink/Testbed2NestedStruct2InterfaceOLinkClient.h"
#include "Testbed2/Generated/OLink/Testbed2NestedStruct2InterfaceOLinkAdapter.h"
#include "OLinkHost.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace NestedStruct2Interface
{
namespace OLink
{
namespace Tests
{
FTestbed2NestedStruct2InterfaceOLinkFixture::FTestbed2NestedStruct2InterfaceOLinkFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2NestedStruct2InterfaceOLinkClient>();
}

FTestbed2NestedStruct2InterfaceOLinkFixture::~FTestbed2NestedStruct2InterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> FTestbed2NestedStruct2InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTestbed2NestedStruct2InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTestbed2NestedStruct2InterfaceOLinkAdapter* FTestbed2NestedStruct2InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2NestedStruct2InterfaceOLinkAdapter>();
}

UGameInstance* FTestbed2NestedStruct2InterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed2NestedStruct2InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
} // namespace Tests
} // namespace OLink
} // namespace NestedStruct2Interface
} // namespace Testbed2

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
