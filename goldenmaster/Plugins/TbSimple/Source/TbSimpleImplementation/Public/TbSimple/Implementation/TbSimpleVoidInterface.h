// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbSimple/Generated/api/AbstractTbSimpleVoidInterface.h"
#include "TbSimpleVoidInterface.generated.h"

UCLASS(BlueprintType)
class TBSIMPLEIMPLEMENTATION_API UTbSimpleVoidInterfaceImplementation : public UAbstractTbSimpleVoidInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleVoidInterfaceImplementation();

	// properties
	// operations
	void FuncVoid() override;
};
