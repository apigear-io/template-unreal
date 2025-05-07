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
#pragma once

#include "Generated/OLink/Testbed1StructArray2InterfaceOLinkClient.h"
#include "OLinkCommon.h"
#include "Testbed1TestsCommon.h"
#include "Testbed1StructArray2InterfaceOLinkFixture.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX

BEGIN_DEFINE_SPEC(UTestbed1StructArray2InterfaceOLinkSpec, "Testbed1.StructArray2Interface.OLink", Testbed1TestFilterMask);

TUniquePtr<FTestbed1StructArray2InterfaceOLinkFixture> ImplFixture;

// signal callbacks for testing
void PropBoolPropertyCb(const FTestbed1StructBoolWithArray& PropBool);
void PropBoolPropertyChangeLocalCheckRemoteCb(const FTestbed1StructBoolWithArray& PropBool);
void PropBoolPropertyChangeLocalChangeRemoteCb(const FTestbed1StructBoolWithArray& PropBool);
void PropIntPropertyCb(const FTestbed1StructIntWithArray& PropInt);
void PropIntPropertyChangeLocalCheckRemoteCb(const FTestbed1StructIntWithArray& PropInt);
void PropIntPropertyChangeLocalChangeRemoteCb(const FTestbed1StructIntWithArray& PropInt);
void PropFloatPropertyCb(const FTestbed1StructFloatWithArray& PropFloat);
void PropFloatPropertyChangeLocalCheckRemoteCb(const FTestbed1StructFloatWithArray& PropFloat);
void PropFloatPropertyChangeLocalChangeRemoteCb(const FTestbed1StructFloatWithArray& PropFloat);
void PropStringPropertyCb(const FTestbed1StructStringWithArray& PropString);
void PropStringPropertyChangeLocalCheckRemoteCb(const FTestbed1StructStringWithArray& PropString);
void PropStringPropertyChangeLocalChangeRemoteCb(const FTestbed1StructStringWithArray& PropString);
void PropEnumPropertyCb(const FTestbed1StructEnumWithArray& PropEnum);
void PropEnumPropertyChangeLocalCheckRemoteCb(const FTestbed1StructEnumWithArray& PropEnum);
void PropEnumPropertyChangeLocalChangeRemoteCb(const FTestbed1StructEnumWithArray& PropEnum);
void SigBoolSignalCb(const FTestbed1StructBoolWithArray& ParamBool);
void SigIntSignalCb(const FTestbed1StructIntWithArray& ParamInt);
void SigFloatSignalCb(const FTestbed1StructFloatWithArray& ParamFloat);
void SigStringSignalCb(const FTestbed1StructStringWithArray& ParamString);
void _SubscriptionStatusChangedCb(bool bSubscribed);
FDoneDelegate testDoneDelegate;

friend class UTestbed1StructArray2InterfaceOLinkHelper;
END_DEFINE_SPEC(UTestbed1StructArray2InterfaceOLinkSpec);

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
