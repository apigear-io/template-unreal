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

#include "Generated/MsgBus/TbSame1SameEnum1InterfaceMsgBusClient.h"
#include "TbSame1TestsCommon.h"
#include "TbSame1SameEnum1InterfaceMsgBusFixture.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

BEGIN_DEFINE_SPEC(UTbSame1SameEnum1InterfaceMsgBusSpec, "TbSame1.SameEnum1Interface.MsgBus", TbSame1TestFilterMask);

TUniquePtr<FTbSame1SameEnum1InterfaceMsgBusFixture> ImplFixture;

// signal callbacks for testing
void Prop1PropertyCb(ETbSame1Enum1 Prop1);
void Sig1SignalCb(ETbSame1Enum1 Param1);
void _ConnectionStatusChangedCb(bool bConnected);
FDoneDelegate testDoneDelegate;

friend class UTbSame1SameEnum1InterfaceMsgBusHelper;
END_DEFINE_SPEC(UTbSame1SameEnum1InterfaceMsgBusSpec);

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
