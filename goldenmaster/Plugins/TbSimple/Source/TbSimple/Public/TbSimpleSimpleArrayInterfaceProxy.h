
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
#include "apig/TbSimple_apig.h"
#include "TbSimpleSimpleArrayInterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "TbSimpleSimpleArrayInterface")
class TBSIMPLE_API UTbSimpleSimpleArrayInterfaceProxy : public UGameInstanceSubsystem, public ITbSimpleSimpleArrayInterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTbSimpleSimpleArrayInterfaceProxy();
	virtual ~UTbSimpleSimpleArrayInterfaceProxy();

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
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<bool> GetPropBool() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void SetPropBool(const TArray<bool>& PropBool) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int32> GetPropInt() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void SetPropInt(const TArray<int32>& PropInt) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<float> GetPropFloat() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void SetPropFloat(const TArray<float>& PropFloat) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<FString> GetPropString() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void SetPropString(const TArray<FString>& PropString) override;

	// operations
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBool(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<bool>& Result, const TArray<bool>& ParamBool);
	TArray<bool> FuncBool(const TArray<bool>& ParamBool) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncInt(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<int32>& Result, const TArray<int32>& ParamInt);
	TArray<int32> FuncInt(const TArray<int32>& ParamInt) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloat(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<float>& Result, const TArray<float>& ParamFloat);
	TArray<float> FuncFloat(const TArray<float>& ParamFloat) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncString(UObject* WorldContextObject, FLatentActionInfo LatentInfo, TArray<FString>& Result, const TArray<FString>& ParamString);
	TArray<FString> FuncString(const TArray<FString>& ParamString) override;

private:
	/** The connection to the service backend. */
	TSharedPtr<ITbSimpleSimpleArrayInterfaceInterface, ESPMode::ThreadSafe> service;

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
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool, BlueprintSetter = SetPropBool, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<bool> PropBool;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt, BlueprintSetter = SetPropInt, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<int32> PropInt;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat, BlueprintSetter = SetPropFloat, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<float> PropFloat;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString, BlueprintSetter = SetPropString, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TArray<FString> PropString;
};
