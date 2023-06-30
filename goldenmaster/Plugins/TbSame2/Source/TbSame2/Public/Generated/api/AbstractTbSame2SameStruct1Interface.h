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

#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSame2_data.h"
#include "TbSame2SameStruct1InterfaceInterface.h"
#include "AbstractTbSame2SameStruct1Interface.generated.h"

/**
 * Abstract UAbstractTbSame2SameStruct1Interface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSAME2_API UAbstractTbSame2SameStruct1Interface : public UGameInstanceSubsystem, public ITbSame2SameStruct1InterfaceInterface
{
	GENERATED_BODY()

public:
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct1Interface", DisplayName = "Sig1 Signal")
	FTbSame2SameStruct1InterfaceSig1Delegate Sig1Signal;
	virtual FTbSame2SameStruct1InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct1Interface", DisplayName = "Prop1 Changed")
	FTbSame2SameStruct1InterfaceProp1ChangedDelegate Prop1Changed;
	virtual FTbSame2SameStruct1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	// methods
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1) override;
	virtual FTbSame2Struct1 Func1_Implementation(const FTbSame2Struct1& Param1) override PURE_VIRTUAL(UAbstractTbSame2SameStruct1Interface::Func1_Implementation, return FTbSame2Struct1(););

	// properties
	virtual FTbSame2Struct1 GetProp1_Implementation() const override PURE_VIRTUAL(UAbstractTbSame2SameStruct1Interface::GetProp1_Implementation, return FTbSame2Struct1(););
	virtual void SetProp1_Implementation(const FTbSame2Struct1& InProp1) override PURE_VIRTUAL(UAbstractTbSame2SameStruct1Interface::SetProp1_Implementation, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;
	// signals
	virtual void BroadcastSig1_Implementation(const FTbSame2Struct1& Param1) override;

	virtual void BroadcastProp1Changed_Implementation(const FTbSame2Struct1& InProp1) override;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame2|SameStruct1Interface")
	FTbSame2Struct1 Prop1{FTbSame2Struct1()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameStruct1Interface", BlueprintInternalUseOnly)
	FTbSame2Struct1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameStruct1Interface", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTbSame2Struct1& InProp1);
};
