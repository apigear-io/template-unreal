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

#include "TbSimple/Generated/MsgBus/TbSimpleSimpleInterfaceMsgBusClient.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "TbSimpleSimpleInterfaceMsgBusFixture.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

BEGIN_DEFINE_SPEC(UTbSimpleSimpleInterfaceMsgBusSpec, "TbSimple.SimpleInterface.MsgBus", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleSimpleInterfaceMsgBusFixture> ImplFixture;

// signal callbacks for testing
void PropBoolPropertyCb(bool bPropBool);
void PropIntPropertyCb(int32 PropInt);
void PropInt32PropertyCb(int32 PropInt32);
void PropInt64PropertyCb(int64 PropInt64);
void PropFloatPropertyCb(float PropFloat);
void PropFloat32PropertyCb(float PropFloat32);
void PropFloat64PropertyCb(double PropFloat64);
void PropStringPropertyCb(const FString& PropString);
void SigBoolSignalCb(bool bParamBool);
void SigIntSignalCb(int32 ParamInt);
void SigInt32SignalCb(int32 ParamInt32);
void SigInt64SignalCb(int64 ParamInt64);
void SigFloatSignalCb(float ParamFloat);
void SigFloat32SignalCb(float ParamFloat32);
void SigFloat64SignalCb(double ParamFloat64);
void SigStringSignalCb(const FString& ParamString);
void _ConnectionStatusChangedCb(bool bConnected);
FDoneDelegate testDoneDelegate;

friend class UTbSimpleSimpleInterfaceMsgBusHelper;
END_DEFINE_SPEC(UTbSimpleSimpleInterfaceMsgBusSpec);

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
