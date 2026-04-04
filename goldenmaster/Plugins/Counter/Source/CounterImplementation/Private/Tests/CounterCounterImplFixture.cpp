// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "CounterCounterImplFixture.h"
#include "Counter/Implementation/CounterCounter.h"
#include "Counter/Tests/CounterTestsCommon.h"
#include "CustomTypes/Tests/CustomTypesTestsCommon.h"
#include "ExternTypes/Tests/ExternTypesTestsCommon.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UCounterCounterImplHelper::SetParentFixture(TWeakPtr<FCounterCounterImplFixture> InFixture)
{
	ImplFixture = InFixture;
}

void UCounterCounterImplHelper::SetSpec(FAutomationTestBase* InSpec)
{
	Spec = InSpec;
}

void UCounterCounterImplHelper::SetTestDone(const FDoneDelegate& InDone)
{
	testDoneDelegate = InDone;
}

void UCounterCounterImplHelper::VectorPropertyCb(const FCustomTypesVector3D& InVector)
{
	FCustomTypesVector3D TestValue = FCustomTypesVector3D();
	// use different test value
	TestValue = createTestFCustomTypesVector3D();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVector, TestValue);
	if (TSharedPtr<FCounterCounterImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetVector(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UCounterCounterImplHelper::VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>();
	// use different test value
	TestValue = createTestFCustomTypesVector3DArray();
	Spec->TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVectorArray, TestValue);
	if (TSharedPtr<FCounterCounterImplFixture> PinnedImplFixture = ImplFixture.Pin())
	{
		Spec->TestEqual(TEXT("Getter should return the same value as set by the setter"), PinnedImplFixture->GetImplementation()->GetVectorArray(), TestValue);
	}
	testDoneDelegate.Execute();
}

void UCounterCounterImplHelper::ValueChangedSignalCb(const FCustomTypesVector3D& InVector, const FVector& InExternVector, const TArray<FCustomTypesVector3D>& InVectorArray, const TArray<FVector>& InExternVectorArray)
{
	// known test value
	FCustomTypesVector3D VectorTestValue = createTestFCustomTypesVector3D();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InVector, VectorTestValue);
	TArray<FCustomTypesVector3D> VectorArrayTestValue = createTestFCustomTypesVector3DArray();
	Spec->TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InVectorArray, VectorArrayTestValue);
	testDoneDelegate.Execute();
}

FCounterCounterImplFixture::FCounterCounterImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UCounterCounterImplementation>();
	Helper = NewObject<UCounterCounterImplHelper>();
}

FCounterCounterImplFixture::~FCounterCounterImplFixture()
{
	CleanUp();
}

TScriptInterface<ICounterCounterInterface> FCounterCounterImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UCounterCounterImplHelper> FCounterCounterImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FCounterCounterImplFixture::GetGameInstance()
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

void FCounterCounterImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UCounterCounterImplHelper::SetParentFixture(TWeakPtr<FCounterCounterImplFixture> /*InFixture*/)
{
}

void UCounterCounterImplHelper::SetSpec(FAutomationTestBase* /*InSpec*/)
{
}

void UCounterCounterImplHelper::SetTestDone(const FDoneDelegate& /*InDone*/)
{
}

void UCounterCounterImplHelper::VectorPropertyCb(const FCustomTypesVector3D& Vector)
{
	(void)Vector;
}

void UCounterCounterImplHelper::VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& VectorArray)
{
	(void)VectorArray;
}

void UCounterCounterImplHelper::ValueChangedSignalCb(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray)
{
	(void)Vector;
	(void)ExternVector;
	(void)VectorArray;
	(void)ExternVectorArray;
}
#endif // WITH_DEV_AUTOMATION_TESTS
