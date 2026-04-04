{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name }}
#pragma once

{{- with .Interface }}
{{- $CppClass := printf "%s%s" $ModuleName (Camel .Name) }}
{{- $Class := printf "%s%sBP" $ModuleName (Camel .Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName (Camel .Name) }}
{{- $class := printf "U%sInterface" $Class }}
{{- $Iface := printf "%s%s" $ModuleName (Camel .Name) }}
#include "{{$CppClass}}Interface.h"
#include "Engine/LatentActionManager.h"
#include "UObject/Interface.h"
#include "{{$ModuleName}}_data.h"
{{- range .Module.Imports }}
#include "{{Camel .Name}}/Generated/api/{{Camel .Name}}_data.h"
{{- end }}
#include "{{$Class}}Interface.generated.h"

/**
 * Interface {{$class}} only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class {{$class}} : public UInterface
{
	GENERATED_BODY()
};
{{ $class := printf "I%sInterface" $Class }}
/**
 * Interface {{$class}}
 */
class {{ $API_MACRO }} {{ $class}}
{
	GENERATED_BODY()

public:
	/// Provides access to the object which holds all the delegates
	/// this is needed since we cannot declare delegates on an UInterface
	/// @return object with signals for property state changes or standalone signals
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}")
	U{{$CppClass}}Publisher* _GetPublisher();
	virtual U{{$CppClass}}Publisher* _GetPublisher_Implementation() = 0;

	// methods
{{- range $i, $e := .Operations }}
{{- if .Return.IsVoid }}
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}|Operations")
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}});
	virtual {{ueReturn "" .Return}} {{Camel .Name}}_Implementation({{ueParams "" .Params}}) = 0;
{{- else }}
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}|Operations")
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}});
	virtual {{ueReturn "" .Return}} {{Camel .Name}}_Implementation({{ueParams "" .Params}}) = 0;
{{- end }}
{{ else }}
{{ end }}
	// properties
{{- range .Properties }}
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}|Properties")
	{{ueReturn "" .}} Get{{Camel .Name}}() const;
	virtual {{ueReturn "" .}} Get{{Camel .Name}}_Implementation() const = 0;
{{- if not .IsReadOnly }}
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}|Properties")
	void Set{{Camel .Name}}({{ueParam "In" .}});
	virtual void Set{{Camel .Name}}_Implementation(UPARAM(DisplayName = "{{ueVar "" .}}") {{ueParam "In" .}}) = 0;
{{- end }}
{{- end }}
};
{{- end }}
