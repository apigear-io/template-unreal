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
#include "TbSame2SameStruct1InterfaceInterface.generated.h"

/**
 * Declaration for SameStruct1Interface
 */
// signal delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct1InterfaceSig1Delegate, const FTbSame2Struct1& /* Param1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct1InterfaceSig1DelegateBP, const FTbSame2Struct1&, Param1);

// property delegates
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct1InterfaceProp1ChangedDelegate, const FTbSame2Struct1& /* Prop1 */);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameStruct1InterfaceProp1ChangedDelegateBP, const FTbSame2Struct1&, Prop1);

/**
 * Class UTbSame2SameStruct1InterfaceInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBSAME2API_API UTbSame2SameStruct1InterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	FTbSame2SameStruct1InterfaceSig1Delegate OnSig1Signal;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct1Interface|Signals", DisplayName = "Sig1 Signal")
	FTbSame2SameStruct1InterfaceSig1DelegateBP OnSig1SignalBP;
	/// C++ wrapper for BP functions to safely call Sig1Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|Signals", DisplayName = "Broadcast Sig1 Signal")
	void BroadcastSig1Signal(const FTbSame2Struct1& Param1)
	{
		OnSig1Signal.Broadcast(Param1);
		OnSig1SignalBP.Broadcast(Param1);
	}

	FTbSame2SameStruct1InterfaceProp1ChangedDelegate OnProp1Changed;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct1Interface|Signals", DisplayName = "Property Prop1 Changed")
	FTbSame2SameStruct1InterfaceProp1ChangedDelegateBP OnProp1ChangedBP;
	/// C++ wrapper for BP functions to safely call OnProp1Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|Signals", DisplayName = "Broadcast Property Prop1 Changed")
	void BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") const FTbSame2Struct1& InProp1)
	{
		OnProp1Changed.Broadcast(InProp1);
		OnProp1ChangedBP.Broadcast(InProp1);
	}
};

/**
 * Interface UTbSame2SameStruct1InterfaceInterface only for Unreal Engine's reflection system
 */
// Note: meta=(CannotImplementInterfaceInBlueprint) is equal to NotBlueprintable and is only needed for UE 4.27
UINTERFACE(NotBlueprintable, MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UTbSame2SameStruct1InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame2SameStruct1InterfaceInterface
 */
class TBSAME2API_API ITbSame2SameStruct1InterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface")
	virtual UTbSame2SameStruct1InterfaceSignals* _GetSignals() = 0;

	// methods
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	virtual void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame2Struct1& Result, const FTbSame2Struct1& Param1) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|Operations")
	virtual FTbSame2Struct1 Func1(const FTbSame2Struct1& Param1) = 0;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|Properties")
	virtual FTbSame2Struct1 GetProp1() const = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface|Properties")
	virtual void SetProp1(UPARAM(DisplayName = "Prop1") const FTbSame2Struct1& InProp1) = 0;
};
