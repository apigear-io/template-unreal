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

#include "TbSame2SameStruct2InterfaceImplFixture.h"
#include "TbSame2/Tests/TbSame2TestsCommon.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbSame2SameStruct2InterfaceImplSpec, "TbSame2.SameStruct2Interface.Impl", TbSame2TestFilterMask);

TUniquePtr<FTbSame2SameStruct2InterfaceImplFixture> ImplFixture;

// signal callbacks for testing
void Prop1PropertyCb(const FTbSame2Struct2& Prop1);
void Prop2PropertyCb(const FTbSame2Struct2& Prop2);
void Sig1SignalCb(const FTbSame2Struct1& Param1);
void Sig2SignalCb(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2);
FDoneDelegate testDoneDelegate;

friend class UTbSame2SameStruct2InterfaceImplHelper;
END_DEFINE_SPEC(UTbSame2SameStruct2InterfaceImplSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
