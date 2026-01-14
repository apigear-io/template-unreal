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
#include "TbEnumEnumInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbEnum/Generated/Jni/TbEnumEnumInterfaceJniClient.h"
#include "TbEnum/Generated/Jni/TbEnumEnumInterfaceJniAdapter.h"
#include "TbEnum/Implementation/TbEnumEnumInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbEnum
{
namespace EnumInterface
{
namespace Jni
{
namespace Tests
{
FTbEnumEnumInterfaceJniFixture::FTbEnumEnumInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceImplementation>();
}

FTbEnumEnumInterfaceJniFixture::~FTbEnumEnumInterfaceJniFixture()
{
	CleanUp();
}

UTbEnumEnumInterfaceJniClient* FTbEnumEnumInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceJniClient>();
}

TScriptInterface<ITbEnumEnumInterfaceInterface> FTbEnumEnumInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbEnumEnumInterfaceJniAdapter* FTbEnumEnumInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceJniAdapter>();
}

UGameInstance* FTbEnumEnumInterfaceJniFixture::GetGameInstance()
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

void FTbEnumEnumInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace EnumInterface
} // namespace TbEnum
#endif // WITH_DEV_AUTOMATION_TESTS
