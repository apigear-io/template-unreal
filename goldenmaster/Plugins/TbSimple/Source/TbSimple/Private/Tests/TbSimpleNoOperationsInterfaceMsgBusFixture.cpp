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
#include "TbSimpleNoOperationsInterfaceMsgBusFixture.h"
#include "TbSimpleNoOperationsInterfaceMsgBus.spec.h"
#include "Generated/MsgBus/TbSimpleNoOperationsInterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSimpleNoOperationsInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTbSimpleNoOperationsInterfaceMsgBusHelper::~UTbSimpleNoOperationsInterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::SetSpec(UTbSimpleNoOperationsInterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropBoolPropertyCb(bool bPropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyCb(bPropBool);
	}
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropBoolPropertyChangeLocalCheckRemoteCb(bool bPropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyChangeLocalCheckRemoteCb(bPropBool);
	}
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropBoolPropertyChangeLocalChangeRemoteCb(bool bPropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyChangeLocalChangeRemoteCb(bPropBool);
	}
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropIntPropertyCb(int32 PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyCb(PropInt);
	}
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropIntPropertyChangeLocalCheckRemoteCb(int32 PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyChangeLocalCheckRemoteCb(PropInt);
	}
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropIntPropertyChangeLocalChangeRemoteCb(int32 PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyChangeLocalChangeRemoteCb(PropInt);
	}
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::SigVoidSignalCb()
{
	if (Spec)
	{
		Spec->SigVoidSignalCb();
	}
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::SigBoolSignalCb(bool bParamBool)
{
	if (Spec)
	{
		Spec->SigBoolSignalCb(bParamBool);
	}
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTbSimpleNoOperationsInterfaceMsgBusFixture::FTbSimpleNoOperationsInterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSimpleNoOperationsInterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterfaceMsgBusClient>();
}

FTbSimpleNoOperationsInterfaceMsgBusFixture::~FTbSimpleNoOperationsInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> FTbSimpleNoOperationsInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSimpleNoOperationsInterfaceMsgBusAdapter* FTbSimpleNoOperationsInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSimpleNoOperationsInterfaceMsgBusHelper> FTbSimpleNoOperationsInterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleNoOperationsInterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleNoOperationsInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTbSimpleNoOperationsInterfaceMsgBusHelper::~UTbSimpleNoOperationsInterfaceMsgBusHelper()
{
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::SetSpec(UTbSimpleNoOperationsInterfaceMsgBusSpec* /* InSpec */)
{
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropBoolPropertyCb(bool bPropBool)
{
	(void)bPropBool;
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::PropIntPropertyCb(int32 PropInt)
{
	(void)PropInt;
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::SigVoidSignalCb()
{
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::SigBoolSignalCb(bool bParamBool)
{
	(void)bParamBool;
}

void UTbSimpleNoOperationsInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
