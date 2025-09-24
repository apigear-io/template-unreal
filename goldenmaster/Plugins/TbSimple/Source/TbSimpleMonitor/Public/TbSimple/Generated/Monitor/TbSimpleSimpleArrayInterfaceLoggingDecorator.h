
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
#include "TbSimple/Generated/api/AbstractTbSimpleSimpleArrayInterface.h"
#include "TbSimpleSimpleArrayInterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleSimpleArrayInterfaceLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLEMONITOR_API UTbSimpleSimpleArrayInterfaceLoggingDecorator : public UAbstractTbSimpleSimpleArrayInterface, public ITbSimpleSimpleArrayInterfaceSubscriberInterface
{
	GENERATED_BODY()

public:
	explicit UTbSimpleSimpleArrayInterfaceLoggingDecorator();
	virtual ~UTbSimpleSimpleArrayInterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void setBackendService(TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	TArray<bool> GetPropBool() const override;

	void SetPropBool(const TArray<bool>& InPropBool) override;

	TArray<int32> GetPropInt() const override;

	void SetPropInt(const TArray<int32>& InPropInt) override;

	TArray<int32> GetPropInt32() const override;

	void SetPropInt32(const TArray<int32>& InPropInt32) override;

	TArray<int64> GetPropInt64() const override;

	void SetPropInt64(const TArray<int64>& InPropInt64) override;

	TArray<float> GetPropFloat() const override;

	void SetPropFloat(const TArray<float>& InPropFloat) override;

	TArray<float> GetPropFloat32() const override;

	void SetPropFloat32(const TArray<float>& InPropFloat32) override;

	TArray<double> GetPropFloat64() const override;

	void SetPropFloat64(const TArray<double>& InPropFloat64) override;

	TArray<FString> GetPropString() const override;

	void SetPropString(const TArray<FString>& InPropString) override;

	FString GetPropReadOnlyString() const override;

	// operations
	TArray<bool> FuncBool(const TArray<bool>& ParamBool) override;

	TArray<int32> FuncInt(const TArray<int32>& ParamInt) override;

	TArray<int32> FuncInt32(const TArray<int32>& ParamInt32) override;

	TArray<int64> FuncInt64(const TArray<int64>& ParamInt64) override;

	TArray<float> FuncFloat(const TArray<float>& ParamFloat) override;

	TArray<float> FuncFloat32(const TArray<float>& ParamFloat32) override;

	TArray<double> FuncFloat64(const TArray<double>& ParamFloat) override;

	TArray<FString> FuncString(const TArray<FString>& ParamString) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> BackendService;

	// signals
	void OnSigBoolSignal(const TArray<bool>& InParamBool);

	void OnSigIntSignal(const TArray<int32>& InParamInt);

	void OnSigInt32Signal(const TArray<int32>& InParamInt32);

	void OnSigInt64Signal(const TArray<int64>& InParamInt64);

	void OnSigFloatSignal(const TArray<float>& InParamFloat);

	void OnSigFloat32Signal(const TArray<float>& InParamFloa32);

	void OnSigFloat64Signal(const TArray<double>& InParamFloat64);

	void OnSigStringSignal(const TArray<FString>& InParamString);

	void OnPropBoolChanged(const TArray<bool>& InPropBool);

	void OnPropIntChanged(const TArray<int32>& InPropInt);

	void OnPropInt32Changed(const TArray<int32>& InPropInt32);

	void OnPropInt64Changed(const TArray<int64>& InPropInt64);

	void OnPropFloatChanged(const TArray<float>& InPropFloat);

	void OnPropFloat32Changed(const TArray<float>& InPropFloat32);

	void OnPropFloat64Changed(const TArray<double>& InPropFloat64);

	void OnPropStringChanged(const TArray<FString>& InPropString);

	void OnPropReadOnlyStringChanged(const FString& InPropReadOnlyString);
};
