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
#include "TbSame2SameEnum2InterfaceJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSame2/Generated/Jni/TbSame2SameEnum2InterfaceJniClient.h"
#include "TbSame2/Generated/Jni/TbSame2SameEnum2InterfaceJniAdapter.h"
#include "TbSame2/Implementation/TbSame2SameEnum2Interface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameEnum2Interface
{
namespace Jni
{
namespace Tests
{
FTbSame2SameEnum2InterfaceJniFixture::FTbSame2SameEnum2InterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSame2SameEnum2InterfaceImplementation>();
}

FTbSame2SameEnum2InterfaceJniFixture::~FTbSame2SameEnum2InterfaceJniFixture()
{
	CleanUp();
}

UTbSame2SameEnum2InterfaceJniClient* FTbSame2SameEnum2InterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameEnum2InterfaceJniClient>();
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> FTbSame2SameEnum2InterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSame2SameEnum2InterfaceJniAdapter* FTbSame2SameEnum2InterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameEnum2InterfaceJniAdapter>();
}

UGameInstance* FTbSame2SameEnum2InterfaceJniFixture::GetGameInstance()
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

void FTbSame2SameEnum2InterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace SameEnum2Interface
} // namespace TbSame2
#endif // WITH_DEV_AUTOMATION_TESTS
