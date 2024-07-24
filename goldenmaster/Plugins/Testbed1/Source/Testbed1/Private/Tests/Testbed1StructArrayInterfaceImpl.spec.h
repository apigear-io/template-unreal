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

#include "Implementation/Testbed1StructArrayInterface.h"
#include "Testbed1StructArrayInterfaceImplFixture.h"

#if WITH_DEV_AUTOMATION_TESTS 

BEGIN_DEFINE_SPEC(UTestbed1StructArrayInterfaceImplSpec, "Testbed1.StructArrayInterface.Impl",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

	TUniquePtr<FTestbed1StructArrayInterfaceImplFixture> ImplFixture;

	// signal callbacks for testing
	void SigBoolSignalCb(const TArray<FTestbed1StructBool>& ParamBool);
	void SigIntSignalCb(const TArray<FTestbed1StructInt>& ParamInt);
	void SigFloatSignalCb(const TArray<FTestbed1StructFloat>& ParamFloat);
	void SigStringSignalCb(const TArray<FTestbed1StructString>& ParamString);
	FDoneDelegate testDoneDelegate;

	friend class UTestbed1StructArrayInterfaceImplHelper;
END_DEFINE_SPEC(UTestbed1StructArrayInterfaceImplSpec);

#endif // WITH_DEV_AUTOMATION_TESTS
