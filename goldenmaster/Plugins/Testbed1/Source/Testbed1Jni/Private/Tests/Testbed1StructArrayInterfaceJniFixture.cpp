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
#include "Testbed1StructArrayInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed1/Generated/Jni/Testbed1StructArrayInterfaceJniClient.h"
#include "Testbed1/Generated/Jni/Testbed1StructArrayInterfaceJniAdapter.h"
#include "Testbed1/Implementation/Testbed1StructArrayInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructArrayInterface
{
namespace Jni
{
namespace Tests
{
FTestbed1StructArrayInterfaceJniFixture::FTestbed1StructArrayInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
}

FTestbed1StructArrayInterfaceJniFixture::~FTestbed1StructArrayInterfaceJniFixture()
{
	CleanUp();
}

UTestbed1StructArrayInterfaceJniClient* FTestbed1StructArrayInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceJniClient>();
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> FTestbed1StructArrayInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTestbed1StructArrayInterfaceJniAdapter* FTestbed1StructArrayInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceJniAdapter>();
}

UGameInstance* FTestbed1StructArrayInterfaceJniFixture::GetGameInstance()
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

void FTestbed1StructArrayInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace StructArrayInterface
} // namespace Testbed1
#endif // WITH_DEV_AUTOMATION_TESTS
