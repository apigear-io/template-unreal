/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "Testbed2Editor.h"
#include "ISettingsModule.h"
#include "PropertyEditorModule.h"
#include "Testbed2Settings.h"
#include "Testbed2ConnectionSettings.h"

#define LOCTEXT_NAMESPACE "Testbed2Editor"

void FTestbed2EditorModule::StartupModule()
{
	// register settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "ApiGear Testbed2", LOCTEXT("Testbed2SettingsName", "ApiGear Testbed2"), LOCTEXT("Testbed2SettingsDescription", "Project settings for ApiGear Testbed2 plugin"), GetMutableDefault<UTestbed2Settings>());
	}

	// register details customization
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
	PropertyModule.RegisterCustomClassLayout("Testbed2Settings", FOnGetDetailCustomizationInstance::CreateStatic(&FTestbed2ConnectionSettingsDetails::MakeInstance));
}

void FTestbed2EditorModule::ShutdownModule()
{
	// unregister settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "ApiGear Testbed2");
	}
}

IMPLEMENT_MODULE(FTestbed2EditorModule, Testbed2Editor)

#undef LOCTEXT_NAMESPACE
