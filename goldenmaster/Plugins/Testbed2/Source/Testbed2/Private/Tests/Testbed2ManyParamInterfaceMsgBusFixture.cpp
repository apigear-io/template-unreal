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
#include "Testbed2ManyParamInterfaceMsgBus.spec.h"
#include "Generated/MsgBus/Testbed2ManyParamInterfaceMsgBusClient.h"
#include "Generated/MsgBus/Testbed2ManyParamInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTestbed2ManyParamInterfaceMsgBusHelper::~UTestbed2ManyParamInterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::SetSpec(UTestbed2ManyParamInterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop1PropertyCb(int32 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyCb(Prop1);
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(int32 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalCheckRemoteCb(Prop1);
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(int32 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalChangeRemoteCb(Prop1);
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop2PropertyCb(int32 Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyCb(Prop2);
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop2PropertyChangeLocalCheckRemoteCb(int32 Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyChangeLocalCheckRemoteCb(Prop2);
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop2PropertyChangeLocalChangeRemoteCb(int32 Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyChangeLocalChangeRemoteCb(Prop2);
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop3PropertyCb(int32 Prop3)
{
	if (Spec)
	{
		Spec->Prop3PropertyCb(Prop3);
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop3PropertyChangeLocalCheckRemoteCb(int32 Prop3)
{
	if (Spec)
	{
		Spec->Prop3PropertyChangeLocalCheckRemoteCb(Prop3);
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop3PropertyChangeLocalChangeRemoteCb(int32 Prop3)
{
	if (Spec)
	{
		Spec->Prop3PropertyChangeLocalChangeRemoteCb(Prop3);
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop4PropertyCb(int32 Prop4)
{
	if (Spec)
	{
		Spec->Prop4PropertyCb(Prop4);
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop4PropertyChangeLocalCheckRemoteCb(int32 Prop4)
{
	if (Spec)
	{
		Spec->Prop4PropertyChangeLocalCheckRemoteCb(Prop4);
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop4PropertyChangeLocalChangeRemoteCb(int32 Prop4)
{
	if (Spec)
	{
		Spec->Prop4PropertyChangeLocalChangeRemoteCb(Prop4);
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Sig1SignalCb(int32 Param1)
{
	if (Spec)
	{
		Spec->Sig1SignalCb(Param1);
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Sig2SignalCb(int32 Param1, int32 Param2)
{
	if (Spec)
	{
		Spec->Sig2SignalCb(Param1, Param2);
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Sig3SignalCb(int32 Param1, int32 Param2, int32 Param3)
{
	if (Spec)
	{
		Spec->Sig3SignalCb(Param1, Param2, Param3);
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Sig4SignalCb(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	if (Spec)
	{
		Spec->Sig4SignalCb(Param1, Param2, Param3, Param4);
	}
}

void UTestbed2ManyParamInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTestbed2ManyParamInterfaceMsgBusFixture::FTestbed2ManyParamInterfaceMsgBusFixture()
{
	Helper = NewObject<UTestbed2ManyParamInterfaceMsgBusHelper>();
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

TSoftObjectPtr<UTestbed2ManyParamInterfaceMsgBusHelper> FTestbed2ManyParamInterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed2ManyParamInterfaceMsgBusFixture::GetGameInstance()
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

void FTestbed2ManyParamInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTestbed2ManyParamInterfaceMsgBusHelper::~UTestbed2ManyParamInterfaceMsgBusHelper()
{
}

void UTestbed2ManyParamInterfaceMsgBusHelper::SetSpec(UTestbed2ManyParamInterfaceMsgBusSpec* /* InSpec */)
{
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop1PropertyCb(int32 Prop1)
{
	(void)Prop1;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop2PropertyCb(int32 Prop2)
{
	(void)Prop2;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop3PropertyCb(int32 Prop3)
{
	(void)Prop3;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Prop4PropertyCb(int32 Prop4)
{
	(void)Prop4;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Sig1SignalCb(int32 Param1)
{
	(void)Param1;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Sig2SignalCb(int32 Param1, int32 Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Sig3SignalCb(int32 Param1, int32 Param2, int32 Param3)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::Sig4SignalCb(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
	(void)Param4;
}

void UTestbed2ManyParamInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
