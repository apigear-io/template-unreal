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
#include "Testbed1StructInterfaceInterface.generated.h"

/**
 * Declaration for StructInterface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructInterfaceSigBoolDelegate, const FTestbed1StructBool&, ParamBool);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructInterfaceSigIntDelegate, const FTestbed1StructInt&, ParamInt);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructInterfaceSigFloatDelegate, const FTestbed1StructFloat&, ParamFloat);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructInterfaceSigStringDelegate, const FTestbed1StructString&, ParamString);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructInterfacePropBoolChangedDelegate, const FTestbed1StructBool&, PropBool);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructInterfacePropIntChangedDelegate, const FTestbed1StructInt&, PropInt);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructInterfacePropFloatChangedDelegate, const FTestbed1StructFloat&, PropFloat);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1StructInterfacePropStringChangedDelegate, const FTestbed1StructString&, PropString);

/**
 * Class UTestbed1StructInterfaceInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TESTBED1API_API UTestbed1StructInterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "SigBool Signal")
	FTestbed1StructInterfaceSigBoolDelegate OnSigBoolSignal;
	/// C++ wrapper for BP functions to safely call SigBoolSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "Broadcast SigBool Signal")
	void BroadcastSigBoolSignal(const FTestbed1StructBool& ParamBool)
	{
		OnSigBoolSignal.Broadcast(ParamBool);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "SigInt Signal")
	FTestbed1StructInterfaceSigIntDelegate OnSigIntSignal;
	/// C++ wrapper for BP functions to safely call SigIntSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "Broadcast SigInt Signal")
	void BroadcastSigIntSignal(const FTestbed1StructInt& ParamInt)
	{
		OnSigIntSignal.Broadcast(ParamInt);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "SigFloat Signal")
	FTestbed1StructInterfaceSigFloatDelegate OnSigFloatSignal;
	/// C++ wrapper for BP functions to safely call SigFloatSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "Broadcast SigFloat Signal")
	void BroadcastSigFloatSignal(const FTestbed1StructFloat& ParamFloat)
	{
		OnSigFloatSignal.Broadcast(ParamFloat);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "SigString Signal")
	FTestbed1StructInterfaceSigStringDelegate OnSigStringSignal;
	/// C++ wrapper for BP functions to safely call SigStringSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "Broadcast SigString Signal")
	void BroadcastSigStringSignal(const FTestbed1StructString& ParamString)
	{
		OnSigStringSignal.Broadcast(ParamString);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "Property PropBool Changed")
	FTestbed1StructInterfacePropBoolChangedDelegate OnPropBoolChanged;
	/// C++ wrapper for BP functions to safely call OnPropBoolChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "Broadcast Property PropBool Changed")
	void BroadcastPropBoolChanged(UPARAM(DisplayName = "PropBool") const FTestbed1StructBool& InPropBool)
	{
		OnPropBoolChanged.Broadcast(InPropBool);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "Property PropInt Changed")
	FTestbed1StructInterfacePropIntChangedDelegate OnPropIntChanged;
	/// C++ wrapper for BP functions to safely call OnPropIntChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "Broadcast Property PropInt Changed")
	void BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") const FTestbed1StructInt& InPropInt)
	{
		OnPropIntChanged.Broadcast(InPropInt);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "Property PropFloat Changed")
	FTestbed1StructInterfacePropFloatChangedDelegate OnPropFloatChanged;
	/// C++ wrapper for BP functions to safely call OnPropFloatChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "Broadcast Property PropFloat Changed")
	void BroadcastPropFloatChanged(UPARAM(DisplayName = "PropFloat") const FTestbed1StructFloat& InPropFloat)
	{
		OnPropFloatChanged.Broadcast(InPropFloat);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "Property PropString Changed")
	FTestbed1StructInterfacePropStringChangedDelegate OnPropStringChanged;
	/// C++ wrapper for BP functions to safely call OnPropStringChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Signals", DisplayName = "Broadcast Property PropString Changed")
	void BroadcastPropStringChanged(UPARAM(DisplayName = "PropString") const FTestbed1StructString& InPropString)
	{
		OnPropStringChanged.Broadcast(InPropString);
	}
};

/**
 * Interface UTestbed1StructInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTestbed1StructInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed1StructInterfaceInterface
 */
class TESTBED1API_API ITestbed1StructInterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	UTestbed1StructInterfaceSignals* _GetSignals();
	virtual UTestbed1StructInterfaceSignals* _GetSignals_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool);
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Operations")
	FTestbed1StructBool FuncBool(const FTestbed1StructBool& ParamBool);
	virtual FTestbed1StructBool FuncBool_Implementation(const FTestbed1StructBool& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructInt& Result, const FTestbed1StructInt& ParamInt);
	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructInt& Result, const FTestbed1StructInt& ParamInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Operations")
	FTestbed1StructInt FuncInt(const FTestbed1StructInt& ParamInt);
	virtual FTestbed1StructInt FuncInt_Implementation(const FTestbed1StructInt& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat);
	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Operations")
	FTestbed1StructFloat FuncFloat(const FTestbed1StructFloat& ParamFloat);
	virtual FTestbed1StructFloat FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString);
	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Operations")
	FTestbed1StructString FuncString(const FTestbed1StructString& ParamString);
	virtual FTestbed1StructString FuncString_Implementation(const FTestbed1StructString& ParamString) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	FTestbed1StructBool GetPropBool() const;
	virtual FTestbed1StructBool GetPropBool_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	void SetPropBool(const FTestbed1StructBool& InPropBool);
	virtual void SetPropBool_Implementation(UPARAM(DisplayName = "PropBool") const FTestbed1StructBool& InPropBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	FTestbed1StructInt GetPropInt() const;
	virtual FTestbed1StructInt GetPropInt_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	void SetPropInt(const FTestbed1StructInt& InPropInt);
	virtual void SetPropInt_Implementation(UPARAM(DisplayName = "PropInt") const FTestbed1StructInt& InPropInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	FTestbed1StructFloat GetPropFloat() const;
	virtual FTestbed1StructFloat GetPropFloat_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	void SetPropFloat(const FTestbed1StructFloat& InPropFloat);
	virtual void SetPropFloat_Implementation(UPARAM(DisplayName = "PropFloat") const FTestbed1StructFloat& InPropFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	FTestbed1StructString GetPropString() const;
	virtual FTestbed1StructString GetPropString_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Properties")
	void SetPropString(const FTestbed1StructString& InPropString);
	virtual void SetPropString_Implementation(UPARAM(DisplayName = "PropString") const FTestbed1StructString& InPropString) = 0;
};
