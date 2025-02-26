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

#include "TbSimple/Generated/MsgBus/TbSimpleSimpleArrayInterfaceMsgBusClient.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "TbSimpleSimpleArrayInterfaceMsgBusFixture.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

BEGIN_DEFINE_SPEC(UTbSimpleSimpleArrayInterfaceMsgBusSpec, "TbSimple.SimpleArrayInterface.MsgBus", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleSimpleArrayInterfaceMsgBusFixture> ImplFixture;

// signal callbacks for testing
void PropBoolPropertyCb(const TArray<bool>& PropBool);
void PropIntPropertyCb(const TArray<int32>& PropInt);
void PropInt32PropertyCb(const TArray<int32>& PropInt32);
void PropInt64PropertyCb(const TArray<int64>& PropInt64);
void PropFloatPropertyCb(const TArray<float>& PropFloat);
void PropFloat32PropertyCb(const TArray<float>& PropFloat32);
void PropFloat64PropertyCb(const TArray<double>& PropFloat64);
void PropStringPropertyCb(const TArray<FString>& PropString);
void SigBoolSignalCb(const TArray<bool>& ParamBool);
void SigIntSignalCb(const TArray<int32>& ParamInt);
void SigInt32SignalCb(const TArray<int32>& ParamInt32);
void SigInt64SignalCb(const TArray<int64>& ParamInt64);
void SigFloatSignalCb(const TArray<float>& ParamFloat);
void SigFloat32SignalCb(const TArray<float>& ParamFloa32);
void SigFloat64SignalCb(const TArray<double>& ParamFloat64);
void SigStringSignalCb(const TArray<FString>& ParamString);
void _ConnectionStatusChangedCb(bool bConnected);
FDoneDelegate testDoneDelegate;

friend class UTbSimpleSimpleArrayInterfaceMsgBusHelper;
END_DEFINE_SPEC(UTbSimpleSimpleArrayInterfaceMsgBusSpec);

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
