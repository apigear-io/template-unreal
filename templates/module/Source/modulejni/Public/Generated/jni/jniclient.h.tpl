
{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}

{{- $IfaceName := Camel .Interface.Name }}
{{- $API_MACRO := printf "%sJNI_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sJniClient" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
#pragma once

#include "{{$ModuleName}}/Generated/api/{{$Iface}}Interface.h"
#include "{{ $ModuleName }}/Generated/api/Abstract{{$Iface}}.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>

#include "{{$Iface}}JniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(Log{{$Iface}}Client_JNI, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class {{ $API_MACRO }} {{$Class}} : public UAbstract{{Camel .Module.Name}}{{Camel .Interface.Name }}
{
	GENERATED_BODY()
public:
	explicit {{$Class}}();

	{{$Class}}(FVTableHelper& Helper);
	virtual ~{{$Class}}();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	{{- range .Interface.Properties }}
	{{ueReturn "" .}} Get{{Camel .Name}}() const override;
	{{- if not .IsReadOnly }}
	void Set{{Camel .Name}}({{ueParam "In" .}}) override;
	{{- end }}
	{{- end}}

	// operations
{{- range $i, $e := .Interface.Operations }}
	virtual {{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) override;
{{- end }}

};
