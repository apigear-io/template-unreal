{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name }}
{{- $class := printf "F%sAPIModule" $ModuleName}}
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
