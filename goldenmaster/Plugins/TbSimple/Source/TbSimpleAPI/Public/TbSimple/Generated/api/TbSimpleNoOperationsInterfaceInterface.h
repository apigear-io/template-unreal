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
#include "TbSimple_data.h"
#include "TbSimpleNoOperationsInterfaceInterface.generated.h"

/**
 * Declaration for NoOperationsInterface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTbSimpleNoOperationsInterfaceSigVoidDelegate);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfaceSigBoolDelegate, bool, bParamBool);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfacePropBoolChangedDelegate, bool, bPropBool);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoOperationsInterfacePropIntChangedDelegate, int32, PropInt);

/**
 * Class UTbSimpleNoOperationsInterfaceInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBSIMPLEAPI_API UTbSimpleNoOperationsInterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface|Signals", DisplayName = "SigVoid Signal")
	FTbSimpleNoOperationsInterfaceSigVoidDelegate OnSigVoidSignal;
	/// C++ wrapper for BP functions to safely call SigVoidSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Signals", DisplayName = "Broadcast SigVoid Signal")
	void BroadcastSigVoidSignal()
	{
		OnSigVoidSignal.Broadcast();
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface|Signals", DisplayName = "SigBool Signal")
	FTbSimpleNoOperationsInterfaceSigBoolDelegate OnSigBoolSignal;
	/// C++ wrapper for BP functions to safely call SigBoolSignal.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Signals", DisplayName = "Broadcast SigBool Signal")
	void BroadcastSigBoolSignal(bool bParamBool)
	{
		OnSigBoolSignal.Broadcast(bParamBool);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface|Signals", DisplayName = "Property PropBool Changed")
	FTbSimpleNoOperationsInterfacePropBoolChangedDelegate OnPropBoolChanged;
	/// C++ wrapper for BP functions to safely call OnPropBoolChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Signals", DisplayName = "Broadcast Property PropBool Changed")
	void BroadcastPropBoolChanged(UPARAM(DisplayName = "bPropBool") bool bInPropBool)
	{
		OnPropBoolChanged.Broadcast(bInPropBool);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface|Signals", DisplayName = "Property PropInt Changed")
	FTbSimpleNoOperationsInterfacePropIntChangedDelegate OnPropIntChanged;
	/// C++ wrapper for BP functions to safely call OnPropIntChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Signals", DisplayName = "Broadcast Property PropInt Changed")
	void BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") int32 InPropInt)
	{
		OnPropIntChanged.Broadcast(InPropInt);
	}
};

/**
 * Interface UTbSimpleNoOperationsInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbSimpleNoOperationsInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSimpleNoOperationsInterfaceInterface
 */
class TBSIMPLEAPI_API ITbSimpleNoOperationsInterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface")
	UTbSimpleNoOperationsInterfaceSignals* _GetSignals();
	virtual UTbSimpleNoOperationsInterfaceSignals* _GetSignals_Implementation() = 0;

	// methods

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Properties")
	bool GetPropBool() const;
	virtual bool GetPropBool_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Properties")
	void SetPropBool(bool bInPropBool);
	virtual void SetPropBool_Implementation(UPARAM(DisplayName = "bPropBool") bool bInPropBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Properties")
	int32 GetPropInt() const;
	virtual int32 GetPropInt_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Properties")
	void SetPropInt(int32 InPropInt);
	virtual void SetPropInt_Implementation(UPARAM(DisplayName = "PropInt") int32 InPropInt) = 0;
};
