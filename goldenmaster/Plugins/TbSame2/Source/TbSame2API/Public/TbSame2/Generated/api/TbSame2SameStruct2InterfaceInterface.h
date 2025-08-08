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
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "TbSame2_data.h"
#include "TbSame2SameStruct2InterfaceInterface.generated.h"

/**
 * Declaration for SameStruct2Interface
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct2InterfaceSig1Delegate, const FTbSame2Struct1& /* Param1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct2InterfaceSig1DelegateBP, const FTbSame2Struct1&, Param1);

DECLARE_MULTICAST_DELEGATE_TwoParams(FTbSame2SameStruct2InterfaceSig2Delegate, const FTbSame2Struct1& /* Param1 */, const FTbSame2Struct2& /* Param2 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTbSame2SameStruct2InterfaceSig2DelegateBP, const FTbSame2Struct1&, Param1, const FTbSame2Struct2&, Param2);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct2InterfaceProp1ChangedDelegate, const FTbSame2Struct2& /* Prop1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct2InterfaceProp1ChangedDelegateBP, const FTbSame2Struct2&, Prop1);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct2InterfaceProp2ChangedDelegate, const FTbSame2Struct2& /* Prop2 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct2InterfaceProp2ChangedDelegateBP, const FTbSame2Struct2&, Prop2);

/**
 * Class UTbSame2SameStruct2InterfaceInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBSAME2API_API UTbSame2SameStruct2InterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	FTbSame2SameStruct2InterfaceSig1Delegate OnSig1Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface|Signals", DisplayName = "Sig1 Signal")
	FTbSame2SameStruct2InterfaceSig1DelegateBP OnSig1SignalBP;
	/// C++ wrapper for BP functions to safely call Sig1Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Signals", DisplayName = "Broadcast Sig1 Signal")
	void BroadcastSig1Signal(const FTbSame2Struct1& Param1)
	{
		OnSig1Signal.Broadcast(Param1);
		OnSig1SignalBP.Broadcast(Param1);
	}

	FTbSame2SameStruct2InterfaceSig2Delegate OnSig2Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface|Signals", DisplayName = "Sig2 Signal")
	FTbSame2SameStruct2InterfaceSig2DelegateBP OnSig2SignalBP;
	/// C++ wrapper for BP functions to safely call Sig2Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Signals", DisplayName = "Broadcast Sig2 Signal")
	void BroadcastSig2Signal(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
	{
		OnSig2Signal.Broadcast(Param1, Param2);
		OnSig2SignalBP.Broadcast(Param1, Param2);
	}

	FTbSame2SameStruct2InterfaceProp1ChangedDelegate OnProp1Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface|Signals", DisplayName = "Property Prop1 Changed")
	FTbSame2SameStruct2InterfaceProp1ChangedDelegateBP OnProp1ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp1Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Signals", DisplayName = "Broadcast Property Prop1 Changed")
	void BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") const FTbSame2Struct2& InProp1)
	{
		OnProp1Changed.Broadcast(InProp1);
		OnProp1ChangedBP.Broadcast(InProp1);
	}

	FTbSame2SameStruct2InterfaceProp2ChangedDelegate OnProp2Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface|Signals", DisplayName = "Property Prop2 Changed")
	FTbSame2SameStruct2InterfaceProp2ChangedDelegateBP OnProp2ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp2Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Signals", DisplayName = "Broadcast Property Prop2 Changed")
	void BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") const FTbSame2Struct2& InProp2)
	{
		OnProp2Changed.Broadcast(InProp2);
		OnProp2ChangedBP.Broadcast(InProp2);
	}
};

/**
 * Interface UTbSame2SameStruct2InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(BlueprintType, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSame2SameStruct2InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame2SameStruct2InterfaceInterface
 */
class TBSAME2API_API ITbSame2SameStruct2InterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface")
	virtual UTbSame2SameStruct2InterfaceSignals* _GetSignals() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Operations")
	virtual FTbSame2Struct1 Func1(const FTbSame2Struct1& Param1) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Operations")
	virtual FTbSame2Struct1 Func2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Properties")
	virtual FTbSame2Struct2 GetProp1() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Properties")
	virtual void SetProp1(UPARAM(DisplayName = "Prop1") const FTbSame2Struct2& InProp1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Properties")
	virtual FTbSame2Struct2 GetProp2() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Properties")
	virtual void SetProp2(UPARAM(DisplayName = "Prop2") const FTbSame2Struct2& InProp2) = 0;
};
