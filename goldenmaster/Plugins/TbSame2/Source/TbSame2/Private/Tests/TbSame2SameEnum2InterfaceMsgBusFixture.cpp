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
#include "TbSame2SameEnum2InterfaceMsgBusFixture.h"
#include "TbSame2SameEnum2InterfaceMsgBus.spec.h"
#include "Generated/MsgBus/TbSame2SameEnum2InterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSame2SameEnum2InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTbSame2SameEnum2InterfaceMsgBusHelper::~UTbSame2SameEnum2InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSame2SameEnum2InterfaceMsgBusHelper::SetSpec(UTbSame2SameEnum2InterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame2SameEnum2InterfaceMsgBusHelper::Prop1PropertyCb(ETbSame2Enum1 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyCb(Prop1);
	}
}

void UTbSame2SameEnum2InterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(ETbSame2Enum1 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalCheckRemoteCb(Prop1);
	}
}

void UTbSame2SameEnum2InterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(ETbSame2Enum1 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalChangeRemoteCb(Prop1);
	}
}

void UTbSame2SameEnum2InterfaceMsgBusHelper::Prop2PropertyCb(ETbSame2Enum2 Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyCb(Prop2);
	}
}

void UTbSame2SameEnum2InterfaceMsgBusHelper::Prop2PropertyChangeLocalCheckRemoteCb(ETbSame2Enum2 Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyChangeLocalCheckRemoteCb(Prop2);
	}
}

void UTbSame2SameEnum2InterfaceMsgBusHelper::Prop2PropertyChangeLocalChangeRemoteCb(ETbSame2Enum2 Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyChangeLocalChangeRemoteCb(Prop2);
	}
}

void UTbSame2SameEnum2InterfaceMsgBusHelper::Sig1SignalCb(ETbSame2Enum1 Param1)
{
	if (Spec)
	{
		Spec->Sig1SignalCb(Param1);
	}
}

void UTbSame2SameEnum2InterfaceMsgBusHelper::Sig2SignalCb(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	if (Spec)
	{
		Spec->Sig2SignalCb(Param1, Param2);
	}
}

void UTbSame2SameEnum2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTbSame2SameEnum2InterfaceMsgBusFixture::FTbSame2SameEnum2InterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSame2SameEnum2InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameEnum2InterfaceMsgBusClient>();
}

FTbSame2SameEnum2InterfaceMsgBusFixture::~FTbSame2SameEnum2InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> FTbSame2SameEnum2InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame2SameEnum2InterfaceMsgBusAdapter* FTbSame2SameEnum2InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame2SameEnum2InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSame2SameEnum2InterfaceMsgBusHelper> FTbSame2SameEnum2InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame2SameEnum2InterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame2SameEnum2InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTbSame2SameEnum2InterfaceMsgBusHelper::~UTbSame2SameEnum2InterfaceMsgBusHelper()
{
}

void UTbSame2SameEnum2InterfaceMsgBusHelper::SetSpec(UTbSame2SameEnum2InterfaceMsgBusSpec* /* InSpec */)
{
}

void UTbSame2SameEnum2InterfaceMsgBusHelper::Prop1PropertyCb(ETbSame2Enum1 Prop1)
{
	(void)Prop1;
}

void UTbSame2SameEnum2InterfaceMsgBusHelper::Prop2PropertyCb(ETbSame2Enum2 Prop2)
{
	(void)Prop2;
}

void UTbSame2SameEnum2InterfaceMsgBusHelper::Sig1SignalCb(ETbSame2Enum1 Param1)
{
	(void)Param1;
}

void UTbSame2SameEnum2InterfaceMsgBusHelper::Sig2SignalCb(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTbSame2SameEnum2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
