// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbSimple/Generated/api/AbstractTbSimpleNoPropertiesInterface.h"
#include "TbSimpleNoPropertiesInterface.generated.h"

UCLASS(BlueprintType)
class TBSIMPLEIMPLEMENTATION_API UTbSimpleNoPropertiesInterfaceImplementation : public UAbstractTbSimpleNoPropertiesInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleNoPropertiesInterfaceImplementation();

	// properties
	// operations
	void FuncVoid() override;

	bool FuncBool(bool bParamBool) override;
};
