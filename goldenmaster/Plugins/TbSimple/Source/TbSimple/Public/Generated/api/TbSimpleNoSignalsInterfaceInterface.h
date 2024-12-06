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
#include "Generated/api/TbSimple_data.h"
#include "TbSimpleNoSignalsInterfaceInterface.generated.h"

/**
 * Declaration for NoSignalsInterface
 */
// signal delegates
// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoSignalsInterfacePropBoolChangedDelegate, bool, bPropBool);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleNoSignalsInterfacePropIntChangedDelegate, int32, PropInt);

/**
 * Class UTbSimpleNoSignalsInterfaceInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleNoSignalsInterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoSignalsInterface|Signals", DisplayName = "Property PropBool Changed")
	FTbSimpleNoSignalsInterfacePropBoolChangedDelegate OnPropBoolChanged;
	/// C++ wrapper for BP functions to safely call OnPropBoolChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface|Signals", DisplayName = "Broadcast Property PropBool Changed")
	void BroadcastPropBoolChanged(UPARAM(DisplayName = "bPropBool") bool bInPropBool)
	{
		OnPropBoolChanged.Broadcast(bInPropBool);
	}

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoSignalsInterface|Signals", DisplayName = "Property PropInt Changed")
	FTbSimpleNoSignalsInterfacePropIntChangedDelegate OnPropIntChanged;
	/// C++ wrapper for BP functions to safely call OnPropIntChanged.Broadcast
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface|Signals", DisplayName = "Broadcast Property PropInt Changed")
	void BroadcastPropIntChanged(UPARAM(DisplayName = "PropInt") int32 InPropInt)
	{
		OnPropIntChanged.Broadcast(InPropInt);
	}
};

/**
 * Interface UTbSimpleNoSignalsInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbSimpleNoSignalsInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSimpleNoSignalsInterfaceInterface
 */
class TBSIMPLE_API ITbSimpleNoSignalsInterfaceInterface
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface")
	UTbSimpleNoSignalsInterfaceSignals* _GetSignals();
	virtual UTbSimpleNoSignalsInterfaceSignals* _GetSignals_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface|Operations")
	void FuncVoid();
	virtual void FuncVoid_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool);
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface|Operations")
	bool FuncBool(bool bParamBool);
	virtual bool FuncBool_Implementation(bool bParamBool) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface|Properties")
	bool GetPropBool() const;
	virtual bool GetPropBool_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface|Properties")
	void SetPropBool(bool bInPropBool);
	virtual void SetPropBool_Implementation(UPARAM(DisplayName = "bPropBool") bool bInPropBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface|Properties")
	int32 GetPropInt() const;
	virtual int32 GetPropInt_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface|Properties")
	void SetPropInt(int32 InPropInt);
	virtual void SetPropInt_Implementation(UPARAM(DisplayName = "PropInt") int32 InPropInt) = 0;
};
