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
#include "Testbed1StructArray2InterfaceOLinkFixture.h"
#include "Testbed1StructArray2InterfaceOLink.spec.h"
#include "OLinkCommon.h"
#include "Generated/OLink/Testbed1StructArray2InterfaceOLinkClient.h"
#include "Generated/OLink/Testbed1StructArray2InterfaceOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UTestbed1StructArray2InterfaceOLinkHelper::SetSpec(UTestbed1StructArray2InterfaceOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropBoolPropertyCb(const FTestbed1StructBoolWithArray& PropBool)
{
	Spec->PropBoolPropertyCb(PropBool);
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb(const FTestbed1StructBoolWithArray& PropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyChangeLocalCheckRemoteCb(PropBool);
	}
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb(const FTestbed1StructBoolWithArray& PropBool)
{
	if (Spec)
	{
		Spec->PropBoolPropertyChangeLocalChangeRemoteCb(PropBool);
	}
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropIntPropertyCb(const FTestbed1StructIntWithArray& PropInt)
{
	Spec->PropIntPropertyCb(PropInt);
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb(const FTestbed1StructIntWithArray& PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyChangeLocalCheckRemoteCb(PropInt);
	}
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb(const FTestbed1StructIntWithArray& PropInt)
{
	if (Spec)
	{
		Spec->PropIntPropertyChangeLocalChangeRemoteCb(PropInt);
	}
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropFloatPropertyCb(const FTestbed1StructFloatWithArray& PropFloat)
{
	Spec->PropFloatPropertyCb(PropFloat);
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropFloatPropertyChangeLocalCheckRemoteCb(const FTestbed1StructFloatWithArray& PropFloat)
{
	if (Spec)
	{
		Spec->PropFloatPropertyChangeLocalCheckRemoteCb(PropFloat);
	}
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropFloatPropertyChangeLocalChangeRemoteCb(const FTestbed1StructFloatWithArray& PropFloat)
{
	if (Spec)
	{
		Spec->PropFloatPropertyChangeLocalChangeRemoteCb(PropFloat);
	}
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropStringPropertyCb(const FTestbed1StructStringWithArray& PropString)
{
	Spec->PropStringPropertyCb(PropString);
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropStringPropertyChangeLocalCheckRemoteCb(const FTestbed1StructStringWithArray& PropString)
{
	if (Spec)
	{
		Spec->PropStringPropertyChangeLocalCheckRemoteCb(PropString);
	}
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropStringPropertyChangeLocalChangeRemoteCb(const FTestbed1StructStringWithArray& PropString)
{
	if (Spec)
	{
		Spec->PropStringPropertyChangeLocalChangeRemoteCb(PropString);
	}
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropEnumPropertyCb(const FTestbed1StructEnumWithArray& PropEnum)
{
	Spec->PropEnumPropertyCb(PropEnum);
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropEnumPropertyChangeLocalCheckRemoteCb(const FTestbed1StructEnumWithArray& PropEnum)
{
	if (Spec)
	{
		Spec->PropEnumPropertyChangeLocalCheckRemoteCb(PropEnum);
	}
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropEnumPropertyChangeLocalChangeRemoteCb(const FTestbed1StructEnumWithArray& PropEnum)
{
	if (Spec)
	{
		Spec->PropEnumPropertyChangeLocalChangeRemoteCb(PropEnum);
	}
}

void UTestbed1StructArray2InterfaceOLinkHelper::SigBoolSignalCb(const FTestbed1StructBoolWithArray& ParamBool)
{
	Spec->SigBoolSignalCb(ParamBool);
}

void UTestbed1StructArray2InterfaceOLinkHelper::SigIntSignalCb(const FTestbed1StructIntWithArray& ParamInt)
{
	Spec->SigIntSignalCb(ParamInt);
}

void UTestbed1StructArray2InterfaceOLinkHelper::SigFloatSignalCb(const FTestbed1StructFloatWithArray& ParamFloat)
{
	Spec->SigFloatSignalCb(ParamFloat);
}

void UTestbed1StructArray2InterfaceOLinkHelper::SigStringSignalCb(const FTestbed1StructStringWithArray& ParamString)
{
	Spec->SigStringSignalCb(ParamString);
}

void UTestbed1StructArray2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FTestbed1StructArray2InterfaceOLinkFixture::FTestbed1StructArray2InterfaceOLinkFixture()
{
	Helper = NewObject<UTestbed1StructArray2InterfaceOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceOLinkClient>();
}

FTestbed1StructArray2InterfaceOLinkFixture::~FTestbed1StructArray2InterfaceOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructArray2InterfaceInterface> FTestbed1StructArray2InterfaceOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FTestbed1StructArray2InterfaceOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UTestbed1StructArray2InterfaceOLinkAdapter* FTestbed1StructArray2InterfaceOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceOLinkAdapter>();
}

TSoftObjectPtr<UTestbed1StructArray2InterfaceOLinkHelper> FTestbed1StructArray2InterfaceOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed1StructArray2InterfaceOLinkFixture::GetGameInstance()
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

void FTestbed1StructArray2InterfaceOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UTestbed1StructArray2InterfaceOLinkHelper::SetSpec(UTestbed1StructArray2InterfaceOLinkSpec* /* InSpec */)
{
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropBoolPropertyCb(const FTestbed1StructBoolWithArray& PropBool)
{
	(void)PropBool;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropIntPropertyCb(const FTestbed1StructIntWithArray& PropInt)
{
	(void)PropInt;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropFloatPropertyCb(const FTestbed1StructFloatWithArray& PropFloat)
{
	(void)PropFloat;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropStringPropertyCb(const FTestbed1StructStringWithArray& PropString)
{
	(void)PropString;
}

void UTestbed1StructArray2InterfaceOLinkHelper::PropEnumPropertyCb(const FTestbed1StructEnumWithArray& PropEnum)
{
	(void)PropEnum;
}

void UTestbed1StructArray2InterfaceOLinkHelper::SigBoolSignalCb(const FTestbed1StructBoolWithArray& ParamBool)
{
	(void)ParamBool;
}

void UTestbed1StructArray2InterfaceOLinkHelper::SigIntSignalCb(const FTestbed1StructIntWithArray& ParamInt)
{
	(void)ParamInt;
}

void UTestbed1StructArray2InterfaceOLinkHelper::SigFloatSignalCb(const FTestbed1StructFloatWithArray& ParamFloat)
{
	(void)ParamFloat;
}

void UTestbed1StructArray2InterfaceOLinkHelper::SigStringSignalCb(const FTestbed1StructStringWithArray& ParamString)
{
	(void)ParamString;
}

void UTestbed1StructArray2InterfaceOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
