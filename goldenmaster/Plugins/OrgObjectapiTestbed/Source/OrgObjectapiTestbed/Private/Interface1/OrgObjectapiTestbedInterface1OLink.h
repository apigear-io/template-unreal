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

#include "apig/OrgObjectapiTestbed_apig.h"
#include "olink/clientnode.h"

class OrgObjectapiTestbedInterface1OLinkService : public IOrgObjectapiTestbedInterface1Interface, public ApiGear::ObjectLink::IObjectSink
{
public:

    explicit OrgObjectapiTestbedInterface1OLinkService();
    virtual ~OrgObjectapiTestbedInterface1OLinkService();

    // signals
    FOrgObjectapiTestbedInterface1Sig1Delegate OrgObjectapiTestbedInterface1Sig1Signal;
    FOrgObjectapiTestbedInterface1Sig1Delegate& GetOrgObjectapiTestbedInterface1Sig1SignalDelegate() override;
    
    FOrgObjectapiTestbedInterface1Sig2Delegate OrgObjectapiTestbedInterface1Sig2Signal;
    FOrgObjectapiTestbedInterface1Sig2Delegate& GetOrgObjectapiTestbedInterface1Sig2SignalDelegate() override;
    
    FOrgObjectapiTestbedInterface1Sig3Delegate OrgObjectapiTestbedInterface1Sig3Signal;
    FOrgObjectapiTestbedInterface1Sig3Delegate& GetOrgObjectapiTestbedInterface1Sig3SignalDelegate() override;
    
    FOrgObjectapiTestbedInterface1Prop1ChangedDelegate OrgObjectapiTestbedInterface1Prop1Changed;
    FOrgObjectapiTestbedInterface1Prop1ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop1ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop2ChangedDelegate OrgObjectapiTestbedInterface1Prop2Changed;
    FOrgObjectapiTestbedInterface1Prop2ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop2ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop3ChangedDelegate OrgObjectapiTestbedInterface1Prop3Changed;
    FOrgObjectapiTestbedInterface1Prop3ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop3ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop4ChangedDelegate OrgObjectapiTestbedInterface1Prop4Changed;
    FOrgObjectapiTestbedInterface1Prop4ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop4ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop5ChangedDelegate OrgObjectapiTestbedInterface1Prop5Changed;
    FOrgObjectapiTestbedInterface1Prop5ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop5ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop6ChangedDelegate OrgObjectapiTestbedInterface1Prop6Changed;
    FOrgObjectapiTestbedInterface1Prop6ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop6ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop7ChangedDelegate OrgObjectapiTestbedInterface1Prop7Changed;
    FOrgObjectapiTestbedInterface1Prop7ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop7ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop10ChangedDelegate OrgObjectapiTestbedInterface1Prop10Changed;
    FOrgObjectapiTestbedInterface1Prop10ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop10ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop11ChangedDelegate OrgObjectapiTestbedInterface1Prop11Changed;
    FOrgObjectapiTestbedInterface1Prop11ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop11ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop12ChangedDelegate OrgObjectapiTestbedInterface1Prop12Changed;
    FOrgObjectapiTestbedInterface1Prop12ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop12ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop14ChangedDelegate OrgObjectapiTestbedInterface1Prop14Changed;
    FOrgObjectapiTestbedInterface1Prop14ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop14ChangedDelegate() override;

    // properties
    bool GetProp1() const override;
    void SetProp1(bool bInProp1) override;

    int32 GetProp2() const override;
    void SetProp2(int32 InProp2) override;

    float GetProp3() const override;
    void SetProp3(float InProp3) override;

    FString GetProp4() const override;
    void SetProp4(const FString& InProp4) override;

    TArray<int32> GetProp5() const override;
    void SetProp5(const TArray<int32>& InProp5) override;

    FOrgObjectapiTestbedStruct1 GetProp6() const override;
    void SetProp6(const FOrgObjectapiTestbedStruct1& InProp6) override;

    int32 GetProp7() const override;
    void SetProp7(int32 InProp7) override;

    TArray<int32> GetProp10() const override;
    void SetProp10(const TArray<int32>& InProp10) override;

    TArray<FOrgObjectapiTestbedStruct1> GetProp11() const override;
    void SetProp11(const TArray<FOrgObjectapiTestbedStruct1>& InProp11) override;

    TArray<EOrgObjectapiTestbedEnum1> GetProp12() const override;
    void SetProp12(const TArray<EOrgObjectapiTestbedEnum1>& InProp12) override;

    TArray<FOrgObjectapiTestbedStruct1> GetProp14() const override;
    void SetProp14(const TArray<FOrgObjectapiTestbedStruct1>& InProp14) override;


    // operations
    void Op1() override;
    
    void Op2(int32 Step) override;
    
    int32 Op3() override;
    

    // olink sink interface
    std::string olinkObjectName() override;
    void olinkOnSignal(std::string name, nlohmann::json args) override;
    void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
    void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node) override;
    void olinkOnRelease() override;

private:
    void applyState(const nlohmann::json& fields);
    
    ApiGear::ObjectLink::IClientNode *m_node;
    bool m_isReady;
    // properties - local copy
    bool bProp1;
    int32 Prop2;
    float Prop3;
    FString Prop4;
    TArray<int32> Prop5;
    FOrgObjectapiTestbedStruct1 Prop6;
    int32 Prop7;
    TArray<int32> Prop10;
    TArray<FOrgObjectapiTestbedStruct1> Prop11;
    TArray<EOrgObjectapiTestbedEnum1> Prop12;
    TArray<FOrgObjectapiTestbedStruct1> Prop14;
};
