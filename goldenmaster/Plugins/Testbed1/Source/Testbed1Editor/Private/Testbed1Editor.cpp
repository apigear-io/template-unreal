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

#include "Testbed1Editor.h"
#include "ISettingsModule.h"
#include "Testbed1Settings.h"

#define LOCTEXT_NAMESPACE "Testbed1Editor"

void FTestbed1EditorModule::StartupModule()
{	
	// register settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)	
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "ApiGear Testbed1",
			LOCTEXT("Testbed1SettingsName", "ApiGear Testbed1"),
			LOCTEXT("Testbed1SettingsDescription", "Project settings for ApiGear Testbed1 plugin"),
			GetMutableDefault<UTestbed1Settings>()
		);
	}
}

void FTestbed1EditorModule::ShutdownModule()
{
	// unregister settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "ApiGear Testbed1");
	}
}

IMPLEMENT_MODULE(FTestbed1EditorModule, Testbed1Editor)

#undef LOCTEXT_NAMESPACE
