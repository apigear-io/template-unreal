{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear%s" $ModuleName }}
{
	"FileVersion": 3,
	"Version": 1,
	"VersionName": "{{.Module.Version}}",
	"FriendlyName": "{{$ModuleName}}",
	"Description": "",
	"Category": "Other",
	"CreatedBy": "",
	"CreatedByURL": "",
	"DocsURL": "",
	"MarketplaceURL": "",
	"SupportURL": "",
	"CanContainContent": true,
	"IsBetaVersion": true,
	"IsExperimentalVersion": false,
	"Installed": false,
	"EnabledByDefault" : true,
	"Modules": [
{{- if .Features.api }}
		{
			"Name": "{{$ModuleName}}API",
			"Type": "Runtime",
			"LoadingPhase": "default"
		},
{{- end }}
		{
			"Name": "{{$ModuleName}}Core",
			"Type": "Runtime",
			"LoadingPhase": "default"
		},
{{- if and .Features.stubs (len .Module.Interfaces) }}
		{
			"Name": "{{$ModuleName}}Implementation",
			"Type": "Runtime",
			"LoadingPhase": "default"
		},
{{- end }}
{{- if and .Features.olink (len .Module.Interfaces) }}
		{
			"Name": "{{$ModuleName}}OLink",
			"Type": "Runtime",
			"LoadingPhase": "default"
		},
{{- end }}
{{- if and .Features.monitor (len .Module.Interfaces) }}
		{
			"Name": "{{$ModuleName}}Monitor",
			"Type": "Runtime",
			"LoadingPhase": "default"
		},
{{- end }}
		{
			"Name" : "{{$ModuleName}}Editor",
			"Type" : "Editor",
			"LoadingPhase" : "default",
			"PlatformAllowList" : [ "Win64", "Mac", "Linux" ]
		}
	]
{{- if or .Features.apigear .Module.Imports }},
	"Plugins": [
		{{- if .Features.apigear }}
		{
			"Name": "ApiGear",
			"Enabled": true
		}{{- if .Module.Imports }}, {{- end}}
		{{- end }}
		{{- range $idx, $elem := .Module.Imports }}
		{{- if $idx}}, {{ end }}
		{
			"Name": "{{Camel .Name}}",
			"Enabled": true
		}
		{{- end }}
	]
{{- end }}
}
