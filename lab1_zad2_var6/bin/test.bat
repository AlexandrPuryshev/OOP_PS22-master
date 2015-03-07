@echo off

REM  ������ (solve.exe <A> <B> <C>)

REM ������ ��������� � ����� ����������
solve.exe 2
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � 5 �����������
solve.exe 2 5 6 7 8
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � 2 �����������
solve.exe 2 5
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � 2 �������
solve.exe a b
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � 3 �������
solve.exe a b c
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � 1 ������
solve.exe a
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ������������� ��������������
solve.exe 5 3 7
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ������� ������������
solve.exe 0 -6 9
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � 2 �������� �������������
solve.exe 4 0 0
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � 1 ������� ������������
solve.exe 1 0 -25
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � 1 ������� ������������, �� ����� ������������
solve.exe 1 0 25
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � 1 ������� ������������
solve.exe 4 -2 0
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ��������������, ������� ����� ����
solve.exe 1 -6 9
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ������� ����������� -> 2 �����
solve.exe 1 -8 12
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
EXIT
:err
ECHO Program testing failed :-(
EXIT