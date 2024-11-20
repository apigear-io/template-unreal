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

#include "Generated/OLink/TbSame2SameStruct1InterfaceOLinkClient.h"
#include "TbSame2TestsCommon.h"
#include "TbSame2SameStruct1InterfaceOLinkFixture.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbSame2SameStruct1InterfaceOLinkSpec, "TbSame2.SameStruct1Interface.OLink", TbSame2TestFilterMask);

TUniquePtr<FTbSame2SameStruct1InterfaceOLinkFixture> ImplFixture;

// signal callbacks for testing
void Prop1PropertyCb(const FTbSame2Struct1& Prop1);
void Sig1SignalCb(const FTbSame2Struct1& Param1);
void _SubscriptionStatusChangedCb(bool bSubscribed);
FDoneDelegate testDoneDelegate;

friend class UTbSame2SameStruct1InterfaceOLinkHelper;
END_DEFINE_SPEC(UTbSame2SameStruct1InterfaceOLinkSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
