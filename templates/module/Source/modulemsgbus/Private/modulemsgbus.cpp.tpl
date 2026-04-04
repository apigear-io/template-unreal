{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $Category := printf "ApiGear%s" $ModuleName }}

{{- $class := printf "F%sMsgBusModule" $ModuleName}}

#include "{{$ModuleName}}/{{$ModuleName}}MsgBus.h"
#include "{{$ModuleName}}/Generated/{{$ModuleName}}Factory.h"
#include "Engine/Engine.h"
#include "{{$ModuleName}}Settings.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "{{$ModuleName}}MsgBus"

void {{$class}}::StartupModule()
{
}

void {{$class}}::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE({{$class}}, {{$ModuleName}}MsgBus)

#undef LOCTEXT_NAMESPACE
