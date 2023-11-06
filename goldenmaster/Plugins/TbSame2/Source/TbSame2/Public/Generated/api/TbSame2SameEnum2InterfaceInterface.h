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
#include "TbSame2SameEnum2InterfaceInterface.generated.h"

/**
 * Declaration for SameEnum2Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameEnum2InterfaceSig1Delegate, ETbSame2Enum1, Param1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTbSame2SameEnum2InterfaceSig2Delegate, ETbSame2Enum1, Param1, ETbSame2Enum2, Param2);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameEnum2InterfaceProp1ChangedDelegate, ETbSame2Enum1, Prop1);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2SameEnum2InterfaceProp2ChangedDelegate, ETbSame2Enum2, Prop2);

/**
 * Class UTbSame2SameEnum2InterfaceInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBSAME2_API UTbSame2SameEnum2InterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "Sig1 Signal")
	FTbSame2SameEnum2InterfaceSig1Delegate OnSig1Signal;
	/// C++ wrapper for BP functions to safely call Sig1Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "Broadcast Sig1 Signal")
	void BroadcastSig1Signal(ETbSame2Enum1 Param1)
	{
		OnSig1Signal.Broadcast(Param1);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "Sig2 Signal")
	FTbSame2SameEnum2InterfaceSig2Delegate OnSig2Signal;
	/// C++ wrapper for BP functions to safely call Sig2Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "Broadcast Sig2 Signal")
	void BroadcastSig2Signal(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
	{
		OnSig2Signal.Broadcast(Param1, Param2);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "Property Prop1 Changed")
	FTbSame2SameEnum2InterfaceProp1ChangedDelegate OnProp1Changed;
	/// C++ wrapper for BP functions to safely call OnProp1Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "Broadcast Property Prop1 Changed")
	void BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") ETbSame2Enum1 InProp1)
	{
		OnProp1Changed.Broadcast(InProp1);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "Property Prop2 Changed")
	FTbSame2SameEnum2InterfaceProp2ChangedDelegate OnProp2Changed;
	/// C++ wrapper for BP functions to safely call OnProp2Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Signals", DisplayName = "Broadcast Property Prop2 Changed")
	void BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") ETbSame2Enum2 InProp2)
	{
		OnProp2Changed.Broadcast(InProp2);
	}
};

/**
 * Interface UTbSame2SameEnum2InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbSame2SameEnum2InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSame2SameEnum2InterfaceInterface
 */
class TBSAME2_API ITbSame2SameEnum2InterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface")
	UTbSame2SameEnum2InterfaceSignals* _GetSignals();
	virtual UTbSame2SameEnum2InterfaceSignals* _GetSignals_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1);
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Operations")
	ETbSame2Enum1 Func1(ETbSame2Enum1 Param1);
	virtual ETbSame2Enum1 Func1_Implementation(ETbSame2Enum1 Param1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1, ETbSame2Enum2 Param2);
	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Operations")
	ETbSame2Enum1 Func2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2);
	virtual ETbSame2Enum1 Func2_Implementation(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties")
	ETbSame2Enum1 GetProp1() const;
	virtual ETbSame2Enum1 GetProp1_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties")
	void SetProp1(ETbSame2Enum1 InProp1);
	virtual void SetProp1_Implementation(ETbSame2Enum1 InProp1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties")
	ETbSame2Enum2 GetProp2() const;
	virtual ETbSame2Enum2 GetProp2_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSame2|SameEnum2Interface|Properties")
	void SetProp2(ETbSame2Enum2 InProp2);
	virtual void SetProp2_Implementation(ETbSame2Enum2 InProp2) = 0;
};
