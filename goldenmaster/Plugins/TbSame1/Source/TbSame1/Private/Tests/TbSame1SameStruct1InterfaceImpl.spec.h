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

#include "Implementation/TbSame1SameStruct1Interface.h"
#include "TbSame1SameStruct1InterfaceImplFixture.h"

#if WITH_DEV_AUTOMATION_TESTS 

BEGIN_DEFINE_SPEC(UTbSame1SameStruct1InterfaceImplSpec, "TbSame1.SameStruct1Interface.Impl",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

	TUniquePtr<FTbSame1SameStruct1InterfaceImplFixture> ImplFixture;

	// signal callbacks for testing
	void Sig1SignalCb(const FTbSame1Struct1& Param1);
	FDoneDelegate testDoneDelegate;

	friend class UTbSame1SameStruct1InterfaceImplHelper;
END_DEFINE_SPEC(UTbSame1SameStruct1InterfaceImplSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
