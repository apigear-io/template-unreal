{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name }}
#pragma once

#include "Logging/LogMacros.h"

/// list of module specific but otherwise generic log categories
/// should be used instead of LogTemp or otherwise too specific categories

{{$API_MACRO}} DECLARE_LOG_CATEGORY_EXTERN(Log{{$ModuleName}}, Log, All);
