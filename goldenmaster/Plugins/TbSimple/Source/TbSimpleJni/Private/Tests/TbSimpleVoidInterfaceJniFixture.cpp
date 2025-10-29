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
#include "TbSimpleVoidInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Generated/Jni/TbSimpleVoidInterfaceJniClient.h"
#include "TbSimple/Generated/Jni/TbSimpleVoidInterfaceJniAdapter.h"
#include "TbSimple/Implementation/TbSimpleVoidInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace VoidInterface
{
namespace Jni
{
namespace Tests
{
FTbSimpleVoidInterfaceJniFixture::FTbSimpleVoidInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSimpleVoidInterfaceImplementation>();
}

FTbSimpleVoidInterfaceJniFixture::~FTbSimpleVoidInterfaceJniFixture()
{
	CleanUp();
}

UTbSimpleVoidInterfaceJniClient* FTbSimpleVoidInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleVoidInterfaceJniClient>();
}

TScriptInterface<ITbSimpleVoidInterfaceInterface> FTbSimpleVoidInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSimpleVoidInterfaceJniAdapter* FTbSimpleVoidInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleVoidInterfaceJniAdapter>();
}

UGameInstance* FTbSimpleVoidInterfaceJniFixture::GetGameInstance()
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

void FTbSimpleVoidInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace VoidInterface
} // namespace TbSimple
#endif // WITH_DEV_AUTOMATION_TESTS
