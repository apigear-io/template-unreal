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

#include "TbEnum_data.h"
#include "TbEnum_apig.generated.h"

/**
 * Declaration for EnumInterface
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig0Delegate, const ETbEnumEnum0&, Param0);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig1Delegate, const ETbEnumEnum1&, Param1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig2Delegate, const ETbEnumEnum2&, Param2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceSig3Delegate, const ETbEnumEnum3&, Param3);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp0ChangedDelegate, const ETbEnumEnum0&, Prop0);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp1ChangedDelegate, const ETbEnumEnum1&, Prop1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp2ChangedDelegate, const ETbEnumEnum2&, Prop2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbEnumEnumInterfaceProp3ChangedDelegate, const ETbEnumEnum3&, Prop3);

/**
 * Interface UTbEnumEnumInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(MinimalAPI)
class UTbEnumEnumInterfaceInterface : public UInterface
{
    GENERATED_BODY()
};

/**
 * Interface ITbEnumEnumInterfaceInterface
 */
class TBENUM_API ITbEnumEnumInterfaceInterface
{
    GENERATED_BODY()

public:
// signals
    virtual FTbEnumEnumInterfaceSig0Delegate& GetSig0SignalDelegate() = 0;

    virtual FTbEnumEnumInterfaceSig1Delegate& GetSig1SignalDelegate() = 0;

    virtual FTbEnumEnumInterfaceSig2Delegate& GetSig2SignalDelegate() = 0;

    virtual FTbEnumEnumInterfaceSig3Delegate& GetSig3SignalDelegate() = 0;

    virtual FTbEnumEnumInterfaceProp0ChangedDelegate& GetProp0ChangedDelegate() = 0;

    virtual FTbEnumEnumInterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() = 0;

    virtual FTbEnumEnumInterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() = 0;

    virtual FTbEnumEnumInterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() = 0;


// methods
    virtual ETbEnumEnum0 Func0(const ETbEnumEnum0& Param0) = 0;
    virtual ETbEnumEnum1 Func1(const ETbEnumEnum1& Param1) = 0;
    virtual ETbEnumEnum2 Func2(const ETbEnumEnum2& Param2) = 0;
    virtual ETbEnumEnum3 Func3(const ETbEnumEnum3& Param3) = 0;
// properties
    virtual ETbEnumEnum0 GetProp0() const = 0;
    virtual void SetProp0(const ETbEnumEnum0& Prop0) = 0;
    virtual ETbEnumEnum1 GetProp1() const = 0;
    virtual void SetProp1(const ETbEnumEnum1& Prop1) = 0;
    virtual ETbEnumEnum2 GetProp2() const = 0;
    virtual void SetProp2(const ETbEnumEnum2& Prop2) = 0;
    virtual ETbEnumEnum3 GetProp3() const = 0;
    virtual void SetProp3(const ETbEnumEnum3& Prop3) = 0;
};
