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
#include "TbSame1SameStruct1InterfaceMsgBusFixture.h"
#include "TbSame1SameStruct1InterfaceMsgBus.spec.h"
#include "Generated/MsgBus/TbSame1SameStruct1InterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSame1SameStruct1InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTbSame1SameStruct1InterfaceMsgBusHelper::~UTbSame1SameStruct1InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSame1SameStruct1InterfaceMsgBusHelper::SetSpec(UTbSame1SameStruct1InterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame1SameStruct1InterfaceMsgBusHelper::Prop1PropertyCb(const FTbSame1Struct1& Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyCb(Prop1);
	}
}

void UTbSame1SameStruct1InterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTbSame1Struct1& Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalCheckRemoteCb(Prop1);
	}
}

void UTbSame1SameStruct1InterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTbSame1Struct1& Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalChangeRemoteCb(Prop1);
	}
}

void UTbSame1SameStruct1InterfaceMsgBusHelper::Sig1SignalCb(const FTbSame1Struct1& Param1)
{
	if (Spec)
	{
		Spec->Sig1SignalCb(Param1);
	}
}

void UTbSame1SameStruct1InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTbSame1SameStruct1InterfaceMsgBusFixture::FTbSame1SameStruct1InterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSame1SameStruct1InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameStruct1InterfaceMsgBusClient>();
}

FTbSame1SameStruct1InterfaceMsgBusFixture::~FTbSame1SameStruct1InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> FTbSame1SameStruct1InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame1SameStruct1InterfaceMsgBusAdapter* FTbSame1SameStruct1InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameStruct1InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSame1SameStruct1InterfaceMsgBusHelper> FTbSame1SameStruct1InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame1SameStruct1InterfaceMsgBusFixture::GetGameInstance()
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

void FTbSame1SameStruct1InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTbSame1SameStruct1InterfaceMsgBusHelper::~UTbSame1SameStruct1InterfaceMsgBusHelper()
{
}

void UTbSame1SameStruct1InterfaceMsgBusHelper::SetSpec(UTbSame1SameStruct1InterfaceMsgBusSpec* /* InSpec */)
{
}

void UTbSame1SameStruct1InterfaceMsgBusHelper::Prop1PropertyCb(const FTbSame1Struct1& Prop1)
{
	(void)Prop1;
}

void UTbSame1SameStruct1InterfaceMsgBusHelper::Sig1SignalCb(const FTbSame1Struct1& Param1)
{
	(void)Param1;
}

void UTbSame1SameStruct1InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
