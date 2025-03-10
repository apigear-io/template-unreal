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
#include "TbSame1_data.h"
#include "TbSame1SameStruct1InterfaceInterface.generated.h"

/**
 * Declaration for SameStruct1Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameStruct1InterfaceSig1Delegate, const FTbSame1Struct1&, Param1);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame1SameStruct1InterfaceProp1ChangedDelegate, const FTbSame1Struct1&, Prop1);

/**
 * Class UTbSame1SameStruct1InterfaceInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBSAME1API_API UTbSame1SameStruct1InterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameStruct1Interface|Signals", DisplayName = "Sig1 Signal")
	FTbSame1SameStruct1InterfaceSig1Delegate OnSig1Signal;
	/// C++ wrapper for BP functions to safely call Sig1Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface|Signals", DisplayName = "Broadcast Sig1 Signal")
	void BroadcastSig1Signal(const FTbSame1Struct1& Param1)
	{
		OnSig1Signal.Broadcast(Param1);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameStruct1Interface|Signals", DisplayName = "Property Prop1 Changed")
	FTbSame1SameStruct1InterfaceProp1ChangedDelegate OnProp1Changed;
	/// C++ wrapper for BP functions to safely call OnProp1Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface|Signals", DisplayName = "Broadcast Property Prop1 Changed")
	void BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") const FTbSame1Struct1& InProp1)
	{
		OnProp1Changed.Broadcast(InProp1);
	}
};

/**
 * Interface UTbSame1SameStruct1InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbSame1SameStruct1InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame1SameStruct1InterfaceInterface
 */
class TBSAME1API_API ITbSame1SameStruct1InterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface")
	UTbSame1SameStruct1InterfaceSignals* _GetSignals();
	virtual UTbSame1SameStruct1InterfaceSignals* _GetSignals_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1);
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface|Operations")
	FTbSame1Struct1 Func1(const FTbSame1Struct1& Param1);
	virtual FTbSame1Struct1 Func1_Implementation(const FTbSame1Struct1& Param1) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface|Properties")
	FTbSame1Struct1 GetProp1() const;
	virtual FTbSame1Struct1 GetProp1_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface|Properties")
	void SetProp1(const FTbSame1Struct1& InProp1);
	virtual void SetProp1_Implementation(UPARAM(DisplayName = "Prop1") const FTbSame1Struct1& InProp1) = 0;
};
