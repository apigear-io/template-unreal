
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
    FProp200ChangedDelegate Prop200Changed;
    FProp200ChangedDelegate& GetProp200ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void OnProp200Changed(int32 InProp200);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    FProp201ChangedDelegate Prop201Changed;
    FProp201ChangedDelegate& GetProp201ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void OnProp201Changed(int32 InProp201);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    FProp202ChangedDelegate Prop202Changed;
    FProp202ChangedDelegate& GetProp202ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void OnProp202Changed(int32 InProp202);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    FProp203ChangedDelegate Prop203Changed;
    FProp203ChangedDelegate& GetProp203ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void OnProp203Changed(float InProp203);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    FProp204ChangedDelegate Prop204Changed;
    FProp204ChangedDelegate& GetProp204ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void OnProp204Changed(float InProp204);

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    FProp205ChangedDelegate Prop205Changed;
    FProp205ChangedDelegate& GetProp205ChangedDelegate() override;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|OrgObjectapiTestbed|Interface2")
    void OnProp205Changed(const FString& InProp205);

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
