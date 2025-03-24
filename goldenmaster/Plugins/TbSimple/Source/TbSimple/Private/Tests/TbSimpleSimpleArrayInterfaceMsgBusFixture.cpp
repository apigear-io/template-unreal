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
#include "TbSimpleSimpleArrayInterfaceMsgBusFixture.h"
#include "TbSimpleSimpleArrayInterfaceMsgBus.spec.h"
#include "Generated/MsgBus/TbSimpleSimpleArrayInterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSimpleSimpleArrayInterfaceMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UTbSimpleSimpleArrayInterfaceMsgBusHelper::~UTbSimpleSimpleArrayInterfaceMsgBusHelper()
{
	Spec = nullptr;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SetSpec(UTbSimpleSimpleArrayInterfaceMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropBoolPropertyCb(const TArray<bool>& PropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyCb(PropBool);
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropIntPropertyCb(const TArray<int32>& PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyCb(PropInt);
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt32PropertyCb(const TArray<int32>& PropInt32)
{
	if (Spec)
	{
		Spec->PropInt32PropertyCb(PropInt32);
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt64PropertyCb(const TArray<int64>& PropInt64)
{
	if (Spec)
	{
		Spec->PropInt64PropertyCb(PropInt64);
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloatPropertyCb(const TArray<float>& PropFloat)
{
	if (Spec)
	{
		Spec->PropFloatPropertyCb(PropFloat);
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat32PropertyCb(const TArray<float>& PropFloat32)
{
	if (Spec)
	{
		Spec->PropFloat32PropertyCb(PropFloat32);
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat64PropertyCb(const TArray<double>& PropFloat64)
{
	if (Spec)
	{
		Spec->PropFloat64PropertyCb(PropFloat64);
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropStringPropertyCb(const TArray<FString>& PropString)
{
	if (Spec)
	{
		Spec->PropStringPropertyCb(PropString);
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigBoolSignalCb(const TArray<bool>& ParamBool)
{
	if (Spec)
	{
		Spec->SigBoolSignalCb(ParamBool);
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigIntSignalCb(const TArray<int32>& ParamInt)
{
	if (Spec)
	{
		Spec->SigIntSignalCb(ParamInt);
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigInt32SignalCb(const TArray<int32>& ParamInt32)
{
	if (Spec)
	{
		Spec->SigInt32SignalCb(ParamInt32);
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigInt64SignalCb(const TArray<int64>& ParamInt64)
{
	if (Spec)
	{
		Spec->SigInt64SignalCb(ParamInt64);
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigFloatSignalCb(const TArray<float>& ParamFloat)
{
	if (Spec)
	{
		Spec->SigFloatSignalCb(ParamFloat);
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigFloat32SignalCb(const TArray<float>& ParamFloa32)
{
	if (Spec)
	{
		Spec->SigFloat32SignalCb(ParamFloa32);
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigFloat64SignalCb(const TArray<double>& ParamFloat64)
{
	if (Spec)
	{
		Spec->SigFloat64SignalCb(ParamFloat64);
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigStringSignalCb(const TArray<FString>& ParamString)
{
	if (Spec)
	{
		Spec->SigStringSignalCb(ParamString);
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FTbSimpleSimpleArrayInterfaceMsgBusFixture::FTbSimpleSimpleArrayInterfaceMsgBusFixture()
{
	Helper = NewObject<UTbSimpleSimpleArrayInterfaceMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceMsgBusClient>();
}

FTbSimpleSimpleArrayInterfaceMsgBusFixture::~FTbSimpleSimpleArrayInterfaceMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> FTbSimpleSimpleArrayInterfaceMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbSimpleSimpleArrayInterfaceMsgBusAdapter* FTbSimpleSimpleArrayInterfaceMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceMsgBusAdapter>();
}

TSoftObjectPtr<UTbSimpleSimpleArrayInterfaceMsgBusHelper> FTbSimpleSimpleArrayInterfaceMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleSimpleArrayInterfaceMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleSimpleArrayInterfaceMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UTbSimpleSimpleArrayInterfaceMsgBusHelper::~UTbSimpleSimpleArrayInterfaceMsgBusHelper()
{
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SetSpec(UTbSimpleSimpleArrayInterfaceMsgBusSpec* /* InSpec */)
{
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropBoolPropertyCb(const TArray<bool>& PropBool)
{
	(void)PropBool;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropIntPropertyCb(const TArray<int32>& PropInt)
{
	(void)PropInt;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt32PropertyCb(const TArray<int32>& PropInt32)
{
	(void)PropInt32;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt64PropertyCb(const TArray<int64>& PropInt64)
{
	(void)PropInt64;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloatPropertyCb(const TArray<float>& PropFloat)
{
	(void)PropFloat;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat32PropertyCb(const TArray<float>& PropFloat32)
{
	(void)PropFloat32;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat64PropertyCb(const TArray<double>& PropFloat64)
{
	(void)PropFloat64;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropStringPropertyCb(const TArray<FString>& PropString)
{
	(void)PropString;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigBoolSignalCb(const TArray<bool>& ParamBool)
{
	(void)ParamBool;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigIntSignalCb(const TArray<int32>& ParamInt)
{
	(void)ParamInt;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigInt32SignalCb(const TArray<int32>& ParamInt32)
{
	(void)ParamInt32;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigInt64SignalCb(const TArray<int64>& ParamInt64)
{
	(void)ParamInt64;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigFloatSignalCb(const TArray<float>& ParamFloat)
{
	(void)ParamFloat;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigFloat32SignalCb(const TArray<float>& ParamFloa32)
{
	(void)ParamFloa32;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigFloat64SignalCb(const TArray<double>& ParamFloat64)
{
	(void)ParamFloat64;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigStringSignalCb(const TArray<FString>& ParamString)
{
	(void)ParamString;
}

void UTbSimpleSimpleArrayInterfaceMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
