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

#include "Implementation/Testbed2NestedStruct2Interface.h"
#include "Testbed2NestedStruct2InterfaceImplFixture.h"
#include "Testbed2TestsCommon.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTestbed2NestedStruct2InterfaceImplSpec, "Testbed2.NestedStruct2Interface.Impl", Testbed2TestFilterMask);

TUniquePtr<FTestbed2NestedStruct2InterfaceImplFixture> ImplFixture;

// signal callbacks for testing
void Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1);
void Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2);
void Sig1SignalCb(const FTestbed2NestedStruct1& Param1);
void Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);
FDoneDelegate testDoneDelegate;

friend class UTestbed2NestedStruct2InterfaceImplHelper;
END_DEFINE_SPEC(UTestbed2NestedStruct2InterfaceImplSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
