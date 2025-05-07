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

#include "Generated/OLink/TbNamesNamEsOLinkClient.h"
#include "OLinkCommon.h"
#include "TbNamesTestsCommon.h"
#include "TbNamesNamEsOLinkFixture.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX

BEGIN_DEFINE_SPEC(UTbNamesNamEsOLinkSpec, "TbNames.NamEs.OLink", TbNamesTestFilterMask);

TUniquePtr<FTbNamesNamEsOLinkFixture> ImplFixture;

// signal callbacks for testing
void SwitchPropertyCb(bool bSwitch);
void SwitchPropertyChangeLocalCheckRemoteCb(bool bSwitch);
void SwitchPropertyChangeLocalChangeRemoteCb(bool bSwitch);
void SomePropertyPropertyCb(int32 SomeProperty);
void SomePropertyPropertyChangeLocalCheckRemoteCb(int32 SomeProperty);
void SomePropertyPropertyChangeLocalChangeRemoteCb(int32 SomeProperty);
void SomePoperty2PropertyCb(int32 SomePoperty2);
void SomePoperty2PropertyChangeLocalCheckRemoteCb(int32 SomePoperty2);
void SomePoperty2PropertyChangeLocalChangeRemoteCb(int32 SomePoperty2);
void EnumPropertyPropertyCb(ETbNamesEnum_With_Under_scores EnumProperty);
void EnumPropertyPropertyChangeLocalCheckRemoteCb(ETbNamesEnum_With_Under_scores EnumProperty);
void EnumPropertyPropertyChangeLocalChangeRemoteCb(ETbNamesEnum_With_Under_scores EnumProperty);
void SomeSignalSignalCb(bool bSomeParam);
void SomeSignal2SignalCb(bool bSomeParam);
void _SubscriptionStatusChangedCb(bool bSubscribed);
FDoneDelegate testDoneDelegate;

friend class UTbNamesNamEsOLinkHelper;
END_DEFINE_SPEC(UTbNamesNamEsOLinkSpec);

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
