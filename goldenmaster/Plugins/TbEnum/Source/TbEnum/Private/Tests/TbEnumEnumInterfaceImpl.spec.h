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

#include "Implementation/TbEnumEnumInterface.h"
#include "TbEnumEnumInterfaceImplFixture.h"

#if WITH_DEV_AUTOMATION_TESTS 

BEGIN_DEFINE_SPEC(UTbEnumEnumInterfaceImplSpec, "TbEnum.EnumInterface.Impl",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

	TUniquePtr<FTbEnumEnumInterfaceImplFixture> ImplFixture;

	// signal callbacks for testing
	void Sig0SignalCb(ETbEnumEnum0 Param0);
	void Sig1SignalCb(ETbEnumEnum1 Param1);
	void Sig2SignalCb(ETbEnumEnum2 Param2);
	void Sig3SignalCb(ETbEnumEnum3 Param3);
	FDoneDelegate testDoneDelegate;

	friend class UTbEnumEnumInterfaceImplHelper;
END_DEFINE_SPEC(UTbEnumEnumInterfaceImplSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
