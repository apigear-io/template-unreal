{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%s_API" (Camel .Module.Name) }}
{{- $Category := printf "ApiGear%s" $ModuleName }}

{{- $class := printf "F%sCoreModule" $ModuleName}}

#include "{{$ModuleName}}Core.h"
#include "{{$ModuleName}}/Generated/{{$ModuleName}}Factory.h"
#include "Engine/Engine.h"
#include "{{$ModuleName}}Settings.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "{{$ModuleName}}Core"

void {{$class}}::StartupModule()
{
}

void {{$class}}::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE({{$class}}, {{$ModuleName}}Core)

#undef LOCTEXT_NAMESPACE
