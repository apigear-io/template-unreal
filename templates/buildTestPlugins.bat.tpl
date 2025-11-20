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

@REM Run primary tests (with ASan if enabled)
set "SANITIZER="
if defined ENABLE_ASAN (
	set "SANITIZER=asan"
)

call :buildTestPlugins "%ProjectTarget_path%/TP_Blank.uproject" ".Impl.{{ if .Features.olink_tests -}}+.OLink.{{ end }}{{ if .Features.msgbus_tests -}}+.MsgBus.{{ end }}" "%SANITIZER%" "%script_path%RunTests.log" "%script_path%"
if %ERRORLEVEL% GEQ 1 (
	echo ERROR: Tests failed
	exit /b %ERRORLEVEL%
)

@REM Check test results
if not exist %script_path%index.json (
	echo WARNING: no test results found
) else (
	findstr /C:"\"failed\": 0" %script_path%index.json >nul
	if %ERRORLEVEL% GEQ 1 (
		echo ERROR: Tests failed ^(check index.json^)
		exit /b %ERRORLEVEL%
	)
)

@REM TSan tests (opt-in with ENABLE_TSAN=1)
@REM Usage: set ENABLE_TSAN=1 && buildTestPlugins.bat
if defined ENABLE_TSAN (
	call :buildTestPlugins "%ProjectTarget_path%/TP_Blank.uproject" ".Impl.{{ if .Features.olink_tests -}}+.OLink.{{ end }}{{ if .Features.msgbus_tests -}}+.MsgBus.{{ end }}" "tsan" "%script_path%RunTests-TSan.log" "%script_path%tsan-results"
	if %ERRORLEVEL% GEQ 1 (
		echo ERROR: TSan tests failed ^(threading issues detected^)
		exit /b %ERRORLEVEL%
	)
	@REM Check TSan test results
	if exist %script_path%tsan-results\index.json (
		findstr /C:"\"failed\": 0" %script_path%tsan-results\index.json >nul
		if %ERRORLEVEL% GEQ 1 (
			echo ERROR: TSan tests failed ^(check tsan-results\index.json^)
			exit /b %ERRORLEVEL%
		)
	)
)
exit /b 0

@REM function implementations

@REM Run tests with optional sanitizer
@REM Args: project tests sanitizer log_file report_path
:buildTestPlugins
(
	set "sanitizer=%~3"
	set "log_file=%~4"
	set "report_path=%~5"
	set "SANITIZER_FLAGS="

	echo === Running Tests ===
	if "%sanitizer%"=="asan" (
		echo Enabled: ASan + UBSan
		set "SANITIZER_FLAGS=-EnableASan -EnableUndefinedBehaviorSanitizer"
	) else if "%sanitizer%"=="tsan" (
		echo Enabled: TSan
		set "SANITIZER_FLAGS=-EnableThreadSanitizer"
	)

	@REM do not use -unattended as this seems to cause some issue when exiting the editor after test run
	"%RunUAT_path%" BuildCookRun -installed !SANITIZER_FLAGS! -project="%~1" -run -RunAutomationTest="%~2" -nullrhi -NoP4 -build -verbose -WarningsAsErrors -nodebuginfo -NoEditorTelemetry -log="!log_file!" -addcmdline="-ReportExportPath=!report_path!" -Configuration=Test -notools -utf8output
)
exit /b %ERRORLEVEL%
