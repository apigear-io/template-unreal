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
#include "TbSame1SameStruct2InterfaceJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSame1/Generated/Jni/TbSame1SameStruct2InterfaceJniClient.h"
#include "TbSame1/Generated/Jni/TbSame1SameStruct2InterfaceJniAdapter.h"
#include "TbSame1/Implementation/TbSame1SameStruct2Interface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameStruct2Interface
{
namespace Jni
{
namespace Tests
{
FTbSame1SameStruct2InterfaceJniFixture::FTbSame1SameStruct2InterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceImplementation>();
}

FTbSame1SameStruct2InterfaceJniFixture::~FTbSame1SameStruct2InterfaceJniFixture()
{
	CleanUp();
}

UTbSame1SameStruct2InterfaceJniClient* FTbSame1SameStruct2InterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceJniClient>();
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> FTbSame1SameStruct2InterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSame1SameStruct2InterfaceJniAdapter* FTbSame1SameStruct2InterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceJniAdapter>();
}

UGameInstance* FTbSame1SameStruct2InterfaceJniFixture::GetGameInstance()
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

void FTbSame1SameStruct2InterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace SameStruct2Interface
} // namespace TbSame1
#endif // WITH_DEV_AUTOMATION_TESTS
