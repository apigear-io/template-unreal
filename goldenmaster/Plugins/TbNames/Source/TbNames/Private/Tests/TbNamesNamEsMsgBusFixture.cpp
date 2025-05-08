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
#include "TbNamesNamEsMsgBusFixture.h"
#include "TbNamesNamEsMsgBus.spec.h"
#include "Generated/MsgBus/TbNamesNamEsMsgBusClient.h"
#include "Generated/MsgBus/TbNamesNamEsMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTbNamesNamEsMsgBusHelper::~UTbNamesNamEsMsgBusHelper()
{
	Spec = nullptr;
}

void UTbNamesNamEsMsgBusHelper::SetSpec(UTbNamesNamEsMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTbNamesNamEsMsgBusHelper::SwitchPropertyCb(bool bSwitch)
{
	if (Spec)
	{
		Spec->SwitchPropertyCb(bSwitch);
	}
}

void UTbNamesNamEsMsgBusHelper::SwitchPropertyChangeLocalCheckRemoteCb(bool bSwitch)
{
	if (Spec)
	{
		Spec->SwitchPropertyChangeLocalCheckRemoteCb(bSwitch);
	}
}

void UTbNamesNamEsMsgBusHelper::SwitchPropertyChangeLocalChangeRemoteCb(bool bSwitch)
{
	if (Spec)
	{
		Spec->SwitchPropertyChangeLocalChangeRemoteCb(bSwitch);
	}
}

void UTbNamesNamEsMsgBusHelper::SomePropertyPropertyCb(int32 SomeProperty)
{
	if (Spec)
	{
		Spec->SomePropertyPropertyCb(SomeProperty);
	}
}

void UTbNamesNamEsMsgBusHelper::SomePropertyPropertyChangeLocalCheckRemoteCb(int32 SomeProperty)
{
	if (Spec)
	{
		Spec->SomePropertyPropertyChangeLocalCheckRemoteCb(SomeProperty);
	}
}

void UTbNamesNamEsMsgBusHelper::SomePropertyPropertyChangeLocalChangeRemoteCb(int32 SomeProperty)
{
	if (Spec)
	{
		Spec->SomePropertyPropertyChangeLocalChangeRemoteCb(SomeProperty);
	}
}

void UTbNamesNamEsMsgBusHelper::SomePoperty2PropertyCb(int32 SomePoperty2)
{
	if (Spec)
	{
		Spec->SomePoperty2PropertyCb(SomePoperty2);
	}
}

void UTbNamesNamEsMsgBusHelper::SomePoperty2PropertyChangeLocalCheckRemoteCb(int32 SomePoperty2)
{
	if (Spec)
	{
		Spec->SomePoperty2PropertyChangeLocalCheckRemoteCb(SomePoperty2);
	}
}

void UTbNamesNamEsMsgBusHelper::SomePoperty2PropertyChangeLocalChangeRemoteCb(int32 SomePoperty2)
{
	if (Spec)
	{
		Spec->SomePoperty2PropertyChangeLocalChangeRemoteCb(SomePoperty2);
	}
}

void UTbNamesNamEsMsgBusHelper::EnumPropertyPropertyCb(ETbNamesEnum_With_Under_scores EnumProperty)
{
	if (Spec)
	{
		Spec->EnumPropertyPropertyCb(EnumProperty);
	}
}

void UTbNamesNamEsMsgBusHelper::EnumPropertyPropertyChangeLocalCheckRemoteCb(ETbNamesEnum_With_Under_scores EnumProperty)
{
	if (Spec)
	{
		Spec->EnumPropertyPropertyChangeLocalCheckRemoteCb(EnumProperty);
	}
}

void UTbNamesNamEsMsgBusHelper::EnumPropertyPropertyChangeLocalChangeRemoteCb(ETbNamesEnum_With_Under_scores EnumProperty)
{
	if (Spec)
	{
		Spec->EnumPropertyPropertyChangeLocalChangeRemoteCb(EnumProperty);
	}
}

void UTbNamesNamEsMsgBusHelper::SomeSignalSignalCb(bool bSomeParam)
{
	if (Spec)
	{
		Spec->SomeSignalSignalCb(bSomeParam);
	}
}

void UTbNamesNamEsMsgBusHelper::SomeSignal2SignalCb(bool bSomeParam)
{
	if (Spec)
	{
		Spec->SomeSignal2SignalCb(bSomeParam);
	}
}

void UTbNamesNamEsMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTbNamesNamEsMsgBusFixture::FTbNamesNamEsMsgBusFixture()
{
	Helper = NewObject<UTbNamesNamEsMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbNamesNamEsMsgBusClient>();
}

FTbNamesNamEsMsgBusFixture::~FTbNamesNamEsMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbNamesNamEsInterface> FTbNamesNamEsMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbNamesNamEsMsgBusAdapter* FTbNamesNamEsMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbNamesNamEsMsgBusAdapter>();
}

TSoftObjectPtr<UTbNamesNamEsMsgBusHelper> FTbNamesNamEsMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbNamesNamEsMsgBusFixture::GetGameInstance()
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

void FTbNamesNamEsMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTbNamesNamEsMsgBusHelper::~UTbNamesNamEsMsgBusHelper()
{
}

void UTbNamesNamEsMsgBusHelper::SetSpec(UTbNamesNamEsMsgBusSpec* /* InSpec */)
{
}

void UTbNamesNamEsMsgBusHelper::SwitchPropertyCb(bool bSwitch)
{
	(void)bSwitch;
}

void UTbNamesNamEsMsgBusHelper::SomePropertyPropertyCb(int32 SomeProperty)
{
	(void)SomeProperty;
}

void UTbNamesNamEsMsgBusHelper::SomePoperty2PropertyCb(int32 SomePoperty2)
{
	(void)SomePoperty2;
}

void UTbNamesNamEsMsgBusHelper::EnumPropertyPropertyCb(ETbNamesEnum_With_Under_scores EnumProperty)
{
	(void)EnumProperty;
}

void UTbNamesNamEsMsgBusHelper::SomeSignalSignalCb(bool bSomeParam)
{
	(void)bSomeParam;
}

void UTbNamesNamEsMsgBusHelper::SomeSignal2SignalCb(bool bSomeParam)
{
	(void)bSomeParam;
}

void UTbNamesNamEsMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
