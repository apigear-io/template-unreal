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
#include "TbNames_data.h"
#include "TbNamesNamEsInterface.generated.h"

/**
 * Declaration for Nam_Es
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsSomeSignalDelegate, bool, bSomeParam);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsSomeSignal2Delegate, bool, bSomeParam);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsSwitchChangedDelegate, bool, bSwitch);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsSomePropertyChangedDelegate, int32, SomeProperty);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbNamesNamEsSomePoperty2ChangedDelegate, int32, SomePoperty2);

/**
 * Class UTbNamesNamEsInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBNAMESAPI_API UTbNamesNamEsSignals : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "SomeSignal Signal")
	FTbNamesNamEsSomeSignalDelegate OnSomeSignalSignal;
	/// C++ wrapper for BP functions to safely call SomeSignalSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Broadcast SomeSignal Signal")
	void BroadcastSomeSignalSignal(bool bSomeParam)
	{
		OnSomeSignalSignal.Broadcast(bSomeParam);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "SomeSignal2 Signal")
	FTbNamesNamEsSomeSignal2Delegate OnSomeSignal2Signal;
	/// C++ wrapper for BP functions to safely call SomeSignal2Signal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Broadcast SomeSignal2 Signal")
	void BroadcastSomeSignal2Signal(bool bSomeParam)
	{
		OnSomeSignal2Signal.Broadcast(bSomeParam);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Property Switch Changed")
	FTbNamesNamEsSwitchChangedDelegate OnSwitchChanged;
	/// C++ wrapper for BP functions to safely call OnSwitchChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Broadcast Property Switch Changed")
	void BroadcastSwitchChanged(UPARAM(DisplayName = "bSwitch") bool bInSwitch)
	{
		OnSwitchChanged.Broadcast(bInSwitch);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Property SomeProperty Changed")
	FTbNamesNamEsSomePropertyChangedDelegate OnSomePropertyChanged;
	/// C++ wrapper for BP functions to safely call OnSomePropertyChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Broadcast Property SomeProperty Changed")
	void BroadcastSomePropertyChanged(UPARAM(DisplayName = "SomeProperty") int32 InSomeProperty)
	{
		OnSomePropertyChanged.Broadcast(InSomeProperty);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Property SomePoperty2 Changed")
	FTbNamesNamEsSomePoperty2ChangedDelegate OnSomePoperty2Changed;
	/// C++ wrapper for BP functions to safely call OnSomePoperty2Changed.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Signals", DisplayName = "Broadcast Property SomePoperty2 Changed")
	void BroadcastSomePoperty2Changed(UPARAM(DisplayName = "SomePoperty2") int32 InSomePoperty2)
	{
		OnSomePoperty2Changed.Broadcast(InSomePoperty2);
	}
};

/**
 * Interface UTbNamesNamEsInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbNamesNamEsInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbNamesNamEsInterface
 */
class TBNAMESAPI_API ITbNamesNamEsInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs")
	UTbNamesNamEsSignals* _GetSignals();
	virtual UTbNamesNamEsSignals* _GetSignals_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Operations")
	void SomeFunction(bool bSomeParam);
	virtual void SomeFunction_Implementation(bool bSomeParam) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Operations")
	void SomeFunction2(bool bSomeParam);
	virtual void SomeFunction2_Implementation(bool bSomeParam) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	bool GetSwitch() const;
	virtual bool GetSwitch_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	void SetSwitch(bool bInSwitch);
	virtual void SetSwitch_Implementation(UPARAM(DisplayName = "bSwitch") bool bInSwitch) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	int32 GetSomeProperty() const;
	virtual int32 GetSomeProperty_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	void SetSomeProperty(int32 InSomeProperty);
	virtual void SetSomeProperty_Implementation(UPARAM(DisplayName = "SomeProperty") int32 InSomeProperty) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	int32 GetSomePoperty2() const;
	virtual int32 GetSomePoperty2_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	void SetSomePoperty2(int32 InSomePoperty2);
	virtual void SetSomePoperty2_Implementation(UPARAM(DisplayName = "SomePoperty2") int32 InSomePoperty2) = 0;
};
