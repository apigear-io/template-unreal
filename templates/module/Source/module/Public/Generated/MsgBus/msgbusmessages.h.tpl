
{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sMsgBusClient" $DisplayName}}
{{- $abstractclass := printf "UAbstract%s%s" (Camel .Module.Name) (Camel .Interface.Name) }}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
#pragma once

{{- $includes := getEmptyStringList}}
{{- $includeName :=  printf "\"Generated/api/%s_data.h\"" $ModuleName }}
{{- $includes = (appendList $includes $includeName) }}
{{- range .Module.Externs }}
{{- $class := ueExtern . }}
{{- if $class.Include }}
{{- $includeName :=  printf "\"%s\"" $class.Include }}
{{- $includes = (appendList $includes $includeName) }}
{{- end }}
{{- end }}
{{- range .Module.Imports }}
{{- $includeName :=  printf "\"Generated/api/%s_data.h\"" (Camel .Name) }}
{{- $includes = (appendList $includes $includeName) }}
{{- end }}
{{- $includes = unique $includes }}
{{ range $includes }}
#include {{ .}}
{{- end }}
#include "{{$Iface}}MsgBusMessages.generated.h"

USTRUCT()
struct F{{$DisplayName}}DiscoveryMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct F{{$DisplayName}}InitMessage
{
	GENERATED_BODY()

	UPROPERTY()
	int32 _ClientPingIntervalMS = 1000;

{{- if len .Interface.Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Properties }}
{{- if $i }}{{nl}}{{ end }}
	UPROPERTY()
	{{ueType "" .}} {{ueVar "" .}} = {{ueDefault "" .}};
{{- end }}
};

USTRUCT()
struct F{{$DisplayName}}ClientDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct F{{$DisplayName}}ServiceDisconnectMessage
{
	GENERATED_BODY()
};

USTRUCT()
struct F{{$DisplayName}}PingMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

USTRUCT()
struct F{{$DisplayName}}PongMessage
{
	GENERATED_BODY()

	UPROPERTY()
	double Timestamp = 0.0;
};

{{- if len .Interface.Signals }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Signals }}
{{- if $i }}{{nl}}{{ end }}
USTRUCT()
struct F{{$DisplayName}}{{Camel .Name}}SignalMessage
{
	GENERATED_BODY()

{{- range $i, $e := .Params }}

	UPROPERTY()
	{{ueType "" .}} {{ueVar "" .}} = {{ueDefault "" .}};
{{- end }}
};

{{- end }}
{{- if len .Interface.Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Properties }}
{{- if $i }}{{nl}}{{ end }}
USTRUCT()
struct F{{$DisplayName}}Set{{Camel .Name}}RequestMessage
{
	GENERATED_BODY()

	UPROPERTY()
	{{ueType "" .}} {{ueVar "" .}} = {{ueDefault "" .}};
};

USTRUCT()
struct F{{$DisplayName}}{{Camel .Name}}ChangedMessage
{
	GENERATED_BODY()

	UPROPERTY()
	{{ueType "" .}} {{ueVar "" .}} = {{ueDefault "" .}};
};
{{- end }}

{{- if len .Interface.Operations }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Operations }}
{{- if $i }}{{nl}}{{ end }}
USTRUCT()
struct F{{$DisplayName}}{{Camel .Name}}RequestMessage
{
	GENERATED_BODY()

{{- if not .Return.IsVoid }}

	UPROPERTY()
	FGuid ResponseId;
{{- end }}

{{- range $i, $e := .Params }}

	UPROPERTY()
	{{ueType "" .}} {{ueVar "" .}} = {{ueDefault "" .}};
{{- end}}
};

{{- if not .Return.IsVoid }}

USTRUCT()
struct F{{$DisplayName}}{{Camel .Name}}ReplyMessage
{
	GENERATED_BODY()

{{- if not .Return.IsVoid }}

	UPROPERTY()
	FGuid ResponseId;
{{- end }}

	UPROPERTY()
	{{ueReturn "" .Return}} Result = {{ueDefault "" .Return}};
};
{{- end }}
{{- end }}
