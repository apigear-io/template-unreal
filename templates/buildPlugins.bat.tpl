{{- $exports := getEmptyStringList}}
{{- range .System.Modules }}
{{- range .Imports }}
{{- $exports = appendList $exports .Name }}
{{- end }}
{{- end }}
{{- $exports = unique $exports}}
@Echo off
SET script_path=%~dp0
echo Script is in %script_path:~0,-1%

@REM Check for UAT
setlocal enableDelayedExpansion
for %%i in (RunUAT.bat) do (
    set "RunUAT_path=%%~$PATH:i" 
)
if not defined RunUAT_path (
	echo RunUAT.bat needs to be in the PATH environment variable
	exit /b 1
)
echo RunUAT.bat found at %RunUAT_path:~0,-11%

@REM Retrive UE path and test for plugins folder
set UE_path=%RunUAT_path:~0,-28%
if exist "%UE_path%\" (
	echo UE installation found at %UE_path%
) else (
	echo Was not able to find UE installation at %UE_path%
	exit /b 1
)
set UEplugins_path=%UE_path%\Plugins
if exist "%UEplugins_path%\" (
	echo UE plugins found at %UEplugins_path%
) else (
	echo Was not able to find UE plugins at %UEplugins_path%
	exit /b 1
)

@REM Check for existing ApiGear plugins
set ApiGearTarget_path=%UEplugins_path%\Marketplace\ApiGear
set RestoreApiGearPlugins=0
if exist "%ApiGearTarget_path%\" (
	echo Existing ApiGear plugins found at %ApiGearTarget_path%
	move "%ApiGearTarget_path%" "%UEplugins_path%\..\ApiGearBackUp" >nul
	if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
	set "RestoreApiGearPlugins=1"
)

{{ if .Features.apigear -}}
@REM Build ApiGear plugin
call :buildUEplugin "%script_path%\Plugins\ApiGear\ApiGear.uplugin" , "%script_path%build\Plugins\ApiGear"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM copy ApiGear plugin to UE installation for use by other plugins
set ApiGearPluginTarget_path=%ApiGearTarget_path%\ApiGear
xcopy /E /Y "%script_path%build\Plugins\ApiGear" "%ApiGearPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 call :cleanup %ERRORLEVEL%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
{{- end }}
{{ range .System.Modules}}
@REM Building and testing {{Camel .Name}} module
call :buildUEplugin "%script_path%\Plugins\{{Camel .Name}}\{{Camel .Name}}.uplugin" , "%script_path%build\Plugins\{{Camel .Name}}"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

{{- if contains $exports .Name }}

@REM copy {{ Camel .Name}} plugin to UE installation for use by other plugins
set {{ Camel .Name}}PluginTarget_path=%ApiGearTarget_path%\{{ Camel .Name}}
xcopy /E /Y "%script_path%build\Plugins\{{ Camel .Name}}" "%{{ Camel .Name}}PluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 call :cleanup %ERRORLEVEL%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
{{- end }}
{{ end }}

call :cleanup 0
exit /b 0

@REM function implementations

@REM build UE plugin
:buildUEplugin
(
	"%RunUAT_path%" BuildPlugin -verbose -Rocket -Plugin=%1 -TargetPlatforms=Win64 -StrictIncludes -Package=%2
	set buildresult=!ERRORLEVEL!
)
exit /b %ERRORLEVEL%

@REM Clean up ApiGear plugin installation
:cleanup
if %RestoreApiGearPlugins% equ 1 (
	echo Restoring old ApiGear plugins in UE installation
	@RD /S /Q "%ApiGearTarget_path%"
	move "%UEplugins_path%\..\ApiGearBackUp" "%ApiGearTarget_path%" >nul
	if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
) else (
	echo Deleting temporary ApiGear plugin installation from UE
	@RD /S /Q "%ApiGearTarget_path%"
	if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
)
exit /b %~1
