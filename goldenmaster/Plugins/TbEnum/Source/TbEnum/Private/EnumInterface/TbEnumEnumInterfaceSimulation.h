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

#include "apig/TbEnum_apig.h"
#include "TbEnumEnumInterfaceSimulation.generated.h"

UCLASS(BlueprintType)
class UTbEnumEnumInterfaceSimulationService : public UObject, public ITbEnumEnumInterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTbEnumEnumInterfaceSimulationService();
	virtual ~UTbEnumEnumInterfaceSimulationService();

	// signals
	FTbEnumEnumInterfaceSig0Delegate Sig0Signal;
	FTbEnumEnumInterfaceSig0Delegate& GetSig0SignalDelegate() override;

	FTbEnumEnumInterfaceSig1Delegate Sig1Signal;
	FTbEnumEnumInterfaceSig1Delegate& GetSig1SignalDelegate() override;

	FTbEnumEnumInterfaceSig2Delegate Sig2Signal;
	FTbEnumEnumInterfaceSig2Delegate& GetSig2SignalDelegate() override;

	FTbEnumEnumInterfaceSig3Delegate Sig3Signal;
	FTbEnumEnumInterfaceSig3Delegate& GetSig3SignalDelegate() override;

	FTbEnumEnumInterfaceProp0ChangedDelegate Prop0Changed;
	FTbEnumEnumInterfaceProp0ChangedDelegate& GetProp0ChangedDelegate() override;

	FTbEnumEnumInterfaceProp1ChangedDelegate Prop1Changed;
	FTbEnumEnumInterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	FTbEnumEnumInterfaceProp2ChangedDelegate Prop2Changed;
	FTbEnumEnumInterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	FTbEnumEnumInterfaceProp3ChangedDelegate Prop3Changed;
	FTbEnumEnumInterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() override;

	// properties
	ETbEnumEnum0 GetProp0_Implementation() const override;
	void SetProp0_Implementation(const ETbEnumEnum0& Prop0) override;

	ETbEnumEnum1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const ETbEnumEnum1& Prop1) override;

	ETbEnumEnum2 GetProp2_Implementation() const override;
	void SetProp2_Implementation(const ETbEnumEnum2& Prop2) override;

	ETbEnumEnum3 GetProp3_Implementation() const override;
	void SetProp3_Implementation(const ETbEnumEnum3& Prop3) override;

	// operations
	void Func0Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, const ETbEnumEnum0& Param0) override{};
	ETbEnumEnum0 Func0_Implementation(const ETbEnumEnum0& Param0) override;

	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, const ETbEnumEnum1& Param1) override{};
	ETbEnumEnum1 Func1_Implementation(const ETbEnumEnum1& Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, const ETbEnumEnum2& Param2) override{};
	ETbEnumEnum2 Func2_Implementation(const ETbEnumEnum2& Param2) override;

	void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, const ETbEnumEnum3& Param3) override{};
	ETbEnumEnum3 Func3_Implementation(const ETbEnumEnum3& Param3) override;

protected:
	// signals
	void BroadcastSig0_Implementation(const ETbEnumEnum0& Param0) override;

	void BroadcastSig1_Implementation(const ETbEnumEnum1& Param1) override;

	void BroadcastSig2_Implementation(const ETbEnumEnum2& Param2) override;

	void BroadcastSig3_Implementation(const ETbEnumEnum3& Param3) override;

	void BroadcastProp0Changed_Implementation(const ETbEnumEnum0& Prop0) override;

	void BroadcastProp1Changed_Implementation(const ETbEnumEnum1& Prop1) override;

	void BroadcastProp2Changed_Implementation(const ETbEnumEnum2& Prop2) override;

	void BroadcastProp3Changed_Implementation(const ETbEnumEnum3& Prop3) override;

private:
	// properties - local copy
	ETbEnumEnum0 Prop0;
	ETbEnumEnum1 Prop1;
	ETbEnumEnum2 Prop2;
	ETbEnumEnum3 Prop3;
};
