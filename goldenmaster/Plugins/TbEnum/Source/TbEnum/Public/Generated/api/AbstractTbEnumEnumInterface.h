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
#include "TbEnum_data.h"
#include "TbEnumEnumInterfaceInterface.h"
#include "AbstractTbEnumEnumInterface.generated.h"

/**
 * Abstract UAbstractTbEnumEnumInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBENUM_API UAbstractTbEnumEnumInterface : public UGameInstanceSubsystem, public ITbEnumEnumInterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbEnumEnumInterface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbEnumEnumInterfaceSignals* _GetSignals_Implementation() override;

	// methods
	virtual void Func0Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, ETbEnumEnum0 Param0) override;
	virtual ETbEnumEnum0 Func0_Implementation(ETbEnumEnum0 Param0) override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::Func0_Implementation, return ETbEnumEnum0::TEE_VALUE0;);

	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, ETbEnumEnum1 Param1) override;
	virtual ETbEnumEnum1 Func1_Implementation(ETbEnumEnum1 Param1) override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::Func1_Implementation, return ETbEnumEnum1::TEE_VALUE1;);

	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, ETbEnumEnum2 Param2) override;
	virtual ETbEnumEnum2 Func2_Implementation(ETbEnumEnum2 Param2) override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::Func2_Implementation, return ETbEnumEnum2::TEE_VALUE2;);

	virtual void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, ETbEnumEnum3 Param3) override;
	virtual ETbEnumEnum3 Func3_Implementation(ETbEnumEnum3 Param3) override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::Func3_Implementation, return ETbEnumEnum3::TEE_VALUE3;);

	// properties
	virtual ETbEnumEnum0 GetProp0_Implementation() const override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::GetProp0_Implementation, return ETbEnumEnum0::TEE_VALUE0;);
	virtual void SetProp0_Implementation(ETbEnumEnum0 InProp0) override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::SetProp0_Implementation, return;);

	virtual ETbEnumEnum1 GetProp1_Implementation() const override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::GetProp1_Implementation, return ETbEnumEnum1::TEE_VALUE1;);
	virtual void SetProp1_Implementation(ETbEnumEnum1 InProp1) override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::SetProp1_Implementation, return;);

	virtual ETbEnumEnum2 GetProp2_Implementation() const override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::GetProp2_Implementation, return ETbEnumEnum2::TEE_VALUE2;);
	virtual void SetProp2_Implementation(ETbEnumEnum2 InProp2) override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::SetProp2_Implementation, return;);

	virtual ETbEnumEnum3 GetProp3_Implementation() const override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::GetProp3_Implementation, return ETbEnumEnum3::TEE_VALUE3;);
	virtual void SetProp3_Implementation(ETbEnumEnum3 InProp3) override PURE_VIRTUAL(UAbstractTbEnumEnumInterface::SetProp3_Implementation, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp0_Private, BlueprintSetter = SetProp0_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum0 Prop0{ETbEnumEnum0::TEE_VALUE0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	ETbEnumEnum0 GetProp0_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	void SetProp0_Private(ETbEnumEnum0 InProp0);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum1 Prop1{ETbEnumEnum1::TEE_VALUE1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	ETbEnumEnum1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	void SetProp1_Private(ETbEnumEnum1 InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum2 Prop2{ETbEnumEnum2::TEE_VALUE2};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	ETbEnumEnum2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	void SetProp2_Private(ETbEnumEnum2 InProp2);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp3_Private, BlueprintSetter = SetProp3_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum3 Prop3{ETbEnumEnum3::TEE_VALUE3};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	ETbEnumEnum3 GetProp3_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface|Properties", BlueprintInternalUseOnly)
	void SetProp3_Private(ETbEnumEnum3 InProp3);

private:
	// signals
	UPROPERTY()
	UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals;
};
