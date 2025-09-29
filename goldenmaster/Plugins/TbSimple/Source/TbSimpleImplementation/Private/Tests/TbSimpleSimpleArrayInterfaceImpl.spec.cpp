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

#include "TbSimple/Implementation/TbSimpleSimpleArrayInterface.h"
#include "TbSimpleSimpleArrayInterfaceImplFixture.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbSimpleSimpleArrayInterfaceImplSpec, "TbSimple.SimpleArrayInterface.Impl", TbSimpleTestFilterMask);

TSharedPtr<FTbSimpleSimpleArrayInterfaceImplFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleSimpleArrayInterfaceImplSpec);

void UTbSimpleSimpleArrayInterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTbSimpleSimpleArrayInterfaceImplFixture>();
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
		TArray<bool> TestValue = TArray<bool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<bool> TestValue = TArray<bool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](const TArray<bool>& InPropBool)
			{
			TArray<bool> TestValue = TArray<bool>();
			// use different test value
			TestValue.Add(true);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(true);
		ImplFixture->GetImplementation()->SetPropBool(TestValue);
	});

	LatentIt("Property.PropBool.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<bool> TestValue = TArray<bool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropBoolChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceImplHelper::PropBoolPropertyCb);
		// use different test value
		TestValue.Add(true);
		ImplFixture->GetImplementation()->SetPropBool(TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](const TArray<int32>& InPropInt)
			{
			TArray<int32> TestValue = TArray<int32>();
			// use different test value
			TestValue.Add(1);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(1);
		ImplFixture->GetImplementation()->SetPropInt(TestValue);
	});

	LatentIt("Property.PropInt.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropIntChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceImplHelper::PropIntPropertyCb);
		// use different test value
		TestValue.Add(1);
		ImplFixture->GetImplementation()->SetPropInt(TestValue);
	});

	It("Property.PropInt32.Default", [this]()
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt32(), TestValue);
	});

	LatentIt("Property.PropInt32.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt32(), TestValue);

		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropInt32Changed.AddLambda([this, TestDone](const TArray<int32>& InPropInt32)
			{
			TArray<int32> TestValue = TArray<int32>();
			// use different test value
			TestValue.Add(1);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt32(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(1);
		ImplFixture->GetImplementation()->SetPropInt32(TestValue);
	});

	LatentIt("Property.PropInt32.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt32(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropInt32ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceImplHelper::PropInt32PropertyCb);
		// use different test value
		TestValue.Add(1);
		ImplFixture->GetImplementation()->SetPropInt32(TestValue);
	});

	It("Property.PropInt64.Default", [this]()
		{
		// Do implement test here
		TArray<int64> TestValue = TArray<int64>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt64(), TestValue);
	});

	LatentIt("Property.PropInt64.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int64> TestValue = TArray<int64>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt64(), TestValue);

		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropInt64Changed.AddLambda([this, TestDone](const TArray<int64>& InPropInt64)
			{
			TArray<int64> TestValue = TArray<int64>();
			// use different test value
			TestValue.Add(1LL);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt64(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(1LL);
		ImplFixture->GetImplementation()->SetPropInt64(TestValue);
	});

	LatentIt("Property.PropInt64.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int64> TestValue = TArray<int64>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt64(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropInt64ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceImplHelper::PropInt64PropertyCb);
		// use different test value
		TestValue.Add(1LL);
		ImplFixture->GetImplementation()->SetPropInt64(TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone](const TArray<float>& InPropFloat)
			{
			TArray<float> TestValue = TArray<float>();
			// use different test value
			TestValue.Add(1.0f);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(1.0f);
		ImplFixture->GetImplementation()->SetPropFloat(TestValue);
	});

	LatentIt("Property.PropFloat.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloatChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceImplHelper::PropFloatPropertyCb);
		// use different test value
		TestValue.Add(1.0f);
		ImplFixture->GetImplementation()->SetPropFloat(TestValue);
	});

	It("Property.PropFloat32.Default", [this]()
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat32(), TestValue);
	});

	LatentIt("Property.PropFloat32.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat32(), TestValue);

		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloat32Changed.AddLambda([this, TestDone](const TArray<float>& InPropFloat32)
			{
			TArray<float> TestValue = TArray<float>();
			// use different test value
			TestValue.Add(1.0f);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat32(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(1.0f);
		ImplFixture->GetImplementation()->SetPropFloat32(TestValue);
	});

	LatentIt("Property.PropFloat32.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat32(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloat32ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceImplHelper::PropFloat32PropertyCb);
		// use different test value
		TestValue.Add(1.0f);
		ImplFixture->GetImplementation()->SetPropFloat32(TestValue);
	});

	It("Property.PropFloat64.Default", [this]()
		{
		// Do implement test here
		TArray<double> TestValue = TArray<double>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat64(), TestValue);
	});

	LatentIt("Property.PropFloat64.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<double> TestValue = TArray<double>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat64(), TestValue);

		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloat64Changed.AddLambda([this, TestDone](const TArray<double>& InPropFloat64)
			{
			TArray<double> TestValue = TArray<double>();
			// use different test value
			TestValue.Add(1.0);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat64(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(1.0);
		ImplFixture->GetImplementation()->SetPropFloat64(TestValue);
	});

	LatentIt("Property.PropFloat64.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<double> TestValue = TArray<double>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat64(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloat64ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceImplHelper::PropFloat64PropertyCb);
		// use different test value
		TestValue.Add(1.0);
		ImplFixture->GetImplementation()->SetPropFloat64(TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		TArray<FString> TestValue = TArray<FString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FString> TestValue = TArray<FString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone](const TArray<FString>& InPropString)
			{
			TArray<FString> TestValue = TArray<FString>();
			// use different test value
			TestValue.Add(FString("xyz"));
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(FString("xyz"));
		ImplFixture->GetImplementation()->SetPropString(TestValue);
	});

	LatentIt("Property.PropString.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FString> TestValue = TArray<FString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropStringChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceImplHelper::PropStringPropertyCb);
		// use different test value
		TestValue.Add(FString("xyz"));
		ImplFixture->GetImplementation()->SetPropString(TestValue);
	});

	It("Property.PropReadOnlyString.Default", [this]()
		{
		// Do implement test here
		FString TestValue = FString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropReadOnlyString(), FString());
	});

	It("Operation.FuncBool", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncBool(TArray<bool>());
	});

	LatentIt("Operation.FuncBoolAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<TArray<bool>> Future = ImplFixture->GetImplementation()->FuncBoolAsync(TArray<bool>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<bool>& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	It("Operation.FuncInt", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncInt(TArray<int32>());
	});

	LatentIt("Operation.FuncIntAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<TArray<int32>> Future = ImplFixture->GetImplementation()->FuncIntAsync(TArray<int32>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<int32>& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	It("Operation.FuncInt32", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncInt32(TArray<int32>());
	});

	LatentIt("Operation.FuncInt32Async", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<TArray<int32>> Future = ImplFixture->GetImplementation()->FuncInt32Async(TArray<int32>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<int32>& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	It("Operation.FuncInt64", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncInt64(TArray<int64>());
	});

	LatentIt("Operation.FuncInt64Async", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<TArray<int64>> Future = ImplFixture->GetImplementation()->FuncInt64Async(TArray<int64>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<int64>& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	It("Operation.FuncFloat", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncFloat(TArray<float>());
	});

	LatentIt("Operation.FuncFloatAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<TArray<float>> Future = ImplFixture->GetImplementation()->FuncFloatAsync(TArray<float>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<float>& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	It("Operation.FuncFloat32", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncFloat32(TArray<float>());
	});

	LatentIt("Operation.FuncFloat32Async", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<TArray<float>> Future = ImplFixture->GetImplementation()->FuncFloat32Async(TArray<float>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<float>& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	It("Operation.FuncFloat64", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncFloat64(TArray<double>());
	});

	LatentIt("Operation.FuncFloat64Async", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<TArray<double>> Future = ImplFixture->GetImplementation()->FuncFloat64Async(TArray<double>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<double>& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	It("Operation.FuncString", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncString(TArray<FString>());
	});

	LatentIt("Operation.FuncStringAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<TArray<FString>> Future = ImplFixture->GetImplementation()->FuncStringAsync(TArray<FString>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<FString>& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnSigBoolSignal.AddLambda([this, TestDone](const TArray<bool>& InParamBool)
			{
			// known test value
			TArray<bool> ParamBoolTestValue = TArray<bool>(); // default value
			ParamBoolTestValue.Add(true);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<bool> ParamBoolTestValue = TArray<bool>(); // default value
		ParamBoolTestValue.Add(true);
		TbSimpleSimpleArrayInterfacePublisher->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigBoolBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnSigBoolSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceImplHelper::SigBoolSignalCb);

		// use different test value
		TArray<bool> ParamBoolTestValue = TArray<bool>(); // default value
		ParamBoolTestValue.Add(true);
		TbSimpleSimpleArrayInterfacePublisher->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnSigIntSignal.AddLambda([this, TestDone](const TArray<int32>& InParamInt)
			{
			// known test value
			TArray<int32> ParamIntTestValue = TArray<int32>(); // default value
			ParamIntTestValue.Add(1);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<int32> ParamIntTestValue = TArray<int32>(); // default value
		ParamIntTestValue.Add(1);
		TbSimpleSimpleArrayInterfacePublisher->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigIntBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnSigIntSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceImplHelper::SigIntSignalCb);

		// use different test value
		TArray<int32> ParamIntTestValue = TArray<int32>(); // default value
		ParamIntTestValue.Add(1);
		TbSimpleSimpleArrayInterfacePublisher->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigInt32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnSigInt32Signal.AddLambda([this, TestDone](const TArray<int32>& InParamInt32)
			{
			// known test value
			TArray<int32> ParamInt32TestValue = TArray<int32>(); // default value
			ParamInt32TestValue.Add(1);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt32, ParamInt32TestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<int32> ParamInt32TestValue = TArray<int32>(); // default value
		ParamInt32TestValue.Add(1);
		TbSimpleSimpleArrayInterfacePublisher->BroadcastSigInt32Signal(ParamInt32TestValue);
	});

	LatentIt("Signal.SigInt32BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnSigInt32SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceImplHelper::SigInt32SignalCb);

		// use different test value
		TArray<int32> ParamInt32TestValue = TArray<int32>(); // default value
		ParamInt32TestValue.Add(1);
		TbSimpleSimpleArrayInterfacePublisher->BroadcastSigInt32Signal(ParamInt32TestValue);
	});

	LatentIt("Signal.SigInt64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnSigInt64Signal.AddLambda([this, TestDone](const TArray<int64>& InParamInt64)
			{
			// known test value
			TArray<int64> ParamInt64TestValue = TArray<int64>(); // default value
			ParamInt64TestValue.Add(1LL);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt64, ParamInt64TestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<int64> ParamInt64TestValue = TArray<int64>(); // default value
		ParamInt64TestValue.Add(1LL);
		TbSimpleSimpleArrayInterfacePublisher->BroadcastSigInt64Signal(ParamInt64TestValue);
	});

	LatentIt("Signal.SigInt64BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnSigInt64SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceImplHelper::SigInt64SignalCb);

		// use different test value
		TArray<int64> ParamInt64TestValue = TArray<int64>(); // default value
		ParamInt64TestValue.Add(1LL);
		TbSimpleSimpleArrayInterfacePublisher->BroadcastSigInt64Signal(ParamInt64TestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnSigFloatSignal.AddLambda([this, TestDone](const TArray<float>& InParamFloat)
			{
			// known test value
			TArray<float> ParamFloatTestValue = TArray<float>(); // default value
			ParamFloatTestValue.Add(1.0f);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<float> ParamFloatTestValue = TArray<float>(); // default value
		ParamFloatTestValue.Add(1.0f);
		TbSimpleSimpleArrayInterfacePublisher->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigFloatBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnSigFloatSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceImplHelper::SigFloatSignalCb);

		// use different test value
		TArray<float> ParamFloatTestValue = TArray<float>(); // default value
		ParamFloatTestValue.Add(1.0f);
		TbSimpleSimpleArrayInterfacePublisher->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigFloat32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnSigFloat32Signal.AddLambda([this, TestDone](const TArray<float>& InParamFloa32)
			{
			// known test value
			TArray<float> ParamFloa32TestValue = TArray<float>(); // default value
			ParamFloa32TestValue.Add(1.0f);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloa32, ParamFloa32TestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<float> ParamFloa32TestValue = TArray<float>(); // default value
		ParamFloa32TestValue.Add(1.0f);
		TbSimpleSimpleArrayInterfacePublisher->BroadcastSigFloat32Signal(ParamFloa32TestValue);
	});

	LatentIt("Signal.SigFloat32BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnSigFloat32SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceImplHelper::SigFloat32SignalCb);

		// use different test value
		TArray<float> ParamFloa32TestValue = TArray<float>(); // default value
		ParamFloa32TestValue.Add(1.0f);
		TbSimpleSimpleArrayInterfacePublisher->BroadcastSigFloat32Signal(ParamFloa32TestValue);
	});

	LatentIt("Signal.SigFloat64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnSigFloat64Signal.AddLambda([this, TestDone](const TArray<double>& InParamFloat64)
			{
			// known test value
			TArray<double> ParamFloat64TestValue = TArray<double>(); // default value
			ParamFloat64TestValue.Add(1.0);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat64, ParamFloat64TestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<double> ParamFloat64TestValue = TArray<double>(); // default value
		ParamFloat64TestValue.Add(1.0);
		TbSimpleSimpleArrayInterfacePublisher->BroadcastSigFloat64Signal(ParamFloat64TestValue);
	});

	LatentIt("Signal.SigFloat64BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnSigFloat64SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceImplHelper::SigFloat64SignalCb);

		// use different test value
		TArray<double> ParamFloat64TestValue = TArray<double>(); // default value
		ParamFloat64TestValue.Add(1.0);
		TbSimpleSimpleArrayInterfacePublisher->BroadcastSigFloat64Signal(ParamFloat64TestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnSigStringSignal.AddLambda([this, TestDone](const TArray<FString>& InParamString)
			{
			// known test value
			TArray<FString> ParamStringTestValue = TArray<FString>(); // default value
			ParamStringTestValue.Add(FString("xyz"));
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FString> ParamStringTestValue = TArray<FString>(); // default value
		ParamStringTestValue.Add(FString("xyz"));
		TbSimpleSimpleArrayInterfacePublisher->BroadcastSigStringSignal(ParamStringTestValue);
	});

	LatentIt("Signal.SigStringBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnSigStringSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceImplHelper::SigStringSignalCb);

		// use different test value
		TArray<FString> ParamStringTestValue = TArray<FString>(); // default value
		ParamStringTestValue.Add(FString("xyz"));
		TbSimpleSimpleArrayInterfacePublisher->BroadcastSigStringSignal(ParamStringTestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
