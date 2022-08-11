
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
#include "apig/Testbed1_apig.h"
#include "Testbed1StructArrayInterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName="Testbed1StructArrayInterface")
class TESTBED1_API UTestbed1StructArrayInterfaceProxy : public UGameInstanceSubsystem, public ITestbed1StructArrayInterfaceInterface
{
	GENERATED_BODY()

public:
    explicit UTestbed1StructArrayInterfaceProxy();
    virtual ~UTestbed1StructArrayInterfaceProxy();

    // signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "SigBool Signal")
    FTestbed1StructArrayInterfaceSigBoolDelegate SigBoolSignal;
    FTestbed1StructArrayInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "SigInt Signal")
    FTestbed1StructArrayInterfaceSigIntDelegate SigIntSignal;
    FTestbed1StructArrayInterfaceSigIntDelegate& GetSigIntSignalDelegate() override;
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "SigFloat Signal")
    FTestbed1StructArrayInterfaceSigFloatDelegate SigFloatSignal;
    FTestbed1StructArrayInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override;
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "SigString Signal")
    FTestbed1StructArrayInterfaceSigStringDelegate SigStringSignal;
    FTestbed1StructArrayInterfaceSigStringDelegate& GetSigStringSignalDelegate() override;
    
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "PropBool Changed")
    FTestbed1StructArrayInterfacePropBoolChangedDelegate PropBoolChanged;
    FTestbed1StructArrayInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "PropInt Changed")
    FTestbed1StructArrayInterfacePropIntChangedDelegate PropIntChanged;
    FTestbed1StructArrayInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "PropFloat Changed")
    FTestbed1StructArrayInterfacePropFloatChangedDelegate PropFloatChanged;
    FTestbed1StructArrayInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface", DisplayName = "PropString Changed")
    FTestbed1StructArrayInterfacePropStringChangedDelegate PropStringChanged;
    FTestbed1StructArrayInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override;

    // properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
    TArray<FTestbed1StructBool> GetPropBool() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
    void SetPropBool(const TArray<FTestbed1StructBool>& PropBool) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
    TArray<FTestbed1StructInt> GetPropInt() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
    void SetPropInt(const TArray<FTestbed1StructInt>& PropInt) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
    TArray<FTestbed1StructFloat> GetPropFloat() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
    void SetPropFloat(const TArray<FTestbed1StructFloat>& PropFloat) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
    TArray<FTestbed1StructString> GetPropString() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
    void SetPropString(const TArray<FTestbed1StructString>& PropString) override;

    // operations
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", meta=(Latent, LatentInfo="LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    void FuncBool(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, FTestbed1StructBool& Result,const TArray<FTestbed1StructBool>& ParamBool);
    FTestbed1StructBool FuncBool(const TArray<FTestbed1StructBool>& ParamBool) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", meta=(Latent, LatentInfo="LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    void FuncInt(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, FTestbed1StructBool& Result,const TArray<FTestbed1StructInt>& ParamInt);
    FTestbed1StructBool FuncInt(const TArray<FTestbed1StructInt>& ParamInt) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", meta=(Latent, LatentInfo="LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    void FuncFloat(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, FTestbed1StructBool& Result,const TArray<FTestbed1StructFloat>& ParamFloat);
    FTestbed1StructBool FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", meta=(Latent, LatentInfo="LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    void FuncString(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, FTestbed1StructBool& Result,const TArray<FTestbed1StructString>& ParamString);
    FTestbed1StructBool FuncString(const TArray<FTestbed1StructString>& ParamString) override;

private:
	/** The connection to the service backend. */
	TSharedPtr<ITestbed1StructArrayInterfaceInterface, ESPMode::ThreadSafe> service;

    // signals
    UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
    void OnSigBool(const TArray<FTestbed1StructBool>& ParamBool);
    
    UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
    void OnSigInt(const TArray<FTestbed1StructInt>& ParamInt);
    
    UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
    void OnSigFloat(const TArray<FTestbed1StructFloat>& ParamFloat);
    
    UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
    void OnSigString(const TArray<FTestbed1StructString>& ParamString);
    
    UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
    void OnPropBoolChanged(const TArray<FTestbed1StructBool>& PropBool);

    UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
    void OnPropIntChanged(const TArray<FTestbed1StructInt>& PropInt);

    UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
    void OnPropFloatChanged(const TArray<FTestbed1StructFloat>& PropFloat);

    UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
    void OnPropStringChanged(const TArray<FTestbed1StructString>& PropString);

    // properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter=GetPropBool, BlueprintSetter=SetPropBool, Category = "ApiGear|Testbed1|StructArrayInterface")
    TArray<FTestbed1StructBool> PropBool;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetPropInt, BlueprintSetter=SetPropInt, Category = "ApiGear|Testbed1|StructArrayInterface")
    TArray<FTestbed1StructInt> PropInt;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetPropFloat, BlueprintSetter=SetPropFloat, Category = "ApiGear|Testbed1|StructArrayInterface")
    TArray<FTestbed1StructFloat> PropFloat;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetPropString, BlueprintSetter=SetPropString, Category = "ApiGear|Testbed1|StructArrayInterface")
    TArray<FTestbed1StructString> PropString;

};
