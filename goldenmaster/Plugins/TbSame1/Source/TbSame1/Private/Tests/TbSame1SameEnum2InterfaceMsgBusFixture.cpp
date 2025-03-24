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
#include "TbSame1SameEnum2InterfaceMsgBusFixture.h"
#include "TbSame1SameEnum2InterfaceMsgBus.spec.h"
#include "Generated/MsgBus/TbSame1SameEnum2InterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSame1SameEnum2InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTbSame1SameEnum2InterfaceMsgBusHelper::~UTbSame1SameEnum2InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::SetSpec(UTbSame1SameEnum2InterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Prop1PropertyCb(ETbSame1Enum1 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyCb(Prop1);
	}
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Prop2PropertyCb(ETbSame1Enum2 Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyCb(Prop2);
	}
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Sig1SignalCb(ETbSame1Enum1 Param1)
{
	if (Spec)
	{
		Spec->Sig1SignalCb(Param1);
	}
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Sig2SignalCb(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	if (Spec)
	{
		Spec->Sig2SignalCb(Param1, Param2);
	}
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTbSame1SameEnum2InterfaceMsgBusFixture::FTbSame1SameEnum2InterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSame1SameEnum2InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceMsgBusClient>();
}

FTbSame1SameEnum2InterfaceMsgBusFixture::~FTbSame1SameEnum2InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> FTbSame1SameEnum2InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame1SameEnum2InterfaceMsgBusAdapter* FTbSame1SameEnum2InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSame1SameEnum2InterfaceMsgBusHelper> FTbSame1SameEnum2InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame1SameEnum2InterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame1SameEnum2InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTbSame1SameEnum2InterfaceMsgBusHelper::~UTbSame1SameEnum2InterfaceMsgBusHelper()
{
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::SetSpec(UTbSame1SameEnum2InterfaceMsgBusSpec* /* InSpec */)
{
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Prop1PropertyCb(ETbSame1Enum1 Prop1)
{
	(void)Prop1;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Prop2PropertyCb(ETbSame1Enum2 Prop2)
{
	(void)Prop2;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Sig1SignalCb(ETbSame1Enum1 Param1)
{
	(void)Param1;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::Sig2SignalCb(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTbSame1SameEnum2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
