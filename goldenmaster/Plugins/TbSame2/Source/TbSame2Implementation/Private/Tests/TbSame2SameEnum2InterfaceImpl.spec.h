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

#include "TbSame2SameEnum2InterfaceImplFixture.h"
#include "TbSame2/Tests/TbSame2TestsCommon.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbSame2SameEnum2InterfaceImplSpec, "TbSame2.SameEnum2Interface.Impl", TbSame2TestFilterMask);

TUniquePtr<FTbSame2SameEnum2InterfaceImplFixture> ImplFixture;

// signal callbacks for testing
void Prop1PropertyCb(ETbSame2Enum1 Prop1);
void Prop2PropertyCb(ETbSame2Enum2 Prop2);
void Sig1SignalCb(ETbSame2Enum1 Param1);
void Sig2SignalCb(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2);
FDoneDelegate testDoneDelegate;

friend class UTbSame2SameEnum2InterfaceImplHelper;
END_DEFINE_SPEC(UTbSame2SameEnum2InterfaceImplSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
