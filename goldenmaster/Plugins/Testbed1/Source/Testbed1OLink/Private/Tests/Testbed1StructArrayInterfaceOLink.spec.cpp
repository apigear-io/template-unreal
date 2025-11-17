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

#include "OLinkCommon.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
#include "Testbed1StructArrayInterfaceOLinkFixture.h"
#include "Testbed1/Implementation/Testbed1StructArrayInterface.h"
#include "Testbed1/Generated/OLink/Testbed1StructArrayInterfaceOLinkClient.h"
#include "Testbed1/Generated/OLink/Testbed1StructArrayInterfaceOLinkAdapter.h"

#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "Testbed1/Tests/Testbed1TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructArrayInterface
{
namespace OLink
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTestbed1StructArrayInterfaceOLinkSpec, "Testbed1.StructArrayInterface.OLink", Testbed1TestFilterMask);

TUniquePtr<FTestbed1StructArrayInterfaceOLinkFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed1StructArrayInterfaceOLinkSpec);

void UTestbed1StructArrayInterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTestbed1StructArrayInterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		UTestbed1StructArrayInterfaceOLinkClient* OLinkClient = Cast<UTestbed1StructArrayInterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddLambda([this, TestDone](bool bSubscribed)
			{
			if (bSubscribed)
			{
				TestDone.Execute();
			}
		});

		ImplFixture->Connection = OLinkFactory::Create(GetTransientPackage(), "TestingConnection");
		ImplFixture->Connection.GetObject()->AddToRoot();
		ImplFixture->Connection->Configure("ws://127.0.0.1:8666/ws", false);

		OLinkClient->UseConnection(ImplFixture->Connection);
		ImplFixture->Connection->Connect();
	});

	AfterEach([this]()
		{
		if (ImplFixture->Connection && IsValid(ImplFixture->Connection.GetObject()))
		{
			ImplFixture->Connection->Disconnect();
			ImplFixture->Connection.GetObject()->RemoveFromRoot();
		}
		ImplFixture.Reset();
	});

	It("Property.PropBool.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructBool>& InPropBool)
			{
			TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
			// use different test value
			TestValue = createTestFTestbed1StructBoolArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructBoolArray();
		ImplFixture->GetImplementation()->SetPropBool(TestValue);
	});

	LatentIt("Property.PropBool.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructBool>& InPropBool)
			{
			TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
			// use different test value
			TestValue = createTestFTestbed1StructBoolArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = createTestFTestbed1StructBoolArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropBool(TestValue);
	});

	LatentIt("Property.PropBool.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructBool>& InPropBool)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
				// use different test value
				TestValue = createTestFTestbed1StructBoolArray();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

				// now set it to the default value
				TestValue = TArray<FTestbed1StructBool>(); // default value
				ImplFixture->GetImplementation()->SetPropBool(TestValue);
			}
			else
			{
				TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = createTestFTestbed1StructBoolArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropBool(TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructInt>& InPropInt)
			{
			TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
			// use different test value
			TestValue = createTestFTestbed1StructIntArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructIntArray();
		ImplFixture->GetImplementation()->SetPropInt(TestValue);
	});

	LatentIt("Property.PropInt.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructInt>& InPropInt)
			{
			TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
			// use different test value
			TestValue = createTestFTestbed1StructIntArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = createTestFTestbed1StructIntArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropInt(TestValue);
	});

	LatentIt("Property.PropInt.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructInt>& InPropInt)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
				// use different test value
				TestValue = createTestFTestbed1StructIntArray();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

				// now set it to the default value
				TestValue = TArray<FTestbed1StructInt>(); // default value
				ImplFixture->GetImplementation()->SetPropInt(TestValue);
			}
			else
			{
				TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = createTestFTestbed1StructIntArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropInt(TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructFloat>& InPropFloat)
			{
			TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
			// use different test value
			TestValue = createTestFTestbed1StructFloatArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructFloatArray();
		ImplFixture->GetImplementation()->SetPropFloat(TestValue);
	});

	LatentIt("Property.PropFloat.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructFloat>& InPropFloat)
			{
			TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
			// use different test value
			TestValue = createTestFTestbed1StructFloatArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = createTestFTestbed1StructFloatArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropFloat(TestValue);
	});

	LatentIt("Property.PropFloat.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructFloat>& InPropFloat)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
				// use different test value
				TestValue = createTestFTestbed1StructFloatArray();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

				// now set it to the default value
				TestValue = TArray<FTestbed1StructFloat>(); // default value
				ImplFixture->GetImplementation()->SetPropFloat(TestValue);
			}
			else
			{
				TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = createTestFTestbed1StructFloatArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropFloat(TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructString>& InPropString)
			{
			TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
			// use different test value
			TestValue = createTestFTestbed1StructStringArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructStringArray();
		ImplFixture->GetImplementation()->SetPropString(TestValue);
	});

	LatentIt("Property.PropString.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructString>& InPropString)
			{
			TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
			// use different test value
			TestValue = createTestFTestbed1StructStringArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = createTestFTestbed1StructStringArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropString(TestValue);
	});

	LatentIt("Property.PropString.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructString>& InPropString)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
				// use different test value
				TestValue = createTestFTestbed1StructStringArray();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

				// now set it to the default value
				TestValue = TArray<FTestbed1StructString>(); // default value
				ImplFixture->GetImplementation()->SetPropString(TestValue);
			}
			else
			{
				TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = createTestFTestbed1StructStringArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropString(TestValue);
	});

	It("Property.PropEnum.Default", [this]()
		{
		// Do implement test here
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
	});

	LatentIt("Property.PropEnum.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropEnumChanged.AddLambda([this, TestDone](const TArray<ETestbed1Enum0>& InPropEnum)
			{
			TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
			// use different test value
			TestValue.Add(ETestbed1Enum0::T1E0_Value1);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(ETestbed1Enum0::T1E0_Value1);
		ImplFixture->GetImplementation()->SetPropEnum(TestValue);
	});

	LatentIt("Property.PropEnum.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropEnumChanged.AddLambda([this, TestDone](const TArray<ETestbed1Enum0>& InPropEnum)
			{
			TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
			// use different test value
			TestValue.Add(ETestbed1Enum0::T1E0_Value1);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue.Add(ETestbed1Enum0::T1E0_Value1);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropEnum(TestValue);
	});

	LatentIt("Property.PropEnum.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropEnumChanged.AddLambda([this, TestDone](const TArray<ETestbed1Enum0>& InPropEnum)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
				// use different test value
				TestValue.Add(ETestbed1Enum0::T1E0_Value1);
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);

				// now set it to the default value
				TestValue = TArray<ETestbed1Enum0>(); // default value
				ImplFixture->GetImplementation()->SetPropEnum(TestValue);
			}
			else
			{
				TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue.Add(ETestbed1Enum0::T1E0_Value1);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
		service->SetPropEnum(TestValue);
	});

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncBool(TArray<FTestbed1StructBool>());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncBoolAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		// Test async operation through OLink (client -> network -> server -> network -> client callback)
		TFuture<TArray<FTestbed1StructBool>> Future = ImplFixture->GetImplementation()->FuncBoolAsync(TArray<FTestbed1StructBool>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<FTestbed1StructBool>& Result)
			{
			// Verify values here based on service logic
			Done.Execute();
		});
	});

	LatentIt("Operation.FuncInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncInt(TArray<FTestbed1StructInt>());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncIntAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		// Test async operation through OLink (client -> network -> server -> network -> client callback)
		TFuture<TArray<FTestbed1StructInt>> Future = ImplFixture->GetImplementation()->FuncIntAsync(TArray<FTestbed1StructInt>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<FTestbed1StructInt>& Result)
			{
			// Verify values here based on service logic
			Done.Execute();
		});
	});

	LatentIt("Operation.FuncFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncFloat(TArray<FTestbed1StructFloat>());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloatAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		// Test async operation through OLink (client -> network -> server -> network -> client callback)
		TFuture<TArray<FTestbed1StructFloat>> Future = ImplFixture->GetImplementation()->FuncFloatAsync(TArray<FTestbed1StructFloat>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<FTestbed1StructFloat>& Result)
			{
			// Verify values here based on service logic
			Done.Execute();
		});
	});

	LatentIt("Operation.FuncString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncString(TArray<FTestbed1StructString>());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncStringAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		// Test async operation through OLink (client -> network -> server -> network -> client callback)
		TFuture<TArray<FTestbed1StructString>> Future = ImplFixture->GetImplementation()->FuncStringAsync(TArray<FTestbed1StructString>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<FTestbed1StructString>& Result)
			{
			// Verify values here based on service logic
			Done.Execute();
		});
	});

	LatentIt("Operation.FuncEnum", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncEnum(TArray<ETestbed1Enum0>());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncEnumAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		// Test async operation through OLink (client -> network -> server -> network -> client callback)
		TFuture<TArray<ETestbed1Enum0>> Future = ImplFixture->GetImplementation()->FuncEnumAsync(TArray<ETestbed1Enum0>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<ETestbed1Enum0>& Result)
			{
			// Verify values here based on service logic
			Done.Execute();
		});
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnSigBoolSignal.AddLambda([this, TestDone](const TArray<FTestbed1StructBool>& InParamBool)
			{
			// known test value
			TArray<FTestbed1StructBool> ParamBoolTestValue = createTestFTestbed1StructBoolArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FTestbed1StructBool> ParamBoolTestValue = createTestFTestbed1StructBoolArray();
		Testbed1StructArrayInterfacePublisher->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnSigIntSignal.AddLambda([this, TestDone](const TArray<FTestbed1StructInt>& InParamInt)
			{
			// known test value
			TArray<FTestbed1StructInt> ParamIntTestValue = createTestFTestbed1StructIntArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FTestbed1StructInt> ParamIntTestValue = createTestFTestbed1StructIntArray();
		Testbed1StructArrayInterfacePublisher->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnSigFloatSignal.AddLambda([this, TestDone](const TArray<FTestbed1StructFloat>& InParamFloat)
			{
			// known test value
			TArray<FTestbed1StructFloat> ParamFloatTestValue = createTestFTestbed1StructFloatArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FTestbed1StructFloat> ParamFloatTestValue = createTestFTestbed1StructFloatArray();
		Testbed1StructArrayInterfacePublisher->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnSigStringSignal.AddLambda([this, TestDone](const TArray<FTestbed1StructString>& InParamString)
			{
			// known test value
			TArray<FTestbed1StructString> ParamStringTestValue = createTestFTestbed1StructStringArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FTestbed1StructString> ParamStringTestValue = createTestFTestbed1StructStringArray();
		Testbed1StructArrayInterfacePublisher->BroadcastSigStringSignal(ParamStringTestValue);
	});

	LatentIt("Signal.SigEnum", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnSigEnumSignal.AddLambda([this, TestDone](const TArray<ETestbed1Enum0>& InParamEnum)
			{
			// known test value
			TArray<ETestbed1Enum0> ParamEnumTestValue = TArray<ETestbed1Enum0>(); // default value
			ParamEnumTestValue.Add(ETestbed1Enum0::T1E0_Value1);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamEnum, ParamEnumTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<ETestbed1Enum0> ParamEnumTestValue = TArray<ETestbed1Enum0>(); // default value
		ParamEnumTestValue.Add(ETestbed1Enum0::T1E0_Value1);
		Testbed1StructArrayInterfacePublisher->BroadcastSigEnumSignal(ParamEnumTestValue);
	});
}
} // namespace Tests
} // namespace OLink
} // namespace StructArrayInterface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
