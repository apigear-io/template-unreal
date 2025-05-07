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
#include "Testbed1StructInterfaceOLinkFixture.h"
#include "Testbed1StructInterfaceOLink.spec.h"
#include "OLinkCommon.h"
#include "Generated/OLink/Testbed1StructInterfaceOLinkClient.h"
#include "Generated/OLink/Testbed1StructInterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTestbed1StructInterfaceOLinkHelper::SetSpec(UTestbed1StructInterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed1StructInterfaceOLinkHelper::PropBoolPropertyCb(const FTestbed1StructBool& PropBool)
{
	Spec->PropBoolPropertyCb(PropBool);
}

void UTestbed1StructInterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const FTestbed1StructBool& PropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyChangeLocalCheckRemoteCb(PropBool);
	}
}

void UTestbed1StructInterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const FTestbed1StructBool& PropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyChangeLocalChangeRemoteCb(PropBool);
	}
}

void UTestbed1StructInterfaceOLinkHelper::PropIntPropertyCb(const FTestbed1StructInt& PropInt)
{
	Spec->PropIntPropertyCb(PropInt);
}

void UTestbed1StructInterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb(const FTestbed1StructInt& PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyChangeLocalCheckRemoteCb(PropInt);
	}
}

void UTestbed1StructInterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb(const FTestbed1StructInt& PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyChangeLocalChangeRemoteCb(PropInt);
	}
}

void UTestbed1StructInterfaceOLinkHelper::PropFloatPropertyCb(const FTestbed1StructFloat& PropFloat)
{
	Spec->PropFloatPropertyCb(PropFloat);
}

void UTestbed1StructInterfaceOLinkHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const FTestbed1StructFloat& PropFloat)
{
	if (Spec)
	{
		Spec->PropFloatPropertyChangeLocalCheckRemoteCb(PropFloat);
	}
}

void UTestbed1StructInterfaceOLinkHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const FTestbed1StructFloat& PropFloat)
{
	if (Spec)
	{
		Spec->PropFloatPropertyChangeLocalChangeRemoteCb(PropFloat);
	}
}

void UTestbed1StructInterfaceOLinkHelper::PropStringPropertyCb(const FTestbed1StructString& PropString)
{
	Spec->PropStringPropertyCb(PropString);
}

void UTestbed1StructInterfaceOLinkHelper::PropStringPropertyChangeLocalCheckRemoteCb(const FTestbed1StructString& PropString)
{
	if (Spec)
	{
		Spec->PropStringPropertyChangeLocalCheckRemoteCb(PropString);
	}
}

void UTestbed1StructInterfaceOLinkHelper::PropStringPropertyChangeLocalChangeRemoteCb(const FTestbed1StructString& PropString)
{
	if (Spec)
	{
		Spec->PropStringPropertyChangeLocalChangeRemoteCb(PropString);
	}
}

void UTestbed1StructInterfaceOLinkHelper::SigBoolSignalCb(const FTestbed1StructBool& ParamBool)
{
	Spec->SigBoolSignalCb(ParamBool);
}

void UTestbed1StructInterfaceOLinkHelper::SigIntSignalCb(const FTestbed1StructInt& ParamInt)
{
	Spec->SigIntSignalCb(ParamInt);
}

void UTestbed1StructInterfaceOLinkHelper::SigFloatSignalCb(const FTestbed1StructFloat& ParamFloat)
{
	Spec->SigFloatSignalCb(ParamFloat);
}

void UTestbed1StructInterfaceOLinkHelper::SigStringSignalCb(const FTestbed1StructString& ParamString)
{
	Spec->SigStringSignalCb(ParamString);
}

void UTestbed1StructInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTestbed1StructInterfaceOLinkFixture::FTestbed1StructInterfaceOLinkFixture()
{
	Helper = NewObject<UTestbed1StructInterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructInterfaceOLinkClient>();
}

FTestbed1StructInterfaceOLinkFixture::~FTestbed1StructInterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructInterfaceInterface> FTestbed1StructInterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTestbed1StructInterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTestbed1StructInterfaceOLinkAdapter* FTestbed1StructInterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructInterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTestbed1StructInterfaceOLinkHelper> FTestbed1StructInterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed1StructInterfaceOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed1StructInterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTestbed1StructInterfaceOLinkHelper::SetSpec(UTestbed1StructInterfaceOLinkSpec* /* InSpec */)
{
}

void UTestbed1StructInterfaceOLinkHelper::PropBoolPropertyCb(const FTestbed1StructBool& PropBool)
{
	(void)PropBool;
}

void UTestbed1StructInterfaceOLinkHelper::PropIntPropertyCb(const FTestbed1StructInt& PropInt)
{
	(void)PropInt;
}

void UTestbed1StructInterfaceOLinkHelper::PropFloatPropertyCb(const FTestbed1StructFloat& PropFloat)
{
	(void)PropFloat;
}

void UTestbed1StructInterfaceOLinkHelper::PropStringPropertyCb(const FTestbed1StructString& PropString)
{
	(void)PropString;
}

void UTestbed1StructInterfaceOLinkHelper::SigBoolSignalCb(const FTestbed1StructBool& ParamBool)
{
	(void)ParamBool;
}

void UTestbed1StructInterfaceOLinkHelper::SigIntSignalCb(const FTestbed1StructInt& ParamInt)
{
	(void)ParamInt;
}

void UTestbed1StructInterfaceOLinkHelper::SigFloatSignalCb(const FTestbed1StructFloat& ParamFloat)
{
	(void)ParamFloat;
}

void UTestbed1StructInterfaceOLinkHelper::SigStringSignalCb(const FTestbed1StructString& ParamString)
{
	(void)ParamString;
}

void UTestbed1StructInterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
