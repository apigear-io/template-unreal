// Copyright Epic Games, Inc. All Rights Reserved
#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FReply;
class FText;
class SDockTab;
class SWidget;

class FApiGearEditorModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void PluginButtonClicked();

	FReply ConnectButtonClicked(FString InConnectionName);
	FReply DisconnectButtonClicked(FString InConnectionName);
	FText ConnectionStatus(FString InConnectionName) const;
	FText ConnectionEndpoint(FString InConnectionName) const;

private:
	void RegisterMenus();
	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);
	TSharedRef<SWidget> MakeSingleConnectionOverviewWidget(TSharedPtr<FText> InConnectionName);
	TSharedRef<SWidget> MakeConnectionsOverviewWidget();
	TArray<TSharedPtr<FText>> CurrentConnections;

	TSharedPtr<class FUICommandList> PluginCommands;
	class UApiGearConnectionsStore* AGCM;

	/** Handle to the test dll we will load */
	void* FApiGearEditorModule;
};
