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

#include "apig/Testbed2_apig.h"
#include "Testbed2NestedStruct1InterfaceSimulation.generated.h"

UCLASS(BlueprintType)
class UTestbed2NestedStruct1InterfaceSimulationService : public UObject, public ITestbed2NestedStruct1InterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed2NestedStruct1InterfaceSimulationService();
	virtual ~UTestbed2NestedStruct1InterfaceSimulationService();

	// signals
	FTestbed2NestedStruct1InterfaceSig1Delegate Sig1Signal;
	FTestbed2NestedStruct1InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	FTestbed2NestedStruct1InterfaceProp1ChangedDelegate Prop1Changed;
	FTestbed2NestedStruct1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	// properties
	FTestbed2NestedStruct1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const FTestbed2NestedStruct1& Prop1) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) override{};
	FTestbed2NestedStruct1 Func1_Implementation(const FTestbed2NestedStruct1& Param1) override;

protected:
	// signals
	void BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1) override;

	void BroadcastProp1Changed_Implementation(const FTestbed2NestedStruct1& Prop1) override;

private:
	// properties - local copy
	FTestbed2NestedStruct1 Prop1;
};
