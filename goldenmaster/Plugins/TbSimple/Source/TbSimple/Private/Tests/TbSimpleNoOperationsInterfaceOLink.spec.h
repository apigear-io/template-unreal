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

#include "Generated/OLink/TbSimpleNoOperationsInterfaceOLinkClient.h"
#include "OLinkCommon.h"
#include "TbSimpleTestsCommon.h"
#include "TbSimpleNoOperationsInterfaceOLinkFixture.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX

BEGIN_DEFINE_SPEC(UTbSimpleNoOperationsInterfaceOLinkSpec, "TbSimple.NoOperationsInterface.OLink", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleNoOperationsInterfaceOLinkFixture> ImplFixture;

// signal callbacks for testing
void PropBoolPropertyCb(bool bPropBool);
void PropBoolPropertyChangeLocalCheckRemoteCb(bool bPropBool);
void PropBoolPropertyChangeLocalChangeRemoteCb(bool bPropBool);
void PropIntPropertyCb(int32 PropInt);
void PropIntPropertyChangeLocalCheckRemoteCb(int32 PropInt);
void PropIntPropertyChangeLocalChangeRemoteCb(int32 PropInt);
void SigVoidSignalCb();
void SigBoolSignalCb(bool bParamBool);
void _SubscriptionStatusChangedCb(bool bSubscribed);
FDoneDelegate testDoneDelegate;

friend class UTbSimpleNoOperationsInterfaceOLinkHelper;
END_DEFINE_SPEC(UTbSimpleNoOperationsInterfaceOLinkSpec);

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
