{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $ConnecitonEnabled := or .Features.stubs .Features.olink }}
{{- $Category := printf "ApiGear%s" $ModuleName }}
#include "{{$ModuleName}}ConnectionSettings.h"

{{- if $.Features.apigear }}
#include "ApiGearSettings.h"
{{- end }}
{{- if $.Features.olink }}
#include "ApiGearOLink.h"
{{- end }}
{{- if $.Features.mqtt }}
#include "apigearmqtt.h"
{{- end }}
#include "{{$ModuleName}}Settings.h"
#include "Templates/SharedPointer.h"
#include "IDetailCustomization.h"
#include "PropertyHandle.h"
#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "IDetailPropertyRow.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION >= 5)
#include "Styling/AppStyle.h"
#endif
#include "Widgets/Input/SComboButton.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Views/SListView.h"
#include "Widgets/Views/STableRow.h"

TSharedRef<IDetailCustomization> F{{$ModuleName}}ConnectionSettingsDetails::MakeInstance()
{
	return MakeShareable(new F{{$ModuleName}}ConnectionSettingsDetails);
}

{{- if $.Features.monitor }}

TSharedRef<SWidget> F{{$ModuleName}}ConnectionSettingsDetails::MakeDefaultBackendServiceSelectorWidget(const TSharedPtr<IPropertyHandle>& PropertyHandle)
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	check(settings);

	TArray<TSharedPtr<FText>>* AvailableServicesNames = &AvailableServices;
	FText TooltipText = FText::FromString(TEXT("Choose which service should be used as default."));

	TSharedPtr<FText> LocalServiceName = TSharedPtr<FText>(new FText(FText::FromString({{$ModuleName}}LocalBackendIdentifier)));
	AvailableServicesNames->Add(LocalServiceName);
	SelectedDefaultBackendService = LocalServiceName;

	TSharedPtr<FText> CurrentServiceName = TSharedPtr<FText>(new FText(FText::GetEmpty()));
	PropertyHandle->GetValueAsDisplayText(*CurrentServiceName);
	if (!CurrentServiceName->EqualTo(FText::GetEmpty()))
	{
		SelectedDefaultBackendService = CurrentServiceName;
	}

	for (auto ConnectionSetting : settings->Connections)
	{
		AvailableServicesNames->Add(MakeShared<FText>(FText::FromString(*ConnectionSetting.Key)));
	}

	// clang-format off
	// Text box component:
	TSharedRef<STextBlock > EditableTextBox = SNew(STextBlock )
		.Text_Lambda([this]() { return *SelectedDefaultBackendService; });

	// Combo box component:
	TSharedRef<SWidget> ComboBox = SNew(SListView<TSharedPtr<FText>>)
		.ListItemsSource(AvailableServicesNames)
		.OnGenerateRow_Lambda([](TSharedPtr<FText> InItem, const TSharedRef< class STableViewBase >& Owner)
		{
			return SNew(STableRow<TSharedPtr<FText>>, Owner)
					.Padding(FMargin(16, 4, 16, 4))
					[
						SNew(STextBlock).Text(*InItem)
					];
		})
		.OnSelectionChanged_Lambda([this, PropertyHandle](TSharedPtr<FText> InText, ESelectInfo::Type)
		{
			SelectedDefaultBackendService = InText;
			PropertyHandle->SetValue(InText->ToString());
		});


	//Generate widget:
	const TSharedRef<SWidget> NewWidget = SNew(SComboButton)
		.ContentPadding(FMargin(0, 0, 5, 0))
		.ToolTipText(TooltipText)
		.ButtonContent()
		[
			SNew(SBorder)
#if (ENGINE_MAJOR_VERSION >= 5)
			.BorderImage(FAppStyle::GetBrush("NoBorder"))
#endif
			.Padding(FMargin(0, 0, 5, 0))
			[
				EditableTextBox
			]
		]
		.MenuContent()
		[
			ComboBox
		];
	// clang-format on

	return NewWidget;
}

void F{{$ModuleName}}ConnectionSettingsDetails::CustomizeTracerDetails(IDetailLayoutBuilder& DetailBuilder)
{
	IDetailCategoryBuilder& TracerServiceCategory = DetailBuilder.EditCategory(TEXT("TracerServiceSetup"));

	TSharedPtr<IPropertyHandle> BackendServiceIdentifierPropertyHandle = DetailBuilder.GetProperty("TracerServiceIdentifier", nullptr);
	IDetailPropertyRow& DefaultBackendServiceIdentifierPropertyRow = TracerServiceCategory.AddProperty(BackendServiceIdentifierPropertyHandle);

	// clang-format off
	DefaultBackendServiceIdentifierPropertyRow.CustomWidget()
		.NameContent()
		[
			BackendServiceIdentifierPropertyHandle->CreatePropertyNameWidget()
		]
		.ValueContent()
		.MaxDesiredWidth(500.0f)
		.MinDesiredWidth(100.0f)
		[
			MakeDefaultBackendServiceSelectorWidget(BackendServiceIdentifierPropertyHandle)
		];
	// clang-format on
}
{{- end }}

{{- if $.Features.olink }}

TSharedRef<SWidget> F{{$ModuleName}}ConnectionSettingsDetails::MakeDefaultOLinkConnectionSelectorWidget(const TSharedPtr<IPropertyHandle>& PropertyHandle)
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	check(settings);

	TArray<TSharedPtr<FText>>* AvailableOLinkConnectionNames = &AvailableOLinkConnections;
	FText TooltipText = FText::FromString(TEXT("Choose which connection should be used as default. Please make sure to have at least one connection defined."));

	TSharedPtr<FText> PlaceholderText = TSharedPtr<FText>(new FText(FText::FromString("Please select a connection.")));
	SelectedDefaultOLinkConnection = PlaceholderText;

	for (auto ConnectionSetting : settings->Connections)
	{
		if (ConnectionSetting.Value.ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
		{
			TSharedPtr<FText> ConnectionName = MakeShared<FText>(FText::FromString(*ConnectionSetting.Key));
			AvailableOLinkConnectionNames->Add(ConnectionName);
		}
	}

	TSharedPtr<FText> CurrentConnectionName = TSharedPtr<FText>(new FText(FText::GetEmpty()));
	PropertyHandle->GetValueAsDisplayText(*CurrentConnectionName);
	if (!CurrentConnectionName->EqualTo(FText::GetEmpty()))
	{
		SelectedDefaultOLinkConnection = CurrentConnectionName;
	}

#if (ENGINE_MAJOR_VERSION >= 5)
	if (settings->Connections.IsEmpty())
#else
	if (settings->Connections.Num() == 0)
#endif
	{
		SelectedDefaultOLinkConnection = TSharedPtr<FText>(new FText(FText::FromString(TEXT("Please define a connection in the settings first!"))));
	}

	// clang-format off
	// Text box component:
	TSharedRef<STextBlock > EditableTextBox = SNew(STextBlock )
		.Text_Lambda([this]() { return *SelectedDefaultOLinkConnection; });

	// Combo box component:
	TSharedRef<SWidget> ComboBox = SNew(SListView<TSharedPtr<FText>>)
		.ListItemsSource(AvailableOLinkConnectionNames)
		.OnGenerateRow_Lambda([](TSharedPtr<FText> InItem, const TSharedRef< class STableViewBase >& Owner)
		{
			return SNew(STableRow<TSharedPtr<FText>>, Owner)
					.Padding(FMargin(16, 4, 16, 4))
					[
						SNew(STextBlock).Text(*InItem)
					];
		})
		.OnSelectionChanged_Lambda([this, PropertyHandle](TSharedPtr<FText> InText, ESelectInfo::Type)
		{
			SelectedDefaultOLinkConnection = InText;
			PropertyHandle->SetValue(InText->ToString());
		});


	//Generate widget:
	const TSharedRef<SWidget> NewWidget = SNew(SComboButton)
		.ContentPadding(FMargin(0, 0, 5, 0))
		.ToolTipText(TooltipText)
		.ButtonContent()
		[
			SNew(SBorder)
#if (ENGINE_MAJOR_VERSION >= 5)
			.BorderImage(FAppStyle::GetBrush("NoBorder"))
#endif
			.Padding(FMargin(0, 0, 5, 0))
			[
				EditableTextBox
			]
		]
		.MenuContent()
		[
			ComboBox
		];
	// clang-format on

	return NewWidget;
}

void F{{$ModuleName}}ConnectionSettingsDetails::CustomizeOLinkDetails(IDetailLayoutBuilder& DetailBuilder)
{
	IDetailCategoryBuilder& OLinkConnectionsCategory = DetailBuilder.EditCategory(TEXT("OLinkConnectionSetup"));

	TSharedPtr<IPropertyHandle> OLinkConnectionIdentifierPropertyHandle = DetailBuilder.GetProperty("OLinkConnectionIdentifier", nullptr);
	IDetailPropertyRow& DefaultOLinkConnectionIdentifierPropertyRow = OLinkConnectionsCategory.AddProperty(OLinkConnectionIdentifierPropertyHandle);

	// clang-format off
	DefaultOLinkConnectionIdentifierPropertyRow.CustomWidget()
		.NameContent()
		[
			OLinkConnectionIdentifierPropertyHandle->CreatePropertyNameWidget()
		]
		.ValueContent()
		.MaxDesiredWidth(500.0f)
		.MinDesiredWidth(100.0f)
		[
			MakeDefaultOLinkConnectionSelectorWidget(OLinkConnectionIdentifierPropertyHandle)
		];
	// clang-format on
}
{{- end }}

{{- if $.Features.mqtt }}

TSharedRef<SWidget> F{{$ModuleName}}ConnectionSettingsDetails::MakeDefaultMqttConnectionSelectorWidget(const TSharedPtr<IPropertyHandle>& PropertyHandle)
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	check(settings);

	TArray<TSharedPtr<FText>>* AvailableMqttConnectionNames = &AvailableMqttConnections;
	FText TooltipText = FText::FromString(TEXT("Choose which MQTT connection should be used as default. Please make sure to have at least one connection defined."));

	TSharedPtr<FText> PlaceholderText = TSharedPtr<FText>(new FText(FText::FromString("Please select a connection.")));
	SelectedDefaultMqttConnection = PlaceholderText;

	for (auto ConnectionSetting : settings->Connections)
	{
		if (ConnectionSetting.Value.ProtocolIdentifier == ApiGearMQTTProtocolIdentifier)
		{
			TSharedPtr<FText> ConnectionName = MakeShared<FText>(FText::FromString(*ConnectionSetting.Key));
			AvailableMqttConnectionNames->Add(ConnectionName);
		}
	}

	TSharedPtr<FText> CurrentConnectionName = TSharedPtr<FText>(new FText(FText::GetEmpty()));
	PropertyHandle->GetValueAsDisplayText(*CurrentConnectionName);
	if (!CurrentConnectionName->EqualTo(FText::GetEmpty()))
	{
		SelectedDefaultMqttConnection = CurrentConnectionName;
	}

#if (ENGINE_MAJOR_VERSION >= 5)
	if (settings->Connections.IsEmpty())
#else
	if (settings->Connections.Num() == 0)
#endif
	{
		SelectedDefaultMqttConnection = TSharedPtr<FText>(new FText(FText::FromString(TEXT("Please define a connection in the settings first!"))));
	}

	// clang-format off
	// Text box component:
	TSharedRef<STextBlock > EditableTextBox = SNew(STextBlock )
		.Text_Lambda([this]() { return *SelectedDefaultMqttConnection; });

	// Combo box component:
	TSharedRef<SWidget> ComboBox = SNew(SListView<TSharedPtr<FText>>)
		.ListItemsSource(AvailableMqttConnectionNames)
		.OnGenerateRow_Lambda([](TSharedPtr<FText> InItem, const TSharedRef< class STableViewBase >& Owner)
		{
			return SNew(STableRow<TSharedPtr<FText>>, Owner)
					.Padding(FMargin(16, 4, 16, 4))
					[
						SNew(STextBlock).Text(*InItem)
					];
		})
		.OnSelectionChanged_Lambda([this, PropertyHandle](TSharedPtr<FText> InText, ESelectInfo::Type)
		{
			SelectedDefaultMqttConnection = InText;
			PropertyHandle->SetValue(InText->ToString());
		});


	//Generate widget:
	const TSharedRef<SWidget> NewWidget = SNew(SComboButton)
		.ContentPadding(FMargin(0, 0, 5, 0))
		.ToolTipText(TooltipText)
		.ButtonContent()
		[
			SNew(SBorder)
#if (ENGINE_MAJOR_VERSION >= 5)
			.BorderImage(FAppStyle::GetBrush("NoBorder"))
#endif
			.Padding(FMargin(0, 0, 5, 0))
			[
				EditableTextBox
			]
		]
		.MenuContent()
		[
			ComboBox
		];
	// clang-format on

	return NewWidget;
}

void F{{$ModuleName}}ConnectionSettingsDetails::CustomizeMqttDetails(IDetailLayoutBuilder& DetailBuilder)
{
	IDetailCategoryBuilder& MqttConnectionsCategory = DetailBuilder.EditCategory(TEXT("MQTTConnectionSetup"));

	TSharedPtr<IPropertyHandle> MqttConnectionIdentifierPropertyHandle = DetailBuilder.GetProperty("MQTTConnectionIdentifier", nullptr);
	IDetailPropertyRow& DefaultMqttConnectionIdentifierPropertyRow = MqttConnectionsCategory.AddProperty(MqttConnectionIdentifierPropertyHandle);

	// clang-format off
	DefaultMqttConnectionIdentifierPropertyRow.CustomWidget()
		.NameContent()
		[
			MqttConnectionIdentifierPropertyHandle->CreatePropertyNameWidget()
		]
		.ValueContent()
		.MaxDesiredWidth(500.0f)
		.MinDesiredWidth(100.0f)
		[
			MakeDefaultMqttConnectionSelectorWidget(MqttConnectionIdentifierPropertyHandle)
		];
	// clang-format on
}
{{- end }}

void F{{$ModuleName}}ConnectionSettingsDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
{{- if $.Features.monitor }}
	CustomizeTracerDetails(DetailBuilder);
{{- end }}
{{- if $.Features.olink }}
	CustomizeOLinkDetails(DetailBuilder);
{{- end }}
{{- if $.Features.mqtt }}
	CustomizeMqttDetails(DetailBuilder);
{{- end }}
}