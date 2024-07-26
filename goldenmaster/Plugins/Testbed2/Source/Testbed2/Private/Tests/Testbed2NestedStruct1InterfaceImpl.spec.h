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

#include "Implementation/Testbed2NestedStruct1Interface.h"
#include "Testbed2NestedStruct1InterfaceImplFixture.h"

#if WITH_DEV_AUTOMATION_TESTS 

BEGIN_DEFINE_SPEC(UTestbed2NestedStruct1InterfaceImplSpec, "Testbed2.NestedStruct1Interface.Impl",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

	TUniquePtr<FTestbed2NestedStruct1InterfaceImplFixture> ImplFixture;

	// signal callbacks for testing
	void Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1);
	void Sig1SignalCb(const FTestbed2NestedStruct1& Param1);
	FDoneDelegate testDoneDelegate;

	friend class UTestbed2NestedStruct1InterfaceImplHelper;
END_DEFINE_SPEC(UTestbed2NestedStruct1InterfaceImplSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
