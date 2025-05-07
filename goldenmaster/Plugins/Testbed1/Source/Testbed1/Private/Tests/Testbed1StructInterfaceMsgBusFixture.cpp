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
#include "Testbed1StructInterfaceMsgBusFixture.h"
#include "Testbed1StructInterfaceMsgBus.spec.h"
#include "Generated/MsgBus/Testbed1StructInterfaceMsgBusClient.h"
#include "Generated/MsgBus/Testbed1StructInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTestbed1StructInterfaceMsgBusHelper::~UTestbed1StructInterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTestbed1StructInterfaceMsgBusHelper::SetSpec(UTestbed1StructInterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed1StructInterfaceMsgBusHelper::PropBoolPropertyCb(const FTestbed1StructBool& PropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyCb(PropBool);
	}
}

void UTestbed1StructInterfaceMsgBusHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const FTestbed1StructBool& PropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyChangeLocalCheckRemoteCb(PropBool);
	}
}

void UTestbed1StructInterfaceMsgBusHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const FTestbed1StructBool& PropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyChangeLocalChangeRemoteCb(PropBool);
	}
}

void UTestbed1StructInterfaceMsgBusHelper::PropIntPropertyCb(const FTestbed1StructInt& PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyCb(PropInt);
	}
}

void UTestbed1StructInterfaceMsgBusHelper::PropIntPropertyChangeLocalCheckRemoteCb(const FTestbed1StructInt& PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyChangeLocalCheckRemoteCb(PropInt);
	}
}

void UTestbed1StructInterfaceMsgBusHelper::PropIntPropertyChangeLocalChangeRemoteCb(const FTestbed1StructInt& PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyChangeLocalChangeRemoteCb(PropInt);
	}
}

void UTestbed1StructInterfaceMsgBusHelper::PropFloatPropertyCb(const FTestbed1StructFloat& PropFloat)
{
	if (Spec)
	{
		Spec->PropFloatPropertyCb(PropFloat);
	}
}

void UTestbed1StructInterfaceMsgBusHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const FTestbed1StructFloat& PropFloat)
{
	if (Spec)
	{
		Spec->PropFloatPropertyChangeLocalCheckRemoteCb(PropFloat);
	}
}

void UTestbed1StructInterfaceMsgBusHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const FTestbed1StructFloat& PropFloat)
{
	if (Spec)
	{
		Spec->PropFloatPropertyChangeLocalChangeRemoteCb(PropFloat);
	}
}

void UTestbed1StructInterfaceMsgBusHelper::PropStringPropertyCb(const FTestbed1StructString& PropString)
{
	if (Spec)
	{
		Spec->PropStringPropertyCb(PropString);
	}
}

void UTestbed1StructInterfaceMsgBusHelper::PropStringPropertyChangeLocalCheckRemoteCb(const FTestbed1StructString& PropString)
{
	if (Spec)
	{
		Spec->PropStringPropertyChangeLocalCheckRemoteCb(PropString);
	}
}

void UTestbed1StructInterfaceMsgBusHelper::PropStringPropertyChangeLocalChangeRemoteCb(const FTestbed1StructString& PropString)
{
	if (Spec)
	{
		Spec->PropStringPropertyChangeLocalChangeRemoteCb(PropString);
	}
}

void UTestbed1StructInterfaceMsgBusHelper::SigBoolSignalCb(const FTestbed1StructBool& ParamBool)
{
	if (Spec)
	{
		Spec->SigBoolSignalCb(ParamBool);
	}
}

void UTestbed1StructInterfaceMsgBusHelper::SigIntSignalCb(const FTestbed1StructInt& ParamInt)
{
	if (Spec)
	{
		Spec->SigIntSignalCb(ParamInt);
	}
}

void UTestbed1StructInterfaceMsgBusHelper::SigFloatSignalCb(const FTestbed1StructFloat& ParamFloat)
{
	if (Spec)
	{
		Spec->SigFloatSignalCb(ParamFloat);
	}
}

void UTestbed1StructInterfaceMsgBusHelper::SigStringSignalCb(const FTestbed1StructString& ParamString)
{
	if (Spec)
	{
		Spec->SigStringSignalCb(ParamString);
	}
}

void UTestbed1StructInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTestbed1StructInterfaceMsgBusFixture::FTestbed1StructInterfaceMsgBusFixture()
{
	Helper = NewObject<UTestbed1StructInterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructInterfaceMsgBusClient>();
}

FTestbed1StructInterfaceMsgBusFixture::~FTestbed1StructInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructInterfaceInterface> FTestbed1StructInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed1StructInterfaceMsgBusAdapter* FTestbed1StructInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructInterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTestbed1StructInterfaceMsgBusHelper> FTestbed1StructInterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed1StructInterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed1StructInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTestbed1StructInterfaceMsgBusHelper::~UTestbed1StructInterfaceMsgBusHelper()
{
}

void UTestbed1StructInterfaceMsgBusHelper::SetSpec(UTestbed1StructInterfaceMsgBusSpec* /* InSpec */)
{
}

void UTestbed1StructInterfaceMsgBusHelper::PropBoolPropertyCb(const FTestbed1StructBool& PropBool)
{
	(void)PropBool;
}

void UTestbed1StructInterfaceMsgBusHelper::PropIntPropertyCb(const FTestbed1StructInt& PropInt)
{
	(void)PropInt;
}

void UTestbed1StructInterfaceMsgBusHelper::PropFloatPropertyCb(const FTestbed1StructFloat& PropFloat)
{
	(void)PropFloat;
}

void UTestbed1StructInterfaceMsgBusHelper::PropStringPropertyCb(const FTestbed1StructString& PropString)
{
	(void)PropString;
}

void UTestbed1StructInterfaceMsgBusHelper::SigBoolSignalCb(const FTestbed1StructBool& ParamBool)
{
	(void)ParamBool;
}

void UTestbed1StructInterfaceMsgBusHelper::SigIntSignalCb(const FTestbed1StructInt& ParamInt)
{
	(void)ParamInt;
}

void UTestbed1StructInterfaceMsgBusHelper::SigFloatSignalCb(const FTestbed1StructFloat& ParamFloat)
{
	(void)ParamFloat;
}

void UTestbed1StructInterfaceMsgBusHelper::SigStringSignalCb(const FTestbed1StructString& ParamString)
{
	(void)ParamString;
}

void UTestbed1StructInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
