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
#include "TbSame2SameStruct1InterfaceSimulation.generated.h"

UCLASS(BlueprintType)
class UTbSame2SameStruct1InterfaceSimulationService : public UObject, public ITbSame2SameStruct1InterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTbSame2SameStruct1InterfaceSimulationService();
	virtual ~UTbSame2SameStruct1InterfaceSimulationService();

	// signals
	FTbSame2SameStruct1InterfaceSig1Delegate Sig1Signal;
	FTbSame2SameStruct1InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	FTbSame2SameStruct1InterfaceProp1ChangedDelegate Prop1Changed;
	FTbSame2SameStruct1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	// properties
	FTbSame2Struct1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const FTbSame2Struct1& Prop1) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1) override{};
	FTbSame2Struct1 Func1_Implementation(const FTbSame2Struct1& Param1) override;

private:
	// properties - local copy
	FTbSame2Struct1 Prop1;
};
