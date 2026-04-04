{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $Category := printf "ApiGear%s" $ModuleName }}

{{- $class := printf "F%sJniModule" $ModuleName}}

#include "{{$ModuleName}}/{{$ModuleName}}Jni.h"
#include "{{$ModuleName}}/Generated/{{$ModuleName}}Factory.h"
#include "{{$ModuleName}}/Generated/Jni/{{$ModuleName}}DataJavaConverter.h"
#include "Engine/Engine.h"
#include "{{$ModuleName}}Settings.h"
#include "Modules/ModuleManager.h"

#include "Generated/Detail/{{$ModuleName}}MethodHelper.h"

#define LOCTEXT_NAMESPACE "{{$ModuleName}}Jni"

DEFINE_LOG_CATEGORY(Log{{Camel .Module.Name}}MethodHelper_JNI);

void {{$class}}::StartupModule()
{
}

void {{$class}}::ShutdownModule()
{
// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
// we call this function before unloading the module.
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	{{- $converterName := printf "%sDataJavaConverter" $ModuleName}}
	{{$converterName}}::cleanJavaReferences();
#endif
}

IMPLEMENT_MODULE({{$class}}, {{$ModuleName}}Jni)

#undef LOCTEXT_NAMESPACE
