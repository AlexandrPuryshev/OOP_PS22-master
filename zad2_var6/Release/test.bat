@echo off

REM  запуск (solve.exe <A> <B> <C>)

REM запуск программы с одним параметром
solve.exe 2
IF ERRORLEVEL 1 GOTO err

REM запуск программы с отрицательным дискрименантом
solve.exe 5 3 7
IF ERRORLEVEL 1 GOTO err

REM запуск программы с нулевым коффициэнтом
solve.exe 0 -6 9
IF ERRORLEVEL 1 GOTO err

REM запуск программы с 2 нулевыми коффициэнтами
solve.exe 4 0 0
IF ERRORLEVEL 1 GOTO err

REM запуск программы с 1 нулевым коффициэнтом
solve.exe 1 0 -25
IF ERRORLEVEL 1 GOTO err

REM запуск программы с 1 нулевым коффициэнтом, но ответ неправильный
solve.exe 1 0 25
IF ERRORLEVEL 1 GOTO err

REM запуск программы с 1 нулевым коффициэнтом
solve.exe 4 -2 0
IF ERRORLEVEL 1 GOTO err

REM запуск программы с дискрименантом, который равен нулю
solve.exe 1 -6 9
IF ERRORLEVEL 1 GOTO err

REM запуск программы с верными параметрами -> 2 корня
solve.exe 1 -8 12
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
EXIT
:err
ECHO Program testing failed :-(
EXIT