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
#include "Testbed2ManyParamInterfaceMsgBusFixture.h"
#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "Testbed2/Generated/MsgBus/Testbed2ManyParamInterfaceMsgBusClient.h"
#include "Testbed2/Generated/MsgBus/Testbed2ManyParamInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"

FTestbed2ManyParamInterfaceMsgBusFixture::FTestbed2ManyParamInterfaceMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceMsgBusClient>();
}

FTestbed2ManyParamInterfaceMsgBusFixture::~FTestbed2ManyParamInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> FTestbed2ManyParamInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed2ManyParamInterfaceMsgBusAdapter* FTestbed2ManyParamInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceMsgBusAdapter>();
}

UGameInstance* FTestbed2ManyParamInterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed2ManyParamInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
