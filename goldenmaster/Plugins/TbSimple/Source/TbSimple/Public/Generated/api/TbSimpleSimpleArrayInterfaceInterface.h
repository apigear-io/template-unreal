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
#include "TbSimple_data.h"
#include "TbSimpleSimpleArrayInterfaceInterface.generated.h"

/**
 * Declaration for SimpleArrayInterface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigBoolDelegate, const TArray<bool>&, ParamBool);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigIntDelegate, const TArray<int32>&, ParamInt);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigFloatDelegate, const TArray<float>&, ParamFloat);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigStringDelegate, const TArray<FString>&, ParamString);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate, const TArray<bool>&, PropBool);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropIntChangedDelegate, const TArray<int32>&, PropInt);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate, const TArray<float>&, PropFloat);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropStringChangedDelegate, const TArray<FString>&, PropString);

/**
 * Interface UTbSimpleSimpleArrayInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbSimpleSimpleArrayInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSimpleSimpleArrayInterfaceInterface
 */
class TBSIMPLE_API ITbSimpleSimpleArrayInterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigIntDelegate& GetSigIntSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfaceSigStringDelegate& GetSigStringSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
	virtual FTbSimpleSimpleArrayInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool);
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<bool> FuncBool(const TArray<bool>& ParamBool);
	virtual TArray<bool> FuncBool_Implementation(const TArray<bool>& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt);
	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int32> FuncInt(const TArray<int32>& ParamInt);
	virtual TArray<int32> FuncInt_Implementation(const TArray<int32>& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat);
	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<float> FuncFloat(const TArray<float>& ParamFloat);
	virtual TArray<float> FuncFloat_Implementation(const TArray<float>& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString);
	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<FString> FuncString(const TArray<FString>& ParamString);
	virtual TArray<FString> FuncString_Implementation(const TArray<FString>& ParamString) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<bool> GetPropBool() const;
	virtual TArray<bool> GetPropBool_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void SetPropBool(const TArray<bool>& PropBool);
	virtual void SetPropBool_Implementation(const TArray<bool>& PropBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int32> GetPropInt() const;
	virtual TArray<int32> GetPropInt_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void SetPropInt(const TArray<int32>& PropInt);
	virtual void SetPropInt_Implementation(const TArray<int32>& PropInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<float> GetPropFloat() const;
	virtual TArray<float> GetPropFloat_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void SetPropFloat(const TArray<float>& PropFloat);
	virtual void SetPropFloat_Implementation(const TArray<float>& PropFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<FString> GetPropString() const;
	virtual TArray<FString> GetPropString_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void SetPropString(const TArray<FString>& PropString);
	virtual void SetPropString_Implementation(const TArray<FString>& PropString) = 0;

protected:
	// signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigBool(const TArray<bool>& ParamBool);
	virtual void BroadcastSigBool_Implementation(const TArray<bool>& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigInt(const TArray<int32>& ParamInt);
	virtual void BroadcastSigInt_Implementation(const TArray<int32>& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigFloat(const TArray<float>& ParamFloat);
	virtual void BroadcastSigFloat_Implementation(const TArray<float>& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigString(const TArray<FString>& ParamString);
	virtual void BroadcastSigString_Implementation(const TArray<FString>& ParamString) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropBoolChanged(const TArray<bool>& PropBool);
	virtual void BroadcastPropBoolChanged_Implementation(const TArray<bool>& PropBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropIntChanged(const TArray<int32>& PropInt);
	virtual void BroadcastPropIntChanged_Implementation(const TArray<int32>& PropInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropFloatChanged(const TArray<float>& PropFloat);
	virtual void BroadcastPropFloatChanged_Implementation(const TArray<float>& PropFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropStringChanged(const TArray<FString>& PropString);
	virtual void BroadcastPropStringChanged_Implementation(const TArray<FString>& PropString) = 0;
};
