@echo off

echo CHECKING

set ORIG_PATH=%PATH%
set Rcmd="C:\Program Files\R\R-3.2.1\bin\x64\Rcmd.exe"

PATH=C:\bin\Rtools\bin;C:\Rtools\gcc-4.6.3\bin;%PATH%

%Rcmd% check --no-multiarch arc

PATH=%ORIG_PATH%
pause
