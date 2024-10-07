// Copyright Epic Games, Inc. All Rights Reserved

#include "ApiGearEditor.h"
#include "ApiGearEditorStyle.h"
#include "ApiGearEditorCommands.h"
#include "ISettingsModule.h"
#include "ApiGearSettings.h"
#include "ApiGearConnectionsStore.h"
#include "ApiGearConnection.h"
#include "LevelEditor.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Views/SListView.h"
#include "ToolMenus.h"

static const FName ApiGearConnectionTabName("ApiGear Connections");

#define LOCTEXT_NAMESPACE "ApiGearEditor"

void FApiGearEditorModule::StartupModule()
{
	// register settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "ApiGear", LOCTEXT("ApiGearSettingsName", "ApiGear"), LOCTEXT("ApiGearSettingsDescription", "Project settings for ApiGear plugin"), GetMutableDefault<UApiGearSettings>());
	}

	// register Editor widgets
	FApiGearEditorStyle::Initialize();
	FApiGearEditorStyle::ReloadTextures();

	FApiGearEditorCommands::Register();

	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(FApiGearEditorCommands::Get().OpenPluginWindow, FExecuteAction::CreateRaw(this, &FApiGearEditorModule::PluginButtonClicked), FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FApiGearEditorModule::RegisterMenus));

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(ApiGearConnectionTabName, FOnSpawnTab::CreateRaw(this, &FApiGearEditorModule::OnSpawnPluginTab)).SetDisplayName(LOCTEXT("FApiGearEditorTabTitle", "ApiGear Connections")).SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FApiGearEditorModule::ShutdownModule()
{
	// unregister settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "ApiGear");
	}

	// unregister editor widgets
	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FApiGearEditorStyle::Shutdown();

	FApiGearEditorCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(ApiGearConnectionTabName);
}

TSharedRef<SDockTab> FApiGearEditorModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	check(GEngine);
	AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionsStore>();

	// clang-format off
	TSharedRef<SDockTab> retTab = SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			[
				MakeConnectionsOverviewWidget()
			]
		];
	// clang-format on

	return retTab;
}

void FApiGearEditorModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(ApiGearConnectionTabName);
}

FReply FApiGearEditorModule::ConnectButtonClicked(FString InConnectionName)
{
	AGCM->GetConnection(InConnectionName)->Connect();

	return FReply::Handled();
}

FReply FApiGearEditorModule::DisconnectButtonClicked(FString InConnectionName)
{
	AGCM->GetConnection(InConnectionName)->Disconnect();

	return FReply::Handled();
}

FText FApiGearEditorModule::ConnectionEndpoint(FString InConnectionName) const
{
	FString ServerUrl = AGCM->GetConnection(InConnectionName)->GetServerURL();
	FString Protocol = AGCM->GetConnection(InConnectionName)->GetConnectionProtocolIdentifier();

	return FText::Format(LOCTEXT("ConnectionEndpoint", "{0} ({1})"), FText::FromString(ServerUrl), FText::FromString(Protocol));
}

FText FApiGearEditorModule::ConnectionStatus(FString InConnectionName) const
{
	switch (AGCM->GetConnection(InConnectionName)->GetConnectionState())
	{
	case EApiGearConnectionState::Connected:
		return FText::FromString("Connected");
	case EApiGearConnectionState::Disconnected:
		return FText::FromString("Disconnected");
	case EApiGearConnectionState::Connecting:
		return FText::FromString("Connecting");
	default:
		return FText::FromString("None");
	}
}

void FApiGearEditorModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FApiGearEditorCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FApiGearEditorCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

TSharedRef<SWidget> FApiGearEditorModule::MakeSingleConnectionOverviewWidget(TSharedPtr<FText> InConnectionName)
{
	FText ConnectButtonText = FText::FromString(TEXT("Connect"));
	FText DisconnectButtonText = FText::FromString(TEXT("Disconnect"));

	// clang-format off
	TSharedRef<SWidget> singleConnectionWidget = 
		SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.HAlign(HAlign_Left)
			[
				SNew(STextBlock)
				.Text(*InConnectionName)
			]
			+ SHorizontalBox::Slot()
			.HAlign(HAlign_Center)
			[
				SNew(STextBlock)
				.Text_Raw(this, &FApiGearEditorModule::ConnectionStatus, InConnectionName->ToString())
			]
			+ SHorizontalBox::Slot()
			.HAlign(HAlign_Center)
			.AutoWidth()
			[
				SNew(SButton)
				.Text(ConnectButtonText)
				.OnClicked_Raw(this, &FApiGearEditorModule::ConnectButtonClicked, InConnectionName->ToString())
			]
			+ SHorizontalBox::Slot()
			.HAlign(HAlign_Center)
			.AutoWidth()
			[
				SNew(SButton)
				.Text(DisconnectButtonText)
				.OnClicked_Raw(this, &FApiGearEditorModule::DisconnectButtonClicked, InConnectionName->ToString())
			];
	// clang-format on

	return singleConnectionWidget;
}

TSharedRef<SWidget> FApiGearEditorModule::MakeConnectionsOverviewWidget()
{
	TArray<FString> ConnectionNames;
	TArray<TSharedPtr<FText>>* ConnectionNamesShareable = &CurrentConnections;
	// remove old connections to make sure we don't accidentally duplicate them
	ConnectionNamesShareable->Empty(ConnectionNames.Num());

	AGCM->GetConnections().GenerateKeyArray(ConnectionNames);
	for (auto& ConnectionName : ConnectionNames)
	{
		ConnectionNamesShareable->Add(MakeShared<FText>(FText::FromString(ConnectionName)));
	}

	// clang-format off
	TSharedRef<SWidget> ConnectionsOverviewList = SNew(SListView<TSharedPtr<FText>>)
		.ListItemsSource(ConnectionNamesShareable)
		.OnGenerateRow_Lambda([this](TSharedPtr<FText> InConnectionName, const TSharedRef< class STableViewBase >& Owner)
		{
			return SNew(STableRow<TSharedPtr<FText>>, Owner)
					.Padding(FMargin(16, 4, 16, 4))
					.ToolTipText_Raw(this, &FApiGearEditorModule::ConnectionEndpoint, InConnectionName->ToString())
					[
						MakeSingleConnectionOverviewWidget(InConnectionName)
					];
		});
	// clang-format on

	return ConnectionsOverviewList;
}

IMPLEMENT_MODULE(FApiGearEditorModule, ApiGearEditor)

#undef LOCTEXT_NAMESPACE
