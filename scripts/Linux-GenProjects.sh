@echo off
pushd %~dp0\..\
call thirdparty\premake\bin\premake5linux.tar.gz gmake2
PAUSE
