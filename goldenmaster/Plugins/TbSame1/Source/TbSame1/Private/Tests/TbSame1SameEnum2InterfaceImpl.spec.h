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

#include "Implementation/TbSame1SameEnum2Interface.h"
#include "TbSame1SameEnum2InterfaceImplFixture.h"

#if WITH_DEV_AUTOMATION_TESTS 

BEGIN_DEFINE_SPEC(UTbSame1SameEnum2InterfaceImplSpec, "TbSame1.SameEnum2Interface.Impl",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

	TUniquePtr<FTbSame1SameEnum2InterfaceImplFixture> ImplFixture;

	// signal callbacks for testing
	void Sig1SignalCb(ETbSame1Enum1 Param1);
	void Sig2SignalCb(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2);
	FDoneDelegate testDoneDelegate;

	friend class UTbSame1SameEnum2InterfaceImplHelper;
END_DEFINE_SPEC(UTbSame1SameEnum2InterfaceImplSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
