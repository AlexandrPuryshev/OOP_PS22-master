@echo off

REM ������ ��������� � ��������������� ������� ������ 
Replace_lab1.exe 1.txt 2.txt friend friends
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ��������������� ������� ������ 
Replace_lab1.exe input.txt "" friend friends
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
Replace_lab1.exe inputMam.txt output1.txt mam mama
IF ERRORLEVEL 1 GOTO err
FC /B output.txt outputMam.txt

REM ������ ��������� � ������� �����������
Replace_lab1.exe inputf.txt output2.txt f ff
IF ERRORLEVEL 1 GOTO err
FC /B output.txt outputf.txt

REM ������ ��������� � ������� �����������
Replace_lab1.exe input.txt output3.txt ������ �����
IF ERRORLEVEL 1 GOTO err
FC /B output.txt outputGRYSH.txt


ECHO Program testing succeeded :-)
EXIT
:err
ECHO Program testing failed :-(
EXIT

