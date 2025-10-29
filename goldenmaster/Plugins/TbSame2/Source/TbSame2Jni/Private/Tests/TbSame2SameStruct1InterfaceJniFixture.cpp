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
#include "TbSame2SameStruct1InterfaceJniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "TbSame2/Generated/Jni/TbSame2SameStruct1InterfaceJniClient.h"
#include "TbSame2/Generated/Jni/TbSame2SameStruct1InterfaceJniAdapter.h"
#include "TbSame2/Implementation/TbSame2SameStruct1Interface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameStruct1Interface
{
namespace Jni
{
namespace Tests
{
FTbSame2SameStruct1InterfaceJniFixture::FTbSame2SameStruct1InterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSame2SameStruct1InterfaceImplementation>();
}

FTbSame2SameStruct1InterfaceJniFixture::~FTbSame2SameStruct1InterfaceJniFixture()
{
	CleanUp();
}

UTbSame2SameStruct1InterfaceJniClient* FTbSame2SameStruct1InterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameStruct1InterfaceJniClient>();
}

TScriptInterface<ITbSame2SameStruct1InterfaceInterface> FTbSame2SameStruct1InterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSame2SameStruct1InterfaceJniAdapter* FTbSame2SameStruct1InterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameStruct1InterfaceJniAdapter>();
}

UGameInstance* FTbSame2SameStruct1InterfaceJniFixture::GetGameInstance()
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

void FTbSame2SameStruct1InterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace SameStruct1Interface
} // namespace TbSame2
#endif // WITH_DEV_AUTOMATION_TESTS
