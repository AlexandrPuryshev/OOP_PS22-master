@echo off

REM ������ ��������� c ��������� �����������
RLE.exe pack
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� c ��������� �����������
RLE.exe pack input_255_crypt.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� c ��������� �����������
RLE.exe pack input_255_crypt.txt output_255_crypt.txt output_2556_crypt.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� ��� ������ � ����� 255 pack 
RLE.exe pack input_255_crypt.txt output_255_crypt.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� ��� ������ � ����� 255 pack, � ���������� ������ 
RLE.exe pack input_255_decimal_crypt.txt output_255_decimal_crypt.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� ��� ������ � ����� 255 unpack
RLE.exe unpack input_255_decrypt.txt output_255_decrypt.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� ��� ������ � ����� 255, � ���������� ������ unpack
RLE.exe unpack input_255_decimal_decrypt.txt output_255_decimal_decrypt.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� ��� ����� ������� > 256, � ������ � ����� - 430 pack 
RLE.exe pack input430.txt output430.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ������������ ����� ����
RLE.exe pack RLE.exe RLE.exe.packed
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ������� ������ ������ unpack 
RLE.exe unpack inputNULL.txt outputNULL.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ������� ����������� pack 
RLE.exe pack input_crypt.txt output1.txt
IF ERRORLEVEL 1 GOTO err
FC /B output1.txt output_crypt.txt

REM ������ ��������� � ������� ����������� unpack 
RLE.exe unpack input_decrypt.txt output2.txt
IF ERRORLEVEL 1 GOTO err
FC /B output2.txt output_decrypt.txt

ECHO Program testing succeeded :-)
EXIT
:err
ECHO Program testing failed :-(
EXIT
