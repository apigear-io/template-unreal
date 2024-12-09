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

#include "Generated/MsgBus/Testbed2ManyParamInterfaceMsgBusClient.h"
#include "Testbed2TestsCommon.h"
#include "Testbed2ManyParamInterfaceMsgBusFixture.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

BEGIN_DEFINE_SPEC(UTestbed2ManyParamInterfaceMsgBusSpec, "Testbed2.ManyParamInterface.MsgBus", Testbed2TestFilterMask);

TUniquePtr<FTestbed2ManyParamInterfaceMsgBusFixture> ImplFixture;

// signal callbacks for testing
void Prop1PropertyCb(int32 Prop1);
void Prop2PropertyCb(int32 Prop2);
void Prop3PropertyCb(int32 Prop3);
void Prop4PropertyCb(int32 Prop4);
void Sig1SignalCb(int32 Param1);
void Sig2SignalCb(int32 Param1, int32 Param2);
void Sig3SignalCb(int32 Param1, int32 Param2, int32 Param3);
void Sig4SignalCb(int32 Param1, int32 Param2, int32 Param3, int32 Param4);
void _ConnectionStatusChangedCb(bool bConnected);
FDoneDelegate testDoneDelegate;

friend class UTestbed2ManyParamInterfaceMsgBusHelper;
END_DEFINE_SPEC(UTestbed2ManyParamInterfaceMsgBusSpec);

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
