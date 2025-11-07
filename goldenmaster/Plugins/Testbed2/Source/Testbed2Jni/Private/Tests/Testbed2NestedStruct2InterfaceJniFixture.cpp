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
#include "Testbed2NestedStruct2InterfaceJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed2/Generated/Jni/Testbed2NestedStruct2InterfaceJniClient.h"
#include "Testbed2/Generated/Jni/Testbed2NestedStruct2InterfaceJniAdapter.h"
#include "Testbed2/Implementation/Testbed2NestedStruct2Interface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace NestedStruct2Interface
{
namespace Jni
{
namespace Tests
{
FTestbed2NestedStruct2InterfaceJniFixture::FTestbed2NestedStruct2InterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTestbed2NestedStruct2InterfaceImplementation>();
}

FTestbed2NestedStruct2InterfaceJniFixture::~FTestbed2NestedStruct2InterfaceJniFixture()
{
	CleanUp();
}

UTestbed2NestedStruct2InterfaceJniClient* FTestbed2NestedStruct2InterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTestbed2NestedStruct2InterfaceJniClient>();
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> FTestbed2NestedStruct2InterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTestbed2NestedStruct2InterfaceJniAdapter* FTestbed2NestedStruct2InterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2NestedStruct2InterfaceJniAdapter>();
}

UGameInstance* FTestbed2NestedStruct2InterfaceJniFixture::GetGameInstance()
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

void FTestbed2NestedStruct2InterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace NestedStruct2Interface
} // namespace Testbed2
#endif // WITH_DEV_AUTOMATION_TESTS
