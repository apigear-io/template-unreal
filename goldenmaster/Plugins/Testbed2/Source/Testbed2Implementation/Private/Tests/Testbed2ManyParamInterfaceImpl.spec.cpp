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

#include "Testbed2/Implementation/Testbed2ManyParamInterface.h"
#include "Testbed2ManyParamInterfaceImplFixture.h"
#include "Testbed2/Tests/Testbed2TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTestbed2ManyParamInterfaceImplSpec, "Testbed2.ManyParamInterface.Impl", Testbed2TestFilterMask);

TSharedPtr<FTestbed2ManyParamInterfaceImplFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed2ManyParamInterfaceImplSpec);

void UTestbed2ManyParamInterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTestbed2ManyParamInterfaceImplFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		ImplFixture->GetHelper()->SetSpec(this);
		ImplFixture->GetHelper()->SetParentFixture(ImplFixture);
	});

	AfterEach([this]()
		{
		ImplFixture.Reset();
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](int32 InProp1)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp1ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2ManyParamInterfaceImplHelper::Prop1PropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](int32 InProp2)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	LatentIt("Property.Prop2.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp2ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2ManyParamInterfaceImplHelper::Prop2PropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	It("Property.Prop3.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
	});

	LatentIt("Property.Prop3.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp3Changed.AddLambda([this, TestDone](int32 InProp3)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetProp3(TestValue);
	});

	LatentIt("Property.Prop3.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp3ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2ManyParamInterfaceImplHelper::Prop3PropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetProp3(TestValue);
	});

	It("Property.Prop4.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp4(), TestValue);
	});

	LatentIt("Property.Prop4.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp4(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp4Changed.AddLambda([this, TestDone](int32 InProp4)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp4(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetProp4(TestValue);
	});

	LatentIt("Property.Prop4.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp4(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp4ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2ManyParamInterfaceImplHelper::Prop4PropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetProp4(TestValue);
	});

	It("Operation.Func1", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func1(0);
	});

	It("Operation.Func2", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func2(0, 0);
	});

	It("Operation.Func3", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func3(0, 0, 0);
	});

	It("Operation.Func4", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func4(0, 0, 0, 0);
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnSig1Signal.AddLambda([this, TestDone](int32 InParam1)
			{
			// known test value
			int32 Param1TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 Param1TestValue = 1;
		Testbed2ManyParamInterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig1BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnSig1SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2ManyParamInterfaceImplHelper::Sig1SignalCb);

		// use different test value
		int32 Param1TestValue = 1;
		Testbed2ManyParamInterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnSig2Signal.AddLambda([this, TestDone](int32 InParam1, int32 InParam2)
			{
			// known test value
			int32 Param1TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			int32 Param2TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		Testbed2ManyParamInterfacePublisher->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});

	LatentIt("Signal.Sig2BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnSig2SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2ManyParamInterfaceImplHelper::Sig2SignalCb);

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		Testbed2ManyParamInterfacePublisher->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnSig3Signal.AddLambda([this, TestDone](int32 InParam1, int32 InParam2, int32 InParam3)
			{
			// known test value
			int32 Param1TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			int32 Param2TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			int32 Param3TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		int32 Param3TestValue = 1;
		Testbed2ManyParamInterfacePublisher->BroadcastSig3Signal(Param1TestValue, Param2TestValue, Param3TestValue);
	});

	LatentIt("Signal.Sig3BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnSig3SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2ManyParamInterfaceImplHelper::Sig3SignalCb);

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		int32 Param3TestValue = 1;
		Testbed2ManyParamInterfacePublisher->BroadcastSig3Signal(Param1TestValue, Param2TestValue, Param3TestValue);
	});

	LatentIt("Signal.Sig4", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnSig4Signal.AddLambda([this, TestDone](int32 InParam1, int32 InParam2, int32 InParam3, int32 InParam4)
			{
			// known test value
			int32 Param1TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			int32 Param2TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			int32 Param3TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
			int32 Param4TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam4, Param4TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		int32 Param3TestValue = 1;
		int32 Param4TestValue = 1;
		Testbed2ManyParamInterfacePublisher->BroadcastSig4Signal(Param1TestValue, Param2TestValue, Param3TestValue, Param4TestValue);
	});

	LatentIt("Signal.Sig4BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnSig4SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2ManyParamInterfaceImplHelper::Sig4SignalCb);

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		int32 Param3TestValue = 1;
		int32 Param4TestValue = 1;
		Testbed2ManyParamInterfacePublisher->BroadcastSig4Signal(Param1TestValue, Param2TestValue, Param3TestValue, Param4TestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
