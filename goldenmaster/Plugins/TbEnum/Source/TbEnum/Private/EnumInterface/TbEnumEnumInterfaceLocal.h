
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

#include "CoreMinimal.h"
#include "apig/TbEnum_apig.h"
#include "TbEnumEnumInterfaceLocal.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "TbEnumEnumInterface")
class TBENUM_API UTbEnumEnumInterfaceLocalService : public UObject, public ITbEnumEnumInterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTbEnumEnumInterfaceLocalService();
	virtual ~UTbEnumEnumInterfaceLocalService();

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
	void GetProp0_Implementation(ETbEnumEnum0& ReturnValue) const override;
	void SetProp0_Implementation(const ETbEnumEnum0& Prop0) override;

	void GetProp1_Implementation(ETbEnumEnum1& ReturnValue) const override;
	void SetProp1_Implementation(const ETbEnumEnum1& Prop1) override;

	void GetProp2_Implementation(ETbEnumEnum2& ReturnValue) const override;
	void SetProp2_Implementation(const ETbEnumEnum2& Prop2) override;

	void GetProp3_Implementation(ETbEnumEnum3& ReturnValue) const override;
	void SetProp3_Implementation(const ETbEnumEnum3& Prop3) override;

	// operations
	void Func0Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, const ETbEnumEnum0& Param0) override{};
	void Func0_Implementation(ETbEnumEnum0& Result, const ETbEnumEnum0& Param0) override;

	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, const ETbEnumEnum1& Param1) override{};
	void Func1_Implementation(ETbEnumEnum1& Result, const ETbEnumEnum1& Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, const ETbEnumEnum2& Param2) override{};
	void Func2_Implementation(ETbEnumEnum2& Result, const ETbEnumEnum2& Param2) override;

	void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, const ETbEnumEnum3& Param3) override{};
	void Func3_Implementation(ETbEnumEnum3& Result, const ETbEnumEnum3& Param3) override;

private:
	// properties - local copy - use setter functions to emit changed signals
	ETbEnumEnum0 Prop0;
	ETbEnumEnum1 Prop1;
	ETbEnumEnum2 Prop2;
	ETbEnumEnum3 Prop3;
};
