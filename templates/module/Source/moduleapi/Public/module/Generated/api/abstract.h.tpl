{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name }}
#pragma once

#include "Runtime/Launch/Resources/Version.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "{{$ModuleName}}_data.h"
{{- $Class := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
#include "{{$ModuleName}}/Generated/api/{{$Class}}Interface.h"
{{- with .Interface }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName (Camel .Name) }}
{{- $class := printf "I%sInterface" $Class }}
{{- $Iface := printf "%s%s" $ModuleName (Camel .Name) }}
#include "Abstract{{$Class}}.generated.h"
{{ $abstractclass := printf "UAbstract%s" $Class }}
/**
 * Abstract {{$abstractclass}}
 */
UCLASS(Abstract, Blueprintable, NotBlueprintType)
class {{ $API_MACRO }} {{ $abstractclass}} : public UGameInstanceSubsystem, public {{ $class }}
{
	GENERATED_BODY()

public:
	// constructor
	{{ $abstractclass}}();
	// subsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

{{- nl }}
	// signals
	virtual U{{$Class}}Publisher* _GetPublisher() override;

	// methods
{{- range $i, $e := .Operations }}
{{- if .Return.IsVoid }}
	virtual {{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) override PURE_VIRTUAL({{ $abstractclass}}::{{Camel .Name}}, return;);
{{- else }}
	virtual void {{Camel .Name}}Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{if len .Params}}, {{end}}{{ueParams "" .Params}}) override;
	virtual TFuture<{{ueReturn "" .Return}}> {{Camel .Name}}Async({{ueParams "" .Params}}) override;
	virtual {{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) override PURE_VIRTUAL({{ $abstractclass}}::{{Camel .Name}}, return {{ueDefault "" .Return}};);
{{- end }}
{{ else }}
{{ end }}
	// properties
{{- range .Properties }}
	virtual {{ueReturn "" .}} Get{{Camel .Name}}() const override PURE_VIRTUAL({{ $abstractclass}}::Get{{Camel .Name}}, return {{ueDefault "" .}};);
{{- if not .IsReadOnly }}
	virtual void Set{{Camel .Name}}({{ueParam "In" .}}) override PURE_VIRTUAL({{ $abstractclass}}::Set{{Camel .Name}}, return;);
{{- end }}
{{- nl }}
{{- else }}{{- nl }}
{{- end }}
	virtual bool IsInitialized() const;
	static void AddReferencedObjects(UObject* InThis, FReferenceCollector& Collector);

protected:
	bool bInitialized = false;

	// properties - local copy
{{- range $i, $e := .Properties }}
{{- if $i }}{{nl}}{{ end }}
{{- if .Description }}
	/** {{.Description}} */
{{- end }}
	UPROPERTY(EditAnywhere, BlueprintGetter = Get{{Camel .Name}}_Private, {{ if not .IsReadOnly -}} BlueprintSetter = Set{{Camel .Name}}_Private, {{ end }}Category = "{{$Category}}")
	{{ueReturn "" .}} {{ueVar "" .}}{ {{- ueDefault "" . -}} };

	UFUNCTION(BlueprintGetter, Category = "{{$Category}}|Properties", BlueprintInternalUseOnly)
	{{ueReturn "" .}} Get{{Camel .Name}}_Private() const;
{{- if not .IsReadOnly }}{{nl}}
	UFUNCTION(BlueprintSetter, Category = "{{$Category}}|Properties", BlueprintInternalUseOnly)
	void Set{{Camel .Name}}_Private({{ueParam "In" .}});
{{- end }}
{{- end }}

private:
	// signals
#if (ENGINE_MAJOR_VERSION >= 5)
	TObjectPtr<U{{$Class}}Publisher> {{$Iface}}Publisher;
#else
	U{{$Class}}Publisher* {{$Iface}}Publisher;
#endif
};
{{- end }}
