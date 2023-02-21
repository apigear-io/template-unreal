
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

UCLASS(BlueprintType, Blueprintable)
class TBSIMPLE_API UTbSimpleSimpleInterfaceLoggingDecorator : public UGameInstanceSubsystem, public ITbSimpleSimpleInterfaceInterface
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

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigVoid Signal")
	FTbSimpleSimpleInterfaceSigVoidDelegate SigVoidSignal;
	FTbSimpleSimpleInterfaceSigVoidDelegate& GetSigVoidSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigBool Signal")
	FTbSimpleSimpleInterfaceSigBoolDelegate SigBoolSignal;
	FTbSimpleSimpleInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigInt Signal")
	FTbSimpleSimpleInterfaceSigIntDelegate SigIntSignal;
	FTbSimpleSimpleInterfaceSigIntDelegate& GetSigIntSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigInt32 Signal")
	FTbSimpleSimpleInterfaceSigInt32Delegate SigInt32Signal;
	FTbSimpleSimpleInterfaceSigInt32Delegate& GetSigInt32SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigInt64 Signal")
	FTbSimpleSimpleInterfaceSigInt64Delegate SigInt64Signal;
	FTbSimpleSimpleInterfaceSigInt64Delegate& GetSigInt64SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigFloat Signal")
	FTbSimpleSimpleInterfaceSigFloatDelegate SigFloatSignal;
	FTbSimpleSimpleInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigFloat32 Signal")
	FTbSimpleSimpleInterfaceSigFloat32Delegate SigFloat32Signal;
	FTbSimpleSimpleInterfaceSigFloat32Delegate& GetSigFloat32SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigFloat64 Signal")
	FTbSimpleSimpleInterfaceSigFloat64Delegate SigFloat64Signal;
	FTbSimpleSimpleInterfaceSigFloat64Delegate& GetSigFloat64SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "SigString Signal")
	FTbSimpleSimpleInterfaceSigStringDelegate SigStringSignal;
	FTbSimpleSimpleInterfaceSigStringDelegate& GetSigStringSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropBool Changed")
	FTbSimpleSimpleInterfacePropBoolChangedDelegate PropBoolChanged;
	FTbSimpleSimpleInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropInt Changed")
	FTbSimpleSimpleInterfacePropIntChangedDelegate PropIntChanged;
	FTbSimpleSimpleInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropInt32 Changed")
	FTbSimpleSimpleInterfacePropInt32ChangedDelegate PropInt32Changed;
	FTbSimpleSimpleInterfacePropInt32ChangedDelegate& GetPropInt32ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropInt64 Changed")
	FTbSimpleSimpleInterfacePropInt64ChangedDelegate PropInt64Changed;
	FTbSimpleSimpleInterfacePropInt64ChangedDelegate& GetPropInt64ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropFloat Changed")
	FTbSimpleSimpleInterfacePropFloatChangedDelegate PropFloatChanged;
	FTbSimpleSimpleInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropFloat32 Changed")
	FTbSimpleSimpleInterfacePropFloat32ChangedDelegate PropFloat32Changed;
	FTbSimpleSimpleInterfacePropFloat32ChangedDelegate& GetPropFloat32ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropFloat64 Changed")
	FTbSimpleSimpleInterfacePropFloat64ChangedDelegate PropFloat64Changed;
	FTbSimpleSimpleInterfacePropFloat64ChangedDelegate& GetPropFloat64ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface", DisplayName = "PropString Changed")
	FTbSimpleSimpleInterfacePropStringChangedDelegate PropStringChanged;
	FTbSimpleSimpleInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override;

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

	void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override;
	bool FuncBool_Implementation(bool bParamBool) override;

	void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt) override;
	int32 FuncInt_Implementation(int32 ParamInt) override;

	void FuncInt32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 ParamInt32) override;
	int32 FuncInt32_Implementation(int32 ParamInt32) override;

	void FuncInt64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int64& Result, int64 ParamInt64) override;
	int64 FuncInt64_Implementation(int64 ParamInt64) override;

	void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat) override;
	float FuncFloat_Implementation(float ParamFloat) override;

	void FuncFloat32Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, float& Result, float ParamFloat32) override;
	float FuncFloat32_Implementation(float ParamFloat32) override;

	void FuncFloat64Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, double& Result, double ParamFloat) override;
	double FuncFloat64_Implementation(double ParamFloat) override;

	void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FString& Result, const FString& ParamString) override;
	FString FuncString_Implementation(const FString& ParamString) override;

protected:
	// signals
	void BroadcastSigVoid_Implementation() override;

	void BroadcastSigBool_Implementation(bool bParamBool) override;

	void BroadcastSigInt_Implementation(int32 ParamInt) override;

	void BroadcastSigInt32_Implementation(int32 ParamInt32) override;

	void BroadcastSigInt64_Implementation(int64 ParamInt64) override;

	void BroadcastSigFloat_Implementation(float ParamFloat) override;

	void BroadcastSigFloat32_Implementation(float ParamFloa32) override;

	void BroadcastSigFloat64_Implementation(double ParamFloat64) override;

	void BroadcastSigString_Implementation(const FString& ParamString) override;

	void BroadcastPropBoolChanged_Implementation(bool bPropBool) override;

	void BroadcastPropIntChanged_Implementation(int32 PropInt) override;

	void BroadcastPropInt32Changed_Implementation(int32 PropInt32) override;

	void BroadcastPropInt64Changed_Implementation(int64 PropInt64) override;

	void BroadcastPropFloatChanged_Implementation(float PropFloat) override;

	void BroadcastPropFloat32Changed_Implementation(float PropFloat32) override;

	void BroadcastPropFloat64Changed_Implementation(double PropFloat64) override;

	void BroadcastPropStringChanged_Implementation(const FString& PropString) override;

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
	void OnPropBoolChanged(bool bPropBool);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(int32 PropInt);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropInt32Changed(int32 PropInt32);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropInt64Changed(int64 PropInt64);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropFloatChanged(float PropFloat);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropFloat32Changed(float PropFloat32);

	UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void OnPropFloat64Changed(double PropFloat64);

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

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt32_Private, BlueprintSetter = SetPropInt32_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	int32 PropInt32{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	int32 GetPropInt32_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropInt32_Private(int32 InPropInt32);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt64_Private, BlueprintSetter = SetPropInt64_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	int64 PropInt64{0LL};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	int64 GetPropInt64_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropInt64_Private(int64 InPropInt64);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat_Private, BlueprintSetter = SetPropFloat_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	float PropFloat{0.0f};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	float GetPropFloat_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropFloat_Private(float InPropFloat);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat32_Private, BlueprintSetter = SetPropFloat32_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	float PropFloat32{0.0f};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	float GetPropFloat32_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropFloat32_Private(float InPropFloat32);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropFloat64_Private, BlueprintSetter = SetPropFloat64_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	double PropFloat64{0.0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	double GetPropFloat64_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropFloat64_Private(double InPropFloat64);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropString_Private, BlueprintSetter = SetPropString_Private, Category = "ApiGear|TbSimple|SimpleInterface")
	FString PropString{FString()};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	FString GetPropString_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|SimpleInterface", BlueprintInternalUseOnly)
	void SetPropString_Private(const FString& InPropString);
};
