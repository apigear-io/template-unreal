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
#include "TbEnumEnumInterfaceMsgBusFixture.h"
#include "TbEnumEnumInterfaceMsgBus.spec.h"
#include "Generated/MsgBus/TbEnumEnumInterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbEnumEnumInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTbEnumEnumInterfaceMsgBusHelper::~UTbEnumEnumInterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbEnumEnumInterfaceMsgBusHelper::SetSpec(UTbEnumEnumInterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTbEnumEnumInterfaceMsgBusHelper::Prop0PropertyCb(ETbEnumEnum0 Prop0)
{
	if (Spec)
	{
		Spec->Prop0PropertyCb(Prop0);
	}
}

void UTbEnumEnumInterfaceMsgBusHelper::Prop0PropertyChangeLocalCheckRemoteCb(ETbEnumEnum0 Prop0)
{
	if (Spec)
	{
		Spec->Prop0PropertyChangeLocalCheckRemoteCb(Prop0);
	}
}

void UTbEnumEnumInterfaceMsgBusHelper::Prop0PropertyChangeLocalChangeRemoteCb(ETbEnumEnum0 Prop0)
{
	if (Spec)
	{
		Spec->Prop0PropertyChangeLocalChangeRemoteCb(Prop0);
	}
}

void UTbEnumEnumInterfaceMsgBusHelper::Prop1PropertyCb(ETbEnumEnum1 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyCb(Prop1);
	}
}

void UTbEnumEnumInterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb(ETbEnumEnum1 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalCheckRemoteCb(Prop1);
	}
}

void UTbEnumEnumInterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb(ETbEnumEnum1 Prop1)
{
	if (Spec)
	{
		Spec->Prop1PropertyChangeLocalChangeRemoteCb(Prop1);
	}
}

void UTbEnumEnumInterfaceMsgBusHelper::Prop2PropertyCb(ETbEnumEnum2 Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyCb(Prop2);
	}
}

void UTbEnumEnumInterfaceMsgBusHelper::Prop2PropertyChangeLocalCheckRemoteCb(ETbEnumEnum2 Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyChangeLocalCheckRemoteCb(Prop2);
	}
}

void UTbEnumEnumInterfaceMsgBusHelper::Prop2PropertyChangeLocalChangeRemoteCb(ETbEnumEnum2 Prop2)
{
	if (Spec)
	{
		Spec->Prop2PropertyChangeLocalChangeRemoteCb(Prop2);
	}
}

void UTbEnumEnumInterfaceMsgBusHelper::Prop3PropertyCb(ETbEnumEnum3 Prop3)
{
	if (Spec)
	{
		Spec->Prop3PropertyCb(Prop3);
	}
}

void UTbEnumEnumInterfaceMsgBusHelper::Prop3PropertyChangeLocalCheckRemoteCb(ETbEnumEnum3 Prop3)
{
	if (Spec)
	{
		Spec->Prop3PropertyChangeLocalCheckRemoteCb(Prop3);
	}
}

void UTbEnumEnumInterfaceMsgBusHelper::Prop3PropertyChangeLocalChangeRemoteCb(ETbEnumEnum3 Prop3)
{
	if (Spec)
	{
		Spec->Prop3PropertyChangeLocalChangeRemoteCb(Prop3);
	}
}

void UTbEnumEnumInterfaceMsgBusHelper::Sig0SignalCb(ETbEnumEnum0 Param0)
{
	if (Spec)
	{
		Spec->Sig0SignalCb(Param0);
	}
}

void UTbEnumEnumInterfaceMsgBusHelper::Sig1SignalCb(ETbEnumEnum1 Param1)
{
	if (Spec)
	{
		Spec->Sig1SignalCb(Param1);
	}
}

void UTbEnumEnumInterfaceMsgBusHelper::Sig2SignalCb(ETbEnumEnum2 Param2)
{
	if (Spec)
	{
		Spec->Sig2SignalCb(Param2);
	}
}

void UTbEnumEnumInterfaceMsgBusHelper::Sig3SignalCb(ETbEnumEnum3 Param3)
{
	if (Spec)
	{
		Spec->Sig3SignalCb(Param3);
	}
}

void UTbEnumEnumInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTbEnumEnumInterfaceMsgBusFixture::FTbEnumEnumInterfaceMsgBusFixture()
{
	Helper = NewObject<UTbEnumEnumInterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceMsgBusClient>();
}

FTbEnumEnumInterfaceMsgBusFixture::~FTbEnumEnumInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbEnumEnumInterfaceInterface> FTbEnumEnumInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbEnumEnumInterfaceMsgBusAdapter* FTbEnumEnumInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbEnumEnumInterfaceMsgBusHelper> FTbEnumEnumInterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbEnumEnumInterfaceMsgBusFixture::GetGameInstance()
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

void FTbEnumEnumInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTbEnumEnumInterfaceMsgBusHelper::~UTbEnumEnumInterfaceMsgBusHelper()
{
}

void UTbEnumEnumInterfaceMsgBusHelper::SetSpec(UTbEnumEnumInterfaceMsgBusSpec* /* InSpec */)
{
}

void UTbEnumEnumInterfaceMsgBusHelper::Prop0PropertyCb(ETbEnumEnum0 Prop0)
{
	(void)Prop0;
}

void UTbEnumEnumInterfaceMsgBusHelper::Prop1PropertyCb(ETbEnumEnum1 Prop1)
{
	(void)Prop1;
}

void UTbEnumEnumInterfaceMsgBusHelper::Prop2PropertyCb(ETbEnumEnum2 Prop2)
{
	(void)Prop2;
}

void UTbEnumEnumInterfaceMsgBusHelper::Prop3PropertyCb(ETbEnumEnum3 Prop3)
{
	(void)Prop3;
}

void UTbEnumEnumInterfaceMsgBusHelper::Sig0SignalCb(ETbEnumEnum0 Param0)
{
	(void)Param0;
}

void UTbEnumEnumInterfaceMsgBusHelper::Sig1SignalCb(ETbEnumEnum1 Param1)
{
	(void)Param1;
}

void UTbEnumEnumInterfaceMsgBusHelper::Sig2SignalCb(ETbEnumEnum2 Param2)
{
	(void)Param2;
}

void UTbEnumEnumInterfaceMsgBusHelper::Sig3SignalCb(ETbEnumEnum3 Param3)
{
	(void)Param3;
}

void UTbEnumEnumInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
