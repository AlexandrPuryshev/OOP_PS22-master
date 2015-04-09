@echo off

REM ������ ��������� c ��������� �����������
crypt.exe pack
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� c ��������� �����������
crypt.exe pack input_255_crypt.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� c ��������� �����������
crypt.exe pack input_255_crypt.txt output_255_crypt.txt output_2556_crypt.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� ��� ������ � ����� 255 pack 
crypt.exe pack input_255_crypt.txt output_255_crypt.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� ��� ������ � ����� 255 pack, � ���������� ������ 
crypt.exe pack input_255_decimal_crypt.txt output_255_decimal_crypt.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� ��� ������ � ����� 255 unpack
crypt.exe unpack input_255_decrypt.txt output_255_decrypt.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� ��� ������ � ����� 255, � ���������� ������ unpack
crypt.exe unpack input_255_decimal_decrypt.txt output_255_decimal_decrypt.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� ��� ����� ������� > 256, � ������ � ����� - 430 pack 
crypt.exe pack input430.txt output430.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ������������ ����� ����
crypt.exe pack crypt.exe crypt.exe.packed
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ������� ������ ������ unpack 
crypt.exe unpack inputNULL.txt outputNULL.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ������� ����������� pack 
crypt.exe pack input_crypt.txt output1.txt
IF ERRORLEVEL 1 GOTO err
FC /B output1.txt output_crypt.txt

REM ������ ��������� � ������� ����������� unpack 
crypt.exe unpack input_decrypt.txt output2.txt
IF ERRORLEVEL 1 GOTO err
FC /B output2.txt output_decrypt.txt

ECHO Program testing succeeded :-)
EXIT
:err
ECHO Program testing failed :-(
EXIT
