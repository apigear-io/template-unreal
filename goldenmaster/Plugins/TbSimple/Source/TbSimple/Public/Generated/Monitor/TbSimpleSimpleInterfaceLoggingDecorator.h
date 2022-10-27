
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
#include "TbSimple_apig.h"
#include "TbSimpleSimpleInterfaceLoggingDecorator.generated.h"

UCLASS(BlueprintType, Blueprintable)
class TBSIMPLE_API UTbSimpleSimpleInterfaceLoggingDecorator : public UGameInstanceSubsystem, public ITbSimpleSimpleInterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTbSimpleSimpleInterfaceLoggingDecorator();
	virtual ~UTbSimpleSimpleInterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void setBackendService(TScriptInterface<ITbSimpleSimpleInterfaceInterface> InService);

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
	bool GetPropBool_Implementation() const override;

	void SetPropBool_Implementation(bool bInPropBool) override;

	int32 GetPropInt_Implementation() const override;

	void SetPropInt_Implementation(int32 InPropInt) override;

	float GetPropFloat_Implementation() const override;

	void SetPropFloat_Implementation(float InPropFloat) override;

	FString GetPropString_Implementation() const override;

	void SetPropString_Implementation(const FString& InPropString) override;

	// operations
	void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override;
	bool FuncBool_Implementation(bool bParamBool) override;

	void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt) override;
	int32 FuncInt_Implementation(int32 ParamInt) override;

	void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat) override;
	float FuncFloat_Implementation(float ParamFloat) override;

	void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString) override;
	FString FuncString_Implementation(const FString& ParamString) override;

protected:
	// signals
	void BroadcastSigBool_Implementation(bool bParamBool) override;

	void BroadcastSigInt_Implementation(int32 ParamInt) override;

	void BroadcastSigFloat_Implementation(float ParamFloat) override;

	void BroadcastSigString_Implementation(const FString& ParamString) override;

	void BroadcastPropBoolChanged_Implementation(bool bPropBool) override;

	void BroadcastPropIntChanged_Implementation(int32 PropInt) override;

	void BroadcastPropFloatChanged_Implementation(float PropFloat) override;

	void BroadcastPropStringChanged_Implementation(const FString& PropString) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|SimpleInterface")
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnSigBool(bool bParamBool);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnSigInt(int32 ParamInt);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnSigFloat(float ParamFloat);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnSigString(const FString& ParamString);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(bool bPropBool);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(int32 PropInt);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropFloatChanged(float PropFloat);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropStringChanged(const FString& PropString);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	bool bPropBool{false};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	bool GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropBool_Private(bool bInPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	int32 PropInt{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	int32 GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropInt_Private(int32 InPropInt);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	float PropFloat{0.0f};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	float GetPropFloat_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropFloat_Private(float InPropFloat);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	FString PropString{FString()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	FString GetPropString_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropString_Private(const FString& InPropString);
};
