/**
Copyright 2024 ApiGear UG
Copyright 2024 Epic Games, Inc.

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
#pragma once

#include "Runtime/Launch/Resources/Version.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Testbed2_data.h"
#include "Testbed2/Generated/api/Testbed2NestedStruct2InterfaceInterface.h"
#include "AbstractTestbed2NestedStruct2Interface.generated.h"

/**
 * Abstract UAbstractTestbed2NestedStruct2Interface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TESTBED2API_API UAbstractTestbed2NestedStruct2Interface : public UGameInstanceSubsystem, public ITestbed2NestedStruct2InterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTestbed2NestedStruct2Interface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTestbed2NestedStruct2InterfacePublisher* _GetPublisher() override;

	// methods
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) override;
	virtual TFuture<FTestbed2NestedStruct1> Func1Async(const FTestbed2NestedStruct1& Param1) override;
	virtual FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1) override PURE_VIRTUAL(UAbstractTestbed2NestedStruct2Interface::Func1, return FTestbed2NestedStruct1(););

	virtual void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;
	virtual TFuture<FTestbed2NestedStruct1> Func2Async(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;
	virtual FTestbed2NestedStruct1 Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override PURE_VIRTUAL(UAbstractTestbed2NestedStruct2Interface::Func2, return FTestbed2NestedStruct1(););

	// properties
	virtual FTestbed2NestedStruct1 GetProp1() const override PURE_VIRTUAL(UAbstractTestbed2NestedStruct2Interface::GetProp1, return FTestbed2NestedStruct1(););
	virtual void SetProp1(const FTestbed2NestedStruct1& InProp1) override PURE_VIRTUAL(UAbstractTestbed2NestedStruct2Interface::SetProp1, return;);

	virtual FTestbed2NestedStruct2 GetProp2() const override PURE_VIRTUAL(UAbstractTestbed2NestedStruct2Interface::GetProp2, return FTestbed2NestedStruct2(););
	virtual void SetProp2(const FTestbed2NestedStruct2& InProp2) override PURE_VIRTUAL(UAbstractTestbed2NestedStruct2Interface::SetProp2, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	FTestbed2NestedStruct1 Prop1{FTestbed2NestedStruct1()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|NestedStruct2Interface|Properties", BlueprintInternalUseOnly)
	FTestbed2NestedStruct1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|NestedStruct2Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTestbed2NestedStruct1& InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	FTestbed2NestedStruct2 Prop2{FTestbed2NestedStruct2()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|NestedStruct2Interface|Properties", BlueprintInternalUseOnly)
	FTestbed2NestedStruct2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|NestedStruct2Interface|Properties", BlueprintInternalUseOnly)
	void SetProp2_Private(const FTestbed2NestedStruct2& InProp2);

private:
	// signals
	UPROPERTY()
	UTestbed2NestedStruct2InterfacePublisher* Testbed2NestedStruct2InterfacePublisher;
};
