
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
#include "Testbed1StructInterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "Testbed1StructInterface")
class TESTBED1_API UTestbed1StructInterfaceProxy : public UGameInstanceSubsystem, public ITestbed1StructInterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTestbed1StructInterfaceProxy();
	virtual ~UTestbed1StructInterfaceProxy();

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface", DisplayName = "SigBool Signal")
	FTestbed1StructInterfaceSigBoolDelegate SigBoolSignal;
	FTestbed1StructInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface", DisplayName = "SigInt Signal")
	FTestbed1StructInterfaceSigIntDelegate SigIntSignal;
	FTestbed1StructInterfaceSigIntDelegate& GetSigIntSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface", DisplayName = "SigFloat Signal")
	FTestbed1StructInterfaceSigFloatDelegate SigFloatSignal;
	FTestbed1StructInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface", DisplayName = "SigString Signal")
	FTestbed1StructInterfaceSigStringDelegate SigStringSignal;
	FTestbed1StructInterfaceSigStringDelegate& GetSigStringSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface", DisplayName = "PropBool Changed")
	FTestbed1StructInterfacePropBoolChangedDelegate PropBoolChanged;
	FTestbed1StructInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface", DisplayName = "PropInt Changed")
	FTestbed1StructInterfacePropIntChangedDelegate PropIntChanged;
	FTestbed1StructInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface", DisplayName = "PropFloat Changed")
	FTestbed1StructInterfacePropFloatChangedDelegate PropFloatChanged;
	FTestbed1StructInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface", DisplayName = "PropString Changed")
	FTestbed1StructInterfacePropStringChangedDelegate PropStringChanged;
	FTestbed1StructInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructBool GetPropBool() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	void SetPropBool(const FTestbed1StructBool& PropBool) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructInt GetPropInt() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	void SetPropInt(const FTestbed1StructInt& PropInt) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructFloat GetPropFloat() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	void SetPropFloat(const FTestbed1StructFloat& PropFloat) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructString GetPropString() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	void SetPropString(const FTestbed1StructString& PropString) override;

	// operations
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBool(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool);
	FTestbed1StructBool FuncBool(const FTestbed1StructBool& ParamBool) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncInt(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructInt& ParamInt);
	FTestbed1StructBool FuncInt(const FTestbed1StructInt& ParamInt) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloat(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat);
	FTestbed1StructFloat FuncFloat(const FTestbed1StructFloat& ParamFloat) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncString(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString);
	FTestbed1StructString FuncString(const FTestbed1StructString& ParamString) override;

private:
	/** The connection to the service backend. */
	TSharedPtr<ITestbed1StructInterfaceInterface, ESPMode::ThreadSafe> service;

	// signals
	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnSigBool(const FTestbed1StructBool& ParamBool);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnSigInt(const FTestbed1StructInt& ParamInt);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnSigFloat(const FTestbed1StructFloat& ParamFloat);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnSigString(const FTestbed1StructString& ParamString);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(const FTestbed1StructBool& PropBool);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(const FTestbed1StructInt& PropInt);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnPropFloatChanged(const FTestbed1StructFloat& PropFloat);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnPropStringChanged(const FTestbed1StructString& PropString);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool, BlueprintSetter = SetPropBool, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructBool PropBool;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt, BlueprintSetter = SetPropInt, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructInt PropInt;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat, BlueprintSetter = SetPropFloat, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructFloat PropFloat;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString, BlueprintSetter = SetPropString, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructString PropString;
};
