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
#include "Testbed2NestedStruct2InterfaceSimulation.generated.h"

UCLASS(BlueprintType)
class UTestbed2NestedStruct2InterfaceSimulationService : public UObject, public ITestbed2NestedStruct2InterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed2NestedStruct2InterfaceSimulationService();
	virtual ~UTestbed2NestedStruct2InterfaceSimulationService();

	// signals
	FTestbed2NestedStruct2InterfaceSig1Delegate Sig1Signal;
	FTestbed2NestedStruct2InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	FTestbed2NestedStruct2InterfaceSig2Delegate Sig2Signal;
	FTestbed2NestedStruct2InterfaceSig2Delegate& GetSig2SignalDelegate() override;

	FTestbed2NestedStruct2InterfaceProp1ChangedDelegate Prop1Changed;
	FTestbed2NestedStruct2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	FTestbed2NestedStruct2InterfaceProp2ChangedDelegate Prop2Changed;
	FTestbed2NestedStruct2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	// properties
	FTestbed2NestedStruct1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const FTestbed2NestedStruct1& Prop1) override;

	FTestbed2NestedStruct2 GetProp2_Implementation() const override;
	void SetProp2_Implementation(const FTestbed2NestedStruct2& Prop2) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) override{};
	FTestbed2NestedStruct1 Func1_Implementation(const FTestbed2NestedStruct1& Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override{};
	FTestbed2NestedStruct1 Func2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;

private:
	// properties - local copy
	FTestbed2NestedStruct1 Prop1;
	FTestbed2NestedStruct2 Prop2;
};
