// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbNames/Generated/api/AbstractTbNamesNamEs.h"
#include "TbNamesNamEs.generated.h"

UCLASS(BlueprintType)
class TBNAMESIMPLEMENTATION_API UTbNamesNamEsImplementation : public UAbstractTbNamesNamEs
{
	GENERATED_BODY()
public:
	virtual ~UTbNamesNamEsImplementation();

	// properties
	bool GetSwitch() const override;
	void SetSwitch(bool bSwitch) override;

	int32 GetSomeProperty() const override;
	void SetSomeProperty(int32 SomeProperty) override;

	int32 GetSomePoperty2() const override;
	void SetSomePoperty2(int32 SomePoperty2) override;

	ETbNamesEnum_With_Under_scores GetEnumProperty() const override;
	void SetEnumProperty(ETbNamesEnum_With_Under_scores EnumProperty) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Properties")
	void _ResetProperties();

	// operations
	void SomeFunction(bool bSomeParam) override;

	void SomeFunction2(bool bSomeParam) override;

protected:
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	mutable FRWLock bSwitchRWLock;
	mutable FRWLock SomePropertyRWLock;
	mutable FRWLock SomePoperty2RWLock;
	mutable FRWLock EnumPropertyRWLock;
#endif
};
