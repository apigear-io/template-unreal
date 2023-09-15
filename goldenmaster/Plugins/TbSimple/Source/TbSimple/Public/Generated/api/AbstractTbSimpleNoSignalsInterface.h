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

#include "Runtime/Launch/Resources/Version.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSimple_data.h"
#include "TbSimpleNoSignalsInterfaceInterface.h"
#include "AbstractTbSimpleNoSignalsInterface.generated.h"

/**
 * Abstract UAbstractTbSimpleNoSignalsInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSIMPLE_API UAbstractTbSimpleNoSignalsInterface : public UGameInstanceSubsystem, public ITbSimpleNoSignalsInterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbSimpleNoSignalsInterface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbSimpleNoSignalsInterfaceSignals* _GetSignals_Implementation() override
	{
		return TbSimpleNoSignalsInterfaceSignals;
	};

	// methods
	virtual void FuncVoid_Implementation() override PURE_VIRTUAL(UAbstractTbSimpleNoSignalsInterface::FuncVoid_Implementation, return;);

	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override;
	virtual bool FuncBool_Implementation(bool bParamBool) override PURE_VIRTUAL(UAbstractTbSimpleNoSignalsInterface::FuncBool_Implementation, return false;);

	// properties
	virtual bool GetPropBool_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleNoSignalsInterface::GetPropBool_Implementation, return false;);
	virtual void SetPropBool_Implementation(bool bInPropBool) override PURE_VIRTUAL(UAbstractTbSimpleNoSignalsInterface::SetPropBool_Implementation, return;);

	virtual int32 GetPropInt_Implementation() const override PURE_VIRTUAL(UAbstractTbSimpleNoSignalsInterface::GetPropInt_Implementation, return 0;);
	virtual void SetPropInt_Implementation(int32 InPropInt) override PURE_VIRTUAL(UAbstractTbSimpleNoSignalsInterface::SetPropInt_Implementation, return;);

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
	UTbSimpleNoSignalsInterfaceSignals* TbSimpleNoSignalsInterfaceSignals;
};
