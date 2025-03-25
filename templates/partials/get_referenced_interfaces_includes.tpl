{{- define "get_referenced_interfaces_includes" }}
{{- $module := .Module }}

{{- $includes := getEmptyStringList}}
{{- with .Interface }}
{{- range .Properties }}
    {{- if eq .KindType "interface"}}
        {{- $moduleName :=  "" }}
        {{- if ne .Import "" }}
            {{- $moduleName = Camel .Import }}
        {{- else }}
            {{- $moduleName = Camel $module.Name }}
        {{- end }}
        {{- $includeName :=  printf "\"%s/Generated/api/%s%sInterface.h\"" $moduleName $moduleName .Type }}
        {{- $includes = (appendList $includes $includeName) }}
    {{- end }}
{{- end }}

{{- range $i, $e := .Operations }}
    {{- if eq .Return.KindType "interface"}}
        {{- $moduleName :=  "" }}
        {{- if ne .Return.Import "" }}
            {{- $moduleName = Camel .Return.Import }}
        {{- else }}
            {{- $moduleName = Camel $module.Name }}
        {{- end }}
        {{- $includeName :=  printf "\"%s/Generated/api/%s%sInterface.h\"" $moduleName $moduleName .Return.Type }}
        {{- $includes = (appendList $includes $includeName) }}
    {{- end }}
    {{- range .Params }}
        {{- if eq .KindType "interface"}}
            {{- $moduleName :=  "" }}
            {{- if ne .Import "" }}
                {{- $moduleName = Camel .Import }}
            {{- else }}
                {{- $moduleName = Camel $module.Name }}
            {{- end }}
            {{- $includeName :=  printf "\"%s/Generated/api/%s%sInterface.h\"" $moduleName $moduleName .Type }}
            {{- $includes = (appendList $includes $includeName) }}
        {{- end }}
    {{- end }}
{{- end }}

{{- range $i, $e := .Signals }}
    {{- range .Params }}
        {{- if eq .KindType "interface"}}
            {{- $moduleName :=  "" }}
            {{- if ne .Import "" }}
                {{- $moduleName = Camel .Import }}
            {{- else }}
                {{- $moduleName = Camel $module.Name }}
            {{- end }}
            {{- $includeName :=  printf "\"%s/Generated/api/%s%sInterface.h\"" $moduleName $moduleName .Type }}
            {{- $includes = (appendList $includes $includeName) }}
        {{- end }}
    {{- end }}
{{- end }}

{{- end }}
{{- $includes = unique $includes }}
{{- range $includes }}
#include {{ .}}
{{- end }}
{{- end }}