// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbIfaceimport/Generated/api/AbstractTbIfaceimportEmptyIf.h"
#include "TbIfaceimportEmptyIf.generated.h"

UCLASS(BlueprintType)
class TBIFACEIMPORTIMPLEMENTATION_API UTbIfaceimportEmptyIfImplementation : public UAbstractTbIfaceimportEmptyIf
{
	GENERATED_BODY()
public:
	virtual ~UTbIfaceimportEmptyIfImplementation();

	// properties
	// operations

protected:
#if PLATFORM_ANDROID && USE_ANDROID_JNI
#endif
};
