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
#include "Testbed2NestedStruct2InterfaceMsgBusFixture.h"
#include "Testbed2NestedStruct2InterfaceMsgBus.spec.h"
#include "Generated/MsgBus/Testbed2NestedStruct2InterfaceMsgBusClient.h"
#include "Generated/MsgBus/Testbed2NestedStruct2InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTestbed2NestedStruct2InterfaceMsgBusHelper::~UTestbed2NestedStruct2InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTestbed2NestedStruct2InterfaceMsgBusHelper::SetSpec(UTestbed2NestedStruct2InterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed2NestedStruct2InterfaceMsgBusHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyCb(Prop1);
	}
}

void UTestbed2NestedStruct2InterfaceMsgBusHelper::Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyCb(Prop2);
	}
}

void UTestbed2NestedStruct2InterfaceMsgBusHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	if (Spec)
	{
		Spec->Sig1SignalCb(Param1);
	}
}

void UTestbed2NestedStruct2InterfaceMsgBusHelper::Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	if (Spec)
	{
		Spec->Sig2SignalCb(Param1, Param2);
	}
}

void UTestbed2NestedStruct2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTestbed2NestedStruct2InterfaceMsgBusFixture::FTestbed2NestedStruct2InterfaceMsgBusFixture()
{
	Helper = NewObject<UTestbed2NestedStruct2InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2NestedStruct2InterfaceMsgBusClient>();
}

FTestbed2NestedStruct2InterfaceMsgBusFixture::~FTestbed2NestedStruct2InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> FTestbed2NestedStruct2InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed2NestedStruct2InterfaceMsgBusAdapter* FTestbed2NestedStruct2InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2NestedStruct2InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTestbed2NestedStruct2InterfaceMsgBusHelper> FTestbed2NestedStruct2InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed2NestedStruct2InterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed2NestedStruct2InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTestbed2NestedStruct2InterfaceMsgBusHelper::~UTestbed2NestedStruct2InterfaceMsgBusHelper()
{
}

void UTestbed2NestedStruct2InterfaceMsgBusHelper::SetSpec(UTestbed2NestedStruct2InterfaceMsgBusSpec* /* InSpec */)
{
}

void UTestbed2NestedStruct2InterfaceMsgBusHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1)
{
	(void)Prop1;
}

void UTestbed2NestedStruct2InterfaceMsgBusHelper::Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2)
{
	(void)Prop2;
}

void UTestbed2NestedStruct2InterfaceMsgBusHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
}

void UTestbed2NestedStruct2InterfaceMsgBusHelper::Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTestbed2NestedStruct2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
