
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
#include "Generated/api/TbSimpleNoPropertiesInterfaceInterface.h"
#include "TbSimpleNoPropertiesInterface.generated.h"

UCLASS(BlueprintType, Blueprintable)
class TBSIMPLE_API UTbSimpleNoPropertiesInterface : public UObject, public ITbSimpleNoPropertiesInterfaceInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleNoPropertiesInterface();

	// signals
	FTbSimpleNoPropertiesInterfaceSigVoidDelegate SigVoidSignal;
	FTbSimpleNoPropertiesInterfaceSigVoidDelegate& GetSigVoidSignalDelegate() override;

	FTbSimpleNoPropertiesInterfaceSigBoolDelegate SigBoolSignal;
	FTbSimpleNoPropertiesInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	// properties
	// operations
	void FuncVoid_Implementation() override;

	void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override{};
	bool FuncBool_Implementation(bool bParamBool) override;

protected:
	// signals
	void BroadcastSigVoid_Implementation() override;

	void BroadcastSigBool_Implementation(bool bParamBool) override;

private:
	// properties - local copy - use setter functions to emit changed signals
};
