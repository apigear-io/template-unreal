{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $Category := printf "ApiGear%s" $ModuleName }}
{{- $class := printf "F%sJniModule" $ModuleName}}
#pragma once

#include "Modules/ModuleManager.h"

class {{$class}} : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
