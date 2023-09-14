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
#include "TbSimpleSimpleArrayInterfaceInterface.generated.h"

/**
 * Declaration for SimpleArrayInterface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigBoolDelegate, const TArray<bool>&, ParamBool);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigIntDelegate, const TArray<int32>&, ParamInt);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigInt32Delegate, const TArray<int32>&, ParamInt32);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigInt64Delegate, const TArray<int64>&, ParamInt64);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigFloatDelegate, const TArray<float>&, ParamFloat);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigFloat32Delegate, const TArray<float>&, ParamFloa32);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigFloat64Delegate, const TArray<double>&, ParamFloat64);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfaceSigStringDelegate, const TArray<FString>&, ParamString);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate, const TArray<bool>&, PropBool);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropIntChangedDelegate, const TArray<int32>&, PropInt);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropInt32ChangedDelegate, const TArray<int32>&, PropInt32);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropInt64ChangedDelegate, const TArray<int64>&, PropInt64);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate, const TArray<float>&, PropFloat);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropFloat32ChangedDelegate, const TArray<float>&, PropFloat32);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleArrayInterfacePropFloat64ChangedDelegate, const TArray<double>&, PropFloat64);

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
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	virtual FTbSimpleSimpleArrayInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	virtual FTbSimpleSimpleArrayInterfaceSigIntDelegate& GetSigIntSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	virtual FTbSimpleSimpleArrayInterfaceSigInt32Delegate& GetSigInt32SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	virtual FTbSimpleSimpleArrayInterfaceSigInt64Delegate& GetSigInt64SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	virtual FTbSimpleSimpleArrayInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	virtual FTbSimpleSimpleArrayInterfaceSigFloat32Delegate& GetSigFloat32SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	virtual FTbSimpleSimpleArrayInterfaceSigFloat64Delegate& GetSigFloat64SignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	virtual FTbSimpleSimpleArrayInterfaceSigStringDelegate& GetSigStringSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	virtual FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	virtual FTbSimpleSimpleArrayInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	virtual FTbSimpleSimpleArrayInterfacePropInt32ChangedDelegate& GetPropInt32ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	virtual FTbSimpleSimpleArrayInterfacePropInt64ChangedDelegate& GetPropInt64ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	virtual FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	virtual FTbSimpleSimpleArrayInterfacePropFloat32ChangedDelegate& GetPropFloat32ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	virtual FTbSimpleSimpleArrayInterfacePropFloat64ChangedDelegate& GetPropFloat64ChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals")
	virtual FTbSimpleSimpleArrayInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool);
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	TArray<bool> FuncBool(const TArray<bool>& ParamBool);
	virtual TArray<bool> FuncBool_Implementation(const TArray<bool>& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt);
	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	TArray<int32> FuncInt(const TArray<int32>& ParamInt);
	virtual TArray<int32> FuncInt_Implementation(const TArray<int32>& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncInt32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32);
	virtual void FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	TArray<int32> FuncInt32(const TArray<int32>& ParamInt32);
	virtual TArray<int32> FuncInt32_Implementation(const TArray<int32>& ParamInt32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncInt64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64);
	virtual void FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int64>& Result, const TArray<int64>& ParamInt64) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	TArray<int64> FuncInt64(const TArray<int64>& ParamInt64);
	virtual TArray<int64> FuncInt64_Implementation(const TArray<int64>& ParamInt64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat);
	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	TArray<float> FuncFloat(const TArray<float>& ParamFloat);
	virtual TArray<float> FuncFloat_Implementation(const TArray<float>& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloat32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32);
	virtual void FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	TArray<float> FuncFloat32(const TArray<float>& ParamFloat32);
	virtual TArray<float> FuncFloat32_Implementation(const TArray<float>& ParamFloat32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloat64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat);
	virtual void FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<double>& Result, const TArray<double>& ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	TArray<double> FuncFloat64(const TArray<double>& ParamFloat);
	virtual TArray<double> FuncFloat64_Implementation(const TArray<double>& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString);
	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Operations")
	TArray<FString> FuncString(const TArray<FString>& ParamString);
	virtual TArray<FString> FuncString_Implementation(const TArray<FString>& ParamString) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	TArray<bool> GetPropBool() const;
	virtual TArray<bool> GetPropBool_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void SetPropBool(const TArray<bool>& InPropBool);
	virtual void SetPropBool_Implementation(const TArray<bool>& InPropBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	TArray<int32> GetPropInt() const;
	virtual TArray<int32> GetPropInt_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void SetPropInt(const TArray<int32>& InPropInt);
	virtual void SetPropInt_Implementation(const TArray<int32>& InPropInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	TArray<int32> GetPropInt32() const;
	virtual TArray<int32> GetPropInt32_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void SetPropInt32(const TArray<int32>& InPropInt32);
	virtual void SetPropInt32_Implementation(const TArray<int32>& InPropInt32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	TArray<int64> GetPropInt64() const;
	virtual TArray<int64> GetPropInt64_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void SetPropInt64(const TArray<int64>& InPropInt64);
	virtual void SetPropInt64_Implementation(const TArray<int64>& InPropInt64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	TArray<float> GetPropFloat() const;
	virtual TArray<float> GetPropFloat_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void SetPropFloat(const TArray<float>& InPropFloat);
	virtual void SetPropFloat_Implementation(const TArray<float>& InPropFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	TArray<float> GetPropFloat32() const;
	virtual TArray<float> GetPropFloat32_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void SetPropFloat32(const TArray<float>& InPropFloat32);
	virtual void SetPropFloat32_Implementation(const TArray<float>& InPropFloat32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	TArray<double> GetPropFloat64() const;
	virtual TArray<double> GetPropFloat64_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void SetPropFloat64(const TArray<double>& InPropFloat64);
	virtual void SetPropFloat64_Implementation(const TArray<double>& InPropFloat64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	TArray<FString> GetPropString() const;
	virtual TArray<FString> GetPropString_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Properties")
	void SetPropString(const TArray<FString>& InPropString);
	virtual void SetPropString_Implementation(const TArray<FString>& InPropString) = 0;

protected:
	// signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastSigBool(const TArray<bool>& ParamBool);
	virtual void BroadcastSigBool_Implementation(const TArray<bool>& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastSigInt(const TArray<int32>& ParamInt);
	virtual void BroadcastSigInt_Implementation(const TArray<int32>& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastSigInt32(const TArray<int32>& ParamInt32);
	virtual void BroadcastSigInt32_Implementation(const TArray<int32>& ParamInt32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastSigInt64(const TArray<int64>& ParamInt64);
	virtual void BroadcastSigInt64_Implementation(const TArray<int64>& ParamInt64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastSigFloat(const TArray<float>& ParamFloat);
	virtual void BroadcastSigFloat_Implementation(const TArray<float>& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastSigFloat32(const TArray<float>& ParamFloa32);
	virtual void BroadcastSigFloat32_Implementation(const TArray<float>& ParamFloa32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastSigFloat64(const TArray<double>& ParamFloat64);
	virtual void BroadcastSigFloat64_Implementation(const TArray<double>& ParamFloat64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastSigString(const TArray<FString>& ParamString);
	virtual void BroadcastSigString_Implementation(const TArray<FString>& ParamString) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastPropBoolChanged(const TArray<bool>& PropBool);
	virtual void BroadcastPropBoolChanged_Implementation(const TArray<bool>& PropBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastPropIntChanged(const TArray<int32>& PropInt);
	virtual void BroadcastPropIntChanged_Implementation(const TArray<int32>& PropInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastPropInt32Changed(const TArray<int32>& PropInt32);
	virtual void BroadcastPropInt32Changed_Implementation(const TArray<int32>& PropInt32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastPropInt64Changed(const TArray<int64>& PropInt64);
	virtual void BroadcastPropInt64Changed_Implementation(const TArray<int64>& PropInt64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastPropFloatChanged(const TArray<float>& PropFloat);
	virtual void BroadcastPropFloatChanged_Implementation(const TArray<float>& PropFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastPropFloat32Changed(const TArray<float>& PropFloat32);
	virtual void BroadcastPropFloat32Changed_Implementation(const TArray<float>& PropFloat32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastPropFloat64Changed(const TArray<double>& PropFloat64);
	virtual void BroadcastPropFloat64Changed_Implementation(const TArray<double>& PropFloat64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Signals", meta = (BlueprintProtected = "true"))
	void BroadcastPropStringChanged(const TArray<FString>& PropString);
	virtual void BroadcastPropStringChanged_Implementation(const TArray<FString>& PropString) = 0;
};
