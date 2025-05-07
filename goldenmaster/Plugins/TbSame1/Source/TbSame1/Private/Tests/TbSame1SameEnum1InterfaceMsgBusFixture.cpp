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
#include "TbSame1SameEnum1InterfaceMsgBusFixture.h"
#include "TbSame1SameEnum1InterfaceMsgBus.spec.h"
#include "Generated/MsgBus/TbSame1SameEnum1InterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSame1SameEnum1InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTbSame1SameEnum1InterfaceMsgBusHelper::~UTbSame1SameEnum1InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSame1SameEnum1InterfaceMsgBusHelper::SetSpec(UTbSame1SameEnum1InterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame1SameEnum1InterfaceMsgBusHelper::Prop1PropertyCb(ETbSame1Enum1 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyCb(Prop1);
	}
}

void UTbSame1SameEnum1InterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(ETbSame1Enum1 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalCheckRemoteCb(Prop1);
	}
}

void UTbSame1SameEnum1InterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(ETbSame1Enum1 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalChangeRemoteCb(Prop1);
	}
}

void UTbSame1SameEnum1InterfaceMsgBusHelper::Sig1SignalCb(ETbSame1Enum1 Param1)
{
	if (Spec)
	{
		Spec->Sig1SignalCb(Param1);
	}
}

void UTbSame1SameEnum1InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTbSame1SameEnum1InterfaceMsgBusFixture::FTbSame1SameEnum1InterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSame1SameEnum1InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameEnum1InterfaceMsgBusClient>();
}

FTbSame1SameEnum1InterfaceMsgBusFixture::~FTbSame1SameEnum1InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameEnum1InterfaceInterface> FTbSame1SameEnum1InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame1SameEnum1InterfaceMsgBusAdapter* FTbSame1SameEnum1InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameEnum1InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSame1SameEnum1InterfaceMsgBusHelper> FTbSame1SameEnum1InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame1SameEnum1InterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame1SameEnum1InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTbSame1SameEnum1InterfaceMsgBusHelper::~UTbSame1SameEnum1InterfaceMsgBusHelper()
{
}

void UTbSame1SameEnum1InterfaceMsgBusHelper::SetSpec(UTbSame1SameEnum1InterfaceMsgBusSpec* /* InSpec */)
{
}

void UTbSame1SameEnum1InterfaceMsgBusHelper::Prop1PropertyCb(ETbSame1Enum1 Prop1)
{
	(void)Prop1;
}

void UTbSame1SameEnum1InterfaceMsgBusHelper::Sig1SignalCb(ETbSame1Enum1 Param1)
{
	(void)Param1;
}

void UTbSame1SameEnum1InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
