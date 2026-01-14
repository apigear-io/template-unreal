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
#include "Testbed2ManyParamInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed2/Generated/Jni/Testbed2ManyParamInterfaceJniClient.h"
#include "Testbed2/Generated/Jni/Testbed2ManyParamInterfaceJniAdapter.h"
#include "Testbed2/Implementation/Testbed2ManyParamInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace ManyParamInterface
{
namespace Jni
{
namespace Tests
{
FTestbed2ManyParamInterfaceJniFixture::FTestbed2ManyParamInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceImplementation>();
}

FTestbed2ManyParamInterfaceJniFixture::~FTestbed2ManyParamInterfaceJniFixture()
{
	CleanUp();
}

UTestbed2ManyParamInterfaceJniClient* FTestbed2ManyParamInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceJniClient>();
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> FTestbed2ManyParamInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTestbed2ManyParamInterfaceJniAdapter* FTestbed2ManyParamInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceJniAdapter>();
}

UGameInstance* FTestbed2ManyParamInterfaceJniFixture::GetGameInstance()
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

void FTestbed2ManyParamInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace ManyParamInterface
} // namespace Testbed2
#endif // WITH_DEV_AUTOMATION_TESTS
