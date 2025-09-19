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
#include "TbEnum_data.h"
#include "TbEnum/Generated/api/TbEnumEnumInterfaceInterface.h"
#include "AbstractTbEnumEnumInterface.generated.h"

/**
 * Abstract UAbstractTbEnumEnumInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBENUMAPI_API UAbstractTbEnumEnumInterface : public UGameInstanceSubsystem, public ITbEnumEnumInterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbEnumEnumInterface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbEnumEnumInterfacePublisher* _GetPublisher() override;

	// methods
	virtual void Func0Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, ETbEnumEnum0 Param0) override;
	virtual ETbEnumEnum0 Func0(ETbEnumEnum0 Param0) override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::Func0, return ETbEnumEnum0::TEE0_Value0;);

	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, ETbEnumEnum1 Param1) override;
	virtual ETbEnumEnum1 Func1(ETbEnumEnum1 Param1) override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::Func1, return ETbEnumEnum1::TEE1_Value1;);

	virtual void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, ETbEnumEnum2 Param2) override;
	virtual ETbEnumEnum2 Func2(ETbEnumEnum2 Param2) override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::Func2, return ETbEnumEnum2::TEE2_Value2;);

	virtual void Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, ETbEnumEnum3 Param3) override;
	virtual ETbEnumEnum3 Func3(ETbEnumEnum3 Param3) override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::Func3, return ETbEnumEnum3::TEE3_Value3;);

	// properties
	virtual ETbEnumEnum0 GetProp0() const override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::GetProp0, return ETbEnumEnum0::TEE0_Value0;);
	virtual void SetProp0(ETbEnumEnum0 InProp0) override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::SetProp0, return;);

	virtual ETbEnumEnum1 GetProp1() const override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::GetProp1, return ETbEnumEnum1::TEE1_Value1;);
	virtual void SetProp1(ETbEnumEnum1 InProp1) override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::SetProp1, return;);

	virtual ETbEnumEnum2 GetProp2() const override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::GetProp2, return ETbEnumEnum2::TEE2_Value2;);
	virtual void SetProp2(ETbEnumEnum2 InProp2) override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::SetProp2, return;);

	virtual ETbEnumEnum3 GetProp3() const override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::GetProp3, return ETbEnumEnum3::TEE3_Value3;);
	virtual void SetProp3(ETbEnumEnum3 InProp3) override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::SetProp3, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp0_Private, BlueprintSetter = SetProp0_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum0 Prop0{ETbEnumEnum0::TEE0_Value0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	ETbEnumEnum0 GetProp0_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	void SetProp0_Private(ETbEnumEnum0 InProp0);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum1 Prop1{ETbEnumEnum1::TEE1_Value1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	ETbEnumEnum1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(ETbEnumEnum1 InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum2 Prop2{ETbEnumEnum2::TEE2_Value2};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	ETbEnumEnum2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	void SetProp2_Private(ETbEnumEnum2 InProp2);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp3_Private, BlueprintSetter = SetProp3_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum3 Prop3{ETbEnumEnum3::TEE3_Value3};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	ETbEnumEnum3 GetProp3_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	void SetProp3_Private(ETbEnumEnum3 InProp3);

private:
	// signals
	UPROPERTY()
	UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher;
};
