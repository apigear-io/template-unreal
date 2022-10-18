
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
#include "apig/TbSimple_apig.h"
#include "TbSimpleSimpleArrayInterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "TbSimpleSimpleArrayInterface")
class TBSIMPLE_API UTbSimpleSimpleArrayInterfaceProxy : public UGameInstanceSubsystem, public ITbSimpleSimpleArrayInterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTbSimpleSimpleArrayInterfaceProxy();
	virtual ~UTbSimpleSimpleArrayInterfaceProxy();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void setBackendService(TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> InService);

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "SigBool Signal")
	FTbSimpleSimpleArrayInterfaceSigBoolDelegate SigBoolSignal;
	FTbSimpleSimpleArrayInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "SigInt Signal")
	FTbSimpleSimpleArrayInterfaceSigIntDelegate SigIntSignal;
	FTbSimpleSimpleArrayInterfaceSigIntDelegate& GetSigIntSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "SigFloat Signal")
	FTbSimpleSimpleArrayInterfaceSigFloatDelegate SigFloatSignal;
	FTbSimpleSimpleArrayInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "SigString Signal")
	FTbSimpleSimpleArrayInterfaceSigStringDelegate SigStringSignal;
	FTbSimpleSimpleArrayInterfaceSigStringDelegate& GetSigStringSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "PropBool Changed")
	FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate PropBoolChanged;
	FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "PropInt Changed")
	FTbSimpleSimpleArrayInterfacePropIntChangedDelegate PropIntChanged;
	FTbSimpleSimpleArrayInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "PropFloat Changed")
	FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate PropFloatChanged;
	FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface", DisplayName = "PropString Changed")
	FTbSimpleSimpleArrayInterfacePropStringChangedDelegate PropStringChanged;
	FTbSimpleSimpleArrayInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override;

	// properties
	TArray<bool> GetPropBool_Implementation() const override;

	void SetPropBool_Implementation(const TArray<bool>& InPropBool) override;

	TArray<int32> GetPropInt_Implementation() const override;

	void SetPropInt_Implementation(const TArray<int32>& InPropInt) override;

	TArray<float> GetPropFloat_Implementation() const override;

	void SetPropFloat_Implementation(const TArray<float>& InPropFloat) override;

	TArray<FString> GetPropString_Implementation() const override;

	void SetPropString_Implementation(const TArray<FString>& InPropString) override;

	// operations
	void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool) override;
	TArray<bool> FuncBool_Implementation(const TArray<bool>& ParamBool) override;

	void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt) override;
	TArray<int32> FuncInt_Implementation(const TArray<int32>& ParamInt) override;

	void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat) override;
	TArray<float> FuncFloat_Implementation(const TArray<float>& ParamFloat) override;

	void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString) override;
	TArray<FString> FuncString_Implementation(const TArray<FString>& ParamString) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnSigBool(const TArray<bool>& ParamBool);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnSigInt(const TArray<int32>& ParamInt);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnSigFloat(const TArray<float>& ParamFloat);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnSigString(const TArray<FString>& ParamString);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(const TArray<bool>& PropBool);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(const TArray<int32>& PropInt);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnPropFloatChanged(const TArray<float>& PropFloat);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void OnPropStringChanged(const TArray<FString>& PropString);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<bool> PropBool;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	TArray<bool> GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void SetPropBool_Private(const TArray<bool>& InPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int32> PropInt;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	TArray<int32> GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void SetPropInt_Private(const TArray<int32>& InPropInt);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<float> PropFloat;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	TArray<float> GetPropFloat_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void SetPropFloat_Private(const TArray<float>& InPropFloat);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<FString> PropString;

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	TArray<FString> GetPropString_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleArrayInterface", BlueprintInternalUseOnly)
	void SetPropString_Private(const TArray<FString>& InPropString);
};
