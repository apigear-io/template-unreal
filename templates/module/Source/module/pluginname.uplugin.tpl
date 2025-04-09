{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%s_API" $ModuleName }}
{{- $Category := printf "ApiGear%s" $ModuleName }}
{
	"FileVersion": 3,
	"Version": 1,
	"VersionName": "{{.Module.Version}}+tpl.{{ template "templateversion" }}",
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
		{
			"Name": "{{$ModuleName}}",
			"Type": "Runtime",
			"LoadingPhase": "default"
		},
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
