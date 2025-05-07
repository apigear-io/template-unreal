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

#include "Generated/MsgBus/Testbed1StructInterfaceMsgBusClient.h"
#include "Testbed1TestsCommon.h"
#include "Testbed1StructInterfaceMsgBusFixture.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTestbed1StructInterfaceMsgBusSpec, "Testbed1.StructInterface.MsgBus", Testbed1TestFilterMask);

TUniquePtr<FTestbed1StructInterfaceMsgBusFixture> ImplFixture;

// signal callbacks for testing
void PropBoolPropertyCb(const FTestbed1StructBool& PropBool);
void PropBoolPropertyChangeLocalCheckRemoteCb(const FTestbed1StructBool& PropBool);
void PropBoolPropertyChangeLocalChangeRemoteCb(const FTestbed1StructBool& PropBool);
void PropIntPropertyCb(const FTestbed1StructInt& PropInt);
void PropIntPropertyChangeLocalCheckRemoteCb(const FTestbed1StructInt& PropInt);
void PropIntPropertyChangeLocalChangeRemoteCb(const FTestbed1StructInt& PropInt);
void PropFloatPropertyCb(const FTestbed1StructFloat& PropFloat);
void PropFloatPropertyChangeLocalCheckRemoteCb(const FTestbed1StructFloat& PropFloat);
void PropFloatPropertyChangeLocalChangeRemoteCb(const FTestbed1StructFloat& PropFloat);
void PropStringPropertyCb(const FTestbed1StructString& PropString);
void PropStringPropertyChangeLocalCheckRemoteCb(const FTestbed1StructString& PropString);
void PropStringPropertyChangeLocalChangeRemoteCb(const FTestbed1StructString& PropString);
void SigBoolSignalCb(const FTestbed1StructBool& ParamBool);
void SigIntSignalCb(const FTestbed1StructInt& ParamInt);
void SigFloatSignalCb(const FTestbed1StructFloat& ParamFloat);
void SigStringSignalCb(const FTestbed1StructString& ParamString);
void _ConnectionStatusChangedCb(bool bConnected);
FDoneDelegate testDoneDelegate;

friend class UTestbed1StructInterfaceMsgBusHelper;
END_DEFINE_SPEC(UTestbed1StructInterfaceMsgBusSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
