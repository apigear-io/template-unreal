
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
#include "Engine/LatentActionManager.h"
#include "Templates/SharedPointer.h"
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
	FTestbed1StructBool GetPropBool_Implementation() const override;

	void SetPropBool_Implementation(const FTestbed1StructBool& InPropBool) override;

	FTestbed1StructInt GetPropInt_Implementation() const override;

	void SetPropInt_Implementation(const FTestbed1StructInt& InPropInt) override;

	FTestbed1StructFloat GetPropFloat_Implementation() const override;

	void SetPropFloat_Implementation(const FTestbed1StructFloat& InPropFloat) override;

	FTestbed1StructString GetPropString_Implementation() const override;

	void SetPropString_Implementation(const FTestbed1StructString& InPropString) override;

	// operations
	void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool) override;
	FTestbed1StructBool FuncBool_Implementation(const FTestbed1StructBool& ParamBool) override;

	void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructInt& ParamInt) override;
	FTestbed1StructBool FuncInt_Implementation(const FTestbed1StructInt& ParamInt) override;

	void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat) override;
	FTestbed1StructFloat FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat) override;

	void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString) override;
	FTestbed1StructString FuncString_Implementation(const FTestbed1StructString& ParamString) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed1|StructInterface")
	TScriptInterface<ITestbed1StructInterfaceInterface> BackendService;

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
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructBool PropBool;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	FTestbed1StructBool GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void SetPropBool_Private(const FTestbed1StructBool& InPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructInt PropInt;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	FTestbed1StructInt GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void SetPropInt_Private(const FTestbed1StructInt& InPropInt);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructFloat PropFloat;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	FTestbed1StructFloat GetPropFloat_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void SetPropFloat_Private(const FTestbed1StructFloat& InPropFloat);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|Testbed1|StructInterface")
	FTestbed1StructString PropString;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	FTestbed1StructString GetPropString_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void SetPropString_Private(const FTestbed1StructString& InPropString);
};
