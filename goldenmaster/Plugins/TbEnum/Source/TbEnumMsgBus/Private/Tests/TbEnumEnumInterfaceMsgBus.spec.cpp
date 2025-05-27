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

#include "TbEnum/Tests/TbEnumTestsCommon.h"
#include "TbEnum/Implementation/TbEnumEnumInterface.h"
#include "TbEnumEnumInterfaceMsgBusFixture.h"
#include "TbEnum/Generated/MsgBus/TbEnumEnumInterfaceMsgBusClient.h"
#include "TbEnum/Generated/MsgBus/TbEnumEnumInterfaceMsgBusAdapter.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbEnum
{
namespace EnumInterface
{
namespace MsgBus
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbEnumEnumInterfaceMsgBusSpec, "TbEnum.EnumInterface.MsgBus", TbEnumTestFilterMask);

TUniquePtr<FTbEnumEnumInterfaceMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTbEnumEnumInterfaceMsgBusSpec);

void UTbEnumEnumInterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbEnumEnumInterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTbEnumEnumInterfaceMsgBusClient* MsgBusClient = Cast<UTbEnumEnumInterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
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

	It("Property.Prop0.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp0(), TestValue);
	});

	LatentIt("Property.Prop0.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp0(), TestValue);

		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp0Changed.AddLambda([this, TestDone](ETbEnumEnum0 InProp0)
			{
			ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0;
			// use different test value
			TestValue = ETbEnumEnum0::TEE0_Value1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp0, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp0(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbEnumEnum0::TEE0_Value1;
		ImplFixture->GetImplementation()->SetProp0(TestValue);
	});

	LatentIt("Property.Prop0.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp0(), TestValue);

		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp0Changed.AddLambda([this, TestDone](ETbEnumEnum0 InProp0)
			{
			ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0;
			// use different test value
			TestValue = ETbEnumEnum0::TEE0_Value1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp0, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp0(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = ETbEnumEnum0::TEE0_Value1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		service->SetProp0(TestValue);
	});

	LatentIt("Property.Prop0.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp0(), TestValue);

		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp0Changed.AddLambda([this, TestDone](ETbEnumEnum0 InProp0)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0;
				// use different test value
				TestValue = ETbEnumEnum0::TEE0_Value1;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp0, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp0(), TestValue);

				// now set it to the default value
				TestValue = ETbEnumEnum0::TEE0_Value0; // default value
				ImplFixture->GetImplementation()->SetProp0(TestValue);
			}
			else
			{
				ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp0, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp0(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = ETbEnumEnum0::TEE0_Value1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		service->SetProp0(TestValue);
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](ETbEnumEnum1 InProp1)
			{
			ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1;
			// use different test value
			TestValue = ETbEnumEnum1::TEE1_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbEnumEnum1::TEE1_Value2;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](ETbEnumEnum1 InProp1)
			{
			ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1;
			// use different test value
			TestValue = ETbEnumEnum1::TEE1_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = ETbEnumEnum1::TEE1_Value2;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		service->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](ETbEnumEnum1 InProp1)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1;
				// use different test value
				TestValue = ETbEnumEnum1::TEE1_Value2;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

				// now set it to the default value
				TestValue = ETbEnumEnum1::TEE1_Value1; // default value
				ImplFixture->GetImplementation()->SetProp1(TestValue);
			}
			else
			{
				ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = ETbEnumEnum1::TEE1_Value2;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		service->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp2Changed.AddLambda([this, TestDone](ETbEnumEnum2 InProp2)
			{
			ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2;
			// use different test value
			TestValue = ETbEnumEnum2::TEE2_Value1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbEnumEnum2::TEE2_Value1;
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	LatentIt("Property.Prop2.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp2Changed.AddLambda([this, TestDone](ETbEnumEnum2 InProp2)
			{
			ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2;
			// use different test value
			TestValue = ETbEnumEnum2::TEE2_Value1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = ETbEnumEnum2::TEE2_Value1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		service->SetProp2(TestValue);
	});

	LatentIt("Property.Prop2.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp2Changed.AddLambda([this, TestDone](ETbEnumEnum2 InProp2)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2;
				// use different test value
				TestValue = ETbEnumEnum2::TEE2_Value1;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

				// now set it to the default value
				TestValue = ETbEnumEnum2::TEE2_Value2; // default value
				ImplFixture->GetImplementation()->SetProp2(TestValue);
			}
			else
			{
				ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = ETbEnumEnum2::TEE2_Value1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		service->SetProp2(TestValue);
	});

	It("Property.Prop3.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
	});

	LatentIt("Property.Prop3.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp3Changed.AddLambda([this, TestDone](ETbEnumEnum3 InProp3)
			{
			ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3;
			// use different test value
			TestValue = ETbEnumEnum3::TEE3_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbEnumEnum3::TEE3_Value2;
		ImplFixture->GetImplementation()->SetProp3(TestValue);
	});

	LatentIt("Property.Prop3.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp3Changed.AddLambda([this, TestDone](ETbEnumEnum3 InProp3)
			{
			ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3;
			// use different test value
			TestValue = ETbEnumEnum3::TEE3_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = ETbEnumEnum3::TEE3_Value2;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		service->SetProp3(TestValue);
	});

	LatentIt("Property.Prop3.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp3Changed.AddLambda([this, TestDone](ETbEnumEnum3 InProp3)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3;
				// use different test value
				TestValue = ETbEnumEnum3::TEE3_Value2;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

				// now set it to the default value
				TestValue = ETbEnumEnum3::TEE3_Value3; // default value
				ImplFixture->GetImplementation()->SetProp3(TestValue);
			}
			else
			{
				ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = ETbEnumEnum3::TEE3_Value2;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		service->SetProp3(TestValue);
	});

	LatentIt("Operation.Func0", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func0(ETbEnumEnum0::TEE0_Value0);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(ETbEnumEnum1::TEE1_Value1);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func2(ETbEnumEnum2::TEE2_Value2);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func3(ETbEnumEnum3::TEE3_Value3);
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig0", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnSig0Signal.AddLambda([this, TestDone](ETbEnumEnum0 InParam0)
			{
			// known test value
			ETbEnumEnum0 Param0TestValue = ETbEnumEnum0::TEE0_Value1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam0, Param0TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbEnumEnum0 Param0TestValue = ETbEnumEnum0::TEE0_Value1;
		TbEnumEnumInterfaceSignals->BroadcastSig0Signal(Param0TestValue);
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnSig1Signal.AddLambda([this, TestDone](ETbEnumEnum1 InParam1)
			{
			// known test value
			ETbEnumEnum1 Param1TestValue = ETbEnumEnum1::TEE1_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbEnumEnum1 Param1TestValue = ETbEnumEnum1::TEE1_Value2;
		TbEnumEnumInterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnSig2Signal.AddLambda([this, TestDone](ETbEnumEnum2 InParam2)
			{
			// known test value
			ETbEnumEnum2 Param2TestValue = ETbEnumEnum2::TEE2_Value1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbEnumEnum2 Param2TestValue = ETbEnumEnum2::TEE2_Value1;
		TbEnumEnumInterfaceSignals->BroadcastSig2Signal(Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnSig3Signal.AddLambda([this, TestDone](ETbEnumEnum3 InParam3)
			{
			// known test value
			ETbEnumEnum3 Param3TestValue = ETbEnumEnum3::TEE3_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbEnumEnum3 Param3TestValue = ETbEnumEnum3::TEE3_Value2;
		TbEnumEnumInterfaceSignals->BroadcastSig3Signal(Param3TestValue);
	});
}
} // namespace Tests
} // namespace MsgBus
} // namespace EnumInterface
} // namespace TbEnum

#endif // WITH_DEV_AUTOMATION_TESTS
