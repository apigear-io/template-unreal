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
class TESTBED1_API ITestbed1StructInterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface")
	virtual FTestbed1StructInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface")
	virtual FTestbed1StructInterfaceSigIntDelegate& GetSigIntSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface")
	virtual FTestbed1StructInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface")
	virtual FTestbed1StructInterfaceSigStringDelegate& GetSigStringSignalDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface")
	virtual FTestbed1StructInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface")
	virtual FTestbed1StructInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface")
	virtual FTestbed1StructInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() = 0;

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface")
	virtual FTestbed1StructInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool);
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructBool FuncBool(const FTestbed1StructBool& ParamBool);
	virtual FTestbed1StructBool FuncBool_Implementation(const FTestbed1StructBool& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructInt& ParamInt);
	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructInt& ParamInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructBool FuncInt(const FTestbed1StructInt& ParamInt);
	virtual FTestbed1StructBool FuncInt_Implementation(const FTestbed1StructInt& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat);
	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructFloat FuncFloat(const FTestbed1StructFloat& ParamFloat);
	virtual FTestbed1StructFloat FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString);
	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructString FuncString(const FTestbed1StructString& ParamString);
	virtual FTestbed1StructString FuncString_Implementation(const FTestbed1StructString& ParamString) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructBool GetPropBool() const;
	virtual FTestbed1StructBool GetPropBool_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	void SetPropBool(const FTestbed1StructBool& InPropBool);
	virtual void SetPropBool_Implementation(const FTestbed1StructBool& InPropBool) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructInt GetPropInt() const;
	virtual FTestbed1StructInt GetPropInt_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	void SetPropInt(const FTestbed1StructInt& InPropInt);
	virtual void SetPropInt_Implementation(const FTestbed1StructInt& InPropInt) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructFloat GetPropFloat() const;
	virtual FTestbed1StructFloat GetPropFloat_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	void SetPropFloat(const FTestbed1StructFloat& InPropFloat);
	virtual void SetPropFloat_Implementation(const FTestbed1StructFloat& InPropFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructString GetPropString() const;
	virtual FTestbed1StructString GetPropString_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	void SetPropString(const FTestbed1StructString& InPropString);
	virtual void SetPropString_Implementation(const FTestbed1StructString& InPropString) = 0;

protected:
	// signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigBool(const FTestbed1StructBool& ParamBool);
	virtual void BroadcastSigBool_Implementation(const FTestbed1StructBool& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigInt(const FTestbed1StructInt& ParamInt);
	virtual void BroadcastSigInt_Implementation(const FTestbed1StructInt& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigFloat(const FTestbed1StructFloat& ParamFloat);
	virtual void BroadcastSigFloat_Implementation(const FTestbed1StructFloat& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", meta = (BlueprintProtected = "true"))
	void BroadcastSigString(const FTestbed1StructString& ParamString);
	virtual void BroadcastSigString_Implementation(const FTestbed1StructString& ParamString) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropBoolChanged(const FTestbed1StructBool& PropBool);
	virtual void BroadcastPropBoolChanged_Implementation(const FTestbed1StructBool& PropBool) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropIntChanged(const FTestbed1StructInt& PropInt);
	virtual void BroadcastPropIntChanged_Implementation(const FTestbed1StructInt& PropInt) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropFloatChanged(const FTestbed1StructFloat& PropFloat);
	virtual void BroadcastPropFloatChanged_Implementation(const FTestbed1StructFloat& PropFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", meta = (BlueprintProtected = "true"))
	void BroadcastPropStringChanged(const FTestbed1StructString& PropString);
	virtual void BroadcastPropStringChanged_Implementation(const FTestbed1StructString& PropString) = 0;
};

/**
 * Abstract UAbstractTestbed1StructInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TESTBED1_API UAbstractTestbed1StructInterface : public UGameInstanceSubsystem, public ITestbed1StructInterfaceInterface
{
	GENERATED_BODY()

public:
	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface", DisplayName = "SigBool Signal")
	FTestbed1StructInterfaceSigBoolDelegate SigBoolSignal;
	virtual FTestbed1StructInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface", DisplayName = "SigInt Signal")
	FTestbed1StructInterfaceSigIntDelegate SigIntSignal;
	virtual FTestbed1StructInterfaceSigIntDelegate& GetSigIntSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface", DisplayName = "SigFloat Signal")
	FTestbed1StructInterfaceSigFloatDelegate SigFloatSignal;
	virtual FTestbed1StructInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface", DisplayName = "SigString Signal")
	FTestbed1StructInterfaceSigStringDelegate SigStringSignal;
	virtual FTestbed1StructInterfaceSigStringDelegate& GetSigStringSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface", DisplayName = "PropBool Changed")
	FTestbed1StructInterfacePropBoolChangedDelegate PropBoolChanged;
	virtual FTestbed1StructInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface", DisplayName = "PropInt Changed")
	FTestbed1StructInterfacePropIntChangedDelegate PropIntChanged;
	virtual FTestbed1StructInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface", DisplayName = "PropFloat Changed")
	FTestbed1StructInterfacePropFloatChangedDelegate PropFloatChanged;
	virtual FTestbed1StructInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface", DisplayName = "PropString Changed")
	FTestbed1StructInterfacePropStringChangedDelegate PropStringChanged;
	virtual FTestbed1StructInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override;

	// methods
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::FuncBoolAsync_Implementation, return;);
	virtual FTestbed1StructBool FuncBool_Implementation(const FTestbed1StructBool& ParamBool) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::FuncBool_Implementation, return FTestbed1StructBool(););

	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructInt& ParamInt) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::FuncIntAsync_Implementation, return;);
	virtual FTestbed1StructBool FuncInt_Implementation(const FTestbed1StructInt& ParamInt) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::FuncInt_Implementation, return FTestbed1StructBool(););

	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::FuncFloatAsync_Implementation, return;);
	virtual FTestbed1StructFloat FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::FuncFloat_Implementation, return FTestbed1StructFloat(););

	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::FuncStringAsync_Implementation, return;);
	virtual FTestbed1StructString FuncString_Implementation(const FTestbed1StructString& ParamString) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::FuncString_Implementation, return FTestbed1StructString(););

	// properties
	virtual FTestbed1StructBool GetPropBool_Implementation() const override PURE_VIRTUAL(UAbstractTestbed1StructInterface::GetPropBool_Implementation, return FTestbed1StructBool(););

	virtual void SetPropBool_Implementation(const FTestbed1StructBool& InPropBool) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::SetPropBool_Implementation, return;);
	virtual FTestbed1StructInt GetPropInt_Implementation() const override PURE_VIRTUAL(UAbstractTestbed1StructInterface::GetPropInt_Implementation, return FTestbed1StructInt(););

	virtual void SetPropInt_Implementation(const FTestbed1StructInt& InPropInt) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::SetPropInt_Implementation, return;);
	virtual FTestbed1StructFloat GetPropFloat_Implementation() const override PURE_VIRTUAL(UAbstractTestbed1StructInterface::GetPropFloat_Implementation, return FTestbed1StructFloat(););

	virtual void SetPropFloat_Implementation(const FTestbed1StructFloat& InPropFloat) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::SetPropFloat_Implementation, return;);
	virtual FTestbed1StructString GetPropString_Implementation() const override PURE_VIRTUAL(UAbstractTestbed1StructInterface::GetPropString_Implementation, return FTestbed1StructString(););

	virtual void SetPropString_Implementation(const FTestbed1StructString& InPropString) override PURE_VIRTUAL(UAbstractTestbed1StructInterface::SetPropString_Implementation, return;);

protected:
	// signals
	virtual void BroadcastSigBool_Implementation(const FTestbed1StructBool& ParamBool) override;

	virtual void BroadcastSigInt_Implementation(const FTestbed1StructInt& ParamInt) override;

	virtual void BroadcastSigFloat_Implementation(const FTestbed1StructFloat& ParamFloat) override;

	virtual void BroadcastSigString_Implementation(const FTestbed1StructString& ParamString) override;

	virtual void BroadcastPropBoolChanged_Implementation(const FTestbed1StructBool& InPropBool) override;

	virtual void BroadcastPropIntChanged_Implementation(const FTestbed1StructInt& InPropInt) override;

	virtual void BroadcastPropFloatChanged_Implementation(const FTestbed1StructFloat& InPropFloat) override;

	virtual void BroadcastPropStringChanged_Implementation(const FTestbed1StructString& InPropString) override;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructBool PropBool{FTestbed1StructBool()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	FTestbed1StructBool GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void SetPropBool_Private(const FTestbed1StructBool& InPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructInt PropInt{FTestbed1StructInt()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	FTestbed1StructInt GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void SetPropInt_Private(const FTestbed1StructInt& InPropInt);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructFloat PropFloat{FTestbed1StructFloat()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	FTestbed1StructFloat GetPropFloat_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void SetPropFloat_Private(const FTestbed1StructFloat& InPropFloat);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructString PropString{FTestbed1StructString()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	FTestbed1StructString GetPropString_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void SetPropString_Private(const FTestbed1StructString& InPropString);
};
