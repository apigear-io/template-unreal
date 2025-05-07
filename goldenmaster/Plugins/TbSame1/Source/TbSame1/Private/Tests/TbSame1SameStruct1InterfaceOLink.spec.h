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

#include "Generated/OLink/TbSame1SameStruct1InterfaceOLinkClient.h"
#include "OLinkCommon.h"
#include "TbSame1TestsCommon.h"
#include "TbSame1SameStruct1InterfaceOLinkFixture.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX

BEGIN_DEFINE_SPEC(UTbSame1SameStruct1InterfaceOLinkSpec, "TbSame1.SameStruct1Interface.OLink", TbSame1TestFilterMask);

TUniquePtr<FTbSame1SameStruct1InterfaceOLinkFixture> ImplFixture;

// signal callbacks for testing
void Prop1PropertyCb(const FTbSame1Struct1& Prop1);
void Prop1PropertyChangeLocalCheckRemoteCb(const FTbSame1Struct1& Prop1);
void Prop1PropertyChangeLocalChangeRemoteCb(const FTbSame1Struct1& Prop1);
void Sig1SignalCb(const FTbSame1Struct1& Param1);
void _SubscriptionStatusChangedCb(bool bSubscribed);
FDoneDelegate testDoneDelegate;

friend class UTbSame1SameStruct1InterfaceOLinkHelper;
END_DEFINE_SPEC(UTbSame1SameStruct1InterfaceOLinkSpec);

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
