@ECHO OFF

SETLOCAL ENABLEEXTENSIONS

SET MODE=Release\
IF "%1"=="" (GOTO :DEFAULT) ELSE (GOTO :PAREM)


:DEFAULT
GOTO :FINAL

:PAREM
IF "%1"=="-r" (
    SET MODE=Release\
)
IF "%1"=="-d" (
    SET MODE=Debug\
)
GOTO :FINAL


:RUN_TEST <testFile>
    @REM Setlocal EnableDelayedExpansion
    IF NOT EXIST %~1 (
        ECHO "[Auto Test Warning] %~1 doesn't exist, skipping"
        ECHO ""
        EXIT /b
    )
    PUSHD %~dp1
    CALL %~1
    IF NOT %errorlevel% == 0 (
        ECHO "Failed: %errorlevel%"
        GOTO :FAILED
    )
    POPD
    EXIT /b


:FINAL
CALL :RUN_TEST %~dp0\%MODE%IfTests.exe
CALL :RUN_TEST %~dp0\%MODE%ModifyArgsTests.exe
CALL :RUN_TEST %~dp0\%MODE%ModifyReturnsTests.exe
CALL :RUN_TEST %~dp0\%MODE%Otherwise_DoTests.exe
CALL :RUN_TEST %~dp0\%MODE%TimesTests.exe
CALL :RUN_TEST %~dp0\%MODE%WhenCalledExpectedly_DoTests.exe
CALL :RUN_TEST %~dp0\%MODE%WhenCalledWithTests.exe

EXIT 0

:FAILED
EXIT 1