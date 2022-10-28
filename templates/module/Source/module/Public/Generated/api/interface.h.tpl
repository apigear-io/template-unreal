{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name ) -}}
/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#pragma once

#include <cinttypes>
#include <string>
#include <list>
#include "UObject/Interface.h"
#include "Engine/LatentActionManager.h"

{{- $ModuleName := Camel .Module.Name}}
#include "{{$ModuleName}}_data.h"
{{- with .Interface }}
{{- $Class := printf "%s%s" $ModuleName (Camel .Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName (Camel .Name) }}
{{- $class := printf "U%sInterface" $Class }}
#include "{{$Class}}Interface.generated.h"

/**
 * Declaration for {{.Name}}
 */
// signal delegates
{{- range .Signals }}
DECLARE_DYNAMIC_MULTICAST_DELEGATE{{Int2Word (len .Params) "_" "Param"}}(F{{$Class}}{{Camel .Name}}Delegate{{range $idx, $elem := .Params}}, {{ueConstType "" .}}, {{ueVar "" .}}{{end}});
{{ end }}
// property delegates
{{- range .Properties }}
DECLARE_DYNAMIC_MULTICAST_DELEGATE{{Int2Word 1 "_" "Param"}}(F{{$Class}}{{Camel .Name}}ChangedDelegate, {{ueConstType "" .}}, {{ueVar "" .}});
{{ end }}
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
	// signals
{{- range $i, $e := .Signals }}
	{{- if $i }}{{nl}}{{ end }}
	UFUNCTION(Category = "{{$Category}}")
	virtual F{{$Class}}{{Camel .Name}}Delegate& Get{{Camel .Name}}SignalDelegate() = 0;
{{- end }}
{{- if len .Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Properties }}
	{{- if $i }}{{nl}}{{ end }}
	UFUNCTION(Category = "{{$Category}}")
	virtual F{{$Class}}{{Camel .Name}}ChangedDelegate& Get{{Camel .Name}}ChangedDelegate() = 0;
{{- end }}

	// methods
{{- range $i, $e := .Operations }}
{{- if .Return.IsVoid }}
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}")
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}});
	virtual {{ueReturn "" .Return}} {{Camel .Name}}_Implementation({{ueParams "" .Params}}) = 0;
{{- else }}
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}", meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	void {{Camel .Name}}Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{if len .Params}},{{end}} {{ueParams "" .Params}});
	virtual void {{Camel .Name}}Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{if len .Params}},{{end}} {{ueParams "" .Params}}) = 0;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}")
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}});
	virtual {{ueReturn "" .Return}} {{Camel .Name}}_Implementation({{ueParams "" .Params}}) = 0;
{{- end }}
{{ else }}
{{ end }}
	// properties
{{- range .Properties }}
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}")
	{{ueReturn "" .}} Get{{Camel .Name}}() const;
	virtual {{ueReturn "" .}} Get{{Camel .Name}}_Implementation() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}")
	void Set{{Camel .Name}}({{ueParam "" .}});
	virtual void Set{{Camel .Name}}_Implementation({{ueParam "" .}}) = 0;
{{- else }}
{{- end }}

protected:
	// signals
{{- range $i, $e := .Signals }}
	{{- if $i }}{{nl}}{{ end }}
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}")
	void Broadcast{{Camel .Name}}({{ueParams "" .Params}});
	virtual void Broadcast{{Camel .Name}}_Implementation({{ueParams "" .Params}}) = 0;
{{- end }}
{{- if len .Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Properties }}
	{{- if $i }}{{nl}}{{ end }}
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "{{$Category}}")
	void Broadcast{{Camel .Name}}Changed({{ueParam "" .}});
	virtual void Broadcast{{Camel .Name}}Changed_Implementation({{ueParam "" .}}) = 0;
{{- end }}
};
{{- end }}
