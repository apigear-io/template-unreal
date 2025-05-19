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

#include "TbSame1/Tests/TbSame1TestsCommon.h"
#include "TbSame1/Implementation/TbSame1SameStruct2Interface.h"
#include "TbSame1SameStruct2InterfaceMsgBusFixture.h"
#include "TbSame1/Generated/MsgBus/TbSame1SameStruct2InterfaceMsgBusClient.h"
#include "TbSame1/Generated/MsgBus/TbSame1SameStruct2InterfaceMsgBusAdapter.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameStruct2Interface
{
namespace MsgBus
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSame1SameStruct2InterfaceMsgBusSpec, "TbSame1.SameStruct2Interface.MsgBus", TbSame1TestFilterMask);

TUniquePtr<FTbSame1SameStruct2InterfaceMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTbSame1SameStruct2InterfaceMsgBusSpec);

void UTbSame1SameStruct2InterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSame1SameStruct2InterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceImplementation>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTbSame1SameStruct2InterfaceMsgBusClient* MsgBusClient = Cast<UTbSame1SameStruct2InterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
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

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame1SameStruct2InterfaceSignals* TbSame1SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameStruct2InterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](const FTbSame1Struct2& InProp1)
			{
			FTbSame1Struct2 TestValue = FTbSame1Struct2();
			// use different test value
			TestValue = createTestFTbSame1Struct2();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbSame1Struct2();
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame1SameStruct2InterfaceSignals* TbSame1SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameStruct2InterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](const FTbSame1Struct2& InProp1)
			{
			FTbSame1Struct2 TestValue = FTbSame1Struct2();
			// use different test value
			TestValue = createTestFTbSame1Struct2();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = createTestFTbSame1Struct2();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceImplementation>();
		service->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame1SameStruct2InterfaceSignals* TbSame1SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameStruct2InterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](const FTbSame1Struct2& InProp1)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				FTbSame1Struct2 TestValue = FTbSame1Struct2();
				// use different test value
				TestValue = createTestFTbSame1Struct2();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

				// now set it to the default value
				TestValue = FTbSame1Struct2(); // default value
				ImplFixture->GetImplementation()->SetProp1(TestValue);
			}
			else
			{
				FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = createTestFTbSame1Struct2();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceImplementation>();
		service->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTbSame1SameStruct2InterfaceSignals* TbSame1SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameStruct2InterfaceSignals->OnProp2Changed.AddLambda([this, TestDone](const FTbSame1Struct2& InProp2)
			{
			FTbSame1Struct2 TestValue = FTbSame1Struct2();
			// use different test value
			TestValue = createTestFTbSame1Struct2();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbSame1Struct2();
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	LatentIt("Property.Prop2.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTbSame1SameStruct2InterfaceSignals* TbSame1SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameStruct2InterfaceSignals->OnProp2Changed.AddLambda([this, TestDone](const FTbSame1Struct2& InProp2)
			{
			FTbSame1Struct2 TestValue = FTbSame1Struct2();
			// use different test value
			TestValue = createTestFTbSame1Struct2();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = createTestFTbSame1Struct2();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceImplementation>();
		service->SetProp2(TestValue);
	});

	LatentIt("Property.Prop2.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTbSame1SameStruct2InterfaceSignals* TbSame1SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameStruct2InterfaceSignals->OnProp2Changed.AddLambda([this, TestDone](const FTbSame1Struct2& InProp2)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				FTbSame1Struct2 TestValue = FTbSame1Struct2();
				// use different test value
				TestValue = createTestFTbSame1Struct2();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

				// now set it to the default value
				TestValue = FTbSame1Struct2(); // default value
				ImplFixture->GetImplementation()->SetProp2(TestValue);
			}
			else
			{
				FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = createTestFTbSame1Struct2();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceImplementation>();
		service->SetProp2(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(FTbSame1Struct1());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func2(FTbSame1Struct1(), FTbSame1Struct2());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame1SameStruct2InterfaceSignals* TbSame1SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameStruct2InterfaceSignals->OnSig1Signal.AddLambda([this, TestDone](const FTbSame1Struct1& InParam1)
			{
			// known test value
			FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
		TbSame1SameStruct2InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame1SameStruct2InterfaceSignals* TbSame1SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameStruct2InterfaceSignals->OnSig2Signal.AddLambda([this, TestDone](const FTbSame1Struct1& InParam1, const FTbSame1Struct2& InParam2)
			{
			// known test value
			FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			FTbSame1Struct2 Param2TestValue = createTestFTbSame1Struct2();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
		FTbSame1Struct2 Param2TestValue = createTestFTbSame1Struct2();
		TbSame1SameStruct2InterfaceSignals->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});
}
} // namespace Tests
} // namespace MsgBus
} // namespace SameStruct2Interface
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS
