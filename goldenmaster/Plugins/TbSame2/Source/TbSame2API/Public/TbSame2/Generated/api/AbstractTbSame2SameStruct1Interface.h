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
#include "TbSame2/Generated/api/TbSame2SameStruct1InterfaceInterface.h"
#include "AbstractTbSame2SameStruct1Interface.generated.h"

/**
 * Abstract UAbstractTbSame2SameStruct1Interface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSAME2API_API UAbstractTbSame2SameStruct1Interface : public UGameInstanceSubsystem, public ITbSame2SameStruct1InterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbSame2SameStruct1Interface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbSame2SameStruct1InterfacePublisher* _GetPublisher() override;

	// methods
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1) override;
	virtual FTbSame2Struct1 Func1(const FTbSame2Struct1& Param1) override PURE_VIRTUAL(UAbstractTbSame2SameStruct1Interface::Func1, return FTbSame2Struct1(););

	// properties
	virtual FTbSame2Struct1 GetProp1() const override PURE_VIRTUAL(UAbstractTbSame2SameStruct1Interface::GetProp1, return FTbSame2Struct1(););
	virtual void SetProp1(const FTbSame2Struct1& InProp1) override PURE_VIRTUAL(UAbstractTbSame2SameStruct1Interface::SetProp1, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame2|SameStruct1Interface")
	FTbSame2Struct1 Prop1{FTbSame2Struct1()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameStruct1Interface|Properties", BlueprintInternalUseOnly)
	FTbSame2Struct1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameStruct1Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTbSame2Struct1& InProp1);

private:
	// signals
	UPROPERTY()
	UTbSame2SameStruct1InterfacePublisher* TbSame2SameStruct1InterfacePublisher;
};
