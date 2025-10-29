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
#include "TbSame1SameEnum1InterfaceJniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "TbSame1/Generated/Jni/TbSame1SameEnum1InterfaceJniClient.h"
#include "TbSame1/Generated/Jni/TbSame1SameEnum1InterfaceJniAdapter.h"
#include "TbSame1/Implementation/TbSame1SameEnum1Interface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameEnum1Interface
{
namespace Jni
{
namespace Tests
{
FTbSame1SameEnum1InterfaceJniFixture::FTbSame1SameEnum1InterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSame1SameEnum1InterfaceImplementation>();
}

FTbSame1SameEnum1InterfaceJniFixture::~FTbSame1SameEnum1InterfaceJniFixture()
{
	CleanUp();
}

UTbSame1SameEnum1InterfaceJniClient* FTbSame1SameEnum1InterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameEnum1InterfaceJniClient>();
}

TScriptInterface<ITbSame1SameEnum1InterfaceInterface> FTbSame1SameEnum1InterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSame1SameEnum1InterfaceJniAdapter* FTbSame1SameEnum1InterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameEnum1InterfaceJniAdapter>();
}

UGameInstance* FTbSame1SameEnum1InterfaceJniFixture::GetGameInstance()
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

void FTbSame1SameEnum1InterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace SameEnum1Interface
} // namespace TbSame1
#endif // WITH_DEV_AUTOMATION_TESTS
