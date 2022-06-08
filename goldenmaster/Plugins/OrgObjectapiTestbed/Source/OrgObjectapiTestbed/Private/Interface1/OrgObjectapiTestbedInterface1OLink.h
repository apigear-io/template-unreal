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
    FOrgObjectapiTestbedInterface1Sig1Delegate Sig1Signal;
    FOrgObjectapiTestbedInterface1Sig1Delegate& GetSig1SignalDelegate() override;
    
    FOrgObjectapiTestbedInterface1Sig2Delegate Sig2Signal;
    FOrgObjectapiTestbedInterface1Sig2Delegate& GetSig2SignalDelegate() override;
    
    FOrgObjectapiTestbedInterface1Sig3Delegate Sig3Signal;
    FOrgObjectapiTestbedInterface1Sig3Delegate& GetSig3SignalDelegate() override;
    
    FOrgObjectapiTestbedInterface1Prop1ChangedDelegate Prop1Changed;
    FOrgObjectapiTestbedInterface1Prop1ChangedDelegate& GetProp1ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop2ChangedDelegate Prop2Changed;
    FOrgObjectapiTestbedInterface1Prop2ChangedDelegate& GetProp2ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop3ChangedDelegate Prop3Changed;
    FOrgObjectapiTestbedInterface1Prop3ChangedDelegate& GetProp3ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop4ChangedDelegate Prop4Changed;
    FOrgObjectapiTestbedInterface1Prop4ChangedDelegate& GetProp4ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop5ChangedDelegate Prop5Changed;
    FOrgObjectapiTestbedInterface1Prop5ChangedDelegate& GetProp5ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop6ChangedDelegate Prop6Changed;
    FOrgObjectapiTestbedInterface1Prop6ChangedDelegate& GetProp6ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop7ChangedDelegate Prop7Changed;
    FOrgObjectapiTestbedInterface1Prop7ChangedDelegate& GetProp7ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop10ChangedDelegate Prop10Changed;
    FOrgObjectapiTestbedInterface1Prop10ChangedDelegate& GetProp10ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop11ChangedDelegate Prop11Changed;
    FOrgObjectapiTestbedInterface1Prop11ChangedDelegate& GetProp11ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop12ChangedDelegate Prop12Changed;
    FOrgObjectapiTestbedInterface1Prop12ChangedDelegate& GetProp12ChangedDelegate() override;

    FOrgObjectapiTestbedInterface1Prop14ChangedDelegate Prop14Changed;
    FOrgObjectapiTestbedInterface1Prop14ChangedDelegate& GetProp14ChangedDelegate() override;

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
