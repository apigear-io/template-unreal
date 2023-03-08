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

#include "UObject/Interface.h"
#include "Engine/LatentActionManager.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Testbed2_data.h"
#include "Testbed2NestedStruct1InterfaceInterface.generated.h"

/**
 * Declaration for NestedStruct1Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct1InterfaceSig1Delegate, const FTestbed2NestedStruct1&, Param1);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct1InterfaceProp1ChangedDelegate, const FTestbed2NestedStruct1&, Prop1);

/**
 * Interface UTestbed2NestedStruct1InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTestbed2NestedStruct1InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed2NestedStruct1InterfaceInterface
 */
class TESTBED2_API ITestbed2NestedStruct1InterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct1Interface")
	virtual FTestbed2NestedStruct1InterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct1Interface")
	virtual FTestbed2NestedStruct1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1);
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1);
	virtual FTestbed2NestedStruct1 Func1_Implementation(const FTestbed2NestedStruct1& Param1) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	FTestbed2NestedStruct1 GetProp1() const;
	virtual FTestbed2NestedStruct1 GetProp1_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	void SetProp1(const FTestbed2NestedStruct1& InProp1);
	virtual void SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1) = 0;

protected:
	// signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface", meta = (BlueprintProtected = "true"))
	void BroadcastSig1(const FTestbed2NestedStruct1& Param1);
	virtual void BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct1Interface", meta = (BlueprintProtected = "true"))
	void BroadcastProp1Changed(const FTestbed2NestedStruct1& Prop1);
	virtual void BroadcastProp1Changed_Implementation(const FTestbed2NestedStruct1& Prop1) = 0;
};

/**
 * Abstract UAbstractTestbed2NestedStruct1Interface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TESTBED2_API UAbstractTestbed2NestedStruct1Interface : public UGameInstanceSubsystem, public ITestbed2NestedStruct1InterfaceInterface
{
	GENERATED_BODY()

public:
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct1Interface", DisplayName = "Sig1 Signal")
	FTestbed2NestedStruct1InterfaceSig1Delegate Sig1Signal;
	virtual FTestbed2NestedStruct1InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct1Interface", DisplayName = "Prop1 Changed")
	FTestbed2NestedStruct1InterfaceProp1ChangedDelegate Prop1Changed;
	virtual FTestbed2NestedStruct1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	// methods
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) override;
	virtual FTestbed2NestedStruct1 Func1_Implementation(const FTestbed2NestedStruct1& Param1) override PURE_VIRTUAL(UAbstractTestbed2NestedStruct1Interface::Func1_Implementation, return FTestbed2NestedStruct1(););

	// properties
	virtual FTestbed2NestedStruct1 GetProp1_Implementation() const override PURE_VIRTUAL(UAbstractTestbed2NestedStruct1Interface::GetProp1_Implementation, return FTestbed2NestedStruct1(););

	virtual void SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1) override PURE_VIRTUAL(UAbstractTestbed2NestedStruct1Interface::SetProp1_Implementation, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;
	// signals
	virtual void BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1) override;

	virtual void BroadcastProp1Changed_Implementation(const FTestbed2NestedStruct1& InProp1) override;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|Testbed2|NestedStruct1Interface")
	FTestbed2NestedStruct1 Prop1{FTestbed2NestedStruct1()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|NestedStruct1Interface", BlueprintInternalUseOnly)
	FTestbed2NestedStruct1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|NestedStruct1Interface", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTestbed2NestedStruct1& InProp1);
};
