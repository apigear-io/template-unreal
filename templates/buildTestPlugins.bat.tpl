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
set ProjectTarget_path=%script_path%build\TP_Blank
set UEtemplate_path=%UE_path:~0,-7%\Templates\TP_Blank
if exist "%UEtemplate_path%\" (
	echo UE blank project template found at %UEtemplate_path%
) else (
	echo Was not able to find UE blank project template %UEtemplate_path%
	exit /b 1
)

if exist "%ProjectTarget_path%\" (
	rd /s /q %ProjectTarget_path%
	if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
)

mkdir %ProjectTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%

@REM copy blank project template for testing
echo Copy blank project from %UEtemplate_path% to %ProjectTarget_path%\
xcopy /E /Y "%UEtemplate_path%" "%ProjectTarget_path%\" >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%

@REM create Plugins folder
mkdir %ProjectTarget_path%\Plugins
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%

{{ if .Features.apigear -}}
@REM copy ApiGear plugin to blank project for build and functional testing
echo Copy ApiGear plugin from "%script_path%ApiGear" to "%ProjectTarget_path%\Plugins\ApiGear"
mkdir %ProjectTarget_path%\Plugins\ApiGear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%ApiGear" "%ProjectTarget_path%\Plugins\ApiGear"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
{{- end }}
{{ range .System.Modules}}

@REM copy {{ Camel .Name}} plugin to blank project for build and functional testing
set {{ Camel .Name}}PluginTarget_path=%ProjectTarget_path%\Plugins\{{ Camel .Name}}
echo {{ Camel .Name}} plugin from "%script_path%\{{ Camel .Name}}" to "%{{ Camel .Name}}PluginTarget_path%\"
mkdir %{{ Camel .Name}}PluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\{{ Camel .Name}}" "%{{ Camel .Name}}PluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
{{ end }}

{{ if .Features.jni -}}

@REM copy android plugins to blank project for build and functional testing
set androidTarget_path=%ProjectTarget_path%\android
echo android from "%script_path%\..\android" to "%androidTarget_path%\"
mkdir %androidTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\..\android" "%androidTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
{{ end }}

@REM run build and tests
call :buildTestPlugins "%ProjectTarget_path%/TP_Blank.uproject" %script_path% ".Impl.{{ if .Features.olink_tests -}}+.OLink.{{ end }}{{ if .Features.msgbus_tests -}}+.MsgBus.{{ end }}{{ if .Features.jni_tests -}}+.Jni.{{ end }}"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
if not exist %script_path%index.json (echo WARNING: no test results found) else findstr /C:"\"failed\": 0" %script_path%index.json >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
exit /b 0

@REM function implementations

@REM build UE plugin
:buildTestPlugins
(
	@REM do not use -unattended as this seems to cause some issue when exiting the editor after test run
	"%RunUAT_path%" BuildCookRun -installed -project="%1" -run -RunAutomationTest="%3" -nullrhi -NoP4 -build -verbose -nodebuginfo -log="%2/RunTests.log" -addcmdline="-ReportExportPath=%2 " -Configuration=Test -notools -utf8output
	set buildresult=!ERRORLEVEL!
)
exit /b %ERRORLEVEL%
