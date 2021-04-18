@echo off
call D:\Softwares\VS19\VC\Auxiliary\Build\vcvars64.bat
cd ..
msbuild Victoria.sln /p:Platform=x64 /p:Configuration=Debug
call bin\Debug-windows-x86_64\Victor\Victor.exe
PAUSE