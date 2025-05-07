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
#include "Testbed2NestedStruct1InterfaceMsgBusFixture.h"
#include "Testbed2NestedStruct1InterfaceMsgBus.spec.h"
#include "Generated/MsgBus/Testbed2NestedStruct1InterfaceMsgBusClient.h"
#include "Generated/MsgBus/Testbed2NestedStruct1InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTestbed2NestedStruct1InterfaceMsgBusHelper::~UTestbed2NestedStruct1InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::SetSpec(UTestbed2NestedStruct1InterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyCb(Prop1);
	}
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct1& Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalCheckRemoteCb(Prop1);
	}
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct1& Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalChangeRemoteCb(Prop1);
	}
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	if (Spec)
	{
		Spec->Sig1SignalCb(Param1);
	}
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTestbed2NestedStruct1InterfaceMsgBusFixture::FTestbed2NestedStruct1InterfaceMsgBusFixture()
{
	Helper = NewObject<UTestbed2NestedStruct1InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2NestedStruct1InterfaceMsgBusClient>();
}

FTestbed2NestedStruct1InterfaceMsgBusFixture::~FTestbed2NestedStruct1InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> FTestbed2NestedStruct1InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed2NestedStruct1InterfaceMsgBusAdapter* FTestbed2NestedStruct1InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2NestedStruct1InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTestbed2NestedStruct1InterfaceMsgBusHelper> FTestbed2NestedStruct1InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed2NestedStruct1InterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed2NestedStruct1InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTestbed2NestedStruct1InterfaceMsgBusHelper::~UTestbed2NestedStruct1InterfaceMsgBusHelper()
{
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::SetSpec(UTestbed2NestedStruct1InterfaceMsgBusSpec* /* InSpec */)
{
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1)
{
	(void)Prop1;
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
}

void UTestbed2NestedStruct1InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
