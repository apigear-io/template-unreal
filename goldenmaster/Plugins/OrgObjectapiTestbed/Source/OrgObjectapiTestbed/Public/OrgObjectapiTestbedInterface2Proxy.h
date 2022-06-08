
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
#include "OrgObjectapiTestbedInterface2Proxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName="OrgObjectapiTestbedInterface2")
class ORGOBJECTAPITESTBED_API UOrgObjectapiTestbedInterface2Proxy : public UObject, public IOrgObjectapiTestbedInterface2Interface
{
	GENERATED_BODY()

public:
    explicit UOrgObjectapiTestbedInterface2Proxy();
    virtual ~UOrgObjectapiTestbedInterface2Proxy();

    // signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    FOrgObjectapiTestbedInterface2Prop200ChangedDelegate OrgObjectapiTestbedInterface2Prop200Changed;
    FOrgObjectapiTestbedInterface2Prop200ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop200ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void OnOrgObjectapiTestbedInterface2Prop200Changed(int32 InProp200);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    FOrgObjectapiTestbedInterface2Prop201ChangedDelegate OrgObjectapiTestbedInterface2Prop201Changed;
    FOrgObjectapiTestbedInterface2Prop201ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop201ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void OnOrgObjectapiTestbedInterface2Prop201Changed(int32 InProp201);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    FOrgObjectapiTestbedInterface2Prop202ChangedDelegate OrgObjectapiTestbedInterface2Prop202Changed;
    FOrgObjectapiTestbedInterface2Prop202ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop202ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void OnOrgObjectapiTestbedInterface2Prop202Changed(int32 InProp202);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    FOrgObjectapiTestbedInterface2Prop203ChangedDelegate OrgObjectapiTestbedInterface2Prop203Changed;
    FOrgObjectapiTestbedInterface2Prop203ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop203ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void OnOrgObjectapiTestbedInterface2Prop203Changed(float InProp203);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    FOrgObjectapiTestbedInterface2Prop204ChangedDelegate OrgObjectapiTestbedInterface2Prop204Changed;
    FOrgObjectapiTestbedInterface2Prop204ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop204ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void OnOrgObjectapiTestbedInterface2Prop204Changed(float InProp204);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    FOrgObjectapiTestbedInterface2Prop205ChangedDelegate OrgObjectapiTestbedInterface2Prop205Changed;
    FOrgObjectapiTestbedInterface2Prop205ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop205ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void OnOrgObjectapiTestbedInterface2Prop205Changed(const FString& InProp205);

    // properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    int32 GetProp200() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void SetProp200(int32 InProp200) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    int32 GetProp201() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void SetProp201(int32 InProp201) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    int32 GetProp202() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void SetProp202(int32 InProp202) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    float GetProp203() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void SetProp203(float InProp203) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    float GetProp204() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void SetProp204(float InProp204) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    FString GetProp205() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void SetProp205(const FString& InProp205) override;

    // operations
private:
	/** The connection to the service backend. */
	TSharedPtr<IOrgObjectapiTestbedInterface2Interface, ESPMode::ThreadSafe> service;

    // properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp200, BlueprintSetter=SetProp200, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    int32 Prop200;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp201, BlueprintSetter=SetProp201, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    int32 Prop201;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp202, BlueprintSetter=SetProp202, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    int32 Prop202;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp203, BlueprintSetter=SetProp203, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    float Prop203;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp204, BlueprintSetter=SetProp204, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    float Prop204;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp205, BlueprintSetter=SetProp205, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    FString Prop205;

};
