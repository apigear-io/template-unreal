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

#include "TbSimple/Generated/OLink/TbSimpleNoPropertiesInterfaceOLinkClient.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "TbSimpleNoPropertiesInterfaceOLinkFixture.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

BEGIN_DEFINE_SPEC(UTbSimpleNoPropertiesInterfaceOLinkSpec, "TbSimple.NoPropertiesInterface.OLink", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleNoPropertiesInterfaceOLinkFixture> ImplFixture;

// signal callbacks for testing
void SigVoidSignalCb();
void SigBoolSignalCb(bool bParamBool);
void _SubscriptionStatusChangedCb(bool bSubscribed);
FDoneDelegate testDoneDelegate;

friend class UTbSimpleNoPropertiesInterfaceOLinkHelper;
END_DEFINE_SPEC(UTbSimpleNoPropertiesInterfaceOLinkSpec);

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
