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
#include "TbSimple/Generated/api/TbSimpleNoOperationsInterfaceInterface.h"
#include "AbstractTbSimpleNoOperationsInterface.generated.h"

/**
 * Abstract UAbstractTbSimpleNoOperationsInterface
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class TBSIMPLEAPI_API UAbstractTbSimpleNoOperationsInterface : public UGameInstanceSubsystem, public ITbSimpleNoOperationsInterfaceInterface
{
	GENERATED_BODY()

public:
	// constructor
	UAbstractTbSimpleNoOperationsInterface();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// signals
	virtual UTbSimpleNoOperationsInterfacePublisher* _GetPublisher() override;

	// methods

	// properties
	virtual bool GetPropBool() const override PURE_VIRTUAL(UAbstractTbSimpleNoOperationsInterface::GetPropBool, return false;);
	virtual void SetPropBool(bool bInPropBool) override PURE_VIRTUAL(UAbstractTbSimpleNoOperationsInterface::SetPropBool, return;);

	virtual int32 GetPropInt() const override PURE_VIRTUAL(UAbstractTbSimpleNoOperationsInterface::GetPropInt, return 0;);
	virtual void SetPropInt(int32 InPropInt) override PURE_VIRTUAL(UAbstractTbSimpleNoOperationsInterface::SetPropInt, return;);

	virtual bool IsInitialized() const;

protected:
	bool bInitialized = false;

	// properties - local copy
	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropBool_Private, BlueprintSetter = SetPropBool_Private, Category = "ApiGear|TbSimple|NoOperationsInterface")
	bool bPropBool{false};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|NoOperationsInterface|Properties", BlueprintInternalUseOnly)
	bool GetPropBool_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|NoOperationsInterface|Properties", BlueprintInternalUseOnly)
	void SetPropBool_Private(bool bInPropBool);

	UPROPERTY(EditAnywhere, BlueprintGetter = GetPropInt_Private, BlueprintSetter = SetPropInt_Private, Category = "ApiGear|TbSimple|NoOperationsInterface")
	int32 PropInt{0};

	UFUNCTION(BlueprintGetter, Category = "ApiGear|TbSimple|NoOperationsInterface|Properties", BlueprintInternalUseOnly)
	int32 GetPropInt_Private() const;

	UFUNCTION(BlueprintSetter, Category = "ApiGear|TbSimple|NoOperationsInterface|Properties", BlueprintInternalUseOnly)
	void SetPropInt_Private(int32 InPropInt);

private:
	// signals
	UPROPERTY()
	UTbSimpleNoOperationsInterfacePublisher* TbSimpleNoOperationsInterfacePublisher;
};
