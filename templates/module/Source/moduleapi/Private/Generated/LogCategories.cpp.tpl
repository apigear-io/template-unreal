{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name }}
#include "{{$ModuleName}}/Generated/{{$ModuleName}}LogCategories.h"

DEFINE_LOG_CATEGORY(Log{{$ModuleName}});
