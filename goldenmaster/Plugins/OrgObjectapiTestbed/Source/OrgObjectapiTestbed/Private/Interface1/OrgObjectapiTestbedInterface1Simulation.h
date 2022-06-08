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

class OrgObjectapiTestbedInterface1SimulationService : public IOrgObjectapiTestbedInterface1Interface
{
public:

    explicit OrgObjectapiTestbedInterface1SimulationService();
    virtual ~OrgObjectapiTestbedInterface1SimulationService();

    // signals
    FSig1Delegate Sig1Signal;
    FSig1Delegate& GetSig1SignalDelegate() override;
    
    FSig2Delegate Sig2Signal;
    FSig2Delegate& GetSig2SignalDelegate() override;
    
    FSig3Delegate Sig3Signal;
    FSig3Delegate& GetSig3SignalDelegate() override;
    
    FbProp1ChangedDelegate bProp1Changed;
    FbProp1ChangedDelegate& GetbProp1ChangedDelegate() override;

    FProp2ChangedDelegate Prop2Changed;
    FProp2ChangedDelegate& GetProp2ChangedDelegate() override;

    FProp3ChangedDelegate Prop3Changed;
    FProp3ChangedDelegate& GetProp3ChangedDelegate() override;

    FProp4ChangedDelegate Prop4Changed;
    FProp4ChangedDelegate& GetProp4ChangedDelegate() override;

    FProp5ChangedDelegate Prop5Changed;
    FProp5ChangedDelegate& GetProp5ChangedDelegate() override;

    FProp6ChangedDelegate Prop6Changed;
    FProp6ChangedDelegate& GetProp6ChangedDelegate() override;

    FProp7ChangedDelegate Prop7Changed;
    FProp7ChangedDelegate& GetProp7ChangedDelegate() override;

    FProp10ChangedDelegate Prop10Changed;
    FProp10ChangedDelegate& GetProp10ChangedDelegate() override;

    FProp11ChangedDelegate Prop11Changed;
    FProp11ChangedDelegate& GetProp11ChangedDelegate() override;

    FProp12ChangedDelegate Prop12Changed;
    FProp12ChangedDelegate& GetProp12ChangedDelegate() override;

    FProp14ChangedDelegate Prop14Changed;
    FProp14ChangedDelegate& GetProp14ChangedDelegate() override;


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

    FStruct1 GetProp6() const override;
    void SetProp6(const FStruct1& InProp6) override;

    int32 GetProp7() const override;
    void SetProp7(int32 InProp7) override;

    TArray<int32> GetProp10() const override;
    void SetProp10(const TArray<int32>& InProp10) override;

    TArray<FStruct1> GetProp11() const override;
    void SetProp11(const TArray<FStruct1>& InProp11) override;

    TArray<EEnum1> GetProp12() const override;
    void SetProp12(const TArray<EEnum1>& InProp12) override;

    TArray<FStruct1> GetProp14() const override;
    void SetProp14(const TArray<FStruct1>& InProp14) override;


    // operations
    void Op1() override;
    
    void Op2(int32 Step) override;
    
    int32 Op3() override;
    

private:
    // properties - local copy
    bool bProp1;
    int32 Prop2;
    float Prop3;
    FString Prop4;
    TArray<int32> Prop5;
    FStruct1 Prop6;
    int32 Prop7;
    TArray<int32> Prop10;
    TArray<FStruct1> Prop11;
    TArray<EEnum1> Prop12;
    TArray<FStruct1> Prop14;
};
