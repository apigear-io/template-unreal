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
#include "TbRefIfacesSimpleLocalIfJniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "TbRefIfaces/Generated/Jni/TbRefIfacesSimpleLocalIfJniClient.h"
#include "TbRefIfaces/Generated/Jni/TbRefIfacesSimpleLocalIfJniAdapter.h"
#include "TbRefIfaces/Implementation/TbRefIfacesSimpleLocalIf.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace SimpleLocalIf
{
namespace Jni
{
namespace Tests
{
FTbRefIfacesSimpleLocalIfJniFixture::FTbRefIfacesSimpleLocalIfJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbRefIfacesSimpleLocalIfImplementation>();
}

FTbRefIfacesSimpleLocalIfJniFixture::~FTbRefIfacesSimpleLocalIfJniFixture()
{
	CleanUp();
}

UTbRefIfacesSimpleLocalIfJniClient* FTbRefIfacesSimpleLocalIfJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbRefIfacesSimpleLocalIfJniClient>();
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> FTbRefIfacesSimpleLocalIfJniFixture::GetLocalImplementation()
{
	return source;
}

UTbRefIfacesSimpleLocalIfJniAdapter* FTbRefIfacesSimpleLocalIfJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbRefIfacesSimpleLocalIfJniAdapter>();
}

UGameInstance* FTbRefIfacesSimpleLocalIfJniFixture::GetGameInstance()
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

void FTbRefIfacesSimpleLocalIfJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace SimpleLocalIf
} // namespace TbRefIfaces
#endif // WITH_DEV_AUTOMATION_TESTS
