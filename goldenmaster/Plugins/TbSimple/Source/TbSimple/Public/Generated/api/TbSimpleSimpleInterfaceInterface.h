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

#include <cinttypes>
#include <string>
#include <list>
#include "UObject/Interface.h"
#include "Engine/LatentActionManager.h"
#include "TbSimple_data.h"
#include "TbSimpleSimpleInterfaceInterface.generated.h"

/**
 * Declaration for SimpleInterface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigBoolDelegate, bool, bParamBool);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigIntDelegate, int32, ParamInt);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigFloatDelegate, float, ParamFloat);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigStringDelegate, const FString&, ParamString);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropBoolChangedDelegate, bool, bPropBool);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropIntChangedDelegate, int32, PropInt);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropFloatChangedDelegate, float, PropFloat);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropStringChangedDelegate, const FString&, PropString);

/**
 * Interface UTbSimpleSimpleInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTbSimpleSimpleInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITbSimpleSimpleInterfaceInterface
 */
class TBSIMPLE_API ITbSimpleSimpleInterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfaceSigIntDelegate& GetSigIntSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfaceSigStringDelegate& GetSigStringSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
	virtual FTbSimpleSimpleInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool);
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	bool FuncBool(bool bParamBool);
	virtual bool FuncBool_Implementation(bool bParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt);
	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	int32 FuncInt(int32 ParamInt);
	virtual int32 FuncInt_Implementation(int32 ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat);
	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	float FuncFloat(float ParamFloat);
	virtual float FuncFloat_Implementation(float ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString);
	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	FString FuncString(const FString& ParamString);
	virtual FString FuncString_Implementation(const FString& ParamString) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	bool GetPropBool() const;
	virtual bool GetPropBool_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void SetPropBool(bool bPropBool);
	virtual void SetPropBool_Implementation(bool bPropBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	int32 GetPropInt() const;
	virtual int32 GetPropInt_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void SetPropInt(int32 PropInt);
	virtual void SetPropInt_Implementation(int32 PropInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	float GetPropFloat() const;
	virtual float GetPropFloat_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void SetPropFloat(float PropFloat);
	virtual void SetPropFloat_Implementation(float PropFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	FString GetPropString() const;
	virtual FString GetPropString_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void SetPropString(const FString& PropString);
	virtual void SetPropString_Implementation(const FString& PropString) = 0;

protected:
	// signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void BroadcastSigBool(bool bParamBool);
	virtual void BroadcastSigBool_Implementation(bool bParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void BroadcastSigInt(int32 ParamInt);
	virtual void BroadcastSigInt_Implementation(int32 ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void BroadcastSigFloat(float ParamFloat);
	virtual void BroadcastSigFloat_Implementation(float ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void BroadcastSigString(const FString& ParamString);
	virtual void BroadcastSigString_Implementation(const FString& ParamString) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void BroadcastPropBoolChanged(bool bPropBool);
	virtual void BroadcastPropBoolChanged_Implementation(bool bPropBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void BroadcastPropIntChanged(int32 PropInt);
	virtual void BroadcastPropIntChanged_Implementation(int32 PropInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void BroadcastPropFloatChanged(float PropFloat);
	virtual void BroadcastPropFloatChanged_Implementation(float PropFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void BroadcastPropStringChanged(const FString& PropString);
	virtual void BroadcastPropStringChanged_Implementation(const FString& PropString) = 0;
};
