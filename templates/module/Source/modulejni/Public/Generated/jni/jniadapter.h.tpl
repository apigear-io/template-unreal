
{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}

{{- $IfaceName := Camel .Interface.Name }}
{{- $API_MACRO := printf "%sJNI_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sJniAdapter" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
#pragma once

#include "{{$ModuleName}}/Generated/api/{{$Iface}}Interface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "{{$Iface}}JniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(Log{{$Iface}}_JNI, Log, All);

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface
 */
UCLASS(BlueprintType)
class {{ $API_MACRO }} {{$Class}} : public UGameInstanceSubsystem, public I{{$Iface}}SubscriberInterface
{
	GENERATED_BODY()
public:
	explicit {{$Class}}();
	virtual ~{{$Class}}() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{Camel .Module.Name}}|{{Camel .Interface.Name}}")
	void setBackendService(TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{Camel .Module.Name}}|{{Camel .Interface.Name}}")
	TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> getBackendService();

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Class object of the used java service.
	jclass m_javaJniServiceClass = nullptr;
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif

	{{- range $i, $e := .Interface.Signals }}
	{{- if $i }}{{nl}}{{ end }}
	void On{{Camel .Name}}Signal({{ueParams "" .Params}}) override;
	{{- end }}

{{- if len .Interface.Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Properties }}
	void On{{Camel .Name}}Changed({{ueParam "" .}}) override;
{{- end }}

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "{{$Category}}")
	TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> BackendService;
};
