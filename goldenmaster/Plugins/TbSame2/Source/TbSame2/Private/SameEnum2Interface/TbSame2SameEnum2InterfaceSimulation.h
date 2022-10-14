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

#include "apig/TbSame2_apig.h"
#include "TbSame2SameEnum2InterfaceSimulation.generated.h"

UCLASS(BlueprintType)
class UTbSame2SameEnum2InterfaceSimulationService : public UObject, public ITbSame2SameEnum2InterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTbSame2SameEnum2InterfaceSimulationService();
	virtual ~UTbSame2SameEnum2InterfaceSimulationService();

	// signals
	FTbSame2SameEnum2InterfaceSig1Delegate Sig1Signal;
	FTbSame2SameEnum2InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	FTbSame2SameEnum2InterfaceSig2Delegate Sig2Signal;
	FTbSame2SameEnum2InterfaceSig2Delegate& GetSig2SignalDelegate() override;

	FTbSame2SameEnum2InterfaceProp1ChangedDelegate Prop1Changed;
	FTbSame2SameEnum2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	FTbSame2SameEnum2InterfaceProp2ChangedDelegate Prop2Changed;
	FTbSame2SameEnum2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	// properties
	void GetProp1_Implementation(ETbSame2Enum1& ReturnValue) const override;
	void SetProp1_Implementation(const ETbSame2Enum1& Prop1) override;

	void GetProp2_Implementation(ETbSame2Enum2& ReturnValue) const override;
	void SetProp2_Implementation(const ETbSame2Enum2& Prop2) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, const ETbSame2Enum1& Param1) override{};
	void Func1_Implementation(ETbSame2Enum1& Result, const ETbSame2Enum1& Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, const ETbSame2Enum1& Param1, const ETbSame2Enum2& Param2) override{};
	void Func2_Implementation(ETbSame2Enum1& Result, const ETbSame2Enum1& Param1, const ETbSame2Enum2& Param2) override;

private:
	// properties - local copy
	ETbSame2Enum1 Prop1;
	ETbSame2Enum2 Prop2;
};
