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

#include "Testbed2ManyParamInterfaceImplFixture.h"
#include "Testbed2/Tests/Testbed2TestsCommon.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTestbed2ManyParamInterfaceImplSpec, "Testbed2.ManyParamInterface.Impl", Testbed2TestFilterMask);

TUniquePtr<FTestbed2ManyParamInterfaceImplFixture> ImplFixture;

// signal callbacks for testing
void Prop1PropertyCb(int32 Prop1);
void Prop2PropertyCb(int32 Prop2);
void Prop3PropertyCb(int32 Prop3);
void Prop4PropertyCb(int32 Prop4);
void Sig1SignalCb(int32 Param1);
void Sig2SignalCb(int32 Param1, int32 Param2);
void Sig3SignalCb(int32 Param1, int32 Param2, int32 Param3);
void Sig4SignalCb(int32 Param1, int32 Param2, int32 Param3, int32 Param4);
FDoneDelegate testDoneDelegate;

friend class UTestbed2ManyParamInterfaceImplHelper;
END_DEFINE_SPEC(UTestbed2ManyParamInterfaceImplSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
