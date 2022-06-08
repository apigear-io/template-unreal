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
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSig1Delegate);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSig2Delegate, int32, Step, const FString&, Step2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSig3Delegate);

// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FbProp1ChangedDelegate, bool, bProp1);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp2ChangedDelegate, int32, Prop2);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp3ChangedDelegate, float, Prop3);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp4ChangedDelegate, const FString&, Prop4);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp5ChangedDelegate, const TArray<int32>&, Prop5);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp6ChangedDelegate, const FStruct1&, Prop6);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp7ChangedDelegate, int32, Prop7);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp10ChangedDelegate, const TArray<int32>&, Prop10);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp11ChangedDelegate, const TArray<FStruct1>&, Prop11);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp12ChangedDelegate, const TArray<EEnum1>&, Prop12);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp14ChangedDelegate, const TArray<FStruct1>&, Prop14);

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
    virtual FSig1Delegate& GetSig1SignalDelegate() = 0;

    virtual FSig2Delegate& GetSig2SignalDelegate() = 0;

    virtual FSig3Delegate& GetSig3SignalDelegate() = 0;

    virtual FbProp1ChangedDelegate& GetbProp1ChangedDelegate() = 0;

    virtual FProp2ChangedDelegate& GetProp2ChangedDelegate() = 0;

    virtual FProp3ChangedDelegate& GetProp3ChangedDelegate() = 0;

    virtual FProp4ChangedDelegate& GetProp4ChangedDelegate() = 0;

    virtual FProp5ChangedDelegate& GetProp5ChangedDelegate() = 0;

    virtual FProp6ChangedDelegate& GetProp6ChangedDelegate() = 0;

    virtual FProp7ChangedDelegate& GetProp7ChangedDelegate() = 0;

    virtual FProp10ChangedDelegate& GetProp10ChangedDelegate() = 0;

    virtual FProp11ChangedDelegate& GetProp11ChangedDelegate() = 0;

    virtual FProp12ChangedDelegate& GetProp12ChangedDelegate() = 0;

    virtual FProp14ChangedDelegate& GetProp14ChangedDelegate() = 0;


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
    virtual FStruct1 GetProp6() const = 0;
    virtual void SetProp6(const FStruct1& InProp6) = 0;
    virtual int32 GetProp7() const = 0;
    virtual void SetProp7(int32 InProp7) = 0;
    virtual TArray<int32> GetProp10() const = 0;
    virtual void SetProp10(const TArray<int32>& InProp10) = 0;
    virtual TArray<FStruct1> GetProp11() const = 0;
    virtual void SetProp11(const TArray<FStruct1>& InProp11) = 0;
    virtual TArray<EEnum1> GetProp12() const = 0;
    virtual void SetProp12(const TArray<EEnum1>& InProp12) = 0;
    virtual TArray<FStruct1> GetProp14() const = 0;
    virtual void SetProp14(const TArray<FStruct1>& InProp14) = 0;
};
/**
 * Declaration for Interface2
 */
// signal delegates
// property delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp200ChangedDelegate, int32, Prop200);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp201ChangedDelegate, int32, Prop201);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp202ChangedDelegate, int32, Prop202);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp203ChangedDelegate, float, Prop203);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp204ChangedDelegate, float, Prop204);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProp205ChangedDelegate, const FString&, Prop205);

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
    virtual FProp200ChangedDelegate& GetProp200ChangedDelegate() = 0;

    virtual FProp201ChangedDelegate& GetProp201ChangedDelegate() = 0;

    virtual FProp202ChangedDelegate& GetProp202ChangedDelegate() = 0;

    virtual FProp203ChangedDelegate& GetProp203ChangedDelegate() = 0;

    virtual FProp204ChangedDelegate& GetProp204ChangedDelegate() = 0;

    virtual FProp205ChangedDelegate& GetProp205ChangedDelegate() = 0;


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
