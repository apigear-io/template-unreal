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
#include "TbSimpleSimpleArrayInterfaceOLinkFixture.h"
#include "TbSimpleSimpleArrayInterfaceOLink.spec.h"
#include "OLinkCommon.h"
#include "Generated/OLink/TbSimpleSimpleArrayInterfaceOLinkClient.h"
#include "Generated/OLink/TbSimpleSimpleArrayInterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SetSpec(UTbSimpleSimpleArrayInterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropBoolPropertyCb(const TArray<bool>& PropBool)
{
	Spec->PropBoolPropertyCb(PropBool);
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const TArray<bool>& PropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyChangeLocalCheckRemoteCb(PropBool);
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const TArray<bool>& PropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyChangeLocalChangeRemoteCb(PropBool);
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropIntPropertyCb(const TArray<int32>& PropInt)
{
	Spec->PropIntPropertyCb(PropInt);
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb(const TArray<int32>& PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyChangeLocalCheckRemoteCb(PropInt);
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb(const TArray<int32>& PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyChangeLocalChangeRemoteCb(PropInt);
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt32PropertyCb(const TArray<int32>& PropInt32)
{
	Spec->PropInt32PropertyCb(PropInt32);
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt32PropertyChangeLocalCheckRemoteCb(const TArray<int32>& PropInt32)
{
	if (Spec)
	{
		Spec->PropInt32PropertyChangeLocalCheckRemoteCb(PropInt32);
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt32PropertyChangeLocalChangeRemoteCb(const TArray<int32>& PropInt32)
{
	if (Spec)
	{
		Spec->PropInt32PropertyChangeLocalChangeRemoteCb(PropInt32);
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt64PropertyCb(const TArray<int64>& PropInt64)
{
	Spec->PropInt64PropertyCb(PropInt64);
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt64PropertyChangeLocalCheckRemoteCb(const TArray<int64>& PropInt64)
{
	if (Spec)
	{
		Spec->PropInt64PropertyChangeLocalCheckRemoteCb(PropInt64);
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt64PropertyChangeLocalChangeRemoteCb(const TArray<int64>& PropInt64)
{
	if (Spec)
	{
		Spec->PropInt64PropertyChangeLocalChangeRemoteCb(PropInt64);
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloatPropertyCb(const TArray<float>& PropFloat)
{
	Spec->PropFloatPropertyCb(PropFloat);
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const TArray<float>& PropFloat)
{
	if (Spec)
	{
		Spec->PropFloatPropertyChangeLocalCheckRemoteCb(PropFloat);
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const TArray<float>& PropFloat)
{
	if (Spec)
	{
		Spec->PropFloatPropertyChangeLocalChangeRemoteCb(PropFloat);
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat32PropertyCb(const TArray<float>& PropFloat32)
{
	Spec->PropFloat32PropertyCb(PropFloat32);
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat32PropertyChangeLocalCheckRemoteCb(const TArray<float>& PropFloat32)
{
	if (Spec)
	{
		Spec->PropFloat32PropertyChangeLocalCheckRemoteCb(PropFloat32);
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat32PropertyChangeLocalChangeRemoteCb(const TArray<float>& PropFloat32)
{
	if (Spec)
	{
		Spec->PropFloat32PropertyChangeLocalChangeRemoteCb(PropFloat32);
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat64PropertyCb(const TArray<double>& PropFloat64)
{
	Spec->PropFloat64PropertyCb(PropFloat64);
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat64PropertyChangeLocalCheckRemoteCb(const TArray<double>& PropFloat64)
{
	if (Spec)
	{
		Spec->PropFloat64PropertyChangeLocalCheckRemoteCb(PropFloat64);
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat64PropertyChangeLocalChangeRemoteCb(const TArray<double>& PropFloat64)
{
	if (Spec)
	{
		Spec->PropFloat64PropertyChangeLocalChangeRemoteCb(PropFloat64);
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropStringPropertyCb(const TArray<FString>& PropString)
{
	Spec->PropStringPropertyCb(PropString);
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropStringPropertyChangeLocalCheckRemoteCb(const TArray<FString>& PropString)
{
	if (Spec)
	{
		Spec->PropStringPropertyChangeLocalCheckRemoteCb(PropString);
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropStringPropertyChangeLocalChangeRemoteCb(const TArray<FString>& PropString)
{
	if (Spec)
	{
		Spec->PropStringPropertyChangeLocalChangeRemoteCb(PropString);
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigBoolSignalCb(const TArray<bool>& ParamBool)
{
	Spec->SigBoolSignalCb(ParamBool);
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigIntSignalCb(const TArray<int32>& ParamInt)
{
	Spec->SigIntSignalCb(ParamInt);
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigInt32SignalCb(const TArray<int32>& ParamInt32)
{
	Spec->SigInt32SignalCb(ParamInt32);
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigInt64SignalCb(const TArray<int64>& ParamInt64)
{
	Spec->SigInt64SignalCb(ParamInt64);
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigFloatSignalCb(const TArray<float>& ParamFloat)
{
	Spec->SigFloatSignalCb(ParamFloat);
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigFloat32SignalCb(const TArray<float>& ParamFloa32)
{
	Spec->SigFloat32SignalCb(ParamFloa32);
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigFloat64SignalCb(const TArray<double>& ParamFloat64)
{
	Spec->SigFloat64SignalCb(ParamFloat64);
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigStringSignalCb(const TArray<FString>& ParamString)
{
	Spec->SigStringSignalCb(ParamString);
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTbSimpleSimpleArrayInterfaceOLinkFixture::FTbSimpleSimpleArrayInterfaceOLinkFixture()
{
	Helper = NewObject<UTbSimpleSimpleArrayInterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceOLinkClient>();
}

FTbSimpleSimpleArrayInterfaceOLinkFixture::~FTbSimpleSimpleArrayInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> FTbSimpleSimpleArrayInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTbSimpleSimpleArrayInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTbSimpleSimpleArrayInterfaceOLinkAdapter* FTbSimpleSimpleArrayInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTbSimpleSimpleArrayInterfaceOLinkHelper> FTbSimpleSimpleArrayInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleSimpleArrayInterfaceOLinkFixture::GetGameInstance()
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

void FTbSimpleSimpleArrayInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTbSimpleSimpleArrayInterfaceOLinkHelper::SetSpec(UTbSimpleSimpleArrayInterfaceOLinkSpec* /* InSpec */)
{
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropBoolPropertyCb(const TArray<bool>& PropBool)
{
	(void)PropBool;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropIntPropertyCb(const TArray<int32>& PropInt)
{
	(void)PropInt;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt32PropertyCb(const TArray<int32>& PropInt32)
{
	(void)PropInt32;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt64PropertyCb(const TArray<int64>& PropInt64)
{
	(void)PropInt64;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloatPropertyCb(const TArray<float>& PropFloat)
{
	(void)PropFloat;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat32PropertyCb(const TArray<float>& PropFloat32)
{
	(void)PropFloat32;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat64PropertyCb(const TArray<double>& PropFloat64)
{
	(void)PropFloat64;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::PropStringPropertyCb(const TArray<FString>& PropString)
{
	(void)PropString;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigBoolSignalCb(const TArray<bool>& ParamBool)
{
	(void)ParamBool;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigIntSignalCb(const TArray<int32>& ParamInt)
{
	(void)ParamInt;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigInt32SignalCb(const TArray<int32>& ParamInt32)
{
	(void)ParamInt32;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigInt64SignalCb(const TArray<int64>& ParamInt64)
{
	(void)ParamInt64;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigFloatSignalCb(const TArray<float>& ParamFloat)
{
	(void)ParamFloat;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigFloat32SignalCb(const TArray<float>& ParamFloa32)
{
	(void)ParamFloa32;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigFloat64SignalCb(const TArray<double>& ParamFloat64)
{
	(void)ParamFloat64;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::SigStringSignalCb(const TArray<FString>& ParamString)
{
	(void)ParamString;
}

void UTbSimpleSimpleArrayInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
