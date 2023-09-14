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
#include "Testbed1_data.h"
#include "Testbed1StructArrayInterfaceInterface.generated.h"

/**
 * Declaration for StructArrayInterface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceSigBoolDelegate, const TArray<FTestbed1StructBool>&, ParamBool);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceSigIntDelegate, const TArray<FTestbed1StructInt>&, ParamInt);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceSigFloatDelegate, const TArray<FTestbed1StructFloat>&, ParamFloat);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfaceSigStringDelegate, const TArray<FTestbed1StructString>&, ParamString);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfacePropBoolChangedDelegate, const TArray<FTestbed1StructBool>&, PropBool);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfacePropIntChangedDelegate, const TArray<FTestbed1StructInt>&, PropInt);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfacePropFloatChangedDelegate, const TArray<FTestbed1StructFloat>&, PropFloat);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArrayInterfacePropStringChangedDelegate, const TArray<FTestbed1StructString>&, PropString);

/**
 * Interface UTestbed1StructArrayInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTestbed1StructArrayInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed1StructArrayInterfaceInterface
 */
class TESTBED1_API ITestbed1StructArrayInterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface|Signals")
	virtual FTestbed1StructArrayInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface|Signals")
	virtual FTestbed1StructArrayInterfaceSigIntDelegate& GetSigIntSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface|Signals")
	virtual FTestbed1StructArrayInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface|Signals")
	virtual FTestbed1StructArrayInterfaceSigStringDelegate& GetSigStringSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface|Signals")
	virtual FTestbed1StructArrayInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface|Signals")
	virtual FTestbed1StructArrayInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface|Signals")
	virtual FTestbed1StructArrayInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface|Signals")
	virtual FTestbed1StructArrayInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructBool>& ParamBool);
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructBool>& ParamBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations")
	FTestbed1StructBool FuncBool(const TArray<FTestbed1StructBool>& ParamBool);
	virtual FTestbed1StructBool FuncBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructInt>& ParamInt);
	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructInt>& ParamInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations")
	FTestbed1StructBool FuncInt(const TArray<FTestbed1StructInt>& ParamInt);
	virtual FTestbed1StructBool FuncInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructFloat>& ParamFloat);
	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructFloat>& ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations")
	FTestbed1StructBool FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat);
	virtual FTestbed1StructBool FuncFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructString>& ParamString);
	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructString>& ParamString) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Operations")
	FTestbed1StructBool FuncString(const TArray<FTestbed1StructString>& ParamString);
	virtual FTestbed1StructBool FuncString_Implementation(const TArray<FTestbed1StructString>& ParamString) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	TArray<FTestbed1StructBool> GetPropBool() const;
	virtual TArray<FTestbed1StructBool> GetPropBool_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	void SetPropBool(const TArray<FTestbed1StructBool>& InPropBool);
	virtual void SetPropBool_Implementation(const TArray<FTestbed1StructBool>& InPropBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	TArray<FTestbed1StructInt> GetPropInt() const;
	virtual TArray<FTestbed1StructInt> GetPropInt_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	void SetPropInt(const TArray<FTestbed1StructInt>& InPropInt);
	virtual void SetPropInt_Implementation(const TArray<FTestbed1StructInt>& InPropInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	TArray<FTestbed1StructFloat> GetPropFloat() const;
	virtual TArray<FTestbed1StructFloat> GetPropFloat_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	void SetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat);
	virtual void SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	TArray<FTestbed1StructString> GetPropString() const;
	virtual TArray<FTestbed1StructString> GetPropString_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Properties")
	void SetPropString(const TArray<FTestbed1StructString>& InPropString);
	virtual void SetPropString_Implementation(const TArray<FTestbed1StructString>& InPropString) = 0;

protected:
	// signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastSigBool(const TArray<FTestbed1StructBool>& ParamBool);
	virtual void BroadcastSigBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastSigInt(const TArray<FTestbed1StructInt>& ParamInt);
	virtual void BroadcastSigInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastSigFloat(const TArray<FTestbed1StructFloat>& ParamFloat);
	virtual void BroadcastSigFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastSigString(const TArray<FTestbed1StructString>& ParamString);
	virtual void BroadcastSigString_Implementation(const TArray<FTestbed1StructString>& ParamString) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastPropBoolChanged(const TArray<FTestbed1StructBool>& PropBool);
	virtual void BroadcastPropBoolChanged_Implementation(const TArray<FTestbed1StructBool>& PropBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastPropIntChanged(const TArray<FTestbed1StructInt>& PropInt);
	virtual void BroadcastPropIntChanged_Implementation(const TArray<FTestbed1StructInt>& PropInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastPropFloatChanged(const TArray<FTestbed1StructFloat>& PropFloat);
	virtual void BroadcastPropFloatChanged_Implementation(const TArray<FTestbed1StructFloat>& PropFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastPropStringChanged(const TArray<FTestbed1StructString>& PropString);
	virtual void BroadcastPropStringChanged_Implementation(const TArray<FTestbed1StructString>& PropString) = 0;
};
