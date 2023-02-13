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
#include "TbSame2_data.h"
#include "TbSame2SameStruct2InterfaceInterface.generated.h"

/**
 * Declaration for SameStruct2Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct2InterfaceSig1Delegate, const FTbSame2Struct1&, Param1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTbSame2SameStruct2InterfaceSig2Delegate, const FTbSame2Struct1&, Param1, const FTbSame2Struct2&, Param2);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct2InterfaceProp1ChangedDelegate, const FTbSame2Struct2&, Prop1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct2InterfaceProp2ChangedDelegate, const FTbSame2Struct2&, Prop2);

/**
 * Interface UTbSame2SameStruct2InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbSame2SameStruct2InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame2SameStruct2InterfaceInterface
 */
class TBSAME2_API ITbSame2SameStruct2InterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UFUNCTION(Category = "ApiGear|TbSame2|SameStruct2Interface")
	virtual FTbSame2SameStruct2InterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSame2|SameStruct2Interface")
	virtual FTbSame2SameStruct2InterfaceSig2Delegate& GetSig2SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSame2|SameStruct2Interface")
	virtual FTbSame2SameStruct2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSame2|SameStruct2Interface")
	virtual FTbSame2SameStruct2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1);
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface")
	FTbSame2Struct1 Func1(const FTbSame2Struct1& Param1);
	virtual FTbSame2Struct1 Func1_Implementation(const FTbSame2Struct1& Param1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2);
	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface")
	FTbSame2Struct1 Func2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2);
	virtual FTbSame2Struct1 Func2_Implementation(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface")
	FTbSame2Struct2 GetProp1() const;
	virtual FTbSame2Struct2 GetProp1_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface")
	void SetProp1(const FTbSame2Struct2& InProp1);
	virtual void SetProp1_Implementation(const FTbSame2Struct2& InProp1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface")
	FTbSame2Struct2 GetProp2() const;
	virtual FTbSame2Struct2 GetProp2_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface")
	void SetProp2(const FTbSame2Struct2& InProp2);
	virtual void SetProp2_Implementation(const FTbSame2Struct2& InProp2) = 0;

protected:
	// signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface", meta = (BlueprintProtected = "true"))
	void BroadcastSig1(const FTbSame2Struct1& Param1);
	virtual void BroadcastSig1_Implementation(const FTbSame2Struct1& Param1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface", meta = (BlueprintProtected = "true"))
	void BroadcastSig2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2);
	virtual void BroadcastSig2_Implementation(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface", meta = (BlueprintProtected = "true"))
	void BroadcastProp1Changed(const FTbSame2Struct2& Prop1);
	virtual void BroadcastProp1Changed_Implementation(const FTbSame2Struct2& Prop1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface", meta = (BlueprintProtected = "true"))
	void BroadcastProp2Changed(const FTbSame2Struct2& Prop2);
	virtual void BroadcastProp2Changed_Implementation(const FTbSame2Struct2& Prop2) = 0;
};

/**
 * Abstract UAbstractTbSame2SameStruct2Interface
 */
UCLASS(Abstract, Blueprintable)
class TBSAME2_API UAbstractTbSame2SameStruct2Interface : public UGameInstanceSubsystem, public ITbSame2SameStruct2InterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface", DisplayName = "Sig1 Signal")
	FTbSame2SameStruct2InterfaceSig1Delegate Sig1Signal;
	UFUNCTION(Category = "ApiGear|TbSame2|SameStruct2Interface")
	virtual FTbSame2SameStruct2InterfaceSig1Delegate& GetSig1SignalDelegate() override
	{
		return Sig1Signal;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface", DisplayName = "Sig2 Signal")
	FTbSame2SameStruct2InterfaceSig2Delegate Sig2Signal;
	UFUNCTION(Category = "ApiGear|TbSame2|SameStruct2Interface")
	virtual FTbSame2SameStruct2InterfaceSig2Delegate& GetSig2SignalDelegate() override
	{
		return Sig2Signal;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface", DisplayName = "Prop1 Changed")
	FTbSame2SameStruct2InterfaceProp1ChangedDelegate Prop1Changed;
	UFUNCTION(Category = "ApiGear|TbSame2|SameStruct2Interface")
	virtual FTbSame2SameStruct2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override
	{
		return Prop1Changed;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface", DisplayName = "Prop2 Changed")
	FTbSame2SameStruct2InterfaceProp2ChangedDelegate Prop2Changed;
	UFUNCTION(Category = "ApiGear|TbSame2|SameStruct2Interface")
	virtual FTbSame2SameStruct2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override
	{
		return Prop2Changed;
	};

	// methods
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1) override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::Func1Async_Implementation, return;);
	virtual FTbSame2Struct1 Func1_Implementation(const FTbSame2Struct1& Param1) override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::Func1_Implementation, return FTbSame2Struct1(););

	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::Func2Async_Implementation, return;);
	virtual FTbSame2Struct1 Func2_Implementation(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::Func2_Implementation, return FTbSame2Struct1(););

	// properties
	virtual FTbSame2Struct2 GetProp1_Implementation() const override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::GetProp1_Implementation, return FTbSame2Struct2(););

	virtual void SetProp1_Implementation(const FTbSame2Struct2& InProp1) override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::SetProp1_Implementation, return;);
	virtual FTbSame2Struct2 GetProp2_Implementation() const override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::GetProp2_Implementation, return FTbSame2Struct2(););

	virtual void SetProp2_Implementation(const FTbSame2Struct2& InProp2) override PURE_VIRTUAL(UAbstractTbSame2SameStruct2Interface::SetProp2_Implementation, return;);

protected:
	// signals
	virtual void BroadcastSig1_Implementation(const FTbSame2Struct1& Param1) override
	{
		Sig1Signal.Broadcast(Param1);
	};

	virtual void BroadcastSig2_Implementation(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override
	{
		Sig2Signal.Broadcast(Param1, Param2);
	};

	virtual void BroadcastProp1Changed_Implementation(const FTbSame2Struct2& InProp1) override
	{
		Prop1Changed.Broadcast(InProp1);
	}

	virtual void BroadcastProp2Changed_Implementation(const FTbSame2Struct2& InProp2) override
	{
		Prop2Changed.Broadcast(InProp2);
	}

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp1_Private, BlueprintSetter = SetProp1_Private, Category = "ApiGear|TbSame2|SameStruct2Interface")
	FTbSame2Struct2 Prop1{FTbSame2Struct2()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameStruct2Interface", BlueprintInternalUseOnly)
	FTbSame2Struct2 GetProp1_Private() const
	{
		return Execute_GetProp1(this);
	};

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameStruct2Interface", BlueprintInternalUseOnly)
	void SetProp1_Private(const FTbSame2Struct2& InProp1)
	{
		Execute_SetProp1(this, InProp1);
	};

	UPROPERTY(EditAnywhere, BlueprintGetter = GetProp2_Private, BlueprintSetter = SetProp2_Private, Category = "ApiGear|TbSame2|SameStruct2Interface")
	FTbSame2Struct2 Prop2{FTbSame2Struct2()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSame2|SameStruct2Interface", BlueprintInternalUseOnly)
	FTbSame2Struct2 GetProp2_Private() const
	{
		return Execute_GetProp2(this);
	};

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSame2|SameStruct2Interface", BlueprintInternalUseOnly)
	void SetProp2_Private(const FTbSame2Struct2& InProp2)
	{
		Execute_SetProp2(this, InProp2);
	};
};
