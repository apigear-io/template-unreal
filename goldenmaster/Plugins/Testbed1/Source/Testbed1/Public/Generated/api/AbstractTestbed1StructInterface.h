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

#include "Subsystems/GameInstanceSubsystem.h"
#include "Testbed1_data.h"
#include "Testbed1StructInterfaceInterface.h"
#include "AbstractTestbed1StructInterface.generated.h"

/**
 * Abstract UAbstractTestbed1StructInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TESTBED1_API UAbstractTestbed1StructInterface : public UGameInstanceSubsystem, public ITestbed1StructInterfaceInterface
{
	GENERATED_BODY()

public:
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "SigBool Signal")
	FTestbed1StructInterfaceSigBoolDelegate SigBoolSignal;
	virtual FTestbed1StructInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "SigInt Signal")
	FTestbed1StructInterfaceSigIntDelegate SigIntSignal;
	virtual FTestbed1StructInterfaceSigIntDelegate& GetSigIntSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "SigFloat Signal")
	FTestbed1StructInterfaceSigFloatDelegate SigFloatSignal;
	virtual FTestbed1StructInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "SigString Signal")
	FTestbed1StructInterfaceSigStringDelegate SigStringSignal;
	virtual FTestbed1StructInterfaceSigStringDelegate& GetSigStringSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "PropBool Changed")
	FTestbed1StructInterfacePropBoolChangedDelegate PropBoolChanged;
	virtual FTestbed1StructInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "PropInt Changed")
	FTestbed1StructInterfacePropIntChangedDelegate PropIntChanged;
	virtual FTestbed1StructInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "PropFloat Changed")
	FTestbed1StructInterfacePropFloatChangedDelegate PropFloatChanged;
	virtual FTestbed1StructInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "PropString Changed")
	FTestbed1StructInterfacePropStringChangedDelegate PropStringChanged;
	virtual FTestbed1StructInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override;

	// methods
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool) override;
	virtual FTestbed1StructBool FuncBool_Implementation(const FTestbed1StructBool& ParamBool) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::FuncBool_Implementation, return FTestbed1StructBool(););

	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructInt& ParamInt) override;
	virtual FTestbed1StructBool FuncInt_Implementation(const FTestbed1StructInt& ParamInt) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::FuncInt_Implementation, return FTestbed1StructBool(););

	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat) override;
	virtual FTestbed1StructFloat FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::FuncFloat_Implementation, return FTestbed1StructFloat(););

	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString) override;
	virtual FTestbed1StructString FuncString_Implementation(const FTestbed1StructString& ParamString) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::FuncString_Implementation, return FTestbed1StructString(););

	// properties
	virtual FTestbed1StructBool GetPropBool_Implementation() const override PURE_VIRTUAL(UAbstractTestbed1StructInterface::GetPropBool_Implementation, return FTestbed1StructBool(););
	virtual void SetPropBool_Implementation(const FTestbed1StructBool& InPropBool) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::SetPropBool_Implementation, return;);

	virtual FTestbed1StructInt GetPropInt_Implementation() const override PURE_VIRTUAL(UAbstractTestbed1StructInterface::GetPropInt_Implementation, return FTestbed1StructInt(););
	virtual void SetPropInt_Implementation(const FTestbed1StructInt& InPropInt) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::SetPropInt_Implementation, return;);

	virtual FTestbed1StructFloat GetPropFloat_Implementation() const override PURE_VIRTUAL(UAbstractTestbed1StructInterface::GetPropFloat_Implementation, return FTestbed1StructFloat(););
	virtual void SetPropFloat_Implementation(const FTestbed1StructFloat& InPropFloat) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::SetPropFloat_Implementation, return;);

	virtual FTestbed1StructString GetPropString_Implementation() const override PURE_VIRTUAL(UAbstractTestbed1StructInterface::GetPropString_Implementation, return FTestbed1StructString(););
	virtual void SetPropString_Implementation(const FTestbed1StructString& InPropString) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::SetPropString_Implementation, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;
	// signals
	virtual void BroadcastSigBool_Implementation(const FTestbed1StructBool& ParamBool) override;

	virtual void BroadcastSigInt_Implementation(const FTestbed1StructInt& ParamInt) override;

	virtual void BroadcastSigFloat_Implementation(const FTestbed1StructFloat& ParamFloat) override;

	virtual void BroadcastSigString_Implementation(const FTestbed1StructString& ParamString) override;

	virtual void BroadcastPropBoolChanged_Implementation(const FTestbed1StructBool& InPropBool) override;

	virtual void BroadcastPropIntChanged_Implementation(const FTestbed1StructInt& InPropInt) override;

	virtual void BroadcastPropFloatChanged_Implementation(const FTestbed1StructFloat& InPropFloat) override;

	virtual void BroadcastPropStringChanged_Implementation(const FTestbed1StructString& InPropString) override;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructBool PropBool{FTestbed1StructBool()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	FTestbed1StructBool GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	void SetPropBool_Private(const FTestbed1StructBool& InPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructInt PropInt{FTestbed1StructInt()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	FTestbed1StructInt GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	void SetPropInt_Private(const FTestbed1StructInt& InPropInt);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructFloat PropFloat{FTestbed1StructFloat()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	FTestbed1StructFloat GetPropFloat_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	void SetPropFloat_Private(const FTestbed1StructFloat& InPropFloat);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructString PropString{FTestbed1StructString()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	FTestbed1StructString GetPropString_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface|Properties", BlueprintInternalUseOnly)
	void SetPropString_Private(const FTestbed1StructString& InPropString);
};
