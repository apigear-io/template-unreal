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

#include "TbSimpleNoOperationsInterfaceOLink.spec.h"
#include "OLinkCommon.h"
#include "Implementation/TbSimpleNoOperationsInterface.h"
#include "TbSimpleNoOperationsInterfaceOLinkFixture.h"
#include "Generated/OLink/TbSimpleNoOperationsInterfaceOLinkClient.h"
#include "Generated/OLink/TbSimpleNoOperationsInterfaceOLinkAdapter.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleNoOperationsInterfaceOLinkSpec::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	// ImplFixture->testDoneDelegate.Execute();
	// InTestDoneDelegate.Execute();
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

void UTbSimpleNoOperationsInterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSimpleNoOperationsInterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterface>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		testDoneDelegate = TestDone;
		UTbSimpleNoOperationsInterfaceOLinkClient* OLinkClient = Cast<UTbSimpleNoOperationsInterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceOLinkHelper::_SubscriptionStatusChangedCb);

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

	It("Property.PropBool.Default", [this]()
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoOperationsInterfaceSignals->OnPropBoolChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceOLinkHelper::PropBoolPropertyCb);
		// use different test value
		TestValue = true;
		ImplFixture->GetImplementation()->Execute_SetPropBool(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.PropBool.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoOperationsInterfaceSignals->OnPropBoolChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceOLinkHelper::PropBoolPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = true;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterface>();
		service->Execute_SetPropBool(service, TestValue);
	});

	LatentIt("Property.PropBool.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoOperationsInterfaceSignals->OnPropBoolChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceOLinkHelper::PropBoolPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = true;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterface>();
		service->Execute_SetPropBool(service, TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoOperationsInterfaceSignals->OnPropIntChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceOLinkHelper::PropIntPropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->Execute_SetPropInt(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.PropInt.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoOperationsInterfaceSignals->OnPropIntChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceOLinkHelper::PropIntPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterface>();
		service->Execute_SetPropInt(service, TestValue);
	});

	LatentIt("Property.PropInt.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoOperationsInterfaceSignals->OnPropIntChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceOLinkHelper::PropIntPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterface>();
		service->Execute_SetPropInt(service, TestValue);
	});

	LatentIt("Signal.SigVoid", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoOperationsInterfaceSignals->OnSigVoidSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceOLinkHelper::SigVoidSignalCb);

		// use different test value
		TbSimpleNoOperationsInterfaceSignals->BroadcastSigVoidSignal();
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoOperationsInterfaceSignals->OnSigBoolSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceOLinkHelper::SigBoolSignalCb);

		// use different test value
		bool bParamBoolTestValue = true;
		TbSimpleNoOperationsInterfaceSignals->BroadcastSigBoolSignal(bParamBoolTestValue);
	});
}

void UTbSimpleNoOperationsInterfaceOLinkSpec::PropBoolPropertyCb(bool bInPropBool)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceOLinkSpec::PropBoolPropertyChangeLocalCheckRemoteCb(bool bInPropBool)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceOLinkSpec::PropBoolPropertyChangeLocalChangeRemoteCb(bool bInPropBool)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		bool TestValue = false;
		// use different test value
		TestValue = true;
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = false; // default value
		ImplFixture->GetImplementation()->Execute_SetPropBool(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		bool TestValue = false; // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTbSimpleNoOperationsInterfaceOLinkSpec::PropIntPropertyCb(int32 InPropInt)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceOLinkSpec::PropIntPropertyChangeLocalCheckRemoteCb(int32 InPropInt)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceOLinkSpec::PropIntPropertyChangeLocalChangeRemoteCb(int32 InPropInt)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		int32 TestValue = 0;
		// use different test value
		TestValue = 1;
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = 0; // default value
		ImplFixture->GetImplementation()->Execute_SetPropInt(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTbSimpleNoOperationsInterfaceOLinkSpec::SigVoidSignalCb()
{
	// known test value
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceOLinkSpec::SigBoolSignalCb(bool bInParamBool)
{
	// known test value
	bool bParamBoolTestValue = true;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
