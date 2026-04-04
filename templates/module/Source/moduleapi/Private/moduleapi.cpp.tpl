{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name }}

{{- $class := printf "F%sAPIModule" $ModuleName}}

#include "{{$ModuleName}}/Generated/{{$ModuleName}}API.h"
#include "Engine/Engine.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "{{$ModuleName}}API"

void {{$class}}::StartupModule()
{
}

void {{$class}}::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE({{$class}}, {{$ModuleName}}API)

#undef LOCTEXT_NAMESPACE
