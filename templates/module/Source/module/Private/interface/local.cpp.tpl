{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%sLocalService" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}

#include "{{$Iface}}Local.h"

{{- if .Interface.Description }}
/**
   \brief {{.Interface.Description}}
*/
{{- end }}
{{$Class}}::{{$Class}}()
	: I{{$Iface}}Interface()
{{- range .Interface.Properties }}
	, {{ueVar "" .}}({{ueDefault "" .}})
{{- end }}
{
}
{{$Class}}::~{{$Class}}()
{
}
{{ range .Interface.Signals }}
F{{$Iface}}{{Camel .Name}}Delegate& {{$Class}}::Get{{Camel .Name}}SignalDelegate()
{
	return {{Camel .Name}}Signal;
}
{{ end }}
{{- range .Interface.Properties }}
{{ueReturn "" .}} {{$Class}}::Get{{Camel .Name}}_Implementation() const
{
	return {{ueVar "" .}};
}

void {{$Class}}::Set{{Camel .Name}}_Implementation({{ueParam "In" .}})
{
	if ({{ueVar "" .}} != {{ueVar "In" .}})
	{
		{{ueVar "" .}} = {{ueVar "In" .}};
		{{Camel .Name}}Changed.Broadcast({{ueVar "" .}});
	}
}

F{{$Iface}}{{Camel .Name}}ChangedDelegate& {{$Class}}::Get{{Camel .Name}}ChangedDelegate()
{
	return {{Camel .Name}}Changed;
}
{{- end }}
{{ range .Interface.Operations }}
{{- if .Description }}
/**
   \brief {{.Description}}
*/
{{- end }}
{{ueReturn "" .Return}} {{$Class}}::{{Camel .Name}}_Implementation({{ueParams "" .Params}})
{
	{{- range .Params }}
	(void){{ueVar "" .}};
	{{- end }}
	// do business logic here
	{{- if not .Return.IsVoid }}
	return {{ueDefault "" .Return}};
	{{- end }}
}
{{- end }}
