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
#include "Testbed1StructInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed1/Generated/Jni/Testbed1StructInterfaceJniClient.h"
#include "Testbed1/Generated/Jni/Testbed1StructInterfaceJniAdapter.h"
#include "Testbed1/Implementation/Testbed1StructInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructInterface
{
namespace Jni
{
namespace Tests
{
FTestbed1StructInterfaceJniFixture::FTestbed1StructInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTestbed1StructInterfaceImplementation>();
}

FTestbed1StructInterfaceJniFixture::~FTestbed1StructInterfaceJniFixture()
{
	CleanUp();
}

UTestbed1StructInterfaceJniClient* FTestbed1StructInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructInterfaceJniClient>();
}

TScriptInterface<ITestbed1StructInterfaceInterface> FTestbed1StructInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTestbed1StructInterfaceJniAdapter* FTestbed1StructInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructInterfaceJniAdapter>();
}

UGameInstance* FTestbed1StructInterfaceJniFixture::GetGameInstance()
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

void FTestbed1StructInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace StructInterface
} // namespace Testbed1
#endif // WITH_DEV_AUTOMATION_TESTS
