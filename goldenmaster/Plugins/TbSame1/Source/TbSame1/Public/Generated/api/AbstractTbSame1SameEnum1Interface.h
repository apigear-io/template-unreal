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

#include "Runtime/Launch/Resources/Version.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSame1_data.h"
#include "TbSame1SameEnum1InterfaceInterface.h"
#include "AbstractTbSame1SameEnum1Interface.generated.h"

/**
 * Abstract UAbstractTbSame1SameEnum1Interface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSAME1_API UAbstractTbSame1SameEnum1Interface : public UGameInstanceSubsystem, public ITbSame1SameEnum1InterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbSame1SameEnum1Interface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbSame1SameEnum1InterfaceSignals* _GetSignals_Implementation() override
	{
		return TbSame1SameEnum1InterfaceSignals;
	};

	// methods
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame1Enum1& Result, ETbSame1Enum1 Param1) override;
	virtual ETbSame1Enum1 Func1_Implementation(ETbSame1Enum1 Param1) override PURE_VIRTUAL(UAbstractTbSame1SameEnum1Interface::Func1_Implementation, return ETbSame1Enum1::TSE_VALUE1;);

	// properties
	virtual ETbSame1Enum1 GetProp1_Implementation() const override PURE_VIRTUAL(UAbstractTbSame1SameEnum1Interface::GetProp1_Implementation, return ETbSame1Enum1::TSE_VALUE1;);
	virtual void SetProp1_Implementation(ETbSame1Enum1 InProp1) override PURE_VIRTUAL(UAbstractTbSame1SameEnum1Interface::SetProp1_Implementation, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame1|SameEnum1Interface")
	ETbSame1Enum1 Prop1{ETbSame1Enum1::TSE_VALUE1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame1|SameEnum1Interface|Properties", BlueprintInternalUseOnly)
	ETbSame1Enum1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame1|SameEnum1Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(ETbSame1Enum1 InProp1);

private:
	// signals
	UPROPERTY()
	UTbSame1SameEnum1InterfaceSignals* TbSame1SameEnum1InterfaceSignals;
};
