{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name ) }}
{{- $hasVoidFunctions := false }}
{{- range $i, $e := .Interface.Operations }}
{{- if .Return.IsVoid }}{{- $hasVoidFunctions = true }}{{- end }}
{{- end }}
#pragma once

#include "UObject/Interface.h"
{{- $ModuleName := Camel .Module.Name}}
#include "{{$ModuleName}}/Generated/api/{{$ModuleName}}_data.h"
{{- with .Interface }}
{{- $Class := printf "%s%s" $ModuleName (Camel .Name) }}
{{- $Category := printf "ApiGear Helper|%s|%s" $ModuleName (Camel .Name) }}
{{- $class := printf "U%sInterface" $Class }}
{{- $Iface := printf "%s%s" $ModuleName (Camel .Name) }}
{{- range .Module.Imports }}
#include "{{Camel .Name}}/Generated/api/{{Camel .Name}}_data.h"
{{- end }}
#include "{{$Class}}BPHelperInterface.generated.h"

{{- if or (len .Properties) (len .Signals) (len .Operations) }}
{{- nl }}
/**
 * Helper interface for {{$Class}} events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events, property-changed events and void-function events only.
 */
UINTERFACE(BlueprintType)
class U{{$Class}}BPHelperInterface : public UInterface
{
	GENERATED_BODY()
};

class {{$API_MACRO}} I{{$Class}}BPHelperInterface
{
	GENERATED_BODY()

public:
{{- range $i, $e := .Signals }}
	{{- if $i }}{{nl}}{{ end }}
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "{{$Category}}|Signals", DisplayName = "On {{Camel .Name}} Signal")
	void On{{Camel .Name}}Signal({{ueParams "" .Params}});
{{- end }}
{{- if and (len .Properties) (len .Signals) }}{{ nl }}{{ end }}
{{- range $i, $e := .Properties }}
	{{- if $i }}{{nl}}{{ end }}
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "{{$Category}}|Signals", DisplayName = "On Property {{Camel .Name}} Changed")
	void On{{Camel .Name}}Changed(UPARAM(DisplayName = "{{ueVar "" .}}") {{ueParam "In" .}});
{{- end }}
{{- if or (and (len .Properties) $hasVoidFunctions) (and (len .Signals) $hasVoidFunctions) }}{{ nl }}{{ end }}
{{- range $i, $e := .Operations }}
{{- if .Return.IsVoid }}
	{{- if $i }}{{nl}}{{ end }}
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "{{$Category}}|Signals", DisplayName = "Do {{Camel .Name}}")
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}});
{{- end }}
{{- end }}
};
{{- end }}
{{- end }}
