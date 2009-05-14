@echo off

set OUTPUT_DIR=..

REM VC_VERSION = 7.1 | 8 | 9
REM 7.1 - MS Visual C++ 2003, 8 - MS Visual C++ 2005, 9 - MS Visual C++ 2008
set VC_VERSION=%1
set RESTORE=%2

if "%VC_VERSION%" == "" (
@echo on
@echo Usage:
@echo create-vc-solution.bat vc_version [/restore]
@echo
@echo vc_version - Visual C++ version for the target solution and project files. Valid values are 8 and 9.
@echo ???please add doc for restore
pause 
exit /b 1)

if "%VC_VERSION%" == "7.1" (
set VC_NAME=Visual Studio 2003
set VC_FORMAT=???
set SLN_FORMAT=???
set PRJ_VERSION=???
set VSPROPS_VERSION=???)

if "%VC_VERSION%" == "8" (
set MSVS_NAME=Visual Studio 2005
set SLN_FORMAT=9.00
set PRJ_VERSION=8,00
set VSPROPS_VERSION=8.00)

if "%VC_VERSION%" == "9" (
set MSVS_NAME=Visual Studio 2008
set SLN_FORMAT=10.00
set PRJ_VERSION=9,00
set VSPROPS_VERSION=8.00)

REM curlpp solution
set FILE1=curlpp.sln
if "%RESTORE%" == "restore" (
sed -T -e s/"%MSVS_NAME%"/MSVS_NAME/ -e s/"%SLN_FORMAT%"/SLN_FORMAT/ %OUTPUT_DIR%\%FILE1% > %FILE1%.stub ) else (
sed -T -e s/MSVS_NAME/"%MSVS_NAME%"/ -e s/SLN_FORMAT/"%SLN_FORMAT%"/ %FILE1%.stub > %OUTPUT_DIR%\%FILE1%)

REM curlpp.common
set FILE2=curlpp.common.vsprops
if "%RESTORE%" == "restore" (
sed -T -e s/"%VSPROPS_VERSION%"/VSPROPS_VERSION/ %OUTPUT_DIR%\%FILE2% > %FILE2%.stub) else (
sed -T -e s/VSPROPS_VERSION/"%VSPROPS_VERSION%"/ %FILE2%.stub > %OUTPUT_DIR%\%FILE2%)

REM curlpp.lib
set FILE3=curlpp.lib.vcproj
set FILE3b=curlpp.lib.vsprops
if "%RESTORE%" == "restore" (
sed -T -e s/"%PRJ_VERSION%"/PRJ_VERSION/ %OUTPUT_DIR%\%FILE3% > %FILE3%.stub
sed -T -e s/"%VSPROPS_VERSION%"/VSPROPS_VERSION/ %OUTPUT_DIR%\%FILE3b% > %FILE3b%.stub) else (
sed -T -e s/PRJ_VERSION/"%PRJ_VERSION%"/ %FILE3%.stub > %OUTPUT_DIR%\%FILE3%
sed -T -e s/VSPROPS_VERSION/"%VSPROPS_VERSION%"/ %FILE3b%.stub > %OUTPUT_DIR%\%FILE3b%)


REM curlpp.examples
set FILE4=curlpp.examples.vcproj
set FILE4b=curlpp.examples.vsprops
if "%RESTORE%" == "restore" (
sed -T -e s/"%PRJ_VERSION%"/PRJ_VERSION/ %OUTPUT_DIR%\%FILE4% > %FILE4%.stub
sed -T -e s/"%VSPROPS_VERSION%"/VSPROPS_VERSION/ %OUTPUT_DIR%\%FILE4b% > %FILE4b%.stub) else (
sed -T -e s/PRJ_VERSION/"%PRJ_VERSION%"/ %FILE4%.stub > %OUTPUT_DIR%\%FILE4%
sed -T -e s/VSPROPS_VERSION/"%VSPROPS_VERSION%"/ %FILE4b%.stub > %OUTPUT_DIR%\%FILE4b%)
