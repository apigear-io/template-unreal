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
#include "TbSimpleSimpleInterfaceMsgBusFixture.h"
#include "TbSimpleSimpleInterfaceMsgBus.spec.h"
#include "Generated/MsgBus/TbSimpleSimpleInterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSimpleSimpleInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTbSimpleSimpleInterfaceMsgBusHelper::~UTbSimpleSimpleInterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SetSpec(UTbSimpleSimpleInterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropBoolPropertyCb(bool bPropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyCb(bPropBool);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropBoolPropertyChangeLocalCheckRemoteCb(bool bPropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyChangeLocalCheckRemoteCb(bPropBool);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropBoolPropertyChangeLocalChangeRemoteCb(bool bPropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyChangeLocalChangeRemoteCb(bPropBool);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropIntPropertyCb(int32 PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyCb(PropInt);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropIntPropertyChangeLocalCheckRemoteCb(int32 PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyChangeLocalCheckRemoteCb(PropInt);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropIntPropertyChangeLocalChangeRemoteCb(int32 PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyChangeLocalChangeRemoteCb(PropInt);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropInt32PropertyCb(int32 PropInt32)
{
	if (Spec)
	{
		Spec->PropInt32PropertyCb(PropInt32);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropInt32PropertyChangeLocalCheckRemoteCb(int32 PropInt32)
{
	if (Spec)
	{
		Spec->PropInt32PropertyChangeLocalCheckRemoteCb(PropInt32);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropInt32PropertyChangeLocalChangeRemoteCb(int32 PropInt32)
{
	if (Spec)
	{
		Spec->PropInt32PropertyChangeLocalChangeRemoteCb(PropInt32);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropInt64PropertyCb(int64 PropInt64)
{
	if (Spec)
	{
		Spec->PropInt64PropertyCb(PropInt64);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropInt64PropertyChangeLocalCheckRemoteCb(int64 PropInt64)
{
	if (Spec)
	{
		Spec->PropInt64PropertyChangeLocalCheckRemoteCb(PropInt64);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropInt64PropertyChangeLocalChangeRemoteCb(int64 PropInt64)
{
	if (Spec)
	{
		Spec->PropInt64PropertyChangeLocalChangeRemoteCb(PropInt64);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropFloatPropertyCb(float PropFloat)
{
	if (Spec)
	{
		Spec->PropFloatPropertyCb(PropFloat);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropFloatPropertyChangeLocalCheckRemoteCb(float PropFloat)
{
	if (Spec)
	{
		Spec->PropFloatPropertyChangeLocalCheckRemoteCb(PropFloat);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropFloatPropertyChangeLocalChangeRemoteCb(float PropFloat)
{
	if (Spec)
	{
		Spec->PropFloatPropertyChangeLocalChangeRemoteCb(PropFloat);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropFloat32PropertyCb(float PropFloat32)
{
	if (Spec)
	{
		Spec->PropFloat32PropertyCb(PropFloat32);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropFloat32PropertyChangeLocalCheckRemoteCb(float PropFloat32)
{
	if (Spec)
	{
		Spec->PropFloat32PropertyChangeLocalCheckRemoteCb(PropFloat32);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropFloat32PropertyChangeLocalChangeRemoteCb(float PropFloat32)
{
	if (Spec)
	{
		Spec->PropFloat32PropertyChangeLocalChangeRemoteCb(PropFloat32);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropFloat64PropertyCb(double PropFloat64)
{
	if (Spec)
	{
		Spec->PropFloat64PropertyCb(PropFloat64);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropFloat64PropertyChangeLocalCheckRemoteCb(double PropFloat64)
{
	if (Spec)
	{
		Spec->PropFloat64PropertyChangeLocalCheckRemoteCb(PropFloat64);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropFloat64PropertyChangeLocalChangeRemoteCb(double PropFloat64)
{
	if (Spec)
	{
		Spec->PropFloat64PropertyChangeLocalChangeRemoteCb(PropFloat64);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropStringPropertyCb(const FString& PropString)
{
	if (Spec)
	{
		Spec->PropStringPropertyCb(PropString);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropStringPropertyChangeLocalCheckRemoteCb(const FString& PropString)
{
	if (Spec)
	{
		Spec->PropStringPropertyChangeLocalCheckRemoteCb(PropString);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropStringPropertyChangeLocalChangeRemoteCb(const FString& PropString)
{
	if (Spec)
	{
		Spec->PropStringPropertyChangeLocalChangeRemoteCb(PropString);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SigBoolSignalCb(bool bParamBool)
{
	if (Spec)
	{
		Spec->SigBoolSignalCb(bParamBool);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SigIntSignalCb(int32 ParamInt)
{
	if (Spec)
	{
		Spec->SigIntSignalCb(ParamInt);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SigInt32SignalCb(int32 ParamInt32)
{
	if (Spec)
	{
		Spec->SigInt32SignalCb(ParamInt32);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SigInt64SignalCb(int64 ParamInt64)
{
	if (Spec)
	{
		Spec->SigInt64SignalCb(ParamInt64);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SigFloatSignalCb(float ParamFloat)
{
	if (Spec)
	{
		Spec->SigFloatSignalCb(ParamFloat);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SigFloat32SignalCb(float ParamFloat32)
{
	if (Spec)
	{
		Spec->SigFloat32SignalCb(ParamFloat32);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SigFloat64SignalCb(double ParamFloat64)
{
	if (Spec)
	{
		Spec->SigFloat64SignalCb(ParamFloat64);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SigStringSignalCb(const FString& ParamString)
{
	if (Spec)
	{
		Spec->SigStringSignalCb(ParamString);
	}
}

void UTbSimpleSimpleInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTbSimpleSimpleInterfaceMsgBusFixture::FTbSimpleSimpleInterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSimpleSimpleInterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleSimpleInterfaceMsgBusClient>();
}

FTbSimpleSimpleInterfaceMsgBusFixture::~FTbSimpleSimpleInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleSimpleInterfaceInterface> FTbSimpleSimpleInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSimpleSimpleInterfaceMsgBusAdapter* FTbSimpleSimpleInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleSimpleInterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSimpleSimpleInterfaceMsgBusHelper> FTbSimpleSimpleInterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleSimpleInterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleSimpleInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTbSimpleSimpleInterfaceMsgBusHelper::~UTbSimpleSimpleInterfaceMsgBusHelper()
{
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SetSpec(UTbSimpleSimpleInterfaceMsgBusSpec* /* InSpec */)
{
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropBoolPropertyCb(bool bPropBool)
{
	(void)bPropBool;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropIntPropertyCb(int32 PropInt)
{
	(void)PropInt;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropInt32PropertyCb(int32 PropInt32)
{
	(void)PropInt32;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropInt64PropertyCb(int64 PropInt64)
{
	(void)PropInt64;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropFloatPropertyCb(float PropFloat)
{
	(void)PropFloat;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropFloat32PropertyCb(float PropFloat32)
{
	(void)PropFloat32;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropFloat64PropertyCb(double PropFloat64)
{
	(void)PropFloat64;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::PropStringPropertyCb(const FString& PropString)
{
	(void)PropString;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SigBoolSignalCb(bool bParamBool)
{
	(void)bParamBool;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SigIntSignalCb(int32 ParamInt)
{
	(void)ParamInt;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SigInt32SignalCb(int32 ParamInt32)
{
	(void)ParamInt32;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SigInt64SignalCb(int64 ParamInt64)
{
	(void)ParamInt64;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SigFloatSignalCb(float ParamFloat)
{
	(void)ParamFloat;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SigFloat32SignalCb(float ParamFloat32)
{
	(void)ParamFloat32;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SigFloat64SignalCb(double ParamFloat64)
{
	(void)ParamFloat64;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::SigStringSignalCb(const FString& ParamString)
{
	(void)ParamString;
}

void UTbSimpleSimpleInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
