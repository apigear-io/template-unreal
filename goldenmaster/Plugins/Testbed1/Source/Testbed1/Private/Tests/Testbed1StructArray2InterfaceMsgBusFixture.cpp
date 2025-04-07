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
#include "Testbed1StructArray2InterfaceMsgBusFixture.h"
#include "Testbed1StructArray2InterfaceMsgBus.spec.h"
#include "Generated/MsgBus/Testbed1StructArray2InterfaceMsgBusClient.h"
#include "Generated/MsgBus/Testbed1StructArray2InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTestbed1StructArray2InterfaceMsgBusHelper::~UTestbed1StructArray2InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SetSpec(UTestbed1StructArray2InterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropBoolPropertyCb(const FTestbed1StructBoolWithArray& PropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyCb(PropBool);
	}
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropIntPropertyCb(const FTestbed1StructIntWithArray& PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyCb(PropInt);
	}
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropFloatPropertyCb(const FTestbed1StructFloatWithArray& PropFloat)
{
	if (Spec)
	{
		Spec->PropFloatPropertyCb(PropFloat);
	}
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropStringPropertyCb(const FTestbed1StructStringWithArray& PropString)
{
	if (Spec)
	{
		Spec->PropStringPropertyCb(PropString);
	}
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropEnumPropertyCb(const FTestbed1StructEnumWithArray& PropEnum)
{
	if (Spec)
	{
		Spec->PropEnumPropertyCb(PropEnum);
	}
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SigBoolSignalCb(const FTestbed1StructBoolWithArray& ParamBool)
{
	if (Spec)
	{
		Spec->SigBoolSignalCb(ParamBool);
	}
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SigIntSignalCb(const FTestbed1StructIntWithArray& ParamInt)
{
	if (Spec)
	{
		Spec->SigIntSignalCb(ParamInt);
	}
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SigFloatSignalCb(const FTestbed1StructFloatWithArray& ParamFloat)
{
	if (Spec)
	{
		Spec->SigFloatSignalCb(ParamFloat);
	}
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SigStringSignalCb(const FTestbed1StructStringWithArray& ParamString)
{
	if (Spec)
	{
		Spec->SigStringSignalCb(ParamString);
	}
}

void UTestbed1StructArray2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTestbed1StructArray2InterfaceMsgBusFixture::FTestbed1StructArray2InterfaceMsgBusFixture()
{
	Helper = NewObject<UTestbed1StructArray2InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceMsgBusClient>();
}

FTestbed1StructArray2InterfaceMsgBusFixture::~FTestbed1StructArray2InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructArray2InterfaceInterface> FTestbed1StructArray2InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed1StructArray2InterfaceMsgBusAdapter* FTestbed1StructArray2InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTestbed1StructArray2InterfaceMsgBusHelper> FTestbed1StructArray2InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed1StructArray2InterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed1StructArray2InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTestbed1StructArray2InterfaceMsgBusHelper::~UTestbed1StructArray2InterfaceMsgBusHelper()
{
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SetSpec(UTestbed1StructArray2InterfaceMsgBusSpec* /* InSpec */)
{
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropBoolPropertyCb(const FTestbed1StructBoolWithArray& PropBool)
{
	(void)PropBool;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropIntPropertyCb(const FTestbed1StructIntWithArray& PropInt)
{
	(void)PropInt;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropFloatPropertyCb(const FTestbed1StructFloatWithArray& PropFloat)
{
	(void)PropFloat;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropStringPropertyCb(const FTestbed1StructStringWithArray& PropString)
{
	(void)PropString;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::PropEnumPropertyCb(const FTestbed1StructEnumWithArray& PropEnum)
{
	(void)PropEnum;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SigBoolSignalCb(const FTestbed1StructBoolWithArray& ParamBool)
{
	(void)ParamBool;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SigIntSignalCb(const FTestbed1StructIntWithArray& ParamInt)
{
	(void)ParamInt;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SigFloatSignalCb(const FTestbed1StructFloatWithArray& ParamFloat)
{
	(void)ParamFloat;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::SigStringSignalCb(const FTestbed1StructStringWithArray& ParamString)
{
	(void)ParamString;
}

void UTestbed1StructArray2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
