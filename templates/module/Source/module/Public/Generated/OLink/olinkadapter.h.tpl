
{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sOLinkAdapter" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
#pragma once

#include "Generated/api/{{$Iface}}Interface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>
#include "{{$Iface}}OLinkAdapter.generated.h"

class UOLinkHost;
namespace ApiGear
{
namespace ObjectLink
{
class RemoteRegistry;
}
} // namespace ApiGear

/** @brief handles the adaption between the service implementation and the OLink protocol
 * takes an object of the type I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface
 * and holds the corresponding {{$Iface}}OLinkSource OLink source object
 */
UCLASS(BlueprintType)
class {{ $API_MACRO }} {{$Class}} : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit {{$Class}}();
	virtual ~{{$Class}}() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "{{$Category}}")
	void setBackendService(TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> InService);

	UFUNCTION(BlueprintCallable, Category = "{{$Category}}")
	void setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost);

private:
	// signals
{{- range $i, $e := .Interface.Signals }}
{{- if $i }}{{nl}}{{ end }}
	UFUNCTION(Category = "{{$Category}}", BlueprintInternalUseOnly)
	void On{{Camel .Name}}({{ueParams "" .Params}});
{{- end }}
{{- if len .Interface.Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Properties }}
{{- if $i }}{{nl}}{{ end }}
	UFUNCTION(Category = "{{$Category}}", BlueprintInternalUseOnly)
	void On{{Camel .Name}}Changed({{ueParam "" .}});
{{- end }}

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "{{$Category}}")
	TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> BackendService;

	/** Holds the registry */
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> Registry;

	/**
	holds the olink source interface implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class {{$Iface}}OLinkSource> Source;
};
