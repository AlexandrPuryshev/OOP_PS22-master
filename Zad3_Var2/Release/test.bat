@echo off

REM ������ ��������� ��� ����� ������ ���� 
Lab1_Zad3_Var2_OOP.exe matrixNULL.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� ��� � ������ ���� �������
Lab1_Zad3_Var2_OOP.exe matrixONE.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ��������� �����������
Lab1_Zad3_Var2_OOP.exe
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � �������� 2*3
Lab1_Zad3_Var2_OOP.exe abracadabra.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ������� �����������
Lab1_Zad3_Var2_OOP.exe matrix.txt
IF ERRORLEVEL 1 GOTO err


ECHO Program testing succeeded :-)
EXIT
:err
ECHO Program testing failed :-(
EXIT

echo on
