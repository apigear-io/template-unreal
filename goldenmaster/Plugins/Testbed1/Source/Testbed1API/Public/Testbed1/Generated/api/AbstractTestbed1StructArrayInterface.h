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
#include "Testbed1/Generated/api/Testbed1StructArrayInterfaceInterface.h"
#include "AbstractTestbed1StructArrayInterface.generated.h"

/**
 * Abstract UAbstractTestbed1StructArrayInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TESTBED1API_API UAbstractTestbed1StructArrayInterface : public UGameInstanceSubsystem, public ITestbed1StructArrayInterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTestbed1StructArrayInterface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTestbed1StructArrayInterfacePublisher* _GetPublisher() override;

	// methods
	virtual void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructBool>& Result, const TArray<FTestbed1StructBool>& ParamBool) override;
	virtual TArray<FTestbed1StructBool> FuncBool(const TArray<FTestbed1StructBool>& ParamBool) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::FuncBool, return TArray<FTestbed1StructBool>(););

	virtual void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructInt>& Result, const TArray<FTestbed1StructInt>& ParamInt) override;
	virtual TArray<FTestbed1StructInt> FuncInt(const TArray<FTestbed1StructInt>& ParamInt) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::FuncInt, return TArray<FTestbed1StructInt>(););

	virtual void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructFloat>& Result, const TArray<FTestbed1StructFloat>& ParamFloat) override;
	virtual TArray<FTestbed1StructFloat> FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::FuncFloat, return TArray<FTestbed1StructFloat>(););

	virtual void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructString>& Result, const TArray<FTestbed1StructString>& ParamString) override;
	virtual TArray<FTestbed1StructString> FuncString(const TArray<FTestbed1StructString>& ParamString) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::FuncString, return TArray<FTestbed1StructString>(););

	virtual void FuncEnumAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<ETestbed1Enum0>& Result, const TArray<ETestbed1Enum0>& ParamEnum) override;
	virtual TArray<ETestbed1Enum0> FuncEnum(const TArray<ETestbed1Enum0>& ParamEnum) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::FuncEnum, return TArray<ETestbed1Enum0>(););

	// properties
	virtual TArray<FTestbed1StructBool> GetPropBool() const override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::GetPropBool, return TArray<FTestbed1StructBool>(););
	virtual void SetPropBool(const TArray<FTestbed1StructBool>& InPropBool) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::SetPropBool, return;);

	virtual TArray<FTestbed1StructInt> GetPropInt() const override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::GetPropInt, return TArray<FTestbed1StructInt>(););
	virtual void SetPropInt(const TArray<FTestbed1StructInt>& InPropInt) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::SetPropInt, return;);

	virtual TArray<FTestbed1StructFloat> GetPropFloat() const override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::GetPropFloat, return TArray<FTestbed1StructFloat>(););
	virtual void SetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::SetPropFloat, return;);

	virtual TArray<FTestbed1StructString> GetPropString() const override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::GetPropString, return TArray<FTestbed1StructString>(););
	virtual void SetPropString(const TArray<FTestbed1StructString>& InPropString) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::SetPropString, return;);

	virtual TArray<ETestbed1Enum0> GetPropEnum() const override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::GetPropEnum, return TArray<ETestbed1Enum0>(););
	virtual void SetPropEnum(const TArray<ETestbed1Enum0>& InPropEnum) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::SetPropEnum, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructBool> PropBool{TArray<FTestbed1StructBool>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<FTestbed1StructBool> GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropBool_Private(const TArray<FTestbed1StructBool>& InPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructInt> PropInt{TArray<FTestbed1StructInt>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<FTestbed1StructInt> GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropInt_Private(const TArray<FTestbed1StructInt>& InPropInt);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructFloat> PropFloat{TArray<FTestbed1StructFloat>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<FTestbed1StructFloat> GetPropFloat_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropFloat_Private(const TArray<FTestbed1StructFloat>& InPropFloat);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructString> PropString{TArray<FTestbed1StructString>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<FTestbed1StructString> GetPropString_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropString_Private(const TArray<FTestbed1StructString>& InPropString);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropEnum_Private, BlueprintSetter = SetPropEnum_Private, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<ETestbed1Enum0> PropEnum{TArray<ETestbed1Enum0>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArrayInterface|Properties", BlueprintInternalUseOnly)
	TArray<ETestbed1Enum0> GetPropEnum_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArrayInterface|Properties", BlueprintInternalUseOnly)
	void SetPropEnum_Private(const TArray<ETestbed1Enum0>& InPropEnum);

private:
	// signals
	UPROPERTY()
	UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher;
};
