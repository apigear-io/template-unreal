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
#include "TbSame2/Generated/api/TbSame2SameStruct2InterfaceInterface.h"
#include "AbstractTbSame2SameStruct2Interface.generated.h"

/**
 * Abstract UAbstractTbSame2SameStruct2Interface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSAME2API_API UAbstractTbSame2SameStruct2Interface : public UGameInstanceSubsystem, public ITbSame2SameStruct2InterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbSame2SameStruct2Interface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbSame2SameStruct2InterfacePublisher* _GetPublisher() override;

	// methods
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1) override;
	virtual TFuture<FTbSame2Struct1> Func1Async(const FTbSame2Struct1& Param1) override;
	virtual FTbSame2Struct1 Func1(const FTbSame2Struct1& Param1) override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::Func1, return FTbSame2Struct1(););

	virtual void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override;
	virtual TFuture<FTbSame2Struct1> Func2Async(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override;
	virtual FTbSame2Struct1 Func2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::Func2, return FTbSame2Struct1(););

	// properties
	virtual FTbSame2Struct2 GetProp1() const override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::GetProp1, return FTbSame2Struct2(););
	virtual void SetProp1(const FTbSame2Struct2& InProp1) override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::SetProp1, return;);

	virtual FTbSame2Struct2 GetProp2() const override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::GetProp2, return FTbSame2Struct2(););
	virtual void SetProp2(const FTbSame2Struct2& InProp2) override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::SetProp2, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame2|SameStruct2Interface")
	FTbSame2Struct2 Prop1{FTbSame2Struct2()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameStruct2Interface|Properties", BlueprintInternalUseOnly)
	FTbSame2Struct2 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameStruct2Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTbSame2Struct2& InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbSame2|SameStruct2Interface")
	FTbSame2Struct2 Prop2{FTbSame2Struct2()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameStruct2Interface|Properties", BlueprintInternalUseOnly)
	FTbSame2Struct2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameStruct2Interface|Properties", BlueprintInternalUseOnly)
	void SetProp2_Private(const FTbSame2Struct2& InProp2);

private:
	// signals
	UPROPERTY()
	UTbSame2SameStruct2InterfacePublisher* TbSame2SameStruct2InterfacePublisher;
};
