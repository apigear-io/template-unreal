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
#include "Testbed1_data.h"
#include "Testbed1/Generated/api/Testbed1StructArray2InterfaceInterface.h"
#include "AbstractTestbed1StructArray2Interface.generated.h"

/**
 * Abstract UAbstractTestbed1StructArray2Interface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TESTBED1API_API UAbstractTestbed1StructArray2Interface : public UGameInstanceSubsystem, public ITestbed1StructArray2InterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTestbed1StructArray2Interface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTestbed1StructArray2InterfacePublisher* _GetPublisher() override;

	// methods
	virtual void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructBool>& Result, const FTestbed1StructBoolWithArray& ParamBool) override;
	virtual TArray<FTestbed1StructBool> FuncBool(const FTestbed1StructBoolWithArray& ParamBool) override PURE_VIRTUAL(UAbstractTestbed1StructArray2Interface::FuncBool, return TArray<FTestbed1StructBool>(););

	virtual void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructInt>& Result, const FTestbed1StructIntWithArray& ParamInt) override;
	virtual TArray<FTestbed1StructInt> FuncInt(const FTestbed1StructIntWithArray& ParamInt) override PURE_VIRTUAL(UAbstractTestbed1StructArray2Interface::FuncInt, return TArray<FTestbed1StructInt>(););

	virtual void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructFloat>& Result, const FTestbed1StructFloatWithArray& ParamFloat) override;
	virtual TArray<FTestbed1StructFloat> FuncFloat(const FTestbed1StructFloatWithArray& ParamFloat) override PURE_VIRTUAL(UAbstractTestbed1StructArray2Interface::FuncFloat, return TArray<FTestbed1StructFloat>(););

	virtual void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructString>& Result, const FTestbed1StructStringWithArray& ParamString) override;
	virtual TArray<FTestbed1StructString> FuncString(const FTestbed1StructStringWithArray& ParamString) override PURE_VIRTUAL(UAbstractTestbed1StructArray2Interface::FuncString, return TArray<FTestbed1StructString>(););

	virtual void FuncEnumAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<ETestbed1Enum0>& Result, const FTestbed1StructEnumWithArray& ParamEnum) override;
	virtual TArray<ETestbed1Enum0> FuncEnum(const FTestbed1StructEnumWithArray& ParamEnum) override PURE_VIRTUAL(UAbstractTestbed1StructArray2Interface::FuncEnum, return TArray<ETestbed1Enum0>(););

	// properties
	virtual FTestbed1StructBoolWithArray GetPropBool() const override PURE_VIRTUAL(UAbstractTestbed1StructArray2Interface::GetPropBool, return FTestbed1StructBoolWithArray(););
	virtual void SetPropBool(const FTestbed1StructBoolWithArray& InPropBool) override PURE_VIRTUAL(UAbstractTestbed1StructArray2Interface::SetPropBool, return;);

	virtual FTestbed1StructIntWithArray GetPropInt() const override PURE_VIRTUAL(UAbstractTestbed1StructArray2Interface::GetPropInt, return FTestbed1StructIntWithArray(););
	virtual void SetPropInt(const FTestbed1StructIntWithArray& InPropInt) override PURE_VIRTUAL(UAbstractTestbed1StructArray2Interface::SetPropInt, return;);

	virtual FTestbed1StructFloatWithArray GetPropFloat() const override PURE_VIRTUAL(UAbstractTestbed1StructArray2Interface::GetPropFloat, return FTestbed1StructFloatWithArray(););
	virtual void SetPropFloat(const FTestbed1StructFloatWithArray& InPropFloat) override PURE_VIRTUAL(UAbstractTestbed1StructArray2Interface::SetPropFloat, return;);

	virtual FTestbed1StructStringWithArray GetPropString() const override PURE_VIRTUAL(UAbstractTestbed1StructArray2Interface::GetPropString, return FTestbed1StructStringWithArray(););
	virtual void SetPropString(const FTestbed1StructStringWithArray& InPropString) override PURE_VIRTUAL(UAbstractTestbed1StructArray2Interface::SetPropString, return;);

	virtual FTestbed1StructEnumWithArray GetPropEnum() const override PURE_VIRTUAL(UAbstractTestbed1StructArray2Interface::GetPropEnum, return FTestbed1StructEnumWithArray(););
	virtual void SetPropEnum(const FTestbed1StructEnumWithArray& InPropEnum) override PURE_VIRTUAL(UAbstractTestbed1StructArray2Interface::SetPropEnum, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|Testbed1|StructArray2Interface")
	FTestbed1StructBoolWithArray PropBool{FTestbed1StructBoolWithArray()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArray2Interface|Properties", BlueprintInternalUseOnly)
	FTestbed1StructBoolWithArray GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArray2Interface|Properties", BlueprintInternalUseOnly)
	void SetPropBool_Private(const FTestbed1StructBoolWithArray& InPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|Testbed1|StructArray2Interface")
	FTestbed1StructIntWithArray PropInt{FTestbed1StructIntWithArray()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArray2Interface|Properties", BlueprintInternalUseOnly)
	FTestbed1StructIntWithArray GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArray2Interface|Properties", BlueprintInternalUseOnly)
	void SetPropInt_Private(const FTestbed1StructIntWithArray& InPropInt);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|Testbed1|StructArray2Interface")
	FTestbed1StructFloatWithArray PropFloat{FTestbed1StructFloatWithArray()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArray2Interface|Properties", BlueprintInternalUseOnly)
	FTestbed1StructFloatWithArray GetPropFloat_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArray2Interface|Properties", BlueprintInternalUseOnly)
	void SetPropFloat_Private(const FTestbed1StructFloatWithArray& InPropFloat);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|Testbed1|StructArray2Interface")
	FTestbed1StructStringWithArray PropString{FTestbed1StructStringWithArray()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArray2Interface|Properties", BlueprintInternalUseOnly)
	FTestbed1StructStringWithArray GetPropString_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArray2Interface|Properties", BlueprintInternalUseOnly)
	void SetPropString_Private(const FTestbed1StructStringWithArray& InPropString);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropEnum_Private, BlueprintSetter = SetPropEnum_Private, Category = "ApiGear|Testbed1|StructArray2Interface")
	FTestbed1StructEnumWithArray PropEnum{FTestbed1StructEnumWithArray()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArray2Interface|Properties", BlueprintInternalUseOnly)
	FTestbed1StructEnumWithArray GetPropEnum_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArray2Interface|Properties", BlueprintInternalUseOnly)
	void SetPropEnum_Private(const FTestbed1StructEnumWithArray& InPropEnum);

private:
	// signals
	UPROPERTY()
	UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher;
};
