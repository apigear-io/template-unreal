
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
#include "Testbed1StructArrayInterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "Testbed1StructArrayInterface")
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
	void GetPropBool_Implementation(TArray<FTestbed1StructBool>& ReturnValue) const override;

	void SetPropBool_Implementation(const TArray<FTestbed1StructBool>& InPropBool) override;

	void GetPropInt_Implementation(TArray<FTestbed1StructInt>& ReturnValue) const override;

	void SetPropInt_Implementation(const TArray<FTestbed1StructInt>& InPropInt) override;

	void GetPropFloat_Implementation(TArray<FTestbed1StructFloat>& ReturnValue) const override;

	void SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat) override;

	void GetPropString_Implementation(TArray<FTestbed1StructString>& ReturnValue) const override;

	void SetPropString_Implementation(const TArray<FTestbed1StructString>& InPropString) override;

	// operations
	void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructBool>& ParamBool) override;
	void FuncBool_Implementation(FTestbed1StructBool& Result, const TArray<FTestbed1StructBool>& ParamBool) override;

	void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructInt>& ParamInt) override;
	void FuncInt_Implementation(FTestbed1StructBool& Result, const TArray<FTestbed1StructInt>& ParamInt) override;

	void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructFloat>& ParamFloat) override;
	void FuncFloat_Implementation(FTestbed1StructBool& Result, const TArray<FTestbed1StructFloat>& ParamFloat) override;

	void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructString>& ParamString) override;
	void FuncString_Implementation(FTestbed1StructBool& Result, const TArray<FTestbed1StructString>& ParamString) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed1|StructArrayInterface")
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> BackendService;

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
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructBool> PropBool;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	TArray<FTestbed1StructBool> GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void SetPropBool_Private(const TArray<FTestbed1StructBool>& InPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructInt> PropInt;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	TArray<FTestbed1StructInt> GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void SetPropInt_Private(const TArray<FTestbed1StructInt>& InPropInt);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructFloat> PropFloat;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	TArray<FTestbed1StructFloat> GetPropFloat_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void SetPropFloat_Private(const TArray<FTestbed1StructFloat>& InPropFloat);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|Testbed1|StructArrayInterface")
	TArray<FTestbed1StructString> PropString;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	TArray<FTestbed1StructString> GetPropString_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void SetPropString_Private(const TArray<FTestbed1StructString>& InPropString);
};
