{{- define "author" -}}
{{- $a := .Module.Meta.GetString "author" -}}
{{- if not $a }}{{- with index .Meta "author" }}{{- $a = . -}}{{ end -}}{{ end -}}
{{- $a -}}
{{- end -}}

{{- define "author_url" -}}
{{- $a := .Module.Meta.GetString "author_url" -}}
{{- if not $a }}{{- with index .Meta "author_url" }}{{- $a = . -}}{{ end -}}{{ end -}}
{{- $a -}}
{{- end -}}
