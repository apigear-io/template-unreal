
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

@REM strip game module from uproject (not needed for plugin testing,
@REM avoids module-not-found errors on non-installed engine builds)
>"%ProjectTarget_path%\TP_Blank.uproject" echo {"FileVersion": 3, "EngineAssociation": ""}

@REM create Plugins folder
mkdir %ProjectTarget_path%\Plugins
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%

@REM copy ApiGear plugin to blank project for build and functional testing
echo Copy ApiGear plugin from "%script_path%ApiGear" to "%ProjectTarget_path%\Plugins\ApiGear"
mkdir %ProjectTarget_path%\Plugins\ApiGear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%ApiGear" "%ProjectTarget_path%\Plugins\ApiGear"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy Testbed2 plugin to blank project for build and functional testing
set Testbed2PluginTarget_path=%ProjectTarget_path%\Plugins\Testbed2
echo Testbed2 plugin from "%script_path%\Testbed2" to "%Testbed2PluginTarget_path%\"
mkdir %Testbed2PluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\Testbed2" "%Testbed2PluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy TbEnum plugin to blank project for build and functional testing
set TbEnumPluginTarget_path=%ProjectTarget_path%\Plugins\TbEnum
echo TbEnum plugin from "%script_path%\TbEnum" to "%TbEnumPluginTarget_path%\"
mkdir %TbEnumPluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\TbEnum" "%TbEnumPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy TbSame1 plugin to blank project for build and functional testing
set TbSame1PluginTarget_path=%ProjectTarget_path%\Plugins\TbSame1
echo TbSame1 plugin from "%script_path%\TbSame1" to "%TbSame1PluginTarget_path%\"
mkdir %TbSame1PluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\TbSame1" "%TbSame1PluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy TbSame2 plugin to blank project for build and functional testing
set TbSame2PluginTarget_path=%ProjectTarget_path%\Plugins\TbSame2
echo TbSame2 plugin from "%script_path%\TbSame2" to "%TbSame2PluginTarget_path%\"
mkdir %TbSame2PluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\TbSame2" "%TbSame2PluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy TbSimple plugin to blank project for build and functional testing
set TbSimplePluginTarget_path=%ProjectTarget_path%\Plugins\TbSimple
echo TbSimple plugin from "%script_path%\TbSimple" to "%TbSimplePluginTarget_path%\"
mkdir %TbSimplePluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\TbSimple" "%TbSimplePluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy Testbed1 plugin to blank project for build and functional testing
set Testbed1PluginTarget_path=%ProjectTarget_path%\Plugins\Testbed1
echo Testbed1 plugin from "%script_path%\Testbed1" to "%Testbed1PluginTarget_path%\"
mkdir %Testbed1PluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\Testbed1" "%Testbed1PluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy TbNames plugin to blank project for build and functional testing
set TbNamesPluginTarget_path=%ProjectTarget_path%\Plugins\TbNames
echo TbNames plugin from "%script_path%\TbNames" to "%TbNamesPluginTarget_path%\"
mkdir %TbNamesPluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\TbNames" "%TbNamesPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy CustomTypes plugin to blank project for build and functional testing
set CustomTypesPluginTarget_path=%ProjectTarget_path%\Plugins\CustomTypes
echo CustomTypes plugin from "%script_path%\CustomTypes" to "%CustomTypesPluginTarget_path%\"
mkdir %CustomTypesPluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\CustomTypes" "%CustomTypesPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy ExternTypes plugin to blank project for build and functional testing
set ExternTypesPluginTarget_path=%ProjectTarget_path%\Plugins\ExternTypes
echo ExternTypes plugin from "%script_path%\ExternTypes" to "%ExternTypesPluginTarget_path%\"
mkdir %ExternTypesPluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\ExternTypes" "%ExternTypesPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy Counter plugin to blank project for build and functional testing
set CounterPluginTarget_path=%ProjectTarget_path%\Plugins\Counter
echo Counter plugin from "%script_path%\Counter" to "%CounterPluginTarget_path%\"
mkdir %CounterPluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\Counter" "%CounterPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy TbIfaceimport plugin to blank project for build and functional testing
set TbIfaceimportPluginTarget_path=%ProjectTarget_path%\Plugins\TbIfaceimport
echo TbIfaceimport plugin from "%script_path%\TbIfaceimport" to "%TbIfaceimportPluginTarget_path%\"
mkdir %TbIfaceimportPluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\TbIfaceimport" "%TbIfaceimportPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy TbRefIfaces plugin to blank project for build and functional testing
set TbRefIfacesPluginTarget_path=%ProjectTarget_path%\Plugins\TbRefIfaces
echo TbRefIfaces plugin from "%script_path%\TbRefIfaces" to "%TbRefIfacesPluginTarget_path%\"
mkdir %TbRefIfacesPluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\TbRefIfaces" "%TbRefIfacesPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy TbStructArray plugin to blank project for build and functional testing
set TbStructArrayPluginTarget_path=%ProjectTarget_path%\Plugins\TbStructArray
echo TbStructArray plugin from "%script_path%\TbStructArray" to "%TbStructArrayPluginTarget_path%\"
mkdir %TbStructArrayPluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\TbStructArray" "%TbStructArrayPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM run build and tests
call :buildTestPlugins "%ProjectTarget_path%/TP_Blank.uproject" %script_path% ".Impl.+.OLink.+.MsgBus.+.Jni."
@REM check test results JSON as source of truth (UAT may return non-zero from
@REM shutdown ensures unrelated to test outcomes, e.g. UE 5.7 access detector)
if not exist %script_path%index.json (echo WARNING: no test results found & exit /b 1)
set "failcount="
for /f "tokens=2 delims=:" %%a in ('findstr /R "failed" "%script_path%index.json"') do set "failcount=%%a"
set "failcount=!failcount: =!"
set "failcount=!failcount:,=!"
if !failcount! GTR 0 (
	echo ERROR: !failcount! test^(s^) failed
	exit /b 1
)

@REM compile-only monolithic (Shipping) build to catch export/link issues
echo Running monolithic (Shipping) compile check...
call :buildMonolithic "%ProjectTarget_path%/TP_Blank.uproject"
if %ERRORLEVEL% GEQ 1 (echo Monolithic Shipping build failed & exit /b %ERRORLEVEL%)
exit /b 0

@REM function implementations

@REM build UE plugin
:buildTestPlugins
(
	"%RunUAT_path%" BuildCookRun -unattended -installed -project="%1" -run -editortest -RunAutomationTest="%3" -nullrhi -NoP4 -build -verbose -nodebuginfo -log="%2/RunTests.log" -addcmdline="-ReportExportPath=%2 " -notools -utf8output -WarningsAsErrors
	set buildresult=!ERRORLEVEL!
)
exit /b %ERRORLEVEL%

@REM monolithic (Shipping) compile-only build
:buildMonolithic
(
	"%RunUAT_path%" BuildCookRun -unattended -installed -project="%1" -nullrhi -NoP4 -build -skipcook -verbose -nodebuginfo -TargetPlatform=Win64 -Configuration=Shipping -notools -utf8output -WaitForUATMutex -WarningsAsErrors
	set buildresult=!ERRORLEVEL!
)
exit /b %ERRORLEVEL%
