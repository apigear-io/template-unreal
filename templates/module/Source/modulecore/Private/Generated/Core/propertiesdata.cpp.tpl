{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%sCORE_API" (CAMEL .Module.Name) }}
#include "{{Camel .Module.Name}}/Generated/Core/{{Camel .Module.Name}}PropertiesData.h"

{{- range .Module.Interfaces }}
{{- $IfaceName := Camel .Name }}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
{{- range $i, $e := .Properties }}
{{- if not ( ueIsStdSimpleType . ) }}
{{- nl }}
void {{$Iface}}PropertiesData::Set{{ueVar "" .}}({{ueParam "In" .}})
{
	FWriteScopeLock WriteLock({{ueVar "" .}}Lock);
	{{ueVar "" .}} = {{ueVar "In" .}};
}

{{ueReturn "" .}} {{$Iface}}PropertiesData::Get{{ueVar "" .}}() const
{
	FReadScopeLock ReadLock({{ueVar "" .}}Lock);
	return {{ueVar "" .}};
}
{{- end }}
{{- end }}
{{- end }}
