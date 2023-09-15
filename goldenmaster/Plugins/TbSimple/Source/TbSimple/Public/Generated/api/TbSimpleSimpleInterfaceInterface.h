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
#include "TbSimpleSimpleInterfaceInterface.generated.h"

/**
 * Declaration for SimpleInterface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTbSimpleSimpleInterfaceSigVoidDelegate);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigBoolDelegate, bool, bParamBool);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigIntDelegate, int32, ParamInt);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigInt32Delegate, int32, ParamInt32);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigInt64Delegate, int64, ParamInt64);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigFloatDelegate, float, ParamFloat);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigFloat32Delegate, float, ParamFloa32);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigFloat64Delegate, double, ParamFloat64);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfaceSigStringDelegate, const FString&, ParamString);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropBoolChangedDelegate, bool, bPropBool);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropIntChangedDelegate, int32, PropInt);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropInt32ChangedDelegate, int32, PropInt32);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropInt64ChangedDelegate, int64, PropInt64);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropFloatChangedDelegate, float, PropFloat);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropFloat32ChangedDelegate, float, PropFloat32);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropFloat64ChangedDelegate, double, PropFloat64);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropStringChangedDelegate, const FString&, PropString);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleSimpleInterfacePropReadOnlyStringChangedDelegate, const FString&, PropReadOnlyString);

/**
 * Class UTbSimpleSimpleInterfaceInterfaceSignals
 * Contains delegates for properties and signals
 * this is needed since we cannot declare delegates on an UInterface
 */
UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleSimpleInterfaceSignals : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "SigVoid Signal")
	FTbSimpleSimpleInterfaceSigVoidDelegate OnSigVoidSignal;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "SigBool Signal")
	FTbSimpleSimpleInterfaceSigBoolDelegate OnSigBoolSignal;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "SigInt Signal")
	FTbSimpleSimpleInterfaceSigIntDelegate OnSigIntSignal;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "SigInt32 Signal")
	FTbSimpleSimpleInterfaceSigInt32Delegate OnSigInt32Signal;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "SigInt64 Signal")
	FTbSimpleSimpleInterfaceSigInt64Delegate OnSigInt64Signal;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "SigFloat Signal")
	FTbSimpleSimpleInterfaceSigFloatDelegate OnSigFloatSignal;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "SigFloat32 Signal")
	FTbSimpleSimpleInterfaceSigFloat32Delegate OnSigFloat32Signal;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "SigFloat64 Signal")
	FTbSimpleSimpleInterfaceSigFloat64Delegate OnSigFloat64Signal;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "SigString Signal")
	FTbSimpleSimpleInterfaceSigStringDelegate OnSigStringSignal;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Property PropBool Changed")
	FTbSimpleSimpleInterfacePropBoolChangedDelegate OnPropBoolChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Property PropInt Changed")
	FTbSimpleSimpleInterfacePropIntChangedDelegate OnPropIntChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Property PropInt32 Changed")
	FTbSimpleSimpleInterfacePropInt32ChangedDelegate OnPropInt32Changed;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Property PropInt64 Changed")
	FTbSimpleSimpleInterfacePropInt64ChangedDelegate OnPropInt64Changed;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Property PropFloat Changed")
	FTbSimpleSimpleInterfacePropFloatChangedDelegate OnPropFloatChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Property PropFloat32 Changed")
	FTbSimpleSimpleInterfacePropFloat32ChangedDelegate OnPropFloat32Changed;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Property PropFloat64 Changed")
	FTbSimpleSimpleInterfacePropFloat64ChangedDelegate OnPropFloat64Changed;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Property PropString Changed")
	FTbSimpleSimpleInterfacePropStringChangedDelegate OnPropStringChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Signals", DisplayName = "Property PropReadOnlyString Changed")
	FTbSimpleSimpleInterfacePropReadOnlyStringChangedDelegate OnPropReadOnlyStringChanged;
};

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
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	UTbSimpleSimpleInterfaceSignals* _GetSignals();
	virtual UTbSimpleSimpleInterfaceSignals* _GetSignals_Implementation() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	void FuncVoid();
	virtual void FuncVoid_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool);
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	bool FuncBool(bool bParamBool);
	virtual bool FuncBool_Implementation(bool bParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt);
	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	int32 FuncInt(int32 ParamInt);
	virtual int32 FuncInt_Implementation(int32 ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncInt32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt32);
	virtual void FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	int32 FuncInt32(int32 ParamInt32);
	virtual int32 FuncInt32_Implementation(int32 ParamInt32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncInt64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int64& Result, int64 ParamInt64);
	virtual void FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int64& Result, int64 ParamInt64) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	int64 FuncInt64(int64 ParamInt64);
	virtual int64 FuncInt64_Implementation(int64 ParamInt64) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat);
	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	float FuncFloat(float ParamFloat);
	virtual float FuncFloat_Implementation(float ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloat32Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat32);
	virtual void FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	float FuncFloat32(float ParamFloat32);
	virtual float FuncFloat32_Implementation(float ParamFloat32) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloat64Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, double& Result, double ParamFloat);
	virtual void FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, double& Result, double ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	double FuncFloat64(double ParamFloat);
	virtual double FuncFloat64_Implementation(double ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString);
	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Operations")
	FString FuncString(const FString& ParamString);
	virtual FString FuncString_Implementation(const FString& ParamString) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	bool GetPropBool() const;
	virtual bool GetPropBool_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	void SetPropBool(bool bInPropBool);
	virtual void SetPropBool_Implementation(bool bInPropBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	int32 GetPropInt() const;
	virtual int32 GetPropInt_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	void SetPropInt(int32 InPropInt);
	virtual void SetPropInt_Implementation(int32 InPropInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	int32 GetPropInt32() const;
	virtual int32 GetPropInt32_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	void SetPropInt32(int32 InPropInt32);
	virtual void SetPropInt32_Implementation(int32 InPropInt32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	int64 GetPropInt64() const;
	virtual int64 GetPropInt64_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	void SetPropInt64(int64 InPropInt64);
	virtual void SetPropInt64_Implementation(int64 InPropInt64) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	float GetPropFloat() const;
	virtual float GetPropFloat_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	void SetPropFloat(float InPropFloat);
	virtual void SetPropFloat_Implementation(float InPropFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	float GetPropFloat32() const;
	virtual float GetPropFloat32_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	void SetPropFloat32(float InPropFloat32);
	virtual void SetPropFloat32_Implementation(float InPropFloat32) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	double GetPropFloat64() const;
	virtual double GetPropFloat64_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	void SetPropFloat64(double InPropFloat64);
	virtual void SetPropFloat64_Implementation(double InPropFloat64) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	FString GetPropString() const;
	virtual FString GetPropString_Implementation() const = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	void SetPropString(const FString& InPropString);
	virtual void SetPropString_Implementation(const FString& InPropString) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Properties")
	FString GetPropReadOnlyString() const;
	virtual FString GetPropReadOnlyString_Implementation() const = 0;
};
