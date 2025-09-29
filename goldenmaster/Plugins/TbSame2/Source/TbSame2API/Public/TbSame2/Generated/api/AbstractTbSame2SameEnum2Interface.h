/**
Copyright 2024 ApiGear UG
Copyright 2024 Epic Games, Inc.

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

#include "Runtime/Launch/Resources/Version.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSame2_data.h"
#include "TbSame2/Generated/api/TbSame2SameEnum2InterfaceInterface.h"
#include "AbstractTbSame2SameEnum2Interface.generated.h"

/**
 * Abstract UAbstractTbSame2SameEnum2Interface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSAME2API_API UAbstractTbSame2SameEnum2Interface : public UGameInstanceSubsystem, public ITbSame2SameEnum2InterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbSame2SameEnum2Interface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbSame2SameEnum2InterfacePublisher* _GetPublisher() override;

	// methods
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1) override;
	virtual TFuture<ETbSame2Enum1> Func1Async(ETbSame2Enum1 Param1) override;
	virtual ETbSame2Enum1 Func1(ETbSame2Enum1 Param1) override PURE_VIRTUAL(UAbstractTbSame2SameEnum2Interface::Func1, return ETbSame2Enum1::TS2E1_Value1;);

	virtual void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override;
	virtual TFuture<ETbSame2Enum1> Func2Async(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override;
	virtual ETbSame2Enum1 Func2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override PURE_VIRTUAL(UAbstractTbSame2SameEnum2Interface::Func2, return ETbSame2Enum1::TS2E1_Value1;);

	// properties
	virtual ETbSame2Enum1 GetProp1() const override PURE_VIRTUAL(UAbstractTbSame2SameEnum2Interface::GetProp1, return ETbSame2Enum1::TS2E1_Value1;);
	virtual void SetProp1(ETbSame2Enum1 InProp1) override PURE_VIRTUAL(UAbstractTbSame2SameEnum2Interface::SetProp1, return;);

	virtual ETbSame2Enum2 GetProp2() const override PURE_VIRTUAL(UAbstractTbSame2SameEnum2Interface::GetProp2, return ETbSame2Enum2::TS2E2_Value1;);
	virtual void SetProp2(ETbSame2Enum2 InProp2) override PURE_VIRTUAL(UAbstractTbSame2SameEnum2Interface::SetProp2, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame2|SameEnum2Interface")
	ETbSame2Enum1 Prop1{ETbSame2Enum1::TS2E1_Value1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties", BlueprintInternalUseOnly)
	ETbSame2Enum1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(ETbSame2Enum1 InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbSame2|SameEnum2Interface")
	ETbSame2Enum2 Prop2{ETbSame2Enum2::TS2E2_Value1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties", BlueprintInternalUseOnly)
	ETbSame2Enum2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties", BlueprintInternalUseOnly)
	void SetProp2_Private(ETbSame2Enum2 InProp2);

private:
	// signals
	UPROPERTY()
	UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher;
};
