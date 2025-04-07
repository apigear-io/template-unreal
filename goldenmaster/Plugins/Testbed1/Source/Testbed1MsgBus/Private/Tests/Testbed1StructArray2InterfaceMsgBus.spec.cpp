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

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed1/Tests/Testbed1TestsCommon.h"
#include "Testbed1/Implementation/Testbed1StructArray2Interface.h"
#include "Testbed1StructArray2InterfaceMsgBusFixture.h"
#include "Testbed1/Generated/MsgBus/Testbed1StructArray2InterfaceMsgBusClient.h"
#include "Testbed1/Generated/MsgBus/Testbed1StructArray2InterfaceMsgBusAdapter.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructArray2Interface
{
namespace MsgBus
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTestbed1StructArray2InterfaceMsgBusSpec, "Testbed1.StructArray2Interface.MsgBus", Testbed1TestFilterMask);

TUniquePtr<FTestbed1StructArray2InterfaceMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed1StructArray2InterfaceMsgBusSpec);

void UTestbed1StructArray2InterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTestbed1StructArray2InterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArray2Interface>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTestbed1StructArray2InterfaceMsgBusClient* MsgBusClient = Cast<UTestbed1StructArray2InterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MsgBus client", MsgBusClient != nullptr);

		MsgBusClient->_ConnectionStatusChanged.AddLambda([this, TestDone](bool bConnected)
			{
			if (bConnected)
			{
				TestDone.Execute();
			}
		});

		MsgBusClient->_Connect();
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

		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnPropBoolChanged.AddLambda([this, TestDone](const FTestbed1StructBoolWithArray& InPropBool)
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

		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnPropIntChanged.AddLambda([this, TestDone](const FTestbed1StructIntWithArray& InPropInt)
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

		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnPropFloatChanged.AddLambda([this, TestDone](const FTestbed1StructFloatWithArray& InPropFloat)
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

		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnPropStringChanged.AddLambda([this, TestDone](const FTestbed1StructStringWithArray& InPropString)
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

		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnPropEnumChanged.AddLambda([this, TestDone](const FTestbed1StructEnumWithArray& InPropEnum)
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

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncBool(FTestbed1StructBoolWithArray());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncInt(FTestbed1StructIntWithArray());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncFloat(FTestbed1StructFloatWithArray());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncString(FTestbed1StructStringWithArray());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncEnum", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncEnum(FTestbed1StructEnumWithArray());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnSigBoolSignal.AddLambda([this, TestDone](const FTestbed1StructBoolWithArray& InParamBool)
			{
			// known test value
			FTestbed1StructBoolWithArray ParamBoolTestValue = createTestFTestbed1StructBoolWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructBoolWithArray ParamBoolTestValue = createTestFTestbed1StructBoolWithArray();
		Testbed1StructArray2InterfaceSignals->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnSigIntSignal.AddLambda([this, TestDone](const FTestbed1StructIntWithArray& InParamInt)
			{
			// known test value
			FTestbed1StructIntWithArray ParamIntTestValue = createTestFTestbed1StructIntWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructIntWithArray ParamIntTestValue = createTestFTestbed1StructIntWithArray();
		Testbed1StructArray2InterfaceSignals->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnSigFloatSignal.AddLambda([this, TestDone](const FTestbed1StructFloatWithArray& InParamFloat)
			{
			// known test value
			FTestbed1StructFloatWithArray ParamFloatTestValue = createTestFTestbed1StructFloatWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructFloatWithArray ParamFloatTestValue = createTestFTestbed1StructFloatWithArray();
		Testbed1StructArray2InterfaceSignals->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnSigStringSignal.AddLambda([this, TestDone](const FTestbed1StructStringWithArray& InParamString)
			{
			// known test value
			FTestbed1StructStringWithArray ParamStringTestValue = createTestFTestbed1StructStringWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructStringWithArray ParamStringTestValue = createTestFTestbed1StructStringWithArray();
		Testbed1StructArray2InterfaceSignals->BroadcastSigStringSignal(ParamStringTestValue);
	});
}
} // namespace Tests
} // namespace MsgBus
} // namespace StructArray2Interface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS
