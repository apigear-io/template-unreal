{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $Category := printf "ApiGear %s" $ModuleName }}

{{- $mclass := printf "F%sEditorModule" $ModuleName }}

#include "{{$ModuleName}}Editor.h"
#include "ISettingsModule.h"
#include "PropertyEditorModule.h"
#include "{{$ModuleName}}Settings.h"
#include "{{$ModuleName}}ConnectionSettings.h"

#define LOCTEXT_NAMESPACE "{{$ModuleName}}Editor"

void {{$mclass}}::StartupModule()
{
	// register settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "{{$Category}}", LOCTEXT("{{$ModuleName}}SettingsName", "{{$Category}}"), LOCTEXT("{{$ModuleName}}SettingsDescription", "Project settings for {{$Category}} plugin"), GetMutableDefault<U{{$ModuleName}}Settings>());
	}

	// register details customization
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
	PropertyModule.RegisterCustomClassLayout("{{$ModuleName}}Settings", FOnGetDetailCustomizationInstance::CreateStatic(&F{{$ModuleName}}ConnectionSettingsDetails::MakeInstance));
}

void {{$mclass}}::ShutdownModule()
{
	// unregister settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "{{$Category}}");
	}
}

IMPLEMENT_MODULE({{$mclass}}, {{$ModuleName}}Editor)

#undef LOCTEXT_NAMESPACE
