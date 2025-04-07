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
#include "TbNamesNamEsOLinkFixture.h"
#include "TbNames/Implementation/TbNamesNamEs.h"
#include "TbNames/Generated/OLink/TbNamesNamEsOLinkClient.h"
#include "TbNames/Generated/OLink/TbNamesNamEsOLinkAdapter.h"

#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "TbNames/Tests/TbNamesTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbNames
{
namespace NamEs
{
namespace OLink
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbNamesNamEsOLinkSpec, "TbNames.NamEs.OLink", TbNamesTestFilterMask);

TUniquePtr<FTbNamesNamEsOLinkFixture> ImplFixture;

END_DEFINE_SPEC(UTbNamesNamEsOLinkSpec);

void UTbNamesNamEsOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbNamesNamEsOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		UTbNamesNamEsOLinkClient* OLinkClient = Cast<UTbNamesNamEsOLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddLambda([this, TestDone](bool bSubscribed)
			{
			if (bSubscribed)
			{
				TestDone.Execute();
			}
		});

		ImplFixture->Connection = OLinkFactory::Create(OLinkClient, "TestingConnection");
		ImplFixture->Connection->Configure("ws://127.0.0.1:8666/ws", false);

		OLinkClient->UseConnection(ImplFixture->Connection);
		ImplFixture->Connection->Connect();
	});

	AfterEach([this]()
		{
		ImplFixture->Connection->Disconnect();
		ImplFixture.Reset();
	});

	It("Property.Switch.Default", [this]()
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSwitch(), TestValue);
	});

	LatentIt("Property.Switch.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSwitch(), TestValue);

		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbNamesNamEsSignals->OnSwitchChanged.AddLambda([this, TestDone](bool bInSwitch)
			{
			bool TestValue = false;
			// use different test value
			TestValue = true;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetSwitch(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = true;
		ImplFixture->GetImplementation()->SetSwitch(TestValue);
	});

	It("Property.SomeProperty.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomeProperty(), TestValue);
	});

	LatentIt("Property.SomeProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomeProperty(), TestValue);

		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbNamesNamEsSignals->OnSomePropertyChanged.AddLambda([this, TestDone](int32 InSomeProperty)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetSomeProperty(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetSomeProperty(TestValue);
	});

	It("Property.SomePoperty2.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomePoperty2(), TestValue);
	});

	LatentIt("Property.SomePoperty2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomePoperty2(), TestValue);

		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbNamesNamEsSignals->OnSomePoperty2Changed.AddLambda([this, TestDone](int32 InSomePoperty2)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetSomePoperty2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetSomePoperty2(TestValue);
	});

	It("Property.EnumProperty.Default", [this]()
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetEnumProperty(), TestValue);
	});

	LatentIt("Property.EnumProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetEnumProperty(), TestValue);

		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbNamesNamEsSignals->OnEnumPropertyChanged.AddLambda([this, TestDone](ETbNamesEnum_With_Under_scores InEnumProperty)
			{
			ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE;
			// use different test value
			TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SECONDVALUE;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetEnumProperty(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SECONDVALUE;
		ImplFixture->GetImplementation()->SetEnumProperty(TestValue);
	});

	LatentIt("Operation.SomeFunction", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->SomeFunction(false);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.SomeFunction2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->SomeFunction2(false);
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SomeSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbNamesNamEsSignals->OnSomeSignalSignal.AddLambda([this, TestDone](bool bInSomeParam)
			{
			// known test value
			bool bSomeParamTestValue = true;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInSomeParam, bSomeParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		bool bSomeParamTestValue = true;
		TbNamesNamEsSignals->BroadcastSomeSignalSignal(bSomeParamTestValue);
	});

	LatentIt("Signal.SomeSignal2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbNamesNamEsSignals->OnSomeSignal2Signal.AddLambda([this, TestDone](bool bInSomeParam)
			{
			// known test value
			bool bSomeParamTestValue = true;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInSomeParam, bSomeParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		bool bSomeParamTestValue = true;
		TbNamesNamEsSignals->BroadcastSomeSignal2Signal(bSomeParamTestValue);
	});
}
} // namespace Tests
} // namespace OLink
} // namespace NamEs
} // namespace TbNames

#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
