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
#include "Testbed2_data.h"
#include "Testbed2NestedStruct3InterfaceInterface.generated.h"

/**
 * Declaration for NestedStruct3Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceSig1Delegate, const FTestbed2NestedStruct1&, Param1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTestbed2NestedStruct3InterfaceSig2Delegate, const FTestbed2NestedStruct1&, Param1, const FTestbed2NestedStruct2&, Param2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTestbed2NestedStruct3InterfaceSig3Delegate, const FTestbed2NestedStruct1&, Param1, const FTestbed2NestedStruct2&, Param2, const FTestbed2NestedStruct3&, Param3);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp1ChangedDelegate, const FTestbed2NestedStruct1&, Prop1);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp2ChangedDelegate, const FTestbed2NestedStruct2&, Prop2);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2NestedStruct3InterfaceProp3ChangedDelegate, const FTestbed2NestedStruct3&, Prop3);

/**
 * Class UTestbed2NestedStruct3InterfaceInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TESTBED2_API UTestbed2NestedStruct3InterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Sig1 Signal")
	FTestbed2NestedStruct3InterfaceSig1Delegate OnSig1Signal;
	/// C++ wrapper for BP functions to safely call Sig1Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Sig1 Signal")
	void BroadcastSig1Signal(const FTestbed2NestedStruct1& Param1)
	{
		OnSig1Signal.Broadcast(Param1);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Sig2 Signal")
	FTestbed2NestedStruct3InterfaceSig2Delegate OnSig2Signal;
	/// C++ wrapper for BP functions to safely call Sig2Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Sig2 Signal")
	void BroadcastSig2Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
	{
		OnSig2Signal.Broadcast(Param1, Param2);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Sig3 Signal")
	FTestbed2NestedStruct3InterfaceSig3Delegate OnSig3Signal;
	/// C++ wrapper for BP functions to safely call Sig3Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Sig3 Signal")
	void BroadcastSig3Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
	{
		OnSig3Signal.Broadcast(Param1, Param2, Param3);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Property Prop1 Changed")
	FTestbed2NestedStruct3InterfaceProp1ChangedDelegate OnProp1Changed;
	/// C++ wrapper for BP functions to safely call OnProp1Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Property Prop1 Changed")
	void BroadcastProp1Changed(UPARAM(DisplayName = "Prop1") const FTestbed2NestedStruct1& InProp1)
	{
		OnProp1Changed.Broadcast(InProp1);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Property Prop2 Changed")
	FTestbed2NestedStruct3InterfaceProp2ChangedDelegate OnProp2Changed;
	/// C++ wrapper for BP functions to safely call OnProp2Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Property Prop2 Changed")
	void BroadcastProp2Changed(UPARAM(DisplayName = "Prop2") const FTestbed2NestedStruct2& InProp2)
	{
		OnProp2Changed.Broadcast(InProp2);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Property Prop3 Changed")
	FTestbed2NestedStruct3InterfaceProp3ChangedDelegate OnProp3Changed;
	/// C++ wrapper for BP functions to safely call OnProp3Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Signals", DisplayName = "Broadcast Property Prop3 Changed")
	void BroadcastProp3Changed(UPARAM(DisplayName = "Prop3") const FTestbed2NestedStruct3& InProp3)
	{
		OnProp3Changed.Broadcast(InProp3);
	}
};

/**
 * Interface UTestbed2NestedStruct3InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTestbed2NestedStruct3InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed2NestedStruct3InterfaceInterface
 */
class TESTBED2_API ITestbed2NestedStruct3InterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	UTestbed2NestedStruct3InterfaceSignals* _GetSignals();
	virtual UTestbed2NestedStruct3InterfaceSignals* _GetSignals_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1);
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations")
	FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1);
	virtual FTestbed2NestedStruct1 Func1_Implementation(const FTestbed2NestedStruct1& Param1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);
	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations")
	FTestbed2NestedStruct1 Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);
	virtual FTestbed2NestedStruct1 Func2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3);
	virtual void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Operations")
	FTestbed2NestedStruct1 Func3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3);
	virtual FTestbed2NestedStruct1 Func3_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	FTestbed2NestedStruct1 GetProp1() const;
	virtual FTestbed2NestedStruct1 GetProp1_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	void SetProp1(const FTestbed2NestedStruct1& InProp1);
	virtual void SetProp1_Implementation(const FTestbed2NestedStruct1& InProp1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	FTestbed2NestedStruct2 GetProp2() const;
	virtual FTestbed2NestedStruct2 GetProp2_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	void SetProp2(const FTestbed2NestedStruct2& InProp2);
	virtual void SetProp2_Implementation(const FTestbed2NestedStruct2& InProp2) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	FTestbed2NestedStruct3 GetProp3() const;
	virtual FTestbed2NestedStruct3 GetProp3_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface|Properties")
	void SetProp3(const FTestbed2NestedStruct3& InProp3);
	virtual void SetProp3_Implementation(const FTestbed2NestedStruct3& InProp3) = 0;
};
