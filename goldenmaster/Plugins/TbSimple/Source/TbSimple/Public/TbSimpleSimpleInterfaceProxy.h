
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
#include "apig/TbSimple_apig.h"
#include "TbSimpleSimpleInterfaceProxy.generated.h"

UCLASS(BlueprintType, Blueprintable, DisplayName = "TbSimpleSimpleInterface")
class TBSIMPLE_API UTbSimpleSimpleInterfaceProxy : public UGameInstanceSubsystem, public ITbSimpleSimpleInterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTbSimpleSimpleInterfaceProxy();
	virtual ~UTbSimpleSimpleInterfaceProxy();

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigBool Signal")
	FTbSimpleSimpleInterfaceSigBoolDelegate SigBoolSignal;
	FTbSimpleSimpleInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigInt Signal")
	FTbSimpleSimpleInterfaceSigIntDelegate SigIntSignal;
	FTbSimpleSimpleInterfaceSigIntDelegate& GetSigIntSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigFloat Signal")
	FTbSimpleSimpleInterfaceSigFloatDelegate SigFloatSignal;
	FTbSimpleSimpleInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigString Signal")
	FTbSimpleSimpleInterfaceSigStringDelegate SigStringSignal;
	FTbSimpleSimpleInterfaceSigStringDelegate& GetSigStringSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropBool Changed")
	FTbSimpleSimpleInterfacePropBoolChangedDelegate PropBoolChanged;
	FTbSimpleSimpleInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropInt Changed")
	FTbSimpleSimpleInterfacePropIntChangedDelegate PropIntChanged;
	FTbSimpleSimpleInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropFloat Changed")
	FTbSimpleSimpleInterfacePropFloatChangedDelegate PropFloatChanged;
	FTbSimpleSimpleInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropString Changed")
	FTbSimpleSimpleInterfacePropStringChangedDelegate PropStringChanged;
	FTbSimpleSimpleInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override;

	// properties
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	bool GetPropBool() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void SetPropBool(bool bPropBool) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	int32 GetPropInt() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void SetPropInt(int32 PropInt) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	float GetPropFloat() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void SetPropFloat(float PropFloat) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	FString GetPropString() const override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void SetPropString(const FString& PropString) override;

	// operations
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncBool(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, bool& Result, bool bParamBool);
	bool FuncBool(bool bParamBool) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncInt(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt);
	int32 FuncInt(int32 ParamInt) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncFloat(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, float& Result, float ParamFloat);
	float FuncFloat(float ParamFloat) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void FuncString(UObject* WorldContextObject, struct FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString);
	FString FuncString(const FString& ParamString) override;

private:
	/** The connection to the service backend. */
	TSharedPtr<ITbSimpleSimpleInterfaceInterface, ESPMode::ThreadSafe> service;

	// signals
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnSigBool(bool bParamBool);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnSigInt(int32 ParamInt);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnSigFloat(float ParamFloat);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnSigString(const FString& ParamString);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(bool bPropBool);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(int32 PropInt);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropFloatChanged(float PropFloat);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropStringChanged(const FString& PropString);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool, BlueprintSetter = SetPropBool, Category = "ApiGear|TbSimple|SimpleInterface")
	bool bPropBool;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt, BlueprintSetter = SetPropInt, Category = "ApiGear|TbSimple|SimpleInterface")
	int32 PropInt;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat, BlueprintSetter = SetPropFloat, Category = "ApiGear|TbSimple|SimpleInterface")
	float PropFloat;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString, BlueprintSetter = SetPropString, Category = "ApiGear|TbSimple|SimpleInterface")
	FString PropString;
};
