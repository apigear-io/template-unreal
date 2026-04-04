// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbRefIfaces/Implementation/TbRefIfacesSimpleLocalIf.h"
#include "TbRefIfacesSimpleLocalIfImplFixture.h"
#include "TbRefIfaces/Tests/TbRefIfacesTestsCommon.h"
#include "TbIfaceimport/Tests/TbIfaceimportTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbRefIfacesSimpleLocalIfImplSpec, "TbRefIfaces.SimpleLocalIf.Impl", TbRefIfacesTestFilterMask);

TSharedPtr<FTbRefIfacesSimpleLocalIfImplFixture> ImplFixture;

END_DEFINE_SPEC(UTbRefIfacesSimpleLocalIfImplSpec);

void UTbRefIfacesSimpleLocalIfImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTbRefIfacesSimpleLocalIfImplFixture>();
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

	It("Property.IntProperty.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetIntProperty(), TestValue);
	});

	LatentIt("Property.IntProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetIntProperty(), TestValue);

		UTbRefIfacesSimpleLocalIfPublisher* TbRefIfacesSimpleLocalIfPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbRefIfacesSimpleLocalIfPublisher->OnIntPropertyChanged.AddLambda([this, TestDone](int32 InIntProperty)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InIntProperty, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetIntProperty(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetIntProperty(TestValue);
	});

	LatentIt("Property.IntProperty.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetIntProperty(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbRefIfacesSimpleLocalIfPublisher* TbRefIfacesSimpleLocalIfPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbRefIfacesSimpleLocalIfPublisher->OnIntPropertyChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbRefIfacesSimpleLocalIfImplHelper::IntPropertyPropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetIntProperty(TestValue);
	});

	It("Operation.IntMethod", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->IntMethod(0);
	});

	LatentIt("Operation.IntMethodAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<int32> Future = ImplFixture->GetImplementation()->IntMethodAsync(0);

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const int32& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	LatentIt("Signal.IntSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefIfacesSimpleLocalIfPublisher* TbRefIfacesSimpleLocalIfPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbRefIfacesSimpleLocalIfPublisher->OnIntSignalSignal.AddLambda([this, TestDone](int32 InParam)
			{
			// known test value
			int32 ParamTestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 ParamTestValue = 1;
		TbRefIfacesSimpleLocalIfPublisher->BroadcastIntSignalSignal(ParamTestValue);
	});

	LatentIt("Signal.IntSignalBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbRefIfacesSimpleLocalIfPublisher* TbRefIfacesSimpleLocalIfPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbRefIfacesSimpleLocalIfPublisher->OnIntSignalSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbRefIfacesSimpleLocalIfImplHelper::IntSignalSignalCb);

		// use different test value
		int32 ParamTestValue = 1;
		TbRefIfacesSimpleLocalIfPublisher->BroadcastIntSignalSignal(ParamTestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
