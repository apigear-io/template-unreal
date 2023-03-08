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
#include "TbEnum_data.h"
#include "TbEnumEnumInterfaceInterface.generated.h"

/**
 * Declaration for EnumInterface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig0Delegate, ETbEnumEnum0, Param0);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig1Delegate, ETbEnumEnum1, Param1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig2Delegate, ETbEnumEnum2, Param2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig3Delegate, ETbEnumEnum3, Param3);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp0ChangedDelegate, ETbEnumEnum0, Prop0);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp1ChangedDelegate, ETbEnumEnum1, Prop1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp2ChangedDelegate, ETbEnumEnum2, Prop2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp3ChangedDelegate, ETbEnumEnum3, Prop3);

/**
 * Interface UTbEnumEnumInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbEnumEnumInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbEnumEnumInterfaceInterface
 */
class TBENUM_API ITbEnumEnumInterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
	virtual FTbEnumEnumInterfaceSig0Delegate& GetSig0SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
	virtual FTbEnumEnumInterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
	virtual FTbEnumEnumInterfaceSig2Delegate& GetSig2SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
	virtual FTbEnumEnumInterfaceSig3Delegate& GetSig3SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
	virtual FTbEnumEnumInterfaceProp0ChangedDelegate& GetProp0ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
	virtual FTbEnumEnumInterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
	virtual FTbEnumEnumInterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
	virtual FTbEnumEnumInterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func0Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, ETbEnumEnum0 Param0);
	virtual void Func0Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, ETbEnumEnum0 Param0) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum0 Func0(ETbEnumEnum0 Param0);
	virtual ETbEnumEnum0 Func0_Implementation(ETbEnumEnum0 Param0) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, ETbEnumEnum1 Param1);
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, ETbEnumEnum1 Param1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum1 Func1(ETbEnumEnum1 Param1);
	virtual ETbEnumEnum1 Func1_Implementation(ETbEnumEnum1 Param1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, ETbEnumEnum2 Param2);
	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, ETbEnumEnum2 Param2) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum2 Func2(ETbEnumEnum2 Param2);
	virtual ETbEnumEnum2 Func2_Implementation(ETbEnumEnum2 Param2) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, ETbEnumEnum3 Param3);
	virtual void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, ETbEnumEnum3 Param3) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum3 Func3(ETbEnumEnum3 Param3);
	virtual ETbEnumEnum3 Func3_Implementation(ETbEnumEnum3 Param3) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum0 GetProp0() const;
	virtual ETbEnumEnum0 GetProp0_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void SetProp0(ETbEnumEnum0 InProp0);
	virtual void SetProp0_Implementation(ETbEnumEnum0 InProp0) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum1 GetProp1() const;
	virtual ETbEnumEnum1 GetProp1_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void SetProp1(ETbEnumEnum1 InProp1);
	virtual void SetProp1_Implementation(ETbEnumEnum1 InProp1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum2 GetProp2() const;
	virtual ETbEnumEnum2 GetProp2_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void SetProp2(ETbEnumEnum2 InProp2);
	virtual void SetProp2_Implementation(ETbEnumEnum2 InProp2) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum3 GetProp3() const;
	virtual ETbEnumEnum3 GetProp3_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void SetProp3(ETbEnumEnum3 InProp3);
	virtual void SetProp3_Implementation(ETbEnumEnum3 InProp3) = 0;

protected:
	// signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSig0(ETbEnumEnum0 Param0);
	virtual void BroadcastSig0_Implementation(ETbEnumEnum0 Param0) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSig1(ETbEnumEnum1 Param1);
	virtual void BroadcastSig1_Implementation(ETbEnumEnum1 Param1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSig2(ETbEnumEnum2 Param2);
	virtual void BroadcastSig2_Implementation(ETbEnumEnum2 Param2) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSig3(ETbEnumEnum3 Param3);
	virtual void BroadcastSig3_Implementation(ETbEnumEnum3 Param3) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", meta = (BlueprintProtected = "true"))
	void BroadcastProp0Changed(ETbEnumEnum0 Prop0);
	virtual void BroadcastProp0Changed_Implementation(ETbEnumEnum0 Prop0) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", meta = (BlueprintProtected = "true"))
	void BroadcastProp1Changed(ETbEnumEnum1 Prop1);
	virtual void BroadcastProp1Changed_Implementation(ETbEnumEnum1 Prop1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", meta = (BlueprintProtected = "true"))
	void BroadcastProp2Changed(ETbEnumEnum2 Prop2);
	virtual void BroadcastProp2Changed_Implementation(ETbEnumEnum2 Prop2) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface", meta = (BlueprintProtected = "true"))
	void BroadcastProp3Changed(ETbEnumEnum3 Prop3);
	virtual void BroadcastProp3Changed_Implementation(ETbEnumEnum3 Prop3) = 0;
};

/**
 * Abstract UAbstractTbEnumEnumInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBENUM_API UAbstractTbEnumEnumInterface : public UGameInstanceSubsystem, public ITbEnumEnumInterfaceInterface
{
	GENERATED_BODY()

public:
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Sig0 Signal")
	FTbEnumEnumInterfaceSig0Delegate Sig0Signal;
	virtual FTbEnumEnumInterfaceSig0Delegate& GetSig0SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Sig1 Signal")
	FTbEnumEnumInterfaceSig1Delegate Sig1Signal;
	virtual FTbEnumEnumInterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Sig2 Signal")
	FTbEnumEnumInterfaceSig2Delegate Sig2Signal;
	virtual FTbEnumEnumInterfaceSig2Delegate& GetSig2SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Sig3 Signal")
	FTbEnumEnumInterfaceSig3Delegate Sig3Signal;
	virtual FTbEnumEnumInterfaceSig3Delegate& GetSig3SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Prop0 Changed")
	FTbEnumEnumInterfaceProp0ChangedDelegate Prop0Changed;
	virtual FTbEnumEnumInterfaceProp0ChangedDelegate& GetProp0ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Prop1 Changed")
	FTbEnumEnumInterfaceProp1ChangedDelegate Prop1Changed;
	virtual FTbEnumEnumInterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Prop2 Changed")
	FTbEnumEnumInterfaceProp2ChangedDelegate Prop2Changed;
	virtual FTbEnumEnumInterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Prop3 Changed")
	FTbEnumEnumInterfaceProp3ChangedDelegate Prop3Changed;
	virtual FTbEnumEnumInterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() override;

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
	// signals
	virtual void BroadcastSig0_Implementation(ETbEnumEnum0 Param0) override;

	virtual void BroadcastSig1_Implementation(ETbEnumEnum1 Param1) override;

	virtual void BroadcastSig2_Implementation(ETbEnumEnum2 Param2) override;

	virtual void BroadcastSig3_Implementation(ETbEnumEnum3 Param3) override;

	virtual void BroadcastProp0Changed_Implementation(ETbEnumEnum0 InProp0) override;

	virtual void BroadcastProp1Changed_Implementation(ETbEnumEnum1 InProp1) override;

	virtual void BroadcastProp2Changed_Implementation(ETbEnumEnum2 InProp2) override;

	virtual void BroadcastProp3Changed_Implementation(ETbEnumEnum3 InProp3) override;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp0_Private, BlueprintSetter = SetProp0_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum0 Prop0{ETbEnumEnum0::TEE_VALUE0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	ETbEnumEnum0 GetProp0_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void SetProp0_Private(ETbEnumEnum0 InProp0);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum1 Prop1{ETbEnumEnum1::TEE_VALUE1};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	ETbEnumEnum1 GetProp1_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void SetProp1_Private(ETbEnumEnum1 InProp1);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum2 Prop2{ETbEnumEnum2::TEE_VALUE2};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	ETbEnumEnum2 GetProp2_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void SetProp2_Private(ETbEnumEnum2 InProp2);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp3_Private, BlueprintSetter = SetProp3_Private, Category = "ApiGear|TbEnum|EnumInterface")
	ETbEnumEnum3 Prop3{ETbEnumEnum3::TEE_VALUE3};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	ETbEnumEnum3 GetProp3_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void SetProp3_Private(ETbEnumEnum3 InProp3);
};
