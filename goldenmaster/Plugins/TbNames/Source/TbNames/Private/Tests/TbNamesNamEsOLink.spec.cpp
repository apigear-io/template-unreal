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
#include "TbNamesTestsCommon.h"
#include "Implementation/TbNamesNamEs.h"
#include "TbNamesNamEsOLinkFixture.h"
#include "Generated/OLink/TbNamesNamEsOLinkClient.h"
#include "Generated/OLink/TbNamesNamEsOLinkAdapter.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbNamesNamEsOLinkSpec, "TbNames.NamEs.OLink", TbNamesTestFilterMask);

TSharedPtr<FTbNamesNamEsOLinkFixture> ImplFixture;

END_DEFINE_SPEC(UTbNamesNamEsOLinkSpec);

void UTbNamesNamEsOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeShared<FTbNamesNamEsOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		ImplFixture->GetHelper()->SetParentFixture(ImplFixture);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		UTbNamesNamEsOLinkClient* OLinkClient = Cast<UTbNamesNamEsOLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsOLinkHelper::_SubscriptionStatusChangedCb);

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

	It("Property.Switch.Default", [this]()
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSwitch(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Switch.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSwitch(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSwitchChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsOLinkHelper::SwitchPropertyCb);
		// use different test value
		TestValue = true;
		ImplFixture->GetImplementation()->Execute_SetSwitch(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.Switch.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSwitch(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSwitchChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsOLinkHelper::SwitchPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = true;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		service->Execute_SetSwitch(service, TestValue);
	});

	LatentIt("Property.Switch.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSwitch(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSwitchChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsOLinkHelper::SwitchPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = true;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		service->Execute_SetSwitch(service, TestValue);
	});

	It("Property.SomeProperty.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomeProperty(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.SomeProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomeProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomePropertyChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsOLinkHelper::SomePropertyPropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->Execute_SetSomeProperty(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.SomeProperty.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomeProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomePropertyChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsOLinkHelper::SomePropertyPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		service->Execute_SetSomeProperty(service, TestValue);
	});

	LatentIt("Property.SomeProperty.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomeProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomePropertyChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsOLinkHelper::SomePropertyPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		service->Execute_SetSomeProperty(service, TestValue);
	});

	It("Property.SomePoperty2.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomePoperty2(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.SomePoperty2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomePoperty2(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomePoperty2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsOLinkHelper::SomePoperty2PropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->Execute_SetSomePoperty2(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.SomePoperty2.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomePoperty2(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomePoperty2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsOLinkHelper::SomePoperty2PropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		service->Execute_SetSomePoperty2(service, TestValue);
	});

	LatentIt("Property.SomePoperty2.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomePoperty2(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomePoperty2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsOLinkHelper::SomePoperty2PropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		service->Execute_SetSomePoperty2(service, TestValue);
	});

	It("Property.EnumProperty.Default", [this]()
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetEnumProperty(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.EnumProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetEnumProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnEnumPropertyChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsOLinkHelper::EnumPropertyPropertyCb);
		// use different test value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SECONDVALUE;
		ImplFixture->GetImplementation()->Execute_SetEnumProperty(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.EnumProperty.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetEnumProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnEnumPropertyChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsOLinkHelper::EnumPropertyPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SECONDVALUE;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		service->Execute_SetEnumProperty(service, TestValue);
	});

	LatentIt("Property.EnumProperty.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetEnumProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnEnumPropertyChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsOLinkHelper::EnumPropertyPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SECONDVALUE;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		service->Execute_SetEnumProperty(service, TestValue);
	});

	LatentIt("Operation.SomeFunction", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_SomeFunction(ImplFixture->GetImplementation().GetObject(), false);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.SomeFunction2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_SomeFunction2(ImplFixture->GetImplementation().GetObject(), false);
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SomeSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomeSignalSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsOLinkHelper::SomeSignalSignalCb);

		// use different test value
		bool bSomeParamTestValue = true;
		TbNamesNamEsSignals->BroadcastSomeSignalSignal(bSomeParamTestValue);
	});

	LatentIt("Signal.SomeSignal2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomeSignal2Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsOLinkHelper::SomeSignal2SignalCb);

		// use different test value
		bool bSomeParamTestValue = true;
		TbNamesNamEsSignals->BroadcastSomeSignal2Signal(bSomeParamTestValue);
	});
}
#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
