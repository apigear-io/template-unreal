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
#include "Testbed2ManyParamInterfaceInterface.generated.h"

/**
 * Declaration for ManyParamInterface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceSig1Delegate, int32, Param1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTestbed2ManyParamInterfaceSig2Delegate, int32, Param1, int32, Param2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTestbed2ManyParamInterfaceSig3Delegate, int32, Param1, int32, Param2, int32, Param3);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FTestbed2ManyParamInterfaceSig4Delegate, int32, Param1, int32, Param2, int32, Param3, int32, Param4);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceProp1ChangedDelegate, int32, Prop1);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceProp2ChangedDelegate, int32, Prop2);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceProp3ChangedDelegate, int32, Prop3);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed2ManyParamInterfaceProp4ChangedDelegate, int32, Prop4);

/**
 * Class UTestbed2ManyParamInterfaceInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TESTBED2_API UTestbed2ManyParamInterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Sig1 Signal")
	FTestbed2ManyParamInterfaceSig1Delegate OnSig1Signal;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Sig2 Signal")
	FTestbed2ManyParamInterfaceSig2Delegate OnSig2Signal;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Sig3 Signal")
	FTestbed2ManyParamInterfaceSig3Delegate OnSig3Signal;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Sig4 Signal")
	FTestbed2ManyParamInterfaceSig4Delegate OnSig4Signal;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Property Prop1 Changed")
	FTestbed2ManyParamInterfaceProp1ChangedDelegate OnProp1Changed;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Property Prop2 Changed")
	FTestbed2ManyParamInterfaceProp2ChangedDelegate OnProp2Changed;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Property Prop3 Changed")
	FTestbed2ManyParamInterfaceProp3ChangedDelegate OnProp3Changed;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Signals", DisplayName = "Property Prop4 Changed")
	FTestbed2ManyParamInterfaceProp4ChangedDelegate OnProp4Changed;
};

/**
 * Interface UTestbed2ManyParamInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTestbed2ManyParamInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed2ManyParamInterfaceInterface
 */
class TESTBED2_API ITestbed2ManyParamInterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	UTestbed2ManyParamInterfaceSignals* _GetSignals();
	virtual UTestbed2ManyParamInterfaceSignals* _GetSignals_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1);
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Operations")
	int32 Func1(int32 Param1);
	virtual int32 Func1_Implementation(int32 Param1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2);
	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Operations")
	int32 Func2(int32 Param1, int32 Param2);
	virtual int32 Func2_Implementation(int32 Param1, int32 Param2) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3);
	virtual void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Operations")
	int32 Func3(int32 Param1, int32 Param2, int32 Param3);
	virtual int32 Func3_Implementation(int32 Param1, int32 Param2, int32 Param3) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func4Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4);
	virtual void Func4Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Operations")
	int32 Func4(int32 Param1, int32 Param2, int32 Param3, int32 Param4);
	virtual int32 Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	int32 GetProp1() const;
	virtual int32 GetProp1_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	void SetProp1(int32 InProp1);
	virtual void SetProp1_Implementation(int32 InProp1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	int32 GetProp2() const;
	virtual int32 GetProp2_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	void SetProp2(int32 InProp2);
	virtual void SetProp2_Implementation(int32 InProp2) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	int32 GetProp3() const;
	virtual int32 GetProp3_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	void SetProp3(int32 InProp3);
	virtual void SetProp3_Implementation(int32 InProp3) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	int32 GetProp4() const;
	virtual int32 GetProp4_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface|Properties")
	void SetProp4(int32 InProp4);
	virtual void SetProp4_Implementation(int32 InProp4) = 0;
};
