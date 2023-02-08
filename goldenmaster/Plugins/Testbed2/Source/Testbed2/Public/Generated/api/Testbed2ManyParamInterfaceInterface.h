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
#include "Testbed2ManyParamInterfaceInterface.generated.h"

/**
 * Declaration for ManyParamInterface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTestbed2ManyParamInterfaceSig0Delegate);

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
	// signals
	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface")
	virtual FTestbed2ManyParamInterfaceSig0Delegate& GetSig0SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface")
	virtual FTestbed2ManyParamInterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface")
	virtual FTestbed2ManyParamInterfaceSig2Delegate& GetSig2SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface")
	virtual FTestbed2ManyParamInterfaceSig3Delegate& GetSig3SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface")
	virtual FTestbed2ManyParamInterfaceSig4Delegate& GetSig4SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface")
	virtual FTestbed2ManyParamInterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface")
	virtual FTestbed2ManyParamInterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface")
	virtual FTestbed2ManyParamInterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface")
	virtual FTestbed2ManyParamInterfaceProp4ChangedDelegate& GetProp4ChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	void Func0();
	virtual void Func0_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1);
	virtual void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Func1(int32 Param1);
	virtual int32 Func1_Implementation(int32 Param1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2);
	virtual void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Func2(int32 Param1, int32 Param2);
	virtual int32 Func2_Implementation(int32 Param1, int32 Param2) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3);
	virtual void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Func3(int32 Param1, int32 Param2, int32 Param3);
	virtual int32 Func3_Implementation(int32 Param1, int32 Param2, int32 Param3) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void Func4Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4);
	virtual void Func4Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 Func4(int32 Param1, int32 Param2, int32 Param3, int32 Param4);
	virtual int32 Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	void Func5(int32 Param1, int32 Param2, int32 Param3, int32 Param4, int32 Param5);
	virtual void Func5_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4, int32 Param5) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 GetProp1() const;
	virtual int32 GetProp1_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	void SetProp1(int32 Prop1);
	virtual void SetProp1_Implementation(int32 Prop1) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 GetProp2() const;
	virtual int32 GetProp2_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	void SetProp2(int32 Prop2);
	virtual void SetProp2_Implementation(int32 Prop2) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 GetProp3() const;
	virtual int32 GetProp3_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	void SetProp3(int32 Prop3);
	virtual void SetProp3_Implementation(int32 Prop3) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	int32 GetProp4() const;
	virtual int32 GetProp4_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	void SetProp4(int32 Prop4);
	virtual void SetProp4_Implementation(int32 Prop4) = 0;

protected:
	// signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSig0();
	virtual void BroadcastSig0_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSig1(int32 Param1);
	virtual void BroadcastSig1_Implementation(int32 Param1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSig2(int32 Param1, int32 Param2);
	virtual void BroadcastSig2_Implementation(int32 Param1, int32 Param2) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSig3(int32 Param1, int32 Param2, int32 Param3);
	virtual void BroadcastSig3_Implementation(int32 Param1, int32 Param2, int32 Param3) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSig4(int32 Param1, int32 Param2, int32 Param3, int32 Param4);
	virtual void BroadcastSig4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", meta = (BlueprintProtected = "true"))
	void BroadcastProp1Changed(int32 Prop1);
	virtual void BroadcastProp1Changed_Implementation(int32 Prop1) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", meta = (BlueprintProtected = "true"))
	void BroadcastProp2Changed(int32 Prop2);
	virtual void BroadcastProp2Changed_Implementation(int32 Prop2) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", meta = (BlueprintProtected = "true"))
	void BroadcastProp3Changed(int32 Prop3);
	virtual void BroadcastProp3Changed_Implementation(int32 Prop3) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", meta = (BlueprintProtected = "true"))
	void BroadcastProp4Changed(int32 Prop4);
	virtual void BroadcastProp4Changed_Implementation(int32 Prop4) = 0;
};
