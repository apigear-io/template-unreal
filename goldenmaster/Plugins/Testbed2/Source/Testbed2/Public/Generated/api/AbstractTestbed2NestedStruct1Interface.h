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
#include "Testbed2NestedStruct1InterfaceInterface.h"
#include "AbstractTestbed2NestedStruct1Interface.generated.h"

/**
 * Abstract UAbstractTestbed2NestedStruct1Interface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TESTBED2_API UAbstractTestbed2NestedStruct1Interface : public UGameInstanceSubsystem, public ITestbed2NestedStruct1InterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTestbed2NestedStruct1Interface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTestbed2NestedStruct1InterfaceSignals* _GetSignals_Implementation() override
	{
		return Testbed2NestedStruct1InterfaceSignals;
	};

	// methods
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) override;
	virtual FTestbed2NestedStruct1 Func1_Implementation(const FTestbed2NestedStruct1& Param1) override PURE_VIRTUAL(UAbstractTestbed2NestedStruct1Interface::Func1_Implementation, return FTestbed2NestedStruct1(););

	// properties
	virtual FTestbed2NestedStruct1 GetProp1_Implementation() const override PURE_VIRTUAL(UAbstractTestbed2NestedStruct1Interface::GetProp1_Implementation, return FTestbed2NestedStruct1(););
	virtual void SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1) override PURE_VIRTUAL(UAbstractTestbed2NestedStruct1Interface::SetProp1_Implementation, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	FTestbed2NestedStruct1 Prop1{FTestbed2NestedStruct1()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|NestedStruct1Interface|Properties", BlueprintInternalUseOnly)
	FTestbed2NestedStruct1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|NestedStruct1Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTestbed2NestedStruct1& InProp1);

private:
	// signals
	UPROPERTY()
	UTestbed2NestedStruct1InterfaceSignals* Testbed2NestedStruct1InterfaceSignals;
};
