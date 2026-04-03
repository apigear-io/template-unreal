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
#include "TbStructArray_data.h"
#include "TbStructArray/Generated/api/TbStructArrayStructArrayFieldInterfaceInterface.h"
#include "AbstractTbStructArrayStructArrayFieldInterface.generated.h"

/**
 * Abstract UAbstractTbStructArrayStructArrayFieldInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSTRUCTARRAYAPI_API UAbstractTbStructArrayStructArrayFieldInterface : public UGameInstanceSubsystem, public ITbStructArrayStructArrayFieldInterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbStructArrayStructArrayFieldInterface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbStructArrayStructArrayFieldInterfacePublisher* _GetPublisher() override;

	// methods
	virtual void FuncMixedAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbStructArrayMixedStruct& Result, const FTbStructArrayMixedStruct& ParamMixed) override;
	virtual TFuture<FTbStructArrayMixedStruct> FuncMixedAsync(const FTbStructArrayMixedStruct& ParamMixed) override;
	virtual FTbStructArrayMixedStruct FuncMixed(const FTbStructArrayMixedStruct& ParamMixed) override PURE_VIRTUAL(UAbstractTbStructArrayStructArrayFieldInterface::FuncMixed, return FTbStructArrayMixedStruct(););

	virtual void FuncStructArrayAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbStructArrayStructWithArrayOfStructs& Result, const FTbStructArrayStructWithArrayOfStructs& ParamPoints) override;
	virtual TFuture<FTbStructArrayStructWithArrayOfStructs> FuncStructArrayAsync(const FTbStructArrayStructWithArrayOfStructs& ParamPoints) override;
	virtual FTbStructArrayStructWithArrayOfStructs FuncStructArray(const FTbStructArrayStructWithArrayOfStructs& ParamPoints) override PURE_VIRTUAL(UAbstractTbStructArrayStructArrayFieldInterface::FuncStructArray, return FTbStructArrayStructWithArrayOfStructs(););

	// properties
	virtual FTbStructArrayStructWithArrayOfStructs GetPropStructArray() const override PURE_VIRTUAL(UAbstractTbStructArrayStructArrayFieldInterface::GetPropStructArray, return FTbStructArrayStructWithArrayOfStructs(););
	virtual void SetPropStructArray(const FTbStructArrayStructWithArrayOfStructs& InPropStructArray) override PURE_VIRTUAL(UAbstractTbStructArrayStructArrayFieldInterface::SetPropStructArray, return;);

	virtual FTbStructArrayStructWithArrayOfEnums GetPropEnumArray() const override PURE_VIRTUAL(UAbstractTbStructArrayStructArrayFieldInterface::GetPropEnumArray, return FTbStructArrayStructWithArrayOfEnums(););
	virtual void SetPropEnumArray(const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray) override PURE_VIRTUAL(UAbstractTbStructArrayStructArrayFieldInterface::SetPropEnumArray, return;);

	virtual FTbStructArrayStructWithArrayOfInts GetPropIntArray() const override PURE_VIRTUAL(UAbstractTbStructArrayStructArrayFieldInterface::GetPropIntArray, return FTbStructArrayStructWithArrayOfInts(););
	virtual void SetPropIntArray(const FTbStructArrayStructWithArrayOfInts& InPropIntArray) override PURE_VIRTUAL(UAbstractTbStructArrayStructArrayFieldInterface::SetPropIntArray, return;);

	virtual FTbStructArrayMixedStruct GetPropMixed() const override PURE_VIRTUAL(UAbstractTbStructArrayStructArrayFieldInterface::GetPropMixed, return FTbStructArrayMixedStruct(););
	virtual void SetPropMixed(const FTbStructArrayMixedStruct& InPropMixed) override PURE_VIRTUAL(UAbstractTbStructArrayStructArrayFieldInterface::SetPropMixed, return;);

	virtual bool IsInitialized() const;
	static void AddReferencedObjects(UObject* InThis, FReferenceCollector& Collector);

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropStructArray_Private, BlueprintSetter = SetPropStructArray_Private, Category = "ApiGear|TbStructArray|StructArrayFieldInterface")
	FTbStructArrayStructWithArrayOfStructs PropStructArray{FTbStructArrayStructWithArrayOfStructs()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Properties", BlueprintInternalUseOnly)
	FTbStructArrayStructWithArrayOfStructs GetPropStructArray_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Properties", BlueprintInternalUseOnly)
	void SetPropStructArray_Private(const FTbStructArrayStructWithArrayOfStructs& InPropStructArray);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropEnumArray_Private, BlueprintSetter = SetPropEnumArray_Private, Category = "ApiGear|TbStructArray|StructArrayFieldInterface")
	FTbStructArrayStructWithArrayOfEnums PropEnumArray{FTbStructArrayStructWithArrayOfEnums()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Properties", BlueprintInternalUseOnly)
	FTbStructArrayStructWithArrayOfEnums GetPropEnumArray_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Properties", BlueprintInternalUseOnly)
	void SetPropEnumArray_Private(const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropIntArray_Private, BlueprintSetter = SetPropIntArray_Private, Category = "ApiGear|TbStructArray|StructArrayFieldInterface")
	FTbStructArrayStructWithArrayOfInts PropIntArray{FTbStructArrayStructWithArrayOfInts()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Properties", BlueprintInternalUseOnly)
	FTbStructArrayStructWithArrayOfInts GetPropIntArray_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Properties", BlueprintInternalUseOnly)
	void SetPropIntArray_Private(const FTbStructArrayStructWithArrayOfInts& InPropIntArray);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropMixed_Private, BlueprintSetter = SetPropMixed_Private, Category = "ApiGear|TbStructArray|StructArrayFieldInterface")
	FTbStructArrayMixedStruct PropMixed{FTbStructArrayMixedStruct()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Properties", BlueprintInternalUseOnly)
	FTbStructArrayMixedStruct GetPropMixed_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbStructArray|StructArrayFieldInterface|Properties", BlueprintInternalUseOnly)
	void SetPropMixed_Private(const FTbStructArrayMixedStruct& InPropMixed);

private:
	// signals
	UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher;
};
