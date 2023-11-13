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
#include "TbSimpleNoPropertiesInterfaceInterface.h"
#include "AbstractTbSimpleNoPropertiesInterface.generated.h"

/**
 * Abstract UAbstractTbSimpleNoPropertiesInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSIMPLE_API UAbstractTbSimpleNoPropertiesInterface : public UGameInstanceSubsystem, public ITbSimpleNoPropertiesInterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbSimpleNoPropertiesInterface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbSimpleNoPropertiesInterfaceSignals* _GetSignals_Implementation() override;

	// methods
	virtual void FuncVoid_Implementation() override PURE_VIRTUAL(UAbstractTbSimpleNoPropertiesInterface::FuncVoid_Implementation, return;);

	virtual void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override;
	virtual bool FuncBool_Implementation(bool bParamBool) override PURE_VIRTUAL(UAbstractTbSimpleNoPropertiesInterface::FuncBool_Implementation, return false;);

	// properties

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy

private:
	// signals
	UPROPERTY()
	UTbSimpleNoPropertiesInterfaceSignals* TbSimpleNoPropertiesInterfaceSignals;
};
