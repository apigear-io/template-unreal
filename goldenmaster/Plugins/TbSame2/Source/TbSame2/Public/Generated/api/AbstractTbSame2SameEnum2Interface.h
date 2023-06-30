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
#include "TbSame2SameEnum2InterfaceInterface.h"
#include "AbstractTbSame2SameEnum2Interface.generated.h"

/**
 * Abstract UAbstractTbSame2SameEnum2Interface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSAME2_API UAbstractTbSame2SameEnum2Interface : public UGameInstanceSubsystem, public ITbSame2SameEnum2InterfaceInterface
{
	GENERATED_BODY()

public:
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface", DisplayName = "Sig1 Signal")
	FTbSame2SameEnum2InterfaceSig1Delegate Sig1Signal;
	virtual FTbSame2SameEnum2InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface", DisplayName = "Sig2 Signal")
	FTbSame2SameEnum2InterfaceSig2Delegate Sig2Signal;
	virtual FTbSame2SameEnum2InterfaceSig2Delegate& GetSig2SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface", DisplayName = "Prop1 Changed")
	FTbSame2SameEnum2InterfaceProp1ChangedDelegate Prop1Changed;
	virtual FTbSame2SameEnum2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface", DisplayName = "Prop2 Changed")
	FTbSame2SameEnum2InterfaceProp2ChangedDelegate Prop2Changed;
	virtual FTbSame2SameEnum2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	// methods
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1) override;
	virtual ETbSame2Enum1 Func1_Implementation(ETbSame2Enum1 Param1) override PURE_VIRTUAL(UAbstractTbSame2SameEnum2Interface::Func1_Implementation, return ETbSame2Enum1::TSE_VALUE1;);

	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override;
	virtual ETbSame2Enum1 Func2_Implementation(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override PURE_VIRTUAL(UAbstractTbSame2SameEnum2Interface::Func2_Implementation, return ETbSame2Enum1::TSE_VALUE1;);

	// properties
	virtual ETbSame2Enum1 GetProp1_Implementation() const override PURE_VIRTUAL(UAbstractTbSame2SameEnum2Interface::GetProp1_Implementation, return ETbSame2Enum1::TSE_VALUE1;);
	virtual void SetProp1_Implementation(ETbSame2Enum1 InProp1) override PURE_VIRTUAL(UAbstractTbSame2SameEnum2Interface::SetProp1_Implementation, return;);

	virtual ETbSame2Enum2 GetProp2_Implementation() const override PURE_VIRTUAL(UAbstractTbSame2SameEnum2Interface::GetProp2_Implementation, return ETbSame2Enum2::TSE_VALUE1;);
	virtual void SetProp2_Implementation(ETbSame2Enum2 InProp2) override PURE_VIRTUAL(UAbstractTbSame2SameEnum2Interface::SetProp2_Implementation, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;
	// signals
	virtual void BroadcastSig1_Implementation(ETbSame2Enum1 Param1) override;

	virtual void BroadcastSig2_Implementation(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override;

	virtual void BroadcastProp1Changed_Implementation(ETbSame2Enum1 InProp1) override;

	virtual void BroadcastProp2Changed_Implementation(ETbSame2Enum2 InProp2) override;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame2|SameEnum2Interface")
	ETbSame2Enum1 Prop1{ETbSame2Enum1::TSE_VALUE1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	ETbSame2Enum1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	void SetProp1_Private(ETbSame2Enum1 InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbSame2|SameEnum2Interface")
	ETbSame2Enum2 Prop2{ETbSame2Enum2::TSE_VALUE1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	ETbSame2Enum2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameEnum2Interface", BlueprintInternalUseOnly)
	void SetProp2_Private(ETbSame2Enum2 InProp2);
};
