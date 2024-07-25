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

#include "Generated/OLink/TbEnumEnumInterfaceOLinkClient.h"
#include "TbEnumEnumInterfaceOLinkFixture.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbEnumEnumInterfaceOLinkSpec, "TbEnum.EnumInterface.OLink", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

TUniquePtr<FTbEnumEnumInterfaceOLinkFixture> ImplFixture;

// signal callbacks for testing
void Prop0PropertyCb(ETbEnumEnum0 Prop0);
void Prop1PropertyCb(ETbEnumEnum1 Prop1);
void Prop2PropertyCb(ETbEnumEnum2 Prop2);
void Prop3PropertyCb(ETbEnumEnum3 Prop3);
void Sig0SignalCb(ETbEnumEnum0 Param0);
void Sig1SignalCb(ETbEnumEnum1 Param1);
void Sig2SignalCb(ETbEnumEnum2 Param2);
void Sig3SignalCb(ETbEnumEnum3 Param3);
void _SubscriptionStatusChangedCb(bool bSubscribed);
FDoneDelegate testDoneDelegate;

friend class UTbEnumEnumInterfaceOLinkHelper;
END_DEFINE_SPEC(UTbEnumEnumInterfaceOLinkSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
