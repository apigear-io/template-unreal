{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $Category := printf "ApiGear%s" $ModuleName }}

{{- $class := printf "F%sOLinkModule" $ModuleName}}

#include "{{$ModuleName}}/{{$ModuleName}}OLink.h"
#include "{{$ModuleName}}/Generated/{{$ModuleName}}Factory.h"
{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
{{- if $.Features.olink }}
#include "{{$ModuleName}}/Generated/OLink/{{$class}}OLinkClient.h"
{{- end }}
{{- end }}
#include "Engine/Engine.h"
#include "{{$ModuleName}}Settings.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "{{$ModuleName}}OLink"

void {{$class}}::StartupModule()
{
{{- $classFactory := printf "F%sModuleFactory" $ModuleName}}
{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
{{- if $.Features.olink }}
	{{$classFactory}}::RegisterFactory(TEXT("olink"), [](FSubsystemCollectionBase& Collection) -> TScriptInterface<I{{$class}}Interface>
		{
		return Cast<{{ printf "U%sOLinkClient" $class}}>(Collection.InitializeDependency({{ printf "U%sOLinkClient" $class}}::StaticClass()));
	});
{{- end }}
{{- end }}
}

void {{$class}}::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE({{$class}}, {{$ModuleName}}OLink)

#undef LOCTEXT_NAMESPACE
