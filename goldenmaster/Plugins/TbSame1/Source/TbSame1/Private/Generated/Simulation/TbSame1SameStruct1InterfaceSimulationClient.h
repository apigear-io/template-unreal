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

#include "TbSame1SameStruct1InterfaceInterface.h"
#include "TbSame1SameStruct1InterfaceSimulationClient.generated.h"

UCLASS(BlueprintType)
class UTbSame1SameStruct1InterfaceSimulationClient : public UObject, public ITbSame1SameStruct1InterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTbSame1SameStruct1InterfaceSimulationClient();
	virtual ~UTbSame1SameStruct1InterfaceSimulationClient();

	// signals
	FTbSame1SameStruct1InterfaceSig1Delegate Sig1Signal;
	FTbSame1SameStruct1InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	FTbSame1SameStruct1InterfaceProp1ChangedDelegate Prop1Changed;
	FTbSame1SameStruct1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	// properties
	FTbSame1Struct1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const FTbSame1Struct1& Prop1) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1) override{};
	FTbSame1Struct1 Func1_Implementation(const FTbSame1Struct1& Param1) override;

protected:
	// signals
	void BroadcastSig1_Implementation(const FTbSame1Struct1& Param1) override;

	void BroadcastProp1Changed_Implementation(const FTbSame1Struct1& Prop1) override;

private:
	// properties - local copy
	FTbSame1Struct1 Prop1;
};
