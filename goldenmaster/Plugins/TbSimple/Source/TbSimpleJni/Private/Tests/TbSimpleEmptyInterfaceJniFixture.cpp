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
#include "TbSimpleEmptyInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Generated/Jni/TbSimpleEmptyInterfaceJniClient.h"
#include "TbSimple/Generated/Jni/TbSimpleEmptyInterfaceJniAdapter.h"
#include "TbSimple/Implementation/TbSimpleEmptyInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace EmptyInterface
{
namespace Jni
{
namespace Tests
{
FTbSimpleEmptyInterfaceJniFixture::FTbSimpleEmptyInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSimpleEmptyInterfaceImplementation>();
}

FTbSimpleEmptyInterfaceJniFixture::~FTbSimpleEmptyInterfaceJniFixture()
{
	CleanUp();
}

UTbSimpleEmptyInterfaceJniClient* FTbSimpleEmptyInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleEmptyInterfaceJniClient>();
}

TScriptInterface<ITbSimpleEmptyInterfaceInterface> FTbSimpleEmptyInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSimpleEmptyInterfaceJniAdapter* FTbSimpleEmptyInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleEmptyInterfaceJniAdapter>();
}

UGameInstance* FTbSimpleEmptyInterfaceJniFixture::GetGameInstance()
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

void FTbSimpleEmptyInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace EmptyInterface
} // namespace TbSimple
#endif // WITH_DEV_AUTOMATION_TESTS
