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
#include "Generated/api/Testbed1_data.h"
#include "Testbed1StructArray2InterfaceInterface.generated.h"

/**
 * Declaration for StructArray2Interface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceSigBoolDelegate, const FTestbed1StructBoolWithArray&, ParamBool);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceSigIntDelegate, const FTestbed1StructIntWithArray&, ParamInt);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceSigFloatDelegate, const FTestbed1StructFloatWithArray&, ParamFloat);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfaceSigStringDelegate, const FTestbed1StructStringWithArray&, ParamString);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfacePropBoolChangedDelegate, const FTestbed1StructBoolWithArray&, PropBool);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfacePropIntChangedDelegate, const FTestbed1StructIntWithArray&, PropInt);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfacePropFloatChangedDelegate, const FTestbed1StructFloatWithArray&, PropFloat);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfacePropStringChangedDelegate, const FTestbed1StructStringWithArray&, PropString);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructArray2InterfacePropEnumChangedDelegate, const FTestbed1StructEnumWithArray&, PropEnum);

/**
 * Class UTestbed1StructArray2InterfaceInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TESTBED1_API UTestbed1StructArray2InterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "SigBool Signal")
	FTestbed1StructArray2InterfaceSigBoolDelegate OnSigBoolSignal;
	/// C++ wrapper for BP functions to safely call SigBoolSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast SigBool Signal")
	void BroadcastSigBoolSignal(const FTestbed1StructBoolWithArray& ParamBool)
	{
		OnSigBoolSignal.Broadcast(ParamBool);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "SigInt Signal")
	FTestbed1StructArray2InterfaceSigIntDelegate OnSigIntSignal;
	/// C++ wrapper for BP functions to safely call SigIntSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast SigInt Signal")
	void BroadcastSigIntSignal(const FTestbed1StructIntWithArray& ParamInt)
	{
		OnSigIntSignal.Broadcast(ParamInt);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "SigFloat Signal")
	FTestbed1StructArray2InterfaceSigFloatDelegate OnSigFloatSignal;
	/// C++ wrapper for BP functions to safely call SigFloatSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast SigFloat Signal")
	void BroadcastSigFloatSignal(const FTestbed1StructFloatWithArray& ParamFloat)
	{
		OnSigFloatSignal.Broadcast(ParamFloat);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "SigString Signal")
	FTestbed1StructArray2InterfaceSigStringDelegate OnSigStringSignal;
	/// C++ wrapper for BP functions to safely call SigStringSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast SigString Signal")
	void BroadcastSigStringSignal(const FTestbed1StructStringWithArray& ParamString)
	{
		OnSigStringSignal.Broadcast(ParamString);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Property PropBool Changed")
	FTestbed1StructArray2InterfacePropBoolChangedDelegate OnPropBoolChanged;
	/// C++ wrapper for BP functions to safely call OnPropBoolChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast Property PropBool Changed")
	void BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const FTestbed1StructBoolWithArray& InPropBool)
	{
		OnPropBoolChanged.Broadcast(InPropBool);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Property PropInt Changed")
	FTestbed1StructArray2InterfacePropIntChangedDelegate OnPropIntChanged;
	/// C++ wrapper for BP functions to safely call OnPropIntChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast Property PropInt Changed")
	void BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const FTestbed1StructIntWithArray& InPropInt)
	{
		OnPropIntChanged.Broadcast(InPropInt);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Property PropFloat Changed")
	FTestbed1StructArray2InterfacePropFloatChangedDelegate OnPropFloatChanged;
	/// C++ wrapper for BP functions to safely call OnPropFloatChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast Property PropFloat Changed")
	void BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const FTestbed1StructFloatWithArray& InPropFloat)
	{
		OnPropFloatChanged.Broadcast(InPropFloat);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Property PropString Changed")
	FTestbed1StructArray2InterfacePropStringChangedDelegate OnPropStringChanged;
	/// C++ wrapper for BP functions to safely call OnPropStringChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast Property PropString Changed")
	void BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const FTestbed1StructStringWithArray& InPropString)
	{
		OnPropStringChanged.Broadcast(InPropString);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Property PropEnum Changed")
	FTestbed1StructArray2InterfacePropEnumChangedDelegate OnPropEnumChanged;
	/// C++ wrapper for BP functions to safely call OnPropEnumChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Signals", DisplayName = "Broadcast Property PropEnum Changed")
	void BroadcastPropEnumChanged(UPARAM(DisplayName = "PropEnum") const FTestbed1StructEnumWithArray& InPropEnum)
	{
		OnPropEnumChanged.Broadcast(InPropEnum);
	}
};

/**
 * Interface UTestbed1StructArray2InterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTestbed1StructArray2InterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed1StructArray2InterfaceInterface
 */
class TESTBED1_API ITestbed1StructArray2InterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface")
	UTestbed1StructArray2InterfaceSignals* _GetSignals();
	virtual UTestbed1StructArray2InterfaceSignals* _GetSignals_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructBool>& Result, const FTestbed1StructBoolWithArray& ParamBool);
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructBool>& Result, const FTestbed1StructBoolWithArray& ParamBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations")
	TArray<FTestbed1StructBool> FuncBool(const FTestbed1StructBoolWithArray& ParamBool);
	virtual TArray<FTestbed1StructBool> FuncBool_Implementation(const FTestbed1StructBoolWithArray& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructInt>& Result, const FTestbed1StructIntWithArray& ParamInt);
	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructInt>& Result, const FTestbed1StructIntWithArray& ParamInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations")
	TArray<FTestbed1StructInt> FuncInt(const FTestbed1StructIntWithArray& ParamInt);
	virtual TArray<FTestbed1StructInt> FuncInt_Implementation(const FTestbed1StructIntWithArray& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructFloat>& Result, const FTestbed1StructFloatWithArray& ParamFloat);
	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructFloat>& Result, const FTestbed1StructFloatWithArray& ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations")
	TArray<FTestbed1StructFloat> FuncFloat(const FTestbed1StructFloatWithArray& ParamFloat);
	virtual TArray<FTestbed1StructFloat> FuncFloat_Implementation(const FTestbed1StructFloatWithArray& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructString>& Result, const FTestbed1StructStringWithArray& ParamString);
	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FTestbed1StructString>& Result, const FTestbed1StructStringWithArray& ParamString) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations")
	TArray<FTestbed1StructString> FuncString(const FTestbed1StructStringWithArray& ParamString);
	virtual TArray<FTestbed1StructString> FuncString_Implementation(const FTestbed1StructStringWithArray& ParamString) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncEnumAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<ETestbed1Enum0>& Result, const FTestbed1StructEnumWithArray& ParamEnum);
	virtual void FuncEnumAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<ETestbed1Enum0>& Result, const FTestbed1StructEnumWithArray& ParamEnum) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Operations")
	TArray<ETestbed1Enum0> FuncEnum(const FTestbed1StructEnumWithArray& ParamEnum);
	virtual TArray<ETestbed1Enum0> FuncEnum_Implementation(const FTestbed1StructEnumWithArray& ParamEnum) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	FTestbed1StructBoolWithArray GetPropBool() const;
	virtual FTestbed1StructBoolWithArray GetPropBool_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	void SetPropBool(const FTestbed1StructBoolWithArray& InPropBool);
	virtual void SetPropBool_Implementation(UPARAM(DisplayName = "PropBool") const FTestbed1StructBoolWithArray& InPropBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	FTestbed1StructIntWithArray GetPropInt() const;
	virtual FTestbed1StructIntWithArray GetPropInt_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	void SetPropInt(const FTestbed1StructIntWithArray& InPropInt);
	virtual void SetPropInt_Implementation(UPARAM(DisplayName = "PropInt") const FTestbed1StructIntWithArray& InPropInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	FTestbed1StructFloatWithArray GetPropFloat() const;
	virtual FTestbed1StructFloatWithArray GetPropFloat_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	void SetPropFloat(const FTestbed1StructFloatWithArray& InPropFloat);
	virtual void SetPropFloat_Implementation(UPARAM(DisplayName = "PropFloat") const FTestbed1StructFloatWithArray& InPropFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	FTestbed1StructStringWithArray GetPropString() const;
	virtual FTestbed1StructStringWithArray GetPropString_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	void SetPropString(const FTestbed1StructStringWithArray& InPropString);
	virtual void SetPropString_Implementation(UPARAM(DisplayName = "PropString") const FTestbed1StructStringWithArray& InPropString) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	FTestbed1StructEnumWithArray GetPropEnum() const;
	virtual FTestbed1StructEnumWithArray GetPropEnum_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Properties")
	void SetPropEnum(const FTestbed1StructEnumWithArray& InPropEnum);
	virtual void SetPropEnum_Implementation(UPARAM(DisplayName = "PropEnum") const FTestbed1StructEnumWithArray& InPropEnum) = 0;
};
