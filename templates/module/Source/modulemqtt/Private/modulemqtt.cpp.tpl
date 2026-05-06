{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $Category := printf "ApiGear%s" $ModuleName }}

{{- $class := printf "F%sMQTTModule" $ModuleName}}

#include "{{$ModuleName}}/{{$ModuleName}}MQTT.h"
#include "{{$ModuleName}}/Generated/{{$ModuleName}}Factory.h"
{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
{{- if $.Features.mqtt }}
#include "{{$ModuleName}}/Generated/MQTT/{{$class}}MQTTClient.h"
{{- end }}
{{- end }}
#include "Engine/Engine.h"
#include "{{$ModuleName}}Settings.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "{{$ModuleName}}MQTT"

void {{$class}}::StartupModule()
{
{{- $classFactory := printf "F%sModuleFactory" $ModuleName}}
{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
{{- if $.Features.mqtt }}
	{{$classFactory}}::RegisterFactory(TEXT("mqtt"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<I{{$class}}Interface>
		{
		return Cast<{{ printf "U%sMQTTClient" $class}}>(Collection.InitializeDependency({{ printf "U%sMQTTClient" $class}}::StaticClass()));
	});
{{- end }}
{{- end }}
}

void {{$class}}::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE({{$class}}, {{$ModuleName}}MQTT)

#undef LOCTEXT_NAMESPACE
