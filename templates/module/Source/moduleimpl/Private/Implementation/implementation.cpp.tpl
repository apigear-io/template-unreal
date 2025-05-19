{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%sImplementation" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}

#include "{{$ModuleName}}/Implementation/{{$Iface}}.h"

{{$Class}}::~{{$Class}}() = default;

{{- range .Interface.Properties }}
{{ueReturn "" .}} {{$Class}}::Get{{Camel .Name}}() const
{
	return {{ueVar "" .}};
}

{{- if not .IsReadOnly }}{{nl}}
void {{$Class}}::Set{{Camel .Name}}({{ueParam "In" .}})
{
	if ({{ueVar "" .}} != {{ueVar "In" .}})
	{
		{{ueVar "" .}} = {{ueVar "In" .}};
		_GetSignals()->Broadcast{{Camel .Name}}Changed({{ueVar "" .}});
	}
}
{{- end }}
{{- else }}
{{- end }}
{{- range .Interface.Operations }}{{ nl }}
{{- if .Description }}
/**
   \brief {{.Description}}
*/
{{- end }}
{{ueReturn "" .Return}} {{$Class}}::{{Camel .Name}}({{ueParams "" .Params}})
{
	{{- range .Params }}
	(void){{ueVar "" .}};
	{{- end }}
	// do business logic here
	{{- if not .Return.IsVoid }}
	return {{ueDefault "" .Return}};
	{{- end }}
}
{{- else }}
{{- end }}

{{- if len .Interface.Properties }}

void {{$Class}}::_ResetProperties()
{
	{{- range .Interface.Properties }}
	if ({{ueVar "" .}} != {{ueDefault "" .}})
	{
		{{ueVar "" .}} = {{ueDefault "" .}};
		_GetSignals()->Broadcast{{Camel .Name}}Changed({{ueVar "" .}});
	}
	{{- end }}
}
{{- end }}
