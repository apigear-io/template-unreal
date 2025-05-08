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
#include "CounterCounterMsgBusFixture.h"
#include "CounterTestsCommon.h"
#include "CustomTypes/Private/Tests/CustomTypesTestsCommon.h"
#include "ExternTypes/Private/Tests/ExternTypesTestsCommon.h"
#include "Generated/MsgBus/CounterCounterMsgBusClient.h"
#include "Generated/MsgBus/CounterCounterMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UCounterCounterMsgBusHelper::~UCounterCounterMsgBusHelper()
{
	Spec = nullptr;
}

void UCounterCounterMsgBusHelper::SetParentFixture(TWeakPtr<FCounterCounterMsgBusFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UCounterCounterMsgBusHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UCounterCounterMsgBusHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UCounterCounterMsgBusHelper::VectorPropertyCb(const FCustomTypesVector3D& InVector)
{
	FCustomTypesVector3D TestValue = FCustomTypesVector3D();
	// use different test value
	TestValue = createTestFCustomTypesVector3D();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVector, TestValue);
	if (TSharedPtr<FCounterCounterMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetVector(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UCounterCounterMsgBusHelper::VectorPropertyChangeLocalCheckRemoteCb(const FCustomTypesVector3D& InVector)
{
	FCustomTypesVector3D TestValue = FCustomTypesVector3D();
	// use different test value
	TestValue = createTestFCustomTypesVector3D();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVector, TestValue);
	if (TSharedPtr<FCounterCounterMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetVector(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UCounterCounterMsgBusHelper::VectorPropertyChangeLocalChangeRemoteCb(const FCustomTypesVector3D& InVector)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FCustomTypesVector3D TestValue = FCustomTypesVector3D();
		// use different test value
		TestValue = createTestFCustomTypesVector3D();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVector, TestValue);
		if (TSharedPtr<FCounterCounterMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetVector(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = FCustomTypesVector3D(); // default value
		if (TSharedPtr<FCounterCounterMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetVector(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		FCustomTypesVector3D TestValue = FCustomTypesVector3D(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVector, TestValue);
		if (TSharedPtr<FCounterCounterMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetVector(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UCounterCounterMsgBusHelper::VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>();
	// use different test value
	TestValue = createTestFCustomTypesVector3DArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVectorArray, TestValue);
	if (TSharedPtr<FCounterCounterMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetVectorArray(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UCounterCounterMsgBusHelper::VectorArrayPropertyChangeLocalCheckRemoteCb(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>();
	// use different test value
	TestValue = createTestFCustomTypesVector3DArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVectorArray, TestValue);
	if (TSharedPtr<FCounterCounterMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetVectorArray(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
	}
	testDoneDelegate.Execute();
}

void UCounterCounterMsgBusHelper::VectorArrayPropertyChangeLocalChangeRemoteCb(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>();
		// use different test value
		TestValue = createTestFCustomTypesVector3DArray();
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVectorArray, TestValue);
		if (TSharedPtr<FCounterCounterMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetVectorArray(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}

		// now set it to the default value
		TestValue = TArray<FCustomTypesVector3D>(); // default value
		if (TSharedPtr<FCounterCounterMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			PinnedImplFixture->GetImplementation()->Execute_SetVectorArray(PinnedImplFixture->GetImplementation().GetObject(), TestValue);
		}
	}
	else
	{
		TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>(); // default value
		Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVectorArray, TestValue);
		if (TSharedPtr<FCounterCounterMsgBusFixture> PinnedImplFixture = ImplFixture.Pin())
		{
			Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->Execute_GetVectorArray(PinnedImplFixture->GetImplementation().GetObject()), TestValue);
		}
		testDoneDelegate.Execute();
	}
}

void UCounterCounterMsgBusHelper::ValueChangedSignalCb(const FCustomTypesVector3D& InVector, const FVector& InExternVector, const TArray<FCustomTypesVector3D>& InVectorArray, const TArray<FVector>& InExternVectorArray)
{
	// known test value
	FCustomTypesVector3D VectorTestValue = createTestFCustomTypesVector3D();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InVector, VectorTestValue);
	TArray<FCustomTypesVector3D> VectorArrayTestValue = createTestFCustomTypesVector3DArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InVectorArray, VectorArrayTestValue);
	testDoneDelegate.Execute();
}

void UCounterCounterMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

FCounterCounterMsgBusFixture::FCounterCounterMsgBusFixture()
{
	Helper = NewObject<UCounterCounterMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UCounterCounterMsgBusClient>();
}

FCounterCounterMsgBusFixture::~FCounterCounterMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ICounterCounterInterface> FCounterCounterMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UCounterCounterMsgBusAdapter* FCounterCounterMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UCounterCounterMsgBusAdapter>();
}

TSoftObjectPtr<UCounterCounterMsgBusHelper> FCounterCounterMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FCounterCounterMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>(GetTransientPackage());
		GameInstance->Init();
		// needed to prevent garbage collection and we can't use UPROPERTY on raw c++ objects
		GameInstance->AddToRoot();
	}

	return GameInstance.Get();
}

void FCounterCounterMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UCounterCounterMsgBusHelper::~UCounterCounterMsgBusHelper()
{
}

void UCounterCounterMsgBusHelper::SetParentFixture(TWeakPtr<FCounterCounterMsgBusFixture> /*InFixture*/)
{
}

void UCounterCounterMsgBusHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UCounterCounterMsgBusHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UCounterCounterMsgBusHelper::VectorPropertyCb(const FCustomTypesVector3D& InVector)
{
	(void)InVector;
}

void UCounterCounterMsgBusHelper::VectorPropertyChangeLocalCheckRemoteCb(const FCustomTypesVector3D& InVector)
{
	(void)InVector;
}

void UCounterCounterMsgBusHelper::VectorPropertyChangeLocalChangeRemoteCb(const FCustomTypesVector3D& InVector)
{
	(void)InVector;
}

void UCounterCounterMsgBusHelper::VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	(void)InVectorArray;
}

void UCounterCounterMsgBusHelper::VectorArrayPropertyChangeLocalCheckRemoteCb(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	(void)InVectorArray;
}

void UCounterCounterMsgBusHelper::VectorArrayPropertyChangeLocalChangeRemoteCb(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	(void)InVectorArray;
}

void UCounterCounterMsgBusHelper::ValueChangedSignalCb(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray)
{
	(void)Vector;
	(void)ExternVector;
	(void)VectorArray;
	(void)ExternVectorArray;
}

void UCounterCounterMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
