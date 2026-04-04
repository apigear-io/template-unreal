{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $Category := printf "ApiGear%s" $ModuleName }}

{{- $class := printf "F%sImplementationModule" $ModuleName}}

#include "{{$ModuleName}}/{{$ModuleName}}Implementation.h"
#include "{{$ModuleName}}/Generated/{{$ModuleName}}Factory.h"
{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
{{- if $.Features.stubs }}
#include "{{$ModuleName}}/Implementation/{{$class}}.h"
{{- end }}
{{- end }}
#include "Engine/Engine.h"
#include "{{$ModuleName}}Settings.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "{{$ModuleName}}Implementation"

void {{$class}}::StartupModule()
{
{{- $classFactory := printf "F%sModuleFactory" $ModuleName}}
{{- range .Module.Interfaces }}
{{- $class := printf "%s%s" $ModuleName (Camel .Name)}}
{{- if $.Features.stubs }}
	{{$classFactory}}::RegisterFactory({{$ModuleName}}LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<I{{$class}}Interface>
		{
		return Cast<U{{$class}}Implementation>(Collection.InitializeDependency(U{{$class}}Implementation::StaticClass()));
	});
{{- end }}
{{- end }}
}

void {{$class}}::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE({{$class}}, {{$ModuleName}}Implementation)

#undef LOCTEXT_NAMESPACE
