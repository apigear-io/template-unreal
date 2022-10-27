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

#include "TbSame1_apig.h"
#include "TbSame1SameEnum1InterfaceSimulation.generated.h"

UCLASS(BlueprintType)
class UTbSame1SameEnum1InterfaceSimulationService : public UObject, public ITbSame1SameEnum1InterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTbSame1SameEnum1InterfaceSimulationService();
	virtual ~UTbSame1SameEnum1InterfaceSimulationService();

	// signals
	FTbSame1SameEnum1InterfaceSig1Delegate Sig1Signal;
	FTbSame1SameEnum1InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	FTbSame1SameEnum1InterfaceProp1ChangedDelegate Prop1Changed;
	FTbSame1SameEnum1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	// properties
	ETbSame1Enum1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const ETbSame1Enum1& Prop1) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, const ETbSame1Enum1& Param1) override{};
	ETbSame1Enum1 Func1_Implementation(const ETbSame1Enum1& Param1) override;

protected:
	// signals
	void BroadcastSig1_Implementation(const ETbSame1Enum1& Param1) override;

	void BroadcastProp1Changed_Implementation(const ETbSame1Enum1& Prop1) override;

private:
	// properties - local copy
	ETbSame1Enum1 Prop1;
};