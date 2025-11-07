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
#include "Testbed1StructArray2InterfaceJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed1/Generated/Jni/Testbed1StructArray2InterfaceJniClient.h"
#include "Testbed1/Generated/Jni/Testbed1StructArray2InterfaceJniAdapter.h"
#include "Testbed1/Implementation/Testbed1StructArray2Interface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructArray2Interface
{
namespace Jni
{
namespace Tests
{
FTestbed1StructArray2InterfaceJniFixture::FTestbed1StructArray2InterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceImplementation>();
}

FTestbed1StructArray2InterfaceJniFixture::~FTestbed1StructArray2InterfaceJniFixture()
{
	CleanUp();
}

UTestbed1StructArray2InterfaceJniClient* FTestbed1StructArray2InterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceJniClient>();
}

TScriptInterface<ITestbed1StructArray2InterfaceInterface> FTestbed1StructArray2InterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTestbed1StructArray2InterfaceJniAdapter* FTestbed1StructArray2InterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceJniAdapter>();
}

UGameInstance* FTestbed1StructArray2InterfaceJniFixture::GetGameInstance()
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

void FTestbed1StructArray2InterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace StructArray2Interface
} // namespace Testbed1
#endif // WITH_DEV_AUTOMATION_TESTS
