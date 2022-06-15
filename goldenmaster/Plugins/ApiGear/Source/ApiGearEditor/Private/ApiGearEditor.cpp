// Copyright Epic Games, Inc. All Rights Reserved

#include "ApiGearEditor.h"
#include "ApiGearEditorStyle.h"
#include "ApiGearEditorCommands.h"
#include "ISettingsModule.h"
#include "ApiGearSettings.h"
#include "ApiGearConnectionManager.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"

static const FName ApiGearConnectionTabName("ApiGear Connections");

#define LOCTEXT_NAMESPACE "ApiGearEditor"

void FApiGearEditorModule::StartupModule()
{	
	// register settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)	
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "ApiGear",
			LOCTEXT("ApiGearSettingsName", "ApiGear"),
			LOCTEXT("ApiGearSettingsDescription", "Project settings for ApiGear plugin"),
			GetMutableDefault<UApiGearSettings>()
		);
	}

	// register Editor widgets
	FApiGearEditorStyle::Initialize();
	FApiGearEditorStyle::ReloadTextures();

	FApiGearEditorCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FApiGearEditorCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FApiGearEditorModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FApiGearEditorModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(ApiGearConnectionTabName, FOnSpawnTab::CreateRaw(this, &FApiGearEditorModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FApiGearEditorTabTitle", "ApiGear Connections"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
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
	FText OLinkSectionText = FText::FromString(TEXT("OLink"));
	FText OLinkConnectButtonText = FText::FromString(TEXT("Connect"));
	FText OLinkDisconnectButtonText = FText::FromString(TEXT("Disconnect"));

	TSharedRef<SDockTab> retTab = SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				[
					SNew(STextBlock)
					.Text(OLinkSectionText)
				]
				+ SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					[
						SNew(SButton)
						.Text(OLinkConnectButtonText)
						.OnClicked_Raw(this, &FApiGearEditorModule::OLinkConnectButtonClicked)
					]
					+ SHorizontalBox::Slot()
					[
						SNew(SButton)
						.Text(OLinkDisconnectButtonText)
						.OnClicked_Raw(this, &FApiGearEditorModule::OLinkDisconnectButtonClicked)
					]
				]
			]
		];

	return retTab;
}

void FApiGearEditorModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(ApiGearConnectionTabName);
}

FReply FApiGearEditorModule::OLinkConnectButtonClicked()
{
	UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
	AGCM->ConnectOLink();

	return FReply::Handled();
}

FReply FApiGearEditorModule::OLinkDisconnectButtonClicked()
{
	UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
	AGCM->DisconnectOLink();

	return FReply::Handled();
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

IMPLEMENT_MODULE(FApiGearEditorModule, ApiGearEditor)

#undef LOCTEXT_NAMESPACE
