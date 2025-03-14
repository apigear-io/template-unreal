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

#include "Counter/Generated/MsgBus/CounterCounterMsgBusClient.h"
#include "Counter/Tests/CounterTestsCommon.h"
#include "CounterCounterMsgBusFixture.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

BEGIN_DEFINE_SPEC(UCounterCounterMsgBusSpec, "Counter.Counter.MsgBus", CounterTestFilterMask);

TUniquePtr<FCounterCounterMsgBusFixture> ImplFixture;

// signal callbacks for testing
void VectorPropertyCb(const FCustomTypesVector3D& Vector);
void VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& VectorArray);
void ValueChangedSignalCb(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray);
void _ConnectionStatusChangedCb(bool bConnected);
FDoneDelegate testDoneDelegate;

friend class UCounterCounterMsgBusHelper;
END_DEFINE_SPEC(UCounterCounterMsgBusSpec);

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
