
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
#include "Subsystems/GameInstanceSubsystem.h"
#include "apig/TbSame1_apig.h"
#include "TbSame1SameEnum2InterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName="TbSame1SameEnum2Interface")
class TBSAME1_API UTbSame1SameEnum2InterfaceProxy : public UGameInstanceSubsystem, public ITbSame1SameEnum2InterfaceInterface
{
	GENERATED_BODY()

public:
    explicit UTbSame1SameEnum2InterfaceProxy();
    virtual ~UTbSame1SameEnum2InterfaceProxy();

    // signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum2Interface", DisplayName = "Sig1 Signal")
    FTbSame1SameEnum2InterfaceSig1Delegate Sig1Signal;
    FTbSame1SameEnum2InterfaceSig1Delegate& GetSig1SignalDelegate() override;
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum2Interface", DisplayName = "Sig2 Signal")
    FTbSame1SameEnum2InterfaceSig2Delegate Sig2Signal;
    FTbSame1SameEnum2InterfaceSig2Delegate& GetSig2SignalDelegate() override;
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum2Interface", DisplayName = "Prop1 Changed")
    FTbSame1SameEnum2InterfaceProp1ChangedDelegate Prop1Changed;
    FTbSame1SameEnum2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum2Interface", DisplayName = "Prop2 Changed")
    FTbSame1SameEnum2InterfaceProp2ChangedDelegate Prop2Changed;
    FTbSame1SameEnum2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

    // properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
    ETbSame1Enum1 GetProp1() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
    void SetProp1(const ETbSame1Enum1& Prop1) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
    ETbSame1Enum2 GetProp2() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface")
    void SetProp2(const ETbSame1Enum2& Prop2) override;

    // operations
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface", meta=(Latent, LatentInfo="LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    void Func1(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, ETbSame1Enum1& Result,const ETbSame1Enum1& Param1);
    ETbSame1Enum1 Func1(const ETbSame1Enum1& Param1) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface", meta=(Latent, LatentInfo="LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    void Func2(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, ETbSame1Enum1& Result,const ETbSame1Enum1& Param1, const ETbSame1Enum2& Param2);
    ETbSame1Enum1 Func2(const ETbSame1Enum1& Param1, const ETbSame1Enum2& Param2) override;

private:
	/** The connection to the service backend. */
	TSharedPtr<ITbSame1SameEnum2InterfaceInterface, ESPMode::ThreadSafe> service;

    // signals
    UFUNCTION(Category = "ApiGear|TbSame1|SameEnum2Interface", BlueprintInternalUseOnly)
    void OnSig1(const ETbSame1Enum1& Param1);
    
    UFUNCTION(Category = "ApiGear|TbSame1|SameEnum2Interface", BlueprintInternalUseOnly)
    void OnSig2(const ETbSame1Enum1& Param1, const ETbSame1Enum2& Param2);
    
    UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface", BlueprintInternalUseOnly)
    void OnProp1Changed(const ETbSame1Enum1& Prop1);

    UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum2Interface", BlueprintInternalUseOnly)
    void OnProp2Changed(const ETbSame1Enum2& Prop2);

    // properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp1, BlueprintSetter=SetProp1, Category = "ApiGear|TbSame1|SameEnum2Interface")
    ETbSame1Enum1 Prop1;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp2, BlueprintSetter=SetProp2, Category = "ApiGear|TbSame1|SameEnum2Interface")
    ETbSame1Enum2 Prop2;

};
