// Copyright Epic Games, Inc. All Rights Reserved
#include "TbSame1ConnectionSettings.h"

#include "ApiGearSettings.h"
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

TSharedRef<IDetailCustomization> FTbSame1ConnectionSettingsDetails::MakeInstance()
{
	return MakeShareable(new FTbSame1ConnectionSettingsDetails);
}

TSharedRef<SWidget> FTbSame1ConnectionSettingsDetails::MakeDefaultConnectionSelectorWidget(const TSharedPtr<IPropertyHandle>& PropertyHandle)
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	check(settings);

	TArray<TSharedPtr<FText>>* AvailableConnectionNames = &AvailableConnections;
	FText TooltipText = FText::FromString(TEXT("Choose which connection should be used as default. Please make sure to have at least one connection defined."));

	TSharedPtr<FText> DefaultEffectName = TSharedPtr<FText>(new FText(FText::FromString(TEXT("Local"))));
	SelectedDefaultConnection = TSharedPtr<FText>(new FText(*DefaultEffectName));
	PropertyHandle->GetValueAsDisplayText(*SelectedDefaultConnection);

	AvailableConnectionNames->Add(DefaultEffectName);

	for (auto ConnectionSetting : settings->Connections)
	{
		AvailableConnectionNames->Add(MakeShared<FText>(FText::FromString(*ConnectionSetting.Key)));
	}

	// clang-format off
	// Text box component:
	TSharedRef<STextBlock > EditableTextBox = SNew(STextBlock )
		.Text_Lambda([this]() { return *SelectedDefaultConnection; });

	// Combo box component:
	TSharedRef<SWidget> ComboBox = SNew(SListView<TSharedPtr<FText>>)
		.ListItemsSource(AvailableConnectionNames)
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
			SelectedDefaultConnection = InText;
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

void FTbSame1ConnectionSettingsDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	IDetailCategoryBuilder& ConnectionsCategory = DetailBuilder.EditCategory(TEXT("ServiceSetup"));

	TSharedPtr<IPropertyHandle> ConnectionIdentifierPropertyHandle = DetailBuilder.GetProperty("ConnectionIdentifier", nullptr);
	IDetailPropertyRow& DefaultConnectionIdentifierPropertyRow = ConnectionsCategory.AddProperty(ConnectionIdentifierPropertyHandle);

	// clang-format off
	DefaultConnectionIdentifierPropertyRow.CustomWidget()
		.NameContent()
		[
			ConnectionIdentifierPropertyHandle->CreatePropertyNameWidget()
		]
		.ValueContent()
		.MaxDesiredWidth(500.0f)
		.MinDesiredWidth(100.0f)
		[
			MakeDefaultConnectionSelectorWidget(ConnectionIdentifierPropertyHandle)
		];
	// clang-format on
}
