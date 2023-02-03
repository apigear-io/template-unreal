// Copyright Epic Games, Inc. All Rights Reserved
#pragma once

#include "IDetailCustomization.h"
#include "Templates/SharedPointer.h"

class IDetailLayoutBuilder;
class IPropertyHandle;
class SWidget;

/**
 * Provides the dropdown menu for the connection settings per module
 */
class FTestbed2ConnectionSettingsDetails : public IDetailCustomization
{
public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<IDetailCustomization> MakeInstance();

	/** IDetailCustomization interface */
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

private:
	TSharedRef<SWidget> MakeDefaultConnectionSelectorWidget(const TSharedPtr<IPropertyHandle>& PropertyHandle);

	TSharedPtr<FText> SelectedDefaultConnection;
	TArray<TSharedPtr<FText>> AvailableConnections;
};
