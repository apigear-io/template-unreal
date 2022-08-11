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

#include "TbSimple_data.h"
#include "TbSimple_apig.generated.h"

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
UINTERFACE(MinimalAPI)
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
    virtual FTbSimpleSimpleInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() = 0;

    virtual FTbSimpleSimpleInterfaceSigIntDelegate& GetSigIntSignalDelegate() = 0;

    virtual FTbSimpleSimpleInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() = 0;

    virtual FTbSimpleSimpleInterfaceSigStringDelegate& GetSigStringSignalDelegate() = 0;

    virtual FTbSimpleSimpleInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() = 0;

    virtual FTbSimpleSimpleInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() = 0;

    virtual FTbSimpleSimpleInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() = 0;

    virtual FTbSimpleSimpleInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() = 0;


// methods
    virtual bool FuncBool(bool bParamBool) = 0;
    virtual int32 FuncInt(int32 ParamInt) = 0;
    virtual float FuncFloat(float ParamFloat) = 0;
    virtual FString FuncString(const FString& ParamString) = 0;
// properties
    virtual bool GetPropBool() const = 0;
    virtual void SetPropBool(bool bPropBool) = 0;
    virtual int32 GetPropInt() const = 0;
    virtual void SetPropInt(int32 PropInt) = 0;
    virtual float GetPropFloat() const = 0;
    virtual void SetPropFloat(float PropFloat) = 0;
    virtual FString GetPropString() const = 0;
    virtual void SetPropString(const FString& PropString) = 0;
};
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
UINTERFACE(MinimalAPI)
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
    virtual FTbSimpleSimpleArrayInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() = 0;

    virtual FTbSimpleSimpleArrayInterfaceSigIntDelegate& GetSigIntSignalDelegate() = 0;

    virtual FTbSimpleSimpleArrayInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() = 0;

    virtual FTbSimpleSimpleArrayInterfaceSigStringDelegate& GetSigStringSignalDelegate() = 0;

    virtual FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() = 0;

    virtual FTbSimpleSimpleArrayInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() = 0;

    virtual FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() = 0;

    virtual FTbSimpleSimpleArrayInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() = 0;


// methods
    virtual TArray<bool> FuncBool(const TArray<bool>& ParamBool) = 0;
    virtual TArray<int32> FuncInt(const TArray<int32>& ParamInt) = 0;
    virtual TArray<float> FuncFloat(const TArray<float>& ParamFloat) = 0;
    virtual TArray<FString> FuncString(const TArray<FString>& ParamString) = 0;
// properties
    virtual TArray<bool> GetPropBool() const = 0;
    virtual void SetPropBool(const TArray<bool>& PropBool) = 0;
    virtual TArray<int32> GetPropInt() const = 0;
    virtual void SetPropInt(const TArray<int32>& PropInt) = 0;
    virtual TArray<float> GetPropFloat() const = 0;
    virtual void SetPropFloat(const TArray<float>& PropFloat) = 0;
    virtual TArray<FString> GetPropString() const = 0;
    virtual void SetPropString(const TArray<FString>& PropString) = 0;
};
