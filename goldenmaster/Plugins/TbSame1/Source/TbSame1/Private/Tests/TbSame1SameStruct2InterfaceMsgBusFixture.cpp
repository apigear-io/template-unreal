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
#include "TbSame1SameStruct2InterfaceMsgBusFixture.h"
#include "TbSame1SameStruct2InterfaceMsgBus.spec.h"
#include "Generated/MsgBus/TbSame1SameStruct2InterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSame1SameStruct2InterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTbSame1SameStruct2InterfaceMsgBusHelper::~UTbSame1SameStruct2InterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSame1SameStruct2InterfaceMsgBusHelper::SetSpec(UTbSame1SameStruct2InterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame1SameStruct2InterfaceMsgBusHelper::Prop1PropertyCb(const FTbSame1Struct2& Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyCb(Prop1);
	}
}

void UTbSame1SameStruct2InterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(const FTbSame1Struct2& Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalCheckRemoteCb(Prop1);
	}
}

void UTbSame1SameStruct2InterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(const FTbSame1Struct2& Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalChangeRemoteCb(Prop1);
	}
}

void UTbSame1SameStruct2InterfaceMsgBusHelper::Prop2PropertyCb(const FTbSame1Struct2& Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyCb(Prop2);
	}
}

void UTbSame1SameStruct2InterfaceMsgBusHelper::Prop2PropertyChangeLocalCheckRemoteCb(const FTbSame1Struct2& Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyChangeLocalCheckRemoteCb(Prop2);
	}
}

void UTbSame1SameStruct2InterfaceMsgBusHelper::Prop2PropertyChangeLocalChangeRemoteCb(const FTbSame1Struct2& Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyChangeLocalChangeRemoteCb(Prop2);
	}
}

void UTbSame1SameStruct2InterfaceMsgBusHelper::Sig1SignalCb(const FTbSame1Struct1& Param1)
{
	if (Spec)
	{
		Spec->Sig1SignalCb(Param1);
	}
}

void UTbSame1SameStruct2InterfaceMsgBusHelper::Sig2SignalCb(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	if (Spec)
	{
		Spec->Sig2SignalCb(Param1, Param2);
	}
}

void UTbSame1SameStruct2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTbSame1SameStruct2InterfaceMsgBusFixture::FTbSame1SameStruct2InterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSame1SameStruct2InterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceMsgBusClient>();
}

FTbSame1SameStruct2InterfaceMsgBusFixture::~FTbSame1SameStruct2InterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> FTbSame1SameStruct2InterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSame1SameStruct2InterfaceMsgBusAdapter* FTbSame1SameStruct2InterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSame1SameStruct2InterfaceMsgBusHelper> FTbSame1SameStruct2InterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame1SameStruct2InterfaceMsgBusFixture::GetGameInstance()
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

void FTbSame1SameStruct2InterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTbSame1SameStruct2InterfaceMsgBusHelper::~UTbSame1SameStruct2InterfaceMsgBusHelper()
{
}

void UTbSame1SameStruct2InterfaceMsgBusHelper::SetSpec(UTbSame1SameStruct2InterfaceMsgBusSpec* /* InSpec */)
{
}

void UTbSame1SameStruct2InterfaceMsgBusHelper::Prop1PropertyCb(const FTbSame1Struct2& Prop1)
{
	(void)Prop1;
}

void UTbSame1SameStruct2InterfaceMsgBusHelper::Prop2PropertyCb(const FTbSame1Struct2& Prop2)
{
	(void)Prop2;
}

void UTbSame1SameStruct2InterfaceMsgBusHelper::Sig1SignalCb(const FTbSame1Struct1& Param1)
{
	(void)Param1;
}

void UTbSame1SameStruct2InterfaceMsgBusHelper::Sig2SignalCb(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTbSame1SameStruct2InterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
