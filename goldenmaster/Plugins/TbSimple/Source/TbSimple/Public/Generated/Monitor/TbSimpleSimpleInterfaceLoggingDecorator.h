
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
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSimpleSimpleInterfaceInterface.h"
#include "TbSimpleSimpleInterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleSimpleInterfaceLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLE_API UTbSimpleSimpleInterfaceLoggingDecorator : public UAbstractTbSimpleSimpleInterface
{
	GENERATED_BODY()

public:
	explicit UTbSimpleSimpleInterfaceLoggingDecorator();
	virtual ~UTbSimpleSimpleInterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void setBackendService(TScriptInterface<ITbSimpleSimpleInterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	bool GetPropBool_Implementation() const override;

	void SetPropBool_Implementation(bool bInPropBool) override;

	int32 GetPropInt_Implementation() const override;

	void SetPropInt_Implementation(int32 InPropInt) override;

	int32 GetPropInt32_Implementation() const override;

	void SetPropInt32_Implementation(int32 InPropInt32) override;

	int64 GetPropInt64_Implementation() const override;

	void SetPropInt64_Implementation(int64 InPropInt64) override;

	float GetPropFloat_Implementation() const override;

	void SetPropFloat_Implementation(float InPropFloat) override;

	float GetPropFloat32_Implementation() const override;

	void SetPropFloat32_Implementation(float InPropFloat32) override;

	double GetPropFloat64_Implementation() const override;

	void SetPropFloat64_Implementation(double InPropFloat64) override;

	FString GetPropString_Implementation() const override;

	void SetPropString_Implementation(const FString& InPropString) override;

	// operations
	void FuncVoid_Implementation() override;

	bool FuncBool_Implementation(bool bParamBool) override;

	int32 FuncInt_Implementation(int32 ParamInt) override;

	int32 FuncInt32_Implementation(int32 ParamInt32) override;

	int64 FuncInt64_Implementation(int64 ParamInt64) override;

	float FuncFloat_Implementation(float ParamFloat) override;

	float FuncFloat32_Implementation(float ParamFloat32) override;

	double FuncFloat64_Implementation(double ParamFloat) override;

	FString FuncString_Implementation(const FString& ParamString) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|SimpleInterface")
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnSigVoid();

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnSigBool(bool bParamBool);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnSigInt(int32 ParamInt);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnSigInt32(int32 ParamInt32);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnSigInt64(int64 ParamInt64);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnSigFloat(float ParamFloat);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnSigFloat32(float ParamFloa32);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnSigFloat64(double ParamFloat64);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnSigString(const FString& ParamString);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(bool bInPropBool);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(int32 InPropInt);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropInt32Changed(int32 InPropInt32);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropInt64Changed(int64 InPropInt64);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropFloatChanged(float InPropFloat);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropFloat32Changed(float InPropFloat32);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropFloat64Changed(double InPropFloat64);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropStringChanged(const FString& InPropString);
};
