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
#include "TbSimpleNoPropertiesInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Generated/Jni/TbSimpleNoPropertiesInterfaceJniClient.h"
#include "TbSimple/Generated/Jni/TbSimpleNoPropertiesInterfaceJniAdapter.h"
#include "TbSimple/Implementation/TbSimpleNoPropertiesInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoPropertiesInterface
{
namespace Jni
{
namespace Tests
{
FTbSimpleNoPropertiesInterfaceJniFixture::FTbSimpleNoPropertiesInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterfaceImplementation>();
}

FTbSimpleNoPropertiesInterfaceJniFixture::~FTbSimpleNoPropertiesInterfaceJniFixture()
{
	CleanUp();
}

UTbSimpleNoPropertiesInterfaceJniClient* FTbSimpleNoPropertiesInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterfaceJniClient>();
}

TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> FTbSimpleNoPropertiesInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSimpleNoPropertiesInterfaceJniAdapter* FTbSimpleNoPropertiesInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterfaceJniAdapter>();
}

UGameInstance* FTbSimpleNoPropertiesInterfaceJniFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>(GetTransientPackage());
		GameInstance->Init();
		// needed to prevent garbage collection and we can't use UPROPERTY on raw c++ objects
		GameInstance->AddToRoot();
	}

	return GameInstance.Get();
}

void FTbSimpleNoPropertiesInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace NoPropertiesInterface
} // namespace TbSimple
#endif // WITH_DEV_AUTOMATION_TESTS
