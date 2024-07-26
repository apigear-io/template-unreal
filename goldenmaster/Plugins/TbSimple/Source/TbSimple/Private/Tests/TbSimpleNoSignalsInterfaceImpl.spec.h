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

#include "Implementation/TbSimpleNoSignalsInterface.h"
#include "TbSimpleNoSignalsInterfaceImplFixture.h"

#if WITH_DEV_AUTOMATION_TESTS 

BEGIN_DEFINE_SPEC(UTbSimpleNoSignalsInterfaceImplSpec, "TbSimple.NoSignalsInterface.Impl",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

	TUniquePtr<FTbSimpleNoSignalsInterfaceImplFixture> ImplFixture;

	// signal callbacks for testing
	void PropBoolPropertyCb(bool bPropBool);
	void PropIntPropertyCb(int32 PropInt);
	FDoneDelegate testDoneDelegate;

	friend class UTbSimpleNoSignalsInterfaceImplHelper;
END_DEFINE_SPEC(UTbSimpleNoSignalsInterfaceImplSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
