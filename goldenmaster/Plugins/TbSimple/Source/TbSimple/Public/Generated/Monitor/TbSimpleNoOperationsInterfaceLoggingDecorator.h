
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
#include "TbSimpleNoOperationsInterfaceInterface.h"
#include "TbSimpleNoOperationsInterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleNoOperationsInterfaceLoggingDecorator, Log, All);

UCLASS(BlueprintType, Blueprintable)
class TBSIMPLE_API UTbSimpleNoOperationsInterfaceLoggingDecorator : public UGameInstanceSubsystem, public ITbSimpleNoOperationsInterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTbSimpleNoOperationsInterfaceLoggingDecorator();
	virtual ~UTbSimpleNoOperationsInterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface")
	void setBackendService(TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface", DisplayName = "SigVoid Signal")
	FTbSimpleNoOperationsInterfaceSigVoidDelegate SigVoidSignal;
	FTbSimpleNoOperationsInterfaceSigVoidDelegate& GetSigVoidSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface", DisplayName = "SigBool Signal")
	FTbSimpleNoOperationsInterfaceSigBoolDelegate SigBoolSignal;
	FTbSimpleNoOperationsInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface", DisplayName = "PropBool Changed")
	FTbSimpleNoOperationsInterfacePropBoolChangedDelegate PropBoolChanged;
	FTbSimpleNoOperationsInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface", DisplayName = "PropInt Changed")
	FTbSimpleNoOperationsInterfacePropIntChangedDelegate PropIntChanged;
	FTbSimpleNoOperationsInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	// properties
	bool GetPropBool_Implementation() const override;

	void SetPropBool_Implementation(bool bInPropBool) override;

	int32 GetPropInt_Implementation() const override;

	void SetPropInt_Implementation(int32 InPropInt) override;

	// operations
protected:
	// signals
	void BroadcastSigVoid_Implementation() override;

	void BroadcastSigBool_Implementation(bool bParamBool) override;

	void BroadcastPropBoolChanged_Implementation(bool bPropBool) override;

	void BroadcastPropIntChanged_Implementation(int32 PropInt) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|NoOperationsInterface")
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void OnSigVoid();

	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void OnSigBool(bool bParamBool);

	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(bool bPropBool);

	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(int32 PropInt);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|TbSimple|NoOperationsInterface")
	bool bPropBool{false};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	bool GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void SetPropBool_Private(bool bInPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|TbSimple|NoOperationsInterface")
	int32 PropInt{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	int32 GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void SetPropInt_Private(int32 InPropInt);
};
