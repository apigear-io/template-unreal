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
	// signals
	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct3Interface")
	virtual FTestbed2NestedStruct3InterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct3Interface")
	virtual FTestbed2NestedStruct3InterfaceSig2Delegate& GetSig2SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct3Interface")
	virtual FTestbed2NestedStruct3InterfaceSig3Delegate& GetSig3SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct3Interface")
	virtual FTestbed2NestedStruct3InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct3Interface")
	virtual FTestbed2NestedStruct3InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct3Interface")
	virtual FTestbed2NestedStruct3InterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1);
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1);
	virtual FTestbed2NestedStruct1 Func1_Implementation(const FTestbed2NestedStruct1& Param1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);
	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	FTestbed2NestedStruct1 Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);
	virtual FTestbed2NestedStruct1 Func2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3);
	virtual void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	FTestbed2NestedStruct1 Func3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3);
	virtual FTestbed2NestedStruct1 Func3_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	FTestbed2NestedStruct1 GetProp1() const;
	virtual FTestbed2NestedStruct1 GetProp1_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	void SetProp1(const FTestbed2NestedStruct1& Prop1);
	virtual void SetProp1_Implementation(const FTestbed2NestedStruct1& Prop1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	FTestbed2NestedStruct2 GetProp2() const;
	virtual FTestbed2NestedStruct2 GetProp2_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	void SetProp2(const FTestbed2NestedStruct2& Prop2);
	virtual void SetProp2_Implementation(const FTestbed2NestedStruct2& Prop2) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	FTestbed2NestedStruct3 GetProp3() const;
	virtual FTestbed2NestedStruct3 GetProp3_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface")
	void SetProp3(const FTestbed2NestedStruct3& Prop3);
	virtual void SetProp3_Implementation(const FTestbed2NestedStruct3& Prop3) = 0;

protected:
	// signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface", meta = (BlueprintProtected = "true"))
	void BroadcastSig1(const FTestbed2NestedStruct1& Param1);
	virtual void BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface", meta = (BlueprintProtected = "true"))
	void BroadcastSig2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);
	virtual void BroadcastSig2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface", meta = (BlueprintProtected = "true"))
	void BroadcastSig3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3);
	virtual void BroadcastSig3_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface", meta = (BlueprintProtected = "true"))
	void BroadcastProp1Changed(const FTestbed2NestedStruct1& Prop1);
	virtual void BroadcastProp1Changed_Implementation(const FTestbed2NestedStruct1& Prop1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface", meta = (BlueprintProtected = "true"))
	void BroadcastProp2Changed(const FTestbed2NestedStruct2& Prop2);
	virtual void BroadcastProp2Changed_Implementation(const FTestbed2NestedStruct2& Prop2) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct3Interface", meta = (BlueprintProtected = "true"))
	void BroadcastProp3Changed(const FTestbed2NestedStruct3& Prop3);
	virtual void BroadcastProp3Changed_Implementation(const FTestbed2NestedStruct3& Prop3) = 0;
};
