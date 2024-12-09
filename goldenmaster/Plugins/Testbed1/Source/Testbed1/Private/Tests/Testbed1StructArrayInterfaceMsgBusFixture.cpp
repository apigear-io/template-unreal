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
#include "Testbed1StructArrayInterfaceMsgBusFixture.h"
#include "Testbed1StructArrayInterfaceMsgBus.spec.h"
#include "Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusClient.h"
#include "Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

UTestbed1StructArrayInterfaceMsgBusHelper::~UTestbed1StructArrayInterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SetSpec(UTestbed1StructArrayInterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropBoolPropertyCb(const TArray<FTestbed1StructBool>& PropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyCb(PropBool);
	}
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropIntPropertyCb(const TArray<FTestbed1StructInt>& PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyCb(PropInt);
	}
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropFloatPropertyCb(const TArray<FTestbed1StructFloat>& PropFloat)
{
	if (Spec)
	{
		Spec->PropFloatPropertyCb(PropFloat);
	}
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropStringPropertyCb(const TArray<FTestbed1StructString>& PropString)
{
	if (Spec)
	{
		Spec->PropStringPropertyCb(PropString);
	}
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigBoolSignalCb(const TArray<FTestbed1StructBool>& ParamBool)
{
	if (Spec)
	{
		Spec->SigBoolSignalCb(ParamBool);
	}
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigIntSignalCb(const TArray<FTestbed1StructInt>& ParamInt)
{
	if (Spec)
	{
		Spec->SigIntSignalCb(ParamInt);
	}
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigFloatSignalCb(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	if (Spec)
	{
		Spec->SigFloatSignalCb(ParamFloat);
	}
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigStringSignalCb(const TArray<FTestbed1StructString>& ParamString)
{
	if (Spec)
	{
		Spec->SigStringSignalCb(ParamString);
	}
}

void UTestbed1StructArrayInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTestbed1StructArrayInterfaceMsgBusFixture::FTestbed1StructArrayInterfaceMsgBusFixture()
{
	Helper = NewObject<UTestbed1StructArrayInterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceMsgBusClient>();
}

FTestbed1StructArrayInterfaceMsgBusFixture::~FTestbed1StructArrayInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> FTestbed1StructArrayInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed1StructArrayInterfaceMsgBusAdapter* FTestbed1StructArrayInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTestbed1StructArrayInterfaceMsgBusHelper> FTestbed1StructArrayInterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed1StructArrayInterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed1StructArrayInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
// create empty implementation in case we do not want to do automated testing
UTestbed1StructArrayInterfaceMsgBusHelper::~UTestbed1StructArrayInterfaceMsgBusHelper()
{
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SetSpec(UTestbed1StructArrayInterfaceMsgBusSpec* /* InSpec */)
{
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropBoolPropertyCb(const TArray<FTestbed1StructBool>& PropBool)
{
	(void)PropBool;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropIntPropertyCb(const TArray<FTestbed1StructInt>& PropInt)
{
	(void)PropInt;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropFloatPropertyCb(const TArray<FTestbed1StructFloat>& PropFloat)
{
	(void)PropFloat;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::PropStringPropertyCb(const TArray<FTestbed1StructString>& PropString)
{
	(void)PropString;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigBoolSignalCb(const TArray<FTestbed1StructBool>& ParamBool)
{
	(void)ParamBool;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigIntSignalCb(const TArray<FTestbed1StructInt>& ParamInt)
{
	(void)ParamInt;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigFloatSignalCb(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	(void)ParamFloat;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::SigStringSignalCb(const TArray<FTestbed1StructString>& ParamString)
{
	(void)ParamString;
}

void UTestbed1StructArrayInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
