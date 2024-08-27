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

#include "Generated/OLink/TbSimpleNoSignalsInterfaceOLinkClient.h"
#include "TbSimpleNoSignalsInterfaceOLinkFixture.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbSimpleNoSignalsInterfaceOLinkSpec, "TbSimple.NoSignalsInterface.OLink", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

TUniquePtr<FTbSimpleNoSignalsInterfaceOLinkFixture> ImplFixture;

// signal callbacks for testing
void PropBoolPropertyCb(bool bPropBool);
void PropIntPropertyCb(int32 PropInt);
void _SubscriptionStatusChangedCb(bool bSubscribed);
FDoneDelegate testDoneDelegate;

friend class UTbSimpleNoSignalsInterfaceOLinkHelper;
END_DEFINE_SPEC(UTbSimpleNoSignalsInterfaceOLinkSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
