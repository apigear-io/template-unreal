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
#include "TbSimpleSimpleInterfaceOLinkFixture.h"
#include "TbSimpleSimpleInterfaceOLink.spec.h"
#include "OLinkCommon.h"
#include "Generated/OLink/TbSimpleSimpleInterfaceOLinkClient.h"
#include "Generated/OLink/TbSimpleSimpleInterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTbSimpleSimpleInterfaceOLinkHelper::SetSpec(UTbSimpleSimpleInterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropBoolPropertyCb(bool bPropBool)
{
	Spec->PropBoolPropertyCb(bPropBool);
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb(bool bPropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyChangeLocalCheckRemoteCb(bPropBool);
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb(bool bPropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyChangeLocalChangeRemoteCb(bPropBool);
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropIntPropertyCb(int32 PropInt)
{
	Spec->PropIntPropertyCb(PropInt);
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb(int32 PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyChangeLocalCheckRemoteCb(PropInt);
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb(int32 PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyChangeLocalChangeRemoteCb(PropInt);
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt32PropertyCb(int32 PropInt32)
{
	Spec->PropInt32PropertyCb(PropInt32);
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt32PropertyChangeLocalCheckRemoteCb(int32 PropInt32)
{
	if (Spec)
	{
		Spec->PropInt32PropertyChangeLocalCheckRemoteCb(PropInt32);
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt32PropertyChangeLocalChangeRemoteCb(int32 PropInt32)
{
	if (Spec)
	{
		Spec->PropInt32PropertyChangeLocalChangeRemoteCb(PropInt32);
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt64PropertyCb(int64 PropInt64)
{
	Spec->PropInt64PropertyCb(PropInt64);
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt64PropertyChangeLocalCheckRemoteCb(int64 PropInt64)
{
	if (Spec)
	{
		Spec->PropInt64PropertyChangeLocalCheckRemoteCb(PropInt64);
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt64PropertyChangeLocalChangeRemoteCb(int64 PropInt64)
{
	if (Spec)
	{
		Spec->PropInt64PropertyChangeLocalChangeRemoteCb(PropInt64);
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloatPropertyCb(float PropFloat)
{
	Spec->PropFloatPropertyCb(PropFloat);
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloatPropertyChangeLocalCheckRemoteCb(float PropFloat)
{
	if (Spec)
	{
		Spec->PropFloatPropertyChangeLocalCheckRemoteCb(PropFloat);
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloatPropertyChangeLocalChangeRemoteCb(float PropFloat)
{
	if (Spec)
	{
		Spec->PropFloatPropertyChangeLocalChangeRemoteCb(PropFloat);
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat32PropertyCb(float PropFloat32)
{
	Spec->PropFloat32PropertyCb(PropFloat32);
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat32PropertyChangeLocalCheckRemoteCb(float PropFloat32)
{
	if (Spec)
	{
		Spec->PropFloat32PropertyChangeLocalCheckRemoteCb(PropFloat32);
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat32PropertyChangeLocalChangeRemoteCb(float PropFloat32)
{
	if (Spec)
	{
		Spec->PropFloat32PropertyChangeLocalChangeRemoteCb(PropFloat32);
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat64PropertyCb(double PropFloat64)
{
	Spec->PropFloat64PropertyCb(PropFloat64);
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat64PropertyChangeLocalCheckRemoteCb(double PropFloat64)
{
	if (Spec)
	{
		Spec->PropFloat64PropertyChangeLocalCheckRemoteCb(PropFloat64);
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat64PropertyChangeLocalChangeRemoteCb(double PropFloat64)
{
	if (Spec)
	{
		Spec->PropFloat64PropertyChangeLocalChangeRemoteCb(PropFloat64);
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropStringPropertyCb(const FString& PropString)
{
	Spec->PropStringPropertyCb(PropString);
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropStringPropertyChangeLocalCheckRemoteCb(const FString& PropString)
{
	if (Spec)
	{
		Spec->PropStringPropertyChangeLocalCheckRemoteCb(PropString);
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropStringPropertyChangeLocalChangeRemoteCb(const FString& PropString)
{
	if (Spec)
	{
		Spec->PropStringPropertyChangeLocalChangeRemoteCb(PropString);
	}
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigBoolSignalCb(bool bParamBool)
{
	Spec->SigBoolSignalCb(bParamBool);
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigIntSignalCb(int32 ParamInt)
{
	Spec->SigIntSignalCb(ParamInt);
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigInt32SignalCb(int32 ParamInt32)
{
	Spec->SigInt32SignalCb(ParamInt32);
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigInt64SignalCb(int64 ParamInt64)
{
	Spec->SigInt64SignalCb(ParamInt64);
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigFloatSignalCb(float ParamFloat)
{
	Spec->SigFloatSignalCb(ParamFloat);
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigFloat32SignalCb(float ParamFloat32)
{
	Spec->SigFloat32SignalCb(ParamFloat32);
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigFloat64SignalCb(double ParamFloat64)
{
	Spec->SigFloat64SignalCb(ParamFloat64);
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigStringSignalCb(const FString& ParamString)
{
	Spec->SigStringSignalCb(ParamString);
}

void UTbSimpleSimpleInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTbSimpleSimpleInterfaceOLinkFixture::FTbSimpleSimpleInterfaceOLinkFixture()
{
	Helper = NewObject<UTbSimpleSimpleInterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleSimpleInterfaceOLinkClient>();
}

FTbSimpleSimpleInterfaceOLinkFixture::~FTbSimpleSimpleInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleSimpleInterfaceInterface> FTbSimpleSimpleInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSimpleSimpleInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSimpleSimpleInterfaceOLinkAdapter* FTbSimpleSimpleInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleSimpleInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSimpleSimpleInterfaceOLinkHelper> FTbSimpleSimpleInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleSimpleInterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleSimpleInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTbSimpleSimpleInterfaceOLinkHelper::SetSpec(UTbSimpleSimpleInterfaceOLinkSpec* /* InSpec */)
{
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropBoolPropertyCb(bool bPropBool)
{
	(void)bPropBool;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropIntPropertyCb(int32 PropInt)
{
	(void)PropInt;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt32PropertyCb(int32 PropInt32)
{
	(void)PropInt32;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropInt64PropertyCb(int64 PropInt64)
{
	(void)PropInt64;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloatPropertyCb(float PropFloat)
{
	(void)PropFloat;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat32PropertyCb(float PropFloat32)
{
	(void)PropFloat32;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropFloat64PropertyCb(double PropFloat64)
{
	(void)PropFloat64;
}

void UTbSimpleSimpleInterfaceOLinkHelper::PropStringPropertyCb(const FString& PropString)
{
	(void)PropString;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigBoolSignalCb(bool bParamBool)
{
	(void)bParamBool;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigIntSignalCb(int32 ParamInt)
{
	(void)ParamInt;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigInt32SignalCb(int32 ParamInt32)
{
	(void)ParamInt32;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigInt64SignalCb(int64 ParamInt64)
{
	(void)ParamInt64;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigFloatSignalCb(float ParamFloat)
{
	(void)ParamFloat;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigFloat32SignalCb(float ParamFloat32)
{
	(void)ParamFloat32;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigFloat64SignalCb(double ParamFloat64)
{
	(void)ParamFloat64;
}

void UTbSimpleSimpleInterfaceOLinkHelper::SigStringSignalCb(const FString& ParamString)
{
	(void)ParamString;
}

void UTbSimpleSimpleInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
