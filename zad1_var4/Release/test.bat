@echo off

REM ������ ��������� � ��������������� ������� ������ 
Replace_lab1.exe 1.txt 2.txt friend friends
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ��������� ������� ������� ������
Replace_lab1.exe input.txt output.txt gavgav friends
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ��������� �����������
Replace_lab1.exe input.txt output.txt friends
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ������ �������
Replace_lab1.exe input.txt output.txt "" ff
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ������� �����������
Replace_lab1.exe input.txt output.txt ������ �����
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
EXIT
:err
ECHO Program testing failed :-(
EXIT