
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
#include "apig/Testbed2_apig.h"
#include "Testbed2ManyParamInterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName="Testbed2ManyParamInterface")
class TESTBED2_API UTestbed2ManyParamInterfaceProxy : public UGameInstanceSubsystem, public ITestbed2ManyParamInterfaceInterface
{
	GENERATED_BODY()

public:
    explicit UTestbed2ManyParamInterfaceProxy();
    virtual ~UTestbed2ManyParamInterfaceProxy();

    // signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Sig1 Signal")
    FTestbed2ManyParamInterfaceSig1Delegate Sig1Signal;
    FTestbed2ManyParamInterfaceSig1Delegate& GetSig1SignalDelegate() override;
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Sig2 Signal")
    FTestbed2ManyParamInterfaceSig2Delegate Sig2Signal;
    FTestbed2ManyParamInterfaceSig2Delegate& GetSig2SignalDelegate() override;
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Sig3 Signal")
    FTestbed2ManyParamInterfaceSig3Delegate Sig3Signal;
    FTestbed2ManyParamInterfaceSig3Delegate& GetSig3SignalDelegate() override;
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Sig4 Signal")
    FTestbed2ManyParamInterfaceSig4Delegate Sig4Signal;
    FTestbed2ManyParamInterfaceSig4Delegate& GetSig4SignalDelegate() override;
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Prop1 Changed")
    FTestbed2ManyParamInterfaceProp1ChangedDelegate Prop1Changed;
    FTestbed2ManyParamInterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Prop2 Changed")
    FTestbed2ManyParamInterfaceProp2ChangedDelegate Prop2Changed;
    FTestbed2ManyParamInterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Prop3 Changed")
    FTestbed2ManyParamInterfaceProp3ChangedDelegate Prop3Changed;
    FTestbed2ManyParamInterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|ManyParamInterface", DisplayName = "Prop4 Changed")
    FTestbed2ManyParamInterfaceProp4ChangedDelegate Prop4Changed;
    FTestbed2ManyParamInterfaceProp4ChangedDelegate& GetProp4ChangedDelegate() override;

    // properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
    int32 GetProp1() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
    void SetProp1(int32 Prop1) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
    int32 GetProp2() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
    void SetProp2(int32 Prop2) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
    int32 GetProp3() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
    void SetProp3(int32 Prop3) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
    int32 GetProp4() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
    void SetProp4(int32 Prop4) override;

    // operations
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", meta=(Latent, LatentInfo="LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    void Func1(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, int32& Result,int32 Param1);
    int32 Func1(int32 Param1) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", meta=(Latent, LatentInfo="LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    void Func2(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, int32& Result,int32 Param1, int32 Param2);
    int32 Func2(int32 Param1, int32 Param2) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", meta=(Latent, LatentInfo="LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    void Func3(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, int32& Result,int32 Param1, int32 Param2, int32 Param3);
    int32 Func3(int32 Param1, int32 Param2, int32 Param3) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", meta=(Latent, LatentInfo="LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    void Func4(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, int32& Result,int32 Param1, int32 Param2, int32 Param3, int32 Param4);
    int32 Func4(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;

private:
	/** The connection to the service backend. */
	TSharedPtr<ITestbed2ManyParamInterfaceInterface, ESPMode::ThreadSafe> service;

    // signals
    UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
    void OnSig1(int32 Param1);
    
    UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
    void OnSig2(int32 Param1, int32 Param2);
    
    UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
    void OnSig3(int32 Param1, int32 Param2, int32 Param3);
    
    UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
    void OnSig4(int32 Param1, int32 Param2, int32 Param3, int32 Param4);
    
    UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
    void OnProp1Changed(int32 Prop1);

    UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
    void OnProp2Changed(int32 Prop2);

    UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
    void OnProp3Changed(int32 Prop3);

    UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
    void OnProp4Changed(int32 Prop4);

    // properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp1, BlueprintSetter=SetProp1, Category = "ApiGear|Testbed2|ManyParamInterface")
    int32 Prop1;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp2, BlueprintSetter=SetProp2, Category = "ApiGear|Testbed2|ManyParamInterface")
    int32 Prop2;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp3, BlueprintSetter=SetProp3, Category = "ApiGear|Testbed2|ManyParamInterface")
    int32 Prop3;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetProp4, BlueprintSetter=SetProp4, Category = "ApiGear|Testbed2|ManyParamInterface")
    int32 Prop4;

};
