
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
set ProjectTarget_path=%script_path%TP_Blank
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

@REM copy ApiGear plugin to blank project for build and functional testing
echo Copy ApiGear plugin from "%script_path%Plugins\ApiGear" to "%ProjectTarget_path%\Plugins\ApiGear"
mkdir %ProjectTarget_path%\Plugins\ApiGear
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%Plugins\ApiGear" "%ProjectTarget_path%\Plugins\ApiGear"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy Testbed2 plugin to blank project for build and functional testing
set Testbed2PluginTarget_path=%ProjectTarget_path%\Plugins\Testbed2
echo Testbed2 plugin from "%script_path%\Plugins\Testbed2" to "%Testbed2PluginTarget_path%\"
mkdir %Testbed2PluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\Plugins\Testbed2" "%Testbed2PluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy TbEnum plugin to blank project for build and functional testing
set TbEnumPluginTarget_path=%ProjectTarget_path%\Plugins\TbEnum
echo TbEnum plugin from "%script_path%\Plugins\TbEnum" to "%TbEnumPluginTarget_path%\"
mkdir %TbEnumPluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\Plugins\TbEnum" "%TbEnumPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy TbSame1 plugin to blank project for build and functional testing
set TbSame1PluginTarget_path=%ProjectTarget_path%\Plugins\TbSame1
echo TbSame1 plugin from "%script_path%\Plugins\TbSame1" to "%TbSame1PluginTarget_path%\"
mkdir %TbSame1PluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\Plugins\TbSame1" "%TbSame1PluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy TbSame2 plugin to blank project for build and functional testing
set TbSame2PluginTarget_path=%ProjectTarget_path%\Plugins\TbSame2
echo TbSame2 plugin from "%script_path%\Plugins\TbSame2" to "%TbSame2PluginTarget_path%\"
mkdir %TbSame2PluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\Plugins\TbSame2" "%TbSame2PluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy TbSimple plugin to blank project for build and functional testing
set TbSimplePluginTarget_path=%ProjectTarget_path%\Plugins\TbSimple
echo TbSimple plugin from "%script_path%\Plugins\TbSimple" to "%TbSimplePluginTarget_path%\"
mkdir %TbSimplePluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\Plugins\TbSimple" "%TbSimplePluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy Testbed1 plugin to blank project for build and functional testing
set Testbed1PluginTarget_path=%ProjectTarget_path%\Plugins\Testbed1
echo Testbed1 plugin from "%script_path%\Plugins\Testbed1" to "%Testbed1PluginTarget_path%\"
mkdir %Testbed1PluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\Plugins\Testbed1" "%Testbed1PluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy TbNames plugin to blank project for build and functional testing
set TbNamesPluginTarget_path=%ProjectTarget_path%\Plugins\TbNames
echo TbNames plugin from "%script_path%\Plugins\TbNames" to "%TbNamesPluginTarget_path%\"
mkdir %TbNamesPluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\Plugins\TbNames" "%TbNamesPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy CustomTypes plugin to blank project for build and functional testing
set CustomTypesPluginTarget_path=%ProjectTarget_path%\Plugins\CustomTypes
echo CustomTypes plugin from "%script_path%\Plugins\CustomTypes" to "%CustomTypesPluginTarget_path%\"
mkdir %CustomTypesPluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\Plugins\CustomTypes" "%CustomTypesPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy ExternTypes plugin to blank project for build and functional testing
set ExternTypesPluginTarget_path=%ProjectTarget_path%\Plugins\ExternTypes
echo ExternTypes plugin from "%script_path%\Plugins\ExternTypes" to "%ExternTypesPluginTarget_path%\"
mkdir %ExternTypesPluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\Plugins\ExternTypes" "%ExternTypesPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM copy Counter plugin to blank project for build and functional testing
set CounterPluginTarget_path=%ProjectTarget_path%\Plugins\Counter
echo Counter plugin from "%script_path%\Plugins\Counter" to "%CounterPluginTarget_path%\"
mkdir %CounterPluginTarget_path%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
xcopy /E /Y "%script_path%\Plugins\Counter" "%CounterPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%


@REM run build and tests
call :buildTestPlugins "%ProjectTarget_path%/TP_Blank.uproject" "%script_path%" ".Impl.+.OLink."
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
