// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbSimple/Generated/api/AbstractTbSimpleEmptyInterface.h"
#include "TbSimpleEmptyInterface.generated.h"

UCLASS(BlueprintType)
class TBSIMPLEIMPLEMENTATION_API UTbSimpleEmptyInterfaceImplementation : public UAbstractTbSimpleEmptyInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleEmptyInterfaceImplementation();

	// properties
	// operations

protected:
#if PLATFORM_ANDROID && USE_ANDROID_JNI
#endif
};
