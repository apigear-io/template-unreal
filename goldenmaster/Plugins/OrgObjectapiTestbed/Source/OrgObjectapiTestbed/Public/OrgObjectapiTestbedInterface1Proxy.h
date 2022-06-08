
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
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", DisplayName = "Sig1 Signal")
    FOrgObjectapiTestbedInterface1Sig1Delegate Sig1Signal;
    FOrgObjectapiTestbedInterface1Sig1Delegate& GetSig1SignalDelegate() override;
	UFUNCTION(Category = "ApiGear|OrgObjectapiTestbed|Interface1", BlueprintInternalUseOnly)
    void OnSig1();
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", DisplayName = "Sig2 Signal")
    FOrgObjectapiTestbedInterface1Sig2Delegate Sig2Signal;
    FOrgObjectapiTestbedInterface1Sig2Delegate& GetSig2SignalDelegate() override;
	UFUNCTION(Category = "ApiGear|OrgObjectapiTestbed|Interface1", BlueprintInternalUseOnly)
    void OnSig2(int32 Step, const FString& Step2);
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", DisplayName = "Sig3 Signal")
    FOrgObjectapiTestbedInterface1Sig3Delegate Sig3Signal;
    FOrgObjectapiTestbedInterface1Sig3Delegate& GetSig3SignalDelegate() override;
	UFUNCTION(Category = "ApiGear|OrgObjectapiTestbed|Interface1", BlueprintInternalUseOnly)
    void OnSig3(float Step);
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", DisplayName = "Prop1 Changed")
    FOrgObjectapiTestbedInterface1Prop1ChangedDelegate Prop1Changed;
    FOrgObjectapiTestbedInterface1Prop1ChangedDelegate& GetProp1ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", BlueprintInternalUseOnly)
    void OnProp1Changed(bool bProp1);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", DisplayName = "Prop2 Changed")
    FOrgObjectapiTestbedInterface1Prop2ChangedDelegate Prop2Changed;
    FOrgObjectapiTestbedInterface1Prop2ChangedDelegate& GetProp2ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", BlueprintInternalUseOnly)
    void OnProp2Changed(int32 Prop2);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", DisplayName = "Prop3 Changed")
    FOrgObjectapiTestbedInterface1Prop3ChangedDelegate Prop3Changed;
    FOrgObjectapiTestbedInterface1Prop3ChangedDelegate& GetProp3ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", BlueprintInternalUseOnly)
    void OnProp3Changed(float Prop3);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", DisplayName = "Prop4 Changed")
    FOrgObjectapiTestbedInterface1Prop4ChangedDelegate Prop4Changed;
    FOrgObjectapiTestbedInterface1Prop4ChangedDelegate& GetProp4ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", BlueprintInternalUseOnly)
    void OnProp4Changed(const FString& Prop4);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", DisplayName = "Prop5 Changed")
    FOrgObjectapiTestbedInterface1Prop5ChangedDelegate Prop5Changed;
    FOrgObjectapiTestbedInterface1Prop5ChangedDelegate& GetProp5ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", BlueprintInternalUseOnly)
    void OnProp5Changed(const TArray<int32>& Prop5);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", DisplayName = "Prop6 Changed")
    FOrgObjectapiTestbedInterface1Prop6ChangedDelegate Prop6Changed;
    FOrgObjectapiTestbedInterface1Prop6ChangedDelegate& GetProp6ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", BlueprintInternalUseOnly)
    void OnProp6Changed(const FOrgObjectapiTestbedStruct1& Prop6);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", DisplayName = "Prop7 Changed")
    FOrgObjectapiTestbedInterface1Prop7ChangedDelegate Prop7Changed;
    FOrgObjectapiTestbedInterface1Prop7ChangedDelegate& GetProp7ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", BlueprintInternalUseOnly)
    void OnProp7Changed(int32 Prop7);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", DisplayName = "Prop10 Changed")
    FOrgObjectapiTestbedInterface1Prop10ChangedDelegate Prop10Changed;
    FOrgObjectapiTestbedInterface1Prop10ChangedDelegate& GetProp10ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", BlueprintInternalUseOnly)
    void OnProp10Changed(const TArray<int32>& Prop10);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", DisplayName = "Prop11 Changed")
    FOrgObjectapiTestbedInterface1Prop11ChangedDelegate Prop11Changed;
    FOrgObjectapiTestbedInterface1Prop11ChangedDelegate& GetProp11ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", BlueprintInternalUseOnly)
    void OnProp11Changed(const TArray<FOrgObjectapiTestbedStruct1>& Prop11);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", DisplayName = "Prop12 Changed")
    FOrgObjectapiTestbedInterface1Prop12ChangedDelegate Prop12Changed;
    FOrgObjectapiTestbedInterface1Prop12ChangedDelegate& GetProp12ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", BlueprintInternalUseOnly)
    void OnProp12Changed(const TArray<EOrgObjectapiTestbedEnum1>& Prop12);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", DisplayName = "Prop14 Changed")
    FOrgObjectapiTestbedInterface1Prop14ChangedDelegate Prop14Changed;
    FOrgObjectapiTestbedInterface1Prop14ChangedDelegate& GetProp14ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1", BlueprintInternalUseOnly)
    void OnProp14Changed(const TArray<FOrgObjectapiTestbedStruct1>& Prop14);

    // properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    bool GetProp1() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp1(bool bProp1) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    int32 GetProp2() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp2(int32 Prop2) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    float GetProp3() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp3(float Prop3) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FString GetProp4() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp4(const FString& Prop4) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<int32> GetProp5() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp5(const TArray<int32>& Prop5) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    FOrgObjectapiTestbedStruct1 GetProp6() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp6(const FOrgObjectapiTestbedStruct1& Prop6) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    int32 GetProp7() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp7(int32 Prop7) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<int32> GetProp10() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp10(const TArray<int32>& Prop10) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<FOrgObjectapiTestbedStruct1> GetProp11() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp11(const TArray<FOrgObjectapiTestbedStruct1>& Prop11) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<EOrgObjectapiTestbedEnum1> GetProp12() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp12(const TArray<EOrgObjectapiTestbedEnum1>& Prop12) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    TArray<FOrgObjectapiTestbedStruct1> GetProp14() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface1")
    void SetProp14(const TArray<FOrgObjectapiTestbedStruct1>& Prop14) override;

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
