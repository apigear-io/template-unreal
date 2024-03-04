{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%s_API" $ModuleName }}
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
{{- if .Features.apigear }},
	"Plugins": [
		{
			"Name": "ApiGear",
			"Enabled": true
		}
	]
{{- end }}
}
