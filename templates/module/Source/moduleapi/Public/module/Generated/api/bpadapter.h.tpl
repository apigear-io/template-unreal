{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name }}
#pragma once

#include "Runtime/Launch/Resources/Version.h"
#include "{{$ModuleName}}_data.h"
{{- $Class := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
#include "{{$ModuleName}}/Generated/api/{{$Class}}Interface.h"
#include "{{$ModuleName}}/Generated/api/{{$Class}}BPInterface.h"
{{- with .Interface }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName (Camel .Name) }}
{{- $cppinterface := printf "I%sInterface" $Class }}
{{- $bpinterface := printf "I%sBPInterface" $Class }}
{{- $Iface := printf "%s%s" $ModuleName (Camel .Name) }}
#include "{{$Class}}BPAdapter.generated.h"
{{ $adapter := printf "U%sBPAdapter" $Class }}
/**
 * Adapter {{$adapter}} from BP to C++ interface
 */
UCLASS(Blueprintable, BlueprintType)
class {{ $API_MACRO }} {{ $adapter}} : public UObject, public {{ $cppinterface }}
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "{{$Category}}")
	TScriptInterface<{{ $bpinterface }}> Target;

	UFUNCTION(BlueprintCallable, Category = "{{$Category}}")
	void Initialize(TScriptInterface<{{ $bpinterface }}> InTarget);

{{- nl }}
	// signals
	U{{$Class}}Publisher* _GetPublisher() override;

	// methods
{{- range $i, $e := .Operations }}
{{- if .Return.IsVoid }}
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) override;
{{- else }}
	void {{Camel .Name}}Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{if len .Params}}, {{end}}{{ueParams "" .Params}}) override;
	TFuture<{{ueReturn "" .Return}}> {{Camel .Name}}Async({{ueParams "" .Params}}) override;
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) override;
{{- end }}
{{ else }}
{{ end }}
	// properties
{{- range $i, $e := .Properties }}
{{- if $i }}{{nl}}{{ end }}
	{{ueReturn "" .}} Get{{Camel .Name}}() const override;
{{- if not .IsReadOnly }}
	void Set{{Camel .Name}}({{ueParam "In" .}}) override;
{{- end }}
{{- end }}
};
{{- end }}
