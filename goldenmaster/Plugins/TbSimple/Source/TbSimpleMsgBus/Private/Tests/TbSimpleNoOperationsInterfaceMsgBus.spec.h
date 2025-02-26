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

#include "TbSimple/Generated/MsgBus/TbSimpleNoOperationsInterfaceMsgBusClient.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "TbSimpleNoOperationsInterfaceMsgBusFixture.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

BEGIN_DEFINE_SPEC(UTbSimpleNoOperationsInterfaceMsgBusSpec, "TbSimple.NoOperationsInterface.MsgBus", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleNoOperationsInterfaceMsgBusFixture> ImplFixture;

// signal callbacks for testing
void PropBoolPropertyCb(bool bPropBool);
void PropIntPropertyCb(int32 PropInt);
void SigVoidSignalCb();
void SigBoolSignalCb(bool bParamBool);
void _ConnectionStatusChangedCb(bool bConnected);
FDoneDelegate testDoneDelegate;

friend class UTbSimpleNoOperationsInterfaceMsgBusHelper;
END_DEFINE_SPEC(UTbSimpleNoOperationsInterfaceMsgBusSpec);

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
