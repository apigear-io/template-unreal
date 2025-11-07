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
#include "TbSimpleNoSignalsInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Generated/Jni/TbSimpleNoSignalsInterfaceJniClient.h"
#include "TbSimple/Generated/Jni/TbSimpleNoSignalsInterfaceJniAdapter.h"
#include "TbSimple/Implementation/TbSimpleNoSignalsInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoSignalsInterface
{
namespace Jni
{
namespace Tests
{
FTbSimpleNoSignalsInterfaceJniFixture::FTbSimpleNoSignalsInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSimpleNoSignalsInterfaceImplementation>();
}

FTbSimpleNoSignalsInterfaceJniFixture::~FTbSimpleNoSignalsInterfaceJniFixture()
{
	CleanUp();
}

UTbSimpleNoSignalsInterfaceJniClient* FTbSimpleNoSignalsInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoSignalsInterfaceJniClient>();
}

TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> FTbSimpleNoSignalsInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSimpleNoSignalsInterfaceJniAdapter* FTbSimpleNoSignalsInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoSignalsInterfaceJniAdapter>();
}

UGameInstance* FTbSimpleNoSignalsInterfaceJniFixture::GetGameInstance()
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

void FTbSimpleNoSignalsInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace NoSignalsInterface
} // namespace TbSimple
#endif // WITH_DEV_AUTOMATION_TESTS
