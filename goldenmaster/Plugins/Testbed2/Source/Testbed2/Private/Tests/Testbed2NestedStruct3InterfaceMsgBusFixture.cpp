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
#include "Testbed2NestedStruct3InterfaceMsgBusFixture.h"
#include "Testbed2NestedStruct3InterfaceMsgBus.spec.h"
#include "Generated/MsgBus/Testbed2NestedStruct3InterfaceMsgBusClient.h"
#include "Generated/MsgBus/Testbed2NestedStruct3InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTestbed2NestedStruct3InterfaceMsgBusHelper::~UTestbed2NestedStruct3InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::SetSpec(UTestbed2NestedStruct3InterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyCb(Prop1);
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct1& Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalCheckRemoteCb(Prop1);
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct1& Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalChangeRemoteCb(Prop1);
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyCb(Prop2);
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop2PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct2& Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyChangeLocalCheckRemoteCb(Prop2);
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop2PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct2& Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyChangeLocalChangeRemoteCb(Prop2);
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop3PropertyCb(const FTestbed2NestedStruct3& Prop3)
{
	if (Spec)
	{
		Spec->Prop3PropertyCb(Prop3);
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop3PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct3& Prop3)
{
	if (Spec)
	{
		Spec->Prop3PropertyChangeLocalCheckRemoteCb(Prop3);
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop3PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct3& Prop3)
{
	if (Spec)
	{
		Spec->Prop3PropertyChangeLocalChangeRemoteCb(Prop3);
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	if (Spec)
	{
		Spec->Sig1SignalCb(Param1);
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	if (Spec)
	{
		Spec->Sig2SignalCb(Param1, Param2);
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Sig3SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	if (Spec)
	{
		Spec->Sig3SignalCb(Param1, Param2, Param3);
	}
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTestbed2NestedStruct3InterfaceMsgBusFixture::FTestbed2NestedStruct3InterfaceMsgBusFixture()
{
	Helper = NewObject<UTestbed2NestedStruct3InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2NestedStruct3InterfaceMsgBusClient>();
}

FTestbed2NestedStruct3InterfaceMsgBusFixture::~FTestbed2NestedStruct3InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> FTestbed2NestedStruct3InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTestbed2NestedStruct3InterfaceMsgBusAdapter* FTestbed2NestedStruct3InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2NestedStruct3InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTestbed2NestedStruct3InterfaceMsgBusHelper> FTestbed2NestedStruct3InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed2NestedStruct3InterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed2NestedStruct3InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTestbed2NestedStruct3InterfaceMsgBusHelper::~UTestbed2NestedStruct3InterfaceMsgBusHelper()
{
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::SetSpec(UTestbed2NestedStruct3InterfaceMsgBusSpec* /* InSpec */)
{
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1)
{
	(void)Prop1;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2)
{
	(void)Prop2;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Prop3PropertyCb(const FTestbed2NestedStruct3& Prop3)
{
	(void)Prop3;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::Sig3SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
}

void UTestbed2NestedStruct3InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
