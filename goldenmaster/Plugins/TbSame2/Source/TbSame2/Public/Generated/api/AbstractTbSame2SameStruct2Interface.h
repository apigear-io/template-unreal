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
#include "TbSame2SameStruct2InterfaceInterface.h"
#include "AbstractTbSame2SameStruct2Interface.generated.h"

/**
 * Abstract UAbstractTbSame2SameStruct2Interface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSAME2_API UAbstractTbSame2SameStruct2Interface : public UGameInstanceSubsystem, public ITbSame2SameStruct2InterfaceInterface
{
	GENERATED_BODY()

public:
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface", DisplayName = "Sig1 Signal")
	FTbSame2SameStruct2InterfaceSig1Delegate Sig1Signal;
	virtual FTbSame2SameStruct2InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface", DisplayName = "Sig2 Signal")
	FTbSame2SameStruct2InterfaceSig2Delegate Sig2Signal;
	virtual FTbSame2SameStruct2InterfaceSig2Delegate& GetSig2SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface", DisplayName = "Prop1 Changed")
	FTbSame2SameStruct2InterfaceProp1ChangedDelegate Prop1Changed;
	virtual FTbSame2SameStruct2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface", DisplayName = "Prop2 Changed")
	FTbSame2SameStruct2InterfaceProp2ChangedDelegate Prop2Changed;
	virtual FTbSame2SameStruct2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	// methods
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1) override;
	virtual FTbSame2Struct1 Func1_Implementation(const FTbSame2Struct1& Param1) override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::Func1_Implementation, return FTbSame2Struct1(););

	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override;
	virtual FTbSame2Struct1 Func2_Implementation(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::Func2_Implementation, return FTbSame2Struct1(););

	// properties
	virtual FTbSame2Struct2 GetProp1_Implementation() const override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::GetProp1_Implementation, return FTbSame2Struct2(););
	virtual void SetProp1_Implementation(const FTbSame2Struct2& InProp1) override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::SetProp1_Implementation, return;);

	virtual FTbSame2Struct2 GetProp2_Implementation() const override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::GetProp2_Implementation, return FTbSame2Struct2(););
	virtual void SetProp2_Implementation(const FTbSame2Struct2& InProp2) override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::SetProp2_Implementation, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;
	// signals
	virtual void BroadcastSig1_Implementation(const FTbSame2Struct1& Param1) override;

	virtual void BroadcastSig2_Implementation(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override;

	virtual void BroadcastProp1Changed_Implementation(const FTbSame2Struct2& InProp1) override;

	virtual void BroadcastProp2Changed_Implementation(const FTbSame2Struct2& InProp2) override;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame2|SameStruct2Interface")
	FTbSame2Struct2 Prop1{FTbSame2Struct2()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameStruct2Interface", BlueprintInternalUseOnly)
	FTbSame2Struct2 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameStruct2Interface", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTbSame2Struct2& InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbSame2|SameStruct2Interface")
	FTbSame2Struct2 Prop2{FTbSame2Struct2()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameStruct2Interface", BlueprintInternalUseOnly)
	FTbSame2Struct2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameStruct2Interface", BlueprintInternalUseOnly)
	void SetProp2_Private(const FTbSame2Struct2& InProp2);
};
