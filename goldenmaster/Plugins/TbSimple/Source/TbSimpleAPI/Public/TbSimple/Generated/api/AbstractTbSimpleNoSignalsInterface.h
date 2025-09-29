/**
Copyright 2024 ApiGear UG
Copyright 2024 Epic Games, Inc.

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

#include "Runtime/Launch/Resources/Version.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSimple_data.h"
#include "TbSimple/Generated/api/TbSimpleNoSignalsInterfaceInterface.h"
#include "AbstractTbSimpleNoSignalsInterface.generated.h"

/**
 * Abstract UAbstractTbSimpleNoSignalsInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSIMPLEAPI_API UAbstractTbSimpleNoSignalsInterface : public UGameInstanceSubsystem, public ITbSimpleNoSignalsInterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbSimpleNoSignalsInterface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbSimpleNoSignalsInterfacePublisher* _GetPublisher() override;

	// methods
	virtual void FuncVoid() override PURE_VIRTUAL(UAbstractTbSimpleNoSignalsInterface::FuncVoid, return;);

	virtual void FuncBoolAsync(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override;
	virtual TFuture<bool> FuncBoolAsync(bool bParamBool) override;
	virtual bool FuncBool(bool bParamBool) override PURE_VIRTUAL(UAbstractTbSimpleNoSignalsInterface::FuncBool, return false;);

	// properties
	virtual bool GetPropBool() const override PURE_VIRTUAL(UAbstractTbSimpleNoSignalsInterface::GetPropBool, return false;);
	virtual void SetPropBool(bool bInPropBool) override PURE_VIRTUAL(UAbstractTbSimpleNoSignalsInterface::SetPropBool, return;);

	virtual int32 GetPropInt() const override PURE_VIRTUAL(UAbstractTbSimpleNoSignalsInterface::GetPropInt, return 0;);
	virtual void SetPropInt(int32 InPropInt) override PURE_VIRTUAL(UAbstractTbSimpleNoSignalsInterface::SetPropInt, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|TbSimple|NoSignalsInterface")
	bool bPropBool{false};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|NoSignalsInterface|Properties", BlueprintInternalUseOnly)
	bool GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|NoSignalsInterface|Properties", BlueprintInternalUseOnly)
	void SetPropBool_Private(bool bInPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|TbSimple|NoSignalsInterface")
	int32 PropInt{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|NoSignalsInterface|Properties", BlueprintInternalUseOnly)
	int32 GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|NoSignalsInterface|Properties", BlueprintInternalUseOnly)
	void SetPropInt_Private(int32 InPropInt);

private:
	// signals
	UPROPERTY()
	UTbSimpleNoSignalsInterfacePublisher* TbSimpleNoSignalsInterfacePublisher;
};
