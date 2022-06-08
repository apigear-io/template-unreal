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

#include "OrgObjectapiTestbed_data.h"
#include "OrgObjectapiTestbed_apig.generated.h"

/**
 * Declaration for Interface1
 */
// signal delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOrgObjectapiTestbedInterface1Sig1Delegate);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOrgObjectapiTestbedInterface1Sig2Delegate, int32, Step, const FString&, Step2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrgObjectapiTestbedInterface1Sig3Delegate, float, Step);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FbOrgObjectapiTestbedInterface1Prop1ChangedDelegate, bool, bProp1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrgObjectapiTestbedInterface1Prop2ChangedDelegate, int32, Prop2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrgObjectapiTestbedInterface1Prop3ChangedDelegate, float, Prop3);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrgObjectapiTestbedInterface1Prop4ChangedDelegate, const FString&, Prop4);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrgObjectapiTestbedInterface1Prop5ChangedDelegate, const TArray<int32>&, Prop5);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrgObjectapiTestbedInterface1Prop6ChangedDelegate, const FOrgObjectapiTestbedStruct1&, Prop6);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrgObjectapiTestbedInterface1Prop7ChangedDelegate, int32, Prop7);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrgObjectapiTestbedInterface1Prop10ChangedDelegate, const TArray<int32>&, Prop10);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrgObjectapiTestbedInterface1Prop11ChangedDelegate, const TArray<FOrgObjectapiTestbedStruct1>&, Prop11);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrgObjectapiTestbedInterface1Prop12ChangedDelegate, const TArray<EOrgObjectapiTestbedEnum1>&, Prop12);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrgObjectapiTestbedInterface1Prop14ChangedDelegate, const TArray<FOrgObjectapiTestbedStruct1>&, Prop14);

/**
 * Interface UOrgObjectapiTestbedInterface1Interface only for Unreal Engine's reflection system
 */
UINTERFACE(MinimalAPI)
class UOrgObjectapiTestbedInterface1Interface : public UInterface
{
    GENERATED_BODY()
};

/**
 * Interface IOrgObjectapiTestbedInterface1Interface
 */
class ORGOBJECTAPITESTBED_API IOrgObjectapiTestbedInterface1Interface
{
    GENERATED_BODY()

public:
// signals
    virtual FOrgObjectapiTestbedInterface1Sig1Delegate& GetOrgObjectapiTestbedInterface1Sig1SignalDelegate() = 0;

    virtual FOrgObjectapiTestbedInterface1Sig2Delegate& GetOrgObjectapiTestbedInterface1Sig2SignalDelegate() = 0;

    virtual FOrgObjectapiTestbedInterface1Sig3Delegate& GetOrgObjectapiTestbedInterface1Sig3SignalDelegate() = 0;

    virtual FbOrgObjectapiTestbedInterface1Prop1ChangedDelegate& GetbOrgObjectapiTestbedInterface1Prop1ChangedDelegate() = 0;

    virtual FOrgObjectapiTestbedInterface1Prop2ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop2ChangedDelegate() = 0;

    virtual FOrgObjectapiTestbedInterface1Prop3ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop3ChangedDelegate() = 0;

    virtual FOrgObjectapiTestbedInterface1Prop4ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop4ChangedDelegate() = 0;

    virtual FOrgObjectapiTestbedInterface1Prop5ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop5ChangedDelegate() = 0;

    virtual FOrgObjectapiTestbedInterface1Prop6ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop6ChangedDelegate() = 0;

    virtual FOrgObjectapiTestbedInterface1Prop7ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop7ChangedDelegate() = 0;

    virtual FOrgObjectapiTestbedInterface1Prop10ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop10ChangedDelegate() = 0;

    virtual FOrgObjectapiTestbedInterface1Prop11ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop11ChangedDelegate() = 0;

    virtual FOrgObjectapiTestbedInterface1Prop12ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop12ChangedDelegate() = 0;

    virtual FOrgObjectapiTestbedInterface1Prop14ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop14ChangedDelegate() = 0;


// methods
    virtual void Op1() = 0;
    virtual void Op2(int32 Step) = 0;
    virtual int32 Op3() = 0;
// properties
    virtual bool GetProp1() const = 0;
    virtual void SetProp1(bool bInProp1) = 0;
    virtual int32 GetProp2() const = 0;
    virtual void SetProp2(int32 InProp2) = 0;
    virtual float GetProp3() const = 0;
    virtual void SetProp3(float InProp3) = 0;
    virtual FString GetProp4() const = 0;
    virtual void SetProp4(const FString& InProp4) = 0;
    virtual TArray<int32> GetProp5() const = 0;
    virtual void SetProp5(const TArray<int32>& InProp5) = 0;
    virtual FOrgObjectapiTestbedStruct1 GetProp6() const = 0;
    virtual void SetProp6(const FOrgObjectapiTestbedStruct1& InProp6) = 0;
    virtual int32 GetProp7() const = 0;
    virtual void SetProp7(int32 InProp7) = 0;
    virtual TArray<int32> GetProp10() const = 0;
    virtual void SetProp10(const TArray<int32>& InProp10) = 0;
    virtual TArray<FOrgObjectapiTestbedStruct1> GetProp11() const = 0;
    virtual void SetProp11(const TArray<FOrgObjectapiTestbedStruct1>& InProp11) = 0;
    virtual TArray<EOrgObjectapiTestbedEnum1> GetProp12() const = 0;
    virtual void SetProp12(const TArray<EOrgObjectapiTestbedEnum1>& InProp12) = 0;
    virtual TArray<FOrgObjectapiTestbedStruct1> GetProp14() const = 0;
    virtual void SetProp14(const TArray<FOrgObjectapiTestbedStruct1>& InProp14) = 0;
};
/**
 * Declaration for Interface2
 */
// signal delegates
// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrgObjectapiTestbedInterface2Prop200ChangedDelegate, int32, Prop200);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrgObjectapiTestbedInterface2Prop201ChangedDelegate, int32, Prop201);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrgObjectapiTestbedInterface2Prop202ChangedDelegate, int32, Prop202);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrgObjectapiTestbedInterface2Prop203ChangedDelegate, float, Prop203);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrgObjectapiTestbedInterface2Prop204ChangedDelegate, float, Prop204);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrgObjectapiTestbedInterface2Prop205ChangedDelegate, const FString&, Prop205);

/**
 * Interface UOrgObjectapiTestbedInterface2Interface only for Unreal Engine's reflection system
 */
UINTERFACE(MinimalAPI)
class UOrgObjectapiTestbedInterface2Interface : public UInterface
{
    GENERATED_BODY()
};

/**
 * Interface IOrgObjectapiTestbedInterface2Interface
 */
class ORGOBJECTAPITESTBED_API IOrgObjectapiTestbedInterface2Interface
{
    GENERATED_BODY()

public:
// signals
    virtual FOrgObjectapiTestbedInterface2Prop200ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop200ChangedDelegate() = 0;

    virtual FOrgObjectapiTestbedInterface2Prop201ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop201ChangedDelegate() = 0;

    virtual FOrgObjectapiTestbedInterface2Prop202ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop202ChangedDelegate() = 0;

    virtual FOrgObjectapiTestbedInterface2Prop203ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop203ChangedDelegate() = 0;

    virtual FOrgObjectapiTestbedInterface2Prop204ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop204ChangedDelegate() = 0;

    virtual FOrgObjectapiTestbedInterface2Prop205ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop205ChangedDelegate() = 0;


// methods
// properties
    virtual int32 GetProp200() const = 0;
    virtual void SetProp200(int32 InProp200) = 0;
    virtual int32 GetProp201() const = 0;
    virtual void SetProp201(int32 InProp201) = 0;
    virtual int32 GetProp202() const = 0;
    virtual void SetProp202(int32 InProp202) = 0;
    virtual float GetProp203() const = 0;
    virtual void SetProp203(float InProp203) = 0;
    virtual float GetProp204() const = 0;
    virtual void SetProp204(float InProp204) = 0;
    virtual FString GetProp205() const = 0;
    virtual void SetProp205(const FString& InProp205) = 0;
};
