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
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "TbSimpleSimpleInterfaceOLinkFixture.h"
#include "TbSimple/Implementation/TbSimpleSimpleInterface.h"
#include "TbSimple/Generated/OLink/TbSimpleSimpleInterfaceOLinkClient.h"
#include "TbSimple/Generated/OLink/TbSimpleSimpleInterfaceOLinkAdapter.h"

#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "TbSimple/Tests/TbSimpleTestsCommon.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace SimpleInterface
{
namespace OLink
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSimpleSimpleInterfaceOLinkSpec, "TbSimple.SimpleInterface.OLink", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleSimpleInterfaceOLinkFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleSimpleInterfaceOLinkSpec);

void UTbSimpleSimpleInterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSimpleSimpleInterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleInterface>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		UTbSimpleSimpleInterfaceOLinkClient* OLinkClient = Cast<UTbSimpleSimpleInterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
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

	It("Property.PropBool.Default", [this]()
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleInterfaceSignals->OnPropBoolChanged.AddLambda([this, TestDone](bool bInPropBool)
			{
			bool TestValue = false;
			// use different test value
			TestValue = true;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = true;
		ImplFixture->GetImplementation()->SetPropBool(TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleInterfaceSignals->OnPropIntChanged.AddLambda([this, TestDone](int32 InPropInt)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetPropInt(TestValue);
	});

	It("Property.PropInt32.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt32(), TestValue);
	});

	LatentIt("Property.PropInt32.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt32(), TestValue);

		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleInterfaceSignals->OnPropInt32Changed.AddLambda([this, TestDone](int32 InPropInt32)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt32(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetPropInt32(TestValue);
	});

	It("Property.PropInt64.Default", [this]()
		{
		// Do implement test here
		int64 TestValue = 0LL; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt64(), TestValue);
	});

	LatentIt("Property.PropInt64.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int64 TestValue = 0LL; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt64(), TestValue);

		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleInterfaceSignals->OnPropInt64Changed.AddLambda([this, TestDone](int64 InPropInt64)
			{
			int64 TestValue = 0LL;
			// use different test value
			TestValue = 1LL;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt64(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1LL;
		ImplFixture->GetImplementation()->SetPropInt64(TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		float TestValue = 0.0f; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		float TestValue = 0.0f; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleInterfaceSignals->OnPropFloatChanged.AddLambda([this, TestDone](float InPropFloat)
			{
			float TestValue = 0.0f;
			// use different test value
			TestValue = 1.0f;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1.0f;
		ImplFixture->GetImplementation()->SetPropFloat(TestValue);
	});

	It("Property.PropFloat32.Default", [this]()
		{
		// Do implement test here
		float TestValue = 0.0f; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat32(), TestValue);
	});

	LatentIt("Property.PropFloat32.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		float TestValue = 0.0f; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat32(), TestValue);

		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleInterfaceSignals->OnPropFloat32Changed.AddLambda([this, TestDone](float InPropFloat32)
			{
			float TestValue = 0.0f;
			// use different test value
			TestValue = 1.0f;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat32(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1.0f;
		ImplFixture->GetImplementation()->SetPropFloat32(TestValue);
	});

	It("Property.PropFloat64.Default", [this]()
		{
		// Do implement test here
		double TestValue = 0.0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat64(), TestValue);
	});

	LatentIt("Property.PropFloat64.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		double TestValue = 0.0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat64(), TestValue);

		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleInterfaceSignals->OnPropFloat64Changed.AddLambda([this, TestDone](double InPropFloat64)
			{
			double TestValue = 0.0;
			// use different test value
			TestValue = 1.0;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat64(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1.0;
		ImplFixture->GetImplementation()->SetPropFloat64(TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		FString TestValue = FString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FString TestValue = FString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleInterfaceSignals->OnPropStringChanged.AddLambda([this, TestDone](const FString& InPropString)
			{
			FString TestValue = FString();
			// use different test value
			TestValue = FString("xyz");
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = FString("xyz");
		ImplFixture->GetImplementation()->SetPropString(TestValue);
	});

	LatentIt("Operation.FuncNoReturnValue", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncNoReturnValue(false);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncBool(false);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncInt(0);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncInt32(0);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncInt64(0LL);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncFloat(0.0f);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncFloat32(0.0f);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncFloat64(0.0);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncString(FString());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleInterfaceSignals->OnSigBoolSignal.AddLambda([this, TestDone](bool bInParamBool)
			{
			// known test value
			bool bParamBoolTestValue = true;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		bool bParamBoolTestValue = true;
		TbSimpleSimpleInterfaceSignals->BroadcastSigBoolSignal(bParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleInterfaceSignals->OnSigIntSignal.AddLambda([this, TestDone](int32 InParamInt)
			{
			// known test value
			int32 ParamIntTestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 ParamIntTestValue = 1;
		TbSimpleSimpleInterfaceSignals->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigInt32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleInterfaceSignals->OnSigInt32Signal.AddLambda([this, TestDone](int32 InParamInt32)
			{
			// known test value
			int32 ParamInt32TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt32, ParamInt32TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 ParamInt32TestValue = 1;
		TbSimpleSimpleInterfaceSignals->BroadcastSigInt32Signal(ParamInt32TestValue);
	});

	LatentIt("Signal.SigInt64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleInterfaceSignals->OnSigInt64Signal.AddLambda([this, TestDone](int64 InParamInt64)
			{
			// known test value
			int64 ParamInt64TestValue = 1LL;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt64, ParamInt64TestValue);
			TestDone.Execute();
		});

		// use different test value
		int64 ParamInt64TestValue = 1LL;
		TbSimpleSimpleInterfaceSignals->BroadcastSigInt64Signal(ParamInt64TestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleInterfaceSignals->OnSigFloatSignal.AddLambda([this, TestDone](float InParamFloat)
			{
			// known test value
			float ParamFloatTestValue = 1.0f;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
			TestDone.Execute();
		});

		// use different test value
		float ParamFloatTestValue = 1.0f;
		TbSimpleSimpleInterfaceSignals->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigFloat32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleInterfaceSignals->OnSigFloat32Signal.AddLambda([this, TestDone](float InParamFloat32)
			{
			// known test value
			float ParamFloat32TestValue = 1.0f;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat32, ParamFloat32TestValue);
			TestDone.Execute();
		});

		// use different test value
		float ParamFloat32TestValue = 1.0f;
		TbSimpleSimpleInterfaceSignals->BroadcastSigFloat32Signal(ParamFloat32TestValue);
	});

	LatentIt("Signal.SigFloat64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleInterfaceSignals->OnSigFloat64Signal.AddLambda([this, TestDone](double InParamFloat64)
			{
			// known test value
			double ParamFloat64TestValue = 1.0;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat64, ParamFloat64TestValue);
			TestDone.Execute();
		});

		// use different test value
		double ParamFloat64TestValue = 1.0;
		TbSimpleSimpleInterfaceSignals->BroadcastSigFloat64Signal(ParamFloat64TestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleInterfaceSignals->OnSigStringSignal.AddLambda([this, TestDone](const FString& InParamString)
			{
			// known test value
			FString ParamStringTestValue = FString("xyz");
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
			TestDone.Execute();
		});

		// use different test value
		FString ParamStringTestValue = FString("xyz");
		TbSimpleSimpleInterfaceSignals->BroadcastSigStringSignal(ParamStringTestValue);
	});
}
} // namespace Tests
} // namespace OLink
} // namespace SimpleInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
