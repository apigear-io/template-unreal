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
#include "Testbed2_data.h"
#include "Testbed2ManyParamInterfaceInterface.h"
#include "AbstractTestbed2ManyParamInterface.generated.h"

/**
 * Abstract UAbstractTestbed2ManyParamInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TESTBED2_API UAbstractTestbed2ManyParamInterface : public UGameInstanceSubsystem, public ITestbed2ManyParamInterfaceInterface
{
	GENERATED_BODY()

public:
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Sig1 Signal")
	FTestbed2ManyParamInterfaceSig1Delegate Sig1Signal;
	virtual FTestbed2ManyParamInterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Sig2 Signal")
	FTestbed2ManyParamInterfaceSig2Delegate Sig2Signal;
	virtual FTestbed2ManyParamInterfaceSig2Delegate& GetSig2SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Sig3 Signal")
	FTestbed2ManyParamInterfaceSig3Delegate Sig3Signal;
	virtual FTestbed2ManyParamInterfaceSig3Delegate& GetSig3SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Sig4 Signal")
	FTestbed2ManyParamInterfaceSig4Delegate Sig4Signal;
	virtual FTestbed2ManyParamInterfaceSig4Delegate& GetSig4SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Prop1 Changed")
	FTestbed2ManyParamInterfaceProp1ChangedDelegate Prop1Changed;
	virtual FTestbed2ManyParamInterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Prop2 Changed")
	FTestbed2ManyParamInterfaceProp2ChangedDelegate Prop2Changed;
	virtual FTestbed2ManyParamInterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Prop3 Changed")
	FTestbed2ManyParamInterfaceProp3ChangedDelegate Prop3Changed;
	virtual FTestbed2ManyParamInterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Prop4 Changed")
	FTestbed2ManyParamInterfaceProp4ChangedDelegate Prop4Changed;
	virtual FTestbed2ManyParamInterfaceProp4ChangedDelegate& GetProp4ChangedDelegate() override;

	// methods
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1) override;
	virtual int32 Func1_Implementation(int32 Param1) override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::Func1_Implementation, return 0;);

	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2) override;
	virtual int32 Func2_Implementation(int32 Param1, int32 Param2) override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::Func2_Implementation, return 0;);

	virtual void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3) override;
	virtual int32 Func3_Implementation(int32 Param1, int32 Param2, int32 Param3) override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::Func3_Implementation, return 0;);

	virtual void Func4Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;
	virtual int32 Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::Func4_Implementation, return 0;);

	// properties
	virtual int32 GetProp1_Implementation() const override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::GetProp1_Implementation, return 0;);

	virtual void SetProp1_Implementation(int32 InProp1) override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::SetProp1_Implementation, return;);
	virtual int32 GetProp2_Implementation() const override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::GetProp2_Implementation, return 0;);

	virtual void SetProp2_Implementation(int32 InProp2) override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::SetProp2_Implementation, return;);
	virtual int32 GetProp3_Implementation() const override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::GetProp3_Implementation, return 0;);

	virtual void SetProp3_Implementation(int32 InProp3) override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::SetProp3_Implementation, return;);
	virtual int32 GetProp4_Implementation() const override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::GetProp4_Implementation, return 0;);

	virtual void SetProp4_Implementation(int32 InProp4) override PURE_VIRTUAL(UAbstractTestbed2ManyParamInterface::SetProp4_Implementation, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;
	// signals
	virtual void BroadcastSig1_Implementation(int32 Param1) override;

	virtual void BroadcastSig2_Implementation(int32 Param1, int32 Param2) override;

	virtual void BroadcastSig3_Implementation(int32 Param1, int32 Param2, int32 Param3) override;

	virtual void BroadcastSig4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;

	virtual void BroadcastProp1Changed_Implementation(int32 InProp1) override;

	virtual void BroadcastProp2Changed_Implementation(int32 InProp2) override;

	virtual void BroadcastProp3Changed_Implementation(int32 InProp3) override;

	virtual void BroadcastProp4Changed_Implementation(int32 InProp4) override;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Prop1{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	int32 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void SetProp1_Private(int32 InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Prop2{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	int32 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void SetProp2_Private(int32 InProp2);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp3_Private, BlueprintSetter = SetProp3_Private, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Prop3{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	int32 GetProp3_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void SetProp3_Private(int32 InProp3);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp4_Private, BlueprintSetter = SetProp4_Private, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Prop4{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	int32 GetProp4_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void SetProp4_Private(int32 InProp4);
};
