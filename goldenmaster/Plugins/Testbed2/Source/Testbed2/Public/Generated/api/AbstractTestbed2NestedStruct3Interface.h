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
#pragma once

#include "Runtime/Launch/Resources/Version.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Testbed2_data.h"
#include "Testbed2NestedStruct3InterfaceInterface.h"
#include "AbstractTestbed2NestedStruct3Interface.generated.h"

/**
 * Abstract UAbstractTestbed2NestedStruct3Interface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TESTBED2_API UAbstractTestbed2NestedStruct3Interface : public UGameInstanceSubsystem, public ITestbed2NestedStruct3InterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTestbed2NestedStruct3Interface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTestbed2NestedStruct3InterfaceSignals* _GetSignals_Implementation() override
	{
		return Testbed2NestedStruct3InterfaceSignals;
	};

	// methods
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) override;
	virtual FTestbed2NestedStruct1 Func1_Implementation(const FTestbed2NestedStruct1& Param1) override PURE_VIRTUAL(UAbstractTestbed2NestedStruct3Interface::Func1_Implementation, return FTestbed2NestedStruct1(););

	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;
	virtual FTestbed2NestedStruct1 Func2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override PURE_VIRTUAL(UAbstractTestbed2NestedStruct3Interface::Func2_Implementation, return FTestbed2NestedStruct1(););

	virtual void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) override;
	virtual FTestbed2NestedStruct1 Func3_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) override PURE_VIRTUAL(UAbstractTestbed2NestedStruct3Interface::Func3_Implementation, return FTestbed2NestedStruct1(););

	// properties
	virtual FTestbed2NestedStruct1 GetProp1_Implementation() const override PURE_VIRTUAL(UAbstractTestbed2NestedStruct3Interface::GetProp1_Implementation, return FTestbed2NestedStruct1(););
	virtual void SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1) override PURE_VIRTUAL(UAbstractTestbed2NestedStruct3Interface::SetProp1_Implementation, return;);

	virtual FTestbed2NestedStruct2 GetProp2_Implementation() const override PURE_VIRTUAL(UAbstractTestbed2NestedStruct3Interface::GetProp2_Implementation, return FTestbed2NestedStruct2(););
	virtual void SetProp2_Implementation(const FTestbed2NestedStruct2& InProp2) override PURE_VIRTUAL(UAbstractTestbed2NestedStruct3Interface::SetProp2_Implementation, return;);

	virtual FTestbed2NestedStruct3 GetProp3_Implementation() const override PURE_VIRTUAL(UAbstractTestbed2NestedStruct3Interface::GetProp3_Implementation, return FTestbed2NestedStruct3(););
	virtual void SetProp3_Implementation(const FTestbed2NestedStruct3& InProp3) override PURE_VIRTUAL(UAbstractTestbed2NestedStruct3Interface::SetProp3_Implementation, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	FTestbed2NestedStruct1 Prop1{FTestbed2NestedStruct1()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties", BlueprintInternalUseOnly)
	FTestbed2NestedStruct1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTestbed2NestedStruct1& InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	FTestbed2NestedStruct2 Prop2{FTestbed2NestedStruct2()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties", BlueprintInternalUseOnly)
	FTestbed2NestedStruct2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties", BlueprintInternalUseOnly)
	void SetProp2_Private(const FTestbed2NestedStruct2& InProp2);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp3_Private, BlueprintSetter = SetProp3_Private, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	FTestbed2NestedStruct3 Prop3{FTestbed2NestedStruct3()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties", BlueprintInternalUseOnly)
	FTestbed2NestedStruct3 GetProp3_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties", BlueprintInternalUseOnly)
	void SetProp3_Private(const FTestbed2NestedStruct3& InProp3);

private:
	// signals
	UPROPERTY()
	UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals;
};
