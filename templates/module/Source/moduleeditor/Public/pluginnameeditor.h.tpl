{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear%s" $ModuleName }}
{{- $Class := printf "F%sEditorModule" $ModuleName }}
#pragma once

#include "Modules/ModuleManager.h"

class {{$Class}} : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	/** Handle to the test dll we will load */
	void* {{$Class}};
};
