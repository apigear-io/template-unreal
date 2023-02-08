
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
#include "TbSimpleNoSignalsInterfaceInterface.h"
#include "TbSimpleNoSignalsInterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleNoSignalsInterfaceLoggingDecorator, Log, All);

UCLASS(BlueprintType, Blueprintable)
class TBSIMPLE_API UTbSimpleNoSignalsInterfaceLoggingDecorator : public UGameInstanceSubsystem, public ITbSimpleNoSignalsInterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTbSimpleNoSignalsInterfaceLoggingDecorator();
	virtual ~UTbSimpleNoSignalsInterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface")
	void setBackendService(TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoSignalsInterface", DisplayName = "PropBool Changed")
	FTbSimpleNoSignalsInterfacePropBoolChangedDelegate PropBoolChanged;
	FTbSimpleNoSignalsInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoSignalsInterface", DisplayName = "PropInt Changed")
	FTbSimpleNoSignalsInterfacePropIntChangedDelegate PropIntChanged;
	FTbSimpleNoSignalsInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	// properties
	bool GetPropBool_Implementation() const override;

	void SetPropBool_Implementation(bool bInPropBool) override;

	int32 GetPropInt_Implementation() const override;

	void SetPropInt_Implementation(int32 InPropInt) override;

	// operations
	void FuncVoid_Implementation() override;

	void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override;
	bool FuncBool_Implementation(bool bParamBool) override;

protected:
	// signals

	void BroadcastPropBoolChanged_Implementation(bool bPropBool) override;

	void BroadcastPropIntChanged_Implementation(int32 PropInt) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|NoSignalsInterface")
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> BackendService;

	// signals

	UFUNCTION(Category = "ApiGear|TbSimple|NoSignalsInterface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(bool bPropBool);

	UFUNCTION(Category = "ApiGear|TbSimple|NoSignalsInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(int32 PropInt);

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|TbSimple|NoSignalsInterface")
	bool bPropBool{false};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|NoSignalsInterface", BlueprintInternalUseOnly)
	bool GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|NoSignalsInterface", BlueprintInternalUseOnly)
	void SetPropBool_Private(bool bInPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|TbSimple|NoSignalsInterface")
	int32 PropInt{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|NoSignalsInterface", BlueprintInternalUseOnly)
	int32 GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|NoSignalsInterface", BlueprintInternalUseOnly)
	void SetPropInt_Private(int32 InPropInt);
};
