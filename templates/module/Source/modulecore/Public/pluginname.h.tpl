{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%sCORE_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear%s" $ModuleName }}
{{- $class := printf "F%sCoreModule" $ModuleName}}
#pragma once

#include "Modules/ModuleManager.h"

class {{$class}} : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	/** Handle to the test dll we will load */
	void* {{$class}};
};
