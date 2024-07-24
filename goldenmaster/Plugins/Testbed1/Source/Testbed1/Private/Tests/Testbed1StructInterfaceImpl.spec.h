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

#include "Implementation/Testbed1StructInterface.h"
#include "Testbed1StructInterfaceImplFixture.h"

#if WITH_DEV_AUTOMATION_TESTS 

BEGIN_DEFINE_SPEC(UTestbed1StructInterfaceImplSpec, "Testbed1.StructInterface.Impl",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

	TUniquePtr<FTestbed1StructInterfaceImplFixture> ImplFixture;

	// signal callbacks for testing
	void SigBoolSignalCb(const FTestbed1StructBool& ParamBool);
	void SigIntSignalCb(const FTestbed1StructInt& ParamInt);
	void SigFloatSignalCb(const FTestbed1StructFloat& ParamFloat);
	void SigStringSignalCb(const FTestbed1StructString& ParamString);
	FDoneDelegate testDoneDelegate;

	friend class UTestbed1StructInterfaceImplHelper;
END_DEFINE_SPEC(UTestbed1StructInterfaceImplSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
