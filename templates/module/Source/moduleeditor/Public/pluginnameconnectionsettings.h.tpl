{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear%s" $ModuleName -}}
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
class F{{$ModuleName}}ConnectionSettingsDetails : public IDetailCustomization
{
public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<IDetailCustomization> MakeInstance();

	/** IDetailCustomization interface */
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

private:
	void CustomizeTracerDetails(IDetailLayoutBuilder& DetailBuilder);
	TSharedRef<SWidget> MakeDefaultBackendServiceSelectorWidget(const TSharedPtr<IPropertyHandle>& PropertyHandle);
	TSharedPtr<FText> SelectedDefaultBackendService;
	TArray<TSharedPtr<FText>> AvailableServices;

{{- if $.Features.olink }}

	void CustomizeOLinkDetails(IDetailLayoutBuilder& DetailBuilder);
	TSharedRef<SWidget> MakeDefaultOLinkConnectionSelectorWidget(const TSharedPtr<IPropertyHandle>& PropertyHandle);
	TSharedPtr<FText> SelectedDefaultOLinkConnection;
	TArray<TSharedPtr<FText>> AvailableOLinkConnections;
{{- end }}
};
