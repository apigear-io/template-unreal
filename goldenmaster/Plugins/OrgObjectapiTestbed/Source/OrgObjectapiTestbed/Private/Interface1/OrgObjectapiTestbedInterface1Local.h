
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
#include "AbstractOrgObjectapiTestbedInterface1Publisher.h"

class OrgObjectapiTestbedInterface1LocalService : public AbstractOrgObjectapiTestbedInterface1Publisher
{
public:

    explicit OrgObjectapiTestbedInterface1LocalService();
    virtual ~OrgObjectapiTestbedInterface1LocalService();

    // properties
    bool GetProp1() const override;
    void SetProp1(bool Value) override;

    int32 GetProp2() const override;
    void SetProp2(int32 Value) override;

    float GetProp3() const override;
    void SetProp3(float Value) override;

    FString GetProp4() const override;
    void SetProp4(FString Value) override;

    TArray<int32> GetProp5() const override;
    void SetProp5(TArray<int32> Value) override;

    FStruct1 GetProp6() const override;
    void SetProp6(const FStruct1& Value) override;

    int32 GetProp7() const override;
    void SetProp7(int32 Value) override;

    TArray<int32> GetProp10() const override;
    void SetProp10(TArray<int32> Value) override;

    TArray<FStruct1> GetProp11() const override;
    void SetProp11(const TArray<FStruct1>& Value) override;

    TArray<EEnum1> GetProp12() const override;
    void SetProp12(const TArray<EEnum1>& Value) override;

    TArray<FStruct1> GetProp14() const override;
    void SetProp14(const TArray<FStruct1>& Value) override;


    // operations
    void Op1() override;
    
    void Op2(int32 Step) override;
    
    int32 Op3() override;
    

private:
    // properties - local copy - use setter functions to emit changed signals
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