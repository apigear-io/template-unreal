// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbSimple/Generated/api/AbstractTbSimpleNoOperationsInterface.h"
#include "TbSimpleNoOperationsInterface.generated.h"

UCLASS(BlueprintType)
class TBSIMPLEIMPLEMENTATION_API UTbSimpleNoOperationsInterfaceImplementation : public UAbstractTbSimpleNoOperationsInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleNoOperationsInterfaceImplementation();

	// properties
	bool GetPropBool() const override;
	void SetPropBool(bool bPropBool) override;

	int32 GetPropInt() const override;
	void SetPropInt(int32 PropInt) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface|Properties")
	void _ResetProperties();

	// operations

protected:
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	mutable FRWLock bPropBoolRWLock;
	mutable FRWLock PropIntRWLock;
#endif
};
