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

#include "TbSame2SameStruct2InterfaceImpl.spec.h"
#include "Implementation/TbSame2SameStruct2Interface.h"
#include "TbSame2SameStruct2InterfaceImplFixture.h"
#include "TbSame2TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSame2SameStruct2InterfaceImplSpec::Define()
{
	BeforeEach([this]()
	{
		ImplFixture = MakeUnique<FTbSame2SameStruct2InterfaceImplFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		ImplFixture->GetHelper()->SetSpec(this);
	});

	AfterEach([this]()
	{
		ImplFixture.Reset();
	});

	It("Property.Prop1", [this]()
	{
		// Do implement test here
		FTbSame2Struct2 TestValue = FTbSame2Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);

		// use different test value
		TestValue = createTestFTbSame2Struct2();
		ImplFixture->GetImplementation()->Execute_SetProp1(ImplFixture->GetImplementation().GetObject(), TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	It("Property.Prop2", [this]()
	{
		// Do implement test here
		FTbSame2Struct2 TestValue = FTbSame2Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);

		// use different test value
		TestValue = createTestFTbSame2Struct2();
		ImplFixture->GetImplementation()->Execute_SetProp2(ImplFixture->GetImplementation().GetObject(), TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	It("Operation.Func1", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_Func1(ImplFixture->GetImplementation().GetObject(), FTbSame2Struct1());
	});

	It("Operation.Func2", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_Func2(ImplFixture->GetImplementation().GetObject(), FTbSame2Struct1(), FTbSame2Struct2());
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
	{
		testDoneDelegate = TestDone;
		UTbSame2SameStruct2InterfaceSignals* TbSame2SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSame2SameStruct2InterfaceSignals->OnSig1Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameStruct2InterfaceImplHelper::Sig1SignalCb);

		// use different test value
		FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
		TbSame2SameStruct2InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
	{
		testDoneDelegate = TestDone;
		UTbSame2SameStruct2InterfaceSignals* TbSame2SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSame2SameStruct2InterfaceSignals->OnSig2Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameStruct2InterfaceImplHelper::Sig2SignalCb);

		// use different test value
		FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
		FTbSame2Struct2 Param2TestValue = createTestFTbSame2Struct2();
		TbSame2SameStruct2InterfaceSignals->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});
}

void UTbSame2SameStruct2InterfaceImplSpec::Sig1SignalCb(const FTbSame2Struct1& InParam1)
{
	// known test value
	FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceImplSpec::Sig2SignalCb(const FTbSame2Struct1& InParam1, const FTbSame2Struct2& InParam2)
{
	// known test value
	FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	FTbSame2Struct2 Param2TestValue = createTestFTbSame2Struct2();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
