
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
    FSig1Delegate Sig1Signal;
    FSig1Delegate& GetSig1SignalDelegate() override;
	UFUNCTION(Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnSig1();
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FSig2Delegate Sig2Signal;
    FSig2Delegate& GetSig2SignalDelegate() override;
	UFUNCTION(Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnSig2(int32 Step);
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FSig3Delegate Sig3Signal;
    FSig3Delegate& GetSig3SignalDelegate() override;
	UFUNCTION(Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnSig3();
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FbProp1ChangedDelegate bProp1Changed;
    FbProp1ChangedDelegate& GetbProp1ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnbProp1Changed(bool bInProp1);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp2ChangedDelegate Prop2Changed;
    FProp2ChangedDelegate& GetProp2ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnProp2Changed(int32 InProp2);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp3ChangedDelegate Prop3Changed;
    FProp3ChangedDelegate& GetProp3ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnProp3Changed(float InProp3);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp4ChangedDelegate Prop4Changed;
    FProp4ChangedDelegate& GetProp4ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnProp4Changed(const FString& InProp4);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp5ChangedDelegate Prop5Changed;
    FProp5ChangedDelegate& GetProp5ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnProp5Changed(const TArray<int32>& InProp5);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp6ChangedDelegate Prop6Changed;
    FProp6ChangedDelegate& GetProp6ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnProp6Changed(const FStruct1& InProp6);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp7ChangedDelegate Prop7Changed;
    FProp7ChangedDelegate& GetProp7ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnProp7Changed(int32 InProp7);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp10ChangedDelegate Prop10Changed;
    FProp10ChangedDelegate& GetProp10ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnProp10Changed(const TArray<int32>& InProp10);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp11ChangedDelegate Prop11Changed;
    FProp11ChangedDelegate& GetProp11ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnProp11Changed(const TArray<FStruct1>& InProp11);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp12ChangedDelegate Prop12Changed;
    FProp12ChangedDelegate& GetProp12ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnProp12Changed(const TArray<EEnum1>& InProp12);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FProp14ChangedDelegate Prop14Changed;
    FProp14ChangedDelegate& GetProp14ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void OnProp14Changed(const TArray<FStruct1>& InProp14);

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
    FStruct1 GetProp6() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp6(const FStruct1& InProp6) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    int32 GetProp7() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp7(int32 InProp7) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<int32> GetProp10() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp10(const TArray<int32>& InProp10) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<FStruct1> GetProp11() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp11(const TArray<FStruct1>& InProp11) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<EEnum1> GetProp12() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp12(const TArray<EEnum1>& InProp12) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<FStruct1> GetProp14() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp14(const TArray<FStruct1>& InProp14) override;

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
    FStruct1 Prop6;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp7, BlueprintSetter=SetProp7, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    int32 Prop7;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp10, BlueprintSetter=SetProp10, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<int32> Prop10;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp11, BlueprintSetter=SetProp11, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<FStruct1> Prop11;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp12, BlueprintSetter=SetProp12, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<EEnum1> Prop12;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp14, BlueprintSetter=SetProp14, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<FStruct1> Prop14;

};
