{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name }}
{{- $Category := printf "ApiGear%s" $ModuleName }}

#include "{{$ModuleName}}/Generated/api/{{$ModuleName}}_data.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"
{{- nl }}

{{- range .Module.Enums }}
{{- $moduleEnumName := printf "%s%s" $ModuleName .Name }}
{{- $class := printf "E%s%s" $ModuleName .Name }}
/**
 * Enumeration {{$class}}
 */
bool U{{ $ModuleName }}Library::to{{$moduleEnumName}}({{$class}}& ConvertedEnum, uint8 InValue)
{
	bool bSuccessful = false;
	switch (InValue)
	{
{{- range .Members }}
	case {{.Value}}:
		ConvertedEnum = {{$class}}::{{ abbreviate $moduleEnumName }}_{{Camel .Name}};
		bSuccessful = true;
		break;
{{- end }}
	default:
		ConvertedEnum = {{$class}}::{{ abbreviate $moduleEnumName }}_{{Camel .Default.Name}};
	}
	return bSuccessful;
}
{{- end }}
{{- if .Module.Enums }}{{nl}}{{ end -}}
{{- range .Module.Structs}}
{{- $class := printf "F%s%s" $ModuleName .Name}}
bool {{$class}}::operator==(const {{$class}}& rhs) const
{
	return
{{- range $idx, $elem := .Fields}}
	{{- if $idx }}{{" &&"}}{{ end }} ({{.Name}} == rhs.{{.Name}})
{{- end }};
}

bool {{$class}}::operator!=(const {{$class}}& rhs) const
{
	return !operator==(rhs);
}

{{$class}}::operator FString() const
{
	return ToString();
}

FString {{$class}}::ToString() const
{
	return ToJSON(true);
}

FString {{$class}}::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}
{{- nl }}
{{- end }}
{{- range $idx, $elem := .Module.Structs }}
	{{- if $idx}}{{nl}}{{end}}
{{- $class := printf "F%s%s" $ModuleName .Name }}
{{- $shortname := printf "%s%s" $ModuleName .Name }}
/* Returns true if {{ $shortname }} A is equal to {{ $shortname }} B (A == B) */
bool U{{ $ModuleName }}Library::EqualEqual_{{ $shortname }}{{ $shortname }}({{ $class }} A, {{ $class }} B)
{
	return A == B;
}

/* Returns true if {{ $shortname }} A is not equal to {{ $shortname }} B (A != B) */
bool U{{ $ModuleName }}Library::NotEqual_{{ $shortname }}{{ $shortname }}({{ $class }} A, {{ $class }} B)
{
	return A != B;
}

FString U{{ $ModuleName }}Library::Conv_{{ $shortname }}ToString(const {{ $class }}& In{{ $shortname }})
{
	return In{{ $shortname }}.ToString();
}

FString U{{ $ModuleName }}Library::Conv_{{ $shortname }}ToJSON(const {{ $class }}& In{{ $shortname }})
{
	return In{{ $shortname }}.ToJSON();
}
{{- end }}
{{- if .Module.Structs }}{{nl}}{{ end -}}
