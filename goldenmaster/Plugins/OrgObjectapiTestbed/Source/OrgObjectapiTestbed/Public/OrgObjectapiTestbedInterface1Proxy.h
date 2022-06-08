
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

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "apig/OrgObjectapiTestbed_apig.h"
#include "OrgObjectapiTestbedInterface1Proxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName="OrgObjectapiTestbedInterface1")
class ORGOBJECTAPITESTBED_API UOrgObjectapiTestbedInterface1Proxy : public UObject, public IOrgObjectapiTestbedInterface1Interface
{
	GENERATED_BODY()

public:
    explicit UOrgObjectapiTestbedInterface1Proxy();
    virtual ~UOrgObjectapiTestbedInterface1Proxy();

    // signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FOrgObjectapiTestbedInterface1Sig1Delegate OrgObjectapiTestbedInterface1Sig1Signal;
    FOrgObjectapiTestbedInterface1Sig1Delegate& GetOrgObjectapiTestbedInterface1Sig1SignalDelegate() override;
	UFUNCTION(Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnOrgObjectapiTestbedInterface1Sig1();
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FOrgObjectapiTestbedInterface1Sig2Delegate OrgObjectapiTestbedInterface1Sig2Signal;
    FOrgObjectapiTestbedInterface1Sig2Delegate& GetOrgObjectapiTestbedInterface1Sig2SignalDelegate() override;
	UFUNCTION(Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnOrgObjectapiTestbedInterface1Sig2(int32 Step, const FString& Step2);
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FOrgObjectapiTestbedInterface1Sig3Delegate OrgObjectapiTestbedInterface1Sig3Signal;
    FOrgObjectapiTestbedInterface1Sig3Delegate& GetOrgObjectapiTestbedInterface1Sig3SignalDelegate() override;
	UFUNCTION(Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnOrgObjectapiTestbedInterface1Sig3(float Step);
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FOrgObjectapiTestbedInterface1Prop1ChangedDelegate OrgObjectapiTestbedInterface1Prop1Changed;
    FOrgObjectapiTestbedInterface1Prop1ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop1ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnOrgObjectapiTestbedInterface1Prop1Changed(bool bInProp1);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FOrgObjectapiTestbedInterface1Prop2ChangedDelegate OrgObjectapiTestbedInterface1Prop2Changed;
    FOrgObjectapiTestbedInterface1Prop2ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop2ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnOrgObjectapiTestbedInterface1Prop2Changed(int32 InProp2);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FOrgObjectapiTestbedInterface1Prop3ChangedDelegate OrgObjectapiTestbedInterface1Prop3Changed;
    FOrgObjectapiTestbedInterface1Prop3ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop3ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnOrgObjectapiTestbedInterface1Prop3Changed(float InProp3);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FOrgObjectapiTestbedInterface1Prop4ChangedDelegate OrgObjectapiTestbedInterface1Prop4Changed;
    FOrgObjectapiTestbedInterface1Prop4ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop4ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnOrgObjectapiTestbedInterface1Prop4Changed(const FString& InProp4);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FOrgObjectapiTestbedInterface1Prop5ChangedDelegate OrgObjectapiTestbedInterface1Prop5Changed;
    FOrgObjectapiTestbedInterface1Prop5ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop5ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnOrgObjectapiTestbedInterface1Prop5Changed(const TArray<int32>& InProp5);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FOrgObjectapiTestbedInterface1Prop6ChangedDelegate OrgObjectapiTestbedInterface1Prop6Changed;
    FOrgObjectapiTestbedInterface1Prop6ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop6ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnOrgObjectapiTestbedInterface1Prop6Changed(const FOrgObjectapiTestbedStruct1& InProp6);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FOrgObjectapiTestbedInterface1Prop7ChangedDelegate OrgObjectapiTestbedInterface1Prop7Changed;
    FOrgObjectapiTestbedInterface1Prop7ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop7ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnOrgObjectapiTestbedInterface1Prop7Changed(int32 InProp7);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FOrgObjectapiTestbedInterface1Prop10ChangedDelegate OrgObjectapiTestbedInterface1Prop10Changed;
    FOrgObjectapiTestbedInterface1Prop10ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop10ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnOrgObjectapiTestbedInterface1Prop10Changed(const TArray<int32>& InProp10);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FOrgObjectapiTestbedInterface1Prop11ChangedDelegate OrgObjectapiTestbedInterface1Prop11Changed;
    FOrgObjectapiTestbedInterface1Prop11ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop11ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnOrgObjectapiTestbedInterface1Prop11Changed(const TArray<FOrgObjectapiTestbedStruct1>& InProp11);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FOrgObjectapiTestbedInterface1Prop12ChangedDelegate OrgObjectapiTestbedInterface1Prop12Changed;
    FOrgObjectapiTestbedInterface1Prop12ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop12ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnOrgObjectapiTestbedInterface1Prop12Changed(const TArray<EOrgObjectapiTestbedEnum1>& InProp12);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FOrgObjectapiTestbedInterface1Prop14ChangedDelegate OrgObjectapiTestbedInterface1Prop14Changed;
    FOrgObjectapiTestbedInterface1Prop14ChangedDelegate& GetOrgObjectapiTestbedInterface1Prop14ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnOrgObjectapiTestbedInterface1Prop14Changed(const TArray<FOrgObjectapiTestbedStruct1>& InProp14);

    // properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    bool GetProp1() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp1(bool bInProp1) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    int32 GetProp2() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp2(int32 InProp2) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    float GetProp3() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp3(float InProp3) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FString GetProp4() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp4(const FString& InProp4) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<int32> GetProp5() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp5(const TArray<int32>& InProp5) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FOrgObjectapiTestbedStruct1 GetProp6() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp6(const FOrgObjectapiTestbedStruct1& InProp6) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    int32 GetProp7() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp7(int32 InProp7) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<int32> GetProp10() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp10(const TArray<int32>& InProp10) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<FOrgObjectapiTestbedStruct1> GetProp11() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp11(const TArray<FOrgObjectapiTestbedStruct1>& InProp11) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<EOrgObjectapiTestbedEnum1> GetProp12() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp12(const TArray<EOrgObjectapiTestbedEnum1>& InProp12) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<FOrgObjectapiTestbedStruct1> GetProp14() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp14(const TArray<FOrgObjectapiTestbedStruct1>& InProp14) override;

    // operations
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void Op1() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void Op2(int32 Step) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", meta=(Latent, LatentInfo="LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    void Op3(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, int32& Result);
    int32 Op3() override;

private:
	/** The connection to the service backend. */
	TSharedPtr<IOrgObjectapiTestbedInterface1Interface, ESPMode::ThreadSafe> service;

    // properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp1, BlueprintSetter=SetProp1, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    bool bProp1;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp2, BlueprintSetter=SetProp2, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    int32 Prop2;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp3, BlueprintSetter=SetProp3, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    float Prop3;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp4, BlueprintSetter=SetProp4, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FString Prop4;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp5, BlueprintSetter=SetProp5, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<int32> Prop5;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp6, BlueprintSetter=SetProp6, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FOrgObjectapiTestbedStruct1 Prop6;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp7, BlueprintSetter=SetProp7, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    int32 Prop7;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp10, BlueprintSetter=SetProp10, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<int32> Prop10;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp11, BlueprintSetter=SetProp11, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<FOrgObjectapiTestbedStruct1> Prop11;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp12, BlueprintSetter=SetProp12, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<EOrgObjectapiTestbedEnum1> Prop12;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp14, BlueprintSetter=SetProp14, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<FOrgObjectapiTestbedStruct1> Prop14;

};
