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

#include "Testbed1/Implementation/Testbed1StructArray2Interface.h"
#include "Testbed1StructArray2InterfaceImplFixture.h"
#include "Testbed1/Tests/Testbed1TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTestbed1StructArray2InterfaceImplSpec, "Testbed1.StructArray2Interface.Impl", Testbed1TestFilterMask);

TSharedPtr<FTestbed1StructArray2InterfaceImplFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed1StructArray2InterfaceImplSpec);

void UTestbed1StructArray2InterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTestbed1StructArray2InterfaceImplFixture>();
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

	It("Property.PropBool.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](const FTestbed1StructBoolWithArray& InPropBool)
			{
			FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructBoolWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructBoolWithArray();
		ImplFixture->GetImplementation()->SetPropBool(TestValue);
	});

	LatentIt("Property.PropBool.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropBoolChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::PropBoolPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructBoolWithArray();
		ImplFixture->GetImplementation()->SetPropBool(TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](const FTestbed1StructIntWithArray& InPropInt)
			{
			FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructIntWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructIntWithArray();
		ImplFixture->GetImplementation()->SetPropInt(TestValue);
	});

	LatentIt("Property.PropInt.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropIntChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::PropIntPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructIntWithArray();
		ImplFixture->GetImplementation()->SetPropInt(TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone](const FTestbed1StructFloatWithArray& InPropFloat)
			{
			FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructFloatWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructFloatWithArray();
		ImplFixture->GetImplementation()->SetPropFloat(TestValue);
	});

	LatentIt("Property.PropFloat.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropFloatChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::PropFloatPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructFloatWithArray();
		ImplFixture->GetImplementation()->SetPropFloat(TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone](const FTestbed1StructStringWithArray& InPropString)
			{
			FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructStringWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructStringWithArray();
		ImplFixture->GetImplementation()->SetPropString(TestValue);
	});

	LatentIt("Property.PropString.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropStringChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::PropStringPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructStringWithArray();
		ImplFixture->GetImplementation()->SetPropString(TestValue);
	});

	It("Property.PropEnum.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
	});

	LatentIt("Property.PropEnum.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);

		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropEnumChanged.AddLambda([this, TestDone](const FTestbed1StructEnumWithArray& InPropEnum)
			{
			FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructEnumWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructEnumWithArray();
		ImplFixture->GetImplementation()->SetPropEnum(TestValue);
	});

	LatentIt("Property.PropEnum.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropEnumChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::PropEnumPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructEnumWithArray();
		ImplFixture->GetImplementation()->SetPropEnum(TestValue);
	});

	It("Operation.FuncBool", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncBool(FTestbed1StructBoolWithArray());
	});

	LatentIt("Operation.FuncBoolAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<TArray<FTestbed1StructBool>> Future = ImplFixture->GetImplementation()->FuncBoolAsync(FTestbed1StructBoolWithArray());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<FTestbed1StructBool>& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	It("Operation.FuncInt", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncInt(FTestbed1StructIntWithArray());
	});

	LatentIt("Operation.FuncIntAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<TArray<FTestbed1StructInt>> Future = ImplFixture->GetImplementation()->FuncIntAsync(FTestbed1StructIntWithArray());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<FTestbed1StructInt>& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	It("Operation.FuncFloat", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncFloat(FTestbed1StructFloatWithArray());
	});

	LatentIt("Operation.FuncFloatAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<TArray<FTestbed1StructFloat>> Future = ImplFixture->GetImplementation()->FuncFloatAsync(FTestbed1StructFloatWithArray());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<FTestbed1StructFloat>& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	It("Operation.FuncString", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncString(FTestbed1StructStringWithArray());
	});

	LatentIt("Operation.FuncStringAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<TArray<FTestbed1StructString>> Future = ImplFixture->GetImplementation()->FuncStringAsync(FTestbed1StructStringWithArray());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<FTestbed1StructString>& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	It("Operation.FuncEnum", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncEnum(FTestbed1StructEnumWithArray());
	});

	LatentIt("Operation.FuncEnumAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<TArray<ETestbed1Enum0>> Future = ImplFixture->GetImplementation()->FuncEnumAsync(FTestbed1StructEnumWithArray());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<ETestbed1Enum0>& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnSigBoolSignal.AddLambda([this, TestDone](const FTestbed1StructBoolWithArray& InParamBool)
			{
			// known test value
			FTestbed1StructBoolWithArray ParamBoolTestValue = createTestFTestbed1StructBoolWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructBoolWithArray ParamBoolTestValue = createTestFTestbed1StructBoolWithArray();
		Testbed1StructArray2InterfacePublisher->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigBoolBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnSigBoolSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::SigBoolSignalCb);

		// use different test value
		FTestbed1StructBoolWithArray ParamBoolTestValue = createTestFTestbed1StructBoolWithArray();
		Testbed1StructArray2InterfacePublisher->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnSigIntSignal.AddLambda([this, TestDone](const FTestbed1StructIntWithArray& InParamInt)
			{
			// known test value
			FTestbed1StructIntWithArray ParamIntTestValue = createTestFTestbed1StructIntWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructIntWithArray ParamIntTestValue = createTestFTestbed1StructIntWithArray();
		Testbed1StructArray2InterfacePublisher->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigIntBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnSigIntSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::SigIntSignalCb);

		// use different test value
		FTestbed1StructIntWithArray ParamIntTestValue = createTestFTestbed1StructIntWithArray();
		Testbed1StructArray2InterfacePublisher->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnSigFloatSignal.AddLambda([this, TestDone](const FTestbed1StructFloatWithArray& InParamFloat)
			{
			// known test value
			FTestbed1StructFloatWithArray ParamFloatTestValue = createTestFTestbed1StructFloatWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructFloatWithArray ParamFloatTestValue = createTestFTestbed1StructFloatWithArray();
		Testbed1StructArray2InterfacePublisher->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigFloatBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnSigFloatSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::SigFloatSignalCb);

		// use different test value
		FTestbed1StructFloatWithArray ParamFloatTestValue = createTestFTestbed1StructFloatWithArray();
		Testbed1StructArray2InterfacePublisher->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnSigStringSignal.AddLambda([this, TestDone](const FTestbed1StructStringWithArray& InParamString)
			{
			// known test value
			FTestbed1StructStringWithArray ParamStringTestValue = createTestFTestbed1StructStringWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructStringWithArray ParamStringTestValue = createTestFTestbed1StructStringWithArray();
		Testbed1StructArray2InterfacePublisher->BroadcastSigStringSignal(ParamStringTestValue);
	});

	LatentIt("Signal.SigStringBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnSigStringSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::SigStringSignalCb);

		// use different test value
		FTestbed1StructStringWithArray ParamStringTestValue = createTestFTestbed1StructStringWithArray();
		Testbed1StructArray2InterfacePublisher->BroadcastSigStringSignal(ParamStringTestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
