
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
#include "TbSame1SameEnum1InterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName="TbSame1SameEnum1Interface")
class TBSAME1_API UTbSame1SameEnum1InterfaceProxy : public UGameInstanceSubsystem, public ITbSame1SameEnum1InterfaceInterface
{
	GENERATED_BODY()

public:
    explicit UTbSame1SameEnum1InterfaceProxy();
    virtual ~UTbSame1SameEnum1InterfaceProxy();

    // signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum1Interface", DisplayName = "Sig1 Signal")
    FTbSame1SameEnum1InterfaceSig1Delegate Sig1Signal;
    FTbSame1SameEnum1InterfaceSig1Delegate& GetSig1SignalDelegate() override;
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame1|SameEnum1Interface", DisplayName = "Prop1 Changed")
    FTbSame1SameEnum1InterfaceProp1ChangedDelegate Prop1Changed;
    FTbSame1SameEnum1InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

    // properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface")
    ETbSame1Enum1 GetProp1() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface")
    void SetProp1(const ETbSame1Enum1& Prop1) override;

    // operations
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface", meta=(Latent, LatentInfo="LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    void Func1(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, ETbSame1Enum1& Result,const ETbSame1Enum1& Param1);
    ETbSame1Enum1 Func1(const ETbSame1Enum1& Param1) override;

private:
	/** The connection to the service backend. */
	TSharedPtr<ITbSame1SameEnum1InterfaceInterface, ESPMode::ThreadSafe> service;

    // signals
    UFUNCTION(Category = "ApiGear|TbSame1|SameEnum1Interface", BlueprintInternalUseOnly)
    void OnSig1(const ETbSame1Enum1& Param1);
    
    UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface", BlueprintInternalUseOnly)
    void OnProp1Changed(const ETbSame1Enum1& Prop1);

    // properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp1, BlueprintSetter=SetProp1, Category = "ApiGear|TbSame1|SameEnum1Interface")
    ETbSame1Enum1 Prop1;

};
