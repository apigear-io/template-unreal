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
#include "Subsystems/GameInstanceSubsystem.h"
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
	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
	virtual FTestbed1StructArrayInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
	virtual FTestbed1StructArrayInterfaceSigIntDelegate& GetSigIntSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
	virtual FTestbed1StructArrayInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
	virtual FTestbed1StructArrayInterfaceSigStringDelegate& GetSigStringSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
	virtual FTestbed1StructArrayInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
	virtual FTestbed1StructArrayInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
	virtual FTestbed1StructArrayInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
	virtual FTestbed1StructArrayInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructBool>& ParamBool);
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructBool>& ParamBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	FTestbed1StructBool FuncBool(const TArray<FTestbed1StructBool>& ParamBool);
	virtual FTestbed1StructBool FuncBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructInt>& ParamInt);
	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructInt>& ParamInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	FTestbed1StructBool FuncInt(const TArray<FTestbed1StructInt>& ParamInt);
	virtual FTestbed1StructBool FuncInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructFloat>& ParamFloat);
	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructFloat>& ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	FTestbed1StructBool FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat);
	virtual FTestbed1StructBool FuncFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructString>& ParamString);
	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructString>& ParamString) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	FTestbed1StructBool FuncString(const TArray<FTestbed1StructString>& ParamString);
	virtual FTestbed1StructBool FuncString_Implementation(const TArray<FTestbed1StructString>& ParamString) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructBool> GetPropBool() const;
	virtual TArray<FTestbed1StructBool> GetPropBool_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	void SetPropBool(const TArray<FTestbed1StructBool>& InPropBool);
	virtual void SetPropBool_Implementation(const TArray<FTestbed1StructBool>& InPropBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructInt> GetPropInt() const;
	virtual TArray<FTestbed1StructInt> GetPropInt_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	void SetPropInt(const TArray<FTestbed1StructInt>& InPropInt);
	virtual void SetPropInt_Implementation(const TArray<FTestbed1StructInt>& InPropInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructFloat> GetPropFloat() const;
	virtual TArray<FTestbed1StructFloat> GetPropFloat_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	void SetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat);
	virtual void SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructString> GetPropString() const;
	virtual TArray<FTestbed1StructString> GetPropString_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	void SetPropString(const TArray<FTestbed1StructString>& InPropString);
	virtual void SetPropString_Implementation(const TArray<FTestbed1StructString>& InPropString) = 0;

protected:
	// signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigBool(const TArray<FTestbed1StructBool>& ParamBool);
	virtual void BroadcastSigBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigInt(const TArray<FTestbed1StructInt>& ParamInt);
	virtual void BroadcastSigInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigFloat(const TArray<FTestbed1StructFloat>& ParamFloat);
	virtual void BroadcastSigFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigString(const TArray<FTestbed1StructString>& ParamString);
	virtual void BroadcastSigString_Implementation(const TArray<FTestbed1StructString>& ParamString) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropBoolChanged(const TArray<FTestbed1StructBool>& PropBool);
	virtual void BroadcastPropBoolChanged_Implementation(const TArray<FTestbed1StructBool>& PropBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropIntChanged(const TArray<FTestbed1StructInt>& PropInt);
	virtual void BroadcastPropIntChanged_Implementation(const TArray<FTestbed1StructInt>& PropInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropFloatChanged(const TArray<FTestbed1StructFloat>& PropFloat);
	virtual void BroadcastPropFloatChanged_Implementation(const TArray<FTestbed1StructFloat>& PropFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropStringChanged(const TArray<FTestbed1StructString>& PropString);
	virtual void BroadcastPropStringChanged_Implementation(const TArray<FTestbed1StructString>& PropString) = 0;
};

/**
 * Abstract UAbstractTestbed1StructArrayInterface
 */
UCLASS(Abstract, Blueprintable)
class TESTBED1_API UAbstractTestbed1StructArrayInterface : public UGameInstanceSubsystem, public ITestbed1StructArrayInterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "SigBool Signal")
	FTestbed1StructArrayInterfaceSigBoolDelegate SigBoolSignal;
	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
	virtual FTestbed1StructArrayInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override
	{
		return SigBoolSignal;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "SigInt Signal")
	FTestbed1StructArrayInterfaceSigIntDelegate SigIntSignal;
	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
	virtual FTestbed1StructArrayInterfaceSigIntDelegate& GetSigIntSignalDelegate() override
	{
		return SigIntSignal;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "SigFloat Signal")
	FTestbed1StructArrayInterfaceSigFloatDelegate SigFloatSignal;
	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
	virtual FTestbed1StructArrayInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override
	{
		return SigFloatSignal;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "SigString Signal")
	FTestbed1StructArrayInterfaceSigStringDelegate SigStringSignal;
	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
	virtual FTestbed1StructArrayInterfaceSigStringDelegate& GetSigStringSignalDelegate() override
	{
		return SigStringSignal;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "PropBool Changed")
	FTestbed1StructArrayInterfacePropBoolChangedDelegate PropBoolChanged;
	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
	virtual FTestbed1StructArrayInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override
	{
		return PropBoolChanged;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "PropInt Changed")
	FTestbed1StructArrayInterfacePropIntChangedDelegate PropIntChanged;
	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
	virtual FTestbed1StructArrayInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override
	{
		return PropIntChanged;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "PropFloat Changed")
	FTestbed1StructArrayInterfacePropFloatChangedDelegate PropFloatChanged;
	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
	virtual FTestbed1StructArrayInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override
	{
		return PropFloatChanged;
	};

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "PropString Changed")
	FTestbed1StructArrayInterfacePropStringChangedDelegate PropStringChanged;
	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
	virtual FTestbed1StructArrayInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override
	{
		return PropStringChanged;
	};

	// methods
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructBool>& ParamBool) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::FuncBoolAsync_Implementation, return;);
	virtual FTestbed1StructBool FuncBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::FuncBool_Implementation, return FTestbed1StructBool(););

	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructInt>& ParamInt) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::FuncIntAsync_Implementation, return;);
	virtual FTestbed1StructBool FuncInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::FuncInt_Implementation, return FTestbed1StructBool(););

	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructFloat>& ParamFloat) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::FuncFloatAsync_Implementation, return;);
	virtual FTestbed1StructBool FuncFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::FuncFloat_Implementation, return FTestbed1StructBool(););

	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructString>& ParamString) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::FuncStringAsync_Implementation, return;);
	virtual FTestbed1StructBool FuncString_Implementation(const TArray<FTestbed1StructString>& ParamString) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::FuncString_Implementation, return FTestbed1StructBool(););

	// properties
	virtual TArray<FTestbed1StructBool> GetPropBool_Implementation() const override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::GetPropBool_Implementation, return TArray<FTestbed1StructBool>(););

	virtual void SetPropBool_Implementation(const TArray<FTestbed1StructBool>& InPropBool) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::SetPropBool_Implementation, return;);
	virtual TArray<FTestbed1StructInt> GetPropInt_Implementation() const override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::GetPropInt_Implementation, return TArray<FTestbed1StructInt>(););

	virtual void SetPropInt_Implementation(const TArray<FTestbed1StructInt>& InPropInt) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::SetPropInt_Implementation, return;);
	virtual TArray<FTestbed1StructFloat> GetPropFloat_Implementation() const override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::GetPropFloat_Implementation, return TArray<FTestbed1StructFloat>(););

	virtual void SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::SetPropFloat_Implementation, return;);
	virtual TArray<FTestbed1StructString> GetPropString_Implementation() const override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::GetPropString_Implementation, return TArray<FTestbed1StructString>(););

	virtual void SetPropString_Implementation(const TArray<FTestbed1StructString>& InPropString) override PURE_VIRTUAL(UAbstractTestbed1StructArrayInterface::SetPropString_Implementation, return;);

protected:
	// signals
	virtual void BroadcastSigBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool) override
	{
		SigBoolSignal.Broadcast(ParamBool);
	};

	virtual void BroadcastSigInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt) override
	{
		SigIntSignal.Broadcast(ParamInt);
	};

	virtual void BroadcastSigFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat) override
	{
		SigFloatSignal.Broadcast(ParamFloat);
	};

	virtual void BroadcastSigString_Implementation(const TArray<FTestbed1StructString>& ParamString) override
	{
		SigStringSignal.Broadcast(ParamString);
	};

	virtual void BroadcastPropBoolChanged_Implementation(const TArray<FTestbed1StructBool>& InPropBool) override
	{
		PropBoolChanged.Broadcast(InPropBool);
	}

	virtual void BroadcastPropIntChanged_Implementation(const TArray<FTestbed1StructInt>& InPropInt) override
	{
		PropIntChanged.Broadcast(InPropInt);
	}

	virtual void BroadcastPropFloatChanged_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat) override
	{
		PropFloatChanged.Broadcast(InPropFloat);
	}

	virtual void BroadcastPropStringChanged_Implementation(const TArray<FTestbed1StructString>& InPropString) override
	{
		PropStringChanged.Broadcast(InPropString);
	}

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructBool> PropBool{TArray<FTestbed1StructBool>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	TArray<FTestbed1StructBool> GetPropBool_Private() const
	{
		return Execute_GetPropBool(this);
	};

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void SetPropBool_Private(const TArray<FTestbed1StructBool>& InPropBool)
	{
		Execute_SetPropBool(this, InPropBool);
	};

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructInt> PropInt{TArray<FTestbed1StructInt>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	TArray<FTestbed1StructInt> GetPropInt_Private() const
	{
		return Execute_GetPropInt(this);
	};

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void SetPropInt_Private(const TArray<FTestbed1StructInt>& InPropInt)
	{
		Execute_SetPropInt(this, InPropInt);
	};

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructFloat> PropFloat{TArray<FTestbed1StructFloat>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	TArray<FTestbed1StructFloat> GetPropFloat_Private() const
	{
		return Execute_GetPropFloat(this);
	};

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void SetPropFloat_Private(const TArray<FTestbed1StructFloat>& InPropFloat)
	{
		Execute_SetPropFloat(this, InPropFloat);
	};

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructString> PropString{TArray<FTestbed1StructString>()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	TArray<FTestbed1StructString> GetPropString_Private() const
	{
		return Execute_GetPropString(this);
	};

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void SetPropString_Private(const TArray<FTestbed1StructString>& InPropString)
	{
		Execute_SetPropString(this, InPropString);
	};
};
