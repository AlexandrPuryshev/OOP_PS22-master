@echo off

REM ������ ��������� ��� ����� ������ ���� 
Inverse_Matrix.exe matrixNULL.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� ��� � ������ ���� �������
Inverse_Matrix.exe matrixONE.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ��������� �����������
Inverse_Matrix.exe
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � �������
Inverse_Matrix.exe MatrixWithWords.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � 1 ������
Inverse_Matrix.exe MatrixWithWord.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ������� �����������
Inverse_Matrix.exe matrix.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
EXIT
:err
ECHO Program testing failed :-(
EXIT
