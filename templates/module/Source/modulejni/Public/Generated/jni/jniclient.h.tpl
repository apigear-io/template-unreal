
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
#include "{{$ModuleName}}/Generated/Jni/{{$ModuleName}}JniConnectionStatus.h"
#include <memory>
#include "Misc/Guid.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "{{$Iface}}JniClient.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(Log{{$Iface}}Client_JNI, Log, All);

// A helper class that exposes part of {{$Class}} to use for native JNI calls.
// The usage of it should allow thread safe access to set properties and broadcasting singals,
// since all JNI native calls are made from JNI thread.
// The difference from already provided subscirber interface is that it does not expose the functions to blueprints use.
class {{$API_MACRO}} I{{$Class}}JniAccessor
{
public:
{{- range $i, $e := .Interface.Signals }}
	{{- if $i }}{{nl}}{{ end }}
	virtual void On{{Camel .Name}}Signal({{ueParams "" .Params}}) = 0;
{{- end }}
{{- if and (len .Interface.Properties) (len .Interface.Signals) }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Properties }}
	{{- if $i }}{{nl}}{{ end }}
	virtual void On{{Camel .Name}}Changed({{ueParam "" .}}) = 0;
{{- end }}
	virtual void notifyIsReady(bool isReady) = 0;
};

UCLASS(NotBlueprintable, BlueprintType)
class {{ $API_MACRO }} {{$Class}} : public UAbstract{{Camel .Module.Name}}{{Camel .Interface.Name }}, public I{{$Class}}JniAccessor
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

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|{{Camel .Module.Name}}|{{$IfaceName}}|Jni|Remote", DisplayName = "Connection Status Changed")
	F{{$ModuleName}}JniConnectionStatusChangedDelegateBP _ConnectionStatusChangedBP;
	F{{$ModuleName}}JniConnectionStatusChangedDelegate _ConnectionStatusChanged;

	/** @brief Informs about the subscription state of the interface client.
	 * @return true if the client is connected to a service and ready to send and receive messages
		or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{Camel .Module.Name}}|{{$IfaceName}}|JNI")
	bool _IsReady() const;

	/** @param package. This client will connect only to a {{$IfaceName}} Service,
		that may be exposed by the application that runs it.
	* To make successful binding the package of that application must be passed here.
	* @return true if successfully bound, false it binding failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{Camel .Module.Name}}|{{$IfaceName}}|JNI|Connection")
	bool _bindToService(FString servicePackage, FString connectionId);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{Camel .Module.Name}}|{{$IfaceName}}|JNI|Connection")
	void _unbind();

private:
{{- range $i, $e := .Interface.Signals }}
	{{- if $i }}{{nl}}{{ end }}
	void On{{Camel .Name}}Signal({{ueParams "In" .Params}}) override;
{{- end }}
{{- if and (len .Interface.Properties) (len .Interface.Signals) }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Properties }}
	{{- if $i }}{{nl}}{{ end }}
	void On{{Camel .Name}}Changed({{ueParam "In" .}}) override;
{{- end }}
{{- if or (len .Interface.Properties) (len .Interface.Signals) }}{{ nl }}{{ end }}
#if PLATFORM_ANDROID && USE_ANDROID_JNI
{{- range $i, $e := .Interface.Operations }}
{{- if $i }}{{nl}}{{ end }}
	bool tryCallAsyncJava{{Camel .Name}}(FGuid Guid, jmethodID MethodId{{- if len (.Params) }}, {{end}}{{ueParams "In" .Params}});
{{- end }}
#endif
	void notifyIsReady(bool isReady) override;

	std::atomic<bool> b_isReady{false};
	FString m_lastBoundServicePackage;
	FString m_lastConnectionId;
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	jobject m_javaJniClientInstance = nullptr;
#endif
};
