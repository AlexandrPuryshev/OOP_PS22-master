@echo off

REM запуск программы где числа только нули 
Inverse_Matrix.exe matrixNULL.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы где в числах есть единицы
Inverse_Matrix.exe matrixONE.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с неполными параметрами
Inverse_Matrix.exe
IF ERRORLEVEL 1 GOTO err

REM запуск программы с буквами
Inverse_Matrix.exe MatrixWithWords.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с 1 буквой
Inverse_Matrix.exe MatrixWithWord.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с верными параметрами
Inverse_Matrix.exe matrix.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
EXIT
:err
ECHO Program testing failed :-(
EXIT
