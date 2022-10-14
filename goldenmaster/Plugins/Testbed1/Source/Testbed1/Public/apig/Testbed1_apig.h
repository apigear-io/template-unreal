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
#include "Testbed1_data.h"
#include "Testbed1_apig.generated.h"

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
	virtual FTestbed1StructInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() = 0;

	virtual FTestbed1StructInterfaceSigIntDelegate& GetSigIntSignalDelegate() = 0;

	virtual FTestbed1StructInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() = 0;

	virtual FTestbed1StructInterfaceSigStringDelegate& GetSigStringSignalDelegate() = 0;

	virtual FTestbed1StructInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() = 0;

	virtual FTestbed1StructInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() = 0;

	virtual FTestbed1StructInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() = 0;

	virtual FTestbed1StructInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool);
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool) = 0;
	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructBool FuncBool(const FTestbed1StructBool& ParamBool);
	virtual FTestbed1StructBool FuncBool_Implementation(const FTestbed1StructBool& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructInt& ParamInt);
	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructInt& ParamInt) = 0;
	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructBool FuncInt(const FTestbed1StructInt& ParamInt);
	virtual FTestbed1StructBool FuncInt_Implementation(const FTestbed1StructInt& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat);
	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructFloat FuncFloat(const FTestbed1StructFloat& ParamFloat);
	virtual FTestbed1StructFloat FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString);
	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString) = 0;
	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructString FuncString(const FTestbed1StructString& ParamString);
	virtual FTestbed1StructString FuncString_Implementation(const FTestbed1StructString& ParamString) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructBool GetPropBool() const;
	virtual FTestbed1StructBool GetPropBool_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructInterface")
	void SetPropBool(const FTestbed1StructBool& PropBool);
	virtual void SetPropBool_Implementation(const FTestbed1StructBool& PropBool) = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructInt GetPropInt() const;
	virtual FTestbed1StructInt GetPropInt_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructInterface")
	void SetPropInt(const FTestbed1StructInt& PropInt);
	virtual void SetPropInt_Implementation(const FTestbed1StructInt& PropInt) = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructFloat GetPropFloat() const;
	virtual FTestbed1StructFloat GetPropFloat_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructInterface")
	void SetPropFloat(const FTestbed1StructFloat& PropFloat);
	virtual void SetPropFloat_Implementation(const FTestbed1StructFloat& PropFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructString GetPropString() const;
	virtual FTestbed1StructString GetPropString_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructInterface")
	void SetPropString(const FTestbed1StructString& PropString);
	virtual void SetPropString_Implementation(const FTestbed1StructString& PropString) = 0;
};
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
	virtual FTestbed1StructArrayInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() = 0;

	virtual FTestbed1StructArrayInterfaceSigIntDelegate& GetSigIntSignalDelegate() = 0;

	virtual FTestbed1StructArrayInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() = 0;

	virtual FTestbed1StructArrayInterfaceSigStringDelegate& GetSigStringSignalDelegate() = 0;

	virtual FTestbed1StructArrayInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() = 0;

	virtual FTestbed1StructArrayInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() = 0;

	virtual FTestbed1StructArrayInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() = 0;

	virtual FTestbed1StructArrayInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() = 0;

	// methods
	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructBool>& ParamBool);
	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructBool>& ParamBool) = 0;
	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructArrayInterface")
	FTestbed1StructBool FuncBool(const TArray<FTestbed1StructBool>& ParamBool);
	virtual FTestbed1StructBool FuncBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool) = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncIntAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructInt>& ParamInt);
	virtual void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructInt>& ParamInt) = 0;
	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructArrayInterface")
	FTestbed1StructBool FuncInt(const TArray<FTestbed1StructInt>& ParamInt);
	virtual FTestbed1StructBool FuncInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt) = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloatAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructFloat>& ParamFloat);
	virtual void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructFloat>& ParamFloat) = 0;
	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructArrayInterface")
	FTestbed1StructBool FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat);
	virtual FTestbed1StructBool FuncFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncStringAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructString>& ParamString);
	virtual void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructString>& ParamString) = 0;
	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructArrayInterface")
	FTestbed1StructBool FuncString(const TArray<FTestbed1StructString>& ParamString);
	virtual FTestbed1StructBool FuncString_Implementation(const TArray<FTestbed1StructString>& ParamString) = 0;

	// properties
	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructBool> GetPropBool() const;
	virtual TArray<FTestbed1StructBool> GetPropBool_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructArrayInterface")
	void SetPropBool(const TArray<FTestbed1StructBool>& PropBool);
	virtual void SetPropBool_Implementation(const TArray<FTestbed1StructBool>& PropBool) = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructInt> GetPropInt() const;
	virtual TArray<FTestbed1StructInt> GetPropInt_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructArrayInterface")
	void SetPropInt(const TArray<FTestbed1StructInt>& PropInt);
	virtual void SetPropInt_Implementation(const TArray<FTestbed1StructInt>& PropInt) = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructFloat> GetPropFloat() const;
	virtual TArray<FTestbed1StructFloat> GetPropFloat_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructArrayInterface")
	void SetPropFloat(const TArray<FTestbed1StructFloat>& PropFloat);
	virtual void SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& PropFloat) = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructString> GetPropString() const;
	virtual TArray<FTestbed1StructString> GetPropString_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, Category = "ApiGear|Testbed1|StructArrayInterface")
	void SetPropString(const TArray<FTestbed1StructString>& PropString);
	virtual void SetPropString_Implementation(const TArray<FTestbed1StructString>& PropString) = 0;
};
