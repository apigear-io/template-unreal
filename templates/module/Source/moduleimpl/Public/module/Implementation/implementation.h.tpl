{{ template "copyright" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $API_MACRO := printf "%sIMPLEMENTATION_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sImplementation" $DisplayName}}
{{- $abstractclass := printf "UAbstract%s%s" (Camel .Module.Name) (Camel .Interface.Name) }}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
#pragma once

#include "CoreMinimal.h"
#include "{{$ModuleName}}/Generated/api/Abstract{{$Iface}}.h"
#include "{{$Iface}}.generated.h"

UCLASS(BlueprintType)
class {{ $API_MACRO }} {{$Class}} : public {{$abstractclass}}
{
	GENERATED_BODY()
public:
	virtual ~{{$Class}}();

	// properties
{{- range .Interface.Properties }}
	{{ueReturn "" .}} Get{{Camel .Name}}() const override;
{{- if not .IsReadOnly }}
	void Set{{Camel .Name}}({{ueParam "" .}}) override;
{{- end}}
{{ end }}
{{- if len .Interface.Properties }}
	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "{{$Category}}|Properties")
	void _ResetProperties();
{{ end }}
	// operations
{{- range $i, $e := .Interface.Operations }}
{{- if ne $i 0 }}{{nl}}{{ end }}
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) override;
{{- end }}
};
