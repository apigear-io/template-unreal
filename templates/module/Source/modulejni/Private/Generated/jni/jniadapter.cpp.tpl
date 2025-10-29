{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $ModuleNameRaw :=  .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sJniAdapter" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
{{- $jniservice_name:= printf "%sjniservice" ( camel $ModuleNameRaw) }}
{{- $javaClassPath := ( join "/" (strSlice ( camel $ModuleNameRaw) $jniservice_name) ) }}
{{- $javaClassName :=  printf "%sJniService" $IfaceName }}
{{- $jniFullFuncPrefix := ( join "_" (strSlice "Java" ( camel $ModuleNameRaw) $jniservice_name $javaClassName ) ) }}
{{- $api_module_name:= printf "%s_api" ( camel $ModuleNameRaw) }}
{{- $javaIfClassName :=  printf "I%s" $IfaceName }}
{{- $javaIfClassFull :=  ( join "/" (strSlice (camel $ModuleNameRaw) $api_module_name $javaIfClassName ) ) }}


{{- define "convert_to_java_type"}}
        {{- $localName := printf "jlocal_%s" (Camel .Name) }}
        {{- $cppropName := ueVar "" .}}
        {{- $javaClassConverter := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
        {{- if (eq $javaClassConverter  "DataJavaConverter" )}}{{- $javaClassConverter = printf "%sDataJavaConverter" (Camel .Schema.Module.Name) }}{{ end }}
    {{- if .IsArray }}
        {{- if (eq .KindType "string")}}
        TArray<FStringView> {{$cppropName}}StringViews;
        {{$cppropName}}StringViews.Reserve({{$cppropName}}.Num());
        for (const FString& Str : {{$cppropName}})
        {
            {{$cppropName}}StringViews.Add(FStringView(Str));
        }
        auto {{$localName}}Wrapped = FJavaHelper::ToJavaStringArray(Env,{{$cppropName}}StringViews);
        jobjectArray {{$localName}} = static_cast<jobjectArray>(Env->NewLocalRef(*{{$localName}}Wrapped));
        {{- else if (eq .KindType "bool")}}
        auto len{{snake .Name}} = {{$cppropName}}.Num();
        {{jniToReturnType .}} {{$localName}} = Env->New{{jniToEnvNameType .}}Array(len{{snake .Name}});
        TArray<jboolean> Temp{{$localName}};
        Temp{{$localName}}.SetNumUninitialized(len{{snake .Name}});
        for (int i = 0; i < len{{snake .Name}}; i++)
        {
            Temp{{$localName}}[i] = {{$cppropName}}[i] ? JNI_TRUE : JNI_FALSE;
        }
        Env->SetBooleanArrayRegion({{$localName}}, 0, len{{snake .Name}}, Temp{{$localName}}.GetData());
        {{- else if and (.IsPrimitive ) (not (eq .KindType "enum")) }}
        auto len{{snake .Name}} = {{$cppropName}}.Num();
        {{jniToReturnType .}} {{$localName}} = Env->New{{jniToEnvNameType .}}Array(len{{snake .Name}});
        if ({{$localName}}  == NULL){/*Log error, skip?*/};
        Env->Set{{jniToEnvNameType .}}ArrayRegion({{$localName}}, 0, len{{snake .Name}}, {{- if (eq .KindType "int64") -}}
        reinterpret_cast<const jlong*>({{$cppropName}}.GetData()));
        {{- else -}}
        {{$cppropName}}.GetData());
        {{- end }}
        {{- else }}
        {{- if eq .KindType "interface" }}
        // interfaces are currently not supported. {{$javaClassConverter}} returns an array with no elements. 
        {{- end }}
        {{jniToReturnType .}} {{$localName}} = {{$javaClassConverter}}::makeJava{{Camel .Type }}Array(Env, {{$cppropName}});
        {{- end }}
    {{- else if (eq .KindType "string")}}
        auto {{$localName}}Wrapped = FJavaHelper::ToJavaString(Env, {{$cppropName}});
        jstring {{$localName}} = static_cast<jstring>(Env->NewLocalRef(*{{$localName}}Wrapped));
    {{- else if ( or (not .IsPrimitive ) (eq .KindType "enum" ) ) }}
        {{- if eq .KindType "interface" }}
        // interfaces are currently not supported. {{$javaClassConverter}} returns nullptr. 
        {{- end }}
        {{jniToReturnType .}} {{$localName}} = {{$javaClassConverter}}::makeJava{{Camel .Type }}(Env, {{$cppropName}});
    {{- end }}
{{- end}}

{{- define "convert_to_local_cpp_value_java_param"}}
{{- $javaPropName := .Name}}
{{- $javaClassConverter := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
{{- $local_value :=  printf "local_%s" (snake .Name) }}
{{- if (eq $javaClassConverter  "DataJavaConverter" )}}{{- $javaClassConverter = printf "%sDataJavaConverter" (Camel .Schema.Module.Name)}}{{ end }}
{{- if .IsArray }}
    {{ueReturn "" .}} {{$local_value}} = {{ ueDefault "" . }};
    {{- if (eq .KindType "string")}}
    {{$local_value}} = FJavaHelper::ObjectArrayToFStringTArray(Env, {{$javaPropName}});
    {{- else if (eq .KindType "bool")}}
    jbooleanArray l_java{{Camel .Name}}Array = (jbooleanArray){{$javaPropName}};
    jsize len{{snake .Name}} = Env->GetArrayLength(l_java{{Camel .Name}}Array);
    {{$local_value}}.Reserve(len{{snake .Name}});
    TArray<jboolean> Temp{{Camel .Name}};
    Temp{{Camel .Name}}.SetNumUninitialized(len{{snake .Name}});
    Env->GetBooleanArrayRegion(l_java{{Camel .Name}}Array, 0, len{{snake .Name}}, Temp{{Camel .Name}}.GetData());
    for (int i = 0; i < len{{snake .Name}}; i++)
    {
        {{$local_value}}.Add(Temp{{Camel .Name}}[i] == JNI_TRUE);
    }
    Env->DeleteLocalRef(l_java{{Camel .Name}}Array);
    {{- else if .IsPrimitive }}
    {{ jniToReturnType . }} l_java{{Camel .Name}}Array = ({{ jniToReturnType . }}){{$javaPropName}};
    jsize len{{snake .Name}} = Env->GetArrayLength(l_java{{Camel .Name}}Array);
    {{$local_value}}.AddUninitialized(len{{snake .Name}});
    Env->Get{{jniToEnvNameType .}}ArrayRegion({{$javaPropName}}, 0,  len{{snake .Name}}, {{- if (eq .KindType "int64") -}}
        reinterpret_cast<jlong*>({{$local_value}}.GetData()));
        {{- else -}}
        {{$local_value}}.GetData());
        {{- end }}
    Env->DeleteLocalRef(l_java{{Camel .Name}}Array);
    {{- else}}
    {{- if eq .KindType "interface" }}
    // interfaces are currently not supported. {{$javaClassConverter}} does not fill the array. 
    {{- end }}
    {{$javaClassConverter}}::fill{{Camel .Type }}Array(Env, {{$javaPropName}}, {{$local_value}});
    {{- end }}
{{- else if eq .KindType "enum" }}
    {{ueReturn "" .}} {{$local_value}} = {{$javaClassConverter}}::get{{Camel .Type }}Value(Env, {{$javaPropName}});
{{- else if (eq .KindType "string")}}
    FString {{$local_value}} = FJavaHelper::FStringFromParam(Env, {{$javaPropName}});
{{- else if not (ueIsStdSimpleType . )}}
    {{- if eq .KindType "interface" }}
    // interfaces are currently not supported. {{$javaClassConverter}} does not fill element. 
    {{- end }}
    {{ueReturn "" .}} {{$local_value}} = {{ ueDefault "" . }};
    {{$javaClassConverter}}::fill{{Camel .Type }}(Env, {{$javaPropName}}, {{$local_value}});
{{- end }}
{{- end }}

////////////////////////////////
// WARNING AUTOGENERATED
// DO NOT MODIFY
///////////////////////////////

#include "{{$ModuleName}}/Generated/Jni/{{$Iface}}JniAdapter.h"
#include "{{$ModuleName}}/Generated/Jni/{{$ModuleName}}DataJavaConverter.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
#include "HAL/Platform.h"

{{- $includes := getEmptyStringList}}
{{- range .Module.Externs }}
{{- $class := ueExtern . }}
{{- if $class.Include }}
{{- $includeName :=  printf "\"%s\"" $class.Include }}
{{- $includes = (appendList $includes $includeName) }}
{{- end }}
{{- end }}
{{- range .Module.Imports }}
{{- $importModuleName := Camel .Name }}
{{- $includeName :=  printf "\"%s/Generated/api/%s_data.h\"" $importModuleName $importModuleName }}
{{- $includeName :=  printf "\"%s/Generated/Jni/%sDataJavaConverter.h\"" $importModuleName $importModuleName }}
{{- $includes = (appendList $includes $includeName) }}
{{- end }}
{{- $includes = unique $includes }}
{{ range $includes }}
#include {{ .}}
{{- end }}
{{- if or (len .Module.Enums) (len .Module.Structs) -}}
#include "{{$ModuleName}}/Generated/api/{{ $ModuleName }}_data.h"
{{ end }}

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

DEFINE_LOG_CATEGORY(Log{{$Iface}}_JNI);


namespace 
{
	{{$Class}}* g{{$Class}}Handle = nullptr;
}


{{- if .Interface.Description }}
/**
   \brief {{.Interface.Description}}
*/
{{- end }}
{{$Class}}::{{$Class}}()
{
}

void {{$Class}}::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	g{{$Class}}Handle = this;
#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
    m_javaJniServiceClass =  FAndroidApplication::FindJavaClassGlobalRef("{{$javaClassPath}}/{{$javaClassName}}");
    auto Env = FAndroidApplication::GetJavaEnv();
    jclass BridgeClass = FAndroidApplication::FindJavaClassGlobalRef("{{$javaClassPath}}/{{$javaClassName}}Starter");
    if (BridgeClass == nullptr)
    {
		UE_LOG(LogTemp, Warning, TEXT("{{Camel .Module.Name}}JavaServiceStarter:start; CLASS not found"));
        return;
    }
	auto functionSignature = "(Landroid/content/Context;)L{{$javaIfClassFull}};";
	jmethodID StartMethod = Env->GetStaticMethodID(BridgeClass, "start", functionSignature);
    if (StartMethod == nullptr)
    {
		UE_LOG(LogTemp, Warning, TEXT( "{{Camel .Module.Name}}JavaServiceStarter:start; method not found"));
		return;
    }
    jobject Activity = FJavaWrapper::GameActivityThis;
	jobject localRef = FJavaWrapper::CallStaticObjectMethod(Env, BridgeClass, StartMethod, Activity);

    m_javaJniServiceInstance = Env->NewGlobalRef(localRef);
    Env->DeleteLocalRef(localRef);
#endif
#endif
}

void {{$Class}}::Deinitialize()
{
	callJniServiceReady(false);
	g{{$Class}}Handle = nullptr;
#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
    m_javaJniServiceClass = nullptr;
    if (m_javaJniServiceInstance)
    {
        FAndroidApplication::GetJavaEnv()->DeleteGlobalRef(m_javaJniServiceInstance);
        m_javaJniServiceInstance = nullptr;
    }
    JNIEnv* Env = FAndroidApplication::GetJavaEnv();

    jclass BridgeClass = FAndroidApplication::FindJavaClassGlobalRef("{{$javaClassPath}}/{{$javaClassName}}Starter");
    if (BridgeClass != nullptr)
    {
        jmethodID StopMethod = Env->GetStaticMethodID(BridgeClass, "stop", "(Landroid/content/Context;)V");
        if (StopMethod != nullptr)
        {
            jobject Activity = FJavaWrapper::GameActivityThis; // Unreal’s activity
            FJavaWrapper::CallStaticVoidMethod(Env, BridgeClass, StopMethod, Activity);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("{{Camel .Module.Name}}JavaServiceStarter:stop; method not found, failed to stop service"));
            return;
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT( "{{Camel .Module.Name}}JavaServiceStarter:stop; CLASS not found, failed to stop service"));
    }
#endif
#endif
	Super::Deinitialize();
}

void {{$Class}}::setBackendService(TScriptInterface<I{{Camel .Module.Name}}{{$IfaceName}}Interface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
		U{{$Iface}}Publisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service {{$Iface}}"));
		BackendPublisher->Unsubscribe(TWeakInterfacePtr<I{{$Iface}}SubscriberInterface>(this));
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface {{$Iface}} is not fully implemented"));

	// subscribe to new backend
{{- $Service := printf "I%sInterface" $Iface }}
	BackendService = InService;
	U{{$Iface}}Publisher* BackendPublisher = BackendService->_GetPublisher();
	checkf(BackendPublisher, TEXT("Cannot subscribe to delegates from backend service {{$Iface}}"));
	// connect property changed signals or simple events
	BackendPublisher->Subscribe(TWeakInterfacePtr<I{{$Iface}}SubscriberInterface>(this));

	callJniServiceReady(true);
}

TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> {{$Class}}::getBackendService()
{
	return BackendService;
}

void {{$Class}}::callJniServiceReady(bool isServiceReady)
{
    UE_LOG(Log{{$Iface}}_JNI, Verbose, TEXT("{{$Class}} call nativeServiceReady the service function "));
    
#if PLATFORM_ANDROID && USE_ANDROID_JNI
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
    {
        if (!m_javaJniServiceClass || !m_javaJniServiceInstance )
        {
            UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$javaClassPath}}/{{$javaClassName}}:nativeServiceReady(Z)V CLASS not found"));
            return;
        }

        static const jmethodID MethodID = Env->GetMethodID(m_javaJniServiceClass, "nativeServiceReady", "(Z)V");

        if (MethodID != nullptr)
        {
            FJavaWrapper::CallVoidMethod(Env, m_javaJniServiceInstance, MethodID, isServiceReady);
        }
        else
        {
            UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$javaClassPath}}/{{$javaClassName}}:nativeServiceReady(Z)V not found "));
        }
    }
#endif 
}

{{- range .Interface.Signals }}

void {{$Class}}::On{{Camel .Name}}Signal({{ueParams "" .Params}})
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
    UE_LOG(Log{{$Iface}}_JNI, Verbose, TEXT("Notify java jni {{$Class}}::on{{Camel .Name}} "));
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
    {
        {{- $signatureParams:= jniJavaSignatureParams .Params}}
        if (m_javaJniServiceClass == nullptr || m_javaJniServiceInstance == nullptr)
        {
            UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$javaClassPath}}/{{$javaClassName}}:on{{Camel .Name}} ({{$signatureParams}})V CLASS not found"));
            return;
        }
        static const jmethodID MethodID = Env->GetMethodID(m_javaJniServiceClass, "on{{Camel .Name}}", "({{$signatureParams}})V");
        if (MethodID == nullptr)
        {
            UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$javaClassPath}}/{{$javaClassName}}:on{{Camel .Name}} ({{$signatureParams}})V not found"));
            return;
        }

        {{- range .Params -}}
        {{template "convert_to_java_type" .}}
        {{- end }}

        FJavaWrapper::CallVoidMethod(Env, m_javaJniServiceInstance, MethodID{{- if len (.Params) }},{{- end}} 
        {{- range $idx, $p := .Params -}} {{- if $idx}}, {{ end -}}
            {{- $javaPropName := Camel .Name}}
            {{- $cppropName := ueVar "" .}}
            {{- $localName := printf "jlocal_%s" $javaPropName }}
            {{- if .IsArray }} {{$localName}}
        {{- else if or ( or (eq .KindType "enum") (eq .KindType "string") ) (not  .IsPrimitive ) }} {{$localName}}
        {{- else }} {{$cppropName}}
        {{- end -}}
        {{- end -}});

        {{- range $idx, $p := .Params -}}
            {{- $javaPropName := Camel .Name}}
            {{- $localName := printf "jlocal_%s" $javaPropName }}
        {{- if or ( or .IsArray  (eq .KindType "enum" ) ) }}
        Env->DeleteLocalRef({{$localName}});
        {{- else if not ( ueIsStdSimpleType .)  }}
        Env->DeleteLocalRef({{$localName}});
        {{- end }}
        {{- end }}
    }
#endif
}
{{- end }}


{{- range .Interface.Properties }}
{{- if eq .KindType "interface" }}
// Interfaces as properties are currently not supported for jni. Generated for compatibility. 
{{- end }}
void {{$Class}}::On{{Camel .Name}}Changed({{ueParam "" .}})
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
    UE_LOG(Log{{$Iface}}_JNI, Verbose, TEXT("Notify java jni {{$Class}}::On{{Camel .Name}} "));
    {{- $signature := printf "(%s)V" (jniJavaSignatureParam .)}}
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
    {
        if (m_javaJniServiceClass == nullptr)
        {
            UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$javaClassPath}}/{{$javaClassName}}::on{{Camel .Name}}Changed{{$signature}} CLASS not found"));
            return;
        }

        static const jmethodID MethodID = Env->GetMethodID(m_javaJniServiceClass, "on{{Camel .Name}}Changed","{{$signature}}");
        if (MethodID == nullptr)
        {
            UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$javaClassPath}}/{{$javaClassName}}:on{{Camel .Name}}Changed{{$signature}} not found"));
            return;
        }

        {{- $cppropName := ueVar "" .}}
        {{template "convert_to_java_type" .}}
        {{- $javaLocalName := printf "jlocal_%s"  (Camel .Name) }}
        {{- if or ( or ( .IsArray  ) (eq .KindType "string")) ( or (eq .KindType "enum") (not (ueIsStdSimpleType .))  ) }}
        FJavaWrapper::CallVoidMethod(Env, m_javaJniServiceInstance, MethodID, {{$javaLocalName}});

        {{- if and .IsArray }}
        Env->DeleteLocalRef({{$javaLocalName}});
        {{- else if not (ueIsStdSimpleType . ) }}
        Env->DeleteLocalRef({{$javaLocalName}});
        {{- end}}
        {{- else }}
        FJavaWrapper::CallVoidMethod(Env, m_javaJniServiceInstance, MethodID, {{$cppropName}});
        {{- end }}

    }
#endif
}
{{- end }}


#if PLATFORM_ANDROID && USE_ANDROID_JNI

{{- range .Interface.Operations }}
JNI_METHOD {{ jniToReturnType .Return}} {{$jniFullFuncPrefix}}_native{{ Camel   .Name }}(JNIEnv* Env, jclass Clazz{{- if len (.Params) }},{{end}} {{jniJavaParams "" .Params }})
{
    UE_LOG(Log{{$Iface}}_JNI, Verbose, TEXT("{{$jniFullFuncPrefix}}_native{{Camel .Name}}"));
    if (g{{$Class}}Handle == nullptr)
    {
        UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$jniFullFuncPrefix}}_native{{ Camel   .Name }}: JNI SERVICE ADAPTER NOT FOUND "));
        return {{ jniEmptyReturn .Return }};
    }

{{- range .Params -}}
    {{- template "convert_to_local_cpp_value_java_param" . }}
{{- end }}

    auto service = g{{$Class}}Handle->getBackendService();
    if (service != nullptr)
    {
    {{- $cppropName := "result"}}
        {{ if not .Return.IsVoid }}auto {{$cppropName}} = {{ end -}}
    service->{{Camel .Name}}(
    {{- range $idx, $p := .Params -}}
        {{- if $idx}}, {{ end -}}
        {{- $local_value :=  printf "local_%s" (snake .Name) -}}
        {{- if or  .IsArray ( or (eq .KindType "enum") (not (ueIsStdSimpleType .))  ) }} {{$local_value -}}
        {{- else }} {{.Name}}
        {{- end -}}
    {{- end -}}
    );

    {{- if .Return.IsVoid }}
        return;
    {{- else if or  .Return.IsArray ( or (eq .Return.KindType "enum") (not (ueIsStdSimpleType .Return))  ) }}
        {{- $localName := "jresult" }}
        {{- $javaClassConverter := printf "%sDataJavaConverter" ( Camel .Return.Schema.Import ) }}
        {{- if (eq $javaClassConverter  "DataJavaConverter" )}}{{- $javaClassConverter = printf "%sDataJavaConverter" $ModuleName }}{{ end }}
    {{- if .Return.IsArray }}
	{{- if (eq .Return.KindType "string")}}
        TArray<FStringView> {{$cppropName}}StringViews;
        {{$cppropName}}StringViews.Reserve({{$cppropName}}.Num());
        for (const FString& Str : {{$cppropName}})
        {
            {{$cppropName}}StringViews.Add(FStringView(Str));
        }
        auto {{$localName}}Wrapped = FJavaHelper::ToJavaStringArray(Env,{{$cppropName}}StringViews);
        auto {{$localName}} = static_cast<jobjectArray>(Env->NewLocalRef(*{{$localName}}Wrapped));
    {{- else if (eq .Return.KindType "bool")}}
        auto len = {{$cppropName}}.Num();
        {{jniToReturnType .Return}} {{$localName}} = Env->New{{jniToEnvNameType .Return}}Array(len);
        TArray<jboolean> Temp;
        Temp.SetNumUninitialized(len);
        for (int i = 0; i < len; i++)
        {
            Temp[i] = {{$cppropName}}[i] ? JNI_TRUE : JNI_FALSE;
        }
        Env->SetBooleanArrayRegion({{$localName}}, 0, len, Temp.GetData());
	{{- else if and (.Return.IsPrimitive ) (not (eq .Return.KindType "enum")) }}
        auto len = {{$cppropName}}.Num();
        {{jniToReturnType .Return}} {{$localName}} = Env->New{{jniToEnvNameType .Return}}Array(len);
        if ({{$localName}}  == NULL){/*Log error, skip?*/};
        Env->Set{{jniToEnvNameType .Return}}ArrayRegion({{$localName}}, 0, len, {{- if (eq .Return.KindType "int64") -}}
        reinterpret_cast<const jlong*>({{$cppropName}}.GetData()));
        {{- else -}}
        {{$cppropName}}.GetData());
        {{- end }}
	{{- else }}
        {{- if eq .Return.KindType "interface" }}
        // interfaces are currently not supported. {{$javaClassConverter}} returns empty array. 
        {{- end }}
        {{jniToReturnType .Return}} {{$localName}} = {{$javaClassConverter}}::makeJava{{Camel .Return.Type }}Array(Env, {{$cppropName}});
	{{- end }}
        {{- else if (eq .Return.KindType "string")}}
        auto {{$localName}}Wrapped = FJavaHelper::ToJavaString(Env, {{$cppropName}});
        jstring {{$localName}} = static_cast<jstring>(Env->NewLocalRef(*{{$localName}}Wrapped));
        {{- else if ( or (not (ueIsStdSimpleType .Return)) (eq .Return.KindType "enum" ) ) }}
        {{- if eq .Return.KindType "interface" }}
        // interfaces are currently not supported. {{$javaClassConverter}} returns nullptr. 
        {{- end }}
        {{jniToReturnType .Return}} {{$localName}} = {{$javaClassConverter}}::makeJava{{Camel .Return.Type }}(Env, {{$cppropName}});
        {{- end }}
        return {{$localName}};
        {{- else }}
        return {{$cppropName}};
        {{- end }}
    }
    else
    {
        UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("service not valid"));
        return {{ jniEmptyReturn .Return }};
    }
}
{{- end}}

	

{{- range .Interface.Properties }}
{{- if not .IsReadOnly }}
{{- $javaPropName := .Name}}
JNI_METHOD void {{$jniFullFuncPrefix}}_nativeSet{{ Camel .Name }}(JNIEnv* Env, jclass Clazz, {{jniJavaParam "" . }})
{
    UE_LOG(Log{{$Iface}}_JNI, Verbose, TEXT("{{$jniFullFuncPrefix}}_nativeSet{{Camel .Name}}"));
    if (g{{$Class}}Handle == nullptr)
    {
        UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$jniFullFuncPrefix}}_nativeSet{{ Camel .Name }}: JNI SERVICE ADAPTER NOT FOUND "));
        return;
    }
    {{ template "convert_to_local_cpp_value_java_param" . }}
    {{- $hasLocalVar := or  .IsArray ( or (eq .KindType "enum") (not (ueIsStdSimpleType .))  ) }}
    {{- $local_value :=  printf "local_%s" (snake .Name) }}

    AsyncTask(ENamedThreads::GameThread, [{{- if $hasLocalVar }}p{{$local_value -}} = MoveTemp({{$local_value -}}){{- else}}{{$javaPropName}}{{- end}}]()
    {
        auto service = g{{$Class}}Handle->getBackendService();
        if (service != nullptr)
        {
        {{- if $hasLocalVar }}
            service->Set{{Camel .Name}}(p{{$local_value}});
        {{- else}}
            service->Set{{Camel .Name}}({{$javaPropName}});
        {{- end}}
        }
        else
        {
            UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("service not valid, cannot set value for {{.Name}}"));
        }
    });
}
{{- end}}

JNI_METHOD {{jniToReturnType .}} {{$jniFullFuncPrefix}}_nativeGet{{ Camel .Name }}(JNIEnv* Env, jclass Clazz)
{
    UE_LOG(Log{{$Iface}}_JNI, Verbose, TEXT("{{$jniFullFuncPrefix}}_nativeGet{{Camel .Name}}"));
    if (g{{$Class}}Handle == nullptr)
    {
        UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$jniFullFuncPrefix}}_nativeGet{{Camel .Name }}: JNI SERVICE ADAPTER NOT FOUND "));
        return {{ jniEmptyReturn . }};
    }
    auto service = g{{$Class}}Handle->getBackendService();
    if (service != nullptr)
    {
    {{- $cppropName := ueVar "" .}}
        auto {{$cppropName}} = service->Get{{Camel .Name}}();
    {{- if or  .IsArray ( or (eq .KindType "enum") (not (ueIsStdSimpleType .))  ) }}
        {{template "convert_to_java_type" .}}
        {{- $localName := printf "jlocal_%s" (Camel .Name) }}
        return {{$localName}};
    {{- else }} 
        return {{$cppropName}};
    {{- end }}
    }
    else
    {
        UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("service not available, try setting a backend service "));
        return {{ jniEmptyReturn . }};
    }
}
{{- end }}
#endif
