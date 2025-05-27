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
#include "Generated/api/TbSame1_data.h"
#include "Generated/api/TbSame1SameEnum2InterfaceInterface.h"
#include "AbstractTbSame1SameEnum2Interface.generated.h"

/**
 * Abstract UAbstractTbSame1SameEnum2Interface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSAME1_API UAbstractTbSame1SameEnum2Interface : public UGameInstanceSubsystem, public ITbSame1SameEnum2InterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbSame1SameEnum2Interface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbSame1SameEnum2InterfaceSignals* _GetSignals_Implementation() override;

	// methods
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1) override;
	virtual ETbSame1Enum1 Func1_Implementation(ETbSame1Enum1 Param1) override PURE_VIRTUAL(UAbstractTbSame1SameEnum2Interface::Func1_Implementation, return ETbSame1Enum1::TS1E1_Value1;);

	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1, ETbSame1Enum2 Param2) override;
	virtual ETbSame1Enum1 Func2_Implementation(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2) override PURE_VIRTUAL(UAbstractTbSame1SameEnum2Interface::Func2_Implementation, return ETbSame1Enum1::TS1E1_Value1;);

	// properties
	virtual ETbSame1Enum1 GetProp1_Implementation() const override PURE_VIRTUAL(UAbstractTbSame1SameEnum2Interface::GetProp1_Implementation, return ETbSame1Enum1::TS1E1_Value1;);
	virtual void SetProp1_Implementation(ETbSame1Enum1 InProp1) override PURE_VIRTUAL(UAbstractTbSame1SameEnum2Interface::SetProp1_Implementation, return;);

	virtual ETbSame1Enum2 GetProp2_Implementation() const override PURE_VIRTUAL(UAbstractTbSame1SameEnum2Interface::GetProp2_Implementation, return ETbSame1Enum2::TS1E2_Value1;);
	virtual void SetProp2_Implementation(ETbSame1Enum2 InProp2) override PURE_VIRTUAL(UAbstractTbSame1SameEnum2Interface::SetProp2_Implementation, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame1|SameEnum2Interface")
	ETbSame1Enum1 Prop1{ETbSame1Enum1::TS1E1_Value1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame1|SameEnum2Interface|Properties", BlueprintInternalUseOnly)
	ETbSame1Enum1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame1|SameEnum2Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(ETbSame1Enum1 InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbSame1|SameEnum2Interface")
	ETbSame1Enum2 Prop2{ETbSame1Enum2::TS1E2_Value1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame1|SameEnum2Interface|Properties", BlueprintInternalUseOnly)
	ETbSame1Enum2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame1|SameEnum2Interface|Properties", BlueprintInternalUseOnly)
	void SetProp2_Private(ETbSame1Enum2 InProp2);

private:
	// signals
	UPROPERTY()
	UTbSame1SameEnum2InterfaceSignals* TbSame1SameEnum2InterfaceSignals;
};
