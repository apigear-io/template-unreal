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
#include "TbSame1_data.h"
#include "TbSame1/Generated/api/TbSame1SameStruct2InterfaceInterface.h"
#include "AbstractTbSame1SameStruct2Interface.generated.h"

/**
 * Abstract UAbstractTbSame1SameStruct2Interface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSAME1API_API UAbstractTbSame1SameStruct2Interface : public UGameInstanceSubsystem, public ITbSame1SameStruct2InterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbSame1SameStruct2Interface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbSame1SameStruct2InterfacePublisher* _GetPublisher() override;

	// methods
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1) override;
	virtual FTbSame1Struct1 Func1(const FTbSame1Struct1& Param1) override PURE_VIRTUAL(UAbstractTbSame1SameStruct2Interface::Func1, return FTbSame1Struct1(););

	virtual void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override;
	virtual FTbSame1Struct1 Func2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override PURE_VIRTUAL(UAbstractTbSame1SameStruct2Interface::Func2, return FTbSame1Struct1(););

	// properties
	virtual FTbSame1Struct2 GetProp1() const override PURE_VIRTUAL(UAbstractTbSame1SameStruct2Interface::GetProp1, return FTbSame1Struct2(););
	virtual void SetProp1(const FTbSame1Struct2& InProp1) override PURE_VIRTUAL(UAbstractTbSame1SameStruct2Interface::SetProp1, return;);

	virtual FTbSame1Struct2 GetProp2() const override PURE_VIRTUAL(UAbstractTbSame1SameStruct2Interface::GetProp2, return FTbSame1Struct2(););
	virtual void SetProp2(const FTbSame1Struct2& InProp2) override PURE_VIRTUAL(UAbstractTbSame1SameStruct2Interface::SetProp2, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame1|SameStruct2Interface")
	FTbSame1Struct2 Prop1{FTbSame1Struct2()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame1|SameStruct2Interface|Properties", BlueprintInternalUseOnly)
	FTbSame1Struct2 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame1|SameStruct2Interface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTbSame1Struct2& InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbSame1|SameStruct2Interface")
	FTbSame1Struct2 Prop2{FTbSame1Struct2()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame1|SameStruct2Interface|Properties", BlueprintInternalUseOnly)
	FTbSame1Struct2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame1|SameStruct2Interface|Properties", BlueprintInternalUseOnly)
	void SetProp2_Private(const FTbSame1Struct2& InProp2);

private:
	// signals
	UPROPERTY()
	UTbSame1SameStruct2InterfacePublisher* TbSame1SameStruct2InterfacePublisher;
};
