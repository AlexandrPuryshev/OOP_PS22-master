@echo off

REM запуск программы где числа только нули 
Lab1_Zad3_Var2_OOP.exe matrixNULL.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы где в числах есть единицы
Lab1_Zad3_Var2_OOP.exe matrixONE.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с неполными параметрами
Lab1_Zad3_Var2_OOP.exe
IF ERRORLEVEL 1 GOTO err

REM запуск программы с матрицой 2*3
Lab1_Zad3_Var2_OOP.exe abracadabra.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с верными параметрами
Lab1_Zad3_Var2_OOP.exe matrix.txt
IF ERRORLEVEL 1 GOTO err


ECHO Program testing succeeded :-)
EXIT
:err
ECHO Program testing failed :-(
EXIT

echo on
